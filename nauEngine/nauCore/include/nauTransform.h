/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauTransform.h
 * @author Marco "Swampy" Millan
 * @date 6/8/2020
 * @brief Transform component that nests a position, rotation, and scale
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#pragma once

#include "nauVector3.h"
#include "nauQuaternion.h"
#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {

/**
 * Transform
 * Description:
 * 	Saves the position, scale and rotation
 * Sample usage:
 * 	Transform.position gives you the position of the object
 */
struct NAU_CORE_EXPORT Transform
{


public:
  Vector3 position;

  Quaternion rotation;

  Vector3 scale;


  
};
}
