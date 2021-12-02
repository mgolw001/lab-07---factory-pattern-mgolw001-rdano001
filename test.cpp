#include "gtest/gtest.h"
#include "Base.hpp"
#include "Factory.hpp"
#include <iostream>
TEST(InputTest, NoInput){
        Factory f;
        char** arr;
        Base* expression = f.parse(arr,0);
        EXPECT_EQ(expression,nullptr);
	delete expression;
}

TEST(InputTest, OperatorFirst){
	Factory f;
	char* arr [] {"+","1"};
        Base* expression = f.parse(arr,2);
        EXPECT_EQ(expression,nullptr);
	delete expression;
}

TEST(InputTest, OperatorLast){
        Factory f;
        char* arr [] {"+"};
        Base* expression = f.parse(arr,1);
        EXPECT_EQ(expression,nullptr);
	delete expression;
}

TEST(InputTest, DoubleOperators){
        Factory f;
        char* arr [] {"+","+"};
        Base* expression = f.parse(arr,2);
        EXPECT_EQ(expression,nullptr);
	delete expression;
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

TEST(AddTest, AddThreeNums){
        Factory f;
        char* arr [] {"1","+","1","+","1"};
        Base* expression = f.parse(arr,5);
        double result = expression->evaluate();
        double answer = 3;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(AddTest, AddFourNums){
        Factory f;
        char* arr [] {"1","+","2","+","3","+","4"};
        Base* expression = f.parse(arr,7);
        double result = expression->evaluate();
        double answer = 10;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(SubTest, SubTwoNums){
        Factory f;
        char* arr [] {"1","-","1"};
        Base* expression = f.parse(arr,3);
        double result = expression->evaluate();
        double answer = 0;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(SubTest, SubThreeNums){
        Factory f;
        char* arr [] {"9","-","3","-","3"};
        Base* expression = f.parse(arr,5);
        double result = expression->evaluate();
        double answer = 3;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(SubTest, SubFourNums){
        Factory f;
        char* arr [] {"9","-","2","-","3","-","4"};
        Base* expression = f.parse(arr,7);
        double result = expression->evaluate();
        double answer = 0;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(MultTest, MultTwoNums){
        Factory f;
        char* arr [] {"3","*","2"};
        Base* expression = f.parse(arr,3);
        double result = expression->evaluate();
        double answer = 6;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(MultTest, MultThreeNums){
        Factory f;
        char* arr [] {"9","*","3","*","3"};
        Base* expression = f.parse(arr,5);
        double result = expression->evaluate();
        double answer = 81;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(MultTest, MultFourNums){
        Factory f;
        char* arr [] {"2","*","2","*","3","*","4"};
        Base* expression = f.parse(arr,7);
        double result = expression->evaluate();
        double answer = 48;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(DivTest, DivTwoNums){
        Factory f;
        char* arr [] {"9","/","3"};
        Base* expression = f.parse(arr,3);
        double result = expression->evaluate();
        double answer = 3;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(DivTest, DivThreeNums){
        Factory f;
        char* arr [] {"9","/","3","/","3"};
        Base* expression = f.parse(arr,5);
        double result = expression->evaluate();
        double answer = 1;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(DivTest, DivFourNums){
        Factory f;
        char* arr [] {"16","/","8","/","4","/","2"};
        Base* expression = f.parse(arr,7);
        double result = expression->evaluate();
        double answer =.25;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(DivTest,DivByZero){
	Factory f;
        char* arr [] {"1","/","0"};
        Base* expression = f.parse(arr,3);
        EXPECT_EQ(expression,nullptr);
	delete expression;
}

TEST(PowTest, PowTwoNums){
        Factory f;
        char* arr [] {"2","**","3"};
        Base* expression = f.parse(arr,3);
        double result = expression->evaluate();
        double answer = 8;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(PowTest, PowThreeNums){
        Factory f;
        char* arr [] {"1","**","3","**","3"};
        Base* expression = f.parse(arr,5);
        double result = expression->evaluate();
        double answer = 1;
        EXPECT_EQ(result,answer);
        delete expression;
}

TEST(PowTest, PowFourNums){
        Factory f;
        char* arr [] {"2","**","2","**","2","**","2"};
        Base* expression = f.parse(arr,7);
        double result = expression->evaluate();
        double answer =256;
        EXPECT_EQ(result,answer);
        delete expression;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
