#include "TUI_library.h"
#include <stdio.h>

int main() {
    if(login() == 1){
        choose_operation();
    };
    return 0;
}
