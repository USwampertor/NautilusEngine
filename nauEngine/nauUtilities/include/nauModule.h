/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauModule.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/07 2018
 * @brief 
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

#pragma once

namespace nauEngineSDK {
  
   /**
    * nauModule
    * Description:
    * 	An Engine Module that can be started up and shut down manually
    *   Its a nice done singleton, (I CANT BELIEVE ITS NOT SINGLETON!)
    * Sample usage:
    * 	
    */
  template <class T>
  class nauModule
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
     * Returns a pointer to the instace
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

      static_cast<nauModule*>(_instance())->onStartUp();
    }

    template<class SubType, class... Args>
    static void
    startUp(Args&& ...args) {
      static_assert(std::is_base_of<T, SubType>::value,
        "Provided type isnt derived from the same type you are initializing");
    
      if (isStartedUp()) {
      //Throws exceptio
      //Already started the module dude
    }

      _instance() = new SubType(std::forward<Args>(args)...);
      isStartedUp() = true;

      static_cast<nauModule*>(_instance())->onStartUp();
    }

    static void
    shutDown() {
      if(isDestroyed()) {
        //Throws exception
        //Trying to shut down something that literaly was never orn
      }

      if (!isStartedUp()) {
        //Throws exception
        //Trying to shut down somethign never started
      }

      static_cast<nauModule*>(_instance())->onShutDown();
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
    nauModule() = default;

    /**
     * Virtual destructor
     */
    virtual
    ~nauModule() = default;

    nauModule(nauModule&&) = delete;

    nauModule(const Module&) = delete;

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
