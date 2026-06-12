#include <stdbool.h>

int binary_search(int** arr, int left, int right, int target) {
    
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (mid == right || (target < arr[mid+1][0]&&target> arr[mid][0]) || target==arr[mid][0])
        return mid;

    if (target < arr[mid][0])
        return binary_search(arr, left, mid - 1, target);
    else
        return binary_search(arr, mid + 1, right, target);    
}
int binary_search2(int** arr, int left, int right, int target,int m) {
    if (left > right)
        return false;

    int mid = left + (right - left) / 2;

    if (arr[m][mid] == target)
        return true;

    if (target < arr[m][mid])
        return binary_search2(arr, left, mid - 1, target, m);
    else
        return binary_search2(arr, mid + 1, right, target, m);
}


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m=0;
    m=binary_search(matrix,0,matrixSize-1,target);
    if (m == -1)
        return false;
    printf("%d",m);
    return binary_search2(matrix,0,matrixColSize[m]-1,target,m);
    // return 0;
}
// same as binary search but helps us understand how to manage 
// the heap overflow when we have condition like m+1 m-1



// so see mid==right and mid==left condition is to check we dont go out of bounds and return that element
// like in matrix we went to right most to return it while in negative we went left most
// left>right is the case when the condition goes oppostite to it like in matrix more left most or in negative the right most