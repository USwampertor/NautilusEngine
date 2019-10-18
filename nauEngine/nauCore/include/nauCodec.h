/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauCodec.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/12 2019
 * @brief CODEC Object for encoding and decoding files
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once
#include "nauPrerequisitesCore.h"

#include <nauPath.h>

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauCodec.h AVAILABLE FORMATS IN THE CODEC
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

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
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauCodec.h DEFAULT FORMATS
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  NONE,
  INVALID,
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauCodec.h IMAGE FORMATS
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  JPG,
  JPEG,
  GIF,
  PNG,
  TARGA,
  DDX,
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauCodec.h ENGINE SPECIFIC FORMATS
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  SCN,          //Scene Format
  SKL,          //Skeleton Format
  MTR,          //Material Format
  ANTN,         //Animation format
  ANTR,         //Animator format

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauCodec.h MISC FILE FORMATS
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  TXT,          //Text Format

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauCodec.h SHADER FILE FORMATS
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

};
}

class Codec
{
public:
  /**
   * Default constructor
   */
  Codec()  = default;

  /**
   * Default destructor
   */
  ~Codec() = default;

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





