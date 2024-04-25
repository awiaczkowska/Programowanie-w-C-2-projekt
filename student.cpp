#ifndef klasy_h
#define klasy_h
#include "klasy.h"

Student::Student()
{
    nazwisko = "";
    imie = "";
    identyfikator = "";
}

string Student::wypisz_nazwisko()const
{
    return nazwisko;
}
string Student::wypisz_imie()const
{
    return imie;
}
string Student::wypisz_identyfikator()const
{
    return identyfikator;
}



void Student::zapisz(string _nazwisko, string _imie, string _identyfikator)
{
    nazwisko = _nazwisko;
    imie = _imie;
    identyfikator = _identyfikator;
}


ostream &operator<<(ostream &wyjscie, const Student &student)
{
    wyjscie << "Nazwisko: " << (student.wypisz_nazwisko() )
            << "\nImie: " << (student.wypisz_imie() )
            << "\nIndeks: " << (student.wypisz_identyfikator() )<<endl;

    return wyjscie;
}

void Student::edytuj_imie(string _imie)
{
    imie=_imie;
}
void Student::edytuj_nazwisko(string _nazwisko)
{
    nazwisko=_nazwisko;
}
void Student::edytuj_identyfikator(string _identyfikator)
{
    identyfikator=_identyfikator;
}

#endif // klasy_h
