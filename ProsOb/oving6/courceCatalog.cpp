#include "courceCatalog.h"

void CourseCatalog::addCourse(){ //legg til et kurs med emnekode og emnenavn.
    string emnekode = "";
    string emnenavn = "";
    cout << "legg til kurs" << endl;
    cout << "Emnekode: " << endl;
    cin >> emnekode;
    cout << "Emnenavn: " << endl;
    cin >> emnenavn;
    fag.insert({emnenavn,emnekode});
} 

void CourseCatalog::removeCourse(){ //fjern et kurs gitt av emnekoden.
    string fjerne = "";
    cout << "skriv inn kursjet du vil fjerne: " << endl;
    cin >> fjerne;
    fag.erase(fjerne);
} 

string CourseCatalog::getCource(){ //finn emnenavnet til et kurs med en gitt emnekode
    string emnenavn;
    cout << "skriv inn emnekode for å finne det tilhørende emnenavnet: ";
    cin >> emnenavn;
    return(static_cast<string>(fag.at(emnenavn)));
    cout << static_cast<string>(fag.at(emnenavn)) << endl;
}
ostream& operator<<(ostream& ostr, const CourseCatalog& cC){
    ostr << "Emnekode; " << f.first << " Name: " << fag.second << endl; 
    return os;
}

void addThree(){
    courceCatalog::fag.insert({"TDT4110", "Informasjonsteknologi grunnkurs"})
    courceCatalog::fag.insert({"TDT4102", "Prosedyre- og objektorientert programering"})
    courceCatalog::fag.insert({"TMA4100", "Matematikk 1"})
}

void CourseCatalog::toFile(){
    ofstream outFile {"fagBibliotek.txt"};
    for(auto& elem : fag){
        outFile << "Emnekode; " << fag.first << " Name: " << fag.second << endl;
    }
}