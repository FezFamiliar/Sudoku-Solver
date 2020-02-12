#include <stdio.h>

const int n = 9;


void print_grid(int grid[n][n]){

	for(size_t i = 0;i < n;i++){
		for(size_t j = 0;j < n;j++){
			printf("%d ",grid[i][j]);
		}
		printf("\n");
	}
}

int main(){

	int grid[n][n];
	for(size_t i = 0;i < n;i++)
		for(size_t j = 0;j < n;j++)
			grid[i][j] = 0;


	print_grid(grid);
	return 0;
}
