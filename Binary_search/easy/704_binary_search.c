int binary_search(int* arr, int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;

    if (target < arr[mid])
        return binary_search(arr, left, mid - 1, target);
    else
        return binary_search(arr, mid + 1, right, target);
}

int search(int* nums, int numsSize, int target) {
    return binary_search(nums, 0, numsSize - 1, target);
}