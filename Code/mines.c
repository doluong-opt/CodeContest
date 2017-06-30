#include<stdio.h>
#include <stdlib.h>
#define M 5
#define N 5
#define MINE -1
int B[M][N];
int T[M][N];
void init() {
	int i,j;
  for ( i = 0; i < M; i++)
    for ( j = 0; j < N; j++) {
      B[i][j] = 0;
      T[i][j] = 0;
    }
    B[1][2] = MINE;
    B[3][1] = MINE;
    }
void count_mines(){
	int i,j;                        
	for (i=0;i<M;i++ )
		for (j=0;j<N;j++)
			if (B[i][j] !=MINE){
				int cnt=0;
				if (i-1>=0 && j-1>=0 && B[i-1][j-1]==MINE)
					cnt=cnt+1;
				if (j-1>=0 && B[i][j-1]==MINE)
					cnt=cnt+1;
				if (i+1<M && j-1>=0 && B[i+1][j-1]==MINE)
					cnt=cnt+1;
                if (i+1<M && B[i+1][j]==MINE)
                    cnt=cnt+1;
                if (i+1<M && j+1<N && B[i+1][j+1]==MINE)
                    cnt=cnt+1;
                if (j+1<N && B[i][j+1]==MINE)
                    cnt=cnt+1;
                if (i-1>=0 &&j+1<N && B[i-1][j+1]==MINE)
                    cnt=cnt+1;
                if (i-1>=0 && B[i-1][j] == MINE)
                    cnt=cnt+1;
                B[i][j] = cnt;
			}
	}
void printMap1() {
	int j,i;
	printf("  ");
	for (j=0;j<N;j++)
		printf("%d ",j%10);
	printf("\n");
	for (i=0;i<M;i++){
		printf("%d ",i%10);
		for (j=0;j<N;j++)
			if (B[i][j]==MINE)
				printf("x ");
			else if (B[i][j]==0)
				printf(". ");
			else printf("%d ",B[i][j]);
		printf("\n");
					
	}
}
void open_cell_1(int r, int c) {
	if (T[r][c] == 0)
		T[r][c] = 1;
}
int count_remain() {
	int i,j,cnt = 0;
	for ( i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			if (T[i][j] == 0)
				cnt++;
	return cnt;
}

int main() {
	int r,c;
	int k=2;
	init();
	count_mines();
	printMap1();
	while(1) {
	printf("Nhap o can mo: "); scanf("%d%d", &r, &c);
	if (B[r][c] == MINE) {
		printf("You lose.\n");
	break;
	}
	open_cell_1(r,c);
	if (count_remain()==k){
		printf("you win.\n");
		break;
		}
	}
	return 0;
}
