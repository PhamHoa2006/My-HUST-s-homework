#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct {
	int vitri ;
	int nhietdo ;
	int hh, mm,ss;
} data;
int main() {
	int tem, delta;
	int cool = 0, stable = 0;
	scanf("%d%d",&tem,&delta);
	int i = 0;
	data *ptr = (data *)malloc(10000000*sizeof(data));
	while(1) {
		ptr[i].vitri = -1;
		scanf("%d",&ptr[i].vitri);
		if (ptr[i].vitri == -1) {
			break;
		}
		scanf("%d",&ptr[i].nhietdo);
		scanf("%d:%d:%d",&ptr[i].hh,&ptr[i].mm,&ptr[i].ss);
		i++;
	}
	int mang[1001][10000] = {0};
	for (int j = 0; j < i; j++) {
		int k = 2;
		mang[ptr[j].vitri][0] ++;
		mang[ptr[j].vitri][1] += ptr[j].nhietdo;
		while (mang[ptr[j].vitri][k] != 0) k++;
		mang[ptr[j].vitri][k] = ptr[j].nhietdo;
		
		}
	for (int j = 0; j < 1001; j++) {
		double dolechchuan = 0;
		double tong = 0;
		if (mang[j][0] != 0) {
			double ave = (double)mang[j][1]/(double)mang[j][0];
            if (ave <= tem) cool++;
			if (mang[j][0] == 1) stable++;
			else{
			for (int lap = 2; lap < mang[j][0]+2; lap++) {
					tong += (ave - mang[j][lap])*(ave - mang[j][lap]);
        	}
			dolechchuan = sqrt(tong/(double)mang[j][0]);
			if (dolechchuan <= delta) stable++;
			}
		}
	}
    printf("%d %d",cool,stable);
	free(ptr);
	ptr = NULL;
    return 0;
}
