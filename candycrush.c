#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void swap(int *a, int *b){
    //doi cho hai so
    int temp = *a;
    *a = *b;
    *b = temp;
}
int kiemtra(int **matrix, int a1, int b1 ) {
    //ham check xem co 3 diem thang hang khong
    int hang = a1; 
    int cot = b1;
    for (int x = -1; x < 2; x++) {
        for (int y = -1; y < 2; y ++) {
            a1 = hang; b1 = cot;
            int hople = 1;
            if (x != 0 && y != 0) continue;
            else if (x == 0 && y == 0) continue;
            else {
                while (matrix[a1][b1] == matrix[a1+x][b1+y]){
                    hople++;
                    a1 += x;
                    b1 += y;
                    if (hople == 3) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int check1(int **matrix, int a, int b) {
    int dem = 0;
    //doi cho mot gia tri 4 lan roi kiem tra 
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j ++) {
            if (i != 0 && j != 0) continue;
            else if (i == 0 && j == 0) continue;
            else {
                if (matrix[a + i][b + j] != -1){
                    swap(&matrix[a][b],&matrix[a+i][b+j]);
                    if (kiemtra(matrix, a + i, b + j) == 1) dem = 1 ;
                    swap(&matrix[a][b],&matrix[a+i][b+j]);
                }
            }
        }
    }
    if (dem == 1) return 1;
    return 0;
}

int main() {
    int N, M;
    scanf("%d%d",&N,&M);
    N = N + 2; M = M + 2;
    int count = 0;
    int **matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        matrix[i] = (int *)malloc(M * sizeof(int));
    }   
    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j< M; j++) {
            if (i == 0 || j == 0 || i == N - 1 || j == M - 1) matrix[i][j] = -1;
            else scanf("%d",&matrix[i][j]);
        }
    }
    for (int i = 1; i < N - 1;i++) {
        for (int j = 1; j < M - 1; j++){
            if (check1(matrix, i , j) == 1) count++;
        }
    }
    printf("%d",count);
    
    return 0;
}