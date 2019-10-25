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
  INVALID         = -1,
  NONE            = 0,
  IMAGE           ,
  MODEL           ,
  MATERIAL        ,
  SKELETON        ,
  SCENE           ,
  AUDIO           ,
  IRINANN         ,

};
}


namespace CODECFORMAT
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
  virtual
  ~Codec() = default;

  /**
   * @brief Checks if the actual object is a valid format
   * @param String path of the object
   * @return true if able to decode
   *
   */
  virtual bool
  canDecode(String path) = 0;

  /**
   * @brief Checks if the actual object is a valid format
   * @param Path object
   * @return true if able to decode
   *
   */
  virtual bool
  canDecode(Path path) = 0;

  /**
   * @brief Creates and retrieves the information stored inside the object
   * @param 
   * @return 
   *
   */
  virtual bool
  decode(String path) = 0;

  /**
   * @brief Returns the type of codec it is
   * @param 
   * @return 
   *
   */
  virtual CODECFORMAT::E
  getFormat() = 0;

};

class CodecImage : public Codec
{
public:
  /**
   * Default constructor
   */
  CodecImage()  = default;

  /**
   * Default destructor
   */
  ~CodecImage() = default;

  /**
   * @brief Checks if the actual object is a valid format
   * @param String path of the object
   * @return true if able to decode
   *
   */
  virtual bool
  canDecode(String path) override;

  /**
   * @brief Checks if the actual object is a valid format
   * @param Path object
   * @return true if able to decode
   *
   */
  virtual bool
  canDecode(Path path) override;

  /**
   * @brief Creates and retrieves the information stored inside the object
   * @param 
   * @return 
   *
   */
  virtual bool
  decode(String path) override;

  /**
   * @brief Returns the type of codec it is
   * @param 
   * @return 
   *
   */
  virtual CODECTYPE::E
  getType() = 0;

};

}





