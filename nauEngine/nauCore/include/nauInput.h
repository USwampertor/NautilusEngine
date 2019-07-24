/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauInput.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/23 2019
 * @brief Input Object
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK 
{

namespace KEY
{
enum CODE
{
  ERRORED             = -1,
  NONE                = 0,
  BACKSPACE           = 1,
  DEL                 = 2,
  TAB                 = 3,
  KEYPAD0             = 4,
  KEYPAD1             = 5,
  KEYPAD2             = 6,
  KEYPAD3             = 7,
  KEYPAD4             = 8,
  KEYPAD5             = 9,
  KEYPAD6             = 10,
  KEYPAD7             = 11,
  KEYPAD8             = 12,
  KEYPAD9             = 13,
  KEYPADDOT           = 14,
  KEYPADENTER         = 15,
  KEYPADPLUS          = 16,
  KEYPADMINUS         = 17,
  KEYPADMULT          = 18,
  KEYPADDIV           = 19,
  KEYPADEQUAL         = 20,
  ARROWUP             = 21,
  ARROWDOWN           = 22,
  ARROWLEFT           = 23,
  ARROWRIGHT          = 24,
  F1                  = 25,
  F2                  = 26,
  F3                  = 27,
  F4                  = 28,
  F5                  = 29,
  F6                  = 30,
  F7                  = 31,
  F8                  = 32,
  F9                  = 33,
  F10                 = 34,
  F11                 = 35,
  F12                 = 36,
  F13                 = 37,
  F14                 = 38,
  F15                 = 39,
  ALPHA0              = 40,
  ALPHA1              = 41,
  ALPHA2              = 42,
  ALPHA3              = 43,
  ALPHA4              = 44,
  ALPHA5              = 45,
  ALPHA6              = 46,
  ALPHA7              = 47,
  ALPHA8              = 48,
  ALPHA9              = 49,
  A                   = 50,
  B                   = 51,
  C                   = 52,
  D                   = 53,
  E                   = 54,
  F                   = 55,
  G                   = 56,
  H                   = 57,
  I                   = 58,
  J                   = 59,
  K                   = 60,
  L                   = 61,
  M                   = 62,
  N                   = 63,
  O                   = 64,
  P                   = 65,
  Q                   = 66,
  R                   = 67,
  S                   = 68,
  T                   = 69,
  U                   = 70,
  V                   = 71,
  W                   = 72,
  X                   = 73,
  Y                   = 74,
  Z                   = 75,
  MOUSE0              = 76,
  MOUSE1              = 77,
  MOUSE2              = 78,
  MOUSE3              = 79,
  MOUSE4              = 80,
  MOUSE5              = 81,
  MOUSE6              = 82,
  JOYSTICK0BUTTON0    = 83,
  JOYSTICK0BUTTON1    = 84,
  JOYSTICK0BUTTON2    = 85,
  JOYSTICK0BUTTON3    = 86,
  JOYSTICK0BUTTON4    = 87,
  JOYSTICK0BUTTON5    = 88,
  JOYSTICK0BUTTON6    = 89,
  JOYSTICK0BUTTON7    = 90,
  JOYSTICK0BUTTON8    = 91,
  JOYSTICK0BUTTON9    = 92,
  JOYSTICK0BUTTON10   = 93,
  JOYSTICK0BUTTON11   = 94,
  JOYSTICK0BUTTON12   = 95,
  JOYSTICK0BUTTON13   = 96,
  JOYSTICK0BUTTON14   = 97,
  JOYSTICK0BUTTON15   = 98,
  JOYSTICK0BUTTON16   = 99,
  JOYSTICK0BUTTON17   = 100,
  JOYSTICK0BUTTON18   = 101,
  JOYSTICK0BUTTON19   = 102,
  JOYSTICK1BUTTON0 = 103,
  JOYSTICK1BUTTON1 = 104,
  JOYSTICK1BUTTON2 = 105,
  JOYSTICK1BUTTON3 = 106,
  JOYSTICK1BUTTON4 = 107,
  JOYSTICK1BUTTON5 = 108,
  JOYSTICK1BUTTON6 = 109,
  JOYSTICK1BUTTON7 = 110,
  JOYSTICK1BUTTON8 = 111,
  JOYSTICK1BUTTON9 = 112,
  JOYSTICK1BUTTON10 = 113,
  JOYSTICK1BUTTON11 = 114,
  JOYSTICK1BUTTON12 = 115,
  JOYSTICK1BUTTON13 = 116,
  JOYSTICK1BUTTON14 = 117,
  JOYSTICK1BUTTON15 = 118,
  JOYSTICK1BUTTON16 = 119,
  JOYSTICK1BUTTON17 = 120,
  JOYSTICK1BUTTON18 = 121,
  JOYSTICK1BUTTON19 = 122,
  JOYSTICK2BUTTON0 = 123,
  JOYSTICK2BUTTON1 = 124,
  JOYSTICK2BUTTON2 = 125,
  JOYSTICK2BUTTON3 = 126,
  JOYSTICK2BUTTON4 = 127,
  JOYSTICK2BUTTON5 = 128,
  JOYSTICK2BUTTON6 = 129,
  JOYSTICK2BUTTON7 = 130,
  JOYSTICK2BUTTON8 = 131,
  JOYSTICK2BUTTON9 = 132,
  JOYSTICK2BUTTON10 = 133,
  JOYSTICK2BUTTON11 = 134,
  JOYSTICK2BUTTON12 = 135,
  JOYSTICK2BUTTON13 = 136,
  JOYSTICK2BUTTON14 = 137,
  JOYSTICK2BUTTON15 = 138,
  JOYSTICK2BUTTON16 = 139,
  JOYSTICK2BUTTON17 = 140,
  JOYSTICK2BUTTON18 = 141,
  JOYSTICK2BUTTON19 = 142,
  JOYSTICK3BUTTON0 = 143,
  JOYSTICK3BUTTON1 = 144,
  JOYSTICK3BUTTON2 = 145,
  JOYSTICK3BUTTON3 = 146,
  JOYSTICK3BUTTON4 = 147,
  JOYSTICK3BUTTON5 = 148,
  JOYSTICK3BUTTON6 = 149,
  JOYSTICK3BUTTON7 = 150,
  JOYSTICK3BUTTON8 = 151,
  JOYSTICK3BUTTON9 = 152,
  JOYSTICK3BUTTON10 = 153,
  JOYSTICK3BUTTON11 = 154,
  JOYSTICK3BUTTON12 = 155,
  JOYSTICK3BUTTON13 = 156,
  JOYSTICK3BUTTON14 = 157,
  JOYSTICK3BUTTON15 = 158,
  JOYSTICK3BUTTON16 = 159,
  JOYSTICK3BUTTON17 = 160,
  JOYSTICK3BUTTON18 = 161,
  JOYSTICK3BUTTON19 = 162,

};
}

namespace AXIS
{
enum E
{
  HORIZONTAL        = 1 << 0,
  VERTICAL          = 1 << 1
};
}

class Input
{
public:

  /**
   * Default constructor
   */
  Input() = default;

  /**
   * Default destructor
   */
  ~Input() = default;
};
}

