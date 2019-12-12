/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSkeleton.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/07/06 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauSkeleton.h"

namespace nauEngineSDK {
  
  Skeleton::Skeleton(const Skeleton& other) {
    *this = other;
  }

  bool
  Skeleton::load(String path) {

    return true;
  }

  void
  Skeleton::init(Vector<Bone*> bones) {

  }

  void
  Skeleton::init(Map<String, Bone *> bones) {


  }

  void
  Skeleton::init(Map<String, Bone *> bones, Vector<aiNode*> nodes) {
    m_root = new Bone();
    aiNode* rootNode = nullptr;

    for (auto node : nodes) {
      if (node->mParent->mName.C_Str() == "RootNode" || 
          node->mParent->mParent == nullptr) {
        rootNode = node;
        break;
      }
    }

    if (rootNode != nullptr) {
      m_root = bones[rootNode->mName.C_Str()];
      aiMatrix4x4 m = rootNode->mTransformation;
      m_root->m_worldPosition.setValues(m.a1, m.b1, m.c1, m.d1,
                                        m.a2, m.b2, m.c2, m.d2,
                                        m.a3, m.b3, m.c3, m.d3,
                                        m.a4, m.b4, m.c4, m.d4);
      if (m_set.find(m_root->m_name) == m_set.end()) { m_set.insert(std::make_pair(m_root->m_name, m_root)); }
      processBone(bones, rootNode, m_root);
    }
    else {
#if NAU_DEBUG_MODE
      Logger::instance().toIDE("Couldn't find a Root Node in the node Vector",
                               LOGGER_LEVEL::ERRORED);
#endif
    }



  }

  void
  Skeleton::processBone(Map<String, Bone *> bones, aiNode* node, Bone* actualBone) {
    
    for (uint32 i = 0; i < node->mNumChildren; ++i) {
      if (bones[node->mChildren[i]->mName.C_Str()] != nullptr) {
        Bone* newBone = bones[node->mChildren[i]->mName.C_Str()];
        aiMatrix4x4 m = node->mTransformation;
        newBone->m_parent = actualBone;
        newBone->m_localPosition.setValues(m.a1, m.b1, m.c1, m.d1,
                                           m.a2, m.b2, m.c2, m.d2,
                                           m.a3, m.b3, m.c3, m.d3,
                                           m.a4, m.b4, m.c4, m.d4);
        newBone->m_worldPosition = newBone->m_parent->m_worldPosition * 
                                   newBone->m_localPosition;
        actualBone->m_children.push_back(newBone);
        if (m_set.find(newBone->m_name) == m_set.end()) { m_set.insert(std::make_pair(newBone->m_name, m_root)); }
        processBone(bones, node->mChildren[i], newBone);
      }
      else {
        processBone(bones, node->mChildren[i], actualBone);
      }
    }
  }

  void
  Skeleton::processMuscles(Vector<Bone*> muscles) {
    for (auto muscle :muscles) {

      m_muscles.push_back(muscle);
    }
  }

  Bone*
  Skeleton::getRoot() {
    return m_root;
  }

  Map<String, Bone*>*
  Skeleton::getAllBones() {
    return &m_set;
  }

  uint32
  Skeleton::getID() {
    return m_ID;
  }



}