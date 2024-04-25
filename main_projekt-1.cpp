#ifndef klasy_h
#define klasy_h
#include "funkcje_main.h"
using namespace std;

int main()
{
    cout << "***************PROGRAM ZARZADZAJACY ZAJECIAMI***************\n\n\n";
    Lista_studentow studenci;
    Lista_wykladow wyklady;
    Lista_zapisow zapisy;
    int wybor, wybor2;//, wybor3;
    while(true)
    {
        cout << "\nWybierz jedna z opcji:" << endl << endl;
        cout << "1. Dodaj / Zapisz..." << endl;
        cout << "2. Usun..." << endl;
        cout << "3. Wypisz..." << endl;
        cout << "4. Sprawdz czy... " << endl;
        cout << "5. Edytuj..."<<endl;
        cout << "0. OPUSC PROGRAM" << endl << endl;
        cout<< "Twoj wybor: ";
        cin >> wybor;
        cin.get();
        cout<<endl;
        switch( wybor )
        {
        case 1:
        {
            cout<<"\t1. Dodaj studenta do listy studentow\n"
                <<"\t2. Dodaj wyklad do listy wykladow\n"
                <<"\t3. Zapisz studenta na wyklad\n"
                <<"\t0. WROC DO MENU GLOWNEGO\n";
            cout<< "\n\tTwoj wybor: ";
            cin>>wybor2;
            cin.get();
            cout<<endl<<endl;
            dodaj_zapisz(wybor2, studenci, wyklady, zapisy);
            break;
        }

        case 4:
        {
            cout<<"\t1. Sprawdz czy istnieje student...\n"
                <<"\t2. Sprawdz czy istnieje wyklad... \n"
                <<"\t3. Sprawdz czy student jest zapisaany na wyklad\n"
                <<"\t0. WROC DO MENU GLOWNEGO\n";
            cout<< "\n\tTwoj wybor: ";
            cin>>wybor2;
            cin.get();
            cout<<endl<<endl;
            sprawdz_czy(wybor2, studenci, wyklady, zapisy);
            break;
        }


        case 3:
        {
            cout<<"\t1. Wypisz liste studentow\n"
                <<"\t2. Wypisz liste wykladow\n"
                <<"\t3. Wypisz liste zapisow\n"
                <<"\t4. Wypisz studentow zapisanych na wyklad\n"
                <<"\t5. Wypisz wyklady studenta\n"
                <<"\t6. Wypisz studenta o podanym...\n"
                <<"\t7. Wypisz wyklad o podanym... \n"
                <<"\t0. WROC DO MENU GLOWNEGO\n";
            cout<< "\n\tTwoj wybor: ";
            cin>>wybor2;
            cin.get();
            cout<<endl<<endl;
            wypisz(wybor2, studenci, wyklady, zapisy);
            break;
        }

        case 2:
        {
            cout<<"\t1. Usun jednego studena\n"
                <<"\t2. Usun jeden wyklad\n"
                <<"\t3. Usun jeden zapis\n"
                <<"\t4. Usun wszystkie...\n"
                <<"\t0. WROC DO MENU GLOWNEGO\n";
            cout<< "\n\tTwoj wybor: ";
            cin>>wybor2;
            cin.get();
            cout<<endl<<endl;

            usun(wybor2, studenci, wyklady, zapisy);
            break;
        }


        case 5:
         {
            cout<<"\t1. Edytuj imie studenta\n"
                <<"\t2. Edytuj nazwisko studenta\n"
                <<"\t3. Edytuj indeks studenta\n"
                <<"\t4. Edytuj tytul wykladu\n"
                <<"\t5. Edytuj punkty ECTS wykladu\n"
                <<"\t6. Edytuj identyfikator wykladu\n"

                <<"\t0. WROC DO MENU GLOWNEGO\n";
            cout<< "\n\tTwoj wybor: ";
            cin>>wybor2;
            cin.get();
            cout<<endl<<endl;
            edytuj(wybor2, studenci, wyklady, zapisy);
            break;
        }

        case 0:
        {
            cout << "\t\t Dziekujemy za skorzystanie z programu!" << endl;
            return 0;
        }

        }//koniec switch
    }//koniec while

    return 0;
}

#endif // klasy_h

