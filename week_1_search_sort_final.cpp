#include <stdio.h>

// Function for search algorithms
int linearSearch(int arr[], int n, int target);
int binarySearch(int arr[], int low, int high, int target);

// Function for sort algorithms
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

//This function will print the array
void printArray(int arr[], int n);

int main() 
{
    int searchArr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int searchSize = sizeof(searchArr) / sizeof(searchArr[0]);
    int searchData = 11;

    int sortArr[] = {64, 34, 25, 12, 22, 11, 90};
    int sortSize = sizeof(sortArr) / sizeof(sortArr[0]);

    printf("Data for search: ");
    printArray(searchArr, searchSize);

    printf("\nData for sorting: ");
    printArray(sortArr, sortSize);

    // Linear search
    int linearResult = linearSearch(searchArr, searchSize, searchData);
    if (linearResult == -1)
        printf("\nLinear Search: Element not found!\n");
    else
        printf("\nLinear Search: Element found at index %d\n", linearResult);

    // Binary search
    bubbleSort(searchArr, searchSize);
    int binaryResult = binarySearch(searchArr, 0, searchSize - 1, searchData);
    if (binaryResult == -1)
        printf("\nBinary Search: Element not found!\n");
    else
        printf("\nBinary Search: Element found at index %d\n", binaryResult);

    // Bubble sort
    bubbleSort(sortArr, sortSize);
    printf("\nBubble Sort: ");
    printArray(sortArr, sortSize);

    // Selection sort
    selectionSort(sortArr, sortSize);
    printf("\nSelection Sort: ");
    printArray(sortArr, sortSize);

    // Insertion sort
    insertionSort(sortArr, sortSize);
    printf("\nInsertion Sort: ");
    printArray(sortArr, sortSize);

    return 0;
}

// Linear search 
// Time complexity comes out to be O(n) since in worst case the function iterates through the entire 
//  array to find the required element 
int linearSearch(int arr[], int n, int target) 
{
    for (int i = 0; i < n; i++) 
	{
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Binary search
// Time complexity comes out to be O(log n) since the search area is halved at every step.
int binarySearch(int arr[], int low, int high, int target) 
{
    if (low <= high) 
	{
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            return binarySearch(arr, mid + 1, high, target);
        else
            return binarySearch(arr, low, mid - 1, target);
    }
    return -1;
}

// Bubble sort 
// Time complexity comes out to be O(n^2) since there are nested loops
void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection sort 
// Time complexity comes out to be O(n^2) since in avg case we need to find the smallest element 
// repeatedly and in worst case we need to make n-1 comparisons 
void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
		{
            if (arr[j] < arr[minIndex]) 
			{
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Insertion sort
// Time complexity comes out to be O(n^2) since in worst case we need to make n-1 comparisons 
// when the array is sorted in reverse order 
void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
	{
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//Prints the array
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
}
