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
#include <nauQuaternion.h>

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
  int toStop = 0;
  Matrix4 normalRotation;
  Matrix4 quaterRotation;
  
  Quaternion rotator;
  ::testing::InitGoogleTest(&argc,argv);
  std::cout << RUN_ALL_TESTS() << std::endl;

  std::cin >> toStop;

}
#ifdef MARCOTESTING
TEST_F(Testing, Basic_Types) {
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

TEST_F(Testing, Basic_Types_Limits) {
  EXPECT_TRUE(static_cast<uint8>(-1)  == std::numeric_limits<uint8>::max());
  EXPECT_TRUE(static_cast<uint16>(-1) == std::numeric_limits<uint16>::max());
  EXPECT_TRUE(static_cast<uint32>(-1) == std::numeric_limits<uint32>::max());
  EXPECT_TRUE(static_cast<uint64>(-1) == std::numeric_limits<uint64>::max());
  fails += ::testing::Test::HasFailure();
}

TEST_F(Testing, Math_Constants) {
  EXPECT_FLOAT_EQ(Math::PI, 3.141592f);
  EXPECT_FLOAT_EQ(Math::DEGREE, 57.295779f);
  EXPECT_NEAR(Math::RADIAN, 0.017453, 0.00001);
  EXPECT_FLOAT_EQ(Math::EULER, 2.71828182f);
  fails += ::testing::Test::HasFailure();
}

TEST_F(Testing, Math_Arithmetics) {
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

TEST_F(Testing, Matrices) {
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

TEST_F(Testing, Quaternions) {

  Vector3 v;
  Vector3 vPlacebo;
  Quaternion q;
  Quaternion q2;
  Quaternion qPlacebo;

  Matrix3 m;
  Matrix3 mPlacebo;

  vPlacebo = { 75.0f, 20.0f, 32.0f };
  qPlacebo = { 0.707f, 0.0f, 0.0f, 0.707f };
  mPlacebo.setValues(.79f, -0.49f, 0.34f, 0.41f, 0.044f, -0.90f, 0.43f, 0.86f, 0.24f);

  q.setEulerDegrees(90, 0, 0);

  for (int i = 0; i < 4; ++i) {
    std::cout<< i << ": " << q[i] << " <----> " << qPlacebo[i] << std::endl;
  }


  std::cout << std::endl;

  q.setValues(0.614f, -0.033f, 0.317f, 0.722f);

  v = q.toEulerDegrees();

  for (int i = 0; i < 3; ++i) {
    std::cout << i << ": " << v[i] << " <----> " << vPlacebo[i] << std::endl;
  }

  std::cout << std::endl;

  m = q.rotationMatrix();

  for (uint32_t i = 0; i < 3; ++i) {
    for (uint32_t j = 0; j < 3; ++j) {
      std::cout << i << j << ": " << m.m[i][j] << " <----> " << mPlacebo.m[i][j] << std::endl;
    }
  }

  std::cout << std::endl;

  q2.setValues(2.0f, 3.0f, 4.0f, 1.0f);
  q *= q2;

  qPlacebo.setValues(-3.294, -2.158, 3.796, 0.248);

  for (int i = 0; i < 4; ++i) {
    std::cout << i << ": " << q[i] << " <----> " << qPlacebo[i] << std::endl;
  }

  std::cout << std::endl;
}

#else
#endif
