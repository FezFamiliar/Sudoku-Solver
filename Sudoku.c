#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int n = 9;



int IsValid(int row, int col, int target,int grid[n][n]){

	int aux_row_length = 0;
	int aux_col_length = 0;
	size_t i, j;
	for(size_t x = 0;x < n;x++) // check row
		if(grid[row][x] == target) return 0;

	for(size_t y = 0;y < n;y++) // check column
		if(grid[y][col] == target) return 0;


	//check box

	if(row < 3 && col < 3){

		i = 0;
		j = 0;

	}
	if(row < 3 && col >= 3 && col < 6){

 		i = 0;
		j = 3;

	}
	if(row < 3 && col >= 6 && col < 9){

		i = 0;
		j = 6;

	}
	if(row >= 3 && row < 6 && col < 3){

		i = 3;
		j = 0;

	}
	if(row >= 3 && row < 6 && col >= 3 && col < 6){

		i = 3;
		j = 3;

	}
	if(row >= 3 && row < 6 && col >= 6 && col < 9){

		i = 3;
		j = 6;

	}
	if(row >= 6 && col < 3){
		i = 6;
		j = 0;

	}
	if(row >= 6 && col >= 3 && col < 6){

		i = 6;
		j = 3;
	}
	if(row >= 6 && col >= 6){

		i = 6;
		j = 6;

	}

	aux_row_length = i + 3;
	aux_col_length = j + 3;

	for(size_t _i = i;_i < aux_row_length;_i++)
		for(size_t _j = j;_j < aux_col_length;_j++)
			if(grid[_i][_j] == target)   return 0;



	return 1;
}

void print_grid(int grid[n][n]){

	for(size_t i = 0;i < n;i++){
		for(size_t j = 0;j < n;j++){

			printf(" %d ",grid[i][j]);
			if(j == 2 || j == 5) printf("|");
			}


		printf("\n");
		if(i == 2 || i == 5) printf("----------------------------\n");
	}
}
void Shuffle(int* random_cask){

	int j, temp;
	for(size_t i = n - 1;i > 0;i--){

		j = rand() % (i + 1);
		temp = random_cask[j];
		random_cask[j] = random_cask[i];
		random_cask[i] = temp;
	}

}

void init(int grid[n][n]){

	int filled, fill_value, fill_place_i, fill_place_j;

	for(size_t i = 0;i < n;i++)
		for(size_t j = 0;j < n;j++)
			grid[i][j] = 0;


	srand(time(0));


	int* random_cask = (int*)malloc(n*sizeof(int));

	for(size_t i = 0;i < n;i++) random_cask[i] = i + 1;


	for(int i = 0;i < n;i+=3){
		for(int j = 0;j < n;j+=3){

			Shuffle(random_cask);
			filled = 2 + rand() % (n - 2);
			for(int k = 0;k < filled;k++){

				fill_place_i = i + rand() % 3;
				fill_place_j = j + rand() % 3;


				grid[fill_place_i][fill_place_j] = random_cask[k++];
			}
		}
	}

	print_grid(grid);
	free(random_cask);
}


int main(){

	int grid[9][9] = {
	0,0,0,8,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,
	2,0,0,7,9,0,0,0,0,
	0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,
	3,0,0,0,9,0,0,0,0,
	6,0,0,0,0,0,0,0,0

	};
	if(IsValid(4,8,9,grid)){


	printf("It's valid!\n");
	}
	else printf("Its not valid!\n");
	//init(grid);
	return 0;
}
