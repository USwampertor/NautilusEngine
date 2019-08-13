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

#include <DirectXMath.h>

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

TEST_F(Testing, Vector_2) {
  Vector2 a;
  Vector2 b;
  Vector2 r;
  Vector2 t;
  float f;

}

TEST_F(Testing, Vector_3) {
  Vector3 a;
  Vector3 b;
  Vector3 r;
  Vector3 t;
  float f;

  a.setValues(1, 0, 3);
  b.setValues(2, 4, 5);
  r = a + b;

  t.setValues(3, 4, 8);

  for (uint32 i = 0; i < 3; ++i) {
    EXPECT_FLOAT_EQ(r[i], t[i]);
  }

  f = Vector3::dot(a, b);

  EXPECT_FLOAT_EQ(f, 17.0f);

  r = Vector3::cross(a, b);
  t.setValues(-12, 1, 4);

  for (uint32 i = 0; i < 3; ++i) {
    EXPECT_FLOAT_EQ(r[i], t[i]);
  }

  r = a * 2;
  t.setValues(2, 0, 6);

  for (uint32 i = 0; i < 3; ++i) {
    EXPECT_FLOAT_EQ(r[i], t[i]);
  }

  std::cout << t.toString() << std::endl;
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

  for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      EXPECT_NEAR(temp.m[i][j],
                  Matrix4::IDENTITY.m[i][j],
                  Math::KINDASMALLNUMBER);
    }
  }

}

TEST_F(Testing, Quaternions) {

  using namespace DirectX;

  uint32_t stop;

  Vector3 v;
  Vector3 a;
  Vector3 r;
  Vector3 vPlacebo;

  Quaternion q;
  Quaternion q2;
  Quaternion qPlacebo;

  Matrix3 m;
  Matrix3 mPlacebo;
  
  XMVECTOR dXv1 = {};
  XMVECTOR dXv2 = {};

  dXv1 = XMVectorSetIntX(dXv1, 0);
  dXv1 = XMVectorSetIntY(dXv1, 1);
  dXv1 = XMVectorSetIntZ(dXv1, 0);
  dXv1 = XMVectorSetIntW(dXv1, 1);
  
  dXv2 = XMQuaternionRotationAxis(dXv1, Math::degToRad(90.0f));

  vPlacebo = { 75.0f, 20.0f, 32.0f };
  qPlacebo = { 0.707f, 0.0f, 0.0f, 0.707f };
  mPlacebo.setValues(.79f, -0.49f, 0.34f, 0.41f, 0.044f, -0.90f, 0.43f, 0.86f, 0.24f);

  q.setEulerDegrees(90, 0, 0);

  std::cout << q.toString()        << std::endl;
  std::cout << qPlacebo.toString() << std::endl;
  std::cout << std::endl;


  q.setValues(0.614f, -0.033f, 0.317f, 0.722f);

  std::cout << std::endl;

  m = q.rotationMatrix();

  std::cout << m.toString()        << std::endl;
  std::cout << mPlacebo.toString() << std::endl;
  std::cout << std::endl;


  q.setValues(12, 30, 24, -60);

  q2.setValues(-2, -3, -4, 1);
 
  Quaternion q3 = q * q2;

  qPlacebo.setValues(84, 210, 288, 150);

  std::cout << q3.toString()       << std::endl;
  std::cout << qPlacebo.toString() << std::endl;
  std::cout << std::endl;

  q.rotateAroundDegrees(180, q);
  qPlacebo.setValues(12, 30, 24, 60);

  std::cout << q.toString()        << std::endl;
  std::cout << qPlacebo.toString() << std::endl;
  std::cout << std::endl;

  v = Vector3::UP;
  a = Vector3::RIGHT;

  r = Quaternion::rotateAroundDegrees(90, v, a);
  vPlacebo = Vector3::FRONT;

  std::cout << r.toString()        << std::endl;
  std::cout << vPlacebo.toString() << std::endl;

  q = Quaternion::RIGHT;

  r = q.rotateAroundDegrees(90, v);

  std::cout << r.toString() << std::endl;
  std::cout << vPlacebo.toString() << std::endl;

  Matrix4 m4 = Matrix4::IDENTITY;

  q.setRotationMatrix(m4.getRotationMatrix());

  std::cout << q.rotationMatrix().toString() << std::endl;
  std::cout << m4.getRotationMatrix().toString() << std::endl;

  m4.rotateX(Math::degToRad(12.34));
  m4.rotateY(Math::degToRad(34.23));
  m4.rotateZ(Math::degToRad(45.34));

  q.setRotationMatrix(m4.getRotationMatrix());

  std::cout << m4.getRotationMatrix().toString() << std::endl;
  std::cout << q.rotationMatrix().toString() << std::endl;

  m4 = Matrix4::IDENTITY;
  q.setRotationMatrix(m4.getRotationMatrix());

  q.rotateAroundY(Math::degToRad(90.0));
  m4.rotateY(Math::degToRad(90.0));

  std::cout << "<=== ROTATION TEST ===>" << std::endl;

  std::cout << q.toString() << std::endl;
  std::cout << XMVectorGetX(dXv2) << " " << XMVectorGetY(dXv2) << " "
            << XMVectorGetZ(dXv2) << " " << XMVectorGetW(dXv2) << std::endl;

  std::cout << "<=== ROTATION TEST ===>" << std::endl;

  std::cout << m4.getRotationMatrix().toString() << std::endl;
  std::cout << q.rotationMatrix().toString() << std::endl;
  
  std::cin >> stop;
}

#else
#endif
