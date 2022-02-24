#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	int n,dizi[100],link[100],enkckindis,lastindis=0,elemansayisi,indis,i;
	
		printf("dizilerin eleman sayisini giriniz:");
	    scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("dizinin %d. elemanini giriniz:",i+1);
		scanf("%d",&dizi[i]);
		
	if(i==0)
	{
		enkckindis=i;
		link[0]=-1;
	}
	else
	{
	if(dizi[enkckindis]>=dizi[i])
	{
		link[i]=enkckindis;
		enkckindis=i;
	}
	else
	{
		indis=enkckindis;
		while(indis!=-1 && dizi[indis]<dizi[i])
		{
			lastindis=indis;
			indis=link[indis];
		}

		link[i]=indis;
		link[lastindis]=i;
	}
	}
	}
	
	
	
	for(i=0;i<n;i++)
		{
			printf("%d\t",dizi[i]);
			
			
			
			
		}
		printf("\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",link[i]);
			
			
			
		}
	
	return 0;
}
