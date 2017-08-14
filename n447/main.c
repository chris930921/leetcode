// 447. Number of Boomerangs

int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize) {
    int dynamicTableSize = pointsRowSize * pointsRowSize;
    int* dynamicTable = (int*)calloc(dynamicTableSize, sizeof(int));
    
    int baseIndex = 0;
    int index = 0;
    int reverseIndex = 0;
    int distance1 = 0;
    int distance2 = 0;
    int delta = 0;
    int compareSum = 0;
    
    int result = 0;
    int i = 0;
    int y = 0;
    int j = 0;
    int x = 0;

    // 動態規劃表，假如現在已經計算 point 1 和 point 2 的距離。
    // 將其儲存起來，以後遇到 (point 1, point 2) 或 (point 2, point 1) 時，
    // 不再重新計算。
    for(int i = 0; i < dynamicTableSize; i++){
        // 初始化為 -1，表示尚未計算過。
        dynamicTable[i] = -1;
    }
    
    // 這裡利用三個 for 迴圈排列 (i,j,k) 不重複的組合。
    // 例如 [point 0, point 1, point 2]。
    // 則排列 
    // [point 0, point 1, point 2]
    // [point 0, point 2, point 1]
    // [point 1, point 0, point 2]
    // [point 1, point 2, point 0]
    // [point 2, point 0, point 1]
    // [point 2, point 1, point 0]
    for(i = 0; i < pointsRowSize; i++){    

        compareSum = 0;
        for(j = 0; j < pointsRowSize; j++){
            // 因為要不重複，有相同的就跳過。
            if(i == j){
                continue;
            }
            
            // 用 i 和 j 當作索引值，從動態規劃表取得 point 0 和 poing 1 的距離。
            baseIndex = i * pointsRowSize;
            index = baseIndex + j;
            reverseIndex = j * pointsRowSize + i;
            distance1 = dynamicTable[index];
            // 取得 -1 代表沒計算過，計算距離並且儲存到動態規劃表。
            if(distance1 == -1){
                for(y = 0; y < pointsColSize; y++){
                    delta = points[i][y] - points[j][y];
                    distance1 += delta * delta;
                }
                dynamicTable[index] = distance1;
                // 因為無論 (point 0, point 1) 或 (point 1, point 0) 距離都一樣，
                // 所以將索引前後調換，一起儲存起來。
                dynamicTable[reverseIndex] = distance1;
            }
            
            // 在 j = 0 時，已經和所有後面的 point 比對過一次了。
            // 所以 x 從 j 開始往後比對就可以。
            for(x = j + 1; x < pointsRowSize; x++){
                // 因為要不重複，有相同的就跳過。
                if(j == x){
                    continue;
                }
                
                // 因為要不重複，有相同的就跳過。
                if(i == x){
                    continue;
                }
                
                // 用 i 和 x 當作索引值，從動態規劃表取得 point 0 和 poing 2 的距離。
                index = baseIndex + x;
                reverseIndex = x * pointsRowSize + i;
                distance2 = dynamicTable[index];
                // 取得 -1 代表沒計算過，計算距離並且儲存到動態規劃表。
                if(distance2 == -1){
                    for(y = 0; y < pointsColSize; y++){
                        delta = points[i][y] - points[x][y];
                        distance2 += delta * delta;
                    }
                    dynamicTable[index] = distance2;
                    // 因為無論 (point 0, point 1) 或 (point 1, point 0) 距離都一樣，
                    // 所以將索引前後調換，一起儲存起來。
                    dynamicTable[reverseIndex] = distance2;
                }
                
                // 如果兩個距離相同，並且 x 從 j + 1 開始，
                // 所以重複的組合不會再計算一次，將結果增加 2。
                if(distance1 == distance2){
                    result += 2;
                }
            }
        }
    }
    
    return result;
}