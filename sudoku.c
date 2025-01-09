#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <math.h>

int main(){
    int N;
    int check = 1;
    scanf("%d",&N);
    
    for (int somatran = 0; somatran < N; somatran++) {
        check = 1;
        int matrix[9][9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d",&matrix[i][j]);
                if (matrix[i][j] < 1 || matrix[i][j] > 9) check = 0;
            }
        }
        if (check == 0) {
            printf("%d",check);
            continue;;
        }
        for (int  i = 0; i < 9; i++){
            int mangdanhdau1[10]={0};
            int mangdanhdau2[10] = {0}; // check hang doc luon
            for (int j = 0; j < 9; j++){
                mangdanhdau1[matrix[i][j]]++;
                mangdanhdau2[matrix[j][i]]++;
            }
            for (int j = 1; j <= 9; j++){
                if (mangdanhdau1[j] != 1 || mangdanhdau2[j] != 1) {
                    check = 0;
                }
            }
        }
        if (check == 0) {
            printf("%d",check);
            continue;;
        }
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j += 3){
                int map3[10] = {0};
                for (int g = 0; g < 3; g++){
                    for (int h = 0; h < 3; h++){
                        map3[matrix[i+g][j+h]]++;
                    }
                }
                for (int j = 1; j <= 9; j++){
                    if (map3[j] != 1) {
                        check = 0;
                    }
                }
            }
        }
        if (check == 0) {
            printf("%d",check);
            continue;;
        }
        printf("1");

    }
    return 0;
}