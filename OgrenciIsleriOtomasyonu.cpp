#include"stdafx.h"
#include "Ogrenci.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); // Türkçe karakter sorunu yaþamamak için kullanýðýmýz fonksiyon
	int secim;
	bool ogr_dongu_cikis = true;
	bool ogrtm_dongu_cikis = true;
	while (true) //Otomasyonun devamlý çalýþmasý için döngü içine alýyoruz
	{
		/*---Ana Menü----*/
		system("cls");//ekraný temizleme fonksiyonu
		cout << endl;		
		cout << "1 - Öðrenci Modülü " << endl;
		cout << "2 - Öðretim Elemaný Modülü" << endl;
		cout << "3 - Ders Modülü" << endl;
		cout << "4 - Not Giriþ Modülü" << endl;
		cout << "5 - Otomasyondan ÇIKIÞ" << endl;
		cin >> secim ;

		/*---Seçim Ve Alt Menüler---*/
		switch (secim)
		{
		case 1 :
			/*---Öðrenci Modülü---*/
			ogr_dongu_cikis = true;
			while (ogr_dongu_cikis)//buradaki while dongusunun amacý kullanýcý yý sürekli öðrenci modül menüsünde tutmak ve kendi istediði zaman ana menüye dönmesini saðlamaktýr.
			{
				int OgrenciS;
				cout << endl;
				cout << "1 - Öðrenci Kayýt " << endl;
				cout << "2 - Öðrenci Arama" << endl;
				cout << "3 - Öðrenci Listeleme" << endl;
				cout << "4 - Öðrenci Bilgileri Düzeltme" << endl;
				cout << "5 - <==Bir Önceki Menüye Dön" << endl;
				cin >> OgrenciS;
				switch (OgrenciS)
				{
				case 1 :
					/*---Öðrenci Kayýt---*/
					system("cls");
					ogrenciKayit();//öðrenci kaydetmek için fonksiyonu çaðýrýyoruz
					break;
				case 2 :
					/*---Öðrenci arama---*/
					system("cls");
					ogrenciArama();
					break;
				case 3 :
					/*---Öðrenci Listeme---*/
					system("cls");
					ogrenciListeleme();
					break;
				case 4 :
					/*---Öðrenci Düzenleme---*/
					system("cls");
					ogrenciDuzenle();
					break;
				case 5 :
					/*---Ana Menüye dönüþ---*/
					ogr_dongu_cikis = false;
					break;
				default:
					cout << "***Hatalý giriþ yaptýnýz, Yeniden Deneyin !***" << endl;
					break;
				}

			}

			break;
		case 2 :
			/*---Öðretim Elemaný Modülü---*/
			ogrtm_dongu_cikis = true;
			while (ogrtm_dongu_cikis)
			{
				int OgretimS;
				cout << endl;
				cout << "1 - Öðretim Elemaný Kayýt " << endl;
				cout << "2 - Öðretim Elemaný Arama" << endl;
				cout << "3 - Öðretim Elemaný Bilgileri Düzeltme" << endl;
				cout << "4 - Öðretim Elemaný Listeleme " << endl;
				cout << "5 - <==Bir Önceki Menüye Dön" << endl;
				cin >> OgretimS;
				switch (OgretimS)
				{
				case 1:
					/*---Öðretim Elemaný Kayýt---*/
					system("cls");
					break;
				case 2:
					/*---Öðretim Elemaný Arama---*/
					system("cls");
					break;
				case 3:
					/*---Öðretim Elemaný Düzenleme---*/
					system("cls");
					break;
				case 4:
					/*---Öðretim Elemaný Listeme---*/
					system("cls");
					break;
				case 5:
					/*---Ana Menüye dönüþ---*/
					ogrtm_dongu_cikis = false;
					break;
				default:
					cout << "***Hatalý giriþ yaptýnýz, Yeniden Deneyin !***" << endl;
					break;
				}

			}
			break;
		case 3 :
			/*---Ders Modülü---*/
			ogrtm_dongu_cikis = true;
			while (ogrtm_dongu_cikis)
			{
				int OgretimS;
				cout << endl;
				cout << "1 - Ders Ekleme " << endl;
				cout << "2 - Ders Güncelleme" << endl;
				cout << "3 - Ders Listeleme" << endl;
				cout << "4 - Ders Arama " << endl;
				cout << "5 - <==Bir Önceki Menüye Dön" << endl;
				cin >> OgretimS;
				switch (OgretimS)
				{
				case 1:
					/*---Ders Ekleme---*/
					system("cls");
					break;
				case 2:
					/*---Ders Güncelleme---*/
					system("cls");
					break;
				case 3:
					/*---Ders Listeleme---*/
					system("cls");
					break;
				case 4:
					/*---Ders Arama---*/
					system("cls");
					break;
				case 5:
					/*---Ana Menüye dönüþ---*/
					ogrtm_dongu_cikis = false;
					break;
				default:
					cout << "***Hatalý giriþ yaptýnýz, Yeniden Deneyin !***" << endl;
					break;
				}

			}
			break;
		case 4 :
			/*---Not Giriþ Modülü---*/
			break;
		case 5 :
			/*Çýkýþ seçimi*/
			exit(0);
			break;
			
		default:
			/*Hatalý Giriþ*/
			cout << "***Hatalý giriþ yaptýnýz, Yeniden Deneyin !***" << endl;
			break;
		}
		
	}

	system("Pause");
    return 0;
}
