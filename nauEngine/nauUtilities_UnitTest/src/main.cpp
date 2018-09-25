/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file main.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief Utilities Unit Testing main
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#include <conio.h>

#include <numeric>
#include <gtest/gtest.h>

#include <nauMath.h>
#include <nauPlatformUtilities.h>
#include <nauPrerequisitesUtil.h>
#include <nauVector2.h>

#define MARCOTESTING


#ifndef MARCOTESTING
  #define IVANTESTING
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
  EXPECT_FLOAT_EQ(nauMath::PI, 3.141592f);
  EXPECT_FLOAT_EQ(nauMath::DEGREE, 57.295779f);
  EXPECT_NEAR(nauMath::RADIAN, 0.017453f, 0.00001);
  //EXPECT_FLOAT_EQ(nauMath::EULER, 2.718281f);


}

TEST(Utilities, Math_Arithmetics)
{
  EXPECT_FLOAT_EQ(nauMath::PI, 3.141592f);
}
#else
  #ifdef IVANTESTING
//Iv嫕 te dejo este pedazo para que yo tambien haga mis dagas

//end Iv嫕 Testing
  #endif
#endif
