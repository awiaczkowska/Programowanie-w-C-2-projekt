#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student
{
private:
	string nazwisko, imie, identyfikator;

public:
	Student();
	friend ostream &operator<<(ostream &wyjscie, const Student &student);
	void zapisz(string _nazwisko, string _imie, string _identyfikator);
	string wypisz_nazwisko()const;
	string wypisz_imie()const;
	string wypisz_identyfikator()const;
	void edytuj_imie(string _imie);
	void edytuj_nazwisko(string _nazwisko);
	void edytuj_identyfikator(string _identyfikator);
	Student *nastepny;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Wyklad
{
private:
	string tytul, identyfikator;
	int ECTS;

public:
    friend ostream &operator<<(ostream &wyjscie, const Wyklad& wyk) ;
	void zapisz(string _tytul, int _ECTS, string _identyfikator);
	string wypisz_tytul() const;
	string wypisz_tytul_podloga() const;
	string wypisz_identyfikator() const;
	int wypisz_ECTS() const;
	Wyklad *nastepny;
	void wypisz();
	void edytuj_tytul(string _tytul);
	void edytuj_ECTS(int ECTS);
	void edytuj_identyfikator(string _identyfikator);


};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Zapis
{
private:
	string identyfikator_student, identyfikator_wyklad;

public:
    friend ostream &operator<<(ostream &wyjscie, const Zapis &zap);
	void zapisz(string _id_stud, string _id_wyk);
	//Student wypisz_student();
	Wyklad wypisz_wyklad();
	string wypisz_student_id()const;
	string wypisz_wyklad_id()const;
	void edytuj_student_id(string _stud);
	void edytuj_wyklad_id(string _wyk);
	Zapis *nastepny;
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Lista_studentow
{
private:
	Student *poczatek, *koniec;
	int liczba;
public:
	Lista_studentow();
	~ Lista_studentow();
	//void dodaj_studenta(string _nazwisko, string _imie, string _identyfikator);
	void dodaj_studenta(string,string, string);
	void wypisz_liste();
	//void znajdz_o_nazwisku(string _nazwisko);
	void wypisz_o_nazwisku(string _nazwisko);
	void wypisz_o_imieniu(string _imie);
    void wypisz_o_id(string _id);
	bool czy_istnieje_id(string _identyfikator);
	bool czy_istnieje_nazw(string _nazwisko);
	bool czy_istnieje_imie(string _identyfikator);
	Student* znajdz_po_identyfikatorze(string _identyfikator);
	void usun(string _identyfikator);
	void usun_wszystko();
    bool czy_pusta();
    void wypisz_z_tablicy(string *tab_id, int ile);
    string wypisz_imiemazwisko_po_id(string _identyfikator);
    void edytuj_imie(string _imie, string _identyfikator);
	void edytuj_nazwisko(string _nazwisko, string _identyfikator);
	void edytuj_identyfikator(string _identyfikator1, string _identyfikator2);
	string* niekompatybilne (string*tab_indeksow,int rozmiar, int &ile );
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Lista_wykladow
{
private:
	Wyklad *poczatek, *koniec;
	int liczba;
public:
	Lista_wykladow();
	~ Lista_wykladow();
	void dodaj_wyklad(string _tytul, int _ECTS, string _identyfikator);
	void wypisz_liste();
	void wypisz_o_tytule(string _tytul);
	void wypisz_o_ECTS(int _ECTS);
	void wypisz_o_id(string _id);
	//Wyklad *znajdz_po_identyfikatorze(string _identyfikator);
	void usun_wyklad(string _identyfikator);
	bool czy_istnieje_id(string _tytul);
	bool czy_istnieje_tytul(string _identyfikator);
	bool czy_istnieje_ECTS(int _ECTS);
	void usun_wszystko();
	bool czy_pusta();
	void wypisz_z_tablicy(string *tab_id, int ile);
	string wypisz_tytul_po_id(string _identyfikator);
	void edytuj_tytul(string _tytul, string _identyfikator);
	void edytuj_ECTS(int _ECTS, string _identyfikator);
    void edytuj_identyfikator(string _identyfikator1, string _identyfikator2);

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Lista_zapisow
{
private:
	Zapis *poczatek, *koniec;
	int liczba;
public:
	Lista_zapisow();
	~ Lista_zapisow();
	void dodaj(string _id_student, string _id_wyklad);
	void wypisz_liste();
	void znajdz_po_studencie_nazw(string _nazwisko);
	void znajdz_po_studencie_id(string _identyfikator);
	void znajdz_po_wykladzie(string _tytul);
	void usun(string _student, string _wyklad);
	void usun_wszystkie_stud(string _student);
	void usun_wszystkie_wyk(string _wyklad);
	bool czy_student(string stud_id);
    bool czy_wyklad(string wyk_id);
    bool czy_zapis(string stud_id,string wyk_id);
    void usun_wszystko();
    bool czy_pusta();
    string* studenci_z_wykladu(string id_wyk, int &ile);
    string* wyklady_studenta(string id_stud, int &ile );
    //void wypisz_z_tablicy(string *tab_id);
    void edytuj_student_id(string stud_id1,string stud_id2 );
	void edytuj_wyklad_id( string wyk_id1,string wyk_id2);
	string* zapisani_stud(int &ile);
	string* wyk_z_zapisami( int &ile);
};



