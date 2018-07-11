#include "stdafx.h"
#include "Ogrenci.h"
/*------------Kay�t Mod�l�--------------*/
void ogrenciKayit()
{	
	fstream ogrYaz ("Ogrenci.txt",ios::app);//.txt dosyam�z� a��yoruz
	Ogrenci ogr1;//Nesne olu�turuyoruz
	/*Kullan�c�dan verileri al�yoruz*/
	cout << "\n\t\t\t**��RENC� KAYIT**\n\n";
	cout << "��renci Numaras�:";
	cin >> ogr1.ogrNo;
	cout << "Ad�:";
	cin >> ogr1.ogrAdi;
	cout << "Soyad�:";
	cin >> ogr1.ogrSoyadi;
	cout << "S�n�f�:";
	cin >> ogr1.ogrSinif;
	cout << "B�l�m�:";
	cin >> ogr1.ogrBolum;
	/*numaray� kontrol i�in fonksiyona yolluyoruz*/
	if (kayitKontrol(ogr1.ogrNo))
	{
		/*dosyaya yaz�yoruz*/
		ogrYaz << ogr1.ogrNo << " " << ogr1.ogrAdi << " " << ogr1.ogrSoyadi << " " << ogr1.ogrSinif << " " << ogr1.ogrBolum << endl;
		cout << "\n\t\t\tEKLEME BA�ARILI ! " << endl;
		return;
	}
	else
	{
		cout<< "\n\t\t\tBA�ARISIZ!!, EKLEMEK �STED���N�Z ��RENC� ZATEN KAYITLI! " << endl;
		return;
	}
	ogrYaz.close();//.txt dosyas�n� kapat�yoruz
	
}
/*ayn� ��renci numaras� girildi�inde kay�t olamas�n diye kontrol fonksiyonuyla kontrol ediyoruz*/
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


/*----------Arama Mod�l�-------------*/
void ogrenciArama() 
{
	int aramaS;
	do
	{
		/*Arama Men�s�*/
		cout << "\n\t\t\t**��RENC� ARAMA**\n\n";
		cout << "1.��renci Numaras�na G�re" << endl;
		cout << "2.��renci Ad�na G�re" << endl;
		cout << "3.<==Bir �nceki Men�ye D�n" << endl;
		cin >> aramaS;
		if (aramaS == 3) 
		{ 
			system("cls");
			return;
		}
		/*Numaraya g�re arama*/
		if (aramaS == 1)
		{
			int kntrl = 0;
			string ogrNo;
			Ogrenci Ogr1;
			cout << "��renci Numaras�n� girin : ";			
			cin >> ogrNo;
			ifstream dosya("Ogrenci.txt");
			while (!dosya.eof())
			{
				dosya >> Ogr1.ogrNo >> Ogr1.ogrAdi >> Ogr1.ogrSoyadi >> Ogr1.ogrSinif >> Ogr1.ogrBolum;
				if (ogrNo==Ogr1.ogrNo)
				{
					cout << "\t\t\t\t******ARADI�INIZ ��RENC�********" << endl;
					cout << "\t"<< setw(15) << "Numara" << setw(15)<< "Ad�" << setw(15)<< "Soyad�"<< setw(15) << "S�n�f" << setw(15)<< "B�l�m" << endl;
					cout << "\t\t" <<"----------------------------------------------------------------"<< endl;
					cout <<"\t"<< setw(15) << Ogr1.ogrNo <<setw(15)<< Ogr1.ogrAdi << setw(15) << Ogr1.ogrSoyadi << setw(15) << Ogr1.ogrSinif << setw(15) << Ogr1.ogrBolum << endl;
					kntrl++;
					Ogr1.ogrNo = "NULL";

				}				
			}						
			if (kntrl == 0)
			{
				cout << "\n\t\t\t**Arad���n�z ��renci Bulunamad�**" << endl; 
			}
				dosya.close();								
			return;
		}
		/*isme g�re arama*/
		else if (aramaS == 2)
		{
			cout << "�sim girin: " << endl;
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
					cout << "\t\t\t\t******ARADI�INIZ ��RENC�********" << endl;
					cout << "\t" << setw(15) << "Numara" << setw(15) << "Ad�" << setw(15) << "Soyad�" << setw(15) << "S�n�f" << setw(15) << "B�l�m" << endl;
					cout << "\t\t" << "----------------------------------------------------------------" << endl;
					cout << "\t" << setw(15) << Ogr1.ogrNo << setw(15) << Ogr1.ogrAdi << setw(15) << Ogr1.ogrSoyadi << setw(15) << Ogr1.ogrSinif << setw(15) << Ogr1.ogrBolum << endl;
					kntrl++;
					Ogr1.ogrAdi = "NULL";
				}				
			}
			if (kntrl == 0)
			{
				cout << "\n\t\t\t**Arad���n�z ��renci Bulunamad�**" << endl;
			}
			dosya.close();
			return;
		}
		else
		{
			system("cls");
			cout << "***Hatal� giri� yapt�n�z, Yeniden Deneyin !***" << endl;
		}
	} while (aramaS!=1||aramaS!=2);//Hatal� giri� yap�nca arama men�s� tekrar y�klensin
}

/*----------Listeleme Mod�l�----------*/
void ogrenciListeleme() 
{
	
	int listelemeS;
	do
	{
		/*listeleme men�s�*/
		ifstream dosya("Ogrenci.txt");
		Ogrenci Ogr1;	
		cout << "\n\t\t\t**��RENC� L�STELEME**\n\n";
		cout << "1 - B�l�me G�re Listele" << endl;
		cout << "2 - S�n�fa G�re Listele" << endl;
		cout << "3.<==Bir �nceki Men�ye D�n" << endl;

		cin >> listelemeS;
		if (listelemeS == 3)
		{
			system("cls");
			return;
		}

		/*B�l�me g�re Listeleme*/
		if (listelemeS == 1) 
		{
			string bolum;
			int kontrol = 0;
			cout << "Listelemek �stedi�iniz B�l�m� Girin:" << endl;
			cin >> bolum;
			cout << "\t" << setw(15) << "Numara" << setw(15) << "Ad�" << setw(15) << "Soyad�" << setw(15) << "S�n�f" << setw(15) << "B�l�m" << endl;
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
				cout << "\n\t\t\t**Arad���n�z B�l�mde ��renci Bulunamad�**" << endl;
			}
			dosya.close();
			return;
		}
		/*S�n�fa g�re listeleme*/
		else if (listelemeS == 2)
		{
			string sinif;
			int kontrol = 0;
			cout << "Listelemek �stedi�iniz S�n�f� Girin:" << endl;
			cin >> sinif;
			cout << "\t" << setw(15) << "Numara" << setw(15) << "Ad�" << setw(15) << "Soyad�" << setw(15) << "S�n�f" << setw(15) << "B�l�m" << endl;
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
				cout << "\n\t\t\t**Arad���n�z S�n�fta ��renci Bulunamad�**" << endl;
			}
			dosya.close();
			return;
		}
		else
		{
			system("cls");
			cout << "***Hatal� giri� yapt�n�z, Yeniden Deneyin !***" << endl;
		}
	} while (listelemeS != 1 || listelemeS != 2);//Hatal� giri� yap�nca listeleme men�s� tekrar y�klensin
		
}
void ogrenciDuzenle() 
{
	int duzenlemeS;
	do
	{
		
		cout << "1.��renci Sil" << endl;
		cout << "2.��rencinin Bilgilerini D�zenle" << endl;
		cout << "3.<==Bir �nceki Men�ye D�n" << endl;
		cin >> duzenlemeS;
		if (duzenlemeS == 3)
		{
			system("cls");
			return;
		}

		/*��renci Sil*/
		else if (duzenlemeS == 1)
		{
			string silOgr;
			int kontrol = 0;
			cout << "Silmek �stedi�iniz ��rencinin Numaras�n� Girin:" << endl;
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
				cout << "\n\t\t\t**Silmek �stedi�iniz ��renci Ba�ar�yla Silinmi�tir!**" << endl;
			}
			else
			{
				system("cls");
				cout << "\n\t\t\t**Silmek �stedi�iniz ��renci Kay�tl� De�ildir!**" << endl;
			}
			dosya.close();
			return;
		}
		else if (duzenlemeS==2)
		{
		
			fstream ogrYaz("Ogrenci.txt");//.txt dosyam�z� a��yoruz
			Ogrenci ogr1;//Nesne olu�turuyoruz
			Ogrenci ogr2;
						 /*Kullan�c�dan verileri al�yoruz*/
			cout << "\n\t\t\t**��RENC� KAYIT**\n\n";
			cout << "D�zenlemek �stedi�iniz ��renci Numaras�:";
			cin >> ogr2.ogrNo;
			cout << "Ad�:";
			cin >> ogr2.ogrAdi;
			cout << "Soyad�:";
			cin >> ogr2.ogrSoyadi;
			cout << "S�n�f�:";
			cin >> ogr2.ogrSinif;
			cout << "B�l�m�:";
			cin >> ogr2.ogrBolum;
			
			
			while (!ogrYaz.eof())
			{
				ogrYaz >> ogr1.ogrNo;
				if (ogr2.ogrNo == ogr1.ogrNo)
				{
					ogrYaz << ogr2.ogrNo << " " << ogr2.ogrAdi << " " << ogr2.ogrSoyadi << " " << ogr2.ogrSinif << " " << ogr2.ogrBolum << endl;
					cout << "Ba�ar�l�" << endl;
				}
				
			}
			ogrYaz.close();
			
		}
	} while (duzenlemeS!=1||duzenlemeS!=2);
	

	
}