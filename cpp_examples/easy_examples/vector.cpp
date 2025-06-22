#include <iostream>
#include <vector>
//using namespace std;

int main(){
	std::vector<int> v = {1,2,3};
	
	int i = 0;
	while(i < v.size()){
		std::cout << v[i] << " ";
		i++;
	}	
	std::cout << "\n";	
}
