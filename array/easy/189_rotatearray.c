void rotate(int* nums, int numsSize, int k) {
    k=k%numsSize;
    int nums1[numsSize];
    int j=0;
    for (int i=numsSize-k;i<(2*numsSize-k);i++){
        int z=i%numsSize;
        nums1[j]=nums[z];
        j++;
    }
    for (int i=0;i<numsSize;i++){
        nums[i]=nums1[i];
    }
}