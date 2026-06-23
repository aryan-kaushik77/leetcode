/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int *arr=(int *)malloc(2 * (sizeof(int)));
    for(int i=0;i<numsSize;i++){
        for (int j=0;j<numsSize;j++){
            if(i==j){
                continue;
            }
            if (target==nums[i]+nums[j]){
                arr[0]=i;
                arr[1]=j;
            }
        }
    }
    return arr;
}