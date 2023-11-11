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
void zad3();
void zad4();

int main(){
    bool petla = true;
    int wybor;
    float *Tab;
    while(petla){
        system("cls");
        printf("Autor: Grzegorz Wszoła\n\n");
        Tab = wpisywanie();
        printf("Ktore zadanie chcesz wybrac\n");
        printf("1 - Wprowadzanie danych do tablicy\n2 - wypisywanie wprowadzonych danych\n3 - \n4 - \n5 - Zakoncz\nWybierz liczbe: ");
        scanf("%d", &wybor);
        switch(wybor){
            case 1:
                break;
            case 2:
                //wypisywanie(Tab);
                break;
            case 3:

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
    float tab[ROZMIAR];
    for(int i = 0; i < ROZMIAR; i++){
        printf("Podaj %d element tablicy: ", i+1);
        scanf("%f", &tab[i]);
    }
    return tab;
}

void wypisywanie(float tab[]){
    //wypisywanie elementow tablicy
    printf("Tab = [");
    for(int i = 0; i < ROZMIAR; i++){
        printf(" %.1f ", tab[i]);
    }
    printf("]\n\n");
    system("pause");
}

void zad1(float tab[]){

    /*


    //sprawdzanie ilosci liczb
    int ile_dodatnich = 0, ile_ujemnych = 0;
    float suma_dod = 0, suma_uj = 0, sr_dod = 0, sr_uj = 0;
    for(int i = 0; i < ROZMIAR; i++){
        if(tab[i] > 0){
            ile_dodatnich++;
            suma_dod += tab[i];
        } else {
            ile_ujemnych++;
            suma_uj += tab[i];
        }
    }
    sr_dod = suma_dod/ile_dodatnich;
    sr_uj = suma_uj/ile_ujemnych;

    printf("Ilosc dodatnich: %d\nIlosc ujemnych: %d\nSuma dodatnich: %.1f\nSuma ujemnych: %.1f\nSrednia"
           " dodatnich: %.1f\nSrednia ujemnych: %.1f\n\n", ile_dodatnich, ile_ujemnych, suma_dod, suma_uj, sr_dod, sr_uj);
    system("pause");*/

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