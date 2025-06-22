#include <iostream>

class Person{
public:
	std::string name;
	int age;


	void hello(){
		std::cout << "name: " << name << "\n" << "age: " << age << "\n";
	}
};

int main(){
	std::cout << "test hello() in person class\n";
	Person p;
	p.name = "MEMEME";
	p.age = 29;
	p.hello();
	return 0;
}
