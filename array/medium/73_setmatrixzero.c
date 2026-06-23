void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize == NULL) return;
    int cols = matrixColSize[0];
    if (cols == 0) return;

    int firstRowZero = 0;
    int firstColZero = 0;

    for (int j = 0; j < cols; j++) if (matrix[0][j] == 0) { firstRowZero = 1; break; }
    for (int i = 0; i < matrixSize; i++) if (matrix[i][0] == 0) { firstColZero = 1; break; }

    for (int i = 1; i < matrixSize; i++){
        for (int j = 1; j < cols; j++){
            if (matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrixSize; i++){
        if (matrix[i][0] == 0){
            for (int j = 1; j < cols; j++) matrix[i][j] = 0;
        }
    }

    for (int j = 1; j < cols; j++){
        if (matrix[0][j] == 0){
            for (int i = 1; i < matrixSize; i++) matrix[i][j] = 0;
        }
    }

    if (firstRowZero){
        for (int j = 0; j < cols; j++) matrix[0][j] = 0;
    }

    if (firstColZero){
        for (int i = 0; i < matrixSize; i++) matrix[i][0] = 0;
    }
}
