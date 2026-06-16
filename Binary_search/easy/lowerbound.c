// we can do it using left and right only left>=right when we dont need to exceed the bound
int lowerBound(int arr[], int lo, int hi, int target) {
    if (lo >= hi) return lo;
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] < target)
        return lowerBound(arr, mid + 1, hi, target);
    else
        return lowerBound(arr, lo, mid, target);
}
// call is lower(arr,0,n,target)