#include "stdafx.h"
#include "Ogrenci.h"
/*------------Kayýt Modülü--------------*/
void ogrenciKayit()
{	
	fstream ogrYaz ("Ogrenci.txt",ios::app);//.txt dosyamýzý açýyoruz
	Ogrenci ogr1;//Nesne oluþturuyoruz
	/*Kullanýcýdan verileri alýyoruz*/
	cout << "\n\t\t\t**ÖÐRENCÝ KAYIT**\n\n";
	cout << "Öðrenci Numarasý:";
	cin >> ogr1.ogrNo;
	cout << "Adý:";
	cin >> ogr1.ogrAdi;
	cout << "Soyadý:";
	cin >> ogr1.ogrSoyadi;
	cout << "Sýnýfý:";
	cin >> ogr1.ogrSinif;
	cout << "Bölümü:";
	cin >> ogr1.ogrBolum;
	/*numarayý kontrol için fonksiyona yolluyoruz*/
	if (kayitKontrol(ogr1.ogrNo))
	{
		/*dosyaya yazýyoruz*/
		ogrYaz << ogr1.ogrNo << " " << ogr1.ogrAdi << " " << ogr1.ogrSoyadi << " " << ogr1.ogrSinif << " " << ogr1.ogrBolum << endl;
		cout << "\n\t\t\tEKLEME BAÞARILI ! " << endl;
		return;
	}
	else
	{
		cout<< "\n\t\t\tBAÞARISIZ!!, EKLEMEK ÝSTEDÝÐÝNÝZ ÖÐRENCÝ ZATEN KAYITLI! " << endl;
		return;
	}
	ogrYaz.close();//.txt dosyasýný kapatýyoruz
	
}
/*ayný öðrenci numarasý girildiðinde kayýt olamasýn diye kontrol fonksiyonuyla kontrol ediyoruz*/
bool kayitKontrol(string OgrNo)
{
	ifstream dosya("Ogrenci.txt");
	Ogrenci Ogr1;
	int kontrol = 0;
	while (!dosya.eof())
	{
		dosya >> Ogr1.ogrNo >> Ogr1.ogrAdi >> Ogr1.ogrSoyadi >> Ogr1.ogrSinif >> Ogr1.ogrBolum;
		if (OgrNo == Ogr1.ogrNo) 
		{
			kontrol++;
			return false;			
		}
	}
	if (kontrol==0)
	{
		return true;
	}
	dosya.close();
}


/*----------Arama Modülü-------------*/
void ogrenciArama() 
{
	int aramaS;
	do
	{
		/*Arama Menüsü*/
		cout << "\n\t\t\t**ÖÐRENCÝ ARAMA**\n\n";
		cout << "1.Öðrenci Numarasýna Göre" << endl;
		cout << "2.Öðrenci Adýna Göre" << endl;
		cout << "3.<==Bir Önceki Menüye Dön" << endl;
		cin >> aramaS;
		if (aramaS == 3) 
		{ 
			system("cls");
			return;
		}
		/*Numaraya göre arama*/
		if (aramaS == 1)
		{
			int kntrl = 0;
			string ogrNo;
			Ogrenci Ogr1;
			cout << "Öðrenci Numarasýný girin : ";			
			cin >> ogrNo;
			ifstream dosya("Ogrenci.txt");
			while (!dosya.eof())
			{
				dosya >> Ogr1.ogrNo >> Ogr1.ogrAdi >> Ogr1.ogrSoyadi >> Ogr1.ogrSinif >> Ogr1.ogrBolum;
				if (ogrNo==Ogr1.ogrNo)
				{
					cout << "\t\t\t\t******ARADIÐINIZ ÖÐRENCÝ********" << endl;
					cout << "\t"<< setw(15) << "Numara" << setw(15)<< "Adý" << setw(15)<< "Soyadý"<< setw(15) << "Sýnýf" << setw(15)<< "Bölüm" << endl;
					cout << "\t\t" <<"----------------------------------------------------------------"<< endl;
					cout <<"\t"<< setw(15) << Ogr1.ogrNo <<setw(15)<< Ogr1.ogrAdi << setw(15) << Ogr1.ogrSoyadi << setw(15) << Ogr1.ogrSinif << setw(15) << Ogr1.ogrBolum << endl;
					kntrl++;
					Ogr1.ogrNo = "NULL";

				}				
			}						
			if (kntrl == 0)
			{
				cout << "\n\t\t\t**Aradýðýnýz Öðrenci Bulunamadý**" << endl; 
			}
				dosya.close();								
			return;
		}
		/*isme göre arama*/
		else if (aramaS == 2)
		{
			cout << "Ýsim girin: " << endl;
			string ogrIsim;
			cin >> ogrIsim;			
			int kntrl = 0;
			string ogrNo;
			Ogrenci Ogr1;
			ifstream dosya("Ogrenci.txt");
			while (!dosya.eof())
			{
				dosya >> Ogr1.ogrNo >> Ogr1.ogrAdi >> Ogr1.ogrSoyadi >> Ogr1.ogrSinif >> Ogr1.ogrBolum;
				if (ogrIsim == Ogr1.ogrAdi)
				{
					cout << "\t\t\t\t******ARADIÐINIZ ÖÐRENCÝ********" << endl;
					cout << "\t" << setw(15) << "Numara" << setw(15) << "Adý" << setw(15) << "Soyadý" << setw(15) << "Sýnýf" << setw(15) << "Bölüm" << endl;
					cout << "\t\t" << "----------------------------------------------------------------" << endl;
					cout << "\t" << setw(15) << Ogr1.ogrNo << setw(15) << Ogr1.ogrAdi << setw(15) << Ogr1.ogrSoyadi << setw(15) << Ogr1.ogrSinif << setw(15) << Ogr1.ogrBolum << endl;
					kntrl++;
					Ogr1.ogrAdi = "NULL";
				}				
			}
			if (kntrl == 0)
			{
				cout << "\n\t\t\t**Aradýðýnýz Öðrenci Bulunamadý**" << endl;
			}
			dosya.close();
			return;
		}
		else
		{
			system("cls");
			cout << "***Hatalý giriþ yaptýnýz, Yeniden Deneyin !***" << endl;
		}
	} while (aramaS!=1||aramaS!=2);//Hatalý giriþ yapýnca arama menüsü tekrar yüklensin
}

/*----------Listeleme Modülü----------*/
void ogrenciListeleme() 
{
	
	int listelemeS;
	do
	{
		/*listeleme menüsü*/
		ifstream dosya("Ogrenci.txt");
		Ogrenci Ogr1;	
		cout << "\n\t\t\t**ÖÐRENCÝ LÝSTELEME**\n\n";
		cout << "1 - Bölüme Göre Listele" << endl;
		cout << "2 - Sýnýfa Göre Listele" << endl;
		cout << "3.<==Bir Önceki Menüye Dön" << endl;

		cin >> listelemeS;
		if (listelemeS == 3)
		{
			system("cls");
			return;
		}

		/*Bölüme göre Listeleme*/
		if (listelemeS == 1) 
		{
			string bolum;
			int kontrol = 0;
			cout << "Listelemek Ýstediðiniz Bölümü Girin:" << endl;
			cin >> bolum;
			cout << "\t" << setw(15) << "Numara" << setw(15) << "Adý" << setw(15) << "Soyadý" << setw(15) << "Sýnýf" << setw(15) << "Bölüm" << endl;
			cout << "\t\t" << "----------------------------------------------------------------" << endl;
			
			while (!dosya.eof())
			{
				
				dosya >> Ogr1.ogrNo >> Ogr1.ogrAdi >> Ogr1.ogrSoyadi >> Ogr1.ogrSinif >> Ogr1.ogrBolum;
				if (bolum == Ogr1.ogrBolum) 
				{
					cout << "\t" << setw(15) << Ogr1.ogrNo << setw(15) << Ogr1.ogrAdi << setw(15) << Ogr1.ogrSoyadi << setw(15) << Ogr1.ogrSinif << setw(15) << Ogr1.ogrBolum << endl;
					kontrol++;
				}
			}
			if (kontrol == 0)
			{
				system("cls");
				cout << "\n\t\t\t**Aradýðýnýz Bölümde Öðrenci Bulunamadý**" << endl;
			}
			dosya.close();
			return;
		}
		/*Sýnýfa göre listeleme*/
		else if (listelemeS == 2)
		{
			string sinif;
			int kontrol = 0;
			cout << "Listelemek Ýstediðiniz Sýnýfý Girin:" << endl;
			cin >> sinif;
			cout << "\t" << setw(15) << "Numara" << setw(15) << "Adý" << setw(15) << "Soyadý" << setw(15) << "Sýnýf" << setw(15) << "Bölüm" << endl;
			cout << "\t\t" << "----------------------------------------------------------------" << endl;
			while (!dosya.eof())
			{
				dosya >> Ogr1.ogrNo >> Ogr1.ogrAdi >> Ogr1.ogrSoyadi >> Ogr1.ogrSinif >> Ogr1.ogrBolum;
				if (sinif == Ogr1.ogrSinif)
				{
					cout << "\t" << setw(15) << Ogr1.ogrNo << setw(15) << Ogr1.ogrAdi << setw(15) << Ogr1.ogrSoyadi << setw(15) << Ogr1.ogrSinif << setw(15) << Ogr1.ogrBolum << endl;
					kontrol++;
				}
			}
			if (kontrol == 0)
			{
				system("cls");
				cout << "\n\t\t\t**Aradýðýnýz Sýnýfta Öðrenci Bulunamadý**" << endl;
			}
			dosya.close();
			return;
		}
		else
		{
			system("cls");
			cout << "***Hatalý giriþ yaptýnýz, Yeniden Deneyin !***" << endl;
		}
	} while (listelemeS != 1 || listelemeS != 2);//Hatalý giriþ yapýnca listeleme menüsü tekrar yüklensin
		
}
void ogrenciDuzenle() 
{
	int duzenlemeS;
	do
	{
		
		cout << "1.Öðrenci Sil" << endl;
		cout << "2.Öðrencinin Bilgilerini Düzenle" << endl;
		cout << "3.<==Bir Önceki Menüye Dön" << endl;
		cin >> duzenlemeS;
		if (duzenlemeS == 3)
		{
			system("cls");
			return;
		}

		/*Öðrenci Sil*/
		else if (duzenlemeS == 1)
		{
			string silOgr;
			int kontrol = 0;
			cout << "Silmek Ýstediðiniz Öðrencinin Numarasýný Girin:" << endl;
			cin >> silOgr;
			Ogrenci ogr1;
			ifstream dosya("Ogrenci.txt");
			fstream temp("temp.txt",ios::app);
			while (!dosya.eof())
			{
				dosya >> ogr1.ogrNo >> ogr1.ogrAdi >> ogr1.ogrSoyadi >> ogr1.ogrSinif >> ogr1.ogrBolum;
				if (silOgr== ogr1.ogrNo)
				{
					kontrol++;
					//temp << ogr1.ogrNo << " " << ogr1.ogrAdi << " " << ogr1.ogrSoyadi << " " << ogr1.ogrSinif << " " << ogr1.ogrBolum << endl;				
				}
				else
				{
					temp << ogr1.ogrNo << " " << ogr1.ogrAdi << " " << ogr1.ogrSoyadi << " " << ogr1.ogrSinif << " " << ogr1.ogrBolum << endl;
				}
			}
			temp.close();
			dosya.close();
			remove("Ogrenci.txt");
			rename("temp.txt", "Ogrenci.txt");
			if (kontrol ==1)
			{
				system("cls");
				cout << "\n\t\t\t**Silmek Ýstediðiniz Öðrenci Baþarýyla Silinmiþtir!**" << endl;
			}
			else
			{
				system("cls");
				cout << "\n\t\t\t**Silmek Ýstediðiniz Öðrenci Kayýtlý Deðildir!**" << endl;
			}
			dosya.close();
			return;
		}
		else if (duzenlemeS==2)
		{
		
			fstream ogrYaz("Ogrenci.txt");//.txt dosyamýzý açýyoruz
			Ogrenci ogr1;//Nesne oluþturuyoruz
			Ogrenci ogr2;
						 /*Kullanýcýdan verileri alýyoruz*/
			cout << "\n\t\t\t**ÖÐRENCÝ KAYIT**\n\n";
			cout << "Düzenlemek Ýstediðiniz Öðrenci Numarasý:";
			cin >> ogr2.ogrNo;
			cout << "Adý:";
			cin >> ogr2.ogrAdi;
			cout << "Soyadý:";
			cin >> ogr2.ogrSoyadi;
			cout << "Sýnýfý:";
			cin >> ogr2.ogrSinif;
			cout << "Bölümü:";
			cin >> ogr2.ogrBolum;
			
			
			while (!ogrYaz.eof())
			{
				ogrYaz >> ogr1.ogrNo;
				if (ogr2.ogrNo == ogr1.ogrNo)
				{
					ogrYaz << ogr2.ogrNo << " " << ogr2.ogrAdi << " " << ogr2.ogrSoyadi << " " << ogr2.ogrSinif << " " << ogr2.ogrBolum << endl;
					cout << "Baþarýlý" << endl;
				}
				
			}
			ogrYaz.close();
			
		}
	} while (duzenlemeS!=1||duzenlemeS!=2);
	

	
}