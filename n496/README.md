## 496. Next Greater Element I
1. 宣告 int 陣列 returnNums。
1. returnSize 等於 findNumsSize。 
2. findNums 是 nums 的子集。
3. findNums 中不會有重複的數值。
4. nums 中不會有重複的數值。
5. 從 findNums 取出一數值 x 後，先找到其數值在 nums 中的位置 y。
6. 從 nums 位置 y 的右邊開始尋找第一個比 x 大的數值 z。
7. 將數值 z 放入 returnNums 中。