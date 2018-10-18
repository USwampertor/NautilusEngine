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

namespace nauEngineSDK {
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
   * Default destructor
   */
  virtual ~nauDataStream() = 0;
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


