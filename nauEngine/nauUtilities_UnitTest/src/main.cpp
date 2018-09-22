#include <gtest/gtest.h>
#include <conio.h>
int main(int argc, char **argv)
{
		::testing::InitGoogleTest(&argc,argv);
		std::cout<< RUN_ALL_TESTS();
    _getch();
    return 0;
}
TEST(Utilities, None)
{

}