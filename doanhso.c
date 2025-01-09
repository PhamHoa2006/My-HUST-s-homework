#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct sanpham
{
    char maSP[50];
    char ten[1000];
    int cost;
    int soluong;
} sanpham;


int main(){
    int N;
    int total = 0;
    scanf("%d",&N);
    sanpham ds[10];
    for (int i = 0; i < N; i++){
        ds[i].soluong = 0;
        scanf("%s",ds[i].maSP);
        getchar();
        fgets(ds[i].ten,1000,stdin);
        ds[i].ten[strcspn(ds[i].ten, "\n")] = '\0';
        scanf("%d",&ds[i].cost);
        
    }
    while(1) {
        int kiemtra = 0;
        int dem = 0;
        char madonhang[50];
        char maSP[50][50] ;
        int soluong[50];
        scanf("%s",madonhang);
        if (madonhang[0] == '$') break;
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
            
            scanf("%s",maSP[dem]);
            if (maSP[dem][0] == '#') break;
            
            scanf("%d",&soluong[dem]);
            kiemtra = 0;
            for (int i = 0; i < N; i++){
                if (strcmp(maSP[dem],ds[i].maSP) == 0){
                    
                    kiemtra = 1;
                }
            }
            dem++;
            if (kiemtra == 0) {
                dem = 0;
                break;
            }
        }
        if (kiemtra != 0) {
            for (int j = 0; j < dem; j++){
                for (int i = 0; i < N; i++){
                    if (strcmp(maSP[j],ds[i].maSP) == 0){
                        ds[i].soluong += soluong[j] ;
                        break;
                    }
            }
            }
        }
    }
    for (int i = 0; i < N; i++){
        if (ds[i].soluong != 0){
            printf("%s: %d\n",ds[i].ten,ds[i].soluong);
        }
        
    }
    
    return 0;
}