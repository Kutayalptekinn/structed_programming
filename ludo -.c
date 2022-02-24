#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void menu();
void Print();
void gotoxy(int x, int y);
int main()
{ 
int c=0,d=0,x=0;
int h = 0;
int p=0;
int k=0;
int y = 0;
int n;
int l=0;

int tmp,tmpp,tmppp;
	Print();
	int m=5;
      int r=3;
	  int q=0;       		int b=8;
	int i,j,tabela[50][50];
	system("cls");
	menu();
	       
	       tabela[0][0]=101;
       tabela[0][1]=102;
       tabela[1][0]=103;
       tabela[1][1]=104;
       tabela[7][0]=11111;
       tabela[7][1]=11112;
       tabela[8][0]=11113;
       tabela[8][1]=11114;
       tabela[7][7]=111;
       tabela[7][8]=112;
       tabela[8][7]=113;
       tabela[8][8]=114;
       tabela[0][3]=8;
       tabela[0][4]=9;
       tabela[1][4]=93;
       tabela[2][4]=92;
       tabela[3][4]=91;
       tabela[5][4]=83;
       tabela[6][4]=82;
       tabela[7][4]=81;
       tabela[0][5]=10;
       tabela[1][3]=7;
       tabela[1][5]=11;
       tabela[2][3]=6;
       tabela[2][5]=12;
       tabela[3][0]=2;
       tabela[3][1]=3;
       tabela[3][2]=4;
       tabela[3][3]=5;
       tabela[3][5]=13;
       tabela[3][6]=14;
       tabela[3][7]=15;
       tabela[3][8]=16;
       tabela[4][0]=1;
       tabela[4][1]=63;
       tabela[4][2]=62;
       tabela[4][3]=61;
       tabela[4][5]=73;
       tabela[4][6]=72;
       tabela[4][7]=71;
       tabela[4][8]=17;
       tabela[5][0]=32;
       tabela[5][1]=31;
       tabela[5][2]=30;
       tabela[5][3]=29;
       tabela[5][5]=21;
       tabela[5][6]=20;
       tabela[5][7]=19;
       tabela[5][8]=18;
       tabela[6][3]=28;
       tabela[6][5]=22;
       tabela[7][3]=27;
       tabela[7][5]=23;
       tabela[8][3]=26;
       tabela[8][4]=25;
       tabela[8][5]=24;
       tabela[0][2]=0;
       tabela[1][2]=0;
       tabela[2][2]=0;
       tabela[2][0]=0;
       tabela[2][1]=0;
       tabela[0][6]=0;
       tabela[0][7]=1111;
       tabela[0][8]=1112;
       tabela[1][7]=1113;
       tabela[1][8]=1114;
       tabela[1][6]=0;
       tabela[2][6]=0;
       tabela[2][7]=0;
       tabela[2][8]=0;
       tabela[6][0]=0;
       tabela[6][1]=0;
       tabela[6][2]=0;
       tabela[7][2]=0;
       tabela[8][2]=0;
       tabela[8][6]=0;
       tabela[7][6]=0;
       tabela[6][6]=0;
       tabela[6][7]=0;
       tabela[6][8]=0;
       tabela[4][4]=0;
       
       matrisokuma(tabela);
     
	 while(k==0&&l==0)
	 {
	 	int ydice=yrolldice();;
 if(ydice==6)
 {
 	printf("yesil piyonunu ilk kareye koyarak oyuna baslayabilir\n");
        tmp=tabela[0][0];
    	tabela[0][0]=1;
    	tmppp=tabela[3][0];
    	tabela[3][0]=tmp;
        matrisokuma(tabela);
        k=1;
 }  
 int mdice=mrolldice();;
 if(mdice==6)
 {
 	printf("mavi piyonunu ilk kareye koyarak oyuna baslayabilir\n");
        tmp=tabela[8][8];
    	tabela[8][8]=1;
    	tmpp=tabela[5][8];
    	tabela[5][8]=tmp;
        matrisokuma(tabela);
        l=1;
 }  
	 }
	 if(k==1&&l==1)
	 {
	 	int ydice=yrolldice();
	 	n=tmppp+ydice;
	 	for (i = 0; i < 9; i++)
         {
         	
             for (j = 0; j < 9; j++)
             {
             	while(tabela[i][j]==n)
             	{
				 tabela[i][j]=tabela[3][0];
				 tabela[3][0]=tmppp;
				}
                 
             }           
         }
         matrisokuma(tabela);
		 
		 int mdice=mrolldice();
		 n=tmpp+mdice;
		 for (i = 0; i < 9; i++)
         {
         	
             for (j = 0; j < 9; j++)
             {
             	while(tabela[i][j]==n)
             	{
				 tabela[i][j]=tabela[5][8];
				 tabela[5][8]=tmpp;
				}
                 
             }           
         }	
		 matrisokuma(tabela);	 	
	 }
	 else if(k)
	 {
	 	while(h==0)
	 	{
	 		int ydice=yrolldice();
	 	n=tmppp+ydice;
	 	for (i = 0; i < 9; i++)
         {
         	
             for (j = 0; j < 9; j++)
             {
             	while(tabela[i][j]==n)
             	{
             		
				 tabela[i][j]=tabela[r][q];
				 
				 tabela[r][q]=tmppp;
				 
				 
				 r=i;
				 q=j;
				 tmppp=tabela[i][j];
				}
                 
             }           
         }
         matrisokuma(tabela);
         
         int mdice=mrolldice();
	 if(mdice==6)
 {
 	printf("mavi piyonunu ilk kareye koyarak oyuna baslayabilir\n");
        tmp=tabela[8][8];
    	tabela[8][8]=1;
    	tmpp=tabela[5][8];
    	tabela[5][8]=tmp;
        matrisokuma(tabela);
        h=1;
 }
 
		 }
		 int ydice=yrolldice();
	 	n=tmppp+ydice;
	 	for (i = 0; i < 9; i++)
         {
         	
             for (j = 0; j < 9; j++)
             {
             	while(tabela[i][j]==n)
             	{
             		
				 tabela[i][j]=tabela[r][q];
				 tabela[r][l]=tmppp;
				 tmppp=tabela[i][j];
				 k=i;
				 q=j;
				}
                 
             }           
         }
         int mdice=mrolldice();
	 	n=tmpp+mdice;
	 	for (i = 0; i < 9; i++)
         {
         	
             for (j = 0; j < 9; j++)
             {
             	while(tabela[i][j]==n)
             	{
             		
				 tabela[i][j]=tabela[m][b];
				 tabela[m][b]=tmpp;
				 tmppp=tabela[i][j];
				 k=i;
				 l=j;
				}
                 
             }           
         }
	 	
	 }
	 else if (l)
	 {
	 	int ydice=yrolldice();
      if(ydice==6)
 {
 	printf("yesil piyonunu ilk kareye koyarak oyuna baslayabilir\n");
        tmp=tabela[0][0];
    	tabela[0][0]=1;
    	tmppp=tabela[3][0];
    	tabela[3][0]=tmp;
        matrisokuma(tabela);
 }   
   int mdice=mrolldice();
    n=tmpp+mdice;
		 for (i = 0; i < 9; i++)
         {
         	
             for (j = 0; j < 9; j++)
             {
             	while(tabela[i][j]==n)
             	{
				 tabela[i][j]=tabela[5][8];
				 tabela[5][8]=tmpp;
				}
                 
             }           
         }	
		 matrisokuma(tabela);
	 }
	 
	   
	
	  
	 
 
 
 
 
	return 0;
}
void menu()
{
		
	
}
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void Print()
{
   gotoxy(10,12);
   printf("\tWELCOME TO THE LUDO GAME.(press any key to continue)\n");
  getch();
   system("cls");
   printf("\n->Game Instructions:\n");
   printf("\n1. Each player has 4 pieces.\n2. There might be 2, 3, or 4 players (Red (R) ,Yellow (Y), Green (G) and Blue (B)) \n3. At each round the respective player rolls the single dice (1-6).\n4. Each piece is allowed to leave from the nest, if the dice shows “6”.\n5. At each cell, only one single piece could exist.\n6. Each player is allowed to place any number of his/her pieces into the raceway.\n7. If the player rolls six, he/she could either place a piece into the board from the nest or play any piece on the board.\n8.A piece could move forward even if there is a piece of any opponent on its way.\n9. If a piece stops at the same place of another piece of the same player, the player is not allowed to move it. He/she should wait for his/her next turn.\n10.Nobody could hurt a piece if it reaches at the final destination.\n11. If any piece could reach to the location of another players’ piece, the piece should return to its nest.\n12. The player whose all 4 pieces reach at final destination becomes the WINNER\n"); 
   printf("\n\nPress any key to continue...");
   getch();
   system("cls");
   printf("\n\nOur game consists of green and blue players and contains one dice.");
   printf("\n\nPress any key to play game...");
   getch();
   
}
int mrolldice()           // Comment this and use the other roledice function for quick checking.
{
	int mdice;
	printf("Mavi oyuncu zari atiniz\n");
	printf("Mavinin zari icin herhangi bir tusa basiniz\n");
	getch(); 	
	mdice = ((rand() % 6) + 1);
	printf("%d\n",mdice);
	return mdice;
}
int yrolldice()           // Comment this and use the other roledice function for quick checking.
{
	int ydice;
	printf("Yesil oyuncu zari atiniz\n");
	printf("Yesilin zari icin herhangi bir tusa basiniz\n");
	getch();	
	srand(time(NULL));
	ydice = ((rand() % 6) + 1);
	printf("%d\n",ydice);
	return ydice;

}


int matrisokuma(int tabela[50][50])
{
    int i,j;
    for (i = 0; i < 9; i++)
         {
             for (j = 0; j < 9; j++)
             {
                 printf("%d\t",tabela[i][j]);
             }
             printf("\n");
         }
    
}


