/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauMesh.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief Mesh class member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauMesh.h"
#include "nauMaterial.h"

namespace nauEngineSDK {
  
  void
  Mesh::draw(Device* dev) {
    uint32 stride;
    uint32 offset;
    stride = sizeof(Vertex);
    offset = 0;
    auto pDC = dev;


    m_vertexBuffer->set(pDC->getContext());
    m_indexBuffer->set(pDC->getContext());

    pDC->draw(m_indexBuffer->size(), 4, 0, 0);
  }
}