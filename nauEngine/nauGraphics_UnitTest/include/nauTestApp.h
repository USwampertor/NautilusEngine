/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauTestApp.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief Test Application running in DirectX
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once


#include <nauPrerequisitesCore.h>
#include <nauBaseApp.h>

namespace nauEngineSDK {
   /**
    * TestApp
    * Description:
    *   A basic Application for testing graphics stuff, like UI and plugins
    * Sample usage:
    *   Runs an IMGUI basic UI and can see models 
    */
  class TestApp : public BaseApp
  {
  public:
    /**
     * Default Constructor
     */
    TestApp() = default;

    /**
     * Default destructor
     */
    ~TestApp() = default;

    void
    start();

    void
    render();

    void
    initApp();

    void
    shutDown();

    void
    close();

  };

}

