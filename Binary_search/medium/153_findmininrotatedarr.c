int findmin(int* nums,int left,int right){
    if (left==right){
        return left;
    }
    int mid=left+(right- left)/2;
    if (nums[mid]>nums[right]){
        return findmin(nums,mid+1,right);

    }else {
        return findmin(nums,left,mid);
    }
}
int findMin(int* nums, int numsSize) {
    int k=findmin(nums,0,numsSize-1);
    printf("%d",k);
    return nums[k];
}