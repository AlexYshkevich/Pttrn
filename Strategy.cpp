#include <iostream>
#include <string>
  
class Strategy 
{
  public:    
    virtual ~Strategy() {}
    virtual void compress( const string & file ) = 0;
};
  
class 1_Strategy : public Strategy
{
  public:
    void compress( const string & file ) {
        cout << "ZIP compression" << endl;
    }
};
  
class 2_Strategy : public Strategy
{
  public:
    void compress( const string & file ) {
        cout << "RAR compression" << endl;
    }
};
  
class 3_Compression : public Strategy
{
  public:
    void compress( const string & file ) {
        cout << "ARJ compression" << endl;
    }
};
  
  
// Класс для использования
class Context 
{
  public:
    Context( Strategy* comp): p(comp) {}
   ~Context() { delete p; }
    void compress( const string & file ) {
      p->compress( file);
    }
  private:
    Strategy* p;
};
  
  
int main()
{
  Context* p = new Context( new 1_Strategy);
  p->compress( "file.txt");
  delete p;
  return 0;
}
