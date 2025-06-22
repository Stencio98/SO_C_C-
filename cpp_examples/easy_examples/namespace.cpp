#include <iostream>

namespace mine {
	void hello(){
		std::cout << "hello from mine namespace\n";
	}
}

int main(){
	std::cout << "a namespace help you to avoid name conficts\n";
	mine::hello();
	 
}
