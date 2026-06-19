void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    mergeSort(g,0,gSize-1);
    mergeSort(s,0,sSize-1);
    
    int count=0;
    int i=0;
    int j=0;
    if (sSize==0){
        return 0;
    }
    while (i<gSize && j<sSize){
        if(s[j]>=g[i]){
            count++;
            j++;
            i++;
        }
        else{
            j++;
        }
    }
    return count;
}