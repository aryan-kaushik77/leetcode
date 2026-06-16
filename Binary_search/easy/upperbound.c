int upperBound(int arr[], int lo, int hi, int target) {
    if (lo >= hi) return lo;
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] <= target)
        return upperBound(arr, mid + 1, hi, target);
    else
        return upperBound(arr, lo, mid, target);
}
// call is upper(arr,0,n,target)