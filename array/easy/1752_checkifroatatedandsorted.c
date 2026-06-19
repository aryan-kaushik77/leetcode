
bool check(int* nums, int numsSize) {
    int decrease=0;
    int index=-1;
    for (int i=1;i<numsSize;i++){
        if (nums[i]<nums[i-1]){
            decrease++;
            index=i;
        }
    }
    printf("%d,%d",index,decrease);
    if (decrease>=2){
        return false;
    }
    if (decrease==0){
        return true;
    }
    if (index==numsSize-1 && decrease==1){
        if  (nums[0]>=nums[numsSize-1]){
            return true;
        }
        else{
            return false;
        }
    }
    if(decrease==1 && nums[index-1]>=nums[index+1]){
        if  (nums[0]>=nums[numsSize-1]){
            return true;
        }
    }
    return false;
}