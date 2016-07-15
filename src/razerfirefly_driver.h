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

#ifndef __HID_RAZER_FIREFLY_H
#define __HID_RAZER_FIREFLY_H


//#################//
//### Constants ###//
//#################//

#define USB_DEVICE_ID_RAZER_FIREFLY 0x0C00

#define RAZER_FIREFLY_ROW_LEN 0x0F

#define RAZER_FIREFLY_WAIT_MIN_US 900
#define RAZER_FIREFLY_WAIT_MAX_US 1000



//#############//
//### Types ###//
//#############//

struct razer_firefly_device {
    struct usb_device *usbdev;
    struct hid_device *hiddev;
    unsigned char effect;
    char name[128];
    char phys[64];
    bool effect_submitted;
    int brightness;
};


#endif
