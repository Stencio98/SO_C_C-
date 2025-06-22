#include <iostream>
#include <vector>


int main(){
	std::cout << "example of dynamic array (like malloc)\n";
    	std::cout << "before push\n";
    	std::vector<int> v = {10, 20, 30};
    	for(auto x : v)
		std::cout << x << " ";
	
	v.push_back(40);
    	std::cout << "\nafter push\n";
    	for(auto x : v)
        	std::cout << x << " ";
}
