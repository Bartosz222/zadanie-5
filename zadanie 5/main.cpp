#include <iostream>
#include <fstream>
using namespace std;
class pliki{
	public:
		pliki();
		~pliki();
		ifstream wejscie;
		ifstream wejscie2;
		ofstream wyjscie;
};
class film:public pliki{
	public:
		string tytul,rezyser;
		string rok;
		void wczytaj1();
		
};
class filmDokumentalny: public film{
	public:
		string opis_wydarzenia;
		using film::wczytaj1;
		void wczytaj();
		void zapisz();
	
};
void filmDokumentalny::wczytaj(){
	while(!wejscie2.eof()){
		wejscie2>>opis_wydarzenia;
		
	}

}
void film::wczytaj1(){
	while(!wejscie.eof()){
		wejscie>>tytul;
		wejscie>>rezyser;
		wejscie>>rok;
	}

}
void filmDokumentalny::zapisz(){
	wyjscie<<"{\"tytul\":\""+tytul+"\",\"rezyser\":\""+rezyser+"\",\"rok\":\""+ rok +"\",\"opis\":\""+opis_wydarzenia+"\"},"<<endl;
}
pliki::pliki(){
	wejscie.open("wejscie.txt");
	wejscie2.open("wejscie2.txt");
	wyjscie.open("wyjscie.txt");
	wyjscie<<"["<<endl;
}
pliki::~pliki(){
	wyjscie<<"]";
	wejscie.close();
	wejscie2.close();
	wyjscie.close();
}
int main() {
	filmDokumentalny f1;
	f1.wczytaj1();
	f1.wczytaj();
	f1.zapisz();
	return 0;
}
