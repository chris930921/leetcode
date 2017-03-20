# n412 Fizz Buzz
輸出 n 長度的陣列，第 n 個位置的字串數值為 n + 1，3 的倍數字串替換成 "Fizz"，5的倍數字串替換成 "Buzz"，15
 的倍數字串替換成 "FizzBuzz"。

# n461 Hamming Distance
兩個輸入數值的 binary 有幾個不同的 bit。 

# n463 Island Perimeter
給一個二維陣列，裡面的數值只有 0 或 1，求出 1 面積的邊框數量。

如果 1 的上下左右格子其中一個也是 1，表示該方向無邊框。

# n476 Number Complement
將數值每個 bit 作 not，要注意比最左邊的 1 更高位元的 0 不做 not，且測資中沒有負數。

# n485 Max Consecutive Ones
找出陣列中最長的連續的 1，求其包含 1 的數量。

# n496 Next Greater Element I
1. 宣告 int 陣列 returnNums。
1. returnSize 等於 findNumsSize。 
2. findNums 是 nums 的子集。
3. findNums 中不會有重複的數值。
4. nums 中不會有重複的數值。
5. 從 findNums 取出一數值 x 後，先找到其數值在 nums 中的位置 y。
6. 從 nums 位置 y 的右邊開始尋找第一個比 x 大的數值 z。
7. 將數值 z 放入 returnNums 中。

# n500 Keyboard Row
檢查每個字串裡的字母，是否在鍵盤上的同一列，測資有些有大寫，有些沒有。