#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void yazdir(int A[4], int i)
{
	int j;
	for(j=0;j<i;j++)
	{
		printf("%2d",A[j]);
	}
	printf("\n");
	
}
int main() 
{
    int i = 0,j;
    int x;
    int A[4]={0};
    int r;
    srand(time(NULL));
    while(i<5)
    {
    	r=rand()%5;
    	j=0;
    	while(j<i&&A[j]!=r)
    	{
    		j++;
		}
		if(j==i)
		{
			A[i]=r;
			i++;
		}
		else printf("%d daha once eklendi \t",r);
    	yazdir(A,i);
	}
	return 0;
}

