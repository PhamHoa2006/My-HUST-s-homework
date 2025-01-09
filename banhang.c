#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct store
{
    long long CCCD;
    char buy;
    char soLuong[50];
    int luong ;
    int chi ;
} banhang;

int changeNum(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else return 0;
}
int main(){
    int N;
    scanf("%d",&N);

    int totalLm = 0;
    int totalCm = 0;
    int totalLb = 0;
    int totalCb = 0;
    banhang history[10000];
    for (int i = 0; i < N; i++) {
        scanf("%lld",&history[i].CCCD);
        getchar();
        scanf("%c",&history[i].buy);
        scanf("%s",history[i].soLuong);
        history[i].luong = 0;
        history[i].chi = 0;
        int len = strlen(history[i].soLuong);
        int vitriL = 0;
        int num = 0;
        for (int j = 0; j < len; j++) {
            if (history[i].soLuong[j] >= '0' && history[i].soLuong[j] <= '9') {
                num = num * 10 + changeNum(history[i].soLuong[j]);
            } else if (history[i].soLuong[j] == 'L') {
                history[i].luong += num;
                num = 0;
            } else if (history[i].soLuong[j] == 'C') {
                history[i].chi += num;
                num = 0;
            }
        }
        for (int j = 0; j < i; j++) {
            if (history[i].CCCD == history[j].CCCD && history[i].buy == history[j].buy) {
                history[j].luong += history[i].luong;
                history[j].chi += history[i].chi;
                i--;
                N--;
                break;
            }
        }
    }
    int maxLm = 0, maxLb = 0;
    int maxCm = 0, maxCb = 0;
    int TopBuy = 0;
    int TopSell = 0;
    for (int i = 0; i < N; i++){
        if (history[i].buy == 'M'){
            totalLm += history[i].luong;
            totalCm += history[i].chi;
            if (maxLm < history[i].luong) {
                TopBuy = i;
                maxLm = history[i].luong;
                maxCm = history[i].chi;
            }
            else if (maxLm == history[i].luong && maxCm < history[i].chi){
                TopBuy = i;
                maxLm = history[i].luong;
                maxCm = history[i].chi;
            }
            

        }
        else if (history[i].buy == 'B'){
            totalLb += history[i].luong;
            totalCb += history[i].chi;
            if (maxLb < history[i].luong) {
                TopSell = i;
                maxLb = history[i].luong;
                maxCb = history[i].chi;
            }
            else if (maxLb == history[i].luong && maxCb < history[i].chi){
                TopSell = i;
                maxLb = history[i].luong;
                maxCb = history[i].chi;
            }
        }

    }
    if (totalLm == 0) {
        if (totalCm == 0) printf("Total Buy:\n");
        else printf("Total Buy: %dC\n",totalCm);
        }
    else  {
        if (totalCm == 0) printf("Total Buy: %dL\n",totalLm);
        else printf("Total Buy: %dL%dC\n",totalLm,totalCm);
    }
    if (totalLb == 0) {
        if (totalCb == 0) printf("Total Sell:\n");
        else printf("Total Sell: %dC\n",totalCb);
        }
    else  {
        if (totalCb == 0) printf("Total Sell: %dL\n",totalLb);
        else printf("Total Sell: %dL%dC\n",totalLb,totalCb);
    }


    if (maxLm == 0) {
        if (maxCm == 0) printf("Top Buyer:\n");
        else printf("Top Buyer: %012lld %dC\n",history[TopBuy].CCCD,maxCm);
    }
    else {
        if (maxCm == 0) printf("Top Buyer: %012lld %dL\n",history[TopBuy].CCCD,maxLm);
        else printf("Top Buyer: %012lld %dL%dC\n",history[TopBuy].CCCD,maxLm,maxCm);
    }
    if (maxLb == 0) {
        if (maxCb == 0) printf("Top Seller:\n");
        else printf("Top Seller: %012lld %dC\n",history[TopSell].CCCD,maxCb);
    }
    else {
        if (maxCb == 0) printf("Top Seller: %012lld %dL\n",history[TopSell].CCCD,maxLb);
        else printf("Top Seller: %012lld %dL%dC\n",history[TopSell].CCCD,maxLb,maxCb);
    }
    return 0;
}