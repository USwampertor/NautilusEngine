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

    m_keyMap.insert(std::make_pair(KEY::MOUSEX,   gainput::MouseAxisX));
    m_keyMap.insert(std::make_pair(KEY::MOUSEY,   gainput::MouseAxisY));

    m_keyMap.insert(std::make_pair(KEY::MOUSE0,   gainput::MouseButton0));
    m_keyMap.insert(std::make_pair(KEY::MOUSE1,   gainput::MouseButton1));
    m_keyMap.insert(std::make_pair(KEY::MOUSE2,   gainput::MouseButton2));
    m_keyMap.insert(std::make_pair(KEY::MOUSE3,   gainput::MouseButton3));
    m_keyMap.insert(std::make_pair(KEY::MOUSE4,   gainput::MouseButton4));
    m_keyMap.insert(std::make_pair(KEY::MOUSE5,   gainput::MouseButton5));
    m_keyMap.insert(std::make_pair(KEY::MOUSE6,   gainput::MouseButton6));
    m_keyMap.insert(std::make_pair(KEY::MOUSE7,   gainput::MouseButton7));
    m_keyMap.insert(std::make_pair(KEY::MOUSE8,   gainput::MouseButton8));
    m_keyMap.insert(std::make_pair(KEY::MOUSE9,   gainput::MouseButton9));
    m_keyMap.insert(std::make_pair(KEY::MOUSE10,  gainput::MouseButton10));
    m_keyMap.insert(std::make_pair(KEY::MOUSE11,  gainput::MouseButton11));
    m_keyMap.insert(std::make_pair(KEY::MOUSE12,  gainput::MouseButton12));
    m_keyMap.insert(std::make_pair(KEY::MOUSE13,  gainput::MouseButton13));
    m_keyMap.insert(std::make_pair(KEY::MOUSE14,  gainput::MouseButton14));
    m_keyMap.insert(std::make_pair(KEY::MOUSE15,  gainput::MouseButton15));
    m_keyMap.insert(std::make_pair(KEY::MOUSE16,  gainput::MouseButton16));

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

    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0LEFTSTICKX, gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0LEFTSTICKY, gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS0,      gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS1,      gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS2,      gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS3,      gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS4,      gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0AXIS5,      gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON0,    gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON1,    gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON2,    gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON3,    gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON4,    gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON5,    gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON6,    gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON7,    gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON8,    gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON9,    gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON10,   gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON11,   gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON12,   gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON13,   gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON14,   gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON15,   gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON16,   gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON17,   gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON18,   gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK0BUTTON19,   gainput::PadButton19));

    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1LEFTSTICKX, gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1LEFTSTICKY, gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS0,      gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS1,      gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS2,      gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS3,      gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS4,      gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1AXIS5,      gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON0,    gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON1,    gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON2,    gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON3,    gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON4,    gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON5,    gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON6,    gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON7,    gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON8,    gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON9,    gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON10,   gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON11,   gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON12,   gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON13,   gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON14,   gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON15,   gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON16,   gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON17,   gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON18,   gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK1BUTTON19,   gainput::PadButton19));

    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2LEFTSTICKX, gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2LEFTSTICKY, gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS0,      gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS1,      gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS2,      gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS3,      gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS4,      gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2AXIS5,      gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON0,    gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON1,    gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON2,    gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON3,    gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON4,    gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON5,    gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON6,    gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON7,    gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON8,    gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON9,    gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON10,   gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON11,   gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON12,   gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON13,   gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON14,   gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON15,   gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON16,   gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON17,   gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON18,   gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK2BUTTON19,   gainput::PadButton19));

    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3LEFTSTICKX, gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3LEFTSTICKY, gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS0,      gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS1,      gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS2,      gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS3,      gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS4,      gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3AXIS5,      gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON0,    gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON1,    gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON2,    gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON3,    gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON4,    gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON5,    gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON6,    gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON7,    gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON8,    gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON9,    gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON10,   gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON11,   gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON12,   gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON13,   gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON14,   gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON15,   gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON16,   gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON17,   gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON18,   gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK3BUTTON19,   gainput::PadButton19));

    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4LEFTSTICKX, gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4LEFTSTICKY, gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS0,      gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS1,      gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS2,      gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS3,      gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS4,      gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4AXIS5,      gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON0,    gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON1,    gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON2,    gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON3,    gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON4,    gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON5,    gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON6,    gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON7,    gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON8,    gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON9,    gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON10,   gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON11,   gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON12,   gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON13,   gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON14,   gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON15,   gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON16,   gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON17,   gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON18,   gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK4BUTTON19,   gainput::PadButton19));
    
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5LEFTSTICKX, gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5LEFTSTICKY, gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS0,      gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS1,      gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS2,      gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS3,      gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS4,      gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5AXIS5,      gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON0,    gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON1,    gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON2,    gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON3,    gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON4,    gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON5,    gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON6,    gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON7,    gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON8,    gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON9,    gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON10,   gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON11,   gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON12,   gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON13,   gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON14,   gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON15,   gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON16,   gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON17,   gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON18,   gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK5BUTTON19,   gainput::PadButton19));
    
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6LEFTSTICKX, gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6LEFTSTICKY, gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS0,      gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS1,      gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS2,      gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS3,      gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS4,      gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6AXIS5,      gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON0,    gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON1,    gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON2,    gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON3,    gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON4,    gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON5,    gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON6,    gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON7,    gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON8,    gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON9,    gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON10,   gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON11,   gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON12,   gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON13,   gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON14,   gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON15,   gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON16,   gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON17,   gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON18,   gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK6BUTTON19,   gainput::PadButton19));
    
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7LEFTSTICKX, gainput::PadButtonLeftStickX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7LEFTSTICKY, gainput::PadButtonLeftStickY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS0,      gainput::PadButtonAxis4));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS1,      gainput::PadButtonAxis5));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS2,      gainput::PadButtonAxis6));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS3,      gainput::PadButtonAxis7));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS4,      gainput::PadButtonAxis8));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7AXIS5,      gainput::PadButtonAxis9));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON0,    gainput::PadButtonStart));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON1,    gainput::PadButtonSelect));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON2,    gainput::PadButtonHome));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON3,    gainput::PadButtonA));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON4,    gainput::PadButtonB));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON5,    gainput::PadButtonX));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON6,    gainput::PadButtonY));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON7,    gainput::PadButtonLeft));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON8,    gainput::PadButtonRight));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON9,    gainput::PadButtonUp));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON10,   gainput::PadButtonDown));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON11,   gainput::PadButtonL1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON12,   gainput::PadButtonR1));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON13,   gainput::PadButtonL2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON14,   gainput::PadButtonR2));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON15,   gainput::PadButtonL3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON16,   gainput::PadButtonR3));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON17,   gainput::PadButton17));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON18,   gainput::PadButton18));
    m_keyMap.insert(std::make_pair(KEY::JOYSTICK7BUTTON19,   gainput::PadButton19));

    //Default Devices
    GAInputDevice* device = new GAInputDevice();
    device->init(DEVICE::KEYBOARD, 
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceKeyboard>()));
    addDevice(device);
    
    device = new GAInputDevice();
    device->init(DEVICE::MOUSE,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceMouse>()));
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

  }

  void
  GAInputManager::mapButton(uint32 ID, DEVICE::TYPE deviceType, KEY::CODE toMap) {

  }

  void
  GAInputManager::mapButton(InputDevice* device, KEY::CODE newKey) {
    //If it needs to map itself as float
    if (newKey) {

    }
    //It will map it as bool
    else {
      m_inputMap.MapBool(newKey, device->getID(), m_keyMap[newKey]);
    }
  }


  void*
  GAInputManager::getManager() {
  
  }

  bool
  GAInputManager::isMousePresent() {
  
  }

  bool
  GAInputManager::isKeyBoardPresent() {
  
  }

  bool
  GAInputManager::isJoyStickPresent(uint32 keycode) {
  
  }

  bool
  GAInputManager::getKeyDown(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getKeyUp(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getKey(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getButtonDown(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getButtonUp(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getButton(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getMouseButtonDown(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getMouseButtonUp(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getMouseButton(KEY::CODE keycode) {
  
  }

  Vector2
  GAInputManager::getMousePosition() {
  
  }

  float
  GAInputManager::getScrollDelta() {
  
  }

  Vector3
  GAInputManager::acceleration() {
  
  }

  bool
  GAInputManager::anyKey() {
  
  }

  float
  GAInputManager::getAxis(uint32 ID, AXIS::E axis, JOYSTICK::E joystick) {
    return m_devices[DEVICE::GAMEPAD][ID]->getAxis(joystick, axis);
  }


}
