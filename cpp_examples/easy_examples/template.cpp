#include <iostream>

template <typename T>
T massimo(T a, T b){
    	return (a > b) ? a : b;
}

int main(){
    	std::cout << massimo(3, 5) << "\n";
    	std::cout << massimo(4.2, 2.3) << "\n";
	std::cout << massimo("c", "a") << "\n";
	return 0;
}
