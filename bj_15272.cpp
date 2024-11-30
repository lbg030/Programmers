#include <iostream>

int main(){

    std::string inp;
    std::cin >> inp;

    std::string check = "ss";

    if (inp.find(check) != std::string::npos){
        std::cout << "hiss";
    } else {
        std::cout << "no hiss";
    }

    return 0;
}