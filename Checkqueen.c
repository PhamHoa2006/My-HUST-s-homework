#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int checkQueen(int field[101][101],int i, int j,int N){
    int hang = i;
    int cot = j;
    for (int x = -1; x < 2; x++){
        for (int y = -1; y <2; y++){
            i = hang;
            j = cot;
            if (x == 0 && y == 0) continue;
            else {
                while (i + x >= 0 && j + y >= 0 && i + x < N && j + y < N) {
                    i += x;
                    j += y;
                    if (field[i][j] == 1) return 0;
                }
            }
        }
    }
    return 1;
}
int main(){
    int numTestcase;
    int check = 1;
    scanf("%d",&numTestcase);
    for (int i = 0; i < numTestcase; i++){
        check = 1;
        int N;
        scanf("%d",&N);
        int field[101][101];
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                scanf("%d",&field[i][j]);
            }
        }
        for (int i = 0; i < N; i++){
            for (int j = 0;j < N; j++){
                if (field[i][j] == 1) {
                    if (checkQueen(field,i,j,N) == 0) check = 0;
                }
            }
        }
        if (i == numTestcase - 1) {
            printf("%d",check);
        }
        else printf("%d\n",check);
    }
    return 0;
}