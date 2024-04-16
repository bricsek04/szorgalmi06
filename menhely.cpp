#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct Allat{
    string fajta;
    string nev;
    int kor;
    string szin;
};

int main(){
    ifstream file("menhely.txt");
    vector<Allat> menhely;

    if (file.is_open()) {
        string line;
        getline(file, line);

        while (getline(file, line)) {
            istringstream iss(line);
            Allat elem;
            string korStr;

            if (getline(iss, elem.fajta, ',') && getline(iss, elem.nev, ',') &&
                getline(iss, korStr, ',') && getline(iss, elem.szin)) {
                elem.fajta.erase(0, elem.fajta.find_first_not_of(' '));
                elem.fajta.erase(elem.fajta.find_last_not_of(' ') + 1);
                elem.nev.erase(0, elem.nev.find_first_not_of(' '));
                elem.nev.erase(elem.nev.find_last_not_of(' ') + 1);
                korStr.erase(0, korStr.find_first_not_of(' '));
                korStr.erase(korStr.find_last_not_of(' ') + 1);
                elem.szin.erase(0, elem.szin.find_first_not_of(' '));
                elem.szin.erase(elem.szin.find_last_not_of(' ') + 1);

                elem.kor = stoi(korStr);
                menhely.push_back(elem);
            } else {
                cerr << "Hibás formátum a fájlban!\n";
                return 1;
            }
        }
    }
    /*for(Allat allat:menhely){
        cout << allat.nev << " " << allat.kor << " " << allat.fajta << " " << allat.szin << endl;
    }*/
    bool szeretne = true;
    do
    {
        cout << "Milyen attribútum alapján szeretne keresni? (fajta (F), név (N), kor (K), szín (SZ))" << endl;
        string attributum;
        cin >> attributum;
        bool hibas = false;
        string fajta, nev, kor, szin;
        if (attributum == "F")
        {
            cout << "Adja meg a fajtát: " << endl;
            cin >> fajta;
        }
        else if(attributum == "N"){
            cout << "Adja meg a nevet: " << endl;
            cin >> nev;
        }
        else if(attributum == "K"){
            cout << "Adja meg a kort: " << endl;
            cin >> kor;
        }
        else if(attributum == "SZ"){
            cout << "Adja meg a színt: " << endl;
            cin >> szin;
        }
        else {cout << "Hibás attribútumot adott meg!" << endl; hibas = true;}
        if(!hibas){
            bool van = false;
            for(Allat allat:menhely){
            if(allat.fajta == fajta){
                cout << allat.nev << " " << allat.kor << " " << allat.fajta << " " << allat.szin << endl;
                van = true;
            }else if(allat.nev == nev){
                cout << allat.nev << " " << allat.kor << " " << allat.fajta << " " << allat.szin << endl; 
                van = true;
            }else if(to_string(allat.kor) == kor){
                cout << allat.nev << " " << allat.kor << " " << allat.fajta << " " << allat.szin << endl;
                van = true;
            }
            else if(allat.szin == szin){
                cout << allat.nev << " " << allat.kor << " " << allat.fajta << " " << allat.szin << endl;
                van = true;
            }
            }
            if (!van){
            cout << "Nincs ilyen állat a menhelyen." << endl;}
        }

        string keresfolyt;
        bool jo = false;
        while (!jo)
        {
            cout << "Szeretné folytatni a keresést? (Igen/Nem)" << endl;
            cin >> keresfolyt;
            if (keresfolyt == "Nem")
            {
                jo = true;
                szeretne = false;
            }else if(keresfolyt == "Igen"){
                jo = true;
            }else {cout << "Hibás attribútumot adott meg!" << endl;}
            
        }
        

        
    } while (szeretne);
    





}