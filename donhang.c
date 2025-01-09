#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct sanpham
{
    char maSP[50];
    char ten[1000];
    int cost;
} sanpham;


int main(){
    int N;
    int total = 0;
    scanf("%d",&N);
    sanpham ds[10];
    for (int i = 0; i < N; i++){
        scanf("%s",ds[i].maSP);
        getchar();
        fgets(ds[i].ten,1000,stdin);
        scanf("%d",&ds[i].cost);
        
    }
    while(1) {
        int kiemtra = 0;
        int tongtien = 0;
        char madonhang[50];
        
        scanf("%s",madonhang);
        if (madonhang[0] == '$') break;
        printf("%s\n",madonhang);
        int check = 0;
        int len = strlen(madonhang);
        for (int i = 0; i < len; i++){
            if (!((madonhang[i]>='A'&&madonhang[i]<='Z') || (madonhang[i]>='0' && madonhang[i]<='9'))) {
                check = 1;
                break;
            }
        }
        if (check == 1) continue;
        while(1) {
            kiemtra = 0;
            char maSP[50];
            scanf("%s",maSP);
            
            if (maSP[0] == '#') break;
            int soluong;
            scanf("%d",&soluong);
            for (int i = 0; i < N; i++){
                if (strcmp(maSP,ds[i].maSP) == 0){
                    tongtien += ds[i].cost * soluong;
                    kiemtra = 1;
                    break;
                }
            }
            if (kiemtra == 0) {
                tongtien = 0;
                break;
            }
        }
        total += tongtien;
    }
    printf("%d",total);
    return 0;
}