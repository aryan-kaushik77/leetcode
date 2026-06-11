int binary_search(int* arr, int left, int right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
        return mid;
    }

    if (arr[mid] < arr[mid + 1]) {
        return binary_search(arr, mid + 1, right);
    } else {
        return binary_search(arr, left, mid - 1);
    }
}

int peakIndexInMountainArray(int* arr, int arrSize) {
    return binary_search(arr, 0, arrSize - 1);
}

// binary search to find the peak element in the mountain array
// binary search is used when we have to find element based on comparing condition in somehow sorted array