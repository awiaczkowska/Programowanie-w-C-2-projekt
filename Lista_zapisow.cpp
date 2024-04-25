#include "klasy.h"

Lista_zapisow::Lista_zapisow()
{
    string plik;
    string temp;
    string _id_stud, _id_wyk;
    Zapis *zap_temp=nullptr, *lista_koniec=nullptr;
    poczatek = nullptr;
    koniec = nullptr;
    int ile = 0;
    cout << "Wczytywanie listy studentow z pliku...\n";
    cout << "Podaj nazwe pliku[zapisy.txt]: ";
    getline(cin, temp);
    if ( temp == "" ) plik = "zapisy.txt";
    else plik = temp;
    ifstream in( plik );
    while ( in>>_id_stud )
    {
        zap_temp = new Zapis;
        if ( ile == 0 ) poczatek = zap_temp;
        in >> _id_wyk;
        (*zap_temp).zapisz(_id_stud,_id_wyk);
        zap_temp -> nastepny = nullptr;
        if ( ile > 0 ) lista_koniec -> nastepny = zap_temp;
        lista_koniec = zap_temp;
        ++ile;
    }
    koniec = lista_koniec;
    cout << "\tWczytano " << ile << " zapisow z pliku " << "\"" << plik <<  "\"" << endl;
}

Lista_zapisow::~Lista_zapisow()
{
    string plik, temp;
    cout << "Zapisywanie listy zapisow do pliku..." << endl << "Podaj nazwe pliku "
         "[zapisy.txt]: ";
    //"wyciagamy" pozostawiony w wejsciu enter
    //cin.get();
    getline(cin, temp);
    if(temp == "") plik = "zapisy.txt";
    else plik = temp;
    ofstream out( plik );
    Zapis *zap_temp = poczatek, *zap_temp_2;
    while( zap_temp )
    {
        out << zap_temp -> wypisz_student_id() << " "
            << zap_temp -> wypisz_wyklad_id() << " " ;
            if(zap_temp->nastepny)out<< endl;
        zap_temp_2 = zap_temp -> nastepny;
        delete zap_temp;
        zap_temp = zap_temp_2;
    }
    cout << "\nLista zapisow zapisana...\n\n";
    out.close();
}


void Lista_zapisow::usun(string _student, string _wyklad)
{
    Zapis *tmp = poczatek;
    Zapis *nast;
    if (tmp -> wypisz_student_id() == _student and tmp -> wypisz_wyklad_id() ==_wyklad )
    {
        //jesli usuwamy pierwszy zapis
        nast = tmp -> nastepny;
        poczatek=nast;
        if(koniec==tmp) //lista 1-elementowa
            koniec=nullptr;
        delete tmp;
        tmp=nullptr;
        return;
    }

    while(tmp->nastepny)
    {
        nast = tmp -> nastepny;
        if (nast -> wypisz_student_id() == _student and nast -> wypisz_wyklad_id() ==_wyklad )
        {
            //usuwamy nastepny zapis
            if (koniec==nast)
                koniec=tmp;
            Zapis * nastepniejszy = nast -> nastepny;
            tmp->nastepny = nastepniejszy;
            delete nast;
            nast=nullptr;
            return;
        }
        tmp=tmp->nastepny;
    }
}


void Lista_zapisow::wypisz_liste()
{
    Zapis *tymcz = poczatek;
    if(tymcz == nullptr)
    {
        cout << "Lista jest pusta...\n";
        return;
    }
    int i = 1;
    while(tymcz!=nullptr)
    {
        cout << "Zapis nr " << i++ << ":" << endl;
        cout<<*tymcz<<endl;
        tymcz = tymcz->nastepny;
    }
}


void Lista_zapisow::dodaj(string _id_student, string _id_wyklad)
{
    Zapis *nowy = new Zapis;
    cout << endl;
    nowy->zapisz(_id_student, _id_wyklad);

    if (koniec != nullptr) koniec -> nastepny = nowy;
    //cout<<"OK";
    nowy -> nastepny = nullptr;
    // alternatywnie: (*nowy).nastepny = nullptr;
    koniec = nowy;
    if(poczatek == nullptr) poczatek = nowy;
    return;
}


void Lista_zapisow::usun_wszystkie_wyk(string _wyklad)
{
    Zapis *tmp = poczatek;
    Zapis *nast;

    while (tmp -> wypisz_wyklad_id() == _wyklad )
    {
        //jesli usuwamy pierwszy zapis z listy
        nast = tmp -> nastepny;
        poczatek=nast;
        if(koniec==tmp) //lista 1-elementowa
            koniec=nullptr;
        delete tmp;
        tmp = poczatek;
    }
    while(tmp->nastepny)
    {
        nast = tmp -> nastepny;
        while (nast -> wypisz_wyklad_id() == _wyklad )
        {
            //usuwamy nastepny zapis
            if (koniec==nast)
            {
                 koniec=tmp;
                 tmp->nastepny=nullptr;
                 delete nast;
                break;
            }
            Zapis * nastepniejszy = nast -> nastepny; //tmp -> nast -> nastepniejszy
            tmp->nastepny = nastepniejszy;  //tmp -> nastepniejszy
            delete nast;
            nast=nastepniejszy;
        }
        tmp=tmp->nastepny;
        if(tmp==nullptr) break; //warunek potrzebny przy usunieciu konca
    }
}



void Lista_zapisow::usun_wszystkie_stud(string _student)
{
    Zapis *tmp = poczatek;
    Zapis *nast;

    while (tmp -> wypisz_student_id() == _student )
    {
    cout<<"1znaleziono "<<tmp->wypisz_wyklad_id()<<endl;

        //jesli usuwamy pierwszy zapis z listy
        nast = tmp -> nastepny;
        poczatek=nast;
        if(koniec==tmp) //lista 1-elementowa
            koniec=nullptr;
        delete tmp;
        tmp = poczatek;
    }
    while(tmp->nastepny)
    {
        nast = tmp -> nastepny;
        while (nast -> wypisz_student_id() == _student )
        {
            cout<<"znaleziono "<<nast->wypisz_wyklad_id()<<endl;
            //usuwamy nastepny zapis
            if (koniec==nast)
            {
                 koniec=tmp;
                 tmp->nastepny=nullptr;
                 delete nast;
                break;
            }
            Zapis * nastepniejszy = nast -> nastepny; //tmp -> nast -> nastepniejszy
            tmp->nastepny = nastepniejszy;  //tmp -> nastepniejszy
            delete nast;
            nast=nastepniejszy;
        }
        tmp=tmp->nastepny;
        if(tmp==nullptr) break;
    }
}


bool Lista_zapisow::czy_student(string stud_id)
{
    Zapis *tmp = poczatek;
    while(tmp!= nullptr)
    {
        if (tmp->wypisz_student_id() == stud_id)
            return true;
        tmp = tmp->nastepny;
    }
    return false;
}

bool Lista_zapisow::czy_wyklad(string wyk_id)
{
    Zapis *tmp = poczatek;
    while(tmp!= nullptr)
    {
        if (tmp->wypisz_wyklad_id() == wyk_id)
            return true;
        tmp = tmp->nastepny;
    }
    return false;
}

bool Lista_zapisow::czy_zapis(string stud_id,string wyk_id )
{
    Zapis *tmp = poczatek;
    while(tmp!= nullptr)
    {
        if (tmp->wypisz_student_id() == stud_id  &&  tmp -> wypisz_wyklad_id() ==wyk_id )
            return true;
        tmp = tmp->nastepny;
    }
    return false;
}

void  Lista_zapisow::usun_wszystko()
{
    Zapis* tmp=poczatek, *nast;
    while(tmp)
    {
        nast=tmp->nastepny;
         delete tmp;
        tmp=nast;
    }
    poczatek=nullptr; koniec=nullptr;
}

bool  Lista_zapisow::czy_pusta()
{
    return (poczatek==nullptr);
}



string* Lista_zapisow::studenci_z_wykladu(string id_wyk,  int &ile)
{
    string* tab= nullptr; //tablica pusta; tablica przechowuje indeksy studentow z wykladu
    ile=0; //ilisc studentow z wykladu
    Zapis* tmp=poczatek;
    while(tmp)
    {
        if (tmp->wypisz_wyklad_id() == id_wyk)
        {
            string* tab2 = new string [ile+1]; //tworzymy nowa tablice o 1 pole wieksza
            for( int j = 0; j < ile; ++j )
                tab2[j] = tab[j];
            tab2[ile]= tmp->wypisz_student_id();
            ile++;
            if(tab != nullptr) delete[] tab; //usuwamy stara tablice
            tab=tab2;
        }
        tmp = tmp->nastepny;
    }
    return tab;
}

string* Lista_zapisow::wyklady_studenta(string id_stud, int &ile )
{
    string* tab= nullptr; //tablica pusta; tablica przechowuje indeksy wykladow studenta
    ile=0; //wykladow studenta
    Zapis* tmp = poczatek;
    while(tmp)
    {
        if (tmp->wypisz_student_id() == id_stud)
        {
            string* tab2 = new string [ile+1];
            for( int j = 0; j < ile; ++j ) tab2[j] = tab[j];
            tab2[ile]= tmp->wypisz_wyklad_id();
            ile++;
            if(tab != nullptr) delete[] tab;
            tab=tab2;
        }
        tmp = tmp->nastepny;
    }
    return tab;
}


void Lista_zapisow::edytuj_student_id(string stud_id1,string stud_id2 )
{
    //zamieniamy id edytowanego studenta we wszystkich zapisach
    Zapis* tmp=poczatek;
    while(tmp)
    {
        if(tmp->wypisz_student_id() == stud_id1)
        {
            tmp-> edytuj_student_id(stud_id2);
        }
        tmp=tmp->nastepny;
    }
}

void Lista_zapisow::edytuj_wyklad_id( string wyk_id1,string wyk_id2)
{
    //zamieniamy id edytowanego studenta we wszystkich zapisach
    Zapis* tmp=poczatek;
    while(tmp)
    {
        if(tmp->wypisz_wyklad_id() == wyk_id1)
        {
            tmp-> edytuj_wyklad_id( wyk_id2);
        }
        tmp=tmp->nastepny;
    }
}



string* Lista_zapisow::zapisani_stud(int &ile)
{
    string* tab= nullptr; //tablica pusta; tablica przechowuje indeksy studentow z wykladu
    ile=0; //ilisc studentow z wykladu
    Zapis* tmp=poczatek;
    bool czy_nowy;
    while(tmp)
    {
        czy_nowy=true;
        for(int j=0;j<ile;j++) //sprawdzamy czy identyfikator juz zostal zapisany
            if (tmp->wypisz_student_id() == tab[j])
                czy_nowy==false;

        if(czy_nowy)
        {
            string* tab2 = new string [ile+1]; //tworzymy nowa tablice o 1 pole wieksza
            for( int j = 0; j < ile; ++j )
                tab2[j] = tab[j];
            tab2[ile]= tmp->wypisz_student_id();
            ile++;
            if(tab != nullptr) delete[] tab; //usuwamy stara tablice
            tab=tab2;
        }
        tmp = tmp->nastepny;
    }
    return tab;
}

string* Lista_zapisow::wyk_z_zapisami( int &ile)
{
    string* tab= nullptr; //tablica pusta; tablica przechowuje indeksy studentow z wykladu
    ile=0; //ilisc studentow z wykladu
    Zapis* tmp=poczatek;
    bool czy_nowy;
    while(tmp)
    {
        czy_nowy=true;
        for(int j=0;j<ile;j++) //sprawdzamy czy identyfikator juz zostal zapisany
            if (tmp->wypisz_wyklad_id() == tab[j]) czy_nowy==false;

        if(czy_nowy)
        {
            string* tab2 = new string [ile+1]; //tworzymy nowa tablice o 1 pole wieksza
            for( int j = 0; j < ile; ++j )
                tab2[j] = tab[j];
            tab2[ile]= tmp->wypisz_wyklad_id();
            ile++;
            if(tab != nullptr) delete[] tab; //usuwamy stara tablice
            tab=tab2;
        }
        tmp = tmp->nastepny;
    }
    return tab;
}


