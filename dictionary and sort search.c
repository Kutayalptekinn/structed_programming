#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{ 
        int i,a,b,m,h,x,z,v,g,u,n,temp,tmp;
         int j = 0, k = 0, l = 0, s = 0;
    char look[50];
    char word[50][50];
 	printf("How many words:\n");
	scanf("%d",&n);
	printf("Enter the words:\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",word[i]);
	}
	
	
	for (h = 0; h < n-1; h++)
	for (k = 0; k < n-1; k++)
{
	j=0;
	  while(word[k][j]!=0 && word[k+1][j]!=0 && word[k+1][j]==word[k][j])
	{
		j++;
	}
	a=strlen(word[k]);
	b=strlen(word[k+1]);    		
	if(word[k][j]>word[k+1][j])
  {
		if(a>b)
	{
		while(word[k][j]!=0)
		{
		tmp=word[k][j];
			word[k][j]=word[k+1][j];
			word[k+1][j]=tmp;
			j++;	
		}
		 if(word[k][j]==0)
		 	{
		tmp=word[k][j];
			word[k][j]=word[k+1][j];
			word[k+1][j]=tmp;
			j++;	
		}			
	}
	else
	{
		while(word[k+1][j]!=0)	
		{
		tmp=word[k][j];
			word[k][j]=word[k+1][j];
			word[k+1][j]=tmp;
			j++;	
		}
		if(word[k+1][j]==0)
		{
		tmp=word[k][j];
			word[k][j]=word[k+1][j];
			word[k+1][j]=tmp;
			j++;	
		}
		 			
	}
	   
  }
}  

printf("alphabetic words:\n");
for(i=0;i<n;i++)
	{
		printf("%s\n",word[i]);
	}	
	printf("which word do you look?\n");
	scanf("%s",look);
	x=strlen(look);
	k = 0;

int counter[26];

for(i=97;i<123;i++)
{
counter[i]=0;
}
 for(i=0;i<n;i++)
 {
     tmp=word[i][0];
     counter[tmp]=counter[tmp]+1;
 }
 for(i=97;i<123;i++)
{
printf("%d",counter[i]);

}
printf("\n");
 
  i=0;
  j=0;
  while(look[j]>word[i][j] && i<=n)
  {
  	i++;
  }
  if(look[j]==word[i][j])
  {
  	v=i;
  }
 
  
  g=look[0];
  u=counter[g];
  j=0;
   while((look[j]!=0 || word[v][j]!=0) && (u>s) )
  {
   if(look[j]==word[v][j])
   {
       j++;        
   }
   //adverb aisle and 
   else if (j!=0)
   {
      v++;
      j=0;
      s++;
   }
   
  }
  if(x==j)
  printf("kelime bulundu");
  else
  printf("kelime bulunamadi");	
	return 0;
}
