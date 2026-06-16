int insertPosHelper(int* nums,int left,int right,int target){
    if(left>right){
        return left;
    }
    int mid=left+(right-left)/2;
    if (nums[mid]==target){
        return mid;
    }
    if (mid==right){
        if (target>nums[mid]) return mid+1;
        return mid;
    }
    if (target>nums[mid] && target<nums[mid+1]){
        return mid+1;
    }
    if (nums[mid]<target){
        return insertPosHelper(nums,mid+1,right,target);
    }
    return insertPosHelper(nums,left,mid-1,target);
}
int searchInsert(int* nums, int numsSize, int target) {
    return insertPosHelper(nums,0,numsSize-1,target);
}