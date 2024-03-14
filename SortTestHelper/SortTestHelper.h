#pragma once
#include<iostream>
#include<ctime>
#include<cassert>
using namespace std;

namespace SortTestHelper {

	int* generateRandomArray(int n ,int rangeL,int rangeR) {

		assert(rangeL <= rangeR);
		int* arr = new int[n];
		srand(time(NULL));

		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}

	template<class T>
	void printArray(T array[],int n) {

		for (int i = 0; i < n; i++)
		{
			cout << array[i]<<" ";
		}
		cout << endl;
	}

	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	template<class T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(isSorted(arr,n));
		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	}



	int* copyIntArray(int a[],int n) {
		int* arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}
}