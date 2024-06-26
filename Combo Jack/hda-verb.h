
/**
 * Parts of the hda-verb code released as part of the alsa-tools project
 *
 * Accessing HD-audio verbs via hwdep interface
 * Version 0.3
 *
 * Copyright (c) 2008 Takashi Iwai <tiwai@suse.de>
 *
 * Licensed under GPL v2 or later.
 */

#ifndef hdaverb_h
#define hdaverb_h

#define kALCUserClientProvider                     "ALCUserClientProvider"


#define AC_VERB_GET_STREAM_FORMAT               0x0a00
#define AC_VERB_GET_AMP_GAIN_MUTE               0x0b00
#define AC_VERB_GET_PROC_COEF                   0x0c00
#define AC_VERB_GET_COEF_INDEX                  0x0d00
#define AC_VERB_PARAMETERS                      0x0f00
#define AC_VERB_GET_CONNECT_SEL                 0x0f01
#define AC_VERB_GET_CONNECT_LIST                0x0f02
#define AC_VERB_GET_PROC_STATE                  0x0f03
#define AC_VERB_GET_SDI_SELECT                  0x0f04
#define AC_VERB_GET_POWER_STATE                 0x0f05
#define AC_VERB_GET_CONV                        0x0f06
#define AC_VERB_GET_PIN_WIDGET_CONTROL          0x0f07
#define AC_VERB_GET_UNSOLICITED_RESPONSE        0x0f08
#define AC_VERB_GET_PIN_SENSE                   0x0f09
#define AC_VERB_GET_BEEP_CONTROL                0x0f0a
#define AC_VERB_GET_EAPD_BTLENABLE              0x0f0c
#define AC_VERB_GET_DIGI_CONVERT_1              0x0f0d
#define AC_VERB_GET_DIGI_CONVERT_2              0x0f0e
#define AC_VERB_GET_VOLUME_KNOB_CONTROL         0x0f0f
#define AC_VERB_GET_GPIO_DATA                   0x0f15
#define AC_VERB_GET_GPIO_MASK                   0x0f16
#define AC_VERB_GET_GPIO_DIRECTION              0x0f17
#define AC_VERB_GET_GPIO_WAKE_MASK              0x0f18
#define AC_VERB_GET_GPIO_UNSOLICITED_RSP_MASK   0x0f19
#define AC_VERB_GET_GPIO_STICKY_MASK            0x0f1a
#define AC_VERB_GET_CONFIG_DEFAULT              0x0f1c
#define AC_VERB_GET_SUBSYSTEM_ID                0x0f20

#define AC_VERB_SET_STREAM_FORMAT               0x200
#define AC_VERB_SET_AMP_GAIN_MUTE               0x300
#define AC_VERB_SET_PROC_COEF                   0x400
#define AC_VERB_SET_COEF_INDEX                  0x500
#define AC_VERB_SET_CONNECT_SEL                 0x701
#define AC_VERB_SET_PROC_STATE                  0x703
#define AC_VERB_SET_SDI_SELECT                  0x704
#define AC_VERB_SET_POWER_STATE                 0x705
#define AC_VERB_SET_CHANNEL_STREAMID            0x706
#define AC_VERB_SET_PIN_WIDGET_CONTROL          0x707
#define AC_VERB_SET_UNSOLICITED_ENABLE          0x708
#define AC_VERB_SET_PIN_SENSE                   0x709
#define AC_VERB_SET_BEEP_CONTROL                0x70a
#define AC_VERB_SET_EAPD_BTLENABLE              0x70c
#define AC_VERB_SET_DIGI_CONVERT_1              0x70d
#define AC_VERB_SET_DIGI_CONVERT_2              0x70e
#define AC_VERB_SET_VOLUME_KNOB_CONTROL         0x70f
#define AC_VERB_SET_GPIO_DATA                   0x715
#define AC_VERB_SET_GPIO_MASK                   0x716
#define AC_VERB_SET_GPIO_DIRECTION              0x717
#define AC_VERB_SET_GPIO_WAKE_MASK              0x718
#define AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK   0x719
#define AC_VERB_SET_GPIO_STICKY_MASK            0x71a
#define AC_VERB_SET_CONFIG_DEFAULT_BYTES_0      0x71c
#define AC_VERB_SET_CONFIG_DEFAULT_BYTES_1      0x71d
#define AC_VERB_SET_CONFIG_DEFAULT_BYTES_2      0x71e
#define AC_VERB_SET_CONFIG_DEFAULT_BYTES_3      0x71f
#define AC_VERB_SET_CODEC_RESET                 0x7ff

#define AC_PAR_VENDOR_ID           0x00
#define AC_PAR_SUBSYSTEM_ID        0x01
#define AC_PAR_REV_ID              0x02
#define AC_PAR_NODE_COUNT          0x04
#define AC_PAR_FUNCTION_TYPE       0x05
#define AC_PAR_AUDIO_FG_CAP        0x08
#define AC_PAR_AUDIO_WIDGET_CAP    0x09
#define AC_PAR_PCM                 0x0a
#define AC_PAR_STREAM              0x0b
#define AC_PAR_PIN_CAP             0x0c
#define AC_PAR_AMP_IN_CAP          0x0d
#define AC_PAR_CONNLIST_LEN        0x0e
#define AC_PAR_POWER_STATE         0x0f
#define AC_PAR_PROC_CAP            0x10
#define AC_PAR_GPIO_CAP            0x11
#define AC_PAR_AMP_OUT_CAP         0x12
#define AC_PAR_VOL_KNB_CAP         0x13

#define VERBSTR(x)    { .val = AC_VERB_##x, .str = #x }
#define PARMSTR(x)    { .val = AC_PAR_##x, .str = #x }

/* verb */
#define HDA_REG_NID_SHIFT   24
#define HDA_REG_VERB_SHIFT  8
#define HDA_REG_VAL_SHIFT   0
//#define HDA_VERB(nid,verb,param) (nid << 20 | verb << 8 | param)

struct strtbl
{
    int val;
    const char *str;
};

static struct strtbl hda_verbs[] =
{
    VERBSTR(GET_STREAM_FORMAT),
    VERBSTR(GET_AMP_GAIN_MUTE),
    VERBSTR(GET_PROC_COEF),
    VERBSTR(GET_COEF_INDEX),
    VERBSTR(PARAMETERS),
    VERBSTR(GET_CONNECT_SEL),
    VERBSTR(GET_CONNECT_LIST),
    VERBSTR(GET_PROC_STATE),
    VERBSTR(GET_SDI_SELECT),
    VERBSTR(GET_POWER_STATE),
    VERBSTR(GET_CONV),
    VERBSTR(GET_PIN_WIDGET_CONTROL),
    VERBSTR(GET_UNSOLICITED_RESPONSE),
    VERBSTR(GET_PIN_SENSE),
    VERBSTR(GET_BEEP_CONTROL),
    VERBSTR(GET_EAPD_BTLENABLE),
    VERBSTR(GET_DIGI_CONVERT_1),
    VERBSTR(GET_DIGI_CONVERT_2),
    VERBSTR(GET_VOLUME_KNOB_CONTROL),
    VERBSTR(GET_GPIO_DATA),
    VERBSTR(GET_GPIO_MASK),
    VERBSTR(GET_GPIO_DIRECTION),
    VERBSTR(GET_GPIO_WAKE_MASK),
    VERBSTR(GET_GPIO_UNSOLICITED_RSP_MASK),
    VERBSTR(GET_GPIO_STICKY_MASK),
    VERBSTR(GET_CONFIG_DEFAULT),
    VERBSTR(GET_SUBSYSTEM_ID),
    
    VERBSTR(SET_STREAM_FORMAT),
    VERBSTR(SET_AMP_GAIN_MUTE),
    VERBSTR(SET_PROC_COEF),
    VERBSTR(SET_COEF_INDEX),
    VERBSTR(SET_CONNECT_SEL),
    VERBSTR(SET_PROC_STATE),
    VERBSTR(SET_SDI_SELECT),
    VERBSTR(SET_POWER_STATE),
    VERBSTR(SET_CHANNEL_STREAMID),
    VERBSTR(SET_PIN_WIDGET_CONTROL),
    VERBSTR(SET_UNSOLICITED_ENABLE),
    VERBSTR(SET_PIN_SENSE),
    VERBSTR(SET_BEEP_CONTROL),
    VERBSTR(SET_EAPD_BTLENABLE),
    VERBSTR(SET_DIGI_CONVERT_1),
    VERBSTR(SET_DIGI_CONVERT_2),
    VERBSTR(SET_VOLUME_KNOB_CONTROL),
    VERBSTR(SET_GPIO_DATA),
    VERBSTR(SET_GPIO_MASK),
    VERBSTR(SET_GPIO_DIRECTION),
    VERBSTR(SET_GPIO_WAKE_MASK),
    VERBSTR(SET_GPIO_UNSOLICITED_RSP_MASK),
    VERBSTR(SET_GPIO_STICKY_MASK),
    VERBSTR(SET_CONFIG_DEFAULT_BYTES_0),
    VERBSTR(SET_CONFIG_DEFAULT_BYTES_1),
    VERBSTR(SET_CONFIG_DEFAULT_BYTES_2),
    VERBSTR(SET_CONFIG_DEFAULT_BYTES_3),
    VERBSTR(SET_CODEC_RESET),
    { }, /* end */
};

static struct strtbl hda_params[] =
{
    PARMSTR(VENDOR_ID),
    PARMSTR(SUBSYSTEM_ID),
    PARMSTR(REV_ID),
    PARMSTR(NODE_COUNT),
    PARMSTR(FUNCTION_TYPE),
    PARMSTR(AUDIO_FG_CAP),
    PARMSTR(AUDIO_WIDGET_CAP),
    PARMSTR(PCM),
    PARMSTR(STREAM),
    PARMSTR(PIN_CAP),
    PARMSTR(AMP_IN_CAP),
    PARMSTR(CONNLIST_LEN),
    PARMSTR(POWER_STATE),
    PARMSTR(PROC_CAP),
    PARMSTR(GPIO_CAP),
    PARMSTR(AMP_OUT_CAP),
    PARMSTR(VOL_KNB_CAP),
    { }, /* end */
};

#endif /* hdaverb_h */

