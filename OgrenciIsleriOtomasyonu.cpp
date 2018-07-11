#include"stdafx.h"
#include "Ogrenci.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); // T�rk�e karakter sorunu ya�amamak i�in kullan���m�z fonksiyon
	int secim;
	bool ogr_dongu_cikis = true;
	bool ogrtm_dongu_cikis = true;
	while (true) //Otomasyonun devaml� �al��mas� i�in d�ng� i�ine al�yoruz
	{
		/*---Ana Men�----*/
		system("cls");//ekran� temizleme fonksiyonu
		cout << endl;		
		cout << "1 - ��renci Mod�l� " << endl;
		cout << "2 - ��retim Eleman� Mod�l�" << endl;
		cout << "3 - Ders Mod�l�" << endl;
		cout << "4 - Not Giri� Mod�l�" << endl;
		cout << "5 - Otomasyondan �IKI�" << endl;
		cin >> secim ;

		/*---Se�im Ve Alt Men�ler---*/
		switch (secim)
		{
		case 1 :
			/*---��renci Mod�l�---*/
			ogr_dongu_cikis = true;
			while (ogr_dongu_cikis)//buradaki while dongusunun amac� kullan�c� y� s�rekli ��renci mod�l men�s�nde tutmak ve kendi istedi�i zaman ana men�ye d�nmesini sa�lamakt�r.
			{
				int OgrenciS;
				cout << endl;
				cout << "1 - ��renci Kay�t " << endl;
				cout << "2 - ��renci Arama" << endl;
				cout << "3 - ��renci Listeleme" << endl;
				cout << "4 - ��renci Bilgileri D�zeltme" << endl;
				cout << "5 - <==Bir �nceki Men�ye D�n" << endl;
				cin >> OgrenciS;
				switch (OgrenciS)
				{
				case 1 :
					/*---��renci Kay�t---*/
					system("cls");
					ogrenciKayit();//��renci kaydetmek i�in fonksiyonu �a��r�yoruz
					break;
				case 2 :
					/*---��renci arama---*/
					system("cls");
					ogrenciArama();
					break;
				case 3 :
					/*---��renci Listeme---*/
					system("cls");
					ogrenciListeleme();
					break;
				case 4 :
					/*---��renci D�zenleme---*/
					system("cls");
					ogrenciDuzenle();
					break;
				case 5 :
					/*---Ana Men�ye d�n��---*/
					ogr_dongu_cikis = false;
					break;
				default:
					cout << "***Hatal� giri� yapt�n�z, Yeniden Deneyin !***" << endl;
					break;
				}

			}

			break;
		case 2 :
			/*---��retim Eleman� Mod�l�---*/
			ogrtm_dongu_cikis = true;
			while (ogrtm_dongu_cikis)
			{
				int OgretimS;
				cout << endl;
				cout << "1 - ��retim Eleman� Kay�t " << endl;
				cout << "2 - ��retim Eleman� Arama" << endl;
				cout << "3 - ��retim Eleman� Bilgileri D�zeltme" << endl;
				cout << "4 - ��retim Eleman� Listeleme " << endl;
				cout << "5 - <==Bir �nceki Men�ye D�n" << endl;
				cin >> OgretimS;
				switch (OgretimS)
				{
				case 1:
					/*---��retim Eleman� Kay�t---*/
					system("cls");
					break;
				case 2:
					/*---��retim Eleman� Arama---*/
					system("cls");
					break;
				case 3:
					/*---��retim Eleman� D�zenleme---*/
					system("cls");
					break;
				case 4:
					/*---��retim Eleman� Listeme---*/
					system("cls");
					break;
				case 5:
					/*---Ana Men�ye d�n��---*/
					ogrtm_dongu_cikis = false;
					break;
				default:
					cout << "***Hatal� giri� yapt�n�z, Yeniden Deneyin !***" << endl;
					break;
				}

			}
			break;
		case 3 :
			/*---Ders Mod�l�---*/
			ogrtm_dongu_cikis = true;
			while (ogrtm_dongu_cikis)
			{
				int OgretimS;
				cout << endl;
				cout << "1 - Ders Ekleme " << endl;
				cout << "2 - Ders G�ncelleme" << endl;
				cout << "3 - Ders Listeleme" << endl;
				cout << "4 - Ders Arama " << endl;
				cout << "5 - <==Bir �nceki Men�ye D�n" << endl;
				cin >> OgretimS;
				switch (OgretimS)
				{
				case 1:
					/*---Ders Ekleme---*/
					system("cls");
					break;
				case 2:
					/*---Ders G�ncelleme---*/
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
					/*---Ana Men�ye d�n��---*/
					ogrtm_dongu_cikis = false;
					break;
				default:
					cout << "***Hatal� giri� yapt�n�z, Yeniden Deneyin !***" << endl;
					break;
				}

			}
			break;
		case 4 :
			/*---Not Giri� Mod�l�---*/
			break;
		case 5 :
			/*��k�� se�imi*/
			exit(0);
			break;
			
		default:
			/*Hatal� Giri�*/
			cout << "***Hatal� giri� yapt�n�z, Yeniden Deneyin !***" << endl;
			break;
		}
		
	}

	system("Pause");
    return 0;
}
