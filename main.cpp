#include "Base.hpp"
#include "Factory.hpp"
#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
	Factory f;
  	Base* expression
	expression = f.parse(argv+1, argc-1);//puls one moves the pointer to the first input rather than the ./calculator, -1 corrects the length
	if(expression == nullptr){
		cout<<"ERROR INVALID INPUT"<<endl;
		return 0;
	}
	expression->stringify();
	cout<<" = "<<expression.evaluate()<<endl;	
	return 0;
}
