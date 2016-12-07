#include <iostream>
#include <string>
  
class Strategy // Абстрактный базовый класс. Определяет, как будут использоваться алгоритмы.
//объявляет интерфейс, общий для всех алгоритмов и используемый классом Context. 
{
  public:    
    virtual ~Strategy() {}
    virtual void compress( const string & file ) = 0;
};
  
class 1_Strategy : public Strategy // Подласс. Реализация алгоритма.
{
  public:
    void compress( const string & file ) {
        cout << "ZIP compression" << endl;
    }
};
  
class 2_Strategy : public Strategy // Подласс. Реализация алгоритма.
{
  public:
    void compress( const string & file ) {
        cout << "RAR compression" << endl;
    }
};
  
class 3_Compression : public Strategy // Подласс. Реализация алгоритма.
{
  public:
    void compress( const string & file ) {
        cout << "ARJ compression" << endl;
    }
};
  
class Context // Используя подклассы, ссылаясь на конкретный тип абстрактного класса, реализует выбранный алгоритм.
{
  public:
    Context( Strategy* comp): p(comp) {}
   ~Context() { delete p; }
    void compress( const string & file ) {
      p->compress( file);
    }
  private:
    Strategy* p;//Указатель на объект абстрактного и предназначен для переадресации пользовательских запросов конкретному алгоритму.
};
  
  
int main()
{
  Context* p = new Context( new 1_Strategy);
  p->compress( "file.txt");
  delete p;
  return 0;
}
