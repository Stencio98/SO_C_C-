#include <iostream>
#include <list>


int main(){
    	std::list<std::string> names = {"Anna", "Luca", "Paolo"};
    	for(auto name : names)
        	std::cout << name << " ";
        	
	names.push_front("Mario");
	std::cout << "\n";
	
    	for(auto name : names)
        	std::cout << name << " ";
}	
