#include <iostream>

class A {
public:
  virtual std::string methodeA1() = 0;
  virtual std::string methodeA2() = 0;
};

class B {
public:
  std::string methodeB1() { return "Salut "; }
  std::string methodeB2() { return "Galarneau" + ponctuation(); }
  virtual std::string ponctuation() { return "!"; }
};

class C : public A, private B {
  virtual std::string methodeA1() override { return methodeB1(); }
  virtual std::string methodeA2() override { return methodeB2(); }

  // On peut surcharger une methode issue de l'heritage prive.
  virtual std::string ponctuation() override { return "!!!?!!!"; }
};

int main()
{
  A * x = new C();
  std::cout << x->methodeA1() << x->methodeA2() << std::endl;
  return 0;
}
  
