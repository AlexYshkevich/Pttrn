#include <iostream>
#include <string>

template<typename TYPE,size_t COUNT>
inline size_t lenof(TYPE(&)[COUNT]){return COUNT;}

class Go;
class Till;
class Theend;
 
class Visitor{
public:
  virtual void visit(Go& ref) = 0;
  virtual void visit(Till& ref) = 0;
  virtual void visit(Theend& ref) = 0;
};
 
class Element{
public:
  virtual void accept(Visitor& v) = 0;
};
 
class Go: public Element{
public:
  void accept(Visitor& v)
  {
    v.visit(*this);
  }
};
 
class Till: public Element{
public:
  void accept(Visitor& v)
  {
    v.visit(*this);
  }
};
 
class Theend:public Element{
public:
  void accept(Visitor& v)
  {
    v.visit(*this);
  }
};
 
class GetType: public Visitor{
public:
  std::string value;
public:
  void visit(Go& ref)
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
