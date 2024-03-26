
#include "SortTestHelper.h"

#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "shellSort.h"
#include "quickSort.h"

int main()
{
	int n = 10000;

	int *a = SortTestHelper::generateRandomArray(n, 0, n);
	int *b = SortTestHelper::copyIntArray(a, n);
	int *c = SortTestHelper::copyIntArray(a, n);
	int *d = SortTestHelper::copyIntArray(a, n);

	SortTestHelper::testSort("selectionSort", selectionSort, a, n);
	SortTestHelper::testSort("insertionSort", insertionSort, b, n);
	SortTestHelper::testSort("mergeSort", mergeSort, c, n);

	//SortTestHelper::printArray(d, n);
	SortTestHelper::testSort("quickSort", quickSort, d, n);
	//	SortTestHelper::testSort("shellSort", shellSort, d, n);
	//SortTestHelper::printArray(d, n);

	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
	return 0;
}