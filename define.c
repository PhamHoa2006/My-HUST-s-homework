#include <stdio.h>
#include <string.h>

long long main() {
    char bieuThuc[1000000];
    scanf("%s",bieuThuc);
    long long ketQua = 0;
    long long countBug = 0;
    long long tich = 1;
    long long lenStr = strlen(bieuThuc)-1;
    if (bieuThuc[0]>'9'||bieuThuc[0]<='0'||bieuThuc[lenStr]<'0'||bieuThuc[lenStr]>'9') {
        printf("NOT_CORRECT");
        return 0;
    }
    for (long long i = lenStr; i >= 0; i--) {
        long long hang = 1;
        long long so = 0;
        while (bieuThuc[i]<='9'&&bieuThuc[i]>='0') {
            countBug = 0;
            so += (bieuThuc[i] - '0')*hang;
            hang *= 10;
            i--;
            if (i<0) {
                ketQua += tich*so;
                printf("%lld",ketQua);
                return 0;
            }
        }
        
        if (bieuThuc[i]<'0'||bieuThuc[i]>'9') {
            countBug++;
            if (countBug>1) {
                printf("NOT_CORRECT");
                return 0;
            }
        }

        if (bieuThuc[i] == '*') {
            tich *= so;
        }
         if (bieuThuc[i] == '+') {
            ketQua += tich*so;
            tich = 1;
        }
    }
}