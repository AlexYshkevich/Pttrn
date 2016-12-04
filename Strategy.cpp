#include <iostream>

class StrategyPay //
{
public:
	virtual ~StrategyPay() {}
	virtual void StrategyPay();
};

class Strategy_1: public StrategyPay
{
public:
	void StrategyPay()=0 {
		cout << "Credit_Card" << endl;
	}
};

class Strategy_2: public StrategyPay
{
public:
	void StrategyPay() {
		cout << "Apple_Pay" << endl;
	}
};

class Context
{
  public:
    Contex( StrategyPay* comp): p(comp) {}
   ~Contex() { delete p; }
    void compress() {
      p->compress();
    }
  private:
    StrategyPay* p;
};
  
  
int main()
{
  Context* p = new Context( new Strategy_1);
  p->compress();
  delete p;
  return 0;
}
