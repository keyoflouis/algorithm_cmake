
#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "SortTestHelper.h"
#include "shellSort.h"

int main()
{
	int n = 10;

	int *a = SortTestHelper::generateRandomArray(n, 0, n);
	int *b = SortTestHelper::copyIntArray(a, n);
	int *c = SortTestHelper::copyIntArray(a, n);
	int *d = SortTestHelper::copyIntArray(a, n);

	SortTestHelper::testSort("selectionSort", selectionSort, a, n);
	SortTestHelper::testSort("insertionSort", insertionSort, b, n);
	SortTestHelper::printArray(c, n);
	
	SortTestHelper::testSort("mergeSort", mergeSort, c, n);
//	SortTestHelper::testSort("shellSort", shellSort, d, n);
	SortTestHelper::printArray(c, n);
	;

	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
	return 0;
}