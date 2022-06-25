#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	int i,j,N,M,k,choice,count=1,numb,elmnt,maxrow=1,maxcol=1;
	int **matris;
	int **matris2;
	int loop=1;
	while(loop==1)
	{
	printf("(1) Seyrek matristen Sikistirilmis matrise\n(2) Sikistirilmis matristen Seyrek matrise\n(3) Cikis\n");
		   scanf("%d",&choice);
	
	
	    if(choice==1)
	    {
	    printf("matrisin boyutlarini giriniz:(sirasiyla satir ve sutun)\n");
        scanf("%d %d",&N,&M);
        
        matris=(int**)malloc(N*sizeof(int*));
        if(matris==NULL) printf("error space");
        
         for(i=0;i<N;i++)
         {
          matris[i]=(int*)malloc(M*sizeof(int));
          if(matris[i]==NULL) printf("error space");
		 }
		 
		 matris2=(int**)malloc(sizeof(int*));        

		 
		 printf("Matrisin elemanlarini giriniz\n");
		   for(i=0;i<N;i++)
		   {
		   		for(j=0;j<M;j++)
                {
                 printf("[%d][%d]:",i,j);
                 scanf("%d",&matris[i][j]);
                 if(matris[i][j]!=0)
                 {
                 	matris2=(int**)realloc(matris2,sizeof(int*)*count);

                    matris2[count-1]=(int*)malloc(3*sizeof(int));

		            matris2[count-1][0]=i;
		            matris2[count-1][1]=j;
		            matris2[count-1][2]=matris[i][j];
		            count++;
				 }
		        }
		   }
		   
		   	printf("Sikistirilmis Matris:\n");
		   for(i=0;i<count-1;i++)
		   {
		   		for(j=0;j<3;j++)
                {
                	printf("%d\t", matris2[i][j]);
                }
                printf("\n");
           }
           
             for(j=0;j<count-1;j++)
                {
                	free(matris2[j]);
                }
            free(matris2);    
           for(j=0;j<N;j++)
                {
                	free(matris[j]);
                }
           free(matris);
              
	    }
	    else if(choice==2)
	    {
	    	printf("Matriste kac tane sifirdan farkli eleman var(Sikistirilmis matristeki satir sayisi)?\n");
	    	scanf("%d",&elmnt);
	    	
	    	 matris=(int**)malloc(elmnt*sizeof(int*));
            if(matris==NULL) printf("error space");
        
             for(i=0;i<elmnt;i++)
             {
             matris[i]=(int*)malloc(3*sizeof(int));
             if(matris[i]==NULL) printf("error space");
	    	 }
	    	
	    	
	    	for(i=0;i<elmnt;i++)
	    	{
	    		printf("%d. eleman icin Satir Sutun ve Degeri girin:\n",i+1);
	    		scanf("%d %d %d",&matris[i][0],&matris[i][1],&matris[i][2]);
	    		
	    		if(i==0)
				{
					maxrow=matris[i][0];
					maxrow++;
					matris2=(int**)calloc(maxrow,sizeof(int*)*maxrow);
					for(j=0;j<maxrow;j++)
                    {
                     matris2[j]=(int*)realloc(matris2[j],maxcol*sizeof(int));
                     if(matris[j]==NULL) printf("error space");
	            	 }
				} 
	    		
	    		
	    		if(i>0 && matris[i][0]+1>maxrow)
				{
					maxrow=matris[i][0];
					maxrow++;
					matris2=(int**)realloc(matris2,sizeof(int*)*(maxrow));
					for(j=0;j<maxrow;j++)
                    {
                     matris2[j]=(int*)realloc(matris2[j],maxcol*sizeof(int));
                     if(matris[j]==NULL) printf("error space");
	            	 }
				 }
				 
				 if(i==0)
				 {
				 	maxcol=matris[i][1];
				 	maxcol++;
				 	for(j=0;j<maxrow;j++)
                    {
                     matris2[j]=(int*)calloc(maxcol,maxcol*sizeof(int));
                     if(matris[j]==NULL) printf("error space");
	                 }
				  } 
                 
				 if(i>0 && matris[i][1]+1>maxcol)
				 {
				 	maxcol=matris[i][1];
				 	maxcol++;
				 	for(j=0;j<maxrow;j++)
                    {
                     matris2[j]=(int*)realloc(matris2[j],maxcol*sizeof(int));
                     if(matris[j]==NULL) printf("error space");
	            	 }	
					 			 	 
				 }		
	    		matris2[matris[i][0]][matris[i][1]]=matris[i][2];
	    		
	    		
			}
			
			 for(i=0;i<maxrow;i++)
		   {
		   		for(j=0;j<maxcol;j++)
                {
                	if(matris2[i][j]>9999 || matris2[i][j]<-9999) matris2[i][j]=0;
                	
                }
           }
			printf("Sikistirilmis Matris:\n");
		   for(i=0;i<elmnt;i++)
		   {
		   		for(j=0;j<3;j++)
                {
                	printf("%d\t", matris[i][j]);
                }
                printf("\n");
           }
           
           	printf("Seyreltilmis Matris:\n");
		   for(i=0;i<maxrow;i++)
		   {
		   		for(j=0;j<maxcol;j++)
                {
                	printf("%d\t", matris2[i][j]);
                }
                printf("\n");
           }
           
           for(j=0;j<maxrow;j++)
                {
                	free(matris2[j]);
                }
            free(matris2);    
           for(j=0;j<elmnt;j++)
                {
                	free(matris[j]);
                }
           free(matris);
           
		}
		else
		{
			loop=0;
		}
	}
	
	
	return 0;
}
