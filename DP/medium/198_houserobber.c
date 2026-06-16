int rob(int* nums, int numsSize) {
    int A[numsSize+1];
    A[0]=0;
    A[1]=nums[0];
    for (int i=2;i<numsSize+1;i++){
        if (A[i-1]<A[i-2]+nums[i-1]){
            A[i]=A[i-2]+nums[i-1];
        }
        else{
            A[i]=A[i-1];
        }
    }
    return A[numsSize];
}