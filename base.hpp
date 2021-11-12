#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>

using namespace std;

class Base
{
	public:
		Base();
		
		virtual ~Base(){}
		
		virtual double evaluate() = 0;

		virtual string stringify() =0;

};
#endif //__BASE_HPP__
