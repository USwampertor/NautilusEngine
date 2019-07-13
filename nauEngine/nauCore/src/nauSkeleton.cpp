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
#if NAU_DEBUG_MODE
      Logger::instance().toIDE("Bone");
#endif
      if (node->mParent->mName.C_Str() == "RootNode" || 
          node->mParent->mParent == nullptr) {
        rootNode = node;
        break;
      }
    }


    if (rootNode != nullptr) {
      m_root = bones[rootNode->mName.C_Str()];
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
    
    for (int i = 0; i < node->mNumChildren; ++i) {
      if (bones[node->mChildren[i]->mName.C_Str()] != nullptr) {
        Bone* newBone = bones[node->mChildren[i]->mName.C_Str()];
        newBone->m_parent = actualBone;
        actualBone->m_children.push_back(newBone);
        processBone(bones, node->mChildren[i], newBone);
      }
      else {
        processBone(bones, node->mChildren[i], actualBone);
      }
    }
  }


  Bone*
  Skeleton::getRoot() {
    return m_root;
  }

  int
  Skeleton::getID() {
    return m_ID;
  }



}