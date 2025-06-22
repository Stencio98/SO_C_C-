#include <iostream>
//using namespace std;

int somma(int a, int b){
    return a + b;
}

float somma(float a, float b){
    return a + b;
}

int main(){
	std::cout << "!!in c language that kind of overloading is not avaiable!!\n";
	std::cout << "we have same signature with different kind of parameters\n";
    	std::cout << somma(3, 4) << "\n";
    	std::cout << somma(3.61f, 2.5f) << "\n";
	return 0;
}

