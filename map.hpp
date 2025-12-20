#include <optional>
#include <algorithm>
#include <iostream>




template<typename K, typename V>
class unordered_map{

    struct Node{
        K key;
        V value;
        Node* next = nullptr;
        Node() = default;
    };

public:
    Node** data_ = nullptr;
    size_t size_ = 0;
    size_t cap_ = 10;
    static constexpr float alpha = 0.7;

public:
    unordered_map(){
        data_ = new Node*[10];
        std::cout << "Hello world" << std::endl;
    }


    void insert(K key, V value){
        Node* newNode = new Node();
        newNode->key = key;
        newNode->value = value;

        std::size_t hash_key = std::hash<K>{}(key);

        Node*& iter = data_[hash_key];
        
        if(iter == nullptr){
            iter = newNode;
        } else {
            while(iter){
                if(iter->key == key && iter->value == value) return;
                iter = iter->next;
            }
            iter->next = newNode;
        }
        size_++;
    }







};