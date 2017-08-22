// 599. Minimum Index Sum of Two Lists

char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    // 建立回傳的字串空間，因為是從現有字串找相同的，所以不可能比現有字串數量多。
    // 利用最大的字串數量來建立空間。
    int resultListSize = (list1Size > list2Size)? list1Size : list2Size;
    char** resultList = (char**)calloc(resultListSize, sizeof(char*));
    
    // 儲存最小的索引值，初始值設定為最大值。
    int minIndex = list1Size + list2Size;
    int i = 0;

    // 走訪第一個字串組的所有字串。
    for(i = 0; i < list1Size; i++){
        char* firstString = list1[i];
        
        int j = 0; 
        // 走訪第二個字串組的所有字串。
        for(j = 0; j < list2Size; j++){
            char* secondString = list2[j];
            
            int x = -1;
            // 開始一個一個字比較。
            while(true){
                x++;
                
                // 只要不相同就不需要繼續比較。
                if(firstString[x] != secondString[x]){
                    break;
                }

                // 如果一直相同到最後，並且都到達字串的結束字元時。
                if(firstString[x] == 0){
                    if(secondString[x] == 0){
                        // 如果索引值相加和曾紀錄的最小索引值相同，新增回傳結果中。
                        if(i+j == minIndex){
                            resultList[*returnSize] = firstString;
                            (*returnSize)++;
                        // 如果索引值相家小於曾記錄的最小索引值，清空回傳結果重新記錄。
                        }else if(i+j < minIndex){
                            (*returnSize) = 0;
                            resultList[*returnSize] = firstString;
                            minIndex = (i+j);
                            (*returnSize)++;
                        }
                        break;
                    }
                }
            }
        }
    }
    return resultList;
}