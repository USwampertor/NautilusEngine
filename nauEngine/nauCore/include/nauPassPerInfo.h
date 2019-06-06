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

    RenderTargetView* m_color;
    RenderTargetView* m_emissive;
    RenderTargetView* m_normal;
    RenderTargetView* m_depth;
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

    RenderTargetView* m_normal;
    RenderTargetView* m_depth;
  };

  struct RDPassInfo : public PassPerInfo
  {

  };

  struct BLPassInfo : public PassPerInfo
  {
    Vector2 viewPortDimensions;
    RenderTargetView* m_ambient;
    RenderTargetView* m_reduction;
  };

  struct LGPassInfo : public PassPerInfo
  {
    float fSpecPower;
    float fNear;
    float fFar;
    float skyBoxRotation;

    Vector3 fLightPos;
    Vector4 vViewPosition;
    Matrix4 invViewProjection;

    RenderTargetView* m_albedo;
    RenderTargetView* m_normal;
    RenderTargetView* m_irradiance;
    RenderTargetView* m_ambient;
    RenderTargetView* m_specular;
    RenderTargetView* m_depth;
    RenderTargetView* m_emissive;

  };

  struct LMPassInfo : public PassPerInfo
  {
    RenderTargetView* m_color;
    RenderTargetView* m_emissive;

    float m_threshold;
  };

  struct FNPassInfo : public PassPerInfo
  {
    float m_bloomMultiplier;
    float m_midPointGrey;

    RenderTargetView* m_color;
    RenderTargetView* m_emissive;
    RenderTargetView* m_luminance;
    
  };

}
