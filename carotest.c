#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int hangdoc(int matrix[100][100],int i, int j,int diem){
    int dem = 0;
    int a = i, b = j;
    while (matrix[i][j] == diem){
        dem++;
        j++;
    }
    i = a;
    j = b;
    if (dem == 3) {
        if (matrix[i][j-1] == 0 && matrix[i][j+3] == 0) return 1;
    }
    if (dem == 4) {
        if (matrix[i][j-1] == 0 || matrix[i][j+4] == 0) return 1;
    }
    return 0;
}
int hangngang(int matrix[100][100],int i, int j,int diem){
    int dem = 0;
    
    int a = i, b = j;
    while (matrix[i][j] == diem){
        dem++;
        i++;
    }
    i = a;
    j = b;
    if (dem == 3) {
        if (matrix[i-1][j] == 0 && matrix[i+3][j] == 0) return 1;
    }
    if (dem == 4) {
        if (matrix[i-1][j] == 0 || matrix[i+4][j] == 0) return 1;
    }
    return 0;
}
int hangcheoduoi(int matrix[100][100],int i, int j,int diem){
    int dem = 0;
    int a = i, b = j;
    while (matrix[i][j] == diem){
        dem++;
        j++;
        i++;
    }
    i = a;
    j = b;
    if (dem == 3) {
        if (matrix[i-1][j-1] == 0 && matrix[i+3][j+3] == 0) return 1;
    }
    if (dem == 4) {
        if (matrix[i-1][j-1] == 0 || matrix[i+4][j+4] == 0) return 1;
    }
    return 0;
}
int hangcheotren(int matrix[100][100],int i, int j,int diem){
    int dem = 0;
    int a = i, b = j;
    while (matrix[i][j] == diem){
        dem++;
        j++;
        i--;
    }
    i = a;
    j = b;
    if (dem == 3) {
        if (matrix[i+1][j-1] == 0 && matrix[i-3][j+3] == 0) return 1;
    }
    if (dem == 4) {
        if (matrix[i+1][j-1] == 0 || matrix[i-4][j+4] == 0) return 1;
    }
    return 0;
}
int threats(int matrix[100][100],int i, int j,int diem){
    int dem = 0;
    if (hangdoc(matrix ,i,j,diem) == 1) dem++ ;
    if(hangngang(matrix,i,j,diem) == 1) dem++ ;
    if (hangcheoduoi(matrix,i,j,diem) == 1) dem++ ;
    if (hangcheotren(matrix,i,j,diem) == 1) dem++ ;
    return dem;
}
int main(){
    int M,N;
    int player;
    int count = 0;
    scanf("%d%d%d",&M,&N,&player);
    if (player == 1) player = 2;
    else if (player == 2) player = 1;
    
    int matrix[100][100]={0};
    for (int i = 0; i < M+4; i++) {
        for (int j = 0; j< N+4; j++){
            if(i == 0 || j == 0 || i == M+3 || j == N+3){
                matrix[i][j] = -1;
            }
            else if (i == 1 || j == 1 || i == M+2 || j == N+2 ){
                matrix[i][j] = -1;
            }
            else {
                scanf("%d",&matrix[i][j]);
            }
        }
    }
  
    for (int i = 2; i <= M+1; i++) {
        for (int j = 2; j <= N+1; j++){
            count += threats(matrix,i,j,player);
        }
    }
    printf("%d",count);
    return 0;
}
// thực ra có thể làm ngắn hơn nhiều dòng, do cố chấp sửa code cũ nên vậy, đừng ai làm theo nhé