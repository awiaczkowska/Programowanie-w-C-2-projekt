#ifndef klasy_h
#define klasy_h
#include "klasy.h"

Lista_studentow::Lista_studentow()
{
    string plik;
    string temp;
    string _nazwisko, _imie, _identyfikator;
    Student *student_temp=nullptr, *lista_koniec=nullptr;
    poczatek = nullptr;
    koniec = nullptr;
    int ile = 0;
    cout << "Wczytywanie listy studentow z pliku...\n";
    cout << "Podaj nazwe pliku[studenci.txt]: ";
    getline(cin, temp);
    if ( temp == "" ) plik = "studenci.txt";
    else plik = temp;
    ifstream in( plik );
    while ( in>>_nazwisko )
    {
        student_temp = new Student;
        if ( ile == 0 ) poczatek = student_temp;
        //in >> _nazwisko >> _imie >> _identyfikator;
        in >> _imie >> _identyfikator;
        (*student_temp).zapisz(_nazwisko, _imie, _identyfikator);
        student_temp -> nastepny = nullptr;
        if ( ile > 0 ) lista_koniec -> nastepny = student_temp;
        lista_koniec = student_temp;
        ++ile;
    }
    koniec = lista_koniec;
    cout << "\tWczytano " << ile << " studentow z pliku " << "\"" << plik <<  "\"" << endl;
}



Lista_studentow::~ Lista_studentow()
{
    string plik, temp;
    cout << "Zapisywanie listy studentow do pliku..." << endl << "Podaj nazwe pliku "
         "[studenci.txt]: ";
    //"wyciagamy" pozostawiony w wejsciu enter
    //cin.get();
    getline(cin, temp);
    if(temp == "") plik = "studenci.txt";
    else plik = temp;
    ofstream out( plik );
    Student *student_temp = poczatek, *student_temp_2;
    while( student_temp )
    {
        out << student_temp -> wypisz_nazwisko() << " "
            << student_temp -> wypisz_imie() << " "
            << student_temp -> wypisz_identyfikator() ;
        if(student_temp->nastepny)out<< endl;
        student_temp_2 = student_temp -> nastepny;
        delete student_temp;
        student_temp = student_temp_2;
    }
    out.close();
    cout << "\nLista studentow zapisana...\n\n";
}


void Lista_studentow::wypisz_liste()
{
    Student *tymcz = poczatek;
    if(tymcz == nullptr)
    {
        cout << "Lista jest pusta...\n";
        return;
    }
    int i = 1;
    while(tymcz!=nullptr)
    {
        cout << "Student nr " << i++ << ":" << endl;
        cout<<*tymcz<<endl;
        tymcz = tymcz->nastepny;
    }
}


void Lista_studentow::dodaj_studenta(string nazwisko, string imie, string identyfikator)
{
    Student *nowy = new Student;
    cout << endl;
    nowy->zapisz(nazwisko, imie, identyfikator);

    if (koniec != nullptr) koniec -> nastepny = nowy;
    //cout<<"OK";
    nowy -> nastepny = nullptr;
    // alternatywnie: (*nowy).nastepny = nullptr;
    koniec = nowy;
    if(poczatek == nullptr) poczatek = nowy;
    return;
}



void Lista_studentow::wypisz_o_nazwisku(string _nazwisko)
{
    Student *tymcz = poczatek;
    int i = 0;
    while(tymcz!=nullptr)
    {

        if (tymcz->wypisz_nazwisko() == _nazwisko)
        {
            cout << "Student nr " << ++i << ":" << endl;
            cout<< *tymcz<<endl;
        }
        tymcz = tymcz->nastepny;
    }
    if(i==0)
        cout << "Brak studentow o nazwisku "<<_nazwisko<< ".\n";
}


void Lista_studentow::wypisz_o_imieniu(string _imie)
{
    Student *tymcz = poczatek;
    int i = 0;
    while(tymcz!=nullptr)
    {
        if (tymcz->wypisz_imie() == _imie)
        {
            cout << "Student nr " << ++i << ":" << endl;
            cout<< *tymcz<<endl;
        }
        tymcz = tymcz->nastepny;
    }
    if(i==0)
        cout << "Brak studentow o imieniu "<<_imie<< ".\n";
}

void Lista_studentow::wypisz_o_id(string _id)
{
    Student *tymcz = poczatek;
    int i = 0;
    while(tymcz!=nullptr)
    {
        if (tymcz->wypisz_identyfikator() == _id)
        {
            cout << "Student nr " << ++i << ":" << endl;
            cout<< *tymcz<<endl;
        }
        tymcz = tymcz->nastepny;
    }
    if(i==0)
        cout << "Brak studentow o indeksie "<<_id<< ".\n";
}



Student* Lista_studentow::znajdz_po_identyfikatorze(string _identyfikator)
/*zakladam ze jest tylko jeden student o danym identyfikatorze;
w przypadku braku studenta fkcja zwraca nullptr*/
{
    Student *stud_tmp = poczatek;
    while(stud_tmp!= nullptr)
    {
        if(stud_tmp->wypisz_identyfikator() == _identyfikator)
        {
            return stud_tmp;
        }
        stud_tmp=stud_tmp -> nastepny;
    }
    return nullptr;
}



void Lista_studentow::usun(string _identyfikator)
{
    if(! czy_istnieje_id(_identyfikator) )
    {
        cout<<"Na liscie nie ma studenta o identyfikatorze "<<_identyfikator<<"! :(\n";
        return;
    }
/////[...]
    //usuwamy studenta z listy
    Student *stud_tmp = poczatek;
    Student *stud_nast;

    if(stud_tmp->wypisz_identyfikator() == _identyfikator)
    {
        //jesli usuwamy pierwszego studenta
        stud_nast=stud_tmp->nastepny;
        poczatek=stud_nast;

        if(koniec==stud_tmp) //lista 1-elementowa
        {
            koniec=nullptr;
        }
        delete stud_tmp;
        stud_tmp=nullptr;

        return;
    }
    while(stud_tmp->nastepny)
    {
        stud_nast=stud_tmp->nastepny;
        if ( stud_nast->wypisz_identyfikator()== _identyfikator)
        {
            //usuwamy stud_nast
            if(koniec==stud_nast)
            {
                koniec=stud_tmp;
            }
            Student *nastepniejszy= stud_nast->nastepny;
            stud_tmp->nastepny = nastepniejszy;
            delete stud_nast;
            stud_nast=nullptr;
            return;
        }
        stud_tmp=stud_nast;
        if(stud_tmp==nullptr) break; //warunek potrzebny przy usunieciu konca
    }
}




bool Lista_studentow::czy_istnieje_id(string _identyfikator)
{
    Student *tmp = poczatek;
    while(tmp!= nullptr)
    {
        if (tmp->wypisz_identyfikator() == _identyfikator)
            return true;
        tmp = tmp->nastepny;
    }
    return false;
}

bool Lista_studentow::czy_istnieje_nazw(string _nazwisko)
{
    Student *tmp = poczatek;
    while(tmp!= nullptr)
    {
        if (tmp->wypisz_nazwisko() == _nazwisko)
            return true;
        tmp = tmp->nastepny;
    }
    return false;
}


bool Lista_studentow::czy_istnieje_imie(string _imie)
{
    Student *tmp = poczatek;
    while(tmp!= nullptr)
    {
        if (tmp->wypisz_imie() == _imie)
            return true;
        tmp = tmp->nastepny;
    }
    return false;
}
void  Lista_studentow::usun_wszystko()
{
    Student* tmp=poczatek, *nast;
    while(tmp)
    {
        nast=tmp->nastepny;
        delete tmp;
        tmp=nast;
    }
    poczatek=nullptr;
    koniec=nullptr;
}


bool  Lista_studentow::czy_pusta()
{
    return (poczatek==nullptr);
}


void Lista_studentow::wypisz_z_tablicy(string *tab_poczatek, int ile)
{
    string tab[ile];
    //cout<<ile;
    for(int j=0; j<ile; ++j) //przepisujemy tablice
    {
        tab[j]=*tab_poczatek;
        //cout<<tab[j];
        if (j<ile-1)tab_poczatek++;
    }
    Student *tmp= poczatek;
    int i=0;//numerek wypisywanego studenta

    while(tmp!=nullptr)
    {

        for(int j=0; j<ile; ++j) //sprawdzamy czy *tmp jest na liscie indeksow
        {
            if (tmp->wypisz_identyfikator() == tab[j])
            {
                cout << "Student nr " << ++i << ":" << endl
                     <<*tmp<<endl;
                break;
            }
        }
        tmp= tmp->nastepny;
    }
    //if (i==0) cout<<"Brak studentow.\n";

}

string Lista_studentow::wypisz_imiemazwisko_po_id(string _identyfikator)
{
    Student* tmp=poczatek;
    while(tmp)
    {
        if (tmp -> wypisz_identyfikator()==_identyfikator )
        {
            string Str="";
            Str+=(tmp->wypisz_imie() ) ;
            Str+= " " ;
            Str+= (tmp->wypisz_nazwisko() );
            return Str;
        }
        tmp = tmp -> nastepny;
    }
    return "*brak studenta*/n";

}


void Lista_studentow::edytuj_imie(string _imie, string _identyfikator)
{
    Student* tmp=poczatek;
    while(tmp)
    {
        if(tmp->wypisz_identyfikator() == _identyfikator)
        {
            tmp-> edytuj_imie( _imie);
            break;
        }
        tmp=tmp->nastepny;
    }
}
void Lista_studentow::edytuj_nazwisko(string _nazwisko, string _identyfikator)
{
    Student* tmp=poczatek;
    while(tmp)
    {
        if(tmp->wypisz_identyfikator() == _identyfikator)
        {
            tmp-> edytuj_nazwisko( _nazwisko);
            break;
        }
        tmp=tmp->nastepny;
    }
}
void Lista_studentow::edytuj_identyfikator(string _identyfikator1, string _identyfikator2)
{
    Student* tmp=poczatek;
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




string* Lista_studentow::niekompatybilne (string *tab_indeksow, int rozmiar, int &ile )
{
    //funkcja przyjmuje tablice indeksow i jej rozmiar; zwraca tablice indeksow ktorych nie ma na liscie
    //studentow i w referencji zmiennej ile podaje rozmiar tablicy
    ///funkcja nie jest wykorzystystana w ostatecznej wersji programu
    string *zle=nullptr;
    ile=0;
    for( int i=0 ;i<rozmiar; ++i)
    {
        if (! czy_istnieje_id(*tab_indeksow) )
        {
            string* tab2 = new string [ile+1]; //tworzymy nowa tablice o 1 pole wieksza
            for( int j = 0; j < ile; ++j )
                tab2[j] = zle[j];
            tab2[ile]= *tab_indeksow;
            ile++;
            if(zle != nullptr) delete[] zle; //usuwamy stara tablice
            zle=tab2;
        }
        tab_indeksow++;
    }
    return zle;
}

#endif // klasy_h
