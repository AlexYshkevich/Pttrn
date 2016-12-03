#include <iostream>

class StrategyPay //
{
public:
	virtual ~StrategyPay() {}
	virtual void StrategyPay() = 0;
};

class Strategy_1: public StrategyPay
{
public:
	void StrategyPay(const string & file) {
		cout << "Credit_Card" << endl;
	}
};

class Strategy_2: public StrategyPay
{
public:
	void StrategyPay(const string & file) {
		cout << "Apple_Pay" << endl;
	}
};

class Context
{
public:
	Context() : p() {}
	~Context() { delete p; }
	void Context() {p->Context();}
private:
	StrategyPay* p;
};

int main()
{
	Context* p = 1000;
	p->Context();
	delete p;
	system("pause");
	return 0;
}
