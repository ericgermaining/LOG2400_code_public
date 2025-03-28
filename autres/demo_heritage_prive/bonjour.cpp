#include <iostream>

class A {
public:
  virtual std::string methodeA1() = 0;
  virtual std::string methodeA2() = 0;
};

class B {
public:
  std::string methodeB1() { return "Salut "; }
  std::string methodeB2() { return "Galarneau!"; }
};

class C : public A, private B {
  virtual std::string methodeA1() override { return methodeB1(); }
  virtual std::string methodeA2() override { return methodeB2(); }
};

int main()
{
  A * x = new C();
  std::cout << x->methodeA1() << x->methodeA2() << std::endl;
  return 0;

  // Ce bloc ne fonctionnera pas.  Pourquoi?
  // B * y = new C();
  // std::cout << y->methodeB1() << y->methodeB2() << std::endl;
  // return 0;
}
  
