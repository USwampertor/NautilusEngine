/**
 * @brief 
 * @param 
 * @return 
 *
 */
#include "nauDataStream.h"

namespace nauEngineSDK {
  

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauDataStream.cpp Data stream member definition
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  void
  DataStream::close() {
    m_data.clear();
    m_size = 0;
    m_currPos = 0;
  }

  void
  DataStream::atStart() {
    m_currPos = 0;
  }

  void
  DataStream::atEnd() {
    m_currPos = m_data.size();
  }

  void
  DataStream::atPosition(SIZE_T position) {
    m_currPos = position;
  }

  void
  DataStream::skip(SIZE_T bytes) {
    m_currPos += bytes;
  }

  bool
  DataStream::eof() const {
    return m_currPos == m_data.size();
  }

  void
  DataStream::readAll(void* destiny) {
    memcpy(destiny, &m_data[0], m_data.size());
  }

  SIZE_T
  DataStream::read(void* destiny, SIZE_T size) {
    if (m_data.size() - m_currPos < size) {
      std::cout << "Vector subscription out of range " << std::endl
                << "Writing as much as possible \n" << std::endl;
      size = m_data.size() - m_currPos;
    }
    memcpy(destiny, &m_data[m_currPos], size);
    m_currPos += size;
    return size;
  }

  SIZE_T
  DataStream::write(const String& information) {
   
    std::copy(information.begin(), information.end(), m_data.begin() + m_currPos);
    //m_data.insert(m_data[m_currPos], information.size(), information);
    //m_currPos += information.size();
    return information.size();
  }

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauDataStream.cpp File stream member definition
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  STREAMTYPE
  FileStream::isType() {
    return STREAMTYPE::FILE;
  }

  bool
  FileStream::open(String path) {

    String temp = path;
    std::fstream streamFile(temp, std::ios::binary | std::ios::ate);
    if (!streamFile.is_open()) {
      std::cout << "Couldn't open file at location " << temp << std::endl;
      return false;
    }
    m_data.resize(static_cast<SIZE_T>(streamFile.tellg()));
    m_size = static_cast<SIZE_T>(streamFile.tellg());
    streamFile.seekg(0, streamFile.beg);
    streamFile.read(&m_data[0], std::ios::binary);
    streamFile.close();
    return true;
  }

  bool
  FileStream::create(void* file) {
    m_data.resize(reinterpret_cast<SIZE_T>(file));
    return true;
  }

  bool
  FileStream::copy(const void* buffer) {
    memcpy(&m_data[0], buffer, sizeof(buffer));
    return true;
  }

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauDataStream.cpp Memory stream member definition
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/


  STREAMTYPE
  MemStream::isType() {
    return STREAMTYPE::MEMORY;
  }

  bool
  MemStream::open(String file) {
    return copy(file.c_str());
  }

  bool
  MemStream::create(void* file) {
    (void)(file);
    return true;
  }

  bool
  MemStream::copy(const void* buffer) {
    memcpy(&m_data[0], buffer, sizeof(buffer));
    return true;
  }

}
