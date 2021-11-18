#include "Base.hpp"
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
  	Base* expression
	expression = parse(<insert parameters>);
	expression.stringify();
	cout<<" = "<<expression.evaluate()<<endl;	
	return 0;
}
