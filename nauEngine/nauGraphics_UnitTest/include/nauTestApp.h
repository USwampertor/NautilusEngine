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

#include <nauAnimationManager.h>
#include <nauBaseApp.h>
#include <nauDLLoader.h>
#include <nauGraphicsAPI.h>
#include <nauInputManager.h>
#include <nauLogger.h>
#include <nauRenderManager.h>
#include <nauResourceManager.h>
#include <nauSceneGraph.h>
#include <nauSceneManager.h>
#include <nauUI.h>
#include <nauTimer.h>

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

    virtual int32
    start() override;

    virtual void
    render() override; 

    virtual void
    renderUI() override;

    virtual bool
    initApp(void* hwnd) override;

    virtual bool
    initUI(void* hwnd) override;

    virtual void
    shutDown() override;

    virtual void
    close() override;

    virtual void
    update() override;

    //CoreFactory* m_factory = nullptr;

    //SceneGraph m_sceneGraph;

  };

}

