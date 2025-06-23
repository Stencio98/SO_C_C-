#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	std::vector<int> v = {3,6,9,3,1,6,90};
	std::vector<std::string> vs = {"ciao", "sono", "stefano", "mela", "bruco", "banana"};
	sort(v.begin(), v.end());
	sort(vs.begin(), vs.end());
	for (auto i : v){
		std::cout << i << " ";
	}
	for (auto i : vs){
		std::cout << i << " ";
	}
}
