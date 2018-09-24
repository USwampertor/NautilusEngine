/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file main.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief Utilities Unit Testing main
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

/*
Use standard order for readability and to avoid hidden dependencies. In header files use the following order:
C library
C++ library
Other libraries'.h or .hpp
Your project's .h or .hpp
While cpp files should use:
The associate header file for the cpp file (Foo.h if we are in Foo.cpp)
C library
C++ library
Other libraries'.h or .hpp
Your project's .h or .hpp
*/

#include <conio.h>

#include <numeric>
#include <gtest/gtest.h>

#include <nauMath.h>
#include <nauPlatformUtilities.h>
#include <nauPrerequisitesUtil.h>


#define MARCOTESTING
#ifndef MARCOTESTING
#define SUMANOTESTING
#endif
using namespace nauEngineSDK;

int main(int argc, char **argv)
{
		::testing::InitGoogleTest(&argc,argv);
		std::cout<< RUN_ALL_TESTS();
    _getch();
    return 0;
}
#ifdef MARCOTESTING
TEST(Utilities, Basic_Types)
{
  EXPECT_TRUE(sizeof(int8)   == 1);
  EXPECT_TRUE(sizeof(int16)  == 2);
  EXPECT_TRUE(sizeof(int32)  == 4);
  EXPECT_TRUE(sizeof(int64)  == 8);
  EXPECT_TRUE(sizeof(int128) == 16);

  EXPECT_TRUE(sizeof(uint8)   == 1);
  EXPECT_TRUE(sizeof(uint16)  == 2);
  EXPECT_TRUE(sizeof(uint32)  == 4);
  EXPECT_TRUE(sizeof(uint64)  == 8);
  EXPECT_TRUE(sizeof(uint128) == 16);

  EXPECT_TRUE(sizeof(float)  == 4);
  EXPECT_TRUE(sizeof(double) == 8);
}

TEST(Utilities, Basic_Types_Limits)
{
  EXPECT_TRUE(static_cast<uint8>(-1) == std::numeric_limits<uint8>::max());
  EXPECT_TRUE(static_cast<uint16>(-1) == std::numeric_limits<uint16>::max());
}

TEST(Utilities, Math_Constants)
{
  EXPECT_NEAR(nauMath::PI, 3.141592f, std::numeric_limits<float>::epsilon());
}

TEST(Utilities, Math_Arithmetics)
{
  EXPECT_FLOAT_EQ(nauMath::PI, 3.141592f);
}
#else
//Sumano te dejo este pedazo para que yo tambien haga mis dagas

//end Sumanos Testing
#endif
