#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int s, int e)
{

    // now its the right time to find the pivot element
    int pivot = arr[s];
    int count = 0; // count to store the no of values

    for (int i = s + 1; i <= e; i++) // this is the statement that if the value is less than the first value so increment the count to store the location
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = s + count; // this is used to calculate the index
    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // write the base case
    if (s < e)
    {

        int p = partition(arr, s, e); // this is used to take the value that is generated in the above funtion in the varialbe p

        // after this we are going to use the quick sort
        quickSort(arr, 0, p - 1);
        quickSort(arr, p + 1, e);
    }
}

int main()
{

    int arr[5] = {7, 3, 234567890, 3, 4};
    quickSort(arr, 0, 4); // passing to the function

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}
