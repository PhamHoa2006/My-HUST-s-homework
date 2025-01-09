#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int escape(int **matrix, int hang, int cot,int N, int M, int visited[100][100]){
    visited[hang][cot] = -1;
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            if (i == 0 && j == 0) continue;
            else if (i != 0 && j != 0) continue;
            else {
                if (matrix[hang+i][cot+j] == 1 && visited[hang+i][cot+j] != -1) {
                    if (hang + i == 0 || hang + i == N-1 || cot + j == 0 || cot + j == M-1){
                        return 1;
                    }
                    else {
                        if (escape(matrix, hang + i, cot + j, N, M, visited) == 1) return 1;
                    }
                }
            }
        }
    }
    return 0;
}



int main(){
    int N, M;
    scanf("%d%d",&N,&M);
    int hang,cot;
    scanf("%d%d",&hang,&cot);
    if (hang == 0 || hang == N-1 || cot == 0 || cot == M-1){
        printf("1");
        return 0;
    }
    int **matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++){
        matrix[i] = (int *)malloc(M * sizeof(int));
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int visited[100][100] = {0};
    printf("%d",escape(matrix, hang, cot, N, M, visited));
    for (int i = 0; i < N; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
    
}