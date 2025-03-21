//
// Created by shaon on 3/21/2025.
//

#ifndef SORT_H
#define SORT_H
#include <iostream>
using namespace std;
class Sort
{
public:
    Sort(int N, int *arr);
    void initArray() const;
    void printArray() const;
    void sortArray(int number) const;
    void printKArray() const;
    void initKArray() const;
    void sortKArray(int number) const;
    void popKArray() const;
    ~Sort()
    {
        delete [] sortedArray;
        delete [] kArray;
    }
private:
    int k;
    int n;
    int *a;
    int *sortedArray;
    int * kArray;

};
#endif //SORT_H
