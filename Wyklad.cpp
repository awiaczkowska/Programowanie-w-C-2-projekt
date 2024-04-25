#include "klasy.h"
#ifndef klasy_h
#define klasy_h

string Wyklad::wypisz_tytul() const
{
    string Str=tytul;

    for (int i=0; i<int(Str.length() ); i++)
    {
        if (Str[i] =='_') Str[i]=' ';
    }
    return Str;
}

string Wyklad::wypisz_identyfikator() const
{
    return identyfikator;
}


string Wyklad::wypisz_tytul_podloga() const
{
    return tytul;
}
int Wyklad::wypisz_ECTS() const
{
    return ECTS;
}

void Wyklad::zapisz(string _tytul, int _ECTS, string _identyfikator)
{
    string Str=_tytul;

    for (int i=0; i<Str.length(); i++)
    {
        if (Str[i] ==' ') Str[i]='_';
    }
    tytul=Str;
    ECTS=_ECTS;
    identyfikator=_identyfikator;
}


ostream &operator<<(ostream &wyjscie, const Wyklad &wyk)
{
    wyjscie  << '\n' << "\tTytul: \t"<< wyk.wypisz_tytul()
             << '\n' << "\tECTS: \t" << wyk.wypisz_ECTS()
             << "\nIdentyfikator: \t" << wyk.wypisz_identyfikator()<< endl;
    return wyjscie;
}


void Wyklad::wypisz()
{
    cout  << '\n' << "\tTytul: \t"<< this-> wypisz_tytul()
          << '\n' << "\tECTS: \t" << this-> wypisz_ECTS()
          << "\nIdentyfikator: \t" <<this->  wypisz_identyfikator()<< endl;
}

void Wyklad::edytuj_tytul(string _tytul)
{
    string Str=_tytul;

    for (int i=0; i<int(Str.length() ); i++)
    {
        if (Str[i] ==' ') Str[i]='_';
    }
    tytul=Str;
}

void Wyklad::edytuj_ECTS(int _ECTS)
{
    ECTS=_ECTS;
}

void Wyklad::edytuj_identyfikator(string _identyfikator)
{
    identyfikator=_identyfikator;
}



#endif // klasy_h
