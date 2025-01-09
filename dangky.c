#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct dangky
{
    char time1[50];
    char time2[50];
    char phong[50];
    int hh1,mm1;
    int hh2,mm2;
} dangky;
//danh sách nhập vào
typedef struct wait
{
    char yeucau[50];
    int maNV;
    int hh1,mm1;
    int hh2,mm2;
} wait;
//danh sách đợi mượn phòng
int comparetime(int hh1, int mm1, int hh2, int mm2){
    int total1 = hh1 * 60 + mm1;
    int total2 = hh2 * 60 + mm2;
    if (total2 > total1) return 1;
    else if (total2 < total1) return -1;
    else if (total2 == total1) return 0;
}
//so sánh thời gian
int main(){
    int N;
    scanf("%d",&N);
    char danhsach[100][50];
    dangky ds[1000];
    int dem = 0;

    for (int i = 0; i < N; i++){
        scanf("%s",danhsach[i]);
        getchar();
    }
    while(1){
        scanf("%s",ds[dem].time1);
        if (ds[dem].time1[0] == '$') {
            getchar();
            break;
        }
        scanf("%s",ds[dem].time2);
        scanf("%s",ds[dem].phong);
        getchar();
        sscanf(ds[dem].time1,"%02d:%02d",&ds[dem].hh1,&ds[dem].mm1);
        sscanf(ds[dem].time2,"%02d:%02d",&ds[dem].hh2,&ds[dem].mm2);
        dem++;
    }
    // đã nhập xong danh sách = 1 cách nào đó
    // ở dưới éo muốn đọc nữa đâu :(((
    // Ngủ
    wait ds2[1000];
    int k = 0;
    while(1){
        int check = 0;
        int vt1 = 0;
        int vt2 = 0;
        scanf("%s",ds2[k].yeucau);
        if (ds2[k].yeucau[0] == '$') break;
        scanf("%d",&ds2[k].maNV);
        scanf("%d:%d",&ds2[k].hh1, &ds2[k].mm1);
        scanf("%d:%d",&ds2[k].hh2,&ds2[k].mm2);
        getchar();
        if (strcmp(ds2[k].yeucau,"?query")!= 0) continue;
        for (int i = 0; i < N; i++) {
            check = 0;
            for (int j = 0; j < dem; j++){
                if (strcmp(ds[j].phong,danhsach[i]) == 0){
                    if (comparetime(ds2[k].hh1,ds2[k].mm1,  ds[j].hh1,ds[j].mm1) == 0) check = -1;
                    else if (comparetime(ds2[k].hh1,ds2[k].mm1,  ds[j].hh1,ds[j].mm1) == 1) {
                        if (comparetime(ds2[k].hh2,ds2[k].mm2,  ds[j].hh1,ds[j].mm1) == 1){
                            vt1 = i;
                            vt2 = j;
                        }
                        else check = -1;
                    }
                    else if (comparetime(ds2[k].hh1,ds2[k].mm1,  ds[j].hh1,ds[j].mm1) == -1) {
                        if (comparetime(ds2[k].hh1,ds2[k].mm1,  ds[j].hh2,ds[j].mm2) == -1) {
                            vt1 = i;
                            vt2 = j;
                        }
                        else check = -1;
                    }
                }
            }
            if (check == -1) continue;
            else if (check == 0) {
                printf("%s\n",danhsach[i]);
                
                ds[dem].hh1 = ds2[k].hh1;
                ds[dem].hh2 = ds2[k].hh2;
                ds[dem].mm1 = ds2[k].mm1;
                ds[dem].mm2 = ds2[k].mm2;
                strcpy(ds[dem].phong,danhsach[i]);
                dem++;
                break;
            }
        }
        if (check != 0) printf("-1\n");
        k++;
        
    }
    return 0;
}