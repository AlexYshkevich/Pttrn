#include <iostream>

class StrategyPay //
{
public:
	virtual ~StrategyPay() {}
	virtual void StrategyPay(const string & file) = 0;
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

class Compressor
{
public:
	Compressor(Compression* comp) : p(comp) {}
	~Compressor() { delete p; }
	void compress(const string & file) {
		p->compress(file);
	}
private:
	Compression* p;
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
