#include "funkcje_main.h"

void dodaj_zapisz(int wybor2, Lista_studentow &studenci ,Lista_wykladow &wyklady, Lista_zapisow &zapisy)
{
    switch (wybor2)
    {
    case 0:
        break;
    case 1:
    {
        string nazwisko, imie, identyfikator;
        cout << "Prosze podac nazwisko: ";
        cin >> nazwisko;
        cin.get();
        cout << endl;
        cout << "Prosze podac imie: ";
        cin >> imie;
        cin.get();
        cout << endl;
        cout << "Prosze podac numer indeksu: ";
        cin >> identyfikator;
        cin.get();
        while(studenci.czy_istnieje_id(identyfikator))
        {
        cout<<"Student o identyfikatorze "<<identyfikator<<" juz istnieje.\nWprowadz inny indeks: ";
        cin >> identyfikator;
        cin.get();
        }
        studenci.dodaj_studenta(nazwisko, imie, identyfikator);
        break;
    }

    case 2:
    {
        string tytul, identyfikator;
        int ECTS;
        cout << "Prosze podac tytul: ";
        getline(cin, tytul);
        cout << endl;
        cout << "Prosze podac ECTS: ";
        cin >> ECTS;
        cin.get();
        cout << endl;
        cout << "Prosze podac identyfikator: ";
        cin >> identyfikator;
        cin.get();
        while(wyklady.czy_istnieje_id(identyfikator))
        {
        cout<<"Wyklad o identyfikatorze "<<identyfikator<<" juz istnieje.\nWprowadz inny identyfikator: ";
        cin >> identyfikator;
        cin.get();
        }
        wyklady.dodaj_wyklad(tytul, ECTS, identyfikator);
        break;
    }

    case 3:
    {
        string student, wyklad;
        cout << "Prosze podac identyfikator studenta: ";
        cin >> student;
        cin.get();
        if(! studenci.czy_istnieje_id(student) )
        {
            cout<<"Nie ma studenta o identyfikatorze "<<student<<" :(\n";
            break;
        }
        cout << "Prosze podac identyfikator wykladu: ";
        cin >> wyklad;
        cin.get();
        if(! wyklady.czy_istnieje_id(wyklad) )
        {
            cout<<"Nie ma wykladu o identyfikatorze "<<wyklad<<" :(\n";
            break;
        }
        if(zapisy.czy_zapis(student,wyklad))
        {
        cout<<"Student "<<studenci.wypisz_imiemazwisko_po_id(student) <<" jest juz zapisany na wyklad "<<wyklady.wypisz_tytul_po_id(wyklad)<<".\n";
        break;
        }
        zapisy.dodaj(student, wyklad);
        break;
    }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void usun(int wybor2, Lista_studentow &studenci,Lista_wykladow &wyklady, Lista_zapisow &zapisy)
{
    int wybor3;
    switch (wybor2)
    {
    case 0:
        break;
    case 1:
    {
        string identyfikator;
        cout<<"Podaj identyfikator studenta, ktorego chcesz usunac: ";
        cin>>identyfikator;
        cin.get();
        if(! studenci.czy_istnieje_id(identyfikator) )
    {
        cout<<"Na liscie nie ma studenta o identyfikatorze "<<identyfikator<<" :(\n";
        break;
    }
        if (zapisy.czy_student(identyfikator))
        {
            cout<<"Podany student obecnie jest zapisany na przedmoty, co uniemozliwia kontynuacje usuwania!\n"
                <<"Wmagane jest wczesniejsze wypisanie go ze wszystkich wykladow.\n"
                <<"Czy chcesz dokonac automatycznego wypisu? [1]\t ";
            cin>>wybor3;
            cin.get();
            if(wybor3==1)
                zapisy.usun_wszystkie_stud(identyfikator);
            else
            {
                cout<<"Usuwanie wstrzymane.\n" ;
                break;
            }
        }
        studenci.usun(identyfikator);
        break;
    }

    case 2:
    {
        string identyfikator;
        cout<<"Podaj identyfikator wykladu, ktory chcesz usunac: ";
        cin>>identyfikator;
        cin.get();
        if(! wyklady.czy_istnieje_id(identyfikator) )
    {
        cout<<"Na liscie nie ma wykladu o identyfikatorze "<<identyfikator<<" :(\n";
        break;
    }
        if (zapisy.czy_wyklad(identyfikator))
        {
            cout<<"Na podany wyklad sa zapisani studenci, co uniemozliwia kontynuacje usuwania!\n"
                <<"Wmagane jest wczesniejsze wypisanie wszystkich studentow z usuwanego przedmiotu.\n"
                <<"Czy chcesz dokonac automatycznego wypisu? [1]\t ";
            cin>>wybor3;
            cin.get();
            if(wybor3==1)
                zapisy.usun_wszystkie_wyk(identyfikator);

            else
            {
                cout<<"Usuwanie wstrzymane.\n" ;
                break;
            }
            ///cout<<"BRR";
        }
        wyklady.usun_wyklad(identyfikator);
        break;
    }
    case 3:
    {
        string stud, wyk;
        cout<<"Podaj indeks studenta, ktorego chcesz wypisac z wykladu: ";
        cin>>stud;
        cin.get();
        cout<<"Podaj identyfikator wykladu, z ktorego chcesz wypisac podanego studenta: ";
        cin>>stud;
        cin.get();
        zapisy.usun(stud,wyk);
        break;
    }

    case 4:
    {
        cout<<"\t\t1. Usun wszystkich studentow\n"
            <<"\t\t2. Usun wszystkie wyklady\n"
            <<"\t\t3. Usun wszystkie zapisy\n"

            <<"\t\t4. Usun wszystkie zapisy studenta\n"
            <<"\t\t5. Usun wszystkich studentow z wykladu\n"
            <<"\t\t0. WROC DO MENU GLOWNEGO\n";
        cout<< "\n\t\tTwoj wybor: ";
        cin>>wybor3;
        cin.get();
        usun_wszystkich(wybor3,studenci,wyklady,zapisy);
        break;
    }

    }
}
void usun_wszystkich(int wybor3, Lista_studentow &studenci,Lista_wykladow &wyklady, Lista_zapisow &zapisy)
{
    int wybor4;
    switch (wybor3)
    {
    case 0:
        break;
    case 1:
    {
        if(! zapisy.czy_pusta())
        {
            cout<<"Studenci obecnie sa zapisani na przedmoty, co uniemozliwia kontynuacje usuwania!"
                <<"Wmagane jest wczesniejsze wypisanie studentow z wykladow.\n"
                <<"Czy chcesz dokonaæ automatycznego wypisu? [1]\t ";
            cin>>wybor4;
            cin.get();
            if(wybor4==1)
                zapisy.usun_wszystko();
            else
            {
                cout<<"Usuwanie wstrzymane.\n" ;
                break;
            }
        }
        studenci.usun_wszystko();
        break;
    }

    case 2:
    {
        if(!zapisy.czy_pusta())
        {
            cout<<"Na wyklady obecnie sa zapisani na studenci, co uniemozliwia\n kontynuacje usuwania!"
                <<"Wmagane jest wczesniejsze wypisanie wszystkich studentow wykladow.\n"
                <<"Czy chcesz dokonaæ automatycznego wypisu? [1]\t ";
            cin>>wybor4;
            cin.get();
            if(wybor4==1)
                zapisy.usun_wszystko();
            else
            {
                cout<<"Usuwanie wstrzymane.\n" ;
                break;
            }
        }
        wyklady.usun_wszystko();
        break;
    }
    case 3:
    {
        zapisy.usun_wszystko();
        break;
    }
    case 4:
    {
        string identyfikator;
        cout<<"Podaj indeks studenta, ktorego chcesz wypisac ze wszystkich przedmiotow: ";
        cin>>identyfikator;
        cin.get();
        if(!studenci.czy_istnieje_id(identyfikator))
        {
            cout<<"Nie istnieje student o identyfikatorze "<<identyfikator<<".\n";
            break;
        }
        zapisy.usun_wszystkie_stud(identyfikator);
        break;
    }
    case 5:
    {
        string identyfikator;
        cout<<"Podaj identyfikator wykladu,z ktorego chcesz wypisac wszystkich studentow: ";
        cin>>identyfikator;
        cin.get();
        if(wyklady.czy_istnieje_id(identyfikator))
        {
            cout<<"Nie istnieje wyklaad o identyfikatorze "<<identyfikator<<".\n";
            break;
        }
        zapisy.usun_wszystkie_wyk(identyfikator);
        break;
    }


    }

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void wypisz(int wybor2, Lista_studentow &studenci,Lista_wykladow &wyklady, Lista_zapisow &zapisy)
{
    int wybor3;
    switch (wybor2)
    {
    case 0:
        break;
    case 1:
    {
        studenci.wypisz_liste();
        break;
    }

    case 2:
    {
        wyklady.wypisz_liste();
        break;
    }

    case 3:
    {
        zapisy.wypisz_liste();
        break;
    }
    case 4:
    {
        int ile;
        string identyfikator;
        cout<<"Podaj identyfikator wykladu: ";
        cin>>identyfikator;
        cin.get();

        if( ! wyklady.czy_istnieje_id(identyfikator))
        {
            cout<<"Nie ma wykladu o identyfikatorze "<<identyfikator<<". :(\n";
            break;
        }
        string* tab =zapisy.studenci_z_wykladu(identyfikator, ile );
        if (ile==0)
        {
            cout<<"Brak studentow zapisanych na wyklad "<< wyklady.wypisz_tytul_po_id(identyfikator)<<".\n";
            break;
        }

        cout<<"Lista osob zapisanych na wyklad "<<wyklady.wypisz_tytul_po_id(identyfikator)<<":\n";

        studenci.wypisz_z_tablicy(tab, ile);
        delete[] tab;
        break;
    }

    case 5:
    {
        int ile;
        string identyfikator;
        cout<<"Podaj identyfikator studenta: ";
        cin>>identyfikator;
        cin.get();
        if( ! studenci.czy_istnieje_id(identyfikator))
        {
            cout<<"Nie ma studenta o identyfikatorze "<<identyfikator<<" :(\n";
            break;
        }
        string* tab =zapisy.wyklady_studenta(identyfikator, ile );
        if (ile==0)
        {
            cout<<"Brak studentow zapisanych na wyklad "<< wyklady.wypisz_tytul_po_id(identyfikator)<<endl;
            break;
        }
        cout<<"Lista wykladow studenta "<<studenci.wypisz_imiemazwisko_po_id(identyfikator)<<":\n";
        wyklady.wypisz_z_tablicy(tab, ile);
        delete[] tab;
        break;
    }

    case 6:
    {
        cout<<"\t\t1. Wypisz studenta o podanym indeksie\n"
            <<"\t\t2. Wypisz studenta(ow) o podanym nazwisku\n"
            <<"\t\t3. Wypisz studentow o podanym imieniu\n"
            <<"\t\t0. WROC DO MENU GLOWNEGO\n";
        cout<< "\n\t\tTwoj wybor: ";
        cin>>wybor3;
        cin.get();
        cout<<endl<<endl;
        wypisz_studenta( wybor3,studenci);
        break;
    }

    case 7:
    {
        cout<<"\t\t1. Wypisz wyklad o podanym indeksie\n"
            <<"\t\t2. Wypisz wyklad(y) o podanym tytule\n"
            <<"\t\t3. Wypisz wyklady o podanych ECTS\n"
            <<"\t\t0. WROC DO MENU GLOWNEGO\n";
        cout<< "\n\t\tTwoj wybor: ";
        cin>>wybor3;
        cin.get();
        cout<<endl<<endl;
        wypisz_wyklad( wybor3,wyklady);
        break;
    }
    }

}

void wypisz_studenta(int wybor3, Lista_studentow &studenci)
{
    switch(wybor3)
    {
    case 0:
        break;
    case 1:
    {
        string identyfikator;
        cout<<"Podaj identyfikator studenta: ";
        cin>>identyfikator;
        cin.get();
        studenci.wypisz_o_id(identyfikator);
        break;
    }
    case 2:
    {
        string nazwisko;
        cout<<"Podaj nazwisko studenta: ";
        cin>>nazwisko;
        cin.get();
        studenci.wypisz_o_nazwisku(nazwisko);
        break;
    }
    case 3:
    {
        string imie;
        cout<<"Podaj imie studenta: ";
        cin>>imie;
        cin.get();
        studenci.wypisz_o_imieniu(imie);
        break;
    }
    }
}

void wypisz_wyklad(int wybor3,Lista_wykladow &wyklady)
{
    switch(wybor3)
    {
    case 0:
        break;
    case 1:
    {
        string identyfikator;
        cout<<"Podaj identyfikator wykladu: ";
        cin>>identyfikator;
        cin.get();
        wyklady.wypisz_o_id(identyfikator);
        break;
    }
    case 2:
    {
        string tytul;
        cout<<"Podaj tytul wykladu: ";
        getline(cin,tytul);
        wyklady.wypisz_o_tytule(tytul);
        break;
    }


    case 3:
    {
        int ECTS;
        cout<<"Podaj liczbe punktow ECTS wykladu: ";
        cin>>ECTS;
        cin.get();
        wyklady.wypisz_o_ECTS(ECTS);
        break;
    }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sprawdz_czy(int wybor2, Lista_studentow &studenci,Lista_wykladow &wyklady, Lista_zapisow &zapisy)
{
        int wybor3;
        switch (wybor2)
        {
        case 0:
            break;

        case 1:
        {
            cout<<"\t\t1. Sprawdz czy istnieje student o podanym indeksie\n"
                <<"\t\t2. Sprawdz czy istnieje student o podanym nazwisku\n"
                <<"\t\t3. Sprawdz czy istnieje student o podanym imieniu\n"
                <<"\t\t0. WROC DO MENU GLOWNEGO\n";
            cout<< "\n\t\tTwoj wybor: ";
            cin>>wybor3;
            cin.get();
            sprawdz_czy_istnieje_student(wybor3,studenci,wyklady,zapisy);

            break;
        }
        case 2:
        {
            cout<<"\t\t1. Sprawdz czy istnieje wyklad o podanym indeksie\n"
                <<"\t\t2. Sprawdz czy istnieje wyklad o podanym tytule\n"
                <<"\t\t3. Sprawdz czy istnieje wyklad o podanych ECTS\n"
                <<"\t\t0. WROC DO MENU GLOWNEGO\n";
            cout<< "\n\t\tTwoj wybor: ";
            cin>>wybor3;
            cin.get();
            sprawdz_czy_istnieje_wyklad(wybor3,studenci,wyklady,zapisy);
        }
        case 3:
        {
            string student, wyklad;
            cout<<"Podaj indeks studenta: ";
            cin>>student;
            cin.get();
            if (!studenci.czy_istnieje_id(student))
            {
                cout<<"Nie ma studenta o identyfikatorze "<<student <<" :(\n";
                break;
            }
            cout<<"Podaj identyfikator wykladu: ";
            cin>>wyklad;
            cin.get();
            if (! wyklady.czy_istnieje_id(wyklad))
            {
                cout<<"Nie ma wykladu o identyfikatorze "<<wyklad <<" :(\n";
                break;
            }
            if( zapisy.czy_zapis(student, wyklad)) cout<<"TAK, student "<<studenci.wypisz_imiemazwisko_po_id(student )
                        <<" jest zapisany na wyklad "<<wyklady.wypisz_tytul_po_id(wyklad)<<".\n";
            else cout<<"NIE, student "<<studenci.wypisz_imiemazwisko_po_id(student )
                         <<" nie jest zapisany na wyklad "<<wyklady.wypisz_tytul_po_id(wyklad)<<".\n";
            break;
        }



        }

}


void sprawdz_czy_istnieje_student(int wybor3, Lista_studentow &studenci,Lista_wykladow &wyklady, Lista_zapisow &zapisy)
{
    switch(wybor3)
    {
    case 0:
        break;

    case 1:
    {
        string identyfikator;
        cout<<"Podaj indeks: ";
        cin>>identyfikator;
        cin.get();
        if( studenci.czy_istnieje_id(identyfikator) ) cout<<"TAK. Istnieje student o indeksie "<<identyfikator<<".\n\n";
        else cout<<"NIE. Nie istnieje student o indeksie "<<identyfikator<<".\n\n";
        break;
    }
    case 2:
    {
        string nazwisko;
        cout<<"Podaj nazwisko: ";
        cin>>nazwisko;
        cin.get();
        if( studenci.czy_istnieje_nazw(nazwisko) ) cout<<"TAK. Istnieje student o nazwisku "<<nazwisko<<".\n\n";
        else cout<<"NIE. Nie istnieje student o nazwisku "<<nazwisko<<".\n\n";
        break;
    }

    case 3:
    {

        string imie;
        cout<<"Podaj imie: ";
        cin>>imie;
        cin.get();
        if( studenci.czy_istnieje_imie(imie) ) cout<<"TAK. Istnieje student o imieniu "<<imie<<".\n\n";
        else cout<<"NIE. Nie istnieje student o imieniu "<<imie<<".\n\n";
        break;

    }

    }
}

void sprawdz_czy_istnieje_wyklad(int wybor3, Lista_studentow &studenci,Lista_wykladow &wyklady, Lista_zapisow &zapisy)
{
    switch(wybor3)
    {
    case 0:
        break;

    case 1:
    {
        string identyfikator;
        cout<<"Podaj identyfikator: ";
        cin>>identyfikator;
        cin.get();
        if( wyklady.czy_istnieje_id(identyfikator) ) cout<<"TAK. Istnieje wyklad o identyfikatorze "<<identyfikator<<".\n\n";
        else cout<<"NIE. Nie istnieje wyklad o identyfikatorze "<<identyfikator<<".\n\n";
        break;
    }

    case 2:
    {
        string tytul;
        cout<<"Podaj tytul: ";
        getline(cin,tytul);
        if( wyklady.czy_istnieje_tytul(tytul) ) cout<<"TAK. Istnieje wyklad o tytule "<<tytul<<".\n\n";
        else cout<<"NIE. Nie istnieje wyklad o tytule "<<tytul<<".\n\n";
        break;
    }
    case 3:
    {
        int ECTS;
        cout<<"Podaj liczbe ECTS: ";
        cin>>ECTS;
        cin.get();
        if( wyklady.czy_istnieje_ECTS(ECTS) ) cout<<"TAK. Istnieje wyklad o liczbie ECTS "<<ECTS<<".\n\n";
        else cout<<"NIE. Nie istnieje wyklad o liczbie ECTS "<<ECTS<<".\n\n";
        break;
    }

    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void edytuj(int wybor2, Lista_studentow &studenci,Lista_wykladow &wyklady, Lista_zapisow &zapisy)
{
    switch(wybor2)
    {
    case 0:
        break;
    case 1:
    {
        string identyfikator, imie;
        cout<<"Podaj identyfikator studenta, ktorego chcesz edytowac: ";
        cin>>identyfikator;
        cin.get();
        if( ! studenci.czy_istnieje_id(identyfikator))
        {
            cout<<"Nie ma studenta o identyfikatorze "<<identyfikator<<" :(\n";
            break;
        }
        cout<<"Podaj nowe imie: ";
        cin>>imie;
        cin.get();
        studenci.edytuj_imie(imie,identyfikator);
        break;
    }
    case 2:
    {
        string identyfikator, nazwisko;
        cout<<"Podaj identyfikator studenta, ktorego chcesz edytowac: ";
        cin>>identyfikator;
        cin.get();
        if( ! studenci.czy_istnieje_id(identyfikator))
        {
            cout<<"Nie ma studenta o identyfikatorze "<<identyfikator<<" :(\n";
            break;
        }
        cout<<"Podaj nowe nazwisko: ";
        cin>>nazwisko;
        cin.get();
        studenci.edytuj_nazwisko(nazwisko,identyfikator);
        break;
    }
    case 3:
    {
        string identyfikator1, identyfikator2;
        cout<<"Podaj identyfikator studenta, ktorego chcesz edytowac: ";
        cin>>identyfikator1;
        cin.get();
        if( ! studenci.czy_istnieje_id(identyfikator1))
        {
            cout<<"Nie ma studenta o identyfikatorze "<<identyfikator1<<" :(\n";
            break;
        }
        cout<<"Podaj nowt identyfikator: ";
        cin>>identyfikator2;
        cin.get();
        if(zapisy.czy_student(identyfikator1))
        {
            cout<<"Podany student jest zapisany na wyklady. Zmiana jego identyfikatora \nspowuduje automatyczna"
                "aktualizacje pliku zapisow, tak aby student pozostal na liscie\nosob zapisanych na przedmioty.\n"
                <<"Nacisnij dowolny klawisz aby kontynuowac...";
            cin.get();
            zapisy.edytuj_student_id(identyfikator1,identyfikator2);
        }
        studenci.edytuj_identyfikator(identyfikator1,identyfikator2);
        break;
    }

    case 4:
    {
        string identyfikator, tytul;
        cout<<"Podaj identyfikator wykladu, ktory chcesz edytowac: ";
        cin>>identyfikator;
        cin.get();
        if( ! wyklady.czy_istnieje_id(identyfikator))
        {
            cout<<"Nie ma wykladu o identyfikatorze "<<identyfikator<<". :(\n";
            break;
        }
        cout<<"Podaj nowy tytul: ";
        getline(cin,tytul);
        wyklady.edytuj_tytul(tytul,identyfikator);
        break;
    }


case 5:
    {
    string identyfikator;
    int ECTS;
        cout<<"Podaj identyfikator wykladu, ktory chcesz edytowac: ";
        cin>>identyfikator;
        cin.get();
        if( ! wyklady.czy_istnieje_id(identyfikator))
        {
            cout<<"Nie ma wykladu o identyfikatorze "<<identyfikator<<". :(\n";
            break;
        }
        cout<<"Podaj nowa liczbe ECTS: ";
        cin>>ECTS;
        cin.get();
        wyklady.edytuj_ECTS(ECTS,identyfikator);
        break;
    }

case 6:
    {
        string identyfikator1, identyfikator2;
        cout<<"Podaj identyfikator wykladu, ktory chcesz edytowac: ";
        cin>>identyfikator1;
        cin.get();
        if( ! wyklady.czy_istnieje_id(identyfikator1))
        {
            cout<<"Nie ma wykladu o identyfikatorze "<<identyfikator1<<". :(\n";
            break;
        }
        cout<<"Podaj nowt identyfikator: ";
        cin>>identyfikator2;
        cin.get();
        if(zapisy.czy_wyklad(identyfikator1))
        {
            cout<<"Na pdany wyklad sa zapisani studenci. Zmiana jego identyfikatora spowuduje\nautomatyczna"
                "aktualizacje pliku zapisow, tak aby studentci pozostali na liscie\nosob zapisanych na przedmiot.\n"
                <<"Nacisnij dowolny klawisz aby kontynuowac...";
            cin.get();
            zapisy.edytuj_wyklad_id(identyfikator1,identyfikator2);
        }
        wyklady.edytuj_identyfikator(identyfikator1,identyfikator2);
        break;
    }
}
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


