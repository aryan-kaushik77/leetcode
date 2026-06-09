int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int current = nums[0];
    int best = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        int take = current + nums[i];
        if (nums[i] > take) {
            current = nums[i];
        } else {
            current = take;
        }
        if (current > best) best = current;
    }

    return best;
}

// even though it decreases at a point we can store it to compare it from best
// after adding onto it 


// againnnn