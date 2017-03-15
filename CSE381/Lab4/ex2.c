#include <stdio.h>

void matrix_add(int mtx1[4][4], int mtx2[4][4], int mtx_sum[4][4]) {
	for (int i=0; i < 4; i++) {
		for (int j=0; j<4; j++) {
			mtx_sum[i][j] = mtx1[i][j] + mtx2[i][j];
		}
	}
}

int main() {
	int mtx1[4][4], mtx2[4][4], mtx_sum[4][4];
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			mtx1[i][j] = i+j;
			mtx2[i][j] = j-i;
		}
	}
	printf("Now we initialize mtx1 as: 0 1 2 3\n1 2 3 4\n2 3 4 5\n3 4 5 6\n");
	printf("Then we initialize mtx2 as: 0 1 2 3\n-1 0 1 2\n-2 -1 0 1\n-3 -2 -1 0\n");
	
	matrix_add(mtx1, mtx2, mtx_sum);
	printf("We get sum result as:\n");	
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
				printf("%d ", mtx_sum[i][j]);
		}
		printf("\n");
	}
}