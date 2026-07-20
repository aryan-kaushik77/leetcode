int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int *A[triangleSize];
    for (int i=0;i<triangleSize;i++){
        A[i]=malloc(triangleColSize[i] * sizeof(int));
    }
    A[0][0]=triangle[0][0];
    
    for(int i=1;i<triangleSize;i++ ){
        A[i][0]=A[i-1][0]+triangle[i][0];
        A[i][triangleColSize[i]-1]=A[i-1][triangleColSize[i-1]-1]+triangle[i][triangleColSize[i]-1];
    }
    for(int i=2;i<triangleSize;i++){
        for(int j=1;j<triangleColSize[i]-1;j++){
            if(A[i-1][j-1]<A[i-1][j]){
                A[i][j]=A[i-1][j-1]+triangle[i][j];
            }
            else{
                A[i][j]=A[i-1][j]+triangle[i][j];
            }
        }
    }
    int min=A[triangleSize-1][0];
    for (int i=0;i<triangleColSize[triangleSize-1];i++){
        if (A[triangleSize-1][i]<min){
            min=A[triangleSize-1][i];
        }
    }

    return min;
}