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
    size_t cap_ = 10;
    static constexpr float alpha = 0.7;

    void resize(){
        if(size_ * alpha >= cap_){
            Node** newData = new Node*[cap_ * 3];
            for(size_t i{}; i<cap_; i++){
                Node* iter = data_[i];
                if(iter == nullptr) continue;
            
                Node* trail = nullptr;

                Node* newNode = new Node();
                newNode->key = iter->key;
                newNode->value = iter->value;


                //finish


            }



        }
    }

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
        hash_key %= cap_;

        Node*& iter = data_[hash_key];
        
        if(iter == nullptr){
            iter = newNode;
        } else {
            Node* curr = iter;
            while(curr->next){
                if(curr->key == key && curr->value == value){
                    delete newNode;
                    return;
                }
                curr = curr->next;
            }
            if(curr->key == key && curr->value == value){
                delete newNode;
                return;
            }
            curr->next = newNode;
        }
        size_++;
        resize();
    }

    size_t size() const { return size_; };
    size_t capacity() const { return cap_; }; 

    








};