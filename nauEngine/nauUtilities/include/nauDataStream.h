/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauDataStream.h
 * @author Marco "Swampy" Mill嫕
 * @date 2018/10/14 2018
 * @brief Data stream object for input and output of information
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include <iostream>



namespace nauEngineSDK {

  
  enum class STREAMMODE 
  {
    READ,
    WRITE
  };

/**
 * nauDataStream
 * Description:
 * 	Father class for the memory and File stream
 * Sample usage:
 * 	NuaDataStream.open Opens a file
 */
class nauDataStream
{
public:
  /**
   * Default constructor
   */
  nauDataStream() = default;

  /**
   * Constructor defining the reading or writing flag
   */

  /**
   * Default destructor
   */
  virtual ~nauDataStream() = 0;

  /**
   * @brief Checks if the data stream can be read
   * @param 
   * @return true if readable 
   *
   */
  bool
  readable() const {
    return m_mode == STREAMMODE::READ;
  }

  /**
   * @brief Checks if the data stream can be written
   * @param
   * @return true if writable
   *
   */
  bool
  writable() const {
    return m_mode == STREAMMODE::WRITE;
  }

  /**
   * @brief gets to the starting point of the file
   * @param 
   * @return 122 31
   *
   */
  virtual void 
  atStart() = 0;

  /**
   * @brief gets to the position in the data stated by the user
   * @param 
   * @return 
   *
   */
  virtual void
  atPosition(int position) = 0;

  virtual void
  load(const char* file) = 0;

 public:

  /**
   * defines if its in writing or reading mode
   */
  STREAMMODE m_mode;

};

/**
 * nauFileStream
 * Description:
 *  Data stream class for managing information from file
 * Sample usage:
 * 	nauFileStream.Open() opens a file
 */
class nauFileStream : public nauDataStream
{
 public:
  
   /**
    * Default constructor
    */
   nauFileStream() = default;

   /**
    * Default Destructor
    */
   ~nauFileStream() {}

};

 /**
  * nauMemStream
  * Description:
  * 	Manages information from the memory
  * Sample usage:
  * 	nauMemStream.Open() gets a file or information from the memory
  */
class nauMemStream : public nauDataStream
{
 public:
  /**
   * Default constructor
   */
  nauMemStream() = default;

  /**
   * Default destructor
   */
  ~nauMemStream() {}

};

} 


