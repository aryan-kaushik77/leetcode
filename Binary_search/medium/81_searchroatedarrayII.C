int unknown_index(int* nums, int left,int right){
    if(left>=right){
        return left;
    }
    int mid=left+(right-left)/2;
    if(nums[left]==nums[mid] && nums[mid]==nums[right]){
        return unknown_index(nums, left + 1, right - 1);
    }
    if (nums[mid] > nums[right]){
        return unknown_index(nums,mid+1,right);
    }
    return unknown_index(nums,left,mid);
}
int binary_search(int* arr, int left, int right, int target) {
    if (left > right)
        return false;

    int mid = left + (right - left) / 2;
    
    // printf("%d\n",mid);
    if (arr[mid] == target)
        return true;
    if(arr[left]==arr[mid]&& arr[mid]==arr[right]){
        if (arr[mid]==target){
            return true;
        }
        return binary_search(arr,left+1,right-1,target);
    }

    if (target < arr[mid])
        return binary_search(arr, left, mid - 1, target);
    else
        return binary_search(arr, mid + 1, right, target);
}
bool search(int* nums, int numsSize, int target) {
    if (numsSize == 0)
        return false;
    

    int pivot = unknown_index(nums, 0, numsSize - 1);
    printf("%d",pivot);
    int left_result = binary_search(nums, 0, pivot - 1, target);
    // printf("%d")
    bool k;
    if (left_result == true)
        k=left_result;
    else{
        k=binary_search(nums, pivot, numsSize - 1, target);
    }
    return k;
}