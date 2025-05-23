#ifndef __KEY_EVENT_DEAL_H__
#define __KEY_EVENT_DEAL_H__

#include "typedef.h"
#include "system/event.h"

enum {
    KEY_POWER_ON = 0x80,//从0x80开始,避免与系统默认事件冲突
    KEY_POWER_ON_HOLD,
    KEY_POWEROFF,
    KEY_POWEROFF_HOLD,
    KEY_BT_DIRECT_INIT,
    KEY_BT_DIRECT_CLOSE,
    KEY_MUSIC_PP,
    KEY_MUSIC_PREV,
    KEY_MUSIC_NEXT,
    KEY_MUSIC_FF,
    KEY_MUSIC_FR,
    KEY_MUSIC_PLAYER_START,
    KEY_MUSIC_PLAYER_END,
    KEY_MUSIC_PLAYER_DEC_ERR,
    KEY_MUSIC_DEVICE_TONE_END,
    KEY_MUSIC_PLAYER_QUIT,
    KEY_MUSIC_PLAYER_AUTO_NEXT,
    KEY_MUSIC_PLAYER_PLAY_FIRST,
    KEY_MUSIC_PLAYER_PLAY_LAST,
    KEY_MUSIC_CHANGE_REPEAT,
    KEY_MUSIC_CHANGE_DEV,
    KEY_MUSIC_AUTO_NEXT_DEV,
    KEY_MUSIC_CHANGE_DEV_REPEAT,
    KEY_MUSIC_SET_PITCH,
    KEY_MUSIC_SET_SPEED,
    KEY_MUSIC_PLAYE_BY_DEV_FILENUM,
    KEY_MUSIC_PLAYE_BY_DEV_SCLUST,
    KEY_MUSIC_PLAYE_BY_DEV_PATH,
    KEY_MUSIC_DELETE_FILE,
    KEY_MUSIC_PLAYE_NEXT_FOLDER,
    KEY_MUSIC_PLAYE_PREV_FOLDER,
    KEY_MUSIC_PLAYE_REC_FOLDER_SWITCH,
    KEY_MUSIC_PLAYER_AB_REPEAT_SWITCH,
    KEY_VOL_UP,
    KEY_VOL_DOWN,
    KEY_CALL_LAST_NO,
    KEY_CALL_HANG_UP,
    KEY_CALL_ANSWER,
    KEY_OPEN_SIRI,
    KEY_HID_CONTROL,
    KEY_LOW_LANTECY,
    KEY_CHANGE_MODE,

    KEY_EQ_MODE,
    KEY_THIRD_CLICK,

    KEY_FM_SCAN_ALL,
    KEY_FM_SCAN_ALL_UP,
    KEY_FM_SCAN_ALL_DOWN,
    KEY_FM_PREV_STATION,
    KEY_FM_NEXT_STATION,
    KEY_FM_PREV_FREQ,
    KEY_FM_NEXT_FREQ,
    KEY_FM_SCAN_UP,//半自动搜台
    KEY_FM_SCAN_DOWN,//半自动搜台


    KEY_FM_EMITTER_MENU,
    KEY_FM_EMITTER_NEXT_FREQ,
    KEY_FM_EMITTER_PERV_FREQ,

    KEY_RTC_UP,
    KEY_RTC_DOWN,
    KEY_RTC_SW,
    KEY_RTC_SW_POS,

    KEY_SPDIF_SW_SOURCE,

    KEY_BT_EMITTER_SW,
    KEY_BT_EMITTER_PLAY,
    KEY_BT_EMITTER_PAUSE,
    KEY_BT_EMITTER_RECEIVER_SW,

    KEY_SWITCH_PITCH_MODE,
    KEY_ENC_START,
    KEY_REVERB_SWITCH,
    KEY_REVERB_OPEN,
    KEY_REVERB_DEEPVAL_UP,
    KEY_REVERB_DEEPVAL_DOWN,
    KEY_REVERB_GAIN0_UP,
    KEY_REVERB_GAIN1_UP,
    KEY_REVERB_GAIN2_UP,
    // KEY_REVERB_GAIN_DOWN,

    KEY_TM_GMA_SEND,
    KEY_APP_SEND_SPEECH_START,
    KEY_SEND_SPEECH_START,
    KEY_SEND_SPEECH_STOP,
    KEY_AI_DEC_SUSPEND,
    KEY_AI_DEC_RESUME,
    KEY_DUEROS_CONNECTED,
    KEY_DUEROS_DISCONNECTED,
    KEY_DUEROS_VER,
    KEY_DUEROS_SEND,
    KEY_TWS_DUEROS_RAND_SET,
    KEY_TWS_BLE_SLAVE_SPEECH_START,
    KEY_SPEECH_START_FROM_TWS,
    KEY_SPEECH_STOP_FROM_TWS,
    KEY_TWS_BLE_DUEROS_CONNECT,
    KEY_TWS_BLE_DUEROS_DISCONNECT,

    KEY_TWS_SEARCH_PAIR,
    KEY_TWS_REMOVE_PAIR,
    KEY_TWS_SEARCH_REMOVE_PAIR,
    KEY_TWS_DISCONN,
    KEY_TWS_CONN,

    KEY_BOX_POWER_CLICK,
    KEY_BOX_POWER_LONG,
    KEY_BOX_POWER_HOLD,
    KEY_BOX_POWER_UP,
    KEY_BOX_POWER_DOUBLE,
    KEY_BOX_POWER_THREE,
    KEY_BOX_POWER_FOUR,
    KEY_BOX_POWER_FIVE,

    ///soundcard相关按键消息
    KEY_SOUNDCARD_MODE_ELECTRIC,
    KEY_SOUNDCARD_MODE_PITCH,
    KEY_SOUNDCARD_MODE_PITCH_BY_VALUE,
    KEY_SOUNDCARD_MODE_MAGIC,
    KEY_SOUNDCARD_MODE_BOOM,
    KEY_SOUNDCARD_MODE_SHOUTING_WHEAT,
    KEY_SOUNDCARD_MODE_DODGE,
    KEY_SOUNDCARD_MODE_ELECTRIC_CANCEL,

    KEY_SOUNDCARD_MAKE_NOISE0,
    KEY_SOUNDCARD_MAKE_NOISE1,
    KEY_SOUNDCARD_MAKE_NOISE2,
    KEY_SOUNDCARD_MAKE_NOISE3,
    KEY_SOUNDCARD_MAKE_NOISE4,
    KEY_SOUNDCARD_MAKE_NOISE5,
    KEY_SOUNDCARD_MAKE_NOISE6,
    KEY_SOUNDCARD_MAKE_NOISE7,
    KEY_SOUNDCARD_MAKE_NOISE8,
    KEY_SOUNDCARD_MAKE_NOISE9,
    KEY_SOUNDCARD_MAKE_NOISE10,
    KEY_SOUNDCARD_MAKE_NOISE11,
///旋钮按键
    KEY_SOUNDCARD_SLIDE_MIC,
    KEY_SOUNDCARD_SLIDE_WET_GAIN,
    KEY_SOUNDCARD_SLIDE_HIGH_SOUND,
    KEY_SOUNDCARD_SLIDE_LOW_SOUND,
    KEY_SOUNDCARD_SLIDE_RECORD_VOL,
    KEY_SOUNDCARD_SLIDE_MUSIC_VOL,
    KEY_SOUNDCARD_SLIDE_EARPHONE_VOL,

    KEY_SOUNDCARD_USB_MIC_MUTE_SWICH,
    KEY_SOUNDCARD_NORMAL_MIC_STATUS_UPDATE,
    KEY_SOUNDCARD_EAR_MIC_STATUS_UPDATE,
    KEY_SOUNDCARD_AUX_STATUS_UPDATE,


    KEY_TEST_DEMO_0,
    KEY_TEST_DEMO_1,

    KEY_IR_NUM_0,  //中间不允许插入
    KEY_IR_NUM_1,
    KEY_IR_NUM_2,
    KEY_IR_NUM_3,
    KEY_IR_NUM_4,
    KEY_IR_NUM_5,
    KEY_IR_NUM_6,
    KEY_IR_NUM_7,
    KEY_IR_NUM_8,
    KEY_IR_NUM_9,//中间不允许插入
    //在这里增加元素
    //
    KEY_HID_MODE_SWITCH,
    KEY_HID_TAKE_PICTURE,
    KEY_LINEIN_START,
    MSG_HALF_SECOND,//半秒的事件
    //不会出现在按键主流程，用于不重要得其他操作
    KEY_MINOR_OPT,

    KEY_NULL = 0xFFFF,

    KEY_MSG_MAX = 0xFFFF,
    //音箱sdk 按键消息已经加大为0xffff
};


enum {
    ONE_KEY_CTL_NEXT_PREV = 1,
    ONE_KEY_CTL_VOL_UP_DOWN,
};


#endif
