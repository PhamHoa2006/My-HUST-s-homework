#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct thuexe
{
    char time1[20];
    char time2[20];
    int hh1,mm1;
    int hh2,mm2;
    int songuoi;
    int bike;
    

} thuexe ; 

int comparetime(int hh1, int mm1, int hh2, int mm2){
    int total1 = hh1 * 60 + mm1;
    int total2 = hh2 * 60 + mm2;
    if (total2 > total1) return 1;
    else if (total2 < total1) return -1;
    else if (total2 == total1) return 0;
}

int main(){
    thuexe ds[1000];
    int dem = 0;
    while(1){
        scanf("%s",ds[dem].time1);
        if (ds[dem].time1[0] == '$') {
            break;
        }
        scanf("%s",ds[dem].time2);
        sscanf(ds[dem].time1,"%d:%d",&ds[dem].hh1,&ds[dem].mm1);
        sscanf(ds[dem].time2,"%d:%d",&ds[dem].hh2,&ds[dem].mm2);
        scanf("%d",&ds[dem].songuoi);
        ds[dem].bike = 0;
        
        dem++;
    }
    int max = 0;
    
    for (int i = 0; i < dem; i++){
        int maxdau = 0;
        int maxduoi = 0;
        for (int j = 0; j < dem; j++){
            if (comparetime(ds[i].hh1,ds[i].mm1, ds[j].hh2,ds[j].mm2) > 0 && comparetime(ds[i].hh1,ds[i].mm1, ds[j].hh1, ds[j].mm1) <= 0){
                maxdau += ds[j].songuoi/2 + ds[j].songuoi%2;
            }
            if (comparetime(ds[i].hh2,ds[i].mm2, ds[j].hh2,ds[j].mm2) >= 0 && comparetime(ds[i].hh2,ds[i].mm2, ds[j].hh1, ds[j].mm1) < 0){
                maxduoi += ds[j].songuoi/2 + ds[j].songuoi%2;
            }
            if (max < maxdau) max = maxdau;
            if (max < maxduoi) max = maxduoi;
            
        }
    }

    printf("%d",max);
    return 0;
}