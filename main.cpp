#include "map.hpp"
#include <algorithm>



int main(){


    unordered_map<int, char> test;
    auto array = test.data_;
    test.insert(4, 'c'); 
    // test.insert(4, 'w');
    for(size_t i{}; i<test.cap_; i++){
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



    // for(size_t i{}; i<test.cap_; i++){
    //     auto* iter = array[i];
    //     if(!iter){
    //         std::cout << "no data on index " << i << std::endl; 
    //     } else {
    //         while(iter){
    //             std::cout << "Index: " << i << " --- Key/Value: " << iter->key << "/" << iter->value << std::endl;
    //             iter = iter->next;
    //         }
    //     }
    // }

    // test.insert(4, 'l');
    // for(size_t i{}; i<test.cap_; i++){
    //     auto* iter = array[i];
    //     if(!iter){
    //         std::cout << "no data on index " << i << std::endl; 
    //     } else {
    //         while(iter){
    //             std::cout << "Index: " << i << " --- Key/Value: " << iter->key << "/" << iter->value << std::endl;
    //             iter = iter->next;
    //         }
    //     }
    // }

    // std::cout << std::addressof(array) << std::endl;
    // std::cout << test.cap_ << std::endl;


    // for(size_t i{}; i<test.cap_; i++){
    //     auto* iter = array[i];
    //     if(!iter){
    //         std::cout << "no data on index " << i << std::endl; 
    //     } else {
    //         while(iter){
    //             std::cout << "Index: " << i << " --- Key/Value: " << iter->key << "/" << iter->value << std::endl;
    //             iter = iter->next;
    //         }
    //     }
    // }

    return 0;
}




// int x = 412;
    // test.insert(x, 'o');
    // test.insert(11, 'k');
    // test.insert(22, 'i');