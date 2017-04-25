int* constructRectangle(int area, int* returnSize) {
    // 因為長寬要盡量相近，所以從開根號開始找最快。
    int length = sqrt(area);
    
    // 長度不能整除面積就遞減，一個一個尋找。
    while((area % length) != 0){
        length--;
    }
    
    // 儲存長寬。
    int* bounds = (int*)calloc(2, sizeof(int));
    bounds[0] = area / length;
    bounds[1] = length;
    
    // 大小固定是 2，回傳結果。
    *returnSize = 2;
    return bounds;
}