int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if(NULL == obstacleGrid || 0 == obstacleGridRowSize || 0 == obstacleGridColSize)
        return 0;
    int **grid = (int **)malloc(obstacleGridRowSize * sizeof(int *));
	for(int i = 0; i < obstacleGridRowSize; i++){
		grid[i] = (int *)calloc(obstacleGridColSize, sizeof(int));
	}
	
	int num = 0;
	while(num < obstacleGridRowSize){
		if(1 == obstacleGrid[num][0])
			break;
		grid[num++][0] = 1;
	}
	num = 0;
	while(num < obstacleGridColSize){
		if(1 == obstacleGrid[0][num])
			break;
		grid[0][num++] = 1;
	}
	
	for(int i = 1; i < obstacleGridRowSize; i++){
		for(int j = 1; j < obstacleGridColSize; j++){
			if(1 == obstacleGrid[i][j])
				grid[i][j] = 0;
			else
			    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
		}
	}
	num = grid[obstacleGridRowSize - 1][obstacleGridColSize - 1];
	
	for(int i = 0; i < obstacleGridRowSize; i++)
		free(grid[i]);
	free(grid);
	
	return num;
}