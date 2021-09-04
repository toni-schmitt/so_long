/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:35:22 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/03 21:47:08 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

/*
 *  Summary:
 *    Virtual keycodes
 *  
 *  Discussion:
 *    These constants are the virtual keycodes defined originally in
 *    Inside Mac Volume V, pg. V-191. They identify physical keys on a
 *    keyboard. Those constants with "ANSI" in the name are labeled
 *    according to the key position on an ANSI-standard US keyboard.
 *    For example, KEY_A indicates the virtual keycode for the key
 *    with the letter 'A' in the US keyboard layout. Other keyboard
 *    layouts may have the 'A' key label on a different physical key;
 *    in this case, pressing 'A' will generate a different virtual
 *    keycode.
 */
enum
{
	KEY_A = 0x00,
	KEY_S = 0x01,
	KEY_D = 0x02,
	KEY_F = 0x03,
	KEY_H = 0x04,
	KEY_G = 0x05,
	KEY_Z = 0x06,
	KEY_X = 0x07,
	KEY_C = 0x08,
	KEY_V = 0x09,
	KEY_B = 0x0B,
	KEY_Q = 0x0C,
	KEY_W = 0x0D,
	KEY_E = 0x0E,
	KEY_R = 0x0F,
	KEY_Y = 0x10,
	KEY_T = 0x11,
	KEY_1 = 0x12,
	KEY_2 = 0x13,
	KEY_3 = 0x14,
	KEY_4 = 0x15,
	KEY_6 = 0x16,
	KEY_5 = 0x17,
	KEY_EQUAL = 0x18,
	KEY_9 = 0x19,
	KEY_7 = 0x1A,
	KEY_MINUS = 0x1B,
	KEY_8 = 0x1C,
	KEY_0 = 0x1D,
	KEY_RIGHTBRACKET = 0x1E,
	KEY_O = 0x1F,
	KEY_U = 0x20,
	KEY_LEFTBRACKET = 0x21,
	KEY_I = 0x22,
	KEY_P = 0x23,
	KEY_L = 0x25,
	KEY_J = 0x26,
	KEY_QUOTE = 0x27,
	KEY_K = 0x28,
	KEY_SEMICOLON = 0x29,
	KEY_BACKSLASH = 0x2A,
	KEY_COMMA = 0x2B,
	KEY_SLASH = 0x2C,
	KEY_N = 0x2D,
	KEY_M = 0x2E,
	KEY_PERIOD = 0x2F,
	KEY_GRAVE = 0x32,
	KEY_KEYPADDECIMAL = 0x41,
	KEY_KEYPADMULTIPLY = 0x43,
	KEY_KEYPADPLUS = 0x45,
	KEY_KEYPADCLEAR = 0x47,
	KEY_KEYPADDIVIDE = 0x4B,
	KEY_KEYPADENTER = 0x4C,
	KEY_KEYPADMINUS = 0x4E,
	KEY_KEYPADEQUALS = 0x51,
	KEY_KEYPAD0 = 0x52,
	KEY_KEYPAD1 = 0x53,
	KEY_KEYPAD2 = 0x54,
	KEY_KEYPAD3 = 0x55,
	KEY_KEYPAD4 = 0x56,
	KEY_KEYPAD5 = 0x57,
	KEY_KEYPAD6 = 0x58,
	KEY_KEYPAD7 = 0x59,
	KEY_KEYPAD8 = 0x5B,
	KEY_KEYPAD9 = 0x5C
};

/* keycodes for keys that are independent of keyboard layout*/
enum
{
	KEY_RETURN = 0x24,
	KEY_TAB = 0x30,
	KEY_SPACE = 0x31,
	KEY_DELETE = 0x33,
	KEY_ESCAPE = 0x35,
	KEY_COMMAND = 0x37,
	KEY_SHIFT = 0x38,
	KEY_CAPSLOCK = 0x39,
	KEY_OPTION = 0x3A,
	KEY_CONTROL = 0x3B,
	KEY_RIGHTSHIFT = 0x3C,
	KEY_RIGHTOPTION = 0x3D,
	KEY_RIGHTCONTROL = 0x3E,
	KEY_FUNCTION = 0x3F,
	KEY_F17 = 0x40,
	KEY_VOLUMEUP = 0x48,
	KEY_VOLUMEDOWN = 0x49,
	KEY_MUTE = 0x4A,
	KEY_F18 = 0x4F,
	KEY_F19 = 0x50,
	KEY_F20 = 0x5A,
	KEY_F5 = 0x60,
	KEY_F6 = 0x61,
	KEY_F7 = 0x62,
	KEY_F3 = 0x63,
	KEY_F8 = 0x64,
	KEY_F9 = 0x65,
	KEY_F11 = 0x67,
	KEY_F13 = 0x69,
	KEY_F16 = 0x6A,
	KEY_F14 = 0x6B,
	KEY_F10 = 0x6D,
	KEY_F12 = 0x6F,
	KEY_F15 = 0x71,
	KEY_HELP = 0x72,
	KEY_HOME = 0x73,
	KEY_PAGEUP = 0x74,
	KEY_FORWARDDELETE = 0x75,
	KEY_F4 = 0x76,
	KEY_END = 0x77,
	KEY_F2 = 0x78,
	KEY_PAGEDOWN = 0x79,
	KEY_F1 = 0x7A,
	KEY_LEFTARROW = 0x7B,
	KEY_RIGHTARROW = 0x7C,
	KEY_DOWNARROW = 0x7D,
	KEY_UPARROW = 0x7E
};

#endif