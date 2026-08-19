int insertPosHelper(int* nums,int left,int right,int target){
    if(left>=right){
        return left;
    }
    int mid=left+(right-left)/2;
    // if (nums[mid]==target){
    //     return mid;
    // }
    if (nums[mid]<target){
        return insertPosHelper(nums,mid+1,right,target);
    }
    return insertPosHelper(nums,left,mid,target);
}
int searchInsert(int* nums, int numsSize, int target) {
    return insertPosHelper(nums,0,numsSize,target);
}