/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file main.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief Utilities Unit Testing main
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

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

struct Testing : public ::testing::Test {
  virtual void SetUp() {
    fails = 0;
  }

  virtual void TearDown() {
    if (fails > 0) {
      std::cerr << "Testing::TearDown sees failures" << std::endl;
    }
  }

  unsigned fails;
};

int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
  
}
#ifdef MARCOTESTING
TEST_F(Testing, Basic_Types)
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
  fails += ::testing::Test::HasFailure();
}

TEST_F(Testing, Basic_Types_Limits)
{
  EXPECT_TRUE(static_cast<uint8>(-1)  == std::numeric_limits<uint8>::max());
  EXPECT_TRUE(static_cast<uint16>(-1) == std::numeric_limits<uint16>::max());
  EXPECT_TRUE(static_cast<uint32>(-1) == std::numeric_limits<uint32>::max());
  EXPECT_TRUE(static_cast<uint64>(-1) == std::numeric_limits<uint64>::max());
  fails += ::testing::Test::HasFailure();
}

TEST_F(Testing, Math_Constants)
{
  EXPECT_FLOAT_EQ(nauMath::PI, 3.141592f);
  EXPECT_FLOAT_EQ(nauMath::DEGREE, 57.295779f);
  EXPECT_NEAR(nauMath::RADIAN, 0.017453, 0.00001);
  EXPECT_FLOAT_EQ(nauMath::EULER, 2.71828182f);
  fails += ::testing::Test::HasFailure();
}

TEST_F(Testing, Math_Arithmetics)
{
  EXPECT_EQ(nauMath::pow(3, 2), 9);
  EXPECT_EQ(nauMath::cos(0), 1);
  EXPECT_EQ(nauMath::sin(0), 0);
  EXPECT_EQ(nauMath::floor(nauMath::PI), 3);
  EXPECT_EQ(nauMath::ceil(nauMath::DEGREE), 58);
  EXPECT_EQ(nauMath::roundHalf(4.6f), 4.5f);
  EXPECT_EQ(nauMath::sqr(6), 36);
  EXPECT_EQ(nauMath::sqrt(9), 3);
  fails += ::testing::Test::HasFailure();
}
#else
  #ifdef IVANTESTING
//Iv�n te dejo este pedazo para que yo tambien haga mis dagas

//end Iv�n Testing
  #endif
#endif
