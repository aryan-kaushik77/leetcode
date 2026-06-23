/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    int *arr=(int *)malloc(numsSize * (sizeof(int)));
    int half=numsSize/2;
    int negative[half];
    int positive[half];
    int k=0;
    int j=0;
    for (int i=0;i<numsSize;i++){
        if(nums[i]<0){
            negative[k]=nums[i];
            k++;
        }
        else{
            positive[j]=nums[i];
            j++;
        }
    }
    int p=0;
    int q=0;

    for (int i=0;i<numsSize;i++){
        if(i%2==0){
            arr[i]=positive[p];
            p++;
        }
        else{
            arr[i]=negative[q];
            q++;
        }
    }
    return arr;
}