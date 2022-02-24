#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct ucus{
	int ID;
	char nereden[50];
	char nereye[50];
	char saat[20];
	int ic_dis;
	int kapi;
	int kullanildi;
	struct ucus *next;
}UCUS;
void printlist(UCUS * head){
	while(head!=NULL){
		printf("%d %s %s %s %d %d\n",head->ID,head->nereden,head->nereye,head->saat,head->ic_dis,head->kapi);
		head=head->next;
	}
}
UCUS * durum_oku(){
	FILE * fp;
	UCUS * head;
	UCUS* yeni;
	int a,b,c;
	head=NULL;	
	char nereden[50],nereye[50],saat[20];
	fp=fopen("ucusBilgi.txt","r");
	yeni=(UCUS*)malloc(sizeof(UCUS));
	yeni->next=NULL;
    while(fscanf(fp,"%d  %s %s %s %d %d ",&yeni->ID,nereden,nereye,saat,&yeni->ic_dis,&yeni->kapi)==6){
    strcpy(yeni->nereden,nereden);
    strcpy(yeni->nereye,nereye);
	strcpy(yeni->saat,saat);
	
	yeni->next=head;
	yeni->kullanildi=0;
	head=yeni;
	yeni=NULL;
	yeni=(UCUS*)malloc(sizeof(UCUS));
	yeni->next=NULL;	
	}
	free(yeni);
	return head;
}
void pist_yazdir(UCUS * head){
	FILE * fp;
	UCUS * headd;
	int deger=0;
	char dosya[30];
	int suanki;
	headd=head;
	while(head!=NULL){
		headd=head;
		suanki=head->kapi;
	if(head->kullanildi==0){
		itoa(headd->kapi,dosya,10);
		strcat(dosya,".pist.txt");
		fp=fopen(dosya,"w");
		deger=1;
	while(headd!=NULL ){
		if(headd->kapi==suanki){
		fprintf(fp,"%d %s %s %s %d %d\n",headd->ID,headd->nereden,headd->nereye,headd->saat,headd->ic_dis,headd->kapi);
		headd->kullanildi=1;}
		headd=headd->next;
	}}
	fclose(fp);
	deger=0;
	head=head->next;
}
	
	
}
int main()
{
	FILE * fp;
	UCUS * head;
    int i,j;
	  head=durum_oku();
	  printlist(head);
	  pist_yazdir(head);
    return 0;
}
