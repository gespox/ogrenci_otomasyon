#pragma once
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <locale.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
/*Ogrenci class'�m�z� yarat�yoruz*/
class Ogrenci
{
public:
	//��renci verilerini tutacak de�i�kenlerimiz
	string ogrNo;
	string ogrAdi;
	string ogrSoyadi;
	string ogrSinif;
	string ogrBolum;
	//string ogrDersler[];


};
//��lemlerimizi yapacak fonksiyonlar�n ana g�vdeleri
void ogrenciKayit();
bool kayitKontrol(string OgrNo);
void ogrenciArama();
void ogrenciListeleme();
void ogrenciDuzenle();

