/******************************************************************************
 *
 * Copyright(c) 2009-2012  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/
#ifndef __REALTEK_PCI92SE_TRX_H__
#define __REALTEK_PCI92SE_TRX_H__

#define RTL92S_USB_BULK_IN_NUM			1
#define RTL92S_NUM_RX_URBS			8

#define RTL92S_SIZE_MAX_RX_BUFFER		30720
#define RX_DRV_INFO_SIZE_UNIT			8

int rtl8192su_endpoint_mapping(struct ieee80211_hw *hw);
u16 rtl8192su_mq_to_hwq(__le16 fc, u16 mac80211_queue_index);
bool rtl92su_rx_query_desc(struct ieee80211_hw *hw, struct rtl_stats *stats,
			   struct ieee80211_rx_status *rx_status, u8 *pdesc,
			   struct sk_buff *skb);
void  rtl8192su_rx_hdl(struct ieee80211_hw *hw, struct sk_buff * skb);
void rtl8192s_tx_cleanup(struct ieee80211_hw *hw, struct sk_buff  *skb);
int rtl8192s_tx_post_hdl(struct ieee80211_hw *hw, struct urb *urb,
			 struct sk_buff *skb);
struct sk_buff *rtl8192s_tx_aggregate_hdl(struct ieee80211_hw *,
					   struct sk_buff_head *);
void rtl92su_tx_fill_desc(struct ieee80211_hw *hw, struct ieee80211_hdr *hdr,
			  u8 *pdesc, struct ieee80211_tx_info *info,
			  struct sk_buff *skb, u8 hw_queue,
			  struct rtl_tcb_desc *ptcb_desc);
void rtl92su_tx_fill_cmddesc(struct ieee80211_hw *hw, u8 *pdesc, bool firstseg,
			     bool lastseg, struct sk_buff *skb);
void rtl92su_set_desc(u8 *pdesc, bool istx, u8 desc_name, u8 *val);
u32 rtl92su_get_desc(u8 *pdesc, bool istx, u8 desc_name);
void rtl92su_tx_polling(struct ieee80211_hw *hw, u8 hw_queue);
