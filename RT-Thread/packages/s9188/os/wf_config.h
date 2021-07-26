#ifndef __WF_CONFIG_H__
#define __WF_CONFIG_H__

/*
all gl configuration should be placed there
*/

#define SURVEY_TO       (100)
#define AUTH_TIMEOUT    (500)
#define ASSOC_TIMEOUT   (300)
#define ADDBA_TO        (2000)
#define LINKED_TO       (1)

#define REAUTH_LIMIT    (2)
#define REASSOC_LIMIT   (4)
#define READDBA_LIMIT   (2)


#define CFG_SUPPORT_WAPI 1
#define CFG_SUPPORT_PASSPOINT   0

/*------------------------------------------------------------------------------
 * Flags of Wi-Fi Direct support
 *------------------------------------------------------------------------------
 */
#ifdef LINUX
#ifdef CONFIG_X86
#define CFG_ENABLE_WIFI_DIRECT          1
#define CFG_SUPPORT_802_11W             1
#define CONFIG_SUPPORT_GTK_REKEY        1
#else
#define CFG_ENABLE_WIFI_DIRECT          1
#define CFG_SUPPORT_802_11W             1   /*!< 0(default): Disable 802.11W */
#define CONFIG_SUPPORT_GTK_REKEY        1
#endif
#else /* !LINUX */
#define CFG_ENABLE_WIFI_DIRECT           0
#define CFG_SUPPORT_802_11W              0  /* Not support at WinXP */
#endif /* LINUX */

#define CFG_SUPPORT_802_11D              1

#define CONFIG_NATIVEAP_MLME
#ifndef CONFIG_NATIVEAP_MLME
#define CONFIG_HOSTAPD_MLME
#endif



#define MACID_NUM_SW_LIMIT 32
#define SEC_CAM_ENT_NUM_SW_LIMIT 32

#ifdef CONFIG_MP_INCLUDED
#define MP_DRIVER   1
#define CONFIG_MP_IWPRIV_SUPPORT
#else /* !CONFIG_MP_INCLUDED */
#define MP_DRIVER   0
#endif /* !CONFIG_MP_INCLUDED */

//#define WF_CONFIG_P2P
#ifdef WF_CONFIG_P2P
#define CONFIG_WFD
#define CONFIG_P2P_OP_CHK_SOCIAL_CH
#define CONFIG_CFG80211_ONECHANNEL_UNDER_CONCURRENT	/* replace CONFIG_P2P_CHK_INVITE_CH_LIST flag */
#define CONFIG_P2P_INVITE_IOT
#endif

#if (!defined(MCU_CMD_MAILBOX) && !defined(MCU_CMD_TXD))
#define MCU_CMD_MAILBOX
#endif

#ifdef __RTTHREAD__
#define WF_VERSION            "1.0.0"
#define WIFI_CFG_DIR          "/etc/wifi.cfg"
#define WIFI_FW_DIR           "/lib/firmware/fw_9188_r1657.bin"

//#define CFG_ENABLE_AP_MODE
#define MCU_CMD_MAILBOX
//#define CONFIG_ARS_FIRMWARE_SUPPORT
// tx frame  number
#define NR_XMITFRAME           8
////open tx soft agg
//#define CONFIG_SOFT_TX_AGGREGATION
//open rx soft agg
#define CONFIG_SOFT_RX_AGGREGATION

#endif

#endif      /* END OF __WF_CONFIG_H__ */