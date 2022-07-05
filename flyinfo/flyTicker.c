#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct ucus{
  int ucusKodu;
  char kalkisSehri[30];
  char varisSehri[30];
  char saat[30];
  int hatBilgisi;
  int pistNo;
  struct ucus *next;
}UCUS;

int main()
{
	UCUS *head=NULL;
	UCUS *tmp,*prev=NULL;
	int used[30]={0};
	FILE *fp;	
	fp = fopen("ucusBilgi.txt","r");
	if(fp==NULL){
		printf("Not found");
		return 0;
	}
	
    UCUS *ucus;
	ucus = (UCUS*)malloc(sizeof(UCUS));
	while(fscanf(fp,"%d %s %s %s %d %d\n",&ucus->ucusKodu,ucus->kalkisSehri,ucus->varisSehri,ucus->saat,&ucus->hatBilgisi,&ucus->pistNo)!=EOF)
	{
	    UCUS *yeniUcus=(UCUS*)malloc(sizeof(UCUS));
	    yeniUcus->ucusKodu=ucus->ucusKodu;
	    strcpy(yeniUcus->kalkisSehri,ucus->kalkisSehri);
	    strcpy(yeniUcus->varisSehri,ucus->varisSehri);
	    strcpy(yeniUcus->saat,ucus->saat);
	    yeniUcus->hatBilgisi=ucus->hatBilgisi;
	    yeniUcus->pistNo=ucus->pistNo;
	    yeniUcus->next=NULL;
	    
	
	    if(head==NULL) head=yeniUcus;
	    else{
		    tmp=head;
		    while(tmp!=NULL && yeniUcus->ucusKodu>tmp->ucusKodu){
			    prev=tmp;
			    tmp=tmp->next;
		    }
		    if(prev==NULL){
			    head=yeniUcus;
			    head->next=tmp;
		    }
		    else if(tmp==NULL){
			    prev->next=yeniUcus;
			    yeniUcus->next=NULL;
		    }
		    else{
			    prev->next=yeniUcus;
			    yeniUcus->next=tmp;
		    }
	    }
		ucus = (UCUS*)malloc(sizeof(UCUS));
	
	}
	    char bf[50];
	    
		tmp=head;
		while(tmp!=NULL){
			printf("%d %s %s %s %d %d\n",tmp->ucusKodu,tmp->kalkisSehri,tmp->varisSehri,tmp->saat,tmp->hatBilgisi,tmp->pistNo);			
            tmp=tmp->next;		
		}
		FILE *fp1;
		tmp=head;
		
		
		while(tmp!=NULL){
			if(used[tmp->pistNo]==0){
			char dosya[50]="pist";	
			itoa(tmp->pistNo,bf,10);
			strcat(dosya,bf);
			strcat(dosya,".txt");
			fp1=fopen(dosya,"w");
			fprintf(fp1,"%d %s %s %s %d %d\n",tmp->ucusKodu,tmp->kalkisSehri,tmp->varisSehri,tmp->saat,tmp->hatBilgisi,tmp->pistNo);
			used[tmp->pistNo]=1;			
            tmp=tmp->next;	
			}
			else{
			char dosya[50]="pist";	
			itoa(tmp->pistNo,bf,10);
			strcat(dosya,bf);
			strcat(dosya,".txt");
			fp1=fopen(dosya,"a");
			fprintf(fp1,"%d %s %s %s %d %d\n",tmp->ucusKodu,tmp->kalkisSehri,tmp->varisSehri,tmp->saat,tmp->hatBilgisi,tmp->pistNo);		
            tmp=tmp->next;		
			}
	
		}
		
						
	
	
	fclose(fp);
    
    
	
	return 0;
}
