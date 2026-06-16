/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int lower(int* nums,int left,int right,int target){
    if(left>=right){
        return left;
    }
    int mid=left+(right-left)/2;
    if (nums[mid]<target){
        return lower(nums,mid+1,right,target);
    }
    return lower(nums,left,mid,target);
}
int upper(int* nums,int left,int right,int target){
    if(left>=right){
        return left;
    }
    int mid=left+(right-left)/2;
    if (nums[mid]<=target){
        return upper(nums,mid+1,right,target);
    }
    return upper(nums,left,mid,target);
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {   
    *returnSize = 2;
    int *arr = (int *)malloc(2 * sizeof(int));
    int k =lower(nums,0,numsSize,target);
    int pred=k-1;
    int q=upper(nums,0,numsSize,target);
    printf("%d,%d",k,q);
    if (numsSize==0){
        arr[0]=-1;
        arr[1]=-1;
        return arr;
    }
    if(k==numsSize){
        arr[0]=-1;
        arr[1]=-1;
        return arr;
    }
    if (nums[k]!=target){
        arr[0]=-1;
        arr[1]=-1;
        return arr;
    }
    
    arr[0]=pred+1;
    arr[1]=q-1;
    // if (nums[k+1]!=target){
    //     arr[0]=-1;
    //     arr[1]=-1;
    //     return arr;
    // }
    return arr;
}