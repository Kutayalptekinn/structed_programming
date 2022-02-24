#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "macro.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	
	int i,j,a[50],min,k,x,y;
	printf("enter initial population\n");
	
	for(i=0;i<PopulationSize;i++)
	{
		
	x=rand() % 50 + 1;
	a[i]=x;
	}
	printf("population:\t");
	for(i=0;i<PopulationSize;i++)
	{
		
	printf("%d\t",a[i]);	
	}
	printf("\n");
	min=a[0];
	for(i=0;i<PopulationSize;i++)
	{
	if(a[i]<min)
	 { 
		min=a[i];
     }	
	}
	printf("initial best cost: %d value\n",COST(min));
	
	
	printf("iterations start...\n");
	
	
	for(k=0;k<IterationNumber;k++)
	{
		
		printf("iteration-%d new population\n",k+1);
		for(j=0;j<PopulationSize;j++)
		{
			
			y=rand() % 50 + 1;
	        a[j]=y;
	        
	        
		}
		printf("population:\t");
		for(j=0;j<PopulationSize;j++)
		{
		//	printf("iteration-%d new population",i+1);
			printf("%d\t",a[j]);
			
		}
		printf("\n");
		min=a[0];
	  for(i=0;i<PopulationSize;i++)
	 {
	    if(a[i]<min)
	   { 
		min=a[i];
       }	
     }
	printf("initial cost in iteration-%d: %d value\n",k+1,COST(min));
	 
	}
	
	
	
	
	
	
	return 0;
}
