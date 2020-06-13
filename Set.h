#ifndef NEWLAB3_SET_H
#define NEWLAB3_SET_H

#include "BinaryTree.h"

template <typename T>
class Set{
public:
    Set<T>(){
        T* A = nullptr;
        this->list = new BinaryTree<T>;
    }

    Set<T>(T* new_list, int new_size){
        this->list = new BinaryTree<T>(new_list, new_size);
    }

    T get(int index) const{
        return this->list->elements()[index];
    }

    void delete_elem(T item){
        this->list->erase(item);
    }

    Set<T> concat(const Set<T>& new_set){
        Set<T> result = new_set;
        for (int i = 0; i < this->Get_Length(); ++i) result.Add(this->get(i));

        return result;
    }

    Set<T> intersection(const Set<T>& new_set){
        Set<T> result;
        T elem;

        if (this->Get_Length() < new_set.Get_Length()){
            for (int i = 0; i < this->Get_Length(); ++i){
                elem = this->get(i);
                if (new_set.HasElement(elem)) result.Add(elem);
            }
        }
        else{
            for (int i = 0; i < new_set.Get_Length(); ++i){
                elem = new_set.get(i);
                if (this->HasElement(elem)) result.Add(elem);
            }
        }

        return result;
    }

    bool HasElement(const T& elem) const{
    return list->contains(elem);
    }

    void Add(const T& item){
        if (this->HasElement(item)) return;
        list->add(item);
    }

    friend bool operator==(const Set<T>& set1, const Set<T>& set2){
        return set1.list->f_round() == set2.list->f_round();
    }

    friend Set<T> operator-(const Set<T>& set1, const Set<T>& set2){
        Set<T> result;
        T item;
        for (int i = 0; i < set1.Get_Length(); ++i){
            item = set1.get(i);
            if (!set2.HasElement(item)) result.Add(item);
        }

        return result;
    }

    [[nodiscard]] int Get_Length ()const{
        return list->get_size();
    }

    bool subset(const Set<T>& set){
        if (set.Get_Length() > this->Get_Length()) throw std::logic_error("Subset can't be bigger then set");
        for (int i = 0; i < set.Get_Length(); ++i) if (!this->HasElement(set.get(i))) return false;
        return true;
    }
    
        std::string str(){
        return list->f_round();
    }

    friend std::ostream& operator<<(std::ostream& stream, const Set<T>& set){
        for(auto i : set.list->elements()) stream << i << ' ';
        return stream;
    }

    friend std::istream&operator>>(std::istream& stream, Set<T>& set){

        //      example : elem1 , elem2 , elem3 , elem4 .

        T item;
        char t = ' ';
        while(t != '.'){
            stream >> item;
            set.Add(item);
            stream >> t;
        }
        return stream;
    }

    ~Set<T>() = default;

private:
    BinaryTree<T>* list;
};


#endif //NEWLAB3_SET_H
