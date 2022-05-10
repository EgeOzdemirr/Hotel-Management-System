#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>


void ekle();  
void list();
void edit();  
void silme();
void arama();



struct MusteriDetaylari
{
	char odanumarasi[10];
	char isim[20];
	char adres[25];
	char telefonumarasi[15];
	char email[20];
	char kalmasuresi[10];
	char varistarihi[10];
}s;

int main()
{
	char musteriadi;
	char secim;
	
while(1)
{
	system("cls");
		
		 for(int i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |ANA MENU|  ***************************** \n");
		for(int i=0;i<80;i++)
		printf("-");
		printf("\n");
		
		printf("\t\t *Yapmak istediginiz islemi seciniz:");
		printf("\n\n");
		printf(" \n Enter 1 -> Oda tut");
		printf("\n------------------------");
		printf(" \n Enter 2 -> Musteri kayitlarina bak");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Musteri kayit sil");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Musteri kayit ara");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Kayit editle");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Cikis");
		printf("\n-----------------");
		printf("\n");
		secim=getche();
		secim=toupper(secim);
		
		switch(secim)
		{
			case '1' :
				ekle();break;
			case '2' :
				list();break;
			case '3' :
				silme();break;
			case '4' :
				arama();break;
			case '5' :
				edit();break;
			case '6' :
				system("cls");
				printf("\n\n\t *****TESEKKUR EDERIZ*****");
				printf("\n\t BIZI SECTIGINIZ ICIN");
				exit(0);
				break;
			default :
				system("cls");
				printf("Yanlis Secim");
				printf("\n Devam etmek icin herhangi bir tusa bas");
				getch();
		}
	
}
	
}

void ekle()
{
	
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	while(1)
	{
		system("cls");
		printf("\n Musteri detaylarini giriniz:");
		printf("\n**************************");
		printf("\n Oda numarasi:\n");
		scanf("\n%s",s.odanumarasi);
		fflush(stdin);
		printf("Isim giriniz:\n");
		scanf("%s",s.isim);
		printf("Adresinizi giriniz:\n");
		scanf("%s",s.adres);
		printf("Telefon numaranizi giriniz:\n");
		scanf("%s",s.telefonumarasi);
		printf("Emailinizi giriniz:\n");
		scanf(" %s",s.email);
		printf("Kac gun kalacaginizi giriniz (\'x\'gün):\n");
		scanf("%s",&s.kalmasuresi);
		printf("Gelis taririnizi giriniz (dd\\mm\\yyyy):\n");
		scanf("%s",&s.varistarihi);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Oda basariyla rezerve edildi!!");
		printf("\n Cikmak icin 'esc' basiniz, baska musteri eklemek icin herhangi bir tusa basiniz:");
		test=getche();
		if(test==27)
			break;
		
	}
	fclose(f);
}

void list()
{
	FILE *f;	
		int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("\tODA    ");
	printf("ISIM\t ");
	printf("\tADRES ");
	printf("\tTELEFON NUMARASI ");
	printf("\t ");
	printf("\tEMAIL ");
	printf("\t\t  KALIS SURESI ");
	printf("\t GELIS TARIHI \n");
		for(i=0;i<118;i++)
		printf("-");
	
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%s \t%s \t\t%s  \t%s  \t%s  \t     %s  \t  %s",s.odanumarasi, s.isim , s.adres , s.telefonumarasi ,s.email,s.kalmasuresi,  s.varistarihi);
	}
	fclose(f);
	getch();
}

void silme()
{
	FILE *f,*t;	
	int i=1;
	char odanumarasi[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Silmek istediginiz otel odasi numarasini giriniz: \n");
	fflush(stdin);
	scanf("%s",odanumarasi);
		while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.odanumarasi,odanumarasi)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
		
	if(i==1)
	{       
		printf("\n\n Bu Oda numarasindaki Musteri kayitlari bulunamadi!!");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nMusteri kaydi basariyla kaldirildi....");
	fclose(f);
	fclose(t);
	getch();
}

void arama()
{
system("cls");
	FILE *f;
	char odanumarasi[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Ayrintilarini aramak icin musterinin Oda numarasini girin: \n");
	scanf("%s", odanumarasi);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.odanumarasi,odanumarasi)==0)
		{
			flag=0;
			printf("\n\tKayit Bulundu\n ");
			printf("\nOda Numarasi:\t%s",s.odanumarasi);
			printf("\nIsim:\t%s",s.isim);
			printf("\nAdres:\t%s",s.adres);
			printf("\nTelefon Numarasi:\t%s",s.telefonumarasi);
			printf("\nEmail:\t%s",s.email);
			printf("\nKalma Suresi:\t%s",s.kalmasuresi);
			printf("\nGelis Tarihi:\t%s",s.varistarihi);
			flag=0;
			break;
		}
	}
	if(flag==1)
	{	
		printf("\n\tIstenilen musteri kaydi bulunamadi");
	}
	getch();
	fclose(f);
	
	
}

void edit()
{
	FILE *f;
	int k=1;
	char odanumarasi[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Editlemek istediginiz odanin numarasini giriniz:\n\n");
	scanf("%[^\n]",odanumarasi);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
			if(strcmp(s.odanumarasi,odanumarasi)==0)
		{
			k=0;
			printf("\nOda Numarasini Giriniz     :");
			gets(s.odanumarasi);
			printf("\nIsim giriniz    :");
			fflush(stdin);
			scanf("%s",&s.isim);
			printf("\nAdres giriniz        :");
			scanf("%s",&s.adres);
			printf("\nTelefon numarasi giriniz :");
			scanf("%f",&s.telefonumarasi);
			printf("\nEnter Email :");
			scanf("%s",&s.email);
			printf("\nKalma suresi :");
			scanf("%s",&s.kalmasuresi);
			printf("\nVaris tarihini giriniz :");
			scanf("%s",&s.varistarihi);
			fseek(f,size,SEEK_CUR);  
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(k==1)
	{
		printf("\n\nBu kayit bulunamadi!!!!");
		fclose(f);
		getch();
	}
	else
	{
	fclose(f);
	printf("\n\n\t\tKayit basariyla editlendi!!!");
	getch();
	}
}

















