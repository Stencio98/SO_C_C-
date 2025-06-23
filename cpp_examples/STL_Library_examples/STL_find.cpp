#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	std::vector<int> v = {3,4,6,1,9,0,2};
	auto it = find(v.begin(), v.end(), 9);
	auto it2 = find(v.begin(), v.end(), 2);
	
	if (it != v.end()){
		std::cout << "finded: " << *it << "\n";
	}
	else {
		std::cout << "not finded" << "\n";
	}
	
	if (it2 != v.end()){
		std::cout << "finded: " << *it2 << "\n";
	}
	else {
		std::cout << "not finded" << "\n";
	}
		
}
