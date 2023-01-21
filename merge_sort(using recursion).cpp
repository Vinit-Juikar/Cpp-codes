// so from here i am going to wrtie the merge sort from scratch

#include <iostream>
using namespace std;

void solve(int arr[], int left[], int right[], int leftCount, int rightCount)
{
    // this is the function that is used to solve the sorting problem where we take leftCount and rightCount as the main inputs

    // first initialize the main inputs

    int i = 0, j = 0, k = 0;

    // take the main while loop
    while (i < leftCount && j < rightCount)
    {
        if (left[i] < right[j]) // that means if the left input is less than the right one then take that in the main array
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }

        // now we have to plan for the things that are not considered or left out
        while (i < leftCount)
        {
            arr[k++] = left[i++];
        }
        while (j < rightCount)
        {
            arr[k++] = right[i++];
        }
    }
}

void mergeSort(int arr[], int size)
{
    // this program will do the work of breaking the main array the base case is if the size is one that is only when one of the element is left

    if (size < 2)
    {
        return;
    }

    // here comes the real code of breking the array .. first thing to do is as we have to break the array into two parts we have to find the mid
    int s = arr[0];
    int e = arr[size];
    int mid = (s + e) / 2;

    // now we have to define two pointers to break the array
    int *left = new int[mid]; // the purpose of writing mid is that instead of storing the value as normal stact cpp stores it as heap so we can store some bigger values

    int *right = new int[size - mid]; // here we copy the full right array

    // now we have to pass the mid value to our main funtion that will do the work of sorting
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    // similarly do this for the right part
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    // let's make it a recursive funtion
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // let's pass these arrays for the merging and sorting work
    solve(arr, left, right, mid, size - mid);
}

int main()
{

    // first take the input
    int size;
    cout << "enter the size of the array" << endl;
    cin >> size;

    // take the array input
    int arr[size];
    cout << "enter the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // here we init the start and the end values

    mergeSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
