bool isarrminheap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Check if the left child is greater than the parent
        if (arr[2 * i + 1] < arr[i]) {
            return false;
        }
        // Check if the right child exists and is greater than the parent
        if (2 * i + 2 < n && arr[2 * i + 2] < arr[i]) {
            return false;
        }
    }
    return true;
}