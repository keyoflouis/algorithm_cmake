#pragma once
#include <iostream>

// arr[l...r]
// return p, arr[l...p-1] <arr[p]; arr[p+1 ... r] >arr[p]
template <class T>
int __partition(T arr[], int l, int r)
{
    T v = arr[l];

    // arr[l+1..j]<v;arr[j+1...i]>v
    int j = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] < v)
        {
            std::swap(arr[j + 1], arr[i]);
            j++;
        }
    }
    std::swap(arr[l], arr[j]);
    return j;
}

// arr[l...r]
template <class T>
void __quickSort(T arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template <class T> 
void quickSort(T arr[], int n)
{
    __quickSort(arr, 0, n - 1);
}