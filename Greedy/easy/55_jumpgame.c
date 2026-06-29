bool canJump(int* nums, int numsSize) {
    int arr[numsSize];
    arr[0]=1;
    for (int i=1;i<numsSize;i++){
        arr[i]=0;
    }
    for (int i=0;i<numsSize;i++){
        if (arr[i]==1){
            for(int j=i+1;j<i+nums[i]+1&&j<numsSize;j++){
                if (arr[j]==0){
                    arr[j]=1;
                }
            }
        }
    }
    return (arr[numsSize-1]==1);
}

// bool canJump(int* nums, int numsSize) {
//     int maxReach = 0;

//     for (int i = 0; i < numsSize; i++) {
//         if (i > maxReach)
//             return false;
// BETTER SOLUTION
//         if (i + nums[i] > maxReach)
//             maxReach = i + nums[i];
//     }

//     return true;
// }