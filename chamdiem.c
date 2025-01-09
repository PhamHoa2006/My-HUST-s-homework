#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct chamdiem
{
    char maSV[17];
    char baithi[250];
    int diem;
    int testcase;
    int count;
    int max;

} chamdiem;
// tao mang luu thu tu

int main(){
    chamdiem ds[2000];
    chamdiem nhap[2000];
    int dem = 0;
    int k = 0;
    while(1){
        scanf("%s",ds[dem].maSV);
        if (ds[dem].maSV[0] == '#') break;
        ds[dem].count = 1;
        scanf("%s",ds[dem].baithi);
        scanf("%d",&ds[dem].diem);
        scanf("%d",&ds[dem].testcase);
        strcpy(nhap[k].maSV,ds[dem].maSV);
        strcpy(nhap[k].baithi,ds[dem].baithi);
        nhap[k].diem = ds[dem].diem;
        nhap[k].testcase = ds[dem].testcase;
        k++;
        for (int i = 0; i < dem; i++) {
            if (strcmp(ds[dem].maSV,ds[i].maSV) == 0 && strcmp(ds[dem].baithi,ds[i].baithi) == 0 ) {
                if (ds[i].count < 10) {
                    if (ds[dem].diem > ds[i].diem) {
                        ds[i].diem = ds[dem].diem;
                    }
                    if (ds[dem].diem = ds[dem].testcase) ds[dem].max++;
                    
                    
                }
                ds[i].count++;
                dem--;
            }
        }
        dem++;
    }
    int N; // yeu cau tuwf 1 den 4
    scanf("%d",&N);
    if (N == 1) {
        for (int i = 0; i < dem; i++){
            int j = 0;
            while ( j < i && i < dem ) {
                if (strcmp(ds[i].maSV,ds[j].maSV) == 0) {
                    i++;
                    j = 0;
                }
                else j++;
            }
            if (i >= dem) break;
            printf("%s\n",ds[i].maSV);
        }
    }
    else if (N == 2) {
        int idk;
        char *sortlist = (char *)malloc(dem * sizeof(int));
        for (int i = 0; i < dem; i ++){
            sortlist[i] = i;
        }
        for (int i = 0; i < dem; i++) {
            for (int j = i+1; j < dem; j++){
                if (strcmp(ds[sortlist[i]].maSV,ds[sortlist[j]].maSV) > 0) {
                    idk = sortlist[i];
                    sortlist[i] = sortlist[j];
                    sortlist[j] = idk;
                }
                else if (strcmp(ds[sortlist[i]].maSV,ds[sortlist[j]].maSV) == 0 &&strcmp(ds[sortlist[i]].baithi, ds[sortlist[j]].baithi) > 0){
                    idk = sortlist[i];
                    sortlist[i] = sortlist[j];
                    sortlist[j] = idk;
                }
            }
        }
        for (int i = 0; i < dem; i++){
            printf("%s ",ds[sortlist[i]].maSV);
            printf("%s:%d ",ds[sortlist[i]].baithi,ds[sortlist[i]].count);
            while (strcmp(ds[sortlist[i]].maSV, ds[sortlist[i+1]].maSV) == 0) {
                printf("%s:%d ",ds[sortlist[i+1]].baithi,ds[sortlist[i+1]].count);
                i++;
            }
            printf("\n");
        }
        free(sortlist);
    }
    else if (N == 3) {
        int idk;
        char *sortlist = (char *)malloc(dem * sizeof(int));
        for (int i = 0; i < dem; i ++){
            sortlist[i] = i;
        }
        for (int i = 0; i < dem; i++) {
            for (int j = i+1; j < dem; j++){
                if (strcmp(ds[sortlist[i]].maSV,ds[sortlist[j]].maSV) > 0) {
                    idk = sortlist[i];
                    sortlist[i] = sortlist[j];
                    sortlist[j] = idk;
                }
            }
        }
        for (int i = 0; i < dem; i++){
            int diem = 0;
            printf("%s ",ds[sortlist[i]].maSV);
            diem += ds[sortlist[i]].diem;
            while (strcmp(ds[sortlist[i]].maSV, ds[sortlist[i+1]].maSV) == 0) {
                diem += ds[sortlist[i+1]].diem;
                i++;
            }
            printf("%d\n",diem);
        }
        free(sortlist);
    }
    else if (N == 4){
        int max = -1;
        int min = 1000;
        int countnhap = 0;
        int countP = 0;
        char tenbai[1000];
        scanf("%s",tenbai);
        for (int i = 0; i < k; i++){
            if (strcmp(tenbai,nhap[i].baithi) == 0){
                if (max < nhap[i].diem) max = nhap[i].diem;
                if (min > nhap[i].diem) min = nhap[i].diem;
            }
        }
        for (int i = 0; i < dem; i++){
            if (strcmp(tenbai,ds[i].baithi) == 0){
                countnhap+= ds[i].count;
                if (ds[i].diem == ds[i].testcase){
                    countP+=ds[i].max;
                }
            }
            else continue;
        }
        double tile = ((double)countP/(double)countnhap)*100; 
        printf("%d %d %.2lf",max,min,tile );
    }

    return 0;
}
