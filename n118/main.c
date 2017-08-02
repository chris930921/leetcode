// 118. Pascal's Triangle

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    *columnSizes = (int*)calloc(numRows, sizeof(int));
    int* columns = *columnSizes;
    
    if(numRows == 0){
        return NULL;
    }
    
    int** result = (int**)calloc(numRows, sizeof(int*));
    result[0] = (int*)calloc(1, sizeof(int));
    result[0][0] = 1;
    columns[0] = 1;
    
    for(int i = 1; i < numRows; i++){
        columns[i] = i + 1;
        result[i] = (int*)calloc(i + 1, sizeof(int));
        result[i][0] = 1;
        result[i][i] = 1;
        
        for(int j = 1; j < columns[i] - 1; j++){
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    
    return result;
}