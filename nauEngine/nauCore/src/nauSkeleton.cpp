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

  void
  Skeleton::init(Vector<Bone*> bones) {

  }

  void
  Skeleton::init(Map<String, Bone *> bones) {


  }

  void
  Skeleton::init(Map<String, Bone *> bones, Vector<aiNode*> nodes) {
    m_root = new Bone();
    for (auto node : nodes) {
      std::cout << "Node " << node->mName.C_Str() << std::endl;
      if (node->mParent->mName.C_Str() == "RootNode" || 
          node->mParent->mParent == nullptr) {
        String rootName = node->mName.C_Str();
        m_root = bones[rootName];
        for (int i = 0; i < node->mNumChildren; ++i) {
          m_root->m_children.push_back(bones[node->mChildren[i]->mName.C_Str()]);
        }
      }
      node->mChildren;
      node->mName;
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