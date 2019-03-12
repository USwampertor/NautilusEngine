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
#include <nauMatrix4.h>

#include <iostream>


#define MARCOTESTING
#ifndef MARCOTESTING
# define IVANTESTING
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
  EXPECT_FLOAT_EQ(Math::PI, 3.141592f);
  EXPECT_FLOAT_EQ(Math::DEGREE, 57.295779f);
  EXPECT_NEAR(Math::RADIAN, 0.017453, 0.00001);
  EXPECT_FLOAT_EQ(Math::EULER, 2.71828182f);
  fails += ::testing::Test::HasFailure();
}

TEST_F(Testing, Math_Arithmetics)
{
  EXPECT_EQ(Math::pow(3, 2), 9);
  EXPECT_EQ(Math::cos(0), 1);
  EXPECT_EQ(Math::sin(0), 0);
  EXPECT_EQ(Math::floor(Math::PI), 3);
  EXPECT_EQ(Math::ceil(Math::DEGREE), 58);
  EXPECT_EQ(Math::roundHalf(4.6f), 4.5f);
  EXPECT_EQ(Math::sqr(6), 36);
  EXPECT_EQ(Math::sqrt(9), 3);
  fails += ::testing::Test::HasFailure();
}

TEST_F(Testing, Matrices)
{
  Matrix4 nautilusMatrix(0);
  Matrix4 nautilusMatrix2(0);
  Matrix4 comparing(0);
  Matrix4 temp(0);

  Matrix3 nautilusMatrix3(0);

  nautilusMatrix3 = Matrix3::IDENTITY;

  nautilusMatrix.setValues(3, 3, 2, 6, 6, 7, 3, 4, 8, 2, 3, 6, 1, 2, 7, 3);
  nautilusMatrix2.setValues(4, 8, 2, 1, 3, 4, 5, 7, 5, 4, 3, 1, 7, 7, 7, 1);
  
  comparing.setValues(73, 86, 69, 32, 88, 116, 84, 62, 95, 126, 77, 31, 66, 65, 54, 25);
  temp = nautilusMatrix * nautilusMatrix2;
  EXPECT_TRUE(temp == comparing);

  temp = nautilusMatrix;
  temp *= nautilusMatrix2;
  EXPECT_TRUE(temp == comparing);

  comparing.setValues(7, 11, 4, 7, 9, 11, 8, 11, 13, 6, 6, 7, 8, 9, 14, 4);
  temp = nautilusMatrix + nautilusMatrix2;
  EXPECT_TRUE(temp == comparing);

  temp = nautilusMatrix;
  temp += nautilusMatrix2;
  EXPECT_TRUE(temp == comparing);

  comparing.setValues(-1, -5, 0, 5, 3, 3, -2, -3, 3, -2, 0, 5, -6, -5, 0, 2);
  temp = nautilusMatrix - nautilusMatrix2;
  EXPECT_TRUE(temp == comparing);

  temp = nautilusMatrix;
  temp -= nautilusMatrix2;
  EXPECT_TRUE(temp == comparing);

  temp = nautilusMatrix;
  nautilusMatrix.inverse();
  temp *= nautilusMatrix;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      EXPECT_NEAR(temp.m[i][j],
                  Matrix4::IDENTITY.m[i][j],
                  Math::KINDASMALLNUMBER);
    }
  }


}

#else
#endif
