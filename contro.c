#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    double x1, y1, r1;
} conCa;
int main() {
    conCa* ptr = (conCa *)malloc(10000*sizeof(conCa));
    int n;
    double r;
    scanf("%d",&n);
    int count[100]={0};
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf",&ptr[i].x1,&ptr[i].y1,&ptr[i].r1);
    }
    scanf("%lf",&r);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sqrt((ptr[i].x1-ptr[j].x1)*(ptr[i].x1-ptr[j].x1)+(ptr[i].y1-ptr[j].y1)*(ptr[i].y1-ptr[j].y1))+ptr[j].r1<=r) {
                count[i]++;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < count[i]) max = count[i];
    }
    printf("%d",max);
    return 0;
}