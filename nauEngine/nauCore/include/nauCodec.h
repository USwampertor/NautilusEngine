/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCodec.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/12 2019
 * @brief CODEC Object for encoding and decoding files
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once
#include "nauPrerequisitesCore.h"

#include <nauPath.h>

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauCodec.h AVAILABLE FORMATS IN THE CODEC
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

namespace nauEngineSDK {

namespace CODECTYPE
{
enum E
{
  NONE            = 0,
  INVALID         = -1,
  IMAGE           = 1<<0,
  MODEL           = 1<<1,
  MATERIAL        = 1<<2,
  SKELETON        = 1<<3,
  SCENE           = 1<<4,
  AUDIO           = 1<<5,
};
}


namespace FORMAT
{
enum E
{
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauCodec.h DEFAULT FORMATS
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  NONE,
  INVALID,
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauCodec.h IMAGE FORMATS
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  JPG,
  JPEG,
  GIF,
  PNG,
  TARGA,
  DDX,
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauCodec.h ENGINE SPECIFIC FORMATS
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  TXT,          //Text Format
  SCN,          //Scene Format
  SKL,          //Skeleton Format
  MTR,          //Material Format
  ANTN,         //Animation format
  ANTR,         //Animator format
};
}

class nauCodec
{
public:
  /**
   * Default constructor
   */
  nauCodec()  = default;

  /**
   * Default destructor
   */
  ~nauCodec() = default;

  /**
   * @brief Checks if the actual object is a valid format
   * @param String path of the object
   * @return true if able to decode
   *
   */
  bool
  canDecode(String path);

  /**
   * @brief Checks if the actual object is a valid format
   * @param Path object
   * @return true if able to decode
   *
   */
  bool
  canDecode(Path path);

  /**
   * @brief Creates and retrieves the information stored inside the object
   * @param 
   * @return 
   *
   */
  bool
  decode(String path);

};
}





