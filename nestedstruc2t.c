#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int derece;
	double katsayi;
}TERIM;

typedef struct{
	TERIM *terimler;
	int terimsayisi;	
}POLINOM;

void polinomYaz(POLINOM p1);
void polinomYazv2(POLINOM *p1);
void polinomOku(POLINOM p1);
void polinomOkuv2(POLINOM *p1);

int main(){
	srand(time(NULL));
	int N;
	int i;
	POLINOM p1;
	POLINOM *p2;
	printf("Terim sayisi giriniz\n"); scanf("%d",&N);
	p1.terimsayisi=N;
	p1.terimler = (TERIM*)malloc(p1.terimsayisi*sizeof(TERIM));
	
	for(i=0;i<p1.terimsayisi;i++){
		p1.terimler[i].derece = i+1;
		p1.terimler[i].katsayi = rand() %5;
	}
	polinomYaz(p1);// call by value
    polinomOku(p1); // call by value içerdeki terimler isimli pointer yüzünden call by ref gibi çalisir
    polinomYaz(p1);
	
	p2 = &p1;
	
	polinomYazv2(p2); // call by ref
	polinomOkuv2(&p1); // call by ref
	
	polinomYazv2(p2);
		
}

void polinomYaz(POLINOM p1){
	int i;
	for(i=0;i<p1.terimsayisi-1;i++){
		printf("%2.1lf X ^ %d + ",p1.terimler[i].katsayi,p1.terimler[i].derece);
	}
	printf("%2.1lf X ^ %d\n",p1.terimler[i].katsayi,p1.terimler[i].derece);
}

void polinomYazv2(POLINOM *p1){
	int i;
    for(i=0;i<p1->terimsayisi-1;i++){
		printf("%2.1lf X ^ %d + ",p1->terimler[i].katsayi,p1->terimler[i].derece);
	}
	printf("%2.1lf X ^ %d\n",p1->terimler[i].katsayi,p1->terimler[i].derece);
}

void polinomOku(POLINOM p1){
	int i;
	for(i=0;i<p1.terimsayisi;i++){
		printf("%d. terimin katsayisi ve derecesi",i);
		scanf("%lf",&p1.terimler[i].katsayi);
		scanf("%d",&p1.terimler[i].derece);	
	}
}

void polinomOkuv2(POLINOM *p1){
	int i;
	printf("Terim sayisi giriniz"); 
	scanf("%d",&p1->terimsayisi);
	
	for(i=0;i<p1->terimsayisi;i++){
		printf("%d. terimin katsayisi ve derecesi",i);
		scanf("%lf",&p1->terimler[i].katsayi);
		scanf("%d",&p1->terimler[i].derece);	
	}
}
