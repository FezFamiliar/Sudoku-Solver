#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int n = 9;


void print_grid(int grid[n][n]){

	for(size_t i = 0;i < n;i++){
		for(size_t j = 0;j < n;j++){
			printf("%d ",grid[i][j]);
		}
		printf("\n");
	}
}


void init(int grid[n][n]){

	int filled, fill_value, fill_place_i, fill_place_j, aux;
	aux = 0;
	srand(time(0));
	filled = 1 + rand() % (n - 2);

	int* duplicate = (int*)malloc(filled*sizeof(int));
	while(filled-- > 0){

		fill_place_i = rand() % 3;
		fill_place_j = rand() % 3;
		fill_value = 1 + rand() % n;

		for(size_t i = 0;i < aux;i++){
			if(duplicate[i] == fill_value){
				do{

				fill_value = 1 + rand() % n;
				}while(fill_value != duplicate[i]);


			}
		}

		duplicate[aux++] = fill_value;

		grid[fill_place_i][fill_place_j] = fill_value;
	}


	print_grid(grid);

}


int main(){

	int grid[n][n];
	for(size_t i = 0;i < n;i++)
		for(size_t j = 0;j < n;j++)
			grid[i][j] = 0;


	//print_grid(grid);
	init(grid);
	return 0;
}
