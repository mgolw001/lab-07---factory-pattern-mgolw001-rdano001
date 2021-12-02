#include "gtest/gtest.h"
#include "Base.hpp"
#include "Factory.hpp"
#include <iostream>
TEST(Test, NoInput){
        Factory f;
        char** arr;
        Base* expression = f.parse(arr,0);
        EXPECT_EQ(expression,nullptr);
}

TEST(AddTest, AddTwoNums){
	Factory f;
	char* arr [] {"1","+","1"};
	Base* expression = f.parse(arr,3);
	double result = expression->evaluate();
	double answer = 2;
	EXPECT_EQ(result,answer);
	delete expression;
}

//insert test cases 


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
