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
/*Ogrenci class'ýmýzý yaratýyoruz*/
class Ogrenci
{
public:
	//Öðrenci verilerini tutacak deðiþkenlerimiz
	string ogrNo;
	string ogrAdi;
	string ogrSoyadi;
	string ogrSinif;
	string ogrBolum;
	//string ogrDersler[];


};
//Ýþlemlerimizi yapacak fonksiyonlarýn ana gövdeleri
void ogrenciKayit();
bool kayitKontrol(string OgrNo);
void ogrenciArama();
void ogrenciListeleme();
void ogrenciDuzenle();

