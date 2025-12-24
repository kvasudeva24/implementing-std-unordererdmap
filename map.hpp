#include <optional>
#include <algorithm>
#include <iostream>
#include <stdexcept>





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

    //since all keys are unique in a map, we pass one key as the parameter
    void remove(K key){
        std::size_t  hash_key = std::hash<K>{}(key) % cap_;
        Node* bucket = data_[hash_key];
        Node* trail = nullptr;


        while(bucket){
            if(bucket->key == key){
                //two cases:
                //1. if bucket is the head of the list and trail is null we move it along
                //2. if node is in middle we jump with trail and delete
                if(trail == nullptr){
                    trail = bucket;
                    bucket = bucket->next;
                    delete trail;
                    data_[hash_key] = bucket;
                    // std::cout << "entered properly case 1" << std::endl;
                } else {
                    trail->next = bucket->next;
                    delete bucket;
                    // std::cout << "entered properly case 2 " << std::endl;
                }
                size_--;
                return;
            }
            trail = bucket;
            bucket = bucket->next;
        }
        throw std::invalid_argument("Key is not in structure");
    }


    ~unordered_map(){
        for(size_t i{}; i<cap_; i++){
            Node* bucket = data_[i];
            Node* trail = nullptr;

            while(bucket){
                trail = bucket;
                bucket = bucket->next;
                delete trail;
                trail = nullptr;
            }
            data_[i] = nullptr;
        }
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        cap_ = 0;
        std::cout << "Deleted!" << std::endl;
    }




    size_t size() const { return size_; };
    size_t capacity() const { return cap_; }; 

    








};