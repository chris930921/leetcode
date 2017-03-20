int countTopEdge(int**grid, int y, int x,int gridRowSize, int gridColSize){
    if(grid[y][x] == 0){
        return 0;
    }
    
    if(y - 1 < 0){
        return 1;
    }
    
    if(grid[y-1][x] == 0){
        return 1;
    }else{
        return 0;
    }
}

int countBottomEdge(int**grid, int y, int x,int gridRowSize, int gridColSize){
    if(grid[y][x] == 0){
        return 0;
    }
    
    if(y + 1 == gridRowSize){
        return 1;
    }
    
    if(grid[y+1][x] == 0){
        return 1;
    }else{
        return 0;
    }
}

int countLeftEdge(int**grid, int y, int x,int gridRowSize, int gridColSize){
    if(grid[y][x] == 0){
        return 0;
    }
    
    if(x - 1 < 0){
        return 1;
    }
    
    if(grid[y][x-1] == 0){
        return 1;
    }else{
        return 0;
    }
}

int countRightEdge(int**grid, int y, int x,int gridRowSize, int gridColSize){
    if(grid[y][x] == 0){
        return 0;
    }
    
    if(x + 1 == gridColSize){
        return 1;
    }
    
    if(grid[y][x+1] == 0){
        return 1;
    }else{
        return 0;
    }
}

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int totoalEdgs = 0;
    
    for(int i = 0; i < gridRowSize; i++){
        for(int j = 0; j < gridColSize; j++){
            int countEdges = 0;
            countEdges += countTopEdge(grid, i, j, gridRowSize, gridColSize);
            countEdges += countBottomEdge(grid, i, j, gridRowSize, gridColSize);
            countEdges += countLeftEdge(grid, i, j, gridRowSize, gridColSize);
            countEdges += countRightEdge(grid, i, j, gridRowSize, gridColSize);
            
            totoalEdgs += countEdges;
        }
    }
    
    return totoalEdgs;
}