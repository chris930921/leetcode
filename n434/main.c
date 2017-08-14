// 434. Number of Segments in a String

int countSegments(char* s) {
    char space = ' ';
    int lengthCounter = 0;
    int segmentCounter = 0;
    int i = 0;
    
    for(i = 0; s[i]; i++){
        if(s[i] == space){
            segmentCounter += (lengthCounter != 0);
            lengthCounter = 0;
        }else{
            lengthCounter++;
        }
    }
    
    segmentCounter += (lengthCounter != 0);
    return segmentCounter;
}