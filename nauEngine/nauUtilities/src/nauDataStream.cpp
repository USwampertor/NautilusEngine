/**
 * @brief 
 * @param 
 * @return 
 *
 */
#include "nauDataStream.h"

namespace nauEngineSDK {
  

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauDataStream.cpp Data stream member definition
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  void
  nauDataStream::close() {
    m_data.clear();
    m_size = 0;
    m_currPos = 0;
  }

  void
  nauDataStream::atStart() {
    m_currPos = 0;
  }

  void
  nauDataStream::atEnd() {
    m_currPos = m_data.size();
  }

  void
  nauDataStream::atPosition(SIZE_T position) {
    m_currPos = position;
  }

  void
  nauDataStream::skip(SIZE_T bytes) {
    m_currPos += bytes;
  }

  bool
  nauDataStream::eof() const {
    return m_currPos == m_data.size();
  }

  void
  nauDataStream::readAll(void* destiny) {
    memcpy(destiny, &m_data[0], m_data.size());
  }

  SIZE_T
  nauDataStream::read(void* destiny, SIZE_T size) {
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
  nauDataStream::write(const String& information) {
   
    std::copy(information.begin(), information.end(), m_data.begin() + m_currPos);
    //m_data.insert(m_data[m_currPos], information.size(), information);
    //m_currPos += information.size();
    return information.size();
  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauDataStream.cpp File stream member definition
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  STREAMTYPE
  nauFileStream::isType() {
    return STREAMTYPE::FILE;
  }

  bool
  nauFileStream::open(void* path) {

    String temp = static_cast<const char*>(path);
    std::fstream streamFile(temp, std::ios::binary | std::ios::ate);
    if (!streamFile.is_open()) {
      std::cout << "Couldn't open file at location " << temp << std::endl;
      return false;
    }
    m_data.resize(streamFile.tellg());
    m_size = static_cast<SIZE_T>(streamFile.tellg());
    streamFile.seekg(0, streamFile.beg);
    streamFile.read(&m_data[0], std::ios::binary);
    streamFile.close();
    return true;
  }

  bool
  nauFileStream::create(void* file) {
    return true;
  }

  bool
  nauFileStream::copy(const void* buffer) {
    memcpy(&m_data[0], buffer, sizeof(buffer));
    return true;
  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauDataStream.cpp Memory stream member definition
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/


  STREAMTYPE
  nauMemStream::isType() {
    return STREAMTYPE::MEMORY;
  }

  bool
  nauMemStream::open(void* file) {
    return copy(file);
  }

  bool
  nauMemStream::create(void* file) {
    (void)(file);
    return true;
  }

  bool
  nauMemStream::copy(const void* buffer) {
    std::memcpy(&m_data[0], buffer, sizeof(buffer));
    return true;
  }

}
