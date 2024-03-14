#pragma once

template <class T>
void shellSort(T arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // Add arr[i] to the elements that have been gap sorted
            // Save arr[i] in temp and make a hole at position i
            T temp = arr[i];

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}