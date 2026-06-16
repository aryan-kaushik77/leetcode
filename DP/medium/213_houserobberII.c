int robber(int* nums,int left,int right) {
    int A[right-left+1];
    A[0]=0;
    A[1]=nums[left];
    for (int i=2;i<right-left+1;i++){
        if (A[i-1]<A[i-2]+nums[left+i-1]){
            A[i]=A[i-2]+nums[left+i-1];
        }
        else{
            A[i]=A[i-1];
        }
    }
    return A[right-left];
}
int rob(int* nums, int numsSize) {
    if (numsSize==1){
        return nums[0];
    }
    
    int p=robber(nums,0,numsSize-1);
    int q=robber(nums,1,numsSize);
    if (p>q){
        return p;
    }
    return q;
    
}