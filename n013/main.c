
int romanToInt(char* s) {
    // I = 1，V = 5，X = 10，L = 50，C = 100，D = 500，M = 1000。
    
    // 找出字串長度。
    int size = 0;
    for(size = 0; s[size] != 0; size++);
    
    int result = 0;
    int previous = 0;
    
    // 羅馬數字的讀法是，先從最右邊的字元開始看。
    // 假設當前字母的代表的數值，比右邊的字母數值還要大，就進行加法。
    // 假設當前字母的代表的數值，比右邊的字母數值還要小，就進行減法。
    for(int i = size -1; i >= 0; i--){
        // 字母 I
        if(s[i] == 73){
            int value = 1;
            result += (value >= previous) ? 1 : -1; 
            previous = value;
        
        // 字母 V    
        }else if(s[i] == 86){
            int value = 2;
            result += (value >= previous) ? 5 : -5; 
            previous = value;
        
        // 字母 X
        }else if(s[i] == 88){
            int value = 3;
            result += (value >= previous) ? 10 : -10; 
            previous = value;
        
        // 字母 L
        }else if(s[i] == 76){
            int value = 4;
            result += (value >= previous) ? 50 : -50; 
            previous = value;
        
        // // 字母 C
        }else if(s[i] == 67){
            int value = 5;
            result += (value >= previous) ? 100 : -100; 
            previous = value;
        
        // 字母 D
        }else if(s[i] == 68){
            int value = 6;
            result += (value >= previous) ? 500 : -500; 
            previous = value;
        
        // 字母 M
        }else if(s[i] == 77){
            int value = 7;
            result += (value >= previous) ? 1000 : -1000; 
            previous = value;
        }
    }
    
    return result;
}