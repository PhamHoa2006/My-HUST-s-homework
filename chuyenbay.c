#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct chuyenbay
{
    int hh,mm;
    char diemden[1000];
    char code[1000];
    char nhaga[10];
} chuyenbay;
int comparetime(int hh1, int mm1, int hh2, int mm2){
    int total1 = hh1 * 60 + mm1;
    int total2 = hh2 * 60 + mm2;
    if (total2 > total1) return 1;
    else if (total2 < total1) return -1;
    else if (total2 == total1) return 0;
}
int main(){
    int check = 0;
    chuyenbay ds[1000];
    int dem = 0;
    while(1) {
        char str[1000];

        fgets(str,1000,stdin);
        str[strcspn(str, "\r\n")] = '\0';
        if (str[0] == '#') break;

        char *tachxau;
        tachxau = strtok(str,";");
        sscanf(tachxau,"%d:%d",&ds[dem].hh,&ds[dem].mm);
        tachxau = strtok(NULL,";");
        strcpy(ds[dem].diemden,tachxau);
        tachxau = strtok(NULL,";");
        strcpy(ds[dem].code,tachxau);
        tachxau = strtok(NULL,";");
        strcpy(ds[dem].nhaga,tachxau);
        tachxau = strtok(NULL,";");
        dem++;
    }
    int N;
    scanf("%d",&N);
    if ( N == 1) {
        char maso[1000];
        scanf("%s",maso);
        for (int i = 0; i < dem; i++){
            if (strcmp(maso,ds[i].code) == 0){
                printf("%02d:%02d %s\n",ds[i].hh,ds[i].mm,ds[i].nhaga);
                check = 1;
            }
        }
    }
    else if ( N == 2 ) {
        int hh2,mm2;
        char diemden[1000];
        scanf("%d:%d",&hh2,&mm2);
        getchar();
        fgets(diemden,1000,stdin);
        diemden[strcspn(diemden, "\n")] = '\0';
        for (int i = 0; i < dem; i++){
            if (comparetime(ds[i].hh,ds[i].mm,hh2,mm2) != 1 && strstr(ds[i].diemden,diemden) != 0){
                printf("%02d:%02d %s %s %s\n", ds[i].hh,ds[i].mm, ds[i].diemden, ds[i].code, ds[i].nhaga);
                check = 1;
            }
        }

    }
    if (check == 0) printf("-1");
    return 0;
}