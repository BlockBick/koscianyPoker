#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> gracz1(5), gracz2(5);
vector<int> sortedGracz1, sortedGracz2;
vector<int> liczbyGracz1(6), liczbyGracz2(6);
int wynik1 = 0, wynik2 = 0;

void Sortuj(vector<int>& vec){
    for(int i = 0; i < vec.size() - 1; i++){
        for(int j = 0; j < vec.size() - i - 1; j++){
            if(vec[j] < vec[j + 1]){
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void Losuj(vector<int>& vec){
    for(int i = 0; i < vec.size(); i++){
        vec[i] = rand() % 6 + 1;
    }
}

void Sprawdz(vector<int>& vec1, vector<int>& vec2, int& wynik){
    int trojka = 0, para = 0, cnt = 0;
    for(int i = 0; i < vec1.size(); i++){
        vec2[vec1[i]-1]++;
    }

    for(int i = 0; i < vec2.size(); i++){
        if(vec2[i] == 1){
            cnt++;
        }
    }

    if(cnt == 5 && vec2[0] == 1 && vec2[vec1.size()] != 1){
        cout << "Maly Street" << endl;
        wynik = 4;
    }
    else if(cnt == 5 && vec2[vec1.size()] == 1 && vec2[0] != 1){
        cout << "Duzy Street" << endl;
        wynik = 5;
    }

    for(int i = 0; i < vec2.size(); i++){
        if(vec2[i] == 5){
            cout << "POKER" << endl;
            wynik = 8;
        }
        else if(vec2[i] == 4){
            cout << "Kareta" << endl;
            wynik = 7;
        }
        else if(vec2[i] == 3){
            trojka++;
        }
        else if(vec2[i] == 2){
            para++;
        }
    }
    
    if(para == 2){
        cout << "Dwie pary" << endl;
        wynik = 2;
    }
    else if(para == 1 && trojka == 1){
        cout << "Full" << endl;
        wynik = 6;
    }
    else if(trojka == 1){
        cout << "Trojka" << endl;
        wynik = 3;
    }
    else if(para == 1){
        cout << "Para" << endl;
        wynik = 1;
    }
}

void Przerzut(vector<int>& vec){
    string kosci;
    cin >> kosci;
    if(kosci != "0"){
        for(int i = 0; i < kosci.size(); i++){
            vec[kosci[i] - 49] = rand() % 6 + 1;
        }
    }
}

void Wypisz1(vector<int>& vec1, vector<int>& vec2){
    cout << "Twoje kostki:" << endl;
    for(int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << " ";
    }
    cout << endl; 
    Sprawdz(vec2, liczbyGracz1, wynik1);
}

void Wypisz2(vector<int>& vec1, vector<int>& vec2){
    cout << "Kostki przeciwnika:" << endl;
    for(int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << " ";
    }
    cout << endl; 
    Sprawdz(vec2, liczbyGracz2, wynik2);
}

void Wynik(vector<int>& vec1, vector<int>& vec2, int& wynik1, int& wynik2){
    if(wynik1 > wynik2){
        cout << "Wygrywasz" << endl;
    }
    else if(wynik1 < wynik2){
        cout << "Przegrywasz" << endl;
    }
    else if(liczbyGracz1 < liczbyGracz2){
        cout << "Wygrywasz" << endl;
    }
    else if(liczbyGracz1 > liczbyGracz2){
        cout << "Przegrywasz" << endl;
    }
    else if(sortedGracz1 > sortedGracz2){
        cout << "Wygrywasz" << endl;
    }
    else if(sortedGracz1 < sortedGracz2){
        cout << "Przegrywasz" << endl;
    }
    else cout << "REMIS NO WAY" << endl;
}

void Rzut(vector<int>& gracz1, vector<int>& gracz2, vector<int>& sortedGracz1, vector<int>& sortedGracz2, int& wynik1, int& wynik2){
    sortedGracz1 = gracz1;
    sortedGracz2 = gracz2;

    Sortuj(sortedGracz1);
    Sortuj(sortedGracz2);

    Wypisz1(gracz1, sortedGracz1);
    Wypisz2(gracz2, sortedGracz2);
}

int main()
{
    for(;;){
        srand(time(0));

        Losuj(gracz1);
        Losuj(gracz2);

        Rzut(gracz1, gracz2, sortedGracz1, sortedGracz2, wynik1, wynik2);

        for(int i = 0; i < 6; i++){
            liczbyGracz1[i] = 0;
            liczbyGracz2[i] = 0;
        }

        Przerzut(gracz1);
        Przerzut(gracz2);

        Rzut(gracz1, gracz2, sortedGracz1, sortedGracz2, wynik1, wynik2);

        Wynik(sortedGracz1, sortedGracz2, wynik1, wynik2);

        system ("pause");

        system("cls");

        for(int i = 0; i < 5; i++){
            gracz1[i] = 0;
            gracz2[i] = 0;
            sortedGracz1[i] = 0;
            sortedGracz2[i] = 0;
        }
        for(int i = 0; i < 6; i++){
            liczbyGracz1[i] = 0;
            liczbyGracz2[i] = 0;
        }
        wynik1 = 0;
        wynik2 = 0;
    }
}