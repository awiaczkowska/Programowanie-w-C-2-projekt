#include "klasy.h"

string  Zapis::wypisz_student_id()const
{
    return identyfikator_student;
}


string  Zapis::wypisz_wyklad_id()const
{
    return identyfikator_wyklad;
}

void Zapis::zapisz(string _id_stud, string _id_wyk)
{
    identyfikator_student=_id_stud;
    identyfikator_wyklad= _id_wyk;
}


ostream &operator<<(ostream &wyjscie, const Zapis &zap)
{
        wyjscie << "Identyfikator studenta:\t" << zap.wypisz_student_id()<<endl
                << "Identyfikator wykladu:\t"  << zap.wypisz_wyklad_id()<<endl;

        return wyjscie;
}


void Zapis::edytuj_student_id(string _stud)
{
    identyfikator_student=_stud;
}

void Zapis::edytuj_wyklad_id(string _wyk)
{
    identyfikator_wyklad=_wyk;
}
