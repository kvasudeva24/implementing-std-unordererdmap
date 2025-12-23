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

public: //public for debugging, private actually
    Node** data_ = nullptr;
    size_t size_ = 0;
    size_t cap_ = 3;
    static constexpr float alpha = 0.7;

    void resize(){
        size_t new_cap = cap_ * 3;
        Node** newData = new Node*[new_cap]{};
        // std::cout << newData << std::endl;
        // std::cout << data_ << std::endl;
        for(size_t i{}; i<cap_; i++){
            Node* item = data_[i];
            while(item){
                Node* old = item;
                item = item->next;

                old->next = nullptr;

                std::size_t hash_key = std::hash<K>{}(old->key);
                hash_key %= new_cap;
                old->next = newData[hash_key];
                newData[hash_key] = old;
            }
        }
        cap_ = new_cap;
        delete[] data_;
        data_ = newData;
        // std::cout << data_ << std::endl;
}

public:
    unordered_map(){
        data_ = new Node*[cap_]{};
    }


    void insert(K key, V value) {
    
        if (size_ >= cap_ * alpha) {
            resize();
        }

        std::size_t hash_key = std::hash<K>{}(key) % cap_;
        Node* curr = data_[hash_key];

        
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value; 
                return;              
            }
            curr = curr->next;
        }

        Node* newNode = new Node();
        newNode->key = key;
        newNode->value = value;

        newNode->next = data_[hash_key]; 
        data_[hash_key] = newNode;       
        
        size_++;
    }




    size_t size() const { return size_; };
    size_t capacity() const { return cap_; }; 

    








};