/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#define CONFIG_ODM_REFRESH_RAMASK
#define CONFIG_PHY_SETTING_WITH_ODM

/*
 * Public  General Config
 */

#define AUTOCONF_INCLUDED

#define RTL871X_MODULE_NAME "8723AS-VAU"
#define DRV_NAME "rtl8723as-vau"

#define PLATFORM_LINUX

#define CONFIG_EMBEDDED_FWIMG
//#define CONFIG_FILE_FWIMG

/*
 * Functions Config
 */

#define CONFIG_XMIT_ACK
#ifdef CONFIG_XMIT_ACK
	#define CONFIG_ACTIVE_KEEP_ALIVE_CHECK
#endif
#define CONFIG_80211N_HT
#define CONFIG_RECV_REORDERING_CTRL


#define SUPPORT_HW_RFOFF_DETECTED

//#define RTW_USE_CFG80211_STA_EVENT /* Indecate new sta asoc through cfg80211_new_sta */
//	#define CONFIG_CFG80211_FORCE_COMPATIBLE_2_6_37_UNDER
//#define CONFIG_DEBUG_CFG80211
#define CONFIG_SET_SCAN_DENY_TIMER

#define CONFIG_AP_MODE
#ifdef CONFIG_AP_MODE
	#define CONFIG_NATIVEAP_MLME
	#ifndef CONFIG_NATIVEAP_MLME
		#define CONFIG_HOSTAPD_MLME
	#endif
	//#define CONFIG_FIND_BEST_CHANNEL
#endif

#define CONFIG_P2P
#ifdef CONFIG_P2P
	//Added by Albert 20110812
	//The CONFIG_WFD is for supporting the Wi-Fi display
	#define CONFIG_WFD

	#ifndef CONFIG_WIFI_TEST
		#define CONFIG_P2P_REMOVE_GROUP_INFO
	#endif
	//#define CONFIG_DBG_P2P

	#define CONFIG_P2P_PS
	//#define CONFIG_P2P_IPS
#endif

//	Added by Kurt 20110511
//#define CONFIG_TDLS
#ifdef CONFIG_TDLS
//	#ifndef CONFIG_WFD
//		#define CONFIG_WFD
//	#endif
//	#define CONFIG_TDLS_AUTOSETUP
//	#define CONFIG_TDLS_AUTOCHECKALIVE
#endif

#define CONFIG_LAYER2_ROAMING
#define CONFIG_LAYER2_ROAMING_RESUME

#define CONFIG_SKB_COPY	//for amsdu

//#define CONFIG_LED

#define USB_INTERFERENCE_ISSUE // this should be checked in all usb interface
#define CONFIG_LONG_DELAY_ISSUE
#define CONFIG_NEW_SIGNAL_STAT_PROCESS
#define RTW_NOTCH_FILTER 0 /* 0:Disable, 1:Enable,  */

#ifdef CONFIG_ANTENNA_DIVERSITY
#define CONFIG_SW_ANTENNA_DIVERSITY
#endif


/*
 * Auto Config Section
 */

#undef CONFIG_MP_IWPRIV_SUPPORT
#define CONFIG_LPS		1



#ifdef CONFIG_LED
	#define CONFIG_SW_LED
	#ifdef CONFIG_SW_LED
		//#define CONFIG_LED_HANDLED_BY_CMD_THREAD
	#endif
#endif // CONFIG_LED

#ifdef CONFIG_POWER_SAVING

#define CONFIG_IPS
//#define CONFIG_LPS_LCLK
#endif // #ifdef CONFIG_POWER_SAVING

#ifdef CONFIG_LPS_LCLK
#define CONFIG_XMIT_THREAD_MODE
#endif

//#define CONFIG_BR_EXT		// Enable NAT2.5 support for STA mode interface with a L2 Bridge
#ifdef CONFIG_BR_EXT
#define CONFIG_BR_EXT_BRNAME	"br0"
#endif	// CONFIG_BR_EXT

#if defined(CONFIG_BT_COEXIST) || defined(CONFIG_POWER_SAVING)
#ifndef CONFIG_USB_INTERRUPT_IN_PIPE
#define CONFIG_USB_INTERRUPT_IN_PIPE
#endif
#endif

/*
 * Interface  Related Config
 */
//#define CONFIG_USB_INTERRUPT_IN_PIPE


#define CONFIG_PREALLOC_RECV_SKB
//#define CONFIG_REDUCE_USB_TX_INT		// Trade-off: Improve performance, but may cause TX URBs blocked by USB Host/Bus driver on few platforms.

/*
 * CONFIG_USE_USB_BUFFER_ALLOC_XX uses Linux USB Buffer alloc API and is for Linux platform only now!
 */
//#define CONFIG_USE_USB_BUFFER_ALLOC_TX	// Trade-off: For TX path, improve stability on some platforms, but may cause performance degrade on other platforms.
//#define CONFIG_USE_USB_BUFFER_ALLOC_RX	// For RX path
#ifdef CONFIG_USE_USB_BUFFER_ALLOC_RX
#undef CONFIG_PREALLOC_RECV_SKB
#endif

/*
 * USB VENDOR REQ BUFFER ALLOCATION METHOD
 * if not set we'll use function local variable (stack memory)
 */
//#define CONFIG_USB_VENDOR_REQ_BUFFER_DYNAMIC_ALLOCATE
#define CONFIG_USB_VENDOR_REQ_BUFFER_PREALLOC

#define CONFIG_USB_VENDOR_REQ_MUTEX
#define CONFIG_VENDOR_REQ_RETRY

//#define CONFIG_USB_SUPPORT_ASYNC_VDN_REQ


/*
 * HAL  Related Config
 */

#define RTL8192C_RX_PACKET_INCLUDE_CRC	0

#define SUPPORTED_BLOCK_IO



#define RTL8192CU_FW_DOWNLOAD_ENABLE	1

//#define CONFIG_ONLY_ONE_OUT_EP_TO_LOW	0

#define CONFIG_OUT_EP_WIFI_MODE	0

#define ENABLE_USB_DROP_INCORRECT_OUT	0

#define RTL8192CU_ASIC_VERIFICATION	0	// For ASIC verification.

#define RTL8192CU_ADHOC_WORKAROUND_SETTING

#define DISABLE_BB_RF	0

#define RTL8191C_FPGA_NETWORKTYPE_ADHOC 0

#define MP_DRIVER 0


/*
 * Outsource  Related Config
 */

#define		RTL8192CE_SUPPORT				0
#define		RTL8192CU_SUPPORT			0
#define		RTL8192C_SUPPORT				(RTL8192CE_SUPPORT|RTL8192CU_SUPPORT)

#define		RTL8192DE_SUPPORT				0
#define		RTL8192DU_SUPPORT			0
#define		RTL8192D_SUPPORT				(RTL8192DE_SUPPORT|RTL8192DU_SUPPORT)

#define		RTL8723AU_SUPPORT				1
#define		RTL8723AS_SUPPORT				0
#define		RTL8723AE_SUPPORT				0
#define		RTL8723A_SUPPORT				(RTL8723AU_SUPPORT|RTL8723AS_SUPPORT|RTL8723AE_SUPPORT)

#define		RTL8723_FPGA_VERIFICATION		0

#define RTL8188EE_SUPPORT				0
#define RTL8188EU_SUPPORT				0
#define RTL8188ES_SUPPORT				0
#define RTL8188E_SUPPORT				(RTL8188EE_SUPPORT|RTL8188EU_SUPPORT|RTL8188ES_SUPPORT)
#define RTL8188E_FOR_TEST_CHIP			0
//#if (RTL8188E_SUPPORT==1)
#define RATE_ADAPTIVE_SUPPORT			0
#define POWER_TRAINING_ACTIVE			0
//#endif

#define CONFIG_80211D

#define CONFIG_ATTEMPT_TO_FIX_AP_BEACON_ERROR

/*
 * Debug Related Config
 */
#define DBG	1

#define CONFIG_DEBUG /* DBG_8723A, etc... */
//#define CONFIG_DEBUG_RTL871X /* RT_TRACE, RT_PRINT_DATA, _func_enter_, _func_exit_ */

#define CONFIG_PROC_DEBUG

#define DBG_CONFIG_ERROR_DETECT
#define DBG_CONFIG_ERROR_RESET

//#define DBG_IO
//#define DBG_DELAY_OS
//#define DBG_MEM_ALLOC
//#define DBG_IOCTL

//#define DBG_TX
//#define DBG_XMIT_BUF
//#define DBG_TX_DROP_FRAME

//#define DBG_RX_DROP_FRAME
//#define DBG_RX_SEQ

//#define DBG_SHOW_MCUFWDL_BEFORE_51_ENABLE
//#define DBG_ROAMING_TEST

//#define DBG_HAL_INIT_PROFILING

//TX use 1 urb
//#define CONFIG_SINGLE_XMIT_BUF
//RX use 1 urb
//#define CONFIG_SINGLE_RECV_BUF
