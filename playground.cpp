#include <optional>
#include <iostream>



int main(){

    int x = 4;
    std::optional<int> y{12};
    
    std::cout << sizeof(x) << sizeof(y) << std::endl;

    return 0;
}