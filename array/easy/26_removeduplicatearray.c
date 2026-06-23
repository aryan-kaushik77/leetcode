int removeDuplicates(int* nums, int numsSize) {
    int last=0;
    int k=1;
    for (int i=1;i<numsSize;i++){
        if (nums[i]!=nums[last]){
            nums[k]=nums[i];
            k++;
            last++;
        }
    }
    return k;
}