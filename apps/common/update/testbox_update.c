
#include "update_loader_download.h"
#include "update.h"
#include "btctrler_task.h"
#include "app_config.h"


#if defined(CONFIG_SPP_AND_LE_CASE_ENABLE) || defined(CONFIG_HID_CASE_ENABLE)
#include "lib_profile_cfg.h"
#else
#include "bt_profile_cfg.h"
#endif

#if (SMART_BOX_EN) && (CONFIG_WATCH_CASE_ENABLE)
#include "smartbox/smartbox_task.h"
#endif

#define LOG_TAG "[TEST-UPDATE]"
#define LOG_INFO_ENABLE
#define LOG_ERROR_ENABLE
#include "system/debug.h"

extern void update_close_hw(void *filter_name);
extern void btctrler_testbox_update_msg_handle_register(void (*handle)(int));
extern void __bt_updata_reset_bt_bredrexm_addr(void);
extern int __bt_updata_save_connection_info(void);
extern const update_op_api_t lmp_ch_update_op;
extern const update_op_api_t ble_ll_ch_update_op;

static void testbox_bt_classic_update_private_param_fill(UPDATA_PARM *p)
{

}

int clk_set(const char *name, int clk);
extern void ll_hci_destory(void);
extern void ram_protect_close(void);
static void testbox_bt_classic_update_before_jump_handle(int type)
{
    if (UPDATE_MODULE_IS_SUPPORT(UPDATE_BT_LMP_EN)) {
        clk_set("sys", 24000000);
#if TCFG_USER_TWS_ENABLE || TCFG_USER_BLE_ENABLE
        log_info("close ble hw\n");
        ll_hci_destory();
#endif
        update_close_hw("bredr");
        if (__bt_updata_save_connection_info()) {
            log_error("bt save conn info fail!\n");
            return;
        }

        ram_protect_close();
        //note:last func will not return;
        __bt_updata_reset_bt_bredrexm_addr();
    }
}

static void testbox_bt_classic_update_state_cbk(int type, u32 state, void *priv)
{
    update_ret_code_t *ret_code = (update_ret_code_t *)priv;

    switch (state) {
    case UPDATE_CH_EXIT:
        log_info("state:%x err:%x\n", ret_code->stu, ret_code->err_code);
        if (UPDATE_DUAL_BANK_IS_SUPPORT()) {
            if ((0 == ret_code->stu) && (0 == ret_code->err_code)) {
                log_info("bt update succ\n");
                update_result_set(UPDATA_SUCC);
            } else {
                log_info("bt update fail\n");
                update_result_set(UPDATA_DEV_ERR);
            }
        } else {
            if ((0 == ret_code->stu) && (0 == ret_code->err_code)) {
                //update_mode_api(BT_UPDATA);
                update_mode_api_v2(BT_UPDATA,
                                   testbox_bt_classic_update_private_param_fill,
                                   testbox_bt_classic_update_before_jump_handle);
            }
        }
        break;
    }
}

static u8 ble_update_ready_jump_flag = 0;
u8 ble_update_get_ready_jump_flag(void)
{
    return ble_update_ready_jump_flag;
}

static void testbox_ble_update_private_param_fill(UPDATA_PARM *p)
{
    u8 addr[6];
    extern int le_controller_get_mac(void *addr);
    if (BT_MODULES_IS_SUPPORT(BT_MODULE_LE) && UPDATE_MODULE_IS_SUPPORT(UPDATE_BLE_TEST_EN)) {
        le_controller_get_mac(addr);
        memcpy(p->parm_priv, addr, 6);
        puts("ble addr:\n");
        put_buf(p->parm_priv, 6);
    }
}

static void testbox_ble_update_before_jump_handle(int type)
{
    if (BT_MODULES_IS_SUPPORT(BT_MODULE_LE) && UPDATE_MODULE_IS_SUPPORT(UPDATE_BLE_TEST_EN)) {
        ll_hci_destory();
    }

    cpu_reset();
}

extern u8 check_le_conn_disconnet_flag(void);
extern void ble_app_disconnect(void);
static void testbox_ble_update_state_cbk(int type, u32 state, void *priv)
{
    update_ret_code_t *ret_code = (update_ret_code_t *)priv;

    switch (state) {
    case UPDATE_CH_EXIT:
        if (UPDATE_DUAL_BANK_IS_SUPPORT()) {
            if ((0 == ret_code->stu) && (0 == ret_code->err_code)) {
                log_info("bt update succ\n");
                update_result_set(UPDATA_SUCC);
            } else {
                log_info("bt update fail\n");
                update_result_set(UPDATA_DEV_ERR);
            }
        } else {
            if ((0 == ret_code->stu) && (0 == ret_code->err_code)) {
#if TCFG_USER_BLE_ENABLE && ((TCFG_BLE_DEMO_SELECT != DEF_BLE_DEMO_ADV)  \
		&& (TCFG_BLE_DEMO_SELECT != DEF_BLE_DEMO_NULL) \
		&& (TCFG_BLE_DEMO_SELECT != DEF_BLE_DEMO_CLIENT))

                ble_update_ready_jump_flag = 1;
                ble_app_disconnect();
                u8 cnt = 0;
                while (!check_le_conn_disconnet_flag()) {
                    log_info("wait discon\n");
                    os_time_dly(2);
                    if (cnt++ > 5) {
                        break;
                    }
                }

                //update_mode_api(BLE_TEST_UPDATA);
                update_mode_api_v2(BLE_TEST_UPDATA,
                                   testbox_ble_update_private_param_fill,
                                   testbox_ble_update_before_jump_handle);
#endif
            }
        }
        break;
    }
}

void testbox_update_msg_handle(int msg)
{
    log_info("msg:%x\n", msg);

    switch (msg) {
    case MSG_BT_UPDATE_LOADER_DOWNLOAD_START:
        if (UPDATE_MODULE_IS_SUPPORT(UPDATE_BT_LMP_EN)) {
#if (SMART_BOX_EN) && (CONFIG_WATCH_CASE_ENABLE)
            app_smartbox_task_prepare(0, SMARTBOX_TASK_ACTION_WATCH_TRANSFER, 0);
#endif
            update_mode_info_t info = {
                .type = BT_UPDATA,
                .state_cbk = testbox_bt_classic_update_state_cbk,
                .p_op_api = &lmp_ch_update_op,
                .task_en = 1,
            };
            app_active_update_task_init(&info);
        }
        break;

    case MSG_BLE_TEST_OTA_LOADER_DOWNLOAD_START:
        if (UPDATE_MODULE_IS_SUPPORT(UPDATE_BLE_TEST_EN)) {
            update_mode_info_t info = {
                .type = BLE_TEST_UPDATA,
                .state_cbk =  testbox_ble_update_state_cbk,
                .p_op_api = &ble_ll_ch_update_op,
                .task_en = 1,
            };
            app_active_update_task_init(&info);
        }
        break;

defaut:
        log_error("not support update msg:%x\n", msg);
        break;
    }

}

void testbox_update_init(void)
{
    if (UPDATE_MODULE_IS_SUPPORT(UPDATE_BLE_TEST_EN) || UPDATE_MODULE_IS_SUPPORT(UPDATE_BT_LMP_EN)) {
        log_info("testbox msg handle reg:%x\n", testbox_update_msg_handle);
        btctrler_testbox_update_msg_handle_register(testbox_update_msg_handle);
    }
}

