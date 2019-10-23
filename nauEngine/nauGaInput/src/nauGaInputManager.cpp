/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGaInputManager.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/07/25 2019
 * @brief GAINPUT Input Manager implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauGaInputManager.h"

namespace nauEngineSDK {
  void
  GAInputManager::init() {
    //Key Map with the GAInput map

    m_keyMap.insert(std::make_pair(KEY::MOUSEX, gainput::MouseAxisX));
    m_keyMap.insert(std::make_pair(KEY::MOUSEY, gainput::MouseAxisY));

    m_keyMap.insert(std::make_pair(KEY::MOUSE0, gainput::MouseButton0));
    m_keyMap.insert(std::make_pair(KEY::MOUSE1, gainput::MouseButton1));
    m_keyMap.insert(std::make_pair(KEY::MOUSE2, gainput::MouseButton2));
    m_keyMap.insert(std::make_pair(KEY::MOUSE3, gainput::MouseButton3));
    m_keyMap.insert(std::make_pair(KEY::MOUSE4, gainput::MouseButton4));
    m_keyMap.insert(std::make_pair(KEY::MOUSE5, gainput::MouseButton5));
    m_keyMap.insert(std::make_pair(KEY::MOUSE6, gainput::MouseButton6));
    m_keyMap.insert(std::make_pair(KEY::MOUSE7, gainput::MouseButton7));
    m_keyMap.insert(std::make_pair(KEY::MOUSE8, gainput::MouseButton8));
    m_keyMap.insert(std::make_pair(KEY::MOUSE9, gainput::MouseButton9));
    m_keyMap.insert(std::make_pair(KEY::MOUSE10, gainput::MouseButton10));
    m_keyMap.insert(std::make_pair(KEY::MOUSE11, gainput::MouseButton11));
    m_keyMap.insert(std::make_pair(KEY::MOUSE12, gainput::MouseButton12));
    m_keyMap.insert(std::make_pair(KEY::MOUSE13, gainput::MouseButton13));
    m_keyMap.insert(std::make_pair(KEY::MOUSE14, gainput::MouseButton14));
    m_keyMap.insert(std::make_pair(KEY::MOUSE15, gainput::MouseButton15));
    m_keyMap.insert(std::make_pair(KEY::MOUSE16, gainput::MouseButton16));

    m_keyMap.insert(std::make_pair(KEY::ALPHA0, gainput::Key0));
    m_keyMap.insert(std::make_pair(KEY::ALPHA1, gainput::Key1));
    m_keyMap.insert(std::make_pair(KEY::ALPHA2, gainput::Key2));
    m_keyMap.insert(std::make_pair(KEY::ALPHA3, gainput::Key3));
    m_keyMap.insert(std::make_pair(KEY::ALPHA4, gainput::Key4));
    m_keyMap.insert(std::make_pair(KEY::ALPHA5, gainput::Key5));
    m_keyMap.insert(std::make_pair(KEY::ALPHA6, gainput::Key6));
    m_keyMap.insert(std::make_pair(KEY::ALPHA7, gainput::Key7));
    m_keyMap.insert(std::make_pair(KEY::ALPHA8, gainput::Key8));
    m_keyMap.insert(std::make_pair(KEY::ALPHA9, gainput::Key9));

    m_keyMap.insert(std::make_pair(KEY::F1, gainput::KeyF1));
    m_keyMap.insert(std::make_pair(KEY::F2, gainput::KeyF2));
    m_keyMap.insert(std::make_pair(KEY::F3, gainput::KeyF3));
    m_keyMap.insert(std::make_pair(KEY::F4, gainput::KeyF4));
    m_keyMap.insert(std::make_pair(KEY::F5, gainput::KeyF5));
    m_keyMap.insert(std::make_pair(KEY::F6, gainput::KeyF6));
    m_keyMap.insert(std::make_pair(KEY::F7, gainput::KeyF7));
    m_keyMap.insert(std::make_pair(KEY::F8, gainput::KeyF8));
    m_keyMap.insert(std::make_pair(KEY::F9, gainput::KeyF9));
    m_keyMap.insert(std::make_pair(KEY::F10, gainput::KeyF10));
    m_keyMap.insert(std::make_pair(KEY::F11, gainput::KeyF11));
    m_keyMap.insert(std::make_pair(KEY::F12, gainput::KeyF12));
    m_keyMap.insert(std::make_pair(KEY::F13, gainput::KeyF13));
    m_keyMap.insert(std::make_pair(KEY::F14, gainput::KeyF14));
    m_keyMap.insert(std::make_pair(KEY::F15, gainput::KeyF15));
    m_keyMap.insert(std::make_pair(KEY::F16, gainput::KeyF16));

    m_keyMap.insert(std::make_pair(KEY::ESCAPE, gainput::KeyEscape));
    m_keyMap.insert(std::make_pair(KEY::SPACE, gainput::KeySpace));
    m_keyMap.insert(std::make_pair(KEY::BACKSPACE, gainput::KeyBackSpace));

    m_keyMap.insert(std::make_pair(KEY::KEYPAD1, gainput::KeyKpEnd));
    m_keyMap.insert(std::make_pair(KEY::KEYPAD2, gainput::KeyKpDown));
    m_keyMap.insert(std::make_pair(KEY::KEYPAD3, gainput::KeyKpPageDown));
    m_keyMap.insert(std::make_pair(KEY::KEYPAD4, gainput::KeyKpLeft));
    m_keyMap.insert(std::make_pair(KEY::KEYPAD5, gainput::KeyKpEqual));
    m_keyMap.insert(std::make_pair(KEY::KEYPAD6, gainput::KeyKpRight));
    m_keyMap.insert(std::make_pair(KEY::KEYPAD7, gainput::KeyKpHome));
    m_keyMap.insert(std::make_pair(KEY::KEYPAD8, gainput::KeyKpUp));
    m_keyMap.insert(std::make_pair(KEY::KEYPAD9, gainput::KeyKpPageUp));

    m_keyMap.insert(std::make_pair(KEY::HOME, gainput::KeyHome));

    m_keyMap.insert(std::make_pair(KEY::A, gainput::KeyA));
    m_keyMap.insert(std::make_pair(KEY::B, gainput::KeyB));
    m_keyMap.insert(std::make_pair(KEY::C, gainput::KeyC));
    m_keyMap.insert(std::make_pair(KEY::D, gainput::KeyD));
    m_keyMap.insert(std::make_pair(KEY::E, gainput::KeyE));
    m_keyMap.insert(std::make_pair(KEY::F, gainput::KeyF));
    m_keyMap.insert(std::make_pair(KEY::G, gainput::KeyG));
    m_keyMap.insert(std::make_pair(KEY::H, gainput::KeyH));
    m_keyMap.insert(std::make_pair(KEY::I, gainput::KeyI));
    m_keyMap.insert(std::make_pair(KEY::J, gainput::KeyJ));
    m_keyMap.insert(std::make_pair(KEY::K, gainput::KeyK));
    m_keyMap.insert(std::make_pair(KEY::L, gainput::KeyL));
    m_keyMap.insert(std::make_pair(KEY::M, gainput::KeyM));
    m_keyMap.insert(std::make_pair(KEY::N, gainput::KeyN));
    m_keyMap.insert(std::make_pair(KEY::O, gainput::KeyO));
    m_keyMap.insert(std::make_pair(KEY::P, gainput::KeyP));
    m_keyMap.insert(std::make_pair(KEY::Q, gainput::KeyQ));
    m_keyMap.insert(std::make_pair(KEY::R, gainput::KeyR));
    m_keyMap.insert(std::make_pair(KEY::S, gainput::KeyS));
    m_keyMap.insert(std::make_pair(KEY::T, gainput::KeyT));
    m_keyMap.insert(std::make_pair(KEY::U, gainput::KeyU));
    m_keyMap.insert(std::make_pair(KEY::V, gainput::KeyV));
    m_keyMap.insert(std::make_pair(KEY::W, gainput::KeyW));
    m_keyMap.insert(std::make_pair(KEY::X, gainput::KeyX));
    m_keyMap.insert(std::make_pair(KEY::Y, gainput::KeyY));
    m_keyMap.insert(std::make_pair(KEY::Z, gainput::KeyZ));

    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0LEFTSTICKX,  gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0LEFTSTICKY,  gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0RIGHTSTICKX, gainput::PadButtonRightStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0RIGHTSTICKY, gainput::PadButtonRightStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS0,       gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS1,       gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS2,       gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS3,       gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS4,       gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS5,       gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON0,     gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON1,     gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON2,     gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON3,     gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON4,     gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON5,     gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON6,     gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON7,     gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON8,     gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON9,     gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON10,    gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON11,    gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON12,    gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON13,    gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON14,    gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON15,    gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON16,    gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON17,    gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON18,    gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON19,    gainput::PadButton19));

    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1LEFTSTICKX,  gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1LEFTSTICKY,  gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1RIGHTSTICKX, gainput::PadButtonRightStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1RIGHTSTICKY, gainput::PadButtonRightStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS0,       gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS1,       gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS2,       gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS3,       gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS4,       gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS5,       gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON0,     gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON1,     gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON2,     gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON3,     gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON4,     gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON5,     gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON6,     gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON7,     gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON8,     gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON9,     gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON10,    gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON11,    gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON12,    gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON13,    gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON14,    gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON15,    gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON16,    gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON17,    gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON18,    gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON19,    gainput::PadButton19));

    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2LEFTSTICKX,  gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2LEFTSTICKY,  gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2RIGHTSTICKX, gainput::PadButtonRightStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2RIGHTSTICKY, gainput::PadButtonRightStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS0,       gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS1,       gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS2,       gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS3,       gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS4,       gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS5,       gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON0,     gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON1,     gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON2,     gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON3,     gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON4,     gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON5,     gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON6,     gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON7,     gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON8,     gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON9,     gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON10,    gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON11,    gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON12,    gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON13,    gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON14,    gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON15,    gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON16,    gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON17,    gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON18,    gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON19,    gainput::PadButton19));

    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3LEFTSTICKX,  gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3LEFTSTICKY,  gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3RIGHTSTICKX, gainput::PadButtonRightStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3RIGHTSTICKY, gainput::PadButtonRightStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS0,       gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS1,       gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS2,       gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS3,       gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS4,       gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS5,       gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON0,     gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON1,     gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON2,     gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON3,     gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON4,     gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON5,     gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON6,     gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON7,     gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON8,     gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON9,     gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON10,    gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON11,    gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON12,    gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON13,    gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON14,    gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON15,    gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON16,    gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON17,    gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON18,    gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON19,    gainput::PadButton19));

    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4LEFTSTICKX,  gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4LEFTSTICKY,  gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4RIGHTSTICKX, gainput::PadButtonRightStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4RIGHTSTICKY, gainput::PadButtonRightStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS0,       gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS1,       gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS2,       gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS3,       gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS4,       gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS5,       gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON0,     gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON1,     gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON2,     gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON3,     gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON4,     gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON5,     gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON6,     gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON7,     gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON8,     gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON9,     gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON10,    gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON11,    gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON12,    gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON13,    gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON14,    gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON15,    gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON16,    gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON17,    gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON18,    gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON19,    gainput::PadButton19));
    
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5LEFTSTICKX,  gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5LEFTSTICKY,  gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5RIGHTSTICKX, gainput::PadButtonRightStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5RIGHTSTICKY, gainput::PadButtonRightStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS0,       gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS1,       gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS2,       gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS3,       gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS4,       gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS5,       gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON0,     gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON1,     gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON2,     gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON3,     gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON4,     gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON5,     gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON6,     gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON7,     gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON8,     gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON9,     gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON10,    gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON11,    gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON12,    gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON13,    gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON14,    gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON15,    gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON16,    gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON17,    gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON18,    gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON19,    gainput::PadButton19));
    
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6LEFTSTICKX,  gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6LEFTSTICKY,  gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6RIGHTSTICKX, gainput::PadButtonRightStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6RIGHTSTICKY, gainput::PadButtonRightStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS0,       gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS1,       gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS2,       gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS3,       gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS4,       gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS5,       gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON0,     gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON1,     gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON2,     gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON3,     gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON4,     gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON5,     gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON6,     gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON7,     gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON8,     gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON9,     gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON10,    gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON11,    gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON12,    gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON13,    gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON14,    gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON15,    gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON16,    gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON17,    gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON18,    gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON19,    gainput::PadButton19));
    
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7LEFTSTICKX,  gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7LEFTSTICKY,  gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7RIGHTSTICKX, gainput::PadButtonRightStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7RIGHTSTICKY, gainput::PadButtonRightStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS0,       gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS1,       gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS2,       gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS3,       gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS4,       gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS5,       gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON0,     gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON1,     gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON2,     gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON3,     gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON4,     gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON5,     gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON6,     gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON7,     gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON8,     gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON9,     gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON10,    gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON11,    gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON12,    gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON13,    gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON14,    gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON15,    gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON16,    gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON17,    gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON18,    gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON19,    gainput::PadButton19));

    //Default Devices
    GAInputDevice* device = new GAInputDevice();
    device->init(DEVICE::KEYBOARD, 
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceKeyboard>()));
    mapButton(device, KEY::A);
    mapButton(device, KEY::B);
    mapButton(device, KEY::C);
    mapButton(device, KEY::D);
    mapButton(device, KEY::E);
    mapButton(device, KEY::F);
    mapButton(device, KEY::G);
    mapButton(device, KEY::H);
    mapButton(device, KEY::I);
    mapButton(device, KEY::J);
    mapButton(device, KEY::K);
    mapButton(device, KEY::L);
    mapButton(device, KEY::M);
    mapButton(device, KEY::N);
    mapButton(device, KEY::O);
    mapButton(device, KEY::P);
    mapButton(device, KEY::Q);
    mapButton(device, KEY::R);
    mapButton(device, KEY::S);
    mapButton(device, KEY::T);
    mapButton(device, KEY::U);
    mapButton(device, KEY::V);
    mapButton(device, KEY::W);
    mapButton(device, KEY::X);
    mapButton(device, KEY::Y);
    mapButton(device, KEY::Z);
    addDevice(device);
    
    device = new GAInputDevice();
    device->init(DEVICE::MOUSE,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceMouse>()));
    mapButton(device, KEY::MOUSE0);
    mapButton(device, KEY::MOUSE1);
    mapButton(device, KEY::MOUSE2);
    addDevice(device);


    device = new GAInputDevice();
    device->init(DEVICE::GAMEPAD,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceBuiltIn>()));
    addDevice(device);

    device = new GAInputDevice();
    device->init(DEVICE::GAMEPAD,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceBuiltIn>()));
    addDevice(device);

    device = new GAInputDevice();
    device->init(DEVICE::GAMEPAD,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceBuiltIn>()));
    addDevice(device);

    device = new GAInputDevice();
    device->init(DEVICE::GAMEPAD,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceBuiltIn>()));
    addDevice(device);

    device = new GAInputDevice();
    device->init(DEVICE::GAMEPAD,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceBuiltIn>()));
    addDevice(device);

    device = new GAInputDevice();
    device->init(DEVICE::GAMEPAD,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceBuiltIn>()));
    addDevice(device);

    device = new GAInputDevice();
    device->init(DEVICE::GAMEPAD,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceBuiltIn>()));
    addDevice(device);

    device = new GAInputDevice();
    device->init(DEVICE::GAMEPAD,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceBuiltIn>()));
    addDevice(device);

  }

  void
  GAInputManager::update() {

  }

  void
  GAInputManager::removeDevice(InputDevice* device) {
    for (uint32 i = 0; i < DEVICE::GAMEPAD + 1; ++i) {
      for (auto registeredDevice : m_devices[i]) {
        if (device == registeredDevice) {
          registeredDevice->setActive(false);
        }
      }
    }
  }

  void
  GAInputManager::mapButton(uint32 ID, 
                            DEVICE::TYPE deviceType, 
                            KEY::CODE toMap,
                            bool isFloat) {
    if (isFloat) {
      m_inputMap.MapFloat(toMap, m_devices[deviceType][ID]->getID(), m_keyMap[toMap]);
    }
    else {
      m_inputMap.MapBool(toMap, m_devices[deviceType][ID]->getID(), m_keyMap[toMap]);
    }
  }

  void
  GAInputManager::mapButton(InputDevice* device, 
                            KEY::CODE newKey, 
                            bool isFloat) {
    //If it needs to map itself as float
    if (isFloat) {
      m_inputMap.MapFloat(newKey, device->getID(), m_keyMap[newKey]);
    }
    //It will map it as bool
    else {
      m_inputMap.MapBool(newKey, device->getID(), m_keyMap[newKey]);
    }
  }


  void*
  GAInputManager::getManager() {
    return reinterpret_cast<void*>(&m_manager);
  }

  bool
  GAInputManager::isMousePresent() {
    return m_devices[DEVICE::MOUSE][0]->isActive();
  }

  bool
  GAInputManager::isKeyBoardPresent() {
  
    return m_devices[DEVICE::KEYBOARD][0]->isActive();
  }

  bool
  GAInputManager::isJoyStickPresent(uint32 keycode) {
    return m_devices[DEVICE::GAMEPAD][keycode]->isActive();
  }

  bool
  GAInputManager::getKeyDown(KEY::CODE keycode) {
    return m_inputMap.GetBoolPrevious(keycode);
  }

  bool
  GAInputManager::getKeyUp(KEY::CODE keycode) {
    return m_inputMap.GetBoolWasDown(keycode);
  }

  bool
  GAInputManager::getKey(KEY::CODE keycode) {
    return m_inputMap.GetBool(keycode);
  }

  bool
  GAInputManager::getButtonDown(KEY::CODE keycode) {
    return m_inputMap.GetBoolPrevious(keycode);
  }

  bool
  GAInputManager::getButtonUp(KEY::CODE keycode) {
    return m_inputMap.GetBoolWasDown(keycode);
  }

  bool
  GAInputManager::getButton(KEY::CODE keycode) {
    return m_inputMap.GetBool(keycode);
  }

  bool
  GAInputManager::getMouseButtonDown(KEY::CODE keycode) {
    return m_inputMap.GetBoolPrevious(keycode);
  }

  bool
  GAInputManager::getMouseButtonUp(KEY::CODE keycode) {
    return m_inputMap.GetBoolWasDown(keycode);
  }

  bool
  GAInputManager::getMouseButton(KEY::CODE keycode) {
    return m_inputMap.GetBool(keycode);
  }

  Vector2
  GAInputManager::getMousePosition() {
    return Vector2(m_inputMap.GetFloat(KEY::MOUSEX), 
                   m_inputMap.GetFloat(KEY::MOUSEY));
  }

  float
  GAInputManager::getScrollDelta() {
    return m_inputMap.GetFloatDelta(KEY::MOUSESCROLL);
  }

  Vector3
  GAInputManager::acceleration() {
    return Vector3(Vector3::ZERO);
  }

  bool
  GAInputManager::anyKey() {
    for (uint32 i = 0; i < KEY::LASTINPUT; ++i) {
      if (m_inputMap.GetBool(i)) return true;
    }
    return false;
  }

  float
  GAInputManager::getAxis(uint32 ID, AXIS::E axis, JOYSTICK::E joystick) {
    return m_devices[DEVICE::GAMEPAD][ID]->getAxis(joystick, axis);
  }

  
}
