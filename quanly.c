#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct quanly
{
    char datetime[100];
    int hh,pp,ss;
    long long CCCD;
    char behavior;
} quanly;

int main(){
    quanly danhsach[1000];
    int dem = 0;
    int i = 0;
    while(1) {
        
        scanf("%s",danhsach[i].datetime);
        if (danhsach[i].datetime[0] == '$') break;

        scanf("%d:%d:%d",&danhsach[i].hh,&danhsach[i].pp,&danhsach[i].ss);
        scanf("%lld",&danhsach[i].CCCD);
        getchar();
        scanf("%c",&danhsach[i].behavior);
        getchar();
        if (danhsach[i].behavior == 'M') {
            for (int j = 0; j < i; j++) {
                if (danhsach[i].CCCD == danhsach[j].CCCD) {
                   danhsach[i].CCCD = 0;
                   i--;
                   break;
                }
            }
        }
        else if (danhsach[i].behavior == 'T') {
            for (int j = 0; j < i; j++){
                if (danhsach[i].CCCD == danhsach[j].CCCD) {
                    danhsach[j].CCCD = 0;
                    i--;
                }
            }
        }
        i++;
    }
    for (int k = 0; k < i; k++){
        if (danhsach[k].CCCD != 0) dem++;
    }
    printf("The number of devices currently being borrowed: %d\n",dem);
    for (int k = 0; k < i; k++){
        if (danhsach[k].CCCD != 0) {
            printf("%s %02d:%02d:%02d %012lld\n",danhsach[k].datetime,danhsach[k].hh,danhsach[k].pp,danhsach[k].ss,danhsach[k].CCCD);
        }
    }
    return 0;
}