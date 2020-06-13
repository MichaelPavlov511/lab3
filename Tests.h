#ifndef NEWLAB3_TESTS_H
#define NEWLAB3_TESTS_H

#include <cassert>

//#include "BinaryTree.h"
#include "Set.h"

void testBase(){
    int arr[5] = {12, 7, 3, 86, 45};
    BinaryTree<int> bt(arr, 5);

        assert(bt.f_round() == "37124586");
        assert(bt.contains(3));
        assert(bt.get_height() == 3);

    bt.erase(7);

        assert(bt.get_height() == 3);
        assert(!bt.contains(7));
        assert(bt.get_size() == 4);

    bt.add(49);

        assert(bt.get_height() == 4);

    BinaryTree<std::string> emptytree;

        assert(emptytree.is_empty());
}

void testSetBase(){
    int arr[5] = {14, 5, 8, 11, 9};
    Set<int> set(arr, 5);

   assert(set.get(2) == 9);

    set.Add(5);

        assert(set.Get_Length() == 5);
        assert(set.HasElement(8));

    set.Add(13);

        assert(set.HasElement(13));

    set.delete_elem(11);

        assert(!set.HasElement(11));

    set.delete_elem(5);

        assert(!set.HasElement(5));
}

void testSetConcat(){
    int arr1[5] = {-4, 7, 11, 3, 4};
    Set<int> set1(arr1, 5);

    int arr2[4] = {5, 8, 7, 15};
    Set<int> set2(arr2, 4);

    int concat_arr[8] = {-4, 3, 4, 5, 7, 8, 11, 15};
    Set<int> concat_set(concat_arr, 8);

    assert(set1.concat(set2) == concat_set);
    assert(set1.concat(set1) == set1);

}

void testSetIntersection(){
    int arr1[5] = {-4, 7, 11, 3, 4};
    Set<int> set1(arr1, 5);

    int arr2[4] = {5, 8, 7, 15};
    Set<int> set2(arr2, 4);

    int arr3[2] = {3, 4};
    Set<int> set3(arr3, 2);

    int intersection_arr[1] = {7};
    Set<int> intersection_set(intersection_arr, 1);

    assert(set2.intersection(set1) == intersection_set);
    assert(set1.intersection(set3) == set3);
}

void testSetSubtraction(){
    int arr1[5] = {-4, 7, 11, 3, 4};
    Set<int> set1(arr1, 5);

    int arr2[4] = {5, 8, 7, 15};
    Set<int> set2(arr2, 4);

    int arr3[2] = {3, 4};
    Set<int> set3(arr3, 2);

    int subtraction_arr[3] = {-4, 11, 7};
    Set<int> subtraction_set(subtraction_arr, 3);

    int subtraction2_arr[4] = {-4, 11, 3, 4};
    Set<int> subtraction2_set(subtraction2_arr, 4);

    assert(set1 - set3 == subtraction_set);
    assert(set1 - set2 == subtraction2_set);
}

void testSetSubset(){
    int arr1[5] = {-4, 7, 11, 3, 4};
    Set<int> set1(arr1, 5);

    int arr2[4] = {5, 8, 7, 15};
    Set<int> set2(arr2, 4);

    int arr3[2] = {3, 4};
    Set<int> set3(arr3, 2);

    assert(!set1.subset(set2));
    assert(set1.subset(set3));
};


void All_Tests(){
    testBase();
    testSetBase();
    testSetConcat();
    testSetIntersection();
    testSetSubtraction();
    testSetSubset();
}

#endif //NEWLAB3_TESTS_H
