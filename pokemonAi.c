#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int backtracking(int n, int m, int matrix[100][100], int i, int j, int *check, int *count, int visited[100][100]) {
    visited[i][j] = -2;
    printf("Checking cell (%d, %d) with value %d\n", i, j, matrix[i][j]);
    
    if (i > 0 && matrix[i-1][j] == *check && visited[i-1][j] != -2) {
        (*count)++;
        matrix[i-1][j] = 0;
        printf("Condition 1 met at (%d, %d)\n", i-1, j);
        return 1;
    }
    if (j > 0 && matrix[i][j-1] == *check && visited[i][j-1] != -2) {
        (*count)++;
        matrix[i][j-1] = 0;
        printf("Condition 2 met at (%d, %d)\n", i, j-1);
        return 1;
    }
    if (i < n-1 && matrix[i+1][j] == *check && visited[i+1][j] != -2) {
        (*count)++;
        matrix[i+1][j] = 0;
        printf("Condition 3 met at (%d, %d)\n", i+1, j);
        return 1;
    }
    if (j < m-1 && matrix[i][j+1] == *check && visited[i][j+1] != -2) {
        (*count)++;
        matrix[i][j+1] = 0;
        printf("Condition 4 met at (%d, %d)\n", i, j+1);
        return 1;
    }

    // Additional code for backtracking here...

    
    if (i > 0 && matrix[i-1][j] == 0 && visited[i-1][j] != -2) {
        if (backtracking(n, m, matrix, i-1, j, check, count, visited) == 1) {
            return 1;
        }
    }
    if (j > 0 && matrix[i][j-1] == 0 && visited[i][j-1] != -2) {
        if (backtracking(n, m, matrix, i, j-1, check, count, visited) == 1) {
            return 1;
        }
    }
    if (i < n+1 && matrix[i+1][j] == 0 && visited[i+1][j] != -2) {
        if (backtracking(n, m, matrix, i+1, j, check, count, visited) == 1) {
            return 1;
        }
    }
    if (j < m+1 && matrix[i][j+1] == 0 && visited[i][j+1] != -2) {
        if (backtracking(n, m, matrix, i, j+1, check, count, visited) == 1) {
            return 1;
        }
    }
    return 0;
}


int main(){
    int n , m;
    scanf("%d%d",&n,&m);
    int dem = 0;
    int *count = &dem;
    int matrix[100][100]={0};
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <=m+1; j++){
            if (i == 0 || j == 0 || i == n+1 || j == m+1){
                matrix[i][j] = 0;

            } else{
                scanf("%d",&matrix[i][j]);
            }
        }
    }
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <=m+1; j++){
            printf("%d ",matrix[i][j]);
        }}
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (matrix[i][j] != 0 && matrix[i][j]!=-1){
                
                int visited[100][100] = {0};
                int *check = &matrix[i][j];
                if (backtracking(n,m,matrix,i,j,check, count,visited)==1){
                    matrix[i][j] = 0;
                    dem++;
                }
                printf("%d  ",*check);
                
            }
        }
    }
    printf("%d",dem/2);
    
    return 0;
}

/*
int backtracking(int n, int m, int matrix[100][100], int i, int j, int *check, int *count, int visited[100][100], int *x, int *y) {
    visited[i][j] = -2;
    printf("Checking cell (%d, %d) with value %d\n", i, j, matrix[i][j]);
    
    if (i > 0 && matrix[i-1][j] == *check && (i-1) != *x && j != *y) {
        (*count)++;
        matrix[i-1][j] = 0;
        printf("Condition 1 met at (%d, %d)\n", i-1, j);
        return 1;
    }
    if (j > 0 && matrix[i][j-1] == *check && i != *x && (j-1) != *y) {
        (*count)++;
        matrix[i][j-1] = 0;
        printf("Condition 2 met at (%d, %d)\n", i, j-1);
        return 1;
    }
    if (i < n-1 && matrix[i+1][j] == *check && (i+1) != *x && j != *y) {
        (*count)++;
        matrix[i+1][j] = 0;
        printf("Condition 3 met at (%d, %d)\n", i+1, j);
        return 1;
    }
    if (j < m-1 && matrix[i][j+1] == *check && i != *x && (j+1) != *y) {
        (*count)++;
        matrix[i][j+1] = 0;
        printf("Condition 4 met at (%d, %d)\n", i, j+1);
        return 1;
    }

    // Additional code for backtracking here...
    
    return 0;
}

*/