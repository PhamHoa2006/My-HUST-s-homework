#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int kiemtra(char matrix[100][100],int a,int b, char *str,int len,int N,int M){
    
    int k = 0;
    int hang = a, cot = b;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++){
            a = hang;
            b = cot;
            k = 0;
            while(a >= 0 && a < N && b >= 0 && b < M && matrix[a][b] == *(str + k)) {
                if (k == len-1) {
                    for(int z = 0; z < len; z++){
                        printf("%c",str[z]);
                    }
                    printf(" %d %d %d %d\n",hang,cot,i,j);
                    return 0;
                }
                k++;
                a+=i;
                b+=j;
                
            }
        }
    }
    return 1;
}


int main() {
    int N, M;
    scanf("%d%d",&N,&M);
    char matrix[100][100];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) {
                scanf(" %c",&matrix[i][j]);
        }
    }
    
    char *str = (char *)malloc(10000*sizeof(char));
    while (1) {
        scanf("%s",str);
        if (*str == '#') break;
        else if (*str == '\n') continue;
        else {
            int dem = 0;
            int len = strlen(str);
            if (str[len-1] == '\n') {
                str[len-1] = '\0';
                len--;
            }
            
            for (int i = 0; i < N; i++){
                for (int j = 0; j < M; j++) {
                    if (kiemtra(matrix,i,j,str,len,N,M) != 1) {
                        dem = 1;
                        break;
                        }
                }
                if (dem == 1) break;
            }
            if (dem == 0) {
                for(int z = 0; z < len; z++){
                        printf("%c",str[z]);
                    }
                printf(" -1\n");

            }
        }
    }
    free(str);
    return 0;
}