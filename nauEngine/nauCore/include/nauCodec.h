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
  SCN,          //Scene Format
  SKL,          //Skeleton Format
  MTR,          //Material Format
  ANTN,         //Animation format
  ANTR,         //Animator format

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauCodec.h MISC FILE FORMATS
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  TXT,          //Text Format

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauCodec.h SHADER FILE FORMATS
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

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





