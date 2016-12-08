#include <iostream>
#include <string>
#include "stdafx.h"
using namespace std;

class BMW_E39
{
public:
	virtual BMW_E39 *clone() const = 0;
	virtual void message()
{
        cout << "BMW E39 is base for the:";
}
};

class Imitator : public  BMW_E39
{
public:
	Imitator();
	Imitator *clone() const { return new Imitator( *this );	
};

int main()
{
	
	Imitator objBMW_M5; // объявление объекта
	objBMW_M5.message(); // вызов функции класса message
  Context* p = new Context( new 1_Strategy);
  p->compress( "file.txt");
  system("pause");
  return 0;
}

 
