/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauAnimation.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/08/14 2019
 * @brief Animation class implementation
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#include "nauAnimation.h"


#include "nauSkeleton.h"

namespace nauEngineSDK {
  void
  Animation::init(aiAnimation* animation, Map<String, Bone*> sceneBones) {

    //Start creating the animation
    m_name = animation->mName.C_Str();
    m_ticksPerSecond = animation->mTicksPerSecond;
    m_duration = animation->mDuration;
    m_loop = false;
    m_frame = 0;

    m_channels.reserve(animation->mNumChannels);

    for (uint32 j = 0; j < animation->mNumChannels; ++j) {

      aiNodeAnim* aiAnimBone = animation->mChannels[j];

      String toTokenize = aiAnimBone->mNodeName.C_Str();
      //We check that the animation was well generated
      if (toTokenize.find(ASSIMPANIMATION) != String::npos) {
        //It's possible that assimp did an oopsie at trying to recover animation
        //Or the artist did animations not attached in the model
        //Mixamo does this, and its garbage, but eh
        //In those cases, Assimp adds a suffix
        //So its going to change the name to be able to find the bone
        toTokenize = toTokenize.substr(0, toTokenize.find(ASSIMPANIMATION));
      }

      auto it = sceneBones.find(toTokenize);
      if (it != sceneBones.end()) {

        Bone* b = it->second;
        AnimationBone* newBone = new AnimationBone();

        newBone->ID = b->m_ID;
        newBone->m_name = toTokenize;

        newBone->m_positions.reserve(aiAnimBone->mNumPositionKeys);
        newBone->m_scale.reserve(aiAnimBone->mNumScalingKeys);
        newBone->m_rotations.reserve(aiAnimBone->mNumRotationKeys);

        aiVectorKey pKey;
        aiQuatKey   qKey;

        for (uint32 positions = 0; positions < aiAnimBone->mNumPositionKeys; ++positions) {
          pKey = aiAnimBone->mPositionKeys[positions];
          Vector3 v = { pKey.mValue.x, pKey.mValue.y, pKey.mValue.z };
          newBone->m_positions.push_back(std::make_pair(pKey.mTime, v));
        }

        for (uint32 rotations = 0; rotations < aiAnimBone->mNumRotationKeys; ++rotations) {
          qKey = aiAnimBone->mRotationKeys[rotations];
          Quaternion q = { qKey.mValue.x, qKey.mValue.y, qKey.mValue.z, qKey.mValue.w };
          newBone->m_rotations.push_back(std::make_pair(qKey.mTime, q));
        }

        for (uint32 scales = 0; scales < aiAnimBone->mNumScalingKeys; ++scales) {
          pKey = aiAnimBone->mScalingKeys[scales];
          Vector3 v = { pKey.mValue.x, pKey.mValue.y, pKey.mValue.z };
          newBone->m_scale.push_back(std::make_pair(pKey.mTime, v));
        }
        m_channels.push_back(newBone);
      }
    }



  }

  void
  Animation::update(float deltaTime) {
    m_frame += deltaTime;
  }

  bool
  Animation::load(String path) {

    return true;
  }

  Vector<Matrix4>
  Animation::getFrame() {
    Vector<Matrix4> finalMatrix;


    for (auto frame : m_channels) {
     
    }

    return finalMatrix;
  }

  bool
  Animation::createBindAnimation(Sptr<Skeleton> skeleton, String fileName) {
    String name = fileName;
    name.append("BindPose");
    auto boneMap = skeleton->getAllBones();

    m_name = name;
    m_ticksPerSecond = 1.0f;
    m_duration = 1.0f;
    m_loop = false;
    m_frame = 0;

    m_channels.reserve(boneMap->size());


    for (auto it = boneMap->begin(); it != boneMap->end(); ++it) {
      AnimationBone* newBone = new AnimationBone();
      newBone->ID = it->second->m_ID;
      newBone->m_name = it->second->m_name;

      Vector3 position = { it->second->m_worldPosition.m[0][3],
                           it->second->m_worldPosition.m[1][3],
                           it->second->m_worldPosition.m[2][3] };
      Quaternion rotation;
      rotation.setRotationMatrix(it->second->m_worldPosition.getRotationMatrix());
      Vector3 scale = { it->second->m_worldPosition.m[0][0],
                        it->second->m_worldPosition.m[1][1],
                        it->second->m_worldPosition.m[2][2] };

      newBone->m_positions.push_back(std::make_pair(0.0f, position));
      newBone->m_rotations.push_back(std::make_pair(0.0f, rotation));
      newBone->m_scale.push_back(std::make_pair(0.0f, scale));
      
      m_channels.push_back(newBone);
    }
    return true;
  }

}

