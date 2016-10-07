char findTheDifference(char* s, char* t) {
    char* letterSet = (char*)calloc(26, sizeof(char));
    int i;
    for(i = 0; s[i] != 0; i++){
        letterSet[s[i] - 97]++;
    }
    for(i = 0; t[i] != 0; i++){
        letterSet[t[i] - 97]--;
    }
    
    i = 0;
    while(letterSet[i] == 0) i++;
    
    return i + 97;
}