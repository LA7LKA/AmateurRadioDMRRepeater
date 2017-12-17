uint8_t RF_POWER_UP[] = {0x02, 0x01, 0x00, 0x01, 0x8C, 0xBA, 0x80};

uint8_t RF_GPIO_PIN_CFG[] = {0x13, 0x00, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00};

uint8_t RF_GLOBAL_XO_TUNE_2[] = {0x11, 0x00, 0x02, 0x00, 0x52, 0x00};

uint8_t RF_GLOBAL_CONFIG_1[] = {0x11, 0x00, 0x01, 0x03, 0x60};

uint8_t RF_INT_CTL_ENABLE_2[] = {0x11, 0x01, 0x02, 0x00, 0x01, 0x10};

uint8_t RF_FRR_CTL_A_MODE_4[] = {0x11, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t RF_PREAMBLE_TX_LENGTH_9[] = {0x11, 0x10, 0x09, 0x00, 0x08, 0x14, 0x00, 0x0F, 0x31, 0x00, 0x00, 0x00, 0x00};

uint8_t RF_SYNC_CONFIG_5[] = {0x11, 0x11, 0x05, 0x00, 0x09, 0xB4, 0x2B, 0x00, 0x00};

uint8_t RF_PKT_CRC_CONFIG_7[] = {0x11, 0x12, 0x07, 0x00, 0x84, 0x00, 0x30, 0xFF, 0xFF, 0x00, 0x22};

uint8_t RF_PKT_LEN_12[] = {0x11, 0x12, 0x0C, 0x08, 0x00, 0x00, 0x00, 0x21, 0x21, 0x00, 0x21, 0x14, 0x80, 0x00, 0x00, 0x00};

uint8_t RF_PKT_FIELD_2_CRC_CONFIG_12[] = {0x11, 0x12, 0x0C, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t RF_PKT_FIELD_5_CRC_CONFIG_12[] = {0x11, 0x12, 0x0C, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t RF_PKT_RX_FIELD_3_CRC_CONFIG_9[] = {0x11, 0x12, 0x09, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t RF_MODEM_MOD_TYPE_12[] = {0x11, 0x20, 0x0C, 0x00, 0x04, 0x00, 0x07, 0x01, 0x77, 0x00, 0x01, 0x8C, 0xBA, 0x80, 0x00, 0x12};

uint8_t RF_MODEM_FREQ_DEV_0_1[] = {0x11, 0x20, 0x01, 0x0C, 0xE8};

uint8_t RF_MODEM_TX_RAMP_DELAY_8[] = {0x11, 0x20, 0x08, 0x18, 0x04, 0x00, 0x08, 0x03, 0x80, 0x00, 0x10, 0x10};

uint8_t RF_MODEM_BCR_OSR_1_9[] = {0x11, 0x20, 0x09, 0x22, 0x01, 0xC3, 0x01, 0x22, 0x60, 0x00, 0x11, 0x02, 0x02};

uint8_t RF_MODEM_AFC_GEAR_7[] = {0x11, 0x20, 0x07, 0x2C, 0x00, 0x12, 0x80, 0x61, 0x08, 0xC7, 0xA0};

uint8_t RF_MODEM_AGC_CONTROL_1[] = {0x11, 0x20, 0x01, 0x35, 0xE2};

uint8_t RF_MODEM_AGC_WINDOW_SIZE_9[] = {0x11, 0x20, 0x09, 0x38, 0x11, 0x63, 0x63, 0x00, 0x02, 0xFF, 0xFF, 0x00, 0x2A};

uint8_t RF_MODEM_OOK_CNT1_9[] = {0x11, 0x20, 0x09, 0x42, 0xA4, 0x03, 0xD6, 0x03, 0x02, 0xED, 0x01, 0xF0, 0xFE};

uint8_t RF_MODEM_RSSI_CONTROL_1[] = {0x11, 0x20, 0x01, 0x4C, 0x00};

uint8_t RF_MODEM_RSSI_COMP_1[] = {0x11, 0x20, 0x01, 0x4E, 0x40};

uint8_t RF_MODEM_CLKGEN_BAND_1[] = {0x11, 0x20, 0x01, 0x51, 0x0A};

uint8_t RF_MODEM_CHFLT_RX1_CHFLT_COE13_7_0_12[] = {0x11, 0x21, 0x0C, 0x00, 0xFF, 0xBA, 0x0F, 0x51, 0xCF, 0xA9, 0xC9, 0xFC, 0x1B, 0x1E, 0x0F, 0x01};

uint8_t RF_MODEM_CHFLT_RX1_CHFLT_COE1_7_0_12[] = {0x11, 0x21, 0x0C, 0x0C, 0xFC, 0xFD, 0x15, 0xFF, 0x00, 0x0F, 0xFF, 0xBA, 0x0F, 0x51, 0xCF, 0xA9};

uint8_t RF_MODEM_CHFLT_RX2_CHFLT_COE7_7_0_12[] = {0x11, 0x21, 0x0C, 0x18, 0xC9, 0xFC, 0x1B, 0x1E, 0x0F, 0x01, 0xFC, 0xFD, 0x15, 0xFF, 0x00, 0x0F};

uint8_t RF_PA_MODE_4[] = {0x11, 0x22, 0x04, 0x00, 0x08, 0x7F, 0x00, 0x3D};

uint8_t RF_SYNTH_PFDCP_CPFF_7[] = {0x11, 0x23, 0x07, 0x00, 0x2C, 0x0E, 0x0B, 0x04, 0x0C, 0x73, 0x03};

uint8_t RF_MATCH_VALUE_1_12[] = {0x11, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t RF_FREQ_CONTROL_INTE_8[] = {0x11, 0x40, 0x08, 0x00, 0x41, 0x0B, 0xB1, 0x3B, 0x07, 0xE0, 0x20, 0xFE};
