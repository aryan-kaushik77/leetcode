int minPathSum(int** grid, int gridSize, int* gridColSize) {
    if(gridSize==0){
        return 0;
    }
    int A[gridSize][gridColSize[0]];
    A[0][0]=grid[0][0];
    for (int i=1;i<gridSize;i++){
        A[i][0]=A[i-1][0]+grid[i][0];
    }
    for (int i=1;i<gridColSize[0];i++){
        A[0][i]=A[0][i-1]+grid[0][i];
    }
    for(int i=1;i<gridSize;i++){
        for(int j=1;j<gridColSize[i];j++){
            if(A[i-1][j]<A[i][j-1]){
                A[i][j]=A[i-1][j]+grid[i][j];
            }
            else{
                A[i][j]=A[i][j-1]+grid[i][j];
            }
        }
    }
    return A[gridSize-1][gridColSize[gridSize-1]-1];

    }