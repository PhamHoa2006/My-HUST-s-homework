#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int area(int **matrix, int hang, int cot, int N, int M, int **visited, int *dem){
    visited[hang][cot] = -1;
    (*dem)++;
    
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            if (i == 0 && j == 0) continue;
            else {
                if (hang + i < 0 || hang + i >= N || cot + j < 0|| cot + j >= M) continue;
                else if (matrix[hang + i][cot + j] == 1 && visited[hang+i][cot+j] != -1) {
                    area(matrix, hang + i, cot + j, N, M, visited, dem);
                }
            }
        }
    }
    matrix[hang][cot] = *dem;
    return 0;
}
int main(){
    int N, M;
    scanf("%d%d",&N,&M);
    int dem = 0;
    
    int **matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++){
        matrix[i] = (int *)malloc(M * sizeof(int));
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int **visited = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++){
        visited[i] = (int *)calloc(M , sizeof(int));
        
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            dem = 0;
            if (matrix[i][j] == 1 && visited[i][j] != -1) area(matrix, i , j, N, M, visited, &dem);
        }
    }
    int maxArea = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){

            if (maxArea < matrix[i][j]) maxArea = matrix[i][j];
        }
    }
    printf("%d",maxArea);
    
    for (int i = 0; i < N; i++){
        free(matrix[i]);
        free(visited[i]);
    }
    free(matrix);
    free(visited);
    return 0;
}