## 13. Roman to Integer

將羅馬數字的字串轉為數值。

例如 VI = 6、VIII = 8、XII = 12。

## 100. Same Tree

檢查輸入的兩個 binary tree，結構和數值都是否都相同。

## 122. Best Time to Buy and Sell Stock II

輸入 int  陣列代表一連串的股票價格，並且依照時間排序。

在價格 x 時買入，並在價格 y 時賣出，利潤即為 y - x。

買入股票後就不能再做買入的動作，直到賣出。

目標是找出最大的利潤。

例如 [20, 30, 40, 10]，買入 20 賣出 40 ，利潤為 20。

例如 [30, 40, 10, 20]，買入 30 賣出 40、買入 10 賣出 20 ，利潤為 20。

例如 [40, 30 20, 10]，價格只降不升，沒有買入沒有賣出，利潤為 0。

## 167. Two Sum II - Input array is sorted

給一數值 target，從陣列中找出任兩個數值相加等於 target，

並且回傳數值在陣列中的索引值，回傳陣列大小固定都是 2。

## 169. Majority Element

輸入 int 陣列，輸出哪個數字的出現次數大於 majority。

假設陣列大小是 numsSize，majority 等於 numsSize 除以 2。

輸入未經過排序，而且正負數都會出現。

## 206. Reverse Linked List

輸入 Link List 並將其反轉後輸出。

例如輸入 [10, 20, 30, 40]，則反轉後輸出 [40, 30, 20, 10]。

## 217. Contains Duplicate

輸入 int 陣列，找出是否有重複的數值。

## 242. Valid Anagram

輸入字串 s 和字串 t，判斷兩者中的字母、出現次數是否都相同 (Anagram)。

## 268. Missing Number

找出哪一個數字沒有出現在輸入中。

假設輸入為 [1, 0, 3]，則數字 2 沒有出現過，所以回傳 2。

假設輸入為 [0, 1, 2]，則數字 3 沒有出現過，所以回傳 3。

假設輸入為 [1, 2, 3]，則數字 0 沒有出現過，所以回傳 0。

## 349. Intersection of Two Arrays

輸入兩組 int 陣列，找出兩個陣列相同的部分。

例如輸入 [1, 2, 2, 1]、[2, 2]，同樣都有 2  所以輸出 [2]。

例如輸入 [1, 2, 2, 1]、[1, 2, 2, 1]，同樣都有 1、2 所以輸出 [1, 2]。

例如輸入 [1, 2, 3, 2, 1, 4]、[1, 2, ,2 ,3 ,3]，同樣都有 1、2、3 所以輸出 [1, 2, 3]。

## 350. Intersection of Two Arrays II

輸入兩組 int 陣列，找出兩個陣列相同的部分，而且須將重複的組合印出。

例如輸入 [1, 2, 2, 1]、[2, 2]，同樣都有 2 而且出現兩次，所以輸出 [2, 2]。

例如輸入 [1, 2, 2, 1]、[1, 2, 2, 1]，同樣都有 1、2 而且出現兩次，所以輸出 [1, 2]。

例如輸入 [1, 2, 3, 2, 1, 4]、[1, 2, ,2 ,3 ,3]，同樣都有 1、2、3 而且 2 出現兩次， 所以輸出 [1, 2, 3]。

例如輸入 [-2147483648, 1, 2, 3]、[1, -2147483648, -2147483648]，同樣都有 -2147483648,、1，所以輸出 [-2147483648, 1]。

## 387. First Unique Character in a String

在字串中找出第一個不重複的字元。

## 401. Binary Watch

假設有一隻手錶用 binary 的方式顯示時間。

上面全部的 LED 燈共有 10 顆。

小時部分顯示 0 ~ 11，總共 4 顆燈。

分鐘部分顯示 0 ~ 59，總共 6 顆燈。

輸入只告訴你全部亮個幾個燈，輸出所有可能的時間。

## 412. Fizz Buzz

輸出 n 長度的陣列，第 n 個位置的字串數值為 n + 1，

3 的倍數字串替換成 "Fizz"，

5的倍數字串替換成 "Buzz"，

15 的倍數字串替換成 "FizzBuzz"。

## 448. Find All Numbers Disappeared in an Array

假設給一個長度 8 的陣列，找出 1 ~ 8 之中哪個數字沒有出現在陣列中。

## 453. Minimum Moves to Equal Array Elements

輸入一個 int 陣列長度為 n，每一次 move 只能對 n-1 個數字 +1。

輸出最少需要幾次 move，才能使陣列內所有數值相等。

## 455. Assign Cookies

輸入一個 child 陣列，陣列 size 就是 child 數量，每個 value 代表 child 要多大的 cookie 才會滿足 (content)。

輸入一個 cookie 陣列，陣列 size 就是 cookie 數量，每個 value 代表 cookie 有多大。

如果 cookie 的 value 大於等於 child 的 value，則 child 就可以被 content。

最後輸出最多可以被 content 的 child 數量。

## 461. Hamming Distance

兩個輸入數值的 binary 有幾個不同的 bit。 

## 463. Island Perimeter

給一個二維陣列，裡面的數值只有 0 或 1，求出 1 面積的邊框數量。

如果 1 的上下左右格子其中一個也是 1，表示該方向無邊框。

## 476. Number Complement

將數值每個 bit 作 not，要注意比最左邊的 1 更高位元的 0 不做 not，且測資中沒有負數。

## 485. Max Consecutive Ones

找出陣列中最長的連續的 1，求其包含 1 的數量。

## 492. Construct the Rectangle

輸入面積(area)，輸出長寬且符合以下條件。

長寬相乘等於面積(area)。

長度(length)大於等於寬度(width)。

長度和寬度的差(length - width)要最小。

## 496. Next Greater Element I
1. 宣告 int 陣列 returnNums。
1. returnSize 等於 findNumsSize。 
2. findNums 是 nums 的子集。
3. findNums 中不會有重複的數值。
4. nums 中不會有重複的數值。
5. 從 findNums 取出一數值 x 後，先找到其數值在 nums 中的位置 y。
6. 從 nums 位置 y 的右邊開始尋找第一個比 x 大的數值 z。
7. 將數值 z 放入 returnNums 中。

## 500. Keyboard Row

檢查每個字串裡的字母，是否在鍵盤上的同一列，測資有些有大寫，有些沒有。

## 504. Base 7

給一個 10 進制數字，轉換成 7 進制字串。

## 506. Relative Ranks

輸入一個沒有排序的成績數值陣列，輸出名次字串陣列，

輸出的名次位置要對應輸入的成績位置。

## 520. Detect Capital
1. 只有開頭字母大寫，回傳 true。
2. 全部字母大寫，回傳 true。
3. 全部字母小寫，回傳 true。
4. 其他，回傳 false。

## 530. Minimum Absolute Difference in BST

輸入 binary tree，輸出任意兩個節點的 difference，且 difference 必須是最小值。

假設有節點 A 和節點 B，這兩個節點有各自的 value 分別是 A.val 和 B.val。

difference 就是 A.val 減去 B.val 的絕對值。

## 541. Reverse String II

輸入一個字串和一個數字 k。

```
從 0  到 k  的部分反轉。
從 k 到 2k 的部分不反轉。
從 2k  到 3k  的部分反轉。
從 3k 到 4k 的部分不反轉，4k 以後以此類推。
```

字串長度小於 k 時全部反轉。

```
例如 123456789，k = 2，反轉後為 21  34  65  78  9，輸出 213465789。
例如 123456789，k = 3，反轉後為 321  456  987，輸出 321456987。
例如 123456789，k = 15，反轉後為 987654321，輸出 987654321。
例如 1234567890123，k = 5，反轉後為 54321  67890  321，輸出 5432167890321。
```