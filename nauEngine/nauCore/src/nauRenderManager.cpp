/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRenderManager.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/06 2019
 * @brief RenderManager member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauRenderManager.h"

namespace nauEngineSDK {

  bool
  RenderManager::init(GraphicsAPI* api) {


    return true;
  }

  void
  RenderManager::render(Vector<MeshComponent*> m_orderedList, GraphicsAPI* api) {
    
    
    
  }

  void
  RenderManager::addPass(GraphicPass* pass) {

  }

  Vector<MeshComponent*>
  RenderManager::createScreenAlignedQuad() {

  }

}