//
// Created by shaon on 3/21/2025.
//

#include "sort.h"

Sort::Sort(int N, int *arr)
{
    n = N;
    k = N/2;
    a = arr;
    sortedArray = new int[n];
    kArray = new int[k];
}

void Sort::initArray() const
{
    for (int i = 0; i < n; i++)
    {
        sortedArray[i] = a[i];
    }
}

void Sort::printArray() const
{
    for (int i = 0; i < n; i++)
    {
        cout << sortedArray[i] << " ";
    }
    cout << endl;
}

void Sort::sortArray(int number) const
{
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number - 1; j++)
        {
            if (sortedArray[j] < sortedArray[j + 1])
            {
                int temp = sortedArray[j];
                sortedArray[j] = sortedArray[j + 1];
                sortedArray[j + 1] = temp;
            }
        }
    }
}

void Sort::printKArray() const
{
    for (int i = 0; i < k; i++)
    {
        cout << kArray[i] << " ";
    }
    cout << endl;
}

void Sort :: initKArray() const
{
    for (int i = 0; i < k; i++)
    {
        kArray[i] = a[i];
    }
}

void Sort::sortKArray(int number) const
{
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number - 1; j++)
        {
            if (kArray[j] < kArray[j + 1])
            {
                int temp = kArray[j];
                kArray[j] = kArray[j + 1];
                kArray[j + 1] = temp;
            }
        }
    }
}

void Sort::popKArray() const
{
    for (int i  = k; i < n; i++)
    {
        if (a[i] > kArray[k - 1])
        {
            kArray[k - 1] = a[i];
            sortKArray(k);
        }
    }
}
