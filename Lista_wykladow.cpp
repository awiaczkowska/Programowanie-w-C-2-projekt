#ifndef klasy_h
#define klasy_h
#include "klasy.h"

Lista_wykladow::Lista_wykladow()
{
    string plik;
    string temp;
    string _tytul, _identyfikator ;
    int _ECTS;
    Wyklad *wyklad_temp=nullptr, *lista_koniec=nullptr;
    poczatek = nullptr;
    koniec = nullptr;
    int ile = 0;
    cout << "Wczytywanie listy wykladow z pliku...\n";
    cout << "Podaj nazwe pliku[wyklady.txt]: ";
    getline(cin, temp);
    if ( temp == "" ) plik = "wyklady.txt";
    else plik = temp;
    ifstream in( plik );
    while ( in >> _tytul )
    {
        wyklad_temp = new Wyklad;
        if ( ile == 0 ) poczatek = wyklad_temp;
        in >> _ECTS >> _identyfikator;
        (*wyklad_temp).zapisz(_tytul, _ECTS, _identyfikator);
        wyklad_temp -> nastepny = nullptr;
        if ( ile > 0 ) lista_koniec -> nastepny = wyklad_temp;
        lista_koniec = wyklad_temp;
        ++ile;
    }
    koniec = lista_koniec;
    cout << "\tWczytano " << ile << " wykladow z pliku " << "\"" << plik <<  "\"" << endl;
}

Lista_wykladow::~Lista_wykladow()
{
    string plik, temp;
    cout << "Zapisywanie listy wykladow do pliku..." << endl << "Podaj nazwe pliku "
         "[wyklady.txt]: ";
    //"wyciagamy" pozostawiony w wejsciu enter
    //cin.get();
    getline(cin, temp);
    if(temp == "") plik = "wyklady.txt";
    else plik = temp;
    ofstream out( plik );
    Wyklad *wyk_temp = poczatek, *wyk_temp_2;
    while( wyk_temp )
    {
        out << wyk_temp -> wypisz_tytul_podloga() << " "
            << wyk_temp -> wypisz_ECTS() << " "
            << wyk_temp -> wypisz_identyfikator();
            if( wyk_temp->nastepny) out<< endl;
        wyk_temp_2 = wyk_temp -> nastepny;
        delete wyk_temp;
        wyk_temp = wyk_temp_2;
    }
    cout << "\nLista studentow zapisana...\n\n";
    out.close();
}



void Lista_wykladow::wypisz_liste()
{
    Wyklad *tymcz = poczatek;
    if(tymcz == nullptr)
    {
        cout << "Lista jest pusta...\n";
        return;
    }
    int i = 1;
    while(tymcz!=nullptr)
    {
        cout << "Wyklad nr " << i++ << ":" << endl;
        (*tymcz).wypisz();
        cout <<endl;
        tymcz = tymcz->nastepny;
    }
}


void Lista_wykladow::dodaj_wyklad(string tytul, int ECTS, string identyfikator)
{
    Wyklad *nowy = new Wyklad;
    cout << endl;
    nowy->zapisz(tytul, ECTS, identyfikator);

    if (koniec != nullptr) koniec -> nastepny = nowy;
    //cout<<"OK";
    nowy -> nastepny = nullptr;
    // alternatywnie: (*nowy).nastepny = nullptr;
    koniec = nowy;
    if(poczatek == nullptr) poczatek = nowy;
    return;
}




void Lista_wykladow::usun_wyklad(string _identyfikator)
{


    Wyklad *tmp = poczatek;
    Wyklad *nast;

    if (tmp -> wypisz_identyfikator() == _identyfikator)
    {
        //jesli usuwamy pierwszy wyklad
        nast = tmp -> nastepny;
        poczatek=nast;
        if(koniec==tmp) //lista 1-elementowa
        {
            koniec=nullptr;
        }
        delete tmp;
        tmp=nullptr;
        return;
    }

    while(tmp->nastepny)
    {
        nast = tmp -> nastepny;
        if (nast -> wypisz_identyfikator() == _identyfikator)
        {
            //usuwamy nastepny wyklad
            if (koniec==nast)
            {
                koniec=tmp;
            }
            Wyklad* nastepniejszy = nast -> nastepny;
            tmp->nastepny = nastepniejszy;
            delete nast;
            nast=nullptr;
            return;
        }
        tmp=tmp->nastepny;
        if(tmp==nullptr) break; //warunek potrzebny przy usunieciu konca
    }
}



bool Lista_wykladow::czy_istnieje_id(string _identyfikator)
{
    Wyklad *tmp = poczatek;
    while(tmp)
    {
        if (tmp->wypisz_identyfikator() == _identyfikator)
            return true;
        tmp = tmp->nastepny;
    }
    return false;
}

bool Lista_wykladow::czy_istnieje_tytul(string _tytul)
{
    Wyklad *tmp = poczatek;
    while(tmp!= nullptr)
    {
        if (tmp->wypisz_tytul() == _tytul)
            return true;
        tmp = tmp->nastepny;
    }
    return false;
}

bool Lista_wykladow::czy_istnieje_ECTS(int _ECTS)
{
    Wyklad *tmp = poczatek;
    while(tmp!= nullptr)
    {
        if (tmp->wypisz_ECTS() == _ECTS)
            return true;
        tmp = tmp->nastepny;
    }
    return false;
}

void  Lista_wykladow::usun_wszystko()
{
    Wyklad *tmp=poczatek, *nast;
    while(tmp!=0)
    {
        nast = tmp->nastepny;
        delete tmp;
        tmp=nast;
    }
    poczatek=nullptr;
    koniec=nullptr;
}

bool  Lista_wykladow::czy_pusta()
{
    return (poczatek==nullptr);
}


void Lista_wykladow::wypisz_z_tablicy(string *tab_poczatek, int ile)
{
    string tab[ile];
    for(int j; j<ile; ++j)
    {
        tab[j]=*tab_poczatek;
        tab_poczatek++;
    }

    Wyklad *tmp= poczatek;
    int i=0;//numerek wypisywanego wykladu

    while(tmp!=nullptr)
    {

        for(int j=0; j<ile; ++j) //sprawdzamy czy *tmp jest na liscie indeksow
        {
            if (tmp->wypisz_identyfikator() == tab[j])
            {
                cout << "Wyklad nr " << ++i << ":" //<< //endl
                     <<*tmp<<endl;
                break;
            }
        }
        tmp= tmp->nastepny;
    }
    //if (i==0) cout<<"Brak wykladow.\n";

}


string Lista_wykladow::wypisz_tytul_po_id(string _identyfikator)
{
    Wyklad* tmp=poczatek;
    while(tmp)
    {
        if (tmp -> wypisz_identyfikator()==_identyfikator )
            return tmp->wypisz_tytul();
        tmp = tmp -> nastepny;
    }
    return "*brak wykladu*/n";
}


void Lista_wykladow::wypisz_o_id(string _id)
{
    Wyklad *tymcz = poczatek;
    int i = 0;
    while(tymcz!=nullptr)
    {
        if (tymcz->wypisz_identyfikator() == _id)
        {
            cout << "Wyklad nr " << ++i << ":" << endl;

            cout<< *tymcz<<endl;
            //tymcz->wypisz();
            cout<<endl;
        }
        tymcz = tymcz->nastepny;
    }
    if(i==0)
        cout << "Brak wykladow o indeksie "<<_id<< ".\n";
}

void Lista_wykladow::wypisz_o_tytule(string _tytul)
{
    Wyklad *tymcz = poczatek;
    int i = 0;
    while(tymcz!=nullptr)
    {
        if (tymcz->wypisz_tytul() == _tytul)
        {
            cout << "Wyklad nr " << ++i << ":" << endl;
            //cout<< *tymcz<<endl;
            tymcz->wypisz();
            cout<<endl;
        }
        tymcz = tymcz->nastepny;
    }
    if(i==0)
        cout << "Brak wykladow o tytule "<<_tytul<< ".\n";
}

void Lista_wykladow::wypisz_o_ECTS(int _ECTS)
{
    Wyklad *tymcz = poczatek;
    int i = 0;
    while(tymcz!=nullptr)
    {
        if (tymcz->wypisz_ECTS() == _ECTS)
        {
            cout << "Wyklad nr " << ++i << ":" << endl;
            //cout<< *tymcz<<endl;
            tymcz->wypisz();
            cout<<endl;
        }
        tymcz = tymcz->nastepny;
    }
    if(i==0)
        cout << "Brak wykladow z iloscia "<<_ECTS<< " ECTS.\n";
}


void Lista_wykladow::edytuj_tytul(string _tytul, string _identyfikator)
{
    Wyklad* tmp=poczatek;
    while(tmp)
    {
        if(tmp->wypisz_identyfikator() == _identyfikator)
        {
            tmp-> edytuj_tytul( _tytul);
            break;
        }
        tmp=tmp->nastepny;
    }
}


void Lista_wykladow::edytuj_ECTS(int _ECTS, string _identyfikator)
{
    Wyklad* tmp=poczatek;
    while(tmp)
    {
        if(tmp->wypisz_identyfikator() == _identyfikator)
        {
            tmp-> edytuj_ECTS( _ECTS);
            break;
        }
        tmp=tmp->nastepny;
    }
}

void Lista_wykladow::edytuj_identyfikator(string _identyfikator1, string _identyfikator2)
{
    Wyklad* tmp=poczatek;
    while(tmp)
    {
        if(tmp->wypisz_identyfikator() == _identyfikator1)
        {
            tmp-> edytuj_identyfikator( _identyfikator2);
            break;
        }
        tmp=tmp->nastepny;
    }
}


#endif // klasy_h
