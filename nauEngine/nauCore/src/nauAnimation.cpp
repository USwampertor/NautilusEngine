/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAnimation.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/08/14 2019
 * @brief Animation class implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauAnimation.h"

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
}

