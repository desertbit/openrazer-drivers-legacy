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

#ifndef USB_VENDOR_ID_RAZER
    #define USB_VENDOR_ID_RAZER 0x1532
#endif

#ifndef USB_DEVICE_ID_RAZER_BLACKWIDOW_ORIGINAL
    #define USB_DEVICE_ID_RAZER_BLACKWIDOW_ORIGINAL 0x011B
#endif

#ifndef USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2012
    #define USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2012 0x010D
#endif

#ifndef USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2013
    #define USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2013 0x011A
#endif

#ifndef USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2016
    #define USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2016 0x0214
#endif

#ifndef USB_DEVICE_ID_RAZER_BLADE_STEALTH
    #define USB_DEVICE_ID_RAZER_BLADE_STEALTH 0x0205
#endif

#ifndef USB_DEVICE_ID_RAZER_BLACKWIDOW_CHROMA
    #define USB_DEVICE_ID_RAZER_BLACKWIDOW_CHROMA 0x0203
#endif

#ifndef USB_DEVICE_ID_RAZER_BLACKWIDOW_CHROMA_TE
    #define USB_DEVICE_ID_RAZER_BLACKWIDOW_CHROMA_TE 0x0209
#endif


/* Each keyboard report has 90 bytes*/
#define RAZER_BLACKWIDOW_REPORT_LEN 0x5A

#define RAZER_BLACKWIDOW_CHROMA_WAVE_DIRECTION_LEFT 2
#define RAZER_BLACKWIDOW_CHROMA_WAVE_DIRECTION_RIGHT 1

#define RAZER_BLACKWIDOW_CHROMA_CHANGE_EFFECT 0x0A

#define RAZER_BLACKWIDOW_CHROMA_EFFECT_NONE 0
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_WAVE 1
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_REACTIVE 2
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_BREATH 3
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_SPECTRUM 4
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_CUSTOM 5 //update profile data
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_STATIC 6
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_CLEAR_ROW 8

#define RAZER_BLACKWIDOW_ULTIMATE_2016_EFFECT_STARLIGHT 0x19


#define RAZER_BLACKWIDOW_CHROMA_EFFECT_SET_KEYS 9 //update profile needs to be called after setting keys to reflect changes
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_RESET 10
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_UNKNOWN 11
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_UNKNOWN2 12
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_UNKNOWN3 13
#define RAZER_BLACKWIDOW_CHROMA_EFFECT_UNKNOWN4 14


#define RAZER_BLACKWIDOW_CHROMA_ROW_LEN 0x16
#define RAZER_BLACKWIDOW_CHROMA_ROWS_NUM 6

#define RAZER_FIREFLY_ROW_LEN 0x0F
#define RAZER_FIREFLY_ROWS_NUM 1


#define RAZER_STEALTH_ROW_LEN 0x10
#define RAZER_STEALTH_ROWS_NUM 6



#define RAZER_BLACKWIDOW_CHROMA_WAIT_MS 1
#define RAZER_BLACKWIDOW_CHROMA_WAIT_MIN_US 600
#define RAZER_BLACKWIDOW_CHROMA_WAIT_MAX_US 800

#define RAZER_FIREFLY_WAIT_MIN_US 900
#define RAZER_FIREFLY_WAIT_MAX_US 1000


struct razer_kbd_device {
    //struct input_dev *dev;
    struct usb_device *usbdev;
    struct hid_device *hiddev;
    unsigned char effect;
    char name[128];
    char phys[64];
    //struct razer_row_rgb matrix[RAZER_BLACKWIDOW_CHROMA_ROWS_NUM];
    bool effect_submitted;
};






#endif
