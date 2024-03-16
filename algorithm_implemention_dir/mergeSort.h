#pragma once
#include "insertionSort.h"
int globle_test = 0;

template <class T>
void __merge(T arr[], int l, int mid, int r)
{
    T aux[r - l + 1];
    for (int i = l; i <= r; i++)
    {
        aux[i - l] = arr[i];
    }

    int i = l, j = mid + 1;

    for (int k = l; k <= r; k++)
    {
        if (i > mid)
        {
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r)
        {
            arr[k] = aux[i - l];
            i++;
        }
        else if (aux[i - l] < aux[j - l])
        {
            arr[k] = aux[i - l];
            i++;
        }
        else
        {
            arr[k] = aux[j - l];
            j++;
        }
    }
}

template <class T>
void __mergeSort(T arr[], int l, int r)
{
    /*if(l>r) return;*/
    if (r - l <= 15)
    {
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);

    if (arr[mid] > arr[mid + 1])
    {
        __merge(arr, l, mid, r);
        // optimism when the arrray is almostly sorted
    }
}

template <class T>
void mergeSort(T arr[], int n)
{
    // std::cout << "first palce" << std::endl;
    __mergeSort(arr, 0, n - 1);
}

template <class T>
void mergeSortBU(T arr[], int n)
{
    for (int sz = 1; sz <= n; sz += sz)
        for (int i = 0; i + sz < n; i += sz + sz)
            __merge(arr, i, i + sz - 1,std::min((i + sz) + sz - 1, n - 1));
}



/*************
 * 两种实现中，递归的实现更加高效
 * 
 *  优化：
 *      1.插入排序优化递归到底的情况
 *      2.针对近乎有序的数组，可以先比较  arr[mid]  arr[mid + 1]，再进行merge
 * 
*/