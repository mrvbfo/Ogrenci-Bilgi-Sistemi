//OGRENCÝ BÝLGÝ SÝSTEMÝ PROJESÝ
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct dersnotu{
	float vize;
	char ogrNo;
	float final;
	int bolumkodu;	
}notlar;

struct ogrenci{
	char ad[20];
	char soyad[20];
	char no[5];
	int staj; // staj degeri 1'e eþitse baþarýlý, 0'a eþitse baþarýsýz
	char sifre[5];
	char bolum[12];
	int bolumkod;
	int ders[20];
	float vize;
	float final;
	int topakts;
	int mezun; //mezun degeri 1'e eþitse mezun olmus 2 ise aktif ogrenci 0'a eþitse öðrencilikten atilmis
	char dogumtarihi[20];
	char dogumyeri[20];
	char cinsiyet[6];
	int altDersSayisi;
	int altDersSayisi2;
}ogr[100];

struct ogrUyesi{
	char ad[20];
	char soyad[20];
	char kullaniciadi[20];
	char sifre[20];
	int ders[24];
}ogrUye[4];

struct memur{
	char ad[20];
	char soyad[20];
	char kullaniciadi[20];
	char sifre[20];
}memur1;

struct ders{
	char ad[50];
	char kod[10];
	int bolumkod;
	char ogretmeni[20];
	char ogrtsifre[20];
}dersler[12];

struct bolumler{
	char ad[50];
	int bolumkod;
}bolum[3]={{"Yazilim",1000},{"Bilgisayar",2000},{"Bilisim Sis",3000}};

void yoneticiPaneli();
void OgretimUyeKayit();
void MemurKayit();
void MemurPaneli();
void OgrenciKayidi();
void dersEkle();
void notgirisi();
void notgirisi2();
void stajdurumu();
void OgrenciPaneli();
void ogrencibelgesi(struct ogrenci s);
void OgrenciMezunMu(struct ogrenci s);
void ogrSil(struct ogrenci s);
void ogrMezuniyet();

int main(){
	int i,choice;

	yoneticiPaneli(); //Sisteme giris icin yonetici dogrulamasý yapar

	do{ 
	printf("1)Memur Girisi\n2)Not Girisi\n3)Alttan Kalanlar Not Girisi\n4)Staj Durumu\n5)Ogrenci Girisi (Not Durumu)\n6)Ogrenci Mezun Sorgulama\n7)Cikis\n");
	printf("Sisteme giris yonteminizi seciniz: (1)/(2)/(3)/(4)/(5)/(6)/(7)\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:system("CLS");MemurPaneli();break;
			case 2:system("CLS");notgirisi();break;
			case 3:system("CLS");notgirisi2();break;
			case 4:system("CLS");stajdurumu();break;
			case 5:system("CLS");OgrenciPaneli();break;
			case 6:system("CLS");ogrMezuniyet();break;
		}
	
	}while(choice!=7);


	return 0;
}

void yoneticiPaneli(){
	char yoneticiAdi[20]="Merve";
	char yoneticiSifre[20]="12345";
	char sifreDogrulama[20];
	char adDogrulama[20];
	int choice;
	
	printf("***************OGRENCI BILGI SISTEMI***************\n\n");
	printf("Ogrenci Bilgi Sistemine Hosgeldiniz...\n\n");
	printf("Sisteme erisim icin yonetici girisi gerekmektedir...\nDevam etmek icin bir tusa basiniz.\n");
	getch(); 
	system("CLS");//Ekrandaki yazýlarý temizler
	fflush(stdin);
	printf("Yonetici Giris Ekrani\n");
	printf("Kullanici adi  :");
	gets(adDogrulama);
	fflush(stdin);
	printf("\nSifre          :");
	gets(sifreDogrulama);
	fflush(stdin);
	
if(strcmp(yoneticiSifre,sifreDogrulama)==0 && strcmp(adDogrulama,yoneticiAdi)==0){ //Yonetici sifre ve kullanici adi dogrulamasi yapar
		printf("Kimlik dogrulama basarili...");
		getch();
		system("CLS");
		printf("\nHosgeldiniz, %s\n\n",yoneticiAdi);
		printf("Yonetici Paneli\n");
		printf("****************\n");
	
		do{
		printf("1-Ogretim Uyesi Kayidi\n2-Ogrenci Isleri Personeli(Memur) Kayidi\n3.Cikis\n");
		printf("Islem secimi yapiniz (1)-(2)-(3) :");
		fflush(stdin);
		scanf("%d",&choice);
		fflush(stdin);
	
			switch(choice){
				case 1:system("CLS");OgretimUyeKayit();break; 
				case 2:system("CLS");MemurKayit();break;
			}
		
		}while(choice!=3);
		system("CLS");
	}
	else{
		printf("Kimlik dogrulama basarisiz...\nCikmak icin bir tusa basiniz.\n");
		getch();
		fflush(stdin);
		system("CLS");
		yoneticiPaneli(); // kimlik dogrulamasi yanlis ise yeniden giris yapabilmek icin
		
	}
}

void OgretimUyeKayit(){
	FILE *fPtr_ogruye;
	fPtr_ogruye= fopen("ogruyesi.txt","a");
	int i;
	
	if(fPtr_ogruye == NULL){
  		puts("Dosya acilamadi.");
  		exit(EXIT_FAILURE);
  	}
  	puts("\n4 Ogretim uyesinin kayidinin yapilmasi gerekiyor.");
  	for(i=0;i<4;i++){
  		printf("%d.Ogretim Uyesi\n",i+1);
  		printf("Adi          :");
  		gets(ogrUye[i].ad);
  		printf("Soyadi       :");
  		gets(ogrUye[i].soyad);
  		printf("Kullanici Adi:");
  		gets(ogrUye[i].kullaniciadi);
  		printf("Sifresi      :");
  		gets(ogrUye[i].sifre);
  		
  		fprintf(fPtr_ogruye,"%s %s %s %s\n",ogrUye[i].ad,ogrUye[i].soyad,ogrUye[i].kullaniciadi,ogrUye[i].sifre); //Ogretim uyesi bilgilerinin dosyada tutulmasini saglar
  		
	  	printf("\n%d. Ogretim Uyesinin bilgileri kaydedildi.\nKayidinin yapilmasi gereken %d ogretim uyesi kaldi.\n",i+1,3-i);
	  	printf("Devam etmek icin bir tusa basiniz.\n\n");
	  	getch();
	  }
	  
	system("CLS");
  	fclose(fPtr_ogruye);
}

void MemurKayit(){
	FILE *fPtr_memur;
	fPtr_memur=fopen("memur.txt","a");
		if(fPtr_memur == NULL){
  		puts("Dosya acilamadi.");
  		exit(EXIT_FAILURE);
  	}
  	puts("\n1 Ogrenci Isleri Personeli(Memur) kayidinin yapilmasi gerekiyor.");
  	
  	printf("Adi:");
  	gets(memur1.ad);
  	printf("Soyadi:");
  	gets(memur1.soyad);
	printf("Kullanici adi:");
  	gets(memur1.kullaniciadi);
	printf("Sifresi:");
  	gets(memur1.sifre);
  		
  	fprintf(fPtr_memur,"%s %s %s %s\n",memur1.ad,memur1.soyad,memur1.kullaniciadi,memur1.sifre); //Memur bilgilerinin dosyada tutulmasini saglar
  		
	printf("\n1 Ogrenci Isleri Personeli(Memur) kayidi tamamlanmistir\n");
	printf("Devam etmek icin bir tusa basiniz.\n");
	getch();
	  
	system("CLS");
  	fclose(fPtr_memur);
}

void MemurPaneli(){
	char memurKullanici[20];
	char memurSifre[20];
	int choice;
	fflush(stdin);
	printf("Memur Paneline Hosgeldiniz.\nSisteme erisim icin sifre kullanici adi dogrulamasi gerekiyor.\nKullanici adi:");
	gets(memurKullanici);
	fflush(stdin);
	if(strcmp(memurKullanici,memur1.kullaniciadi)!=0){
		printf("Sistemde boyle bir kullanici bulunmamaktadir. Yoneticinin kayit yapmasi gerekmektedir."); //Memur kullanici adi dogrulamasi
	}
	printf("\nSifre:");
	gets(memurSifre);
	fflush(stdin);
	
	if(strcmp(memurSifre,memur1.sifre)==0){ //Memur girisi sifre dogrulamasi 
		printf("Kimlik dogrulama basarili...");
		getch();
		system("CLS");
		printf("\nHosgeldiniz, %s\n\n",memurKullanici);
		printf("Memur Paneli\n");
		printf("****************\n");
	
		do{
		printf("1-Ogrenci Kayidi\n2-Ogretim Uyesine Ders Acma\n3-Cikis\n");
		printf("Islem secimi yapiniz (1)-(2)-(3) :");
		fflush(stdin);
		scanf("%d",&choice);
		fflush(stdin);
	
		switch(choice){
			case 1:system("CLS");OgrenciKayidi();break;
			case 2:system("CLS");dersEkle();break;
		}
		
		}while(choice!=3); 
		system("CLS");
	}
	
}

void OgrenciKayidi(){
	FILE *fPtr_ogr;
	fPtr_ogr= fopen("ogrenci.txt","a");
	int sayac=0,temp,i;
	
	if(fPtr_ogr == NULL){
  		puts("Dosya acilamadi.");
  		exit(EXIT_FAILURE);
  	}
  	
  	puts("\nOgrenci kayidi icin bilgileri giriniz:\n");
  	do{
  		printf("Devam etmekicin bir tusa basiniz.");
  		getch();
  		system("CLS");
		sayac++;
		if(sayac>100){ //100 ogrencinin kayidinin yapilmasina izin verilmistir
			puts("Sistem esnekligi 100 ogrenciye kadardir. Kayit islemi bitmistir."); 
			puts("Ana menuye yonlendiriliyorsunuz.");
		}
		else{
		fflush(stdin);
		printf("%d.Ogrenci:\n",sayac);
 		printf("Adi             :");
		gets(ogr[sayac].ad);
		fflush(stdin);
		printf("Soyadi          :");
		gets(ogr[sayac].soyad);
		fflush(stdin);
		printf("Ogrenci eklemek istediginiz bolumun kodunu giriniz:\nYazilim Muhendisligi(1000)/Bilgisayar Muhendisligi(2000)/Bilisim Sistemleri Muhendisligi(3000)\n");
		printf("Bolum kodu      :"); //Bolumler tanýtýlýr ona gore bir secim yapilmasi istenir
		scanf("%d",&ogr[sayac].bolumkod);
		fflush(stdin);
		printf("Dogum Yeri      :");
		gets(ogr[sayac].dogumyeri);
		fflush(stdin);
		printf("Cinsiyet        :");
		gets(ogr[sayac].cinsiyet);
		fflush(stdin);
		printf("Numarasi       :");
		gets(ogr[sayac].no);
		fflush(stdin);
		printf("Sifresi        :");
		gets(ogr[sayac].sifre);
		fflush(stdin);
		fprintf(fPtr_ogr,"%s %s %s %s %s %s %d\n",ogr[sayac].ad,ogr[sayac].soyad,ogr[sayac].no,ogr[sayac].sifre,ogr[sayac].dogumyeri,ogr[sayac].cinsiyet,ogr[sayac].bolumkod); //girilen bilgiler dosyaya yazdirilir
		puts("Yeni bir kayit icin bir tusa, cikmak icin ESC tusuna basiniz."); 
		}
	}while(getch()!=27);
 
	fclose(fPtr_ogr);
	puts("\nOgrenci kayit islemi tamamlanmistir..."); 
	getch();
}

void dersEkle(){
	int kod,i,j,k,temp,secim,sayac,bolumkod;
	FILE *fPtr_ders;
	fPtr_ders=fopen("dersler.txt","a");
	
	if(fPtr_ders == NULL){
 	 	puts("Dosya acilamadi.");
 	 	exit(EXIT_FAILURE);
 	}
 	printf("Ders eklemek istediginiz bolumun kodunu giriniz:\nYazilim Muhendisligi(1000)/Bilgisayar Muhendisligi(2000)/Bilisim Sistemleri Muhendisligi(3000)\n");
	printf("Bolum Kodu   :");
	scanf("%d",&bolumkod);
	fflush(stdin);
 	for(i=0;i<8;i++){
 		dersler[i].bolumkod=bolumkod;
		printf("%d.Dersin,\n",i+1);
 	 	printf("Adi      :");
		gets(dersler[i].ad);
		fflush(stdin);
		printf("Ders Kodu     :");
		gets(dersler[i].kod);
		fflush(stdin);
		printf("Ders icin ogretim uyesi seciniz:\n"); //Sisteme kayitli ogretim uyeleri kullaniciya gösterilir.
  		for(j=0;j<4;j++){
  			printf("%d)%s %s\n",j+1,ogrUye[j].ad,ogrUye[j].soyad);
		}
		printf("Ogretim Uyesinin Adi     :");
		gets(dersler[i].ogretmeni); //her dersin ogretmeni struct yapisiyla kayit edilir.
		fflush(stdin);
		for(k=0;k<4;k++){
			if(strcmp(dersler[i].ogretmeni,ogrUye[k].ad)==0){
				strcpy(dersler[i].ogrtsifre,ogrUye[k].sifre);
			}
		}
		fprintf(fPtr_ders,"%s %d %s %s\n",dersler[i].ad,dersler[i].bolumkod,dersler[i].kod,dersler[i].ogretmeni); //ders bilgileri dosyaya kayit edilir.
	}
  fclose(fPtr_ders);
}

void notgirisi(){
	FILE *fPtr_notlar=fopen("notlar.txt","a");
	FILE *fPtr_alttan=fopen("alttan.txt","a");
	char ogrencino[5];
	int i,temp,secim,sayac=0;
	float vizenot,finalnot,ort;
	char OgrUyeKullanici[20];
	char OgrUyeSifre[20];
	char OgrUyeKontrol[20];
	char dersad[20],derskod[5],dershocasi[20];
	int bkod;
	fflush(stdin);
	puts("\nOgrenci Not Girisi\n");
	printf("Ogretim Uyesi Girisi\n");
  	printf("Ogretim Uyesinin Kimlik Dogrulamasi yapmasi gerekmektedir...\n");
	printf("Ogretim uyesinin adi :");
	gets(OgrUyeKullanici);
	fflush(stdin);
	printf("Sifre                :");
	gets(OgrUyeSifre);
	fflush(stdin);
	for(i=0;i<4;i++){
		if((strcmp(OgrUyeKullanici,ogrUye[i].kullaniciadi)==0) && (strcmp(OgrUyeSifre,ogrUye[i].sifre)==0) ){ //ogretim uyesinin kimlik dogrulamasi yapilir
			printf("Kimlik dogrulama basarili...");
			getch();
			system("CLS");
			temp=i;
			printf("\nHosgeldiniz, %s\n\n",ogrUye[i].kullaniciadi);
		}
	}
	
	printf("Not girisi yapmak istediginiz ogrencinin numarasini giriniz   :");
	gets(ogrencino);
	fflush(stdin);
	printf("Not girisi yapmak istediginiz dersin adini giriniz             :");
	gets(dersad);
	fflush(stdin);
	printf("Vize Notu    :");
    scanf("%f",&vizenot);
	fflush(stdin);
    printf("Final Notu    :");
    scanf("%f",&finalnot);
    fflush(stdin);
	ort=vizenot*0.4+finalnot*0.6;
	printf("Ogrenci ortalamasi:%f\n",ort);
	if(ort<50){  	// not ortalamasi 50 altindaysa dersten kaldigi kabul edilir.
		ogr[i].altDersSayisi=+1; //alttan ders sayisi dersten kaldigi icin arttirilir
		fprintf(fPtr_alttan,"%s %s %f %f %f\n",ogrencino,dersad,vizenot,finalnot,ort); //alttan derslerin bilgisi dosyaya yazdirilir
	}
	fprintf(fPtr_notlar,"%s %s %f %f %f\n",ogrencino,dersad,vizenot,finalnot,ort);	//alttan derslerin ve diger derslerin bilgileri dosyaya yazdirilir
	
	for(i=0;i<100;i++){
		ogr[i].altDersSayisi2=ogr[i].altDersSayisi; //alttan dersi olanlarin 5. ve 6. yariyilda tamamlamasini kontrol etmek icin
	}
	
	fclose(fPtr_alttan);
	fclose(fPtr_notlar);
	getch();
}

void notgirisi2(){
	FILE *fPtr_alttan=fopen("fPtr_alttan","r");
	printf("5 ve 6. yarýyýl icin not girisi.");
	char ogrencino[5];
	int i,temp,secim;
	float vize,final,ort;
	char OgrUyeKullanici[20];
	char OgrUyeSifre[20];
	char OgrUyeKontrol[20];
	char ad[20],ders[50];

	printf("Altan dersi olan öðrenci listesi:\n");
	while(fscanf(fPtr_alttan,"%s\n%s %f %f %f\n",ad,ders,&vize,&final,&ort)!=EOF){ //alttan ders dosyasini okunur
		for(i=0;i<100;i++){
			if(strcmp(ad,ogr[i].ad)==0){
			printf("%s %s",ogr[i].ad,ogr[i].no); //ekrana alttan dersi olan ogrencilerin ciktisi verilir
		}
	}

	do{
	printf("Not girisi yapmak istediginiz Ogrencinin numarasini giriniz:\n");
	gets(ogrencino); //ogrenciye not girisi
	
	for(i=0;i<100;i++){
		if(strcmp(ogrencino,ogr[i].no)==0){ //structtan ogrencinin bilgilerine erismek icin girilen numara bilgisi karsilastirilir
			temp=i; //bulunan ogrencinin indisi bir temp degerine aktarilir
		}
	}
	printf("Ogrenci Bilgisi\nAd:%s\nBolum:%d\n",ogr[temp].ad,ogr[temp].bolumkod);
	printf("Ogrencinin Ders Listesi:\n");
	
	while(!feof(fPtr_alttan)){ //alttan dersi olan ogrencilerin dosyasi okunur
		fflush(stdout);
		fscanf(fPtr_alttan,"%s\n%s %f %f %f\n",ad,ders,&vize,&final,&ort);
		for(i=0;i<100;i++){
			if(strcmp(ad,ogr[temp].ad)==0){ //numarasi girilen ogrenci ile dosyadan okunan ogrencinin bilgileri esit mi kontrol edilir
			printf("%s ",ders); //esit olursa ogrencinin dersleri ekrana yazdirilir
			}
		}
		printf("!Dersin Ogretim Uyesinin Kimlik Dogrulamasi yapmasý gerekmektedir...\n");
		printf("Kullanici adi       :\n");
		gets(OgrUyeKullanici);
		fflush(stdin);
		printf("\nSifre:");
		gets(OgrUyeSifre);
		fflush(stdin);
		if((strcmp(OgrUyeKullanici,dersler[i].ogretmeni)==0) && (strcmp(OgrUyeSifre,dersler[i].ogrtsifre)==0) ){ //dersin ogretim uyesinin kimlik dogrulamasi
			printf("Kimlik dogrulama basarili...");
			getch();
			system("CLS");
			printf("\nHosgeldiniz, %s\n\n",ogrUye[i].kullaniciadi);
			printf("Ogrencinin vize notunu giriniz:\n");
			scanf("%f",&vize);
			fflush(stdin);
			printf("Ogrencinin final notunu giriniz:\n");
			scanf("%f",&final);
			fflush(stdin);
			ort=vize*0.4+final*0.6; //ogrenci ortalamasi hesaplanir.
			printf("Ders Ortalamasi         :%f",ort);
			if(ort>=50){
				ogr[temp].altDersSayisi2=-1; //5. ve 6. yariyilda tamamlanan alttan derslerin sayisi azaltýlýr.
			}
		}
	}
	
	printf("Yeni bir ogrencinin not girisi icin 0'dan farklý bir sayi giriniz.\n");
	}while(secim!=0);

	fclose(fPtr_alttan);
	}
}

void stajdurumu(){
	int i,temp,basari,k;
	char secim[20];
	char memurKullanici[20];
	char memurSifre[20];
	char danisman[20];
	char OgrUyeKullanici[20];
	char OgrUyeSifre[20];
	char OgrUyeKontrol[20];
	char ad[20],soyad[20],no[5],sifre[5],yer[20],cins[6];
	int bkod;
	
	fflush(stdin);
	printf("Memur Paneline Hosgeldiniz.\nSisteme erisim icin sifre kullanici adi dogrulamasi gerekiyor.\nKullanici adi:"); //Memur girisi ile Danýsman Ogretim Uyesi secilir
	gets(memurKullanici);
	fflush(stdin);
	
	if(strcmp(memurKullanici,memur1.kullaniciadi)!=0){ //Memur girisinin dogrulamasi
		printf("Sistemde böyle bir kullanici bulunmamaktadir. Yoneticinin kayit yapmasi gerekmektedir."); 
	}
	printf("\nSifre:");
	gets(memurSifre);
	fflush(stdin);
	
	if(strcmp(memurSifre,memur1.sifre)==0){
		printf("Kimlik dogrulama basarili...");
		getch();
		system("CLS");
		printf("\nHosgeldiniz, %s\n\n",memurKullanici);
		printf("Memur Paneli\n");
		printf("****************\n");
		printf("Staj danismani icin bir ogretim gorevlisi belirleyiniz.\n"); //Ogretim Gorevlileri sýralanir
		for(i=0;i<4;i++){
			printf("%d %s %s\n",i+1,ogrUye[i].ad,ogrUye[i].soyad);
		}
		printf("Danisman seciminiz: (ad giriniz.)\n"); //Danisman hoca olarak secilmesi istenir
		gets(danisman);
		
		printf("Danismanin kimlik dogrulamasi yapmasi gerekmektedir.");//Danisman hoca kimlik dogrulamasi ile sisteme giris yapar
		printf("Ogretim Uyesi Paneline Hosgeldiniz.\nSisteme erisim icin sifre kullanici adi dogrulamasi gerekiyor.\nKullanici adi:");
		gets(OgrUyeKullanici);
		fflush(stdin);
		printf("\nSifre:");
		gets(OgrUyeSifre);
		fflush(stdin);
		for(i=0;i<4;i++){
			if((strcmp(OgrUyeKullanici,ogrUye[i].kullaniciadi)==0) && (strcmp(OgrUyeSifre,ogrUye[i].sifre)==0) ){ //kimlik dogrulamasi
				printf("Kimlik dogrulama basarili...");
				getch();
				system("CLS");
				temp=i;
				printf("\nHosgeldiniz, %s\n\n",ogrUye[i].kullaniciadi);
				printf("Staj  basari durumu girisi yapilacaktir.\n");
				do{
				printf("Ogrenci numarasi giriniz:");
				gets(no);
				for(i=0;i<100;i++){
					if(strcmp(no,ogr[i].no)==0){//numarasi girilen ogrencinin bilgilerine erismek icin 
						temp=i;
					}
				}
				printf("Staj basarili ise 1 basarisiz ise 0 giriniz.\n");
				scanf("%d",&ogr[temp].staj); // ogrencinin staj bilgisi kaydediliyor
				fflush(stdin);
				puts("Yeni bir kayit icin bir tusa, cikmak icin ESC tusuna basiniz.");
				}while(getch()!=27);
			}
			
		}
	}
}

void OgrenciPaneli(){
	int i,temp,choice;
	FILE *fPtr_notlar=fopen("notlar.txt","r");
	char ogrencino[5],sifre[4],ad[20],ders[50];
	float vize,final,ort;
	fflush(stdin);
	printf("Ogrenci Paneline Hosgeldiniz...\n");
	printf("Ogrenci numaranizi giriniz:\n");
	gets(ogrencino);
	fflush(stdin);
	printf("Sifre:\n");
	gets(sifre);
	fflush(stdin);
	
	for(i=0;i<100;i++){
		if(strcmp(ogrencino,ogr[i].no)==0){//numarasi girilen ogrencinin bilgilerine erismek icin 
			temp=i;
		}
	}
	
	if(strcmp(ogrencino,ogr[temp].no)==0 && strcmp(sifre,ogr[temp].sifre)==0){ //ogrencinin kimlik dogrulamasi
		printf("Kimlik dogrulama basarili...");
		getch();
		system("CLS");
		while(!feof(fPtr_notlar)){ 
			fflush(stdout);
			fscanf(fPtr_notlar,"%s %s %f %f %f\n",ad,ders,&vize,&final,&ort);//not bilgileri dosyadan okunuyor
			if(strcmp(ogr[temp].ad,ad)==0){ //dosyadan okunan ogrenci ile girilen ogrenci ayný mý kontrol ediliyor
				printf("%s %f %f %f\n",ders,vize,final,ort); //ogrencinin dosyadan okunan not bilgileri gösteriliyor
				if(ort>50){
					printf("Basarili\n");
					ogr[temp].topakts=+5; //basarili olunan ders sayisi kadar akts arttýrýlýyor (1 Ders= 5 AKTS)
				}
				else{
					printf("Basarisiz\n");
				}
			}
		}
		if(ogr[temp].staj==1){ 
			printf("Staj Basarili\n");
		}
		else{
			printf("Staj Basarisiz\n");
		}
		
	}
	
	else{
		printf("Kimlik dogrulama yanlis.");
	}
	printf("\nOgrenci Belgesi Ýstiyor musunuz?(1->EVET / 2->HAYIR)");
	scanf("%d",&choice);
	if(choice==1){
		ogrencibelgesi(ogr[temp]);
    }
	fclose(fPtr_notlar);
}

void ogrencibelgesi(struct ogrenci s){
	system("CLS");
	printf("---------------OGRENCI BELGESI------------------\n");
	printf("**************************************************\n");
	printf("Ad                 :%s\n",s.ad);
	printf("Soyad              :%s\n",s.soyad);
	printf("Bolum              :%d\n",s.bolumkod);
	printf("Numara             :%s\n",s.no);
	printf("Dogum Yeri         :%s\n",s.dogumyeri);
	printf("Cinsiyet           :%s\n",s.cinsiyet);
	if(s.mezun==1){
		printf("Ogrencilik Durumu      :Mezun\n");
	}
	else{
		printf("Ogrencilik Durumu      :Aktif Ogrenci\n");		
	}

}

void OgrenciMezunMu(struct ogrenci s){

	if(s.altDersSayisi!=0){	//Ogrenci mezun olamaz!Alttan derslerini 5. ve 6. yariyilda tamamlamasi gerekir.
		s.mezun=2;
		if(s.altDersSayisi2!=0){ //	Ogrenci alttan derslerini tamamlayamadigi icin mezun olamaz. Ogrenciligine son verilmistir.
			s.mezun=0;
		}
		if(s.altDersSayisi2=0){	//	Ogrenci alttan derslerini tamamladigi icin mezun olmustur
			s.mezun=1;
		}
	}
	else{
		if(s.topakts>=40){
			if(s.staj==1){ //	Ogrenci mezun olmustur
				s.mezun=1;
			}
		}
	}
}

void ogrSil(struct ogrenci s){
	char num[5],ad[20],soyad[20],no[5],sifre[5],yer[20],cins[6];
	int bkod,durum=0;// durum 1 olduðunda kayit silinir 

	FILE *fPtr_ogr=fopen("ogrenci.txt","r");
	FILE *fPtr_yedek=fopen("yedek.txt","a");//gecici olarak ogrenci dosyasý gorevi gorecek
	if( fPtr_ogr == NULL){
		puts("Dosya acilamadi");
	}
 	if( fPtr_yedek == NULL){
 		puts("Dosya acilamadi");
	}
	while(!feof(fPtr_ogr)){
		fflush(stdout);
		fscanf(fPtr_ogr,"%s %s %s %s %s %s %d\n",ad,soyad,no,sifre,yer,cins,bkod); // ogrenci dosyasý okunur
    	if(s.no != no){ // Eðer ogrenci numarasi dosyada okunan numaraya eþit deðilse if döngüsüne girer
   			fprintf(fPtr_yedek,"%s %s %s %s %s %s %d\n",ad,soyad,no,sifre,yer,cins,bkod); //bilgiler yedek dosyasýna yazilir ve girilen ogrenci silinmis olur
    	}
    else durum=1; 
	}
	
	fclose(fPtr_ogr);
	fclose(fPtr_yedek);
	
	if(durum == 1){
		remove("ogrenci.txt"); //silinmesi icin girilen ogrenci bu dosyada kaldigi icin silinir
		rename("yedek.txt","ogrenci.txt"); //yedek dosya ogrenci dosyasi olarak degistirilir ve istenilen ogrenci silinmis olur
		puts("Silme islemi tamamlandi devam etmek icin bir tusa basin");
	} 
	
	else{ // girilen ogrenci dosyada yoksa
		remove("yedek.txt"); // yedek dosyasý kullanýlmadýgý ýcýn silinmis
	}
	
	fflush(stdin);
	getch();
}

void ogrMezuniyet(){
	char ad[20],soyad[20],no[5],sifre[5],yer[20],cins[6];
	int bkod;
	FILE *fPtr_mezun=fopen("mezunlar.txt","a");
	FILE *fPtr_ogr=fopen("ogrenci.txt","r");
	
	int i;
	
	for(i=0;i<100;i++){
		OgrenciMezunMu(ogr[i]); //kaydedilen ogrencilerin mezunluk durumuna bakilir.
		if(ogr[i].mezun==0){
			printf("Ogrenci alttan derslerini tamamlayamadigi icin mezun olamaz.\nOgrenciligine son verilmistir.\n");
			ogrSil(ogr[i]); //ogrenciligi bittigi icin ogrenci dosyasindan silinir
		}
		if(ogr[i].mezun==1){
			printf("Ogrenci mezun olmustur.");
			 while(!feof(fPtr_ogr)){
			 	fflush(stdout);
 				 fscanf(fPtr_ogr,"%s %s %s %s %s %s %d\n",ad,soyad,no,sifre,yer,cins,bkod);  //ogrenci dosyasindan bilgiler okunur
   				 if(ogr[i].no == no){ //numarasi esit olan ogrenci bulunur
     			 fprintf(fPtr_mezun,"%s %s %s %s %s %s %d\n",ad,soyad,no,sifre,yer,cins,bkod); //mezun dosyasina ogrencinin bilgileri yazilir.
				}
			}
		}
	}
	fclose(fPtr_ogr);
 	fclose(fPtr_mezun);
}
