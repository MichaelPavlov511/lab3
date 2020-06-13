#ifndef NEWLAB3_BINARYTREE_H
#define NEWLAB3_BINARYTREE_H
#pragma once

#include <string>
#include <vector>

template <typename T>
class BinaryTree{
    struct Node
    {
        T data;
        Node* left;
        Node* right;
    };


public:

    BinaryTree() {
        root = nullptr;
    }

    BinaryTree(T* array, int arr_size) {
        root = nullptr;
        for (int i = 0; i < arr_size; ++ i) add(array[i]);
    }

    ~BinaryTree() {
        destroy_tree();
    }

    void add(T item){
        if(this->contains(item)) return;

        if(root != nullptr){
            add_(item, root);
            size++;
        }
        else{
            root = new Node;
            root->data = item;
            root->left = nullptr;
            root->right = nullptr;
        }
    }

    Node* search(T item) {
        return search_(item, root);
    }

    void destroy_tree() {
        destroy_tree_(root);
    }

    bool contains(T item) {
        Node* result = search_(item, root);
        return result != nullptr;
    }

    int get_height() {
        return get_height_(root);
    }

    int get_size() {
        return size;
    }

    bool is_empty() {
        return !root;
    }

    std::string f_round(){
        f_round_(root);
        std::string result = f_round_str;
        f_round_str = "";
        return result;
    }

    std::vector<T> elements(){
        elements_(root);
        std::vector<T> result = Elements;
        Elements.clear();
        return result;
    }

    void erase(T item){
        root = erase_(item, root);
        size--;
    }



private:
    void destroy_tree_(Node* node) {
        if(node != nullptr){
            destroy_tree_(node->left);
            destroy_tree_(node->right);
            delete node;
        }
    }

    void add_(T item, Node* node){
        if(item < node->data){
            if(node->left != nullptr) add_(item, node->left);
            else{
                node->left = new Node;
                node->left->data = item;
                node->left->left = nullptr;
                node->left->right = nullptr;
            }
        }
        else if(item >= node->data){
            if(node->right != nullptr) add_(item, node->right);
            else{
                node->right = new Node;
                node->right->data = item;
                node->right->left = nullptr;
                node->right->right = nullptr;
            }
        }
    }

    Node* search_(T item, Node *node) {
        if(node != nullptr){
            if(item == node->data) return node;
            if(item < node->data) return search_(item, node->left);
            else return search_(item, node->right);
        }
        else return nullptr;
    }

    void f_round_(Node* node){
        if(node != nullptr){
            f_round_(node->left);
            f_round_str+=std::to_string(node->data);
            f_round_(node->right);
        }
    }

    int get_height_(const Node *node) {
        if (node == nullptr) return 0;
        int lHeight = get_height_(node->left);
        int rHeight = get_height_(node->right);

        if(lHeight > rHeight) return (lHeight + 1);
        else return (rHeight + 1);
    }

    void elements_(Node* node){
        if(node != nullptr){
            elements_(node->left);
            Elements.push_back(node->data);
            elements_(node->right);
        }
    }

    Node* minValueNode(Node* node){
        Node* current = node;
        while(current && current->left != nullptr) current = current->left;
        return current;
    }

    Node* erase_(T item, Node* node){
        if(node == nullptr) return node;
        if(item < node->data) node->left = erase_(item, node->left);
        else if(item > node->data) node->right = erase_(item, node->right);
        else{
            if(node->left == nullptr){
                Node* temp = node->right;
                free(node);
                return temp;
            }
            else if(node->right == nullptr){
                Node* temp = node->right;
                free(node);
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = erase_(item, node->right);
        }
        return node;
    }

    int size = 1;
    std::vector<T> Elements;
    Node* root;
    std::string f_round_str;

};



#endif //NEWLAB3_BINARYTREE_H
