/*
 * Razer Kernel Drivers
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef __HID_RAZER_KEYBOARD_BLACKWIDOW_CHROMA_H
#define __HID_RAZER_KEYBOARD_BLACKWIDOW_CHROMA_H


//#################//
//### Constants ###//
//#################//

#define RAZER_KBD_WAIT_MIN_US 600
#define RAZER_KBD_WAIT_MAX_US 800

// Device IDs
#define USB_DEVICE_ID_RAZER_BLACKWIDOW_ORIGINAL 0x011B
#define USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2012 0x010D
#define USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2013 0x011A
#define USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2016 0x0214
#define USB_DEVICE_ID_RAZER_BLADE_STEALTH 0x0205
#define USB_DEVICE_ID_RAZER_BLADE_14_2016 0x020F
#define USB_DEVICE_ID_RAZER_BLACKWIDOW_CHROMA 0x0203
#define USB_DEVICE_ID_RAZER_BLACKWIDOW_CHROMA_TE 0x0209

#define RAZER_BLACKWIDOW_CHROMA_ROW_LEN 0x16
#define RAZER_STEALTH_ROW_LEN 0x10
#define RAZER_BLADE_14_2016_ROW_LEN 0x10



//#############//
//### Types ###//
//#############//

struct razer_kbd_device {
    struct usb_device *usbdev;
    struct hid_device *hiddev;
    unsigned char effect;
    char name[128];
    char phys[64];
    bool effect_submitted;
};

#endif
