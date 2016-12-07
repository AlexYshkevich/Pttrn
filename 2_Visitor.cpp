#include <iostream>
#include <string>

template<typename TYPE,size_t COUNT>
inline size_t lenof(TYPE(&)[COUNT]){return COUNT;}

class Go;
class Till;
class Theend;
 
class Visitor{ // Базовый класс
//Нужен для создания объектов
public:
  virtual void visit(Go& ref) = 0; //методы для Element
  virtual void visit(Till& ref) = 0;//их реализация использует открытый интрерфейс Element
  virtual void visit(Theend& ref) = 0;
};
 
class Element{
public:
  virtual void accept(Visitor& v) = 0; // добавление метода в иерархию  
};
 
class Go: public Element{
public:
  void accept(Visitor& v)//вызывается при передаче созданного объекта в Element
  {
    v.visit(*this);
  }
};
 
class Till: public Element{
public:
  void accept(Visitor& v)//метод, который реализует Element
//В качестве параметра принимает указатель или ссылку на абстрактный базовый класс иерархии Visitor
  {
    v.visit(*this);//вызывает метод visit(), передавая в качестве единственного параметра указатель this
  }
};
 
class Theend:public Element{
public:
  void accept(Visitor& v)
  {
    v.visit(*this);
  }
};
 
class DominnantRuleDisgrase: public Visitor{ // Для каждого метода, котоый должен выполняться для объектов Element, создаем производный от Visitor класс
//Обрабатывает функциональность подклассов Element
//Каждая новая добавляемая операция моделируется при помощи конкретного подкласса
 public:
  std::string value;
public:
  void visit(Go& ref)// используют интерфейс Element
  {
    value="Go";
  }
  void visit(Till& ref)
  { 
    value="Till";
  }
  void visit(Theend& ref)
  {
    value="Theend";
  }
};
 
int main()
{
  Go go;
  Till till; 
  Theend theend;
  Element* elements[] = { &go, &till, &theend};
  for(size_t i = 0; i < lenof(elements); i++)  {
    GetType visitor;
    elements[i]->accept(visitor);
    std::cout<<visitor.value<<std::endl;
  }
  return 0;
}
