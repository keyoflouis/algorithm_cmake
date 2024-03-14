#pragma once
#include<iostream>

template<class T>
void selectionSort(T arr[],int n){
    for (int i = 0; i < n ; i++)
    {
        int minIndex = i;
        for (int j = i; j < n ; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        std::swap(arr[minIndex], arr[i]);
    }
    return;
}