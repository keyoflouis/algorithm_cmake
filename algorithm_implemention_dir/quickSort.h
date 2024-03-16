#pragma once
#include <iostream>

// arr[l...r]
// return p, arr[l...p-1] <arr[p]; arr[p+1 ... r] >arr[p]
template <class T>
int __partition(T arr[], int l, int r)
{
    
    //swap(arr[l],arr[rand()%(r-l+1)+l]);

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
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}







/********************************************************************************
 *  快速排序在去排序一个完全有序的或有着大量重复元素的数组，就是一个n^2 的算法,
 * 
 * 
 * 
 * ************
 *    优化：
 *         1. 用插入排序优化递归到底的情况
 *         2. 针对近乎有序的数组，可以用随机种子，写一个随机算法。swap(arr[l],arr[rand()%(r-l+1)+l]);
 *         3. 针对大量重复的数组，换一种双路或者三路快排partition的写法，将相等的元素相对均衡的分布在两边的数组
 * 
 * 设计这个算法的思想也很重要，什么时候，怎么用，这个算法，这个问题比理解本身还要重要
 * 
*/