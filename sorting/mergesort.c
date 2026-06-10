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
// void merge(int** intervals, int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     int** L = malloc(n1 * sizeof(int*));
//     int** R = malloc(n2 * sizeof(int*));

//     for (int i = 0; i < n1; i++)
//         L[i] = intervals[left + i];                                  for 2d

//     for (int i = 0; i < n2; i++)
//         R[i] = intervals[mid + 1 + i];

//     int i = 0, j = 0, k = left;

//     while (i < n1 && j < n2) {
//         if (L[i][1] <= R[j][1])   // compare END time
//             intervals[k++] = L[i++];
//         else
//             intervals[k++] = R[j++];
//     }

//     while (i < n1)
//         intervals[k++] = L[i++];

//     while (j < n2)
//         intervals[k++] = R[j++];

//     free(L);
//     free(R);
// }
void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}