#include <iostream>
#include <set>

int main(){
	std::set<int> num = {4,2,2,3,6,8,9,9};
	for(auto n : num){
		std::cout << n << " ";
	}
	std::cout << "\n";
}
