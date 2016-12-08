#include <iostream>
#include <string>
using namespace std;
 
class BMW_E39{
public:
	virtual BMW_E39 *clone() const = 0;
	virtual void message(){
        cout << "BMW E39 is base for the:";
}
};
 
class Imitator : public  BMW_E39
{
public:
	Imitator();
	Imitator *clone() const { return new Imitator( *this )	
};
 
int main(){
	Imitator* BMW_M5; 
	BMW_M5.message();
	return 0;
	};
