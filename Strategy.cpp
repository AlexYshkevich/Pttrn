#include <iostream>

class StrategyPay //
{
public:
	virtual ~Strategy() {}
	virtual void use(void) = 0;
};

class Strategy_1: public StrategyPay
{
public:
	Strategy_1
	void use(void){ std::cout << "Strategy_1" << std::endl; };
};

class Strategy_2: public StrategyPay
{
public:
	void use(void){ std::cout << "Strategy_2" << std::endl; };
};

class Context
{
protected:
	StrategyPay* operation;

public:
	virtual ~Context() {}
	virtual void useStrategyPay(void) = 0;
	virtual void setStrategyPay(StrategyPay* v) = 0;
};

class Client: public Context
{
public:
	void useStrategyPay(void)
	{
		operation->use();
	}

	void setStrategyPay(StrategyPay* o)
	{
		operation = o;
	}
};

int main(int /*argc*/, char* /*argv*/[])
{
	Client customClient;
	Strategy_1 str1;
	Strategy_2 str2;

	customClient.setStrategyPay(&str1);
	customClient.useStrategyPay();
	customClient.setStrategyPay(&str2);
	customClient.useStrategyPay();
	customClient.setStrategyPay(&str3);
	customClient.useStrategyPay();

	return 0;
}
