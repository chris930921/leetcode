/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

char keyboardMap[] = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};

int getKeyIndex(char* alphabet){
    if(alphabet > 96){
        return alphabet - 97;
    }else{
        return alphabet + (97 - 65) - 97;
    }
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    char* features = (char*)calloc(wordsSize, sizeof(char));
    for(int i = 0; i < wordsSize; i++){
        int firstKeyIndex = getKeyIndex(words[i][0]);
        int lineIndex = keyboardMap[firstKeyIndex];
        for(int j = 0; words[i][j] != 0; j++){
            int keyIndex =  getKeyIndex(words[i][j]);
            features[i] += (keyboardMap[keyIndex] != lineIndex);
        }
    }
    
    for(int i = 0; i < wordsSize; i++){
        (*returnSize) += (features[i] == 0);
    }
    
    char** resultWords = (char**)malloc(sizeof(char*) * (*returnSize));
    int pushIndex = 0;
    for(int i = 0; i < wordsSize; i++){
        if(features[i] == 0){
           resultWords[pushIndex] = words[i];
           pushIndex++;
        }
    }

    return resultWords;
}

void main(){
    char test0[] = "Hello";
    char test1[] = "Alaska";
    char test2[] = "Dad";
    char test3[] = "Peace";
    char* words[] = { test0, test1, test2, test3};
    
    int returnSize = 0;
    char** results = findWords(words, 4, &returnSize);
    
    printf("%d\n", returnSize);
    for(int i = 0; i < returnSize; i++){
        printf("%s\n", results[i]);
    }
}

/* fail_version

char* keyboardMap = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2}; 
 
char** findWords(char** words, int wordsSize, int* returnSize) {
    for(int i = 0; i < wordsSize; i++) words[i][0] += (97 - 65);
    
    char* features = (char*)calloc(wordsSize, sizeof(char));
    char features[wordsSize];
    for(int i = 0; i < wordsSize; i++){
        int firstKeyIndex = words[i][0] - 97;
        int lineIndex = keyboardMap[firstKeyIndex];
        for(int j = 0; words[i][j] != 0; j++){
            int keyIndex = words[i][j] - 97;
            //features[i] += (keyboardMap[keyIndex] != lineIndex);
            features[0] += (keyboardMap[keyIndex] != lineIndex);
        }
    }
    
    for(int i = 0; i < wordsSize; i++){
        (*returnSize) += (features[i] == 0);
    }
    
    char** resultWords = (char**)malloc(sizeof(char*) * (*returnSize));
    for(int i = 0; i < wordsSize; i++){
        if(features[i] == 0){
           resultWords[i] = words[i]; 
        }
    }
    
    for(int i = 0; i < wordsSize; i++) words[i][0] -= (97 - 65);
    *returnSize = wordsSize;
    return words;
}
*/