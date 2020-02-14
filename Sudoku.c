#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int n = 9;

int IsEmpty(int row, int col, int grid[n][n]);
int IsValid(int i, int j, int target, int grid[n][n]);
int IsFull(int grid[n][n]);

int Recurse(int row, int col, int grid[n][n]){

	if(IsFull(grid)) return 1;

	for(int t = 1;t <= n;t++){

		if(IsValid(row,col,t,grid) && IsEmpty(row,col,grid)){

			grid[row][col] = t;
			if(Recurse(row,col,grid)) return 1;
			grid[row][col] = 0;
		}

	}
	return 0;
}




int IsEmpty(int row, int col, int grid[n][n]){


	return (grid[row][col] == 0) ? 1 : 0;

}


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

	printf("\n");
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

int IsFull(int grid[n][n]){

	for(size_t i = 0;i < n;i++)
		for(size_t j = 0;j < n;j++)
			if(grid[i][j] == 0) return 0;


	return 1;
}

int main(){

	int test[9][9] = {
	0,7,2,0,0,4,9,0,0,
	3,0,4,0,8,9,1,0,0,
	8,1,9,0,0,6,2,5,4,
	7,0,1,0,0,0,0,9,5,
	9,0,0,0,0,2,0,7,0,
	0,0,0,8,0,7,0,1,0,
	4,0,5,0,0,1,6,2,0,
	2,3,7,0,0,0,5,0,1,
	0,0,0,0,2,5,7,0,0

	};

	print_grid(test);
	Recurse(0,0,test);
	print_grid(test);
	return 0;
}
