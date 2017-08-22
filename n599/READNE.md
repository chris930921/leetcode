## 599. Minimum Index Sum of Two Lists

從兩組字串中找出相同的字串。

並且該字串在兩組中的 index 相加是最小值。

如果有兩個字串同時出現並且都是最小值，一起加入道輸出結果中。

範例 1。

```
輸入
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]

"Shogun" 字串同時出現，index 相加是 0 + 3 = 3。

輸出
["Shogun"]
```

範例 2。

```
輸入
["Shogun", "Burger King", "KFC"]
["Burger King", "Shogun", "Hungry Hunter Steakhouse"]

"Shogun" 字串同時出現，index 相加是 0 + 1 = 1。
"Burger King" 字串同時出現，index 相加是 1 + 0 = 1。

輸出
["Shogun", "Burger King"]
```

範例 3。

```
輸入
["Shogun", "Burger King", "KFC"]
["Burger King", "Hungry Hunter Steakhouse", "Shogun"]

"Shogun" 字串同時出現，index 相加是 0 + 2 = 2。
"Burger King" 字串同時出現，index 相加是 1 + 0 = 1。

輸出
["Burger King"]
```