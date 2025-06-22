#include <iostream> 
//input output schermo e tastiera, output di errore

//using namespace std; --> bello ma in grandi codici può essere difficile
//gestire i nomi delle variabili
//using namespace std; --> consente di scrivere "cout" al posto di "std::cout"

int read_from_keyboard(){
    std::cout << "we are inside read_from_keyboard\n";
    int x;
    std::cout << "enter an integer number\n";
    std::cin >> x;
    std::cout << "u inserted " << x << "\n";
    return 0;
}

int main(){
    std::cout << "hello\n"; 
    //std::cout è l'oggetto che scrive su console (like printf)
    // << inserisce ciò che c'è a destra nel flusso di output    
    std::cout << "functions to try c++\n";
    read_from_keyboard();
}


