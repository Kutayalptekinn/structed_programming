#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
int arr[4][4]={0},c[4],temp=0,len=0,score=0,highscore=0,count=0,ch=0;
void print()
{
	      if(score<highscore) printf("HIGH SCORE=%d\t\t\t\t\t\n",highscore); 
          else 
          {
              highscore=score;  
              printf("HIGH SCORE=%d\t\t\t\t\t\n",highscore); 
          }
          
	int i,j,k,len1;
	 printf("\n\t\t\t\t\t            WELCOME!            \n");
	 
	    printf("YOUR SCORE=%d",score); 
        printf("\nPREV      ->Z");
        printf("\nRESTART   ->R");
        printf("\nEXIT      ->E"); 
        
        printf("\t\t\t\t_________________________________\n");
        for (i=0;i<4;i++) 
    {
        for(j=0;j<4;j++)
        {
          if(j==0) //eger  j == 0 
          {
          printf("\t\t\t\t\t|"); 
          }
            if(arr[i][j]!=0)
            {
            	for(k=0;k<3;k++) 
            	{
            		printf(" ");
				}
				printf("%d",arr[i][j]);
				for(k=4;k<7;k++) 
            	{
            		printf(" ");
				}
				printf("|");
			}
			else
			{
				for(k=0;k<7;k++) 
			    {
                printf(" ");
			    }
			    printf("|");
			}
        }
        if(i!=3)
        {
        printf("\n");
        printf("\t\t\t\t\t_________________________________\n");
        }
    }
   printf("\n\t\t\t\t\t_________________________________\n");
   printf("\t\t\t\t\tENTER YOUR CHOISE -> W,S,A,D\n\t\t\t\t\t");
}
void diziyiacilanyereatma(int ***p)
{
	int i,j,k;
	if(count==4)
    {
        for(i=3;i>0;i--)
        {
            for(j=0;j<4;j++)
            {
                for(k=0;k<4;k++)
                {
                        p[i][j][k]=p[i-1][j][k];
                }
            }

        }
        count=3;
    }
	for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            p[3-count][i][j]=arr[i][j];
        }
    }
}
void randomsayiuret() 
{
    int no;
    srand(time(NULL)); 
    int i,j; 
    
    do
    {
    i=(rand ())%(4); 
    j=(rand ())%(4);
    }
    while(arr[i][j]!=0); 
    
    no=2*((rand ()%10)+1);	 
    if(no==3 || no==2)
    {
        arr[i][j]=4; 
    }
    else 
    {
        arr[i][j]=2; 
    }
}
void guncelle()
{
	int i,j;
    for(i=3;i>0;i--)
    {
        if(c[i]==c[i-1] )
        {
          c[i]+=c[i-1];
          score=score+c[i];
          c[i-1]=0;
          temp=1;
        }
        else if(c[i-1]==0 && c[i]!=0 )
        {
           c[i-1]=c[i];
           c[i]=0; 
           temp=1;
        }
        else if(c[i]==0)
        {
          temp=1;  
       }
    }
    guncelleiki();
}
guncelleiki()
{
	int i,j;
	for(j=0;j<4;j++)
	{
	for(i=0;i<4;i++)
    {
        if(c[i]!=0) 
        {
                if(c[i+1]==0) 
                {
                    c[i+1]=c[i]; 
                    c[i]=0;
                }    
        }
    }	
	}
    
}
void oncekihali(int ***p)
{
    int data,i,j;
    if(count==0)
    {
        printf("\n\t\t\t\t\t******FURTHER MORE PREV NOT POSSIBLE********");
        return;
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            arr[i][j]=p[3-count][i][j];
        }
    }
    count--;
}
void resetgame()
{
            int i,j;
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    arr[i][j]=0;

                }
            }
            system("cls") ; 
            score=0;
            randomsayiuret();

}
int main()
{
	system("color 4");
    int i,j,k,m,n,same=0,islem;
    char choise,s=177,reschk;
    printf("\n\t\t\t\t\t1)    ->Gelistiriceler  icin ");
    printf("\n\t\t\t\t\t2)    ->Konsol komut Bilgileri ");
    printf("\n\t\t\t\t\t3)    ->Oyuna Baslamak ");
    printf("\n\t\t\t\t\tLutfen 1 ve 2 veya 3 seciniz:");
    scanf("%d",&islem);
    switch(islem) 
     {
case 1:         printf("\n\t\t\t         isim soyisim:");
				printf("Kutay Alptekin");
				printf("\n\t\t\t         Oyuna Baslamak icin herhangi bir tusa basiniz...");
				system("color 3");
				getch();
				system("cls");
				break;			 
case 2:	        printf("\n\n\t\tKonsol Komutlari\n");
		        printf("\n\t\t\t\tYukari      ->'W' veya 'w'");
		        printf("\n\t\t\t\tAsagi       ->'S' veya 's'");
				printf("\n\t\t\t\tSola        ->'A' veya 'a'");
				printf("\n\t\t\t\tSaga        ->'D' veya 'd'");
				printf("\n\t\t\t\tGeri Alma   ->'Z' veya 'z'");
				printf("\n\t\t\t\tRestart     ->'R' veya 'r'");
				printf("\n\t\t\t\tCikis       ->'E' veya 'e'");
				printf("\n\n\t\t\t\t\tOyuna Baslamak icin herhangi tusa basiniz...");
				system("color 3");
				getch();
				system("cls");
				break;
	}
	 for(i=0;i<1;i++)
    {
    printf("\n\t\t\t**************Oyununuz Hazirlaniyor Lutfen Bekleyin**************");
	sleep(3);	
	}
     printf("\n\n\t\t\t\tLOADING ");
    for( i=0; i<36;i++)  
    {
    	system("color 2"); 
        printf("%c",s);
        j=i;
        if(i%2!=0 && i<20) 
		{
            sleep(1);
        }
    }
    sleep(1);
    system("cls");
    
    int ***p; 
    p=(int ***)malloc(sizeof(int *)*(4)); 
    for(i=0;i<4;i++)   
    {
       p[i]=(int **)malloc(sizeof(int *)*4);  //(*p+1)
    }
    for(i=0;i<4;i++)
    {
        for( j=0;j<4;j++)
        {
            p[i][j]=(int *)malloc(sizeof(int)*4);
        }
    }
    
    FILE *ptr;    
    ptr=fopen("highscore.txt","r"); 
    fscanf(ptr,"%d",&highscore); 
    fclose(ptr); 
    ptr=fopen("hstr.txt","a");
    fprintf(ptr,"%d ",score); 
    fclose(ptr);
    
    randomsayiuret(); 
	print();
	
	while(1)
	{
		    if(score>highscore) 
            {
            ptr=fopen("highscore.txt","w"); 
            fprintf(ptr,"%d",score);        
            fclose(ptr);                 
            }
            
            choise=getch(); 
            
        if(choise=='D' || choise =='d')  
        {
            count++;  
            diziyiacilanyereatma(p);
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    c[j]=arr[i][j]; 
                }
                    guncelle();
                for(k=0;k<4;k++)
                {
                    arr[i][k]=c[k];
                }
            }
        }
        else if(choise=='a' || choise=='A')
        {
            count++;
            diziyiacilanyereatma(p);
            for(i=0;i<4;i++)
            {
                for(j=3;j>=0;j--)
                {
                    c[3-j]=arr[i][j];
                }
                guncelle();
                for(k=0;k<4;k++)
                {
                    arr[i][3-k]=c[k];
                }
            }
        }
        else if(choise=='S' || choise =='s')
        {
            count++;
            diziyiacilanyereatma(p);
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    c[j]=arr[j][i];
                }
                guncelle();
                for(k=0;k<4;k++)
                {
                    arr[k][i]=c[k];
                }
            }
        }
        else if(choise=='W' || choise=='w')
        {
            count++;
            diziyiacilanyereatma(p);
            for(i=0;i<4;i++)
            {
                for(j=3;j>=0;j--)
                {
                    c[3-j]=arr[j][i];
                }
                guncelle();
                for(k=0;k<4;k++)
                {
                  arr[3-k][i]=c[k];
                }
            }
        }
        else if(choise=='Z' || choise =='z')
        {
            oncekihali(p);
            temp=8;
        }
        else if(choise=='R' || choise=='r')
        {
            count=0;
            resetgame();
            print();
            continue;
        }
        else if(choise=='e'||choise=='E')
        {
            exit(0);
        }
        
        if(temp==1)
            {
                temp=0;
                system("cls") ;
                printf("\n%c\n",choise);
                randomsayiuret();
                print();

            }
            else if(temp==8)
            {
                temp=0;
                print();
            }
            
	}
}
