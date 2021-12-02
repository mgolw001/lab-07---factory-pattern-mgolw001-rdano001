#include "Base.hpp"
#include "Factory.hpp"
#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
	Factory f;
  	Base* expression = f.parse(argv+1, argc-1);//puls one moves the pointer to the first input rather than the ./calculator, -1 corrects the length
	if(expression!=nullptr){
		for (int i = 1; i<argc;i++){
			cout<<argv[i];
		}
		expression->stringify();
        	cout<<" = "<<expression->evaluate()<<endl;	
	}
	else{
		cout<<"ERROR INVALID INPUT"<<endl;
	}
	delete expression;
	return 0;
}
