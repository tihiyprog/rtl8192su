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
#ifndef __REALTEK_PCI92SE_HW_H__
#define __REALTEK_PCI92SE_HW_H__

enum WIRELESS_NETWORK_TYPE {
	WIRELESS_11B = 1,
	WIRELESS_11G = 2,
	WIRELESS_11A = 4,
	WIRELESS_11N = 8
};

void rtl92su_get_hw_reg(struct ieee80211_hw *hw,
			u8 variable, u8 *val);
void rtl92su_read_chip_version(struct ieee80211_hw *hw);
void rtl92su_read_eeprom_info(struct ieee80211_hw *hw);
void rtl92su_interrupt_recognized(struct ieee80211_hw *hw,
				  u32 *inta, u32 *intb);
int rtl92su_hw_init(struct ieee80211_hw *hw);
void rtl92su_card_disable(struct ieee80211_hw *hw);
void rtl92su_enable_interrupt(struct ieee80211_hw *hw);
void rtl92su_disable_interrupt(struct ieee80211_hw *hw);
int rtl92su_set_network_type(struct ieee80211_hw *hw,
			     enum nl80211_iftype type);
void rtl92su_set_check_bssid(struct ieee80211_hw *hw, bool check_bssid);
void rtl92su_set_qos(struct ieee80211_hw *hw, int aci);
void rtl92su_set_beacon_related_registers(struct ieee80211_hw *hw);
void rtl92su_set_beacon_interval(struct ieee80211_hw *hw);
void rtl92su_update_interrupt_mask(struct ieee80211_hw *hw,
				   u32 add_msr, u32 rm_msr);
void rtl92su_set_hw_reg(struct ieee80211_hw *hw, u8 variable,
			u8 *val);
void rtl92su_update_hal_rate_tbl(struct ieee80211_hw *hw,
		struct ieee80211_sta *sta, u8 rssi_level);
void rtl92su_update_channel_access_setting(struct ieee80211_hw *hw);
bool rtl92su_gpio_radio_on_off_checking(struct ieee80211_hw *hw,
					u8 *valid);
void rtl92su_enable_hw_security_config(struct ieee80211_hw *hw);
void rtl92su_set_key(struct ieee80211_hw *hw,
		     u32 key_index, u8 *macaddr, bool is_group,
		     u8 enc_algo, bool is_wepkey, bool clear_all);
void rtl92su_suspend(struct ieee80211_hw *hw);
void rtl92su_resume(struct ieee80211_hw *hw);

#endif
