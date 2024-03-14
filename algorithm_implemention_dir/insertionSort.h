#pragma once

template <class T>
void insertionSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        T e = arr[i];
        for (; j > 0 && e < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}
/*
对于每一个unsorted的元素，都向前遍历
（只要满足 arr[j] > 当前元素，就把 arr[j-1]的值赋给arr[j]，移动排序的数组）
*/


template <class T>
void insertionSort(T arr[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j - 1] > e; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}