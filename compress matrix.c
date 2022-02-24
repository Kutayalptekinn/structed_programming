#include <stdio.h>
#include <stdlib.h>
#define max 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int matris[max][max];
int i,j,n,m,c,v=0,k,z,h=0;
int a[max][max];
int x[max][max];


while(h==0)
{
		printf("menudeki degeri giriniz\n 1--seyrek matristen sikistirilmis matrise \n2--sikistirilmis matristen seyrek matrise \n3--cikis\n");
scanf("%d",&z);

if(z==1)
{
printf("Satir sayisini giriniz:");
scanf("%d",&n);
printf("Sutun sayisini giriniz:");
scanf("%d",&m);

printf("\n Matrisin degerlerini giriniz:\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("\nmatris[%d][%d] icin deger: ",i,j);
scanf("%d",&matris[i][j]);
}
}


for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
if(matris[i][j]!=0)
{
	a[i][0]=i;
	a[i][1]=j;
	a[i][2]=matris[i][j];
}
}

}
printf("seyrek matris:\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
	printf("%3d",matris[i][j]);
}
printf("\n");
}


printf("sikistirilimis matris:\n");
for(i=0;i<n;i++)
{
for(j=0;j<3;j++)
{
	printf("%3d",a[i][j]);
}
printf("\n");
}	

}

else if(z==2)
{
printf("Satir sayisini giriniz:");
scanf("%d",&n);
printf("Sutun sayisini giriniz:");
scanf("%d",&m);

	printf("matriste kac tane 0 dan farkli eleman var\n");
scanf("%d",&k);
for(c=1;k>=c;c++)
{
	printf("%d. eleman icin satir sutun ve degeri girin:\n",c);
for(j=0;j<3;j++)
{
scanf("%d",&x[v][j]);
}
v++;
}
printf("sikistirilimis matris:\n");
for(i=0;i<n;i++)
{
for(j=0;j<3;j++)
{
	printf("%3d",x[i][j]);
}
printf("\n");
}
for(i=0;i<k;i++)
{
	matris[x[i][0]][x[i][1]]=x[i][2];
}


printf("seyrek matris:\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
	printf("%3d",matris[i][j]);
}
printf("\n");
}
}
else if(z==3)
{
	printf("cikis yapabilirsiniz");
	
	return 0;
}
else
{
	printf("hatali deger tekrar giriniz");
	h=1;
 } 

}
}






	
	
	
	
	
	
