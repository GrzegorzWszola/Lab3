/*
Autor: Grzegorz Wszoła
Grupa: Czw/P 17:05
Temat: Lab 2
Data: 21 pazdziernika 2023r
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define ROZMIAR 5

float *wpisywanie();
void wypisywanie(float tab[]);
void sprawdzanieElementow(float tab[]);
void zad4();
//comment
int main(){
    bool petla = true;
    int wybor;
    float *Tab;
    Tab = wpisywanie();
    while(petla){
        system("cls");
        printf("Autor: Grzegorz Wszoła\n\n");
        printf("Ktore zadanie chcesz wybrac\n");
        printf("Aktualna tablica: ");wypisywanie(Tab);
        printf("1 - Wprowadzanie danych do tablicy\n2 - Wypisywanie wprowadzonych danych\n3 - "
               "Sprawdz dane tablicy\n4 - \n5 - Zakoncz\nWybierz liczbe: ");
        scanf("%d", &wybor);
        printf("\n\n");
        switch(wybor){
            case 1:
                Tab = wpisywanie();
                system("pause");
                break;
            case 2:
                wypisywanie(Tab);
                system("pause");
                break;
            case 3:
                sprawdzanieElementow(Tab);
                break;
            case 4:

                break;
            case 5:
                system("cls");
                printf("Dziekuje!\n\n");
                system("pause");
                petla = false;
                break;
            default:
                printf("%c", wybor);
                system("cls");
                printf("Niepoprawny numer\n");
                system("pause");
        }
    }
    return 0;
}

float *wpisywanie(){
    //wczytywanie elementow tablicy
    printf("Wprowadz dane do tablicy\n");
    static float tab[ROZMIAR];
    for(int i = 0; i < ROZMIAR; i++){
        printf("Tab[ %d ] =  ", i);
        scanf("%f", &tab[i]);
    }
    printf("Tablica to Tab = [ ");
    for(int i = 0; i < ROZMIAR; i++){
        printf(" %.1f ", tab[i]);
    }
    printf(" ]\n\n");
    return tab;
}

void wypisywanie(float tab[]){
    //wypisywanie elementow tablicy
    printf("Tab = [");
    for(int i = 0; i < ROZMIAR; i++){
        printf(" %.1f ", tab[i]);
    }
    printf("]\n\n");
}

void sprawdzanieElementow(float tab[]){
    //sprawdzanie ilosci liczb
    int ile_dodatnich = 0, ile_ujemnych = 0;
    float suma_dod = 0, suma_uj = 0, sr_dod = 0, sr_uj = 0;
    for(int i = 0; i < ROZMIAR; i++){
        if(tab[i] > 0){
            ile_dodatnich++;
            suma_dod += tab[i];
        } else if(tab[i] == 0){
            continue;
        } else {
            ile_ujemnych++;
            suma_uj += tab[i];
        }
    }


    printf("Ilosc dodatnich: %d\nIlosc ujemnych: %d\nSuma dodatnich: %.1f\nSuma ujemnych: %.1f\n",
           ile_dodatnich, ile_ujemnych, suma_dod, suma_uj);
    if(ile_dodatnich != 0){
        sr_dod = suma_dod/ile_dodatnich;
        printf("Srednia dodatnich: %.1f\n", sr_dod);
    } else {
        printf("Srednia dodatnich: 0\n");
    }
    if(ile_ujemnych != 0){
        sr_uj = suma_uj/ile_ujemnych;
        printf("Srednia ujemnych: %.1f\n\n", sr_uj);
    } else {
        printf("Srednia ujemnych: 0\n\n");
    }
    system("pause");
}

void sprawdzanieCiaglosci(float tab[]){

}

void zad1(float tab[]){

    bool rosnacy = false, niemalejacy = false, staly = false, nierosnacy = false, malejacy = false;
    for(int i = 0; i < ROZMIAR; i++) {
        for(int j = 1; j < ROZMIAR; j++){
            if(tab[i] == tab[j]){
                staly = true;
            }
        }

    }
    if(staly){
        printf("jednakowy");
    } else  if(rosnacy) {
        printf("rosnacy");
    } else if(malejacy){
        printf("malejacy");
    } else {
        printf("spierdalaj");
    }


    printf("\n\n");
    system("pause");
}