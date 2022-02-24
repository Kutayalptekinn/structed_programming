#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ogrenciDersBilgisi{
  
  int ID;
  char DersKodu[30];
  char Durum[30];
  long OgrenciNo;
  char Tarih[30];
} OGRENCIDERSBILGISI;



typedef struct ogrenci{
  
  long Numara;
  char Ad[75];
  char Soyad[30];
  int DersSayisi;
  int ToplamKredisi;
  struct ogrenci *next;
  struct ogrenci *prev;
} OGRENCI;

typedef struct dersbilgisi{
	char DersKodu[30];
	char DersAdi[50];
	int ToplamKredi;
	int Kontenjan;
	int mem;
	struct dersbilgisi *next;
	long *next2;
}DERSBILGISI;


DERSBILGISI *dersAra(DERSBILGISI **head, char DersKodu[]);
OGRENCI *ogrenciAra(OGRENCI **head1, long Numara);
OGRENCIDERSBILGISI * ogrenciDersBilgisi(OGRENCIDERSBILGISI * head,int n,char DersKodu[],long OgrenciNo,char Durum[],char tarih[]);
OGRENCIDERSBILGISI *ogrenciDersBilgisiEkle(long OgrenciNo,char DersKodu[],int ID,char Durum[]);
void dersSil(DERSBILGISI **head,char DersKodu[]);
void dersEkle(DERSBILGISI **head, char DersKodu[],char DersAdi[],int ToplamKredi,int Kontenjan);
DERSBILGISI *dersBilgisiEkle(char DersKodu[],char DersAdi[],int ToplamKredi,int Kontenjan);
void ogrenciSil(OGRENCI **head,long Numara);
void yeniogrenciEkle(OGRENCI **head, long Numara,char Ad[],char Soyad[],int ToplamKredisi,int DersSayisi);
void ogrenciGuncelle(OGRENCI **head, long Numara,char Ad[],char Soyad[],int ToplamKredisi,int DersSayisi);
void ogrenciDersBilgisiGuncelle(OGRENCIDERSBILGISI ogrenciler[],int n,long OgrenciNo,char DersKodu[],char Durum[]);
void dersleriListele(OGRENCIDERSBILGISI ogrenciler[],long OgrenciNo,int n);
void ogrencileriListele(OGRENCIDERSBILGISI ogrenciler[],char DersKodu[],int n);
void derseOgrenciEkle(OGRENCIDERSBILGISI **head,DERSBILGISI **head1,OGRENCI **head2,char DersKodu[],long OgrenciNo,char Tarih[],int length[]);
OGRENCI *yeniOgrenciOkuEkle();
DERSBILGISI *yeniDersOkuEkle();
OGRENCI* OgrenciOkuVeYazdir(OGRENCI *head);
DERSBILGISI* DersOkuVeYazdir(DERSBILGISI *head);
OGRENCIDERSBILGISI *OgrenciDersOkuVeYazdir(OGRENCIDERSBILGISI *head,int length[],DERSBILGISI *head1,OGRENCI *head2);
OGRENCIDERSBILGISI *yeniOgrenciDersOkuEkle();
void derseOgrencileriEkle(OGRENCIDERSBILGISI *ogrenciler,OGRENCI *temp3,DERSBILGISI *head,OGRENCI *head1,int maxders,int maxkredi,int length[],int number,int w);
void derstenOgrenciSil(OGRENCI *head1,DERSBILGISI *head,int length[],long number,OGRENCIDERSBILGISI ogrenciler[],int w);

int main() 
{
	OGRENCIDERSBILGISI *ogrenciler=NULL;
	OGRENCIDERSBILGISI *head2=NULL;
	DERSBILGISI ders;
    DERSBILGISI *temp=NULL;
    DERSBILGISI *temp2=NULL;
    OGRENCI *temp3=NULL;
    OGRENCI *temp4=NULL;
    OGRENCI *temp6=NULL;
    DERSBILGISI *temp5=NULL;	
	DERSBILGISI *head=NULL;
	OGRENCI ogrenci;
	OGRENCI *head1=NULL;
	head=DersOkuVeYazdir(head);   //dosya okuma 
	head1=OgrenciOkuVeYazdir(head1);//dosya okuma
	
	char *durum="ders acildi";
	char tarih[30];
	int a,c,d,e=0,f=0,g,k=0,m=1,n=1,l,p,r,q=1,w=0,kont=0,j,i,krediS=0,maxders,maxkredi,used=1,length[50]={0},ID=0;
	long number,numara;
	char kod[30],kod2[30],kod3[30],b[30];
	ogrenciler=OgrenciDersOkuVeYazdir(ogrenciler,length,head,head1);//dosya okuma islemlerin
	while(e!=3 && k==0)
	{
		while(ogrenciler[w].ID==w+1)
		    {
			    	w++;
				}
		int k=1;
	printf("egitmen iseniz 1'i ogrenci iseniz 2'yi cikmak icin 3'u tuslayiniz:\n");
	scanf("%d",&e);
	if(e==1)
	{
		if(used==1)
		{
		printf("max ders sayisini giriniz:\n");
		scanf("%d",&maxders);
		printf("max kredi sayisini giriniz:\n");
		scanf("%d",&maxkredi);
		used=0;
		
		
			
		}
		q=1;
		while(q==1 && k==1)
		{
		printf("Ders Koduna gore ogrencileri listelemek icin 1'i\nOgrenci numarasina gore alinan dersleri listelemek icin 2'yi\nDevam etmek icin 3'u\nbasa donmek icin 4'u tuslayiniz:\n");
		scanf("%d",&r);
			if(r==1)
			{
				printf("ders kodunu giriniz:");
				scanf("%s",&kod3);
			    
				ogrencileriListele(ogrenciler,kod3,w);	
				printf("\n");
				
			}
			else if (r==2)
			{
				printf("ogrenci numarasini giriniz:");
				scanf("%ld",&numara);				
				dersleriListele(ogrenciler,numara,w);
				printf("\n");	
			}
			else if (r==3)
			{
				q=0;
			}
			
			else if (r==4)
			{
				k=0;
			}
			else
			{
				printf("yanlis tuslama yaptiniz cikis yapiliyor");
				return 0;
				}	
		}
		
		
		
		while(f!=3&& k==1)
		{
			printf("ders eklemek veya silmek icin 1'i ogrenci eklemek veya silmek icin 2'yi cikmak icin 3'u basa donmek icin 4'u tuslayiniz:");
		    scanf("%d",&f);
		if(f==1)
		{
			while(a!=3&& k==1)
			{
				printf("ders eklemek icin 1'i silmek icin 2'yi cikmak icin 3'u basa donmek icin 4'u tuslayiniz:\n");
	            scanf("%d",&a);
	if(a==1)
	{
		printf("eklemek istediginiz ders bilgilerini giriniz:\n");
		m=1;

		
		
		while(m==1)
		{
		
    	printf("ders kodu:");
		scanf("%s",&ders.DersKodu);
		if(head!=NULL)
		{
		if(dersAra(&head,ders.DersKodu) )
        {
        	
			printf("Eklemeye calistiginiz ders daha once eklenmistir yeniden denemek icin 1'i cikis yapmak icin 2'yi tuslayiniz:\n");
			scanf("%d",&l);
			if(l==1)
			{
				m=1;
			}
			else if(l==2)
			{
				printf("cikis yapiliyor...");
				return 0;
			}
			else
			{
				printf("yanlis tuslama yaptiniz cikis yapiliyor...");
				return 0;
			}
			}
			else
			{
				m=0;
				}	
		}
		else
		{
			m=0;
		}
				
		}
			

		
		
		printf("ders adi:");
		scanf("%s",&ders.DersAdi);
		printf("ders toplam kredisi:");
		scanf("%d",&ders.ToplamKredi);
		printf("ders kontenjani:");
		scanf("%d",&ders.Kontenjan);
		dersEkle(&head,ders.DersKodu,ders.DersAdi,ders.ToplamKredi,ders.Kontenjan);
		
	}
	else if(a==2)
	{
		printf("silmek istediginiz dersin kodunu giriniz:");
		scanf("%s",b);
		if(head==NULL)
		{
			printf("ders silmek icin once ders eklemeniz gerekmektedir.");
			return 0;
		}
		if(dersAra(&head,b))
		{
		temp5=dersAra(&head,b);
		for(i=0;i<length[temp5->mem];i++)
		{
			temp4=ogrenciAra(&head1,temp5->next2[i]);
			temp4->DersSayisi--;
			temp4->ToplamKredisi=temp4->ToplamKredisi-temp5->ToplamKredi;
			ogrenciGuncelle(&head1,temp4->Numara,temp4->Ad,temp4->Soyad,temp4->DersSayisi,temp4->ToplamKredisi);
			ogrenciDersBilgisiGuncelle(ogrenciler,w,0,temp5->DersKodu,"derskapandi");

		}
		dersSil(&head,b);	
		}
		else
		{
			printf("boyle bir ders yoktur.");
			return 0;
		}
		
			}
			
		else if(a==3)
		{
			printf("cikis yapiliyor");
			return 0;
		}	
		else if(a==4)
		{
			k=0;
			}
			else
			{
				printf("yanlis tuslama yaptiniz cikis yapiliyor...");
				return 0;
				}	
	}
		}
		else if (f==2)
		{
			while(c!=3 && k==1)
			{
					printf("ogrenci eklemek icin 1'i silmek icin 2'yi cikmak icin 3'u basa donmek icin 4'u tuslayiniz.\n");
	scanf("%d",&c);
	if(c==1)
	{
		
		printf("eklemek istediginiz ogrenci bilgilerini giriniz:\n");
		n=1;
		while(n==1)
		{
		
    	printf("numara:");
		scanf("%ld",&ogrenci.Numara);
		if(head1!=NULL)
		{
		if(ogrenciAra(&head1,ogrenci.Numara) )
        {
        	
			printf("Eklemeye calistiginiz ogrenci daha once eklenmistir yeniden denemek icin 1'i cikis yapmak icin 2'yi tuslayiniz:\n");
			scanf("%d",&p);
			if(p==1)
			{
				n=1;
			}
			else if(p==2)
			{
				printf("cikis yapiliyor...");
				return 0;
			}
			else
			{
				printf("yanlis tuslama yaptiniz cikis yapiliyor...");
				return 0;
			}
			}
			else
			{
				n=0;
				}	
		}
		else
		{
			n=0;
		}
				
		}
			

		
		printf("ad:");	
		scanf("%s",&ogrenci.Ad);
		printf("soyad:");
		scanf("%s",&ogrenci.Soyad);
		printf("Yeni eklenen ogrencilerin ders sayisi ve kredisi otomatik olarak 0 atanmistir.\n");
		ogrenci.DersSayisi=0;
		ogrenci.ToplamKredisi=0;

		yeniogrenciEkle(&head1,ogrenci.Numara,ogrenci.Ad,ogrenci.Soyad,ogrenci.DersSayisi,ogrenci.ToplamKredisi);
		
	}
	else if(c==2)
	{	
	printf("silmek istediginiz ogrencinin numarasini giriniz:");
		scanf("%d",&d);
		if(head1==NULL)
		{
			printf("ogrenci silmek icin once ogrenci eklemeniz gerekmektedir.");
			return 0;
		}
		
		

		if(ogrenciAra(&head1,d))
		{
		ogrenciSil(&head1,d);	
		ogrenciDersBilgisiGuncelle(ogrenciler,w,d,"derskod","ogrencisilindi");
		}
		else
		{
			printf("boyle bir ogrenci yoktur.");
			return 0;
		}
		}
		else if(c==3)
		{
			printf("cikis yapiliyor...");
			return 0;
		}
		else if(c==4)
		{
			k=0;
		}
		
			
			}
	
				
	}	
	else if(f==3)
	{
		printf("cikis yapiliyor...");
		return 0;
	}
	else if(f==4)
	{
		k=0;
	}
	else
	{
		printf("yanlis tuslama yaptiniz cikis yapiliyor");
		return 0;
	}
		}

	}
	else if(e==2)
	{
		
		printf("okul numaranizi giriniz:\n");
		scanf("%ld",&number);
		if(head1==NULL)
		{
			printf("sistemde kayitli ogrenci yoktur");

		}
		else{
		
		while(g!=3 && k==1)
		{
		printf("ders secmek icin 1'i var olan dersi silmek icin 2'yi cikmak icin 3'u basa donmek icin 4'u tuslayiniz:");
		scanf("%d",&g);
		temp3=ogrenciAra(&head1,number);
		if(temp3==NULL)
		{
			return 0;
		}
		if(g==1)
		{
			if(maxkredi>temp3->ToplamKredisi && maxders>temp3->DersSayisi)
		{
			 printf("secmek istediginiz ders kodunu giriniz:\n");
		 scanf("%s",kod);	
		 
		 
		 if(dersAra(&head,kod)==0)
		 {
		 	printf("boyle bir ders bulunamadi cikis yapiliyor..");
		 	return;
		 }

		
		i=0;
		temp = head;
		
		while(temp->next!= NULL && (strcmp(temp->DersKodu,kod)<0)){
			temp= temp->next;
			i++;
		}
		
		if(length[i]==0)
		{
		temp->next2=(long*)calloc(temp->Kontenjan ,sizeof(long));
		}
		if(length[i]==temp->Kontenjan)
		{
			printf("daha fazla eleman ekleyemezsiniz");
			return;
		}
		j=0;
		
		while(j<=length[i] && number>temp->next2[j])
		{
			if(number==temp->next2[j])
			{
				printf("bu dersi daha once aldiniz.\n");
				return;
			}
			j++;
		}
		
		temp->next2[j-1]=number;
		length[i]++;
	    temp3->DersSayisi++;
	    temp3->ToplamKredisi=temp3->ToplamKredisi+temp->ToplamKredi;
	    ogrenciGuncelle(&head1,temp3->Numara,temp3->Ad,temp3->Soyad,temp3->DersSayisi,temp3->ToplamKredisi);
        w++;
        
        printf("tarihi giriniz: ");
		 scanf("%s",tarih);
	    ogrenciler=ogrenciDersBilgisi(ogrenciler,w,kod,temp->next2[j-1],"kayitli",tarih);
	    
		}
		else
		{
			printf("dersi secmeye krediniz yetmiyor veya maximum ders sayisina ulastiniz");
			return;
		}
		}

		else if(g==2)
		{
				
	        printf("silmek istediginiz ders kodunu giriniz:\n");
			scanf("%s",kod2);
			temp2=dersAra(&head,kod2);
			temp6=ogrenciAra(&head1,number);
			i=0;
			while(i<=length[temp2->mem] && number>temp2->next2[i])
		   {
			i++;
		   }
		   if(number==temp2->next2[i])
		   {
		   	for(j=i;j<length[temp2->mem];j++)
		   {
		   	temp->next2[j]=temp->next2[j+1];
		   }
		   length[temp2->mem]--;
		   temp6->DersSayisi--;
		   temp6->ToplamKredisi=temp6->ToplamKredisi-temp2->ToplamKredi;
		   ogrenciGuncelle(&head1,temp6->Numara,temp6->Ad,temp6->Soyad,temp6->DersSayisi,temp6->ToplamKredisi);
		   k=0;
		   
		   while(ogrenciler[k].OgrenciNo!=number && (strcmp(ogrenciler[k].DersKodu,kod2)!=0))
		   {
		   	k++;
		   }
		   
		   ogrenciDersBilgisiGuncelle(ogrenciler,w,number,kod2,"dersisildi");
		   }
		   else{
		   	printf("silmek istediginiz eleman bulunamadi");
		   }
			
		}
		else if(g==3)
		{
		printf("cikis yapiliyor...");
			return 0;	
		}
		else if(g==4)
		{
			k=0;
		 } 
		 else
		{
			printf("yanlis tuslama yaptiniz cikis yapiliyor...");
		return 0;
		}
		
	
			
		}
	}
		
	}
	else if(e==3)
	{
		printf("cikis yapiliyor...");
		return 0;
	}
	else
	{
		printf("yanlis tuslama yaptiniz cikis yapiliyor...");
		return 0;
	}
	}

	
	return 0;
}


OGRENCI *ogrenciEkle(long Numara,char Ad[],char Soyad[],int ToplamKredisi,int DersSayisi)
{
	OGRENCI* tmpp;
	tmpp = (OGRENCI*) malloc(sizeof(OGRENCI));	
	tmpp->Numara=Numara;
	strcpy(tmpp->Ad,Ad);
	strcpy(tmpp->Soyad,Soyad);
	tmpp->DersSayisi = DersSayisi;
	tmpp->ToplamKredisi = ToplamKredisi;
	tmpp->next = NULL;
	tmpp->prev = NULL;
	return tmpp;
}


void yeniogrenciEkle(OGRENCI **head, long Numara,char Ad[],char Soyad[],int ToplamKredisi,int DersSayisi){
	OGRENCI *tmpp;
	
	FILE *data;
	OGRENCI *yeniOgrenci=ogrenciEkle(Numara,Ad,Soyad,ToplamKredisi,DersSayisi);
	if(*head==NULL){
		*head = yeniOgrenci;
	}
	else{
		tmpp = *head;
		while(tmpp->next!= NULL && tmpp->Numara < Numara){
			tmpp= tmpp->next;
		
		}
		if(tmpp==*head && tmpp->Numara > Numara)
		{
			*head=yeniOgrenci;
			yeniOgrenci->next=tmpp;
			tmpp->prev=*head;
		}
		else
		{
			if(tmpp->next==NULL){
			yeniOgrenci->prev=tmpp;
			tmpp->next=yeniOgrenci;
		}
		else{
			
			yeniOgrenci->next = tmpp;
			yeniOgrenci->prev=tmpp->prev;
			tmpp->prev=yeniOgrenci;
			yeniOgrenci->prev->next=yeniOgrenci;
			
		}
		}
		
	}
	
	data=fopen("ogrenciler.txt","w");
	if(data!=NULL){
		tmpp = *head;	
		while(tmpp!=NULL)
		{
			fprintf(data,"%ld %s %s %d %d\n",tmpp->Numara,tmpp->Ad,tmpp->Soyad,tmpp->ToplamKredisi,tmpp->DersSayisi);
			tmpp=tmpp->next;
			
		}
		fclose(data);
	}

	
}


void ogrenciSil(OGRENCI **head,long Numara){
	OGRENCI *tmpp,*tmpp2;
	FILE *data;
	if((*head)->Numara==Numara){
		tmpp=(*head)->next;
		printf("%d silindi\n",(*head)->Numara);
		free(*head);
		(*head)->next=NULL;
		*head = tmpp;		
	}
	else{
		tmpp = *head;
		while(tmpp->next!=NULL && tmpp->next->Numara!=Numara){
			tmpp = tmpp->next;
		}
		if(tmpp== NULL){
			printf("bulunamadi!\n");
		}
		else{
			tmpp2=tmpp->next;
			tmpp->next=tmpp->next->next;
			printf("\n%d silindi\n",tmpp2->Numara);
			free(tmpp2);
			tmpp2=NULL;
		}
	}
	data=fopen("ogrenciler.txt","w");
	if(data!=NULL){
		tmpp = *head;	
		while(tmpp!=NULL)
		{
			fprintf(data,"%ld %s %s %d %d\n",tmpp->Numara,tmpp->Ad,tmpp->Soyad,tmpp->ToplamKredisi,tmpp->DersSayisi);
			tmpp=tmpp->next;
			
		}
		fclose(data);
	}
}

DERSBILGISI *dersBilgisiEkle(char DersKodu[],char DersAdi[],int ToplamKredi,int Kontenjan)
{
	DERSBILGISI* tmp;
	tmp = (DERSBILGISI*) malloc(sizeof(DERSBILGISI));	
	strcpy(tmp->DersAdi,DersAdi);
	strcpy(tmp->DersKodu,DersKodu);
	tmp->ToplamKredi = ToplamKredi;
	tmp->Kontenjan = Kontenjan;
	tmp->next = NULL;
	return tmp;
}



void dersEkle(DERSBILGISI **head, char DersKodu[],char DersAdi[],int ToplamKredi,int Kontenjan){
	int i=0;
	DERSBILGISI *tmp;
	FILE *data;
	DERSBILGISI *yeniDersBilgisi=dersBilgisiEkle(DersKodu,DersAdi,ToplamKredi,Kontenjan);
	if(*head==NULL){
		*head = yeniDersBilgisi;
	}
	else{
		tmp = *head;
		while(tmp->next!= NULL && (strcmp(tmp->next->DersKodu,DersKodu)<0)){
			tmp= tmp->next;
			i++;
		}
		if(tmp==*head && tmp->DersKodu > DersKodu)
		{
			*head=yeniDersBilgisi;
			yeniDersBilgisi->next = tmp;
		}
		else
		{
			if(tmp->next==NULL){
			tmp->next=yeniDersBilgisi;
		}
		else{
			yeniDersBilgisi->next = tmp->next;
			tmp->next=yeniDersBilgisi;	
		}
		}	
	}
	
	data=fopen("dersler.txt","w");
	if(data!=NULL){
		tmp = *head;	
		while(tmp!=NULL)
		{
			fprintf(data,"%s %s %d %d\n",tmp->DersKodu,tmp->DersAdi,tmp->ToplamKredi,tmp->Kontenjan);
			tmp=tmp->next;
			
		}
		fclose(data);
	}
	
}


void dersSil(DERSBILGISI **head,char DersKodu[]){
	DERSBILGISI *tmp,*tmp2;
	FILE *data;
	if((strcmp((*head)->DersKodu,DersKodu)==0)){
		tmp=(*head)->next;
		printf("%s silindi\n",(*head)->DersKodu);
		free(*head);
		(*head)->next=NULL;
		*head = tmp;		
	}
	else{
		tmp = *head;
		while(tmp->next!=NULL && (strcmp(tmp->next->DersKodu,DersKodu)!=0)){
			tmp = tmp->next;
		}
		if(tmp== NULL){
			printf("bulunamadi!\n");
		}
		else{
			tmp2=tmp->next;
			tmp->next=tmp->next->next;
			printf("\n%s silindi\n",tmp2->DersKodu);
			free(tmp2);
			tmp2=NULL;
		}
	}
	
	data=fopen("dersler.txt","w");
	if(data!=NULL){
		tmp = *head;	
		while(tmp!=NULL)
		{
			fprintf(data,"%s %s %d %d\n",tmp->DersKodu,tmp->DersAdi,tmp->ToplamKredi,tmp->Kontenjan);
			tmp=tmp->next;
			
		}
		fclose(data);
	}
}

DERSBILGISI *dersAra(DERSBILGISI **head, char DersKodu[]){
	DERSBILGISI *tmp;
	int i=1;
		tmp = *head;
		tmp->mem=0;
		while(tmp->next!= NULL && (strcmp(DersKodu,tmp->DersKodu)>0)){
			tmp= tmp->next;
			tmp->mem=i;
			i++;
			
		}
		if(strcmp(DersKodu,tmp->DersKodu)==0){
			
			return tmp;
			
		}
		else{
			printf("eleman bulunamadi:\n");
			return NULL;	
		}
}
OGRENCI *ogrenciAra(OGRENCI **head1, long Numara){
	OGRENCI *tmpp;
		tmpp = *head1;
		while(tmpp->next!= NULL && tmpp->Numara < Numara){
			tmpp= tmpp->next;
		}
		if(tmpp->Numara==Numara){
			return tmpp;
		}
		else{
			printf("eleman bulunamadi:");
			return 0;	
		}
}


void ogrenciDersBilgisiGuncelle(OGRENCIDERSBILGISI ogrenciler[],int n,long OgrenciNo,char DersKodu[],char Durum[])
{
	int i=0,j=0;
	FILE *data;

    data=fopen("ogrenciDersKayit.txt","w");
	if(data!=NULL){		
		{
		if(strcmp(DersKodu,"derskod")==0 || OgrenciNo==0)
		{
			while((strcmp(ogrenciler[i].DersKodu,DersKodu)!=0) && ogrenciler[i].OgrenciNo!=OgrenciNo && ogrenciler[i].ID==i+1)
			{
				i++;
			}
				if(ogrenciler[i].ID==i+1)
			{
				strcpy(ogrenciler[i].Durum,Durum);
			}
		}
		else
		{
		while((strcmp(ogrenciler[i].DersKodu,DersKodu)!=0) || ogrenciler[i].OgrenciNo!=OgrenciNo && ogrenciler[i].ID==i+1)
			{
				i++;
			}
			if(ogrenciler[i].ID==i+1)
			{
				strcpy(ogrenciler[i].Durum,Durum);
			}
				
		}
			
		}
		for(i=0;i<n;i++)
		{
				fprintf(data,"%d %s %ld %s %s\n",ogrenciler[i].ID,ogrenciler[i].DersKodu,ogrenciler[i].OgrenciNo,ogrenciler[i].Tarih,ogrenciler[i].Durum);
		}
		
		
		fclose(data);
	}
}
OGRENCIDERSBILGISI * ogrenciDersBilgisi(OGRENCIDERSBILGISI * head,int n,char DersKodu[],long OgrenciNo,char Durum[],char Tarih[]){
	int i=0;
	FILE *data;
	if(head==NULL){
	head=(OGRENCIDERSBILGISI *)malloc(sizeof(OGRENCIDERSBILGISI));
	head[0].ID=1;
	strcpy(head[0].DersKodu,DersKodu);
	head[0].OgrenciNo=OgrenciNo;
	strcpy(head[0].Tarih,Tarih);
	strcpy(head[0].Durum,Durum);
	}
	else{
	head=(OGRENCIDERSBILGISI*)realloc(head,(n)*sizeof(OGRENCIDERSBILGISI));
	head[(n)-1].ID=n;
	strcpy(head[(n)-1].DersKodu,DersKodu);
	head[(n)-1].OgrenciNo=OgrenciNo;
	strcpy(head[(n)-1].Tarih,Tarih);
	strcpy(head[(n)-1].Durum,Durum);	
		
	}
	
	data=fopen("ogrenciDersKayit.txt","w");
	if(data!=NULL){		
	while(i<n)
		{
			fprintf(data,"%d %s %ld %s %s\n",head[i].ID,head[i].DersKodu,head[i].OgrenciNo,head[i].Tarih,head[i].Durum);
		i++;
		}
		fclose(data);
	}
	
	return head;
	
	
	
}
void ogrenciGuncelle(OGRENCI **head, long Numara,char Ad[],char Soyad[],int DersSayisi,int ToplamKredisi)
{
	FILE *data;
	OGRENCI *tmp;
	tmp = *head;
	data=fopen("ogrenciler.txt","w");
		
	if(data!=NULL){		
		{
			while(tmp!= NULL ){
			fprintf(data,"%ld %s %s %d %d\n",tmp->Numara,tmp->Ad,tmp->Soyad,tmp->ToplamKredisi,tmp->DersSayisi);
			tmp= tmp->next;
		}
	
		
		}
		fclose(data);
	}
	
}
void ogrencileriListele(OGRENCIDERSBILGISI ogrenciler[],char DersKodu[],int n)
{
	FILE *data;
	int i=0,m=0;
	if(i==n)
	{
		printf("listelenecek ogrenci bulunamadi");
	}
	else
	{
		while(i<n)
	{
		
	if(strcmp(ogrenciler[i].DersKodu,DersKodu)!=0)
	{
				i++;
	}
	else if(strcmp(ogrenciler[i].DersKodu,DersKodu)==0)
	{
		if(strcmp(ogrenciler[i].Durum,"kayitli")==0)
		{
		printf("%ld\n",ogrenciler[i].OgrenciNo);
				data=fopen("DERSKODU.txt","a");
				if(data!=NULL){		
		        {
				fprintf(data,"%ld\n",ogrenciler[i].OgrenciNo);
	         	}
		        
	}
				i++;
				m++;	
		}
		else
		{
			i++;
		}
				
	}	
	
	}
	
	if(m==0)
	{
		printf("listelenecek ogrenci bulunamadi");
	}
	else{
		fclose(data);
	}
	}
		
}

void derseOgrenciEkle(OGRENCIDERSBILGISI **head,DERSBILGISI **head1,OGRENCI **head2,char DersKodu[],long OgrenciNo,char Tarih[],int length[])
{
		int i=0,j=0;
		 DERSBILGISI *temp;
		 OGRENCI *temp3;

		temp3=ogrenciAra(head2,OgrenciNo);
		temp = * head1;
		while(temp->next!= NULL && (strcmp(temp->DersKodu,DersKodu)<0)){
			temp= temp->next;
			i++;
		}
		
		if(length[i]==0)
		{
		temp->next2=(long*)calloc(temp->Kontenjan ,sizeof(long));
		}
		
		while(j<=length[i] && OgrenciNo>temp->next2[j])
		{
			j++;
		}
		
		temp->next2[j-1]=OgrenciNo;
		length[i]++;
	    temp3->DersSayisi++;
	    temp3->ToplamKredisi=temp3->ToplamKredisi+temp->ToplamKredi;
	    ogrenciGuncelle(head2,temp3->Numara,temp3->Ad,temp3->Soyad,temp3->DersSayisi,temp3->ToplamKredisi);
        
}
void dersleriListele(OGRENCIDERSBILGISI ogrenciler[],long OgrenciNo,int n)
{
	FILE *data;
	int i=0;
	int m=0;
	if(i==n)
	{
		printf("listelenecek ders bulunamadi");
		printf("\n");
	}
	else
	{
	while(i<n)
	{
		
	if(ogrenciler[i].OgrenciNo!=OgrenciNo)
	{
				i++;
	}
	else if(ogrenciler[i].OgrenciNo==OgrenciNo)
	{
		if(strcmp(ogrenciler[i].Durum,"kayitli")==0)
		{
			printf("%s\n",ogrenciler[i].DersKodu);
				data=fopen("OGRENCINO_DERSPROGRAMI.txt","a");
				if(data!=NULL){		
		        {
				fprintf(data,"%s\n",ogrenciler[i].DersKodu);
	         	}
				i++;
				m++;
		}
				
	}
	else
	{
		i++;
		}	
	
	}
		
	}

	if(m==0)
	{
		printf("listelenecek ders bulunamadi\n");
		
	}
	else
	{
			fclose(data);
	}
	
		
			
}
}
DERSBILGISI* DersOkuVeYazdir(DERSBILGISI *head)
{
	DERSBILGISI *yeniDersOku=yeniDersOkuEkle();
	FILE *fp;	
	fp = fopen("dersler.txt", "r");
	if(fp==NULL){
		printf("Dosya bulunamadi");
		return NULL;
		
	}
	
	while(fscanf(fp,"%s %s %d %d\n",yeniDersOku->DersKodu,yeniDersOku->DersAdi,&yeniDersOku->ToplamKredi,&yeniDersOku->Kontenjan)!=EOF)
	{
		dersEkle(&head,yeniDersOku->DersKodu,yeniDersOku->DersAdi,yeniDersOku->ToplamKredi,yeniDersOku->Kontenjan);
		yeniDersOku=yeniDersOkuEkle();
	}

	fclose(fp);
	return head;
	
}
OGRENCI *OgrenciOkuVeYazdir(OGRENCI *head)
{ 
    OGRENCI *yeniOgrenciOku=yeniOgrenciOkuEkle();
	FILE *fp;	
	fp = fopen("ogrenciler.txt", "r");
	if(fp==NULL){
		printf("Dosya bulunamadi");
		return NULL;
		
	}
	while(fscanf(fp,"%ld %s %s %d %d\n",&yeniOgrenciOku->Numara,yeniOgrenciOku->Ad,yeniOgrenciOku->Soyad,&yeniOgrenciOku->ToplamKredisi,&yeniOgrenciOku->DersSayisi)!=EOF)
	{
		yeniogrenciEkle(&head,yeniOgrenciOku->Numara,yeniOgrenciOku->Ad,yeniOgrenciOku->Soyad,yeniOgrenciOku->ToplamKredisi,yeniOgrenciOku->DersSayisi);
		yeniOgrenciOku=yeniOgrenciOkuEkle();
	}

	fclose(fp);
	return head;
}

OGRENCIDERSBILGISI *OgrenciDersOkuVeYazdir(OGRENCIDERSBILGISI *head,int length[],DERSBILGISI *head1,OGRENCI *head2)
{ 
    OGRENCIDERSBILGISI *yeniOgrenciDersOku=yeniOgrenciDersOkuEkle();
	FILE *fp;	
	fp = fopen("ogrenciDersKayit.txt", "r");
	if(fp==NULL){
		printf("Dosya bulunamadi");
		return NULL;
		
	}
	while(fscanf(fp,"%d %s %ld %s %s\n",&yeniOgrenciDersOku->ID,yeniOgrenciDersOku->DersKodu,&yeniOgrenciDersOku->OgrenciNo,yeniOgrenciDersOku->Tarih,yeniOgrenciDersOku->Durum)!=EOF)
	{
		head=ogrenciDersBilgisi(head,yeniOgrenciDersOku->ID,yeniOgrenciDersOku->DersKodu,yeniOgrenciDersOku->OgrenciNo,yeniOgrenciDersOku->Durum,yeniOgrenciDersOku->Tarih);
		if(strcmp(yeniOgrenciDersOku->Durum,"kayitli")==0)
		{
			derseOgrenciEkle(&head,&head1,&head2,yeniOgrenciDersOku->DersKodu,yeniOgrenciDersOku->OgrenciNo,yeniOgrenciDersOku->Tarih,length);
		}
		yeniOgrenciDersOku=yeniOgrenciDersOkuEkle();
	}

	fclose(fp);
	return head;
}

OGRENCI *yeniOgrenciOkuEkle()
{
	OGRENCI* tmp;
	tmp = (OGRENCI*) malloc(sizeof(OGRENCI));

	return tmp;
}

DERSBILGISI *yeniDersOkuEkle()
{
	DERSBILGISI* tmp;
	tmp = (DERSBILGISI*) malloc(sizeof(DERSBILGISI));	
	
	return tmp;
}

OGRENCIDERSBILGISI *yeniOgrenciDersOkuEkle()
{
	OGRENCIDERSBILGISI* tmp;
	tmp = (OGRENCIDERSBILGISI*) malloc(sizeof(OGRENCIDERSBILGISI));	
	
	return tmp;
}




