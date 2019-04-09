/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauPassPerInfo.h
 * @author Marco "Swampy" Millan
 * @date 2019/04/08 2019
 * @brief Pass info based up on specific passes in the renderer
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "nauPrerequisitesCore.h"
#include "nauMatrix4.h"
#include "nauVector4.h"


namespace nauEngineSDK {
  struct PassPerInfo
  {
  
  };
  
  struct GBPassInfo : public PassPerInfo 
  {
    Matrix4 WorldMat;
    Matrix4 ViewMat;
    Matrix4 Projection;
    float fNear;
    float fFar;
  };

  struct AOPassInfo : public PassPerInfo
  {
    Matrix4 invViewProjection;
    float fNear;
    float fFar;
    float sampleRadius;
    float intensity;
    float scale;
    float bias;
    Vector4 clearColor;

  };

  struct RDPassInfo : public PassPerInfo
  {

  };

  struct BLPassInfo : public PassPerInfo
  {

  };

  struct LGPassInfo : public PassPerInfo
  {

  };

  struct LMPassInfo : public PassPerInfo
  {

  };

  struct FNPassInfo : public PassPerInfo
  {

  };

}
