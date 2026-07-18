// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify subtree rooted at index i
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check right child
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If root is not the largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Heapify the affected subtree
        maxHeapify(arr, n, largest);
    }
}

// Convert Min Heap to Max Heap
void convertMaxHeap(int arr[], int n)
{
    // Start from the last non-leaf node
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}