#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct aracBilgisi{
	char model[50];
	int yil;
	int satisFiyati;
	int adet;	
}ARACBILGISI;

void InsertCar(ARACBILGISI **araclar,int count);
void SortAscendent(ARACBILGISI **araclar,int count);
void SortDescendent(ARACBILGISI **araclar,int count);
void Print(ARACBILGISI **araclar,int count);

int main(int argc, char *argv[]) 
{
	ARACBILGISI *araclar;
	int choice,chc,loop=1;
	int count=3;
	araclar=(ARACBILGISI*)malloc(count*sizeof(ARACBILGISI));

	araclar[0].adet=3;
	araclar[0].satisFiyati=300;
	araclar[0].yil=2000;
	strcpy(araclar[0].model,"fiat");
	
	araclar[1].adet=4;
	araclar[1].satisFiyati=200;
	araclar[1].yil=2001;
	strcpy(araclar[1].model,"mercedes");
	
	araclar[2].adet=5;
	araclar[2].satisFiyati=500;
	araclar[2].yil=1998;
	strcpy(araclar[2].model,"bmw");

   while(loop==1)
   {
   	 printf("Arac eklemek icin 1, var olan listeyle devam etmek icin 2 cikmak icin 3 giriniz...\n");
    scanf("%d",&choice);
    
    if(choice==1)
    {
    	count++;
    	InsertCar(&araclar,count);
	}
	else if(choice==2)
	{
		printf("artan siralama icin 1 azalan icin 2 giriniz:\n");
		scanf("%d",&chc);
		if(chc==1)
		{
		  SortDescendent(&araclar,count);
		  Print(&araclar,count);
        }	
        else if(chc==2)
    	{
         SortAscendent(&araclar,count);
         Print(&araclar,count);
    	}
	}
	else if(choice==3)
	{
		loop=0;
	}
	else{
		printf("tekrar dene\n");
	}
		
	
	
   }
   
	Print(&araclar,count);
	free(araclar);
	return 0;
}


void SortAscendent(ARACBILGISI **araclar,int count)
{
	ARACBILGISI **tmp;
	int i,j;
	for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
           	if (strcmp((*araclar)[j].model,(*araclar)[j+1].model)>0)
           	{
        	**tmp=(*araclar)[j];
             (*araclar)[j]=(*araclar)[j+1];
           	(*araclar)[j+1]=**tmp;
			}
		}
    }
			 
}

void SortDescendent(ARACBILGISI **araclar,int count)
{
	ARACBILGISI **tmp;
	ARACBILGISI *tmp1;
	tmp1=*araclar;
	int i,j;
	for (i = 0; i < count - 1; i++)
        {
         for (j = 0; j < count - i - 1; j++)
         {
       	   if (strcmp(tmp1[j].model,tmp1[j+1].model)<0)
           {
             **tmp=tmp1[j];
             (*araclar)[j]=tmp1[j+1];
           	tmp1[j+1]=**tmp;
	    	}
		  }
		
		}
		araclar=&tmp1;	
}

void Print(ARACBILGISI **araclar,int count)
{
	int i;
	for(i=0;i<count;i++)
    {
	printf("adet: %d\n",(*araclar)[i].adet);
	printf("satis fiyati: %d\n",(*araclar)[i].satisFiyati);
    printf("yil: %d\n",(*araclar)[i].yil);
	printf("model: %s\n",(*araclar)[i].model);
	printf("\n");
	printf("\n");
    }
    
}

void InsertCar(ARACBILGISI **araclar,int count)
{
   	printf("eklemek istediginiz arac bilgilerini giriniz:\n");

	(*araclar)=(ARACBILGISI*)realloc((*araclar),count*sizeof(ARACBILGISI));
	printf("satis fiyati:");
    scanf("%d",&(*araclar)[count-1].satisFiyati);
	printf("model:");
    scanf("%s",&(*araclar)[count-1].model);
    printf("yil:");
    scanf("%d",&(*araclar)[count-1].yil);
    printf("adet:");
    scanf("%d",&(*araclar)[count-1].adet);;
}
