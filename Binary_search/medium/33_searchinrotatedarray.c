int unknown_index(int* nums, int left,int right){
    if(left==right){
        return left;
    }
    int mid=left+(right-left)/2;
    if (nums[mid] > nums[right]){
        return unknown_index(nums,mid+1,right);
    }
    return unknown_index(nums,left,mid);
}
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
    if (numsSize == 0)
        return -1;

    int pivot = unknown_index(nums, 0, numsSize - 1);
    int left_result = binary_search(nums, 0, pivot - 1, target);

    if (left_result != -1)
        return left_result;

    return binary_search(nums, pivot, numsSize - 1, target);
}