#include <iostream>
#include <string>

template<typename TYPE,size_t COUNT>
inline size_t lenof(TYPE(&)[COUNT]){return COUNT;}

class Foo;
class Bar;
class Baz;
 
class Visitor{
public:
  virtual void visit(Foo& ref) = 0;////методы для Element, их реализация использует открытый интрерфейс Element
  virtual void visit(Bar& ref) = 0;
  virtual void visit(Baz& ref) = 0;
};
 
class Element{
public:
  virtual void accept(Visitor& v) = 0; // добавление метода в иерархию  
};
 
class Foo: public Element{
public:
  void accept(Visitor& v)//метод, который реализует Element
//В качестве параметра принимает указатель или ссылку на абстрактный базовый класс иерархии Visitor
//Используя полученный адрес экземпляра подкласса, вызывает его метод visit(),передавая в качестве единственного параметра указатель this
  {
    v.visit(*this);
  }
};
 
class Bar: public Element{
public:
  void accept(Visitor& v)
  {
    v.visit(*this);
  }
};
 
class Baz:public Element{
public:
  void accept(Visitor& v)
  {
    v.visit(*this);
  }
};
 
class GetType: public Visitor{
 // Для каждого метода, котоый должен выполняться для объектов Element, создаем производный от Visitor класс
//Обрабатывает функциональность подклассов Element
//Каждая новая добавляемая операция моделируется при помощи конкретного подкласса
public:
  std::string value;
public:
  void visit(Foo& ref) // используют интерфейс Element
  {
    value="Foo";
  }
  void visit(Bar& ref) // используют интерфейс Element
  { 
    value="Bar";
  }
  void visit(Baz& ref) // используют интерфейс Element
  {
    value="Baz";
  }
};
 
int main()
{
  Foo foo;
  Bar bar; 
  Baz baz;
  Element* elements[] = { &foo, &bar, &baz};
  for(size_t i = 0; i < lenof(elements); i++)  {
    GetType visitor;
    elements[i]->accept(visitor);
    std::cout<<visitor.value<<std::endl;
  }
  return 0;
}
