#include <iostream>
#include <map>

int main(){
	std::map<std::string, int> age;
	age["Luke"] = 23;
	age["Anna"] = 22;
	age["Steve"] = 24;
	age["Angeline"] = 42;
	
	for(auto p:age){
		std::cout << p.first << ": " << p.second << "\n";
		//std::cout << p.first << ": " ;//<< p.second << "\n";
	}
	
	std::cout << "\n\n";
	
	for(auto p:age){
		
		std::cout << p.second << ": " << p.first << "\n";
	}
}
