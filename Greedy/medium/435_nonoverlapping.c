void merge(int** intervals, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int** L = malloc(n1 * sizeof(int*));
    int** R = malloc(n2 * sizeof(int*));

    for (int i = 0; i < n1; i++)
        L[i] = intervals[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = intervals[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i][1] <= R[j][1])   // compare END time
            intervals[k++] = L[i++];
        else
            intervals[k++] = R[j++];
    }

    while (i < n1)
        intervals[k++] = L[i++];

    while (j < n2)
        intervals[k++] = R[j++];

    free(L);
    free(R);
}
void mergeSort(int** intervals, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(intervals, left, mid);
    mergeSort(intervals, mid + 1, right);

    merge(intervals, left, mid, right);
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {

    mergeSort(intervals, 0, intervalsSize - 1);

    for (int i = 0; i < intervalsSize; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", intervals[i][j]);
        }
        printf("\n");
    }
    int count=0;
    int j=0;
    for (int i=1;i<intervalsSize;i++){
        if(intervals[i][0]<intervals[j][1]){
            count++;
            // j++;
        }
        else{
            j=i;
        }
        printf("%d+%d-%d\n",i,j,count);

    }

    return count;
}
