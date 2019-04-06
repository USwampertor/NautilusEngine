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




namespace nauEngineSDK {

  
  enum class NAU_UTILITY_EXPORT STREAMACCESS
  {
    READ = 0,
    WRITE
  };

  enum class NAU_UTILITY_EXPORT STREAMTYPE
  {
    FILE = 0,
    MEMORY
  };

/**
 * nauDataStream
 * Description:
 * 	Father class for the memory and File stream
 * Sample usage:
 * 	NuaDataStream.open Opens a file
 */
class NAU_UTILITY_EXPORT DataStream
{
public:
  /**
   * Default constructor
   */
  DataStream() = default;

  /**
   * Constructor defining the reading or writing flag
   */

  /**
   * STREAMACCESS defined constructor
   */
  DataStream(STREAMACCESS sAccess) : m_mode(sAccess) {}

  /**
   * path defined constructor
   */
  DataStream(const String& path, STREAMACCESS sAccess = STREAMACCESS::READ)
    : m_path(path),
      m_mode(sAccess) {}

  /**
   * Default destructor
   */
  virtual ~DataStream() {};

  /**
   * @brief Checks if the data stream can be read
   * @param 
   * @return true if readable 
   *
   */
  bool
  readable() const {
    return m_mode == STREAMACCESS::READ;
  }

  /**
   * @brief Checks if the data stream can be written
   * @param
   * @return true if writable
   *
   */
  bool
  writable() const {
    return m_mode == STREAMACCESS::WRITE;
  }

  /**
   * @brief gets to the starting point of the file
   * @param 
   * @return 122 31
   *
   */
  void 
  atStart();

  /**
   * @brief gets to the position in the data stated by the user
   * @param 
   * @return 
   *
   */
  void
  atPosition(SIZE_T position);

  /**
   * @brief gets to the ending point of the file
   * @param
   * @return
   *
   */
  void
  atEnd();

  /**
   * @brief skips a certain amount of bytes defined by the user
   * @param amount of bytes to skip
   * @return 
   *
   */
  void
  skip(SIZE_T bytes);

  /**
   * @brief returns if the dataStream is a file or memory
   * @param 
   * @return returns either a FILE or MEMORY enum if file
   *
   */
  virtual STREAMTYPE
  isType() = 0;

  /**
   * @brief open a file
   * @param string of the path where you find the file
   * @return true if loaded
   *
   */
  virtual bool
  open(String path) = 0;

  /**
   * @brief creates a file
   * @param string of the path where you find the file
   * @return true if loaded
   *
   */
  virtual bool
  create(void* path) = 0;

  /**
   * @brief creates a file
   * @param string of the path where you find the file
   * @return true if loaded
   *
   */
  virtual bool
  copy(const void* buffer) = 0;

  /**
   * @brief closes a file
   * @param 
   * @return 
   *
   */
  void
  close();

  /**
   * @brief inserts the stream at the end of the stream
   * @param path
   * @return the size of the file that was copied
   *
   */
  SIZE_T
  write(const String& information);

  /**
   * @brief inserts the stream at the end of the stream
   * @param void* the destiny of the information either a buffer or a variable
   *        size_t the size of the bytes read
   * @return the size of the file that was copied
   *
   */
  SIZE_T
  read(void* destiny, SIZE_T size);

  /**
   * @brief returns a string with all the info from the stream
   * @param 
   * @return 
   *
   */
  void
  readAll(void* destiny);

  /**
   * @brief returns true if the stream is at the end of the file
   * @param 
   * @return true if the current position is equal to the size of the vector
   *
   */
  bool
  eof() const;

  /**
   * @brief returns the name of the dataStream
   * @param 
   * @return the String with the name
   *
   */
  const String& getPath() { return m_path; }

  /**
   * @brief returns the name of the dataStream
   * @param
   * @return the String with the name
   *
   */
  STREAMACCESS getStreamAccess() { return m_mode; }

  /**
   * Member declaration
   */
 public:

  /**
   * defines if its in writing or reading mode
   */
  STREAMACCESS m_mode;

  /**
   * the stream of information
   */
  Vector<char> m_data;

  /**
   * Stream object to help us move things
   */
  String m_path;

  /**
   * size of our data stream
   */
  SIZE_T m_size;

  /**
   * Current position of the pointer of the stream
   */
  SIZE_T m_currPos;

};

/**
 * nauFileStream
 * Description:
 *  Data stream class for managing information from file
 * Sample usage:
 * 	nauFileStream.Open() opens a file
 */
class NAU_UTILITY_EXPORT FileStream : public DataStream
{
 public:
  
  /**
   * Default constructor
   */
  FileStream() = default;

  /**
   * Default destructor
   */
  ~FileStream() = default;

  /**
   * Parameter based constructor constructor
   */
  FileStream(const String& path, STREAMACCESS sAccess = STREAMACCESS::READ) {
    m_path = path;
    m_mode = sAccess;
  }

  STREAMTYPE
  isType();

  bool
  open(String file);

  bool
  create(void* file);

  bool
  copy(const void* buffer);


  std::fstream m_file;

};

/**
 * nauMemStream
 * Description:
 * 	Manages information from the memory
 * Sample usage:
 * 	nauMemStream.Open() gets a file or information from the memory
 */
class NAU_UTILITY_EXPORT MemStream : public DataStream
{
 public:
  /**
   * Default constructor
   */
  MemStream() = default;

  /**
   * Default destructor
   */
  ~MemStream() {}

  /**
   * @brief returns if the dataStream is a file or memory
   * @param 
   * @return returns either a FILE or MEMORY enum if file
   *
   */
  STREAMTYPE
  isType();

  bool
  open(String path);

  bool
  create(void* path);

  bool
  copy(const void* buffer);

};

} 


