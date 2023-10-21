#include <iostream>

int main(){

    std::string c;
    int a, b;

    std::cin >> c;
    std::cin >> a >> b;

    if(c == "ADD"){
        std::cout << a + b << std::endl;
    }
    else if(c == "SUB") {
        std::cout << a - b << std::endl;
    }
    else if(c == "RSF"){
        std::cout << (a >> b) << std::endl;
    }
    else if(c == "LSF"){
        std::cout << (a << b) << std::endl;
    }
    return 0;
}