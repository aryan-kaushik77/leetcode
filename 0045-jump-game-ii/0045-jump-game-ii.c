int jump(int* nums, int numsSize) {
    int arr[numsSize];
    arr[0]=0;
    for (int i=1;i<numsSize;i++){
        arr[i]=numsSize+1;
    }
    for (int i=0;i<numsSize;i++){
        if (arr[i]>=0){
            for(int j=i+1;j<i+nums[i]+1&&j<numsSize;j++){
                arr[j]=fmin(arr[j],arr[i]+1);
            }
        }
    }
    return arr[numsSize-1];
}