int binary_search(int* arr,int left,int right){
    if (left>right){
        return left;
    }
    int mid=left+(right-left)/2;
    if (arr[mid] < 0) {
        if (mid == left || arr[mid - 1] >= 0)
            return mid;
        return binary_search(arr, left, mid - 1);
    }
    else
        return binary_search(arr, mid + 1, right);
    

}
int countNegatives(int** grid, int gridSize, int* gridColSize) {
    // int m=binary_search(grid[0],0,gridColSize[0]-1);
    // printf("%d",m);
    // return 0;
    int m=0;
    int count=0;
    // int r=binary_search(grid[3],0,gridColSize[3]-1);
    // printf("%d",r);
    
    for (int i=0;i<gridSize;i++){
        int r=0;
        
        r=binary_search(grid[i],0,gridColSize[i]-1);
        // if (r==gridColSize[i]){
        //     r=0;
        // }
        // printf("%d",r);
        // printf("\n");
        count=count+(gridColSize[i]-r);
    }
    return count;
}

// main is how we handled the out of bounds access when we have condition like m-1 m+1 in binary search
// we check if mid is the leftmost element or rightmost element and then we check the condition for that element and return the index accordingly