/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauInputManager.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/23 2019
 * @brief Input Manager
 *
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauGAPrerequisites.h"

#include "nauGAInputDevice.h"

#include <nauInputManager.h>

namespace nauEngineSDK {
  class GAInputManager : public InputManager
  {
  public:
    /**
     * Default constructor
     */
    GAInputManager() = default;

    /**
     * Default destructor
     */
    virtual
    ~GAInputManager() = default;

    /**
     * @brief initializes the input manager and all default inputs available
     * @param
     * @return
     *
     */
    virtual void
    init() override;

    /**
     * @brief returns the plugin-managed object in charge of the management of objects
     * @param
     * @return
     *
     */
    virtual void*
    getManager() override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual bool
    isMousePresent() override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual bool
    isKeyBoardPresent() override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual bool
    isJoyStickPresent(KEY::CODE keycode) override;

    /**
     * @brief returns if any key or button is being pressed
     * @param
     * @return
     *
     */
    virtual bool
    getKeyDown(KEY::CODE keycode) override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual bool
    getKeyUp(KEY::CODE keycode) override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual bool
    getKey(KEY::CODE keycode) override;

    /**
     * @brief returns if any key or button is being pressed
     * @param
     * @return
     *
     */
    virtual bool
    getButtonDown(KEY::CODE keycode) override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual bool
    getButtonUp(KEY::CODE keycode) override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual bool
    getButton(KEY::CODE keycode) override;

    /**
     * @brief returns if any key or button is being pressed
     * @param
     * @return
     *
     */
    virtual bool
    getMouseButtonDown(KEY::CODE keycode) override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual bool
    getMouseButtonUp(KEY::CODE keycode) override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual bool
    getMouseButton(KEY::CODE keycode) override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual Vector2
    getMousePosition() override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual float
    getScrollDelta() override;

    /**
     * @brief returns the acceleration given at the last frame
     * @param
     * @return
     *
     */
    virtual Vector3
    acceleration() override;

    /**
     * @brief Returns true if any key is being pressed
     * @param
     * @return true if theres any key being pressed
     *
     */
    virtual bool
    anyKey() override;

    /**
     * @brief
     * @param
     * @return
     *
     */
    virtual float
    getAxis(AXIS::E axis) override;

    virtual void
    setState(KEY::CODE key) override;

    virtual void
    registerKey(KEY::CODE key, DEVICE::TYPE type) override;

    gainput::InputManager m_manager;

    gainput::InputMap m_map;

  };
}


