#include <stdio.h>
#include <stdlib.h>
#include<time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	
	int n,i,j,toplam=0,toplam2=0,toplam3=0;
	
	int **a;
	
	printf("Enter matris size:\n");
	scanf("%d",&n);
	
	a=(int**)malloc(n*sizeof(int*));
	
	for(i=0;i<n;i++)
	{
		a[i]=(int*)malloc(n*sizeof(int));
	}
	    
	    
	
	for(i=0;i<n;i++)
	{  
	    for(j=0;j<n;j++)
		{
			a[i][j]=(rand() % 100)+1;
		}
	}
	
     a=(int**)realloc(a,(n+1)*sizeof(int*));
     a[n]=(int*)malloc(sizeof(int));
     for(i=0;i<n;i++)
	{
		a[i]=(int*)realloc(a[i],(n+1)*sizeof(int));
	}

    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
		{
		    toplam=toplam+a[i][j];
		}
		a[i][j]=toplam;
		toplam3=toplam3+toplam;
		toplam=0;
	}
	
	for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
		{
		    toplam2=toplam2+a[j][i];
		}
		a[j][i]=toplam2;
		toplam3=toplam3+toplam2;
		toplam2=0;
	}
	a[n][n]=toplam3;
	
	for(i=0;i<n+1;i++)
    {
    	for(j=0;j<n+1;j++)
		{
		    printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	   
                for(j=0;j<n+1;j++)
                {
                	free(a[j]);
                }
                free(a);
	
	return 0;
}
