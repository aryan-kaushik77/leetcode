int binary_search(int* arr, int left, int right) {
    if (left == right) {
        return left;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] < arr[mid + 1]) {
        return binary_search(arr, mid + 1, right);
    }

    return binary_search(arr, left, mid);
}

int findPeakElement(int* nums, int numsSize) {
    return binary_search(nums, 0, numsSize - 1);
}

// binary search to find the peak element in the mountain array
// recursion works by keeping the half that must contain the peak