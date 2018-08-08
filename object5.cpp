#include <cstdio>
#include <string>
#include <memory>

class Person {
  public:
    int age; //年齢
    std::string name; //名前
    
    Person(int _age, const std::string& _name) {
      age = _age;
      name = _name;
    };
};


int main() {
    
  std::shared_ptr<Person> p = std::shared_ptr<Person>(new Person(20, "Watson"));
  printf("%d\n", p->age);
  return 0;
}
//shared使えば勝手にデリートしてくれる！！便利！！
//