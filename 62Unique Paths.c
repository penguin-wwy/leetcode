int uniquePaths(int m, int n) {
    if(0 == m || 0 == n)
        return 0;
    int **grid = (int **)malloc(m * sizeof(int *));
	for(int i = 0; i < m; i++){
		grid[i] = (int *)malloc(n * sizeof(int));
	}
	grid[0][0] = 1;
	
	for(int i = 1; i < m; i++)
		grid[i][0] = 1;
	for(int i = 1; i < n; i++)
		grid[0][i] = 1;
		
	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
		}
	}
	int num = grid[m - 1][n - 1];
	
	for(int i = 0; i < m; i++)
		free(grid[i]);
	free(grid);
 
 	return num;
}