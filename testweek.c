#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct 
{
	char ten;
	int hp;
	int dam;
	int def;
} quanBai;
int daubai(quanBai a,quanBai b){
	while(1) {
		if ((a.dam <= b.def)&&(b.dam <= a.def)){
			printf("loi");
			return -1;
		}
		b.hp -= a.dam - b.def;
		if (b.hp <= 0) return 1;
		a.hp -= b.dam - a.def;
		if (a.hp <= 0) return 0;
	}
}
int doicho(quanBai *a, quanBai *b){
	quanBai temp = *a;
    *a = *b;
    *b = temp;
	return 0;
}
int main(){
	quanBai *Ene = (quanBai *)malloc(4*sizeof(quanBai));
	quanBai *Me = (quanBai *)malloc(4*sizeof(quanBai));
	for (int i = 0; i < 3; i++){
		scanf("%d%d%d",&Ene[i].hp,&Ene[i].dam,&Ene[i].def);
	}
	for (int i = 0; i < 3; i++){
		scanf(" %c%d%d%d",&Me[i].ten,&Me[i].hp,&Me[i].dam,&Me[i].def);
	}
	int change = 0;
	for (int i = 0; i < 3;i++) {
	    int count = 0;
		for (int j = 0; j < 3; j++){
		    if (daubai(Me[j],Ene[j]) == 1){
		        count++;
		    }
		}
	    if (count > 1) {
		    for (int k = 0; k < 3; k++){
		        printf("%c ",Me[k].ten);
	    	}
	    	return 0;
		}
    	else {
		    if (change == 0) {
		       doicho(&Me[1],&Me[2]);
		       change = 1;
		    }
		    else if (change == 1) {
		        doicho(&Me[0],&Me[2]);
		        change = 0;
		    }
	}
	
	}
	return 0;
}