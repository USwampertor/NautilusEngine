/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauModule.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/07 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

namespace nauEngineSDK {
  
   /**
    * nauModule
    * Description:
    * 	An Engine Module that can be started up and shut down manually
    *   Its a nicely done singleton, (I CANT BELIEVE ITS NOT SINGLETON!)
    * Sample usage:
    * 	
    */
  template <class T>
  class Module
  {
  public:

    /**
     * Returns a reference to the instance
     */
    static T&
      instance() {
      if (!isStartedUp()) {
        //Sends an exception
        //Error trying to access a module without initialization
      }

      if (isDestroyed()) {
        //Sends an exception
        //Error trying to access a destroyed module
      }

      return *_instace();
    }

    /**
     * Returns a pointer to the instance
     */
    static T*
      instance() {
      if (!isStartedUp()) {
        //Sends an exception
        //Error trying to access a module without initialization
      }

      if (isDestroyed()) {
        //Sends an exception
        //Error trying to access a destroyed module
      }

      return _instace();
    }

    template<class... Args>
    static void
    startUp(Args&& ...args) {
      if (isStartedUp()) {
        //Throws an exception
        //Already started Up
      }

      _instance() = new T(std::forward<Args>(args)...);
      isStartedUp() = true;

      static_cast<Module*>(_instance())->onStartUp();
    }

    template<class SubType, class... Args>
    static void
    startUp(Args&& ...args) {
      static_assert(std::is_base_of<T, SubType>::value,
        "Provided type isnt derived from the same type you are initializing");
    
      if (isStartedUp()) {
      //Throws exception
      //Already started the module dude
    }

      _instance() = new SubType(std::forward<Args>(args)...);
      isStartedUp() = true;

      static_cast<Module*>(_instance())->onStartUp();
    }

    static void
    shutDown() {
      if(isDestroyed()) {
        //Throws exception
        //Trying to shut down something that literally was never born
      }

      if (!isStartedUp()) {
        //Throws exception
        //Trying to shut down something never started
      }

      static_cast<Module*>(_instance())->onShutDown();
      delete _instance();
      isDestroyed() = true;
    }

    static bool
    isStarted() {
      return isStartedUp() && !isDestroyed();
    }

   protected:

    /**
     * Default constructor
     */
    Module() = default;

    /**
     * Virtual destructor
     */
    virtual
    ~Module() = default;

    Module(Module&&) = delete;

    Module(const Module&) = delete;

    Module&
    operator = (Module&&) = delete;

    Module&
    operator = (const Module&) = delete;

    virtual void
    onStartUp() {}

    virtual void
    onShutDown {}

    static T*&
    _instance() {
      static T* inst = nullptr;
      return inst;
    }

    static bool&
    isDestroyed() {
      static bool inst = false;
      return inst;
    }

    static bool&
    isStartedUp() {
      static bool inst = false;
      return inst;
    }

  };
  
}

