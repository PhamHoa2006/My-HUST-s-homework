#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char str[100];
    fgets(str,100,stdin); //Nhap ten
    int len = strlen(str);
    char sapxep[100]; // sap xep lai ten theo thu tu 
    int k = 0;
    for (int j = 0; j < len; j++) {
            if (str[j]<= 'Z' && str[j] >= 'A'){
                sapxep[k] = str[j];
                k++;
            }
    } 
    for (int j = 0; j < len; j++) {
            if (str[j]<= 'z' && str[j] >= 'a'){
                sapxep[k] = str[j];
                k++;
            }
    }
    int date;
    scanf("%d",&date);
    char xaudacbiet[30] ;
    scanf("%s",xaudacbiet);
    int birth[8];
    for (int i = 7; i >= 0; i--) {
        birth[i] = date % 10;
        date /= 10;
    }
    int dodai;
    scanf("%d",&dodai);
    char matkhau[dodai+3]; // xau luu mat khau
    for (int i = 0; i < dodai; i++) {
        if (i % 2 == 0) {
            matkhau[i] = sapxep[i/2] ;
        }
        else {
            matkhau[i] = xaudacbiet[birth[i/2]];
        }
    }
    printf("Mat khau tao ra: ");
    for (int i = 0; i < dodai; i++){
        printf("%c",matkhau[i]);
    }
        

    return 0;
}