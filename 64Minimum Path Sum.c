int minPathSum(int** grid, int gridRowSize, int gridColSize) {
	int **arr = (int **)malloc(gridRowSize * sizeof(int *));
	for (int i = 0; i < gridRowSize; i++){
		arr[i] = (int *)calloc(gridColSize, sizeof(int));
	}

	arr[0][0] = grid[0][0];
	for (int i = 1; i < gridColSize; i++)
		arr[0][i] = arr[0][i - 1] + grid[0][i];

	for (int i = 1; i < gridRowSize; i++)
		arr[i][0] = arr[i - 1][0] + grid[i][0];

	for (int i = 1; i < gridRowSize; i++){
		for (int j = 1; j < gridColSize; j++)
			arr[i][j] = (arr[i - 1][j] < arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1]) + grid[i][j];
	}

	int num = arr[gridRowSize - 1][gridColSize - 1];
	for (int i = 0; i < gridRowSize; i++)
		free(arr[i]);
	free(arr);
	arr = NULL;

	return num;
}