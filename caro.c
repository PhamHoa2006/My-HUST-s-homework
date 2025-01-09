#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int kiemtra(int matrix[100][100],int a,int b,int N,int M, int arr[100][100], int player){
    int dem = 0;
    int k = 0;
    int hang = a, cot = b;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++){
            if (i == 0 && j == 0) continue;
            a = hang;
            b = cot;
            k = 0;
            if (matrix[a+i][b+j] != player) {
                continue;
            }
            while(a >= 1 && a <= M && b >= 1 && b <= N ) {
                
                k++;
                a+=i;
                b+=j;
                if (matrix[a+i][b+j] != player) break;
            }
            if (k > 5) {
                printf("loi");
                return 0;
            }
            if (k == 5) k = 50;
            else if (k == 4 ) {
                if (matrix[a+i][b+j] == 0 && matrix[hang - i][cot - j] == 0) k = 40;
                else if (matrix[a+i][b+j] == 0 && matrix[hang - i][cot -j] != 0) k = 39;
                else if (matrix[a+i][b+j] != 0 && matrix[hang - i][cot -j] == 0) k = 39;
                else if (matrix[a+i][b+j] != 0 && matrix[hang - i][cot -j] != 0) k = 0;
            } 
            
            else if (k == 3 ) {
                if (matrix[a+i][b+j] == player || matrix[hang - i][cot - j] == player) k = 30;
                else if (matrix[a+i][b+j] == 0 && matrix[hang - i][cot - j] == 0) k = 29;
                else if (matrix[a+i][b+j] == 0 && matrix[hang - i][cot -j] != 0) k = 28;
                else if (matrix[a+i][b+j] != 0 && matrix[hang - i][cot -j] == 0) k = 28;
                else if (matrix[a+i][b+j] != 0 && matrix[hang - i][cot -j] != 0) k = 0;
            } 
            else if (k == 2 ) {
                if (matrix[a+i][b+j] == player || matrix[hang - i][cot - j] == player) k = 20;
                else if (matrix[a+i][b+j] == 0 && matrix[hang - i][cot - j] == 0) k = 19;
                else if (matrix[a+i][b+j] == 0 && matrix[hang - i][cot -j] != 0) k = 18;
                else if (matrix[a+i][b+j] != 0 && matrix[hang - i][cot -j] == 0) k = 18;
                else if (matrix[a+i][b+j] != 0 && matrix[hang - i][cot -j] != 0) k = 0;
            } 
            else if (k == 1 ) {
                if (matrix[a+i][b+j] == player || matrix[hang - i][cot - j] == player) k = 10;
                else if (matrix[a+i][b+j] == 0 && matrix[hang - i][cot - j] == 0) k = 9;
                else if (matrix[a+i][b+j] == 0 && matrix[hang - i][cot -j] != 0) k = 8;
                else if (matrix[a+i][b+j] != 0 && matrix[hang - i][cot -j] == 0) k = 8;
                else if (matrix[a+i][b+j] != 0 && matrix[hang - i][cot -j] != 0) k = 0;
            } 
            k += dem;
            if ( k >=1 ) dem++;

            if ( k > arr[hang][cot]) arr[hang][cot] = k;
            
        }
    }
    return 0;
}
int main(){
    int M,N;
    int player;
    int max = 0;
    scanf("%d%d%d",&M,&N,&player);
    int matrix[100][100]={0};
    for (int i = 0; i < M+2; i++) {
        for (int j = 0; j< N+2; j++){
            if(i == 0 || j == 0 || i == M+1 || j == N+1){
                matrix[i][j] = -1;
            }
            
            else {
                scanf("%d",&matrix[i][j]);
            }
        }
    }
    int arr[100][100] = {0};
    
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++){
            if (matrix[i][j] == 0) kiemtra(matrix,i,j,N,M,arr,player);
        }
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] > max ) max = arr[i][j];
        }
    }
    for (int i  = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if ( arr[i][j] == max) {
                printf("%d %d",i - 1, j-1);
                return 0;
            }
        }
    }
    return 0;
}