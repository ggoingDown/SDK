
        media_bss_start = .;
        . = ALIGN(4);
        *(.jlsp_bss)
		*(.aec_bss)
		*(.res_bss)
		*(.ns_bss)
		*(.der_bss)
		*(.nlp_bss)
		*(.qmf_bss)
		*(.bt_audioplc_bss)
		*(.fft_bss)
		*(.sms_bss)
        *(.pcm_bss)
		/* *(.cvsd_bss) */
		*(.g729_bss)
		*(.g726_bss)
		*(.wtg_dec_bss)
		*(.wtgv2_bss)
		*(.wtgv2dec_bss)
		*(.mp3_bss)
		*(.mp3_dec_bss)
		*(.msbc_bss)
		*(.mty_bss)
		*(.mp3tsy_dec_bss)
		*(.sbc_bss)
		*(.sine_bss)
		/* *(.wav_bss) */
		*(.wma_bss)
		*(.wma_dec_bss)
		/* *(.aac_bss) */
		*(.amr_bss)
		*(.midi_bss)
		/* *(.ape_bss) */
		*(.audio_decoder_bss)
		/* *(.dts_bss) */
		/* *(.flac_bss) */
		/* *(.m4a_bss) */
        *(.mp3_encode_bss)
		*(.media_device_bss)
		*(.audio_encoder_bss)
		*(.mixer_bss)
		*(.stream_bss)
		*(.dec_server_bss)
		*(.rec_server_bss)
		*(.auto_mute_bss)
		*(.plc_bss)
		*(.wireless_sync_bss)

		*(.audio_buf)

		*(.resample_cal_bss)
		*(.bt_crossOver_bss)
		*(.bt_compressor_bss)
		*(.bt_limiter_bss)
		*(.bt_limiter_sparse_bss)
		*(.bt_crossOver_sparse_bss)
		*(.bt_compressor_sparse_bss)

		*(.iap_bss)
		*(.audio_bfilt_bss)
		*(.audio_buf_sync_bss)
		*(.audio_dec_app_bss)
		*(.audio_dec_app_sync_bss)
		*(.audio_dig_vol_bss)
		*(.audio_echo_reverb_bss)
		*(.echo_cal_bss)
		*(.reverb_cal_bss)
		*(.reverb0_bss)
		*(.platereverb_bss)
		*(.audio_echo_src_bss)
		*(.audio_energy_detect_bss)
		*(.audio_eq_bss)
		*(.audio_drc_bss)
		*(.audio_eq_drc_apply_bss)
		*(.audio_equalloudness_bss)
		*(.audio_howling_bss)
		*(.howlings_phf_bss)
		*(.audio_noisegate_bss)
		*(.audio_output_dac_bss)
		*(.audio_pemafrow_bss)
		*(.audio_pitch_bss)
		*(.audio_pitchspeed_bss)
		*(.audio_surround_bss)
		*(.audio_vbass_bss)
		*(.audio_vocal_remove_bss)
		*(.audio_vocal_tract_synthesis_bss)
		*(.eq_config_bss)
		*(.eq_config_protocol_bss)
		*(.spectrum_eq_bss)
		*(.spectrum_fft_bss)
		*(.audio_localtws_bss)
		*(.audio_dec_localtws_bss)
		*(.audio_dec_a2dp_bss)
		*(.audio_dec_esco_bss)
		*(.audio_dec_file_bss)
		*(.audio_dec_pcm_bss)
		*(.audio_resample_bss)
		*(.audio_splicing_bss)
		*(.channel_switch_bss)
		*(.sw_drc_bss)
		*(.aptx_decoder_bss)
		*(.ldac_decoder_bss)
		*(.speex_encoder_bss)
		*(.sbc_encoder_bss)
		*(.opus_encoder_bss)
		*(.prevent_task_fill_bss)
		*(.audio_cfifo_bss)
		*(.audio_track_bss)
		*(.audio_adc_bss)
		*(.audio_dac_bss)
		*(.audio_linein_bss)
		*(.audio_link_bss)
		*(.audio_sample_sync_bss)
		*(.audio_wireless_sync_bss)
		*(.audio_spdif_bss)
		*(.audio_src_bss)
		*(.audio_src_base_bss)
		*(.effectrs_sync_bss)
		*(.eq_design_bss)
		*(.hw_eq_bss)
		*(.iic_bss)
		*(.mic_cap_bss)
		*(.sbc_hwaccel_bss)
		*(.resample_fastcal_bss)
		*(.lfwordana_bss)
        media_bss_end = .;




