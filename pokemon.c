#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int backtracking(int n, int m, int matrix[10][10], int i, int j, int *check, int visited[10][10]) {
    visited[i][j] = -2;
    if (i > 0 && matrix[i-1][j] == *check && visited[i-1][j] != -2) {

        matrix[i-1][j] = 0;
        return 1;
    }
    if (j > 0 && matrix[i][j-1] == *check && visited[i][j-1] != -2) {
        
        matrix[i][j-1] = 0;
        return 1;
    }
    if (i < n+1 && matrix[i+1][j] == *check && visited[i+1][j] != -2) {
        
        matrix[i+1][j] = 0;
        return 1;
    }
    if (j < m+1 && matrix[i][j+1] == *check &&visited[i][j+1] != -2) {
       
        matrix[i][j+1] = 0;
        return 1;
    }
    if (i > 0 && matrix[i-1][j] == 0 && visited[i-1][j] != -2) {
        if (backtracking(n, m, matrix, i-1, j, check, visited) == 1) {
            return 1;
        }
    }
    if (j > 0 && matrix[i][j-1] == 0 && visited[i][j-1] != -2) {
        if (backtracking(n, m, matrix, i, j-1, check, visited) == 1) {
            return 1;
        }
    }
    if (i < n+1 && matrix[i+1][j] == 0 && visited[i+1][j] != -2) {
        if (backtracking(n, m, matrix, i+1, j, check, visited) == 1) {
            return 1;
        }
    }
    if (j < m+1 && matrix[i][j+1] == 0 && visited[i][j+1] != -2) {
        if (backtracking(n, m, matrix, i, j+1, check, visited) == 1) {
            return 1;
        }
    }
    return 0;
}


int main(){
    int n , m;
    scanf("%d%d",&n,&m);
    int dem = 0;
    int matrix[10][10]={0};
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <=m+1; j++){
            if (i == 0 || j == 0 || i == n+1 || j == m+1){
                matrix[i][j] = 0;

            } else{
                scanf("%d",&matrix[i][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (matrix[i][j] != 0 && matrix[i][j]!=-1){
                
                int visited[10][10] = {0};
                int *check = &matrix[i][j];
                if (backtracking(n,m,matrix,i,j,check,visited)==1){
                    matrix[i][j] = 0;
                    dem++;
                }
                
            }
        }
    }
    printf("%d",dem);
    
    return 0;
}