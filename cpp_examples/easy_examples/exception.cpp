#include <iostream>

int main(){
	std::cout << "this example really look like java\n";
	try {
		throw 42;
	}
	catch(int e){
		std::cout << "exception: " << e << "\n";
	}

}
