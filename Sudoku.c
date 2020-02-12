#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int n = 9;


void print_grid(int grid[n][n]){

	for(size_t i = 0;i < n;i++){
		for(size_t j = 0;j < n;j++)
			printf("%d ",grid[i][j]);

		printf("\n");
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


void SolveMe(){


	if(){


	}
	else{

		for(;;){
		
		SolveMe(k + 1);

		}


	}

}



int main(){

	int grid[n][n];
	init(grid);

	return 0;
}
