#include "map.hpp"



int main(){


    unordered_map<int, char> test;
    // test.insert(4, 'c');
    // int x = 412;
    // test.insert(x, 'o');
    // test.insert(11, 'k');
    // test.insert(22, 'i');

    auto array = test.data_;
    for(int i{}; i<10; i++){
        auto* iter = array[i];
        if(!iter){
            std::cout << "no data on index " << i << std::endl; 
        } else {
            while(iter){
                std::cout << "Index: " << i << " --- Key/Value: " << iter->key << "/" << iter->value << std::endl;
                iter = iter->next;
            }
        }
        
    }

    return 0;
}