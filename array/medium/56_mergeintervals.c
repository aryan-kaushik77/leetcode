/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void merge1(int** intervals, int left, int mid, int right) {
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
        if(L[i][0]==R[j][0]){
            if(L[i][1]>=R[j][1]){
                intervals[k++] = L[i++];
            }
            else{
                intervals[k++] = R[j++];
            }
        }
        else if (L[i][0] < R[j][0])   // compare END time
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

    merge1(intervals, left, mid, right);
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    mergeSort(intervals,0,intervalsSize-1);
    int overlap=0;
    int end_time=intervals[0][1];
    for (int i=0;i<intervalsSize-1;i++){
        if(end_time>=intervals[i+1][0]){
            overlap++;
            if(end_time<intervals[i+1][1]){
                end_time=intervals[i+1][1];
            }
        }
        else{
            end_time=intervals[i+1][1];
        }
    }
    *returnSize = intervalsSize-overlap;
    *returnColumnSizes = (int*)malloc((intervalsSize-overlap) * sizeof(int));
    ////// we create a array which contain no. of rowsin each
    int **arr = (int**)malloc((intervalsSize-overlap) * sizeof(int*));
    for (int i = 0; i < intervalsSize-overlap; i++) {
        (*returnColumnSizes)[i] = 2;
    //////    this is how we initalize the rows in 2d array
        arr[i] = (int*)malloc((2) * sizeof(int));
    }
    arr[0]=intervals[0];
    int j=0;
    for(int i=1;i<intervalsSize;i++){
        if(arr[j][1]>=intervals[i][0]){
            if(arr[j][1]<intervals[i][1]){
                arr[j][1]=intervals[i][1];
            }  
        }
        else{
            j++;
            arr[j]=intervals[i];
        }
    }
    return arr;

    
}