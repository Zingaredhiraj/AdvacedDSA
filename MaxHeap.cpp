#include <iostream>
#include <algorithm>   // for swap()
using namespace std;

class Heap
{
public:
    int arr[100];   // increased size

    void getArray(int n);
    void printArray(int arr[], int n);
    void maxHeapify(int arr[], int n, int i);
    void minHeapify(int arr[], int n, int i);
    void maxHeapSort(int arr[], int n);
    void minHeapSort(int arr[], int n);
};

// Input function
void Heap::getArray(int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

// Display function
void Heap::printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Max Heapify (for ascending sort)
void Heap::maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Min Heapify (for descending sort)
void Heap::minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Max Heap Sort (Ascending Order)
void Heap::maxHeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// Min Heap Sort (Descending Order)
void Heap::minHeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

// MAIN FUNCTION (VERY IMPORTANT)
int main()
{
    Heap h;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    h.getArray(n);

    int arr1[100], arr2[100];

    // Copy original array
    for (int i = 0; i < n; i++)
    {
        arr1[i] = h.arr[i];
        arr2[i] = h.arr[i];
    }

    cout << "\nOriginal Array:\n";
    h.printArray(h.arr, n);

    // Ascending
    h.maxHeapSort(arr1, n);
    cout << "\nAscending Order:\n";
    h.printArray(arr1, n);

    // Descending
    h.minHeapSort(arr2, n);
    cout << "\nDescending Order:\n";
    h.printArray(arr2, n);

    return 0;
} 
