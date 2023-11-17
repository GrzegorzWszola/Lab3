/*
Autor: Grzegorz Wszoła
Grupa: Czw/P 17:05
Temat: Lab 2
Data: 01 Grudzien 2023r
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define ROZMIAR 10

float *wpisywanie();
void wypisywanie(float tab[]);
void sprawdzanieElementow(float tab[]);
float *losowanie();
void sortowanie(float tab[]);
void zadanie4();

int main(){
    bool petla = true;
    int wybor, pozycja = 0;
    float *Tab;
    Tab = wpisywanie();
    printf("Poruszaj sie \'w\' - w gore, \'s\' - w dol, zatwierdz naciskajac \'e\'\n\n");
    printf("==> Wpisywanie danych do tablicy\n    Wypisywanie danych z tablicy\n    Sprawdzanie elementow tablicy\n    Losowanie elementow tablicyn\n"
           "    Sortowanie elementow tablicy\n\n    Zadanie 4(dla ambitnych)\n\n    Zakoncz");
    while(petla){
        wybor = getch();
        switch(wybor){
            case 'w':
                pozycja--;
                break;
            case 's':
                pozycja++;
                break;
        }
        //nie pozwala wyjsc poza ilosc wyborow
        if(pozycja > 6){
            pozycja = 6;
        } else if(pozycja < 0){
            pozycja = 0;
        }

        switch(pozycja){
            case 0:
                system("cls");
                printf("Poruszaj sie \'w\' - w gore, \'s\' - w dol, zatwierdz naciskajac \'e\'\n\n");
                printf("==> Wpisywanie danych do tablicy\n    Wypisywanie danych z tablicy\n    Sprawdzanie elementow tablicy\n    Losowanie elementow tablicyn\n"
                       "    Sortowanie elementow tablicy\n\n    Zadanie 4(dla ambitnych)\n\n    Zakoncz");
                break;
            case 1:
                system("cls");
                printf("Poruszaj sie \'w\' - w gore, \'s\' - w dol, zatwierdz naciskajac \'e\'\n\n");
                printf("    Wpisywanie danych do tablicy\n==> Wypisywanie danych z tablicy\n    Sprawdzanie elementow tablicy\n    Losowanie elementow tablicyn\n"
                       "    Sortowanie elementow tablicy\n\n    Zadanie 4(dla ambitnych)\n\n    Zakoncz");
                break;
            case 2:
                system("cls");
                printf("Poruszaj sie \'w\' - w gore, \'s\' - w dol, zatwierdz naciskajac \'e\'\n\n");
                printf("    Wpisywanie danych do tablicy\n    Wypisywanie danych z tablicy\n==> Sprawdzanie elementow tablicy\n    Losowanie elementow tablicyn\n"
                       "    Sortowanie elementow tablicy\n\n    Zadanie 4(dla ambitnych)\n\n    Zakoncz");
                break;
            case 3:
                system("cls");
                printf("Poruszaj sie \'w\' - w gore, \'s\' - w dol, zatwierdz naciskajac \'e\'\n\n");
                printf("    Wpisywanie danych do tablicy\n    Wypisywanie danych z tablicy\n    Sprawdzanie elementow tablicy\n==> Losowanie elementow tablicyn\n"
                       "    Sortowanie elementow tablicy\n\n    Zadanie 4(dla ambitnych)\n\n    Zakoncz");
                break;
            case 4:
                system("cls");
                printf("Poruszaj sie \'w\' - w gore, \'s\' - w dol, zatwierdz naciskajac \'e\'\n\n");
                printf("    Wpisywanie danych do tablicy\n    Wypisywanie danych z tablicy\n    Sprawdzanie elementow tablicy\n    Losowanie elementow tablicyn\n"
                       "==> Sortowanie elementow tablicy\n\n    Zadanie 4(dla ambitnych)\n\n    Zakoncz");
                break;
            case 5:
                system("cls");
                printf("Poruszaj sie \'w\' - w gore, \'s\' - w dol, zatwierdz naciskajac \'e\'\n\n");
                printf("    Wpisywanie danych do tablicy\n    Wypisywanie danych z tablicy\n    Sprawdzanie elementow tablicy\n    Losowanie elementow tablicyn\n"
                       "    Sortowanie elementow tablicy\n\n==> Zadanie 4(dla ambitnych)\n\n    Zakoncz");
                break;
            case 6:
                system("cls");
                printf("Poruszaj sie \'w\' - w gore, \'s\' - w dol, zatwierdz naciskajac \'e\'\n\n");
                printf("    Wpisywanie danych do tablicy\n    Wypisywanie danych z tablicy\n    Sprawdzanie elementow tablicy\n    Losowanie elementow tablicyn\n"
                       "    Sortowanie elementow tablicy\n\n    Zadanie 4(dla ambitnych)\n\n==> Zakoncz");
                break;
        }

        if(pozycja == 0 && wybor == 101){
            system("cls");
            Tab = wpisywanie();
        } else if(pozycja == 1 && wybor == 101){
            system("cls");
            wypisywanie(Tab);
        } else if(pozycja == 2 && wybor == 101){
            system("cls");
            sprawdzanieElementow(Tab);
        } else if(pozycja == 3 && wybor == 101){
            system("cls");
            Tab = losowanie();
        } else if(pozycja == 4 && wybor == 101){
            system("cls");
            sortowanie(Tab);
        } else if(pozycja == 5 && wybor == 101){
            system("cls");
            zadanie4();
        } else if(pozycja == 6 && wybor == 101){
            petla = false;
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

    //wypisywanie danych z tablicy
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
}

void sprawdzanieCiaglosci(float tab[]){

}

float *losowanie(){
    static float tab[ROZMIAR];
    float min, max;
    srand(time(NULL));
    printf("Funkcja wprowadza losowe dane do tablicy\n");
    printf("Podaj zakres liczb losowych\nOd: ");
    scanf("%f", &min);
    printf("Do: "); scanf("%f", &max);

    for(int i = 0; i < ROZMIAR; i++){
        tab[i] = min + (max - min)*rand()/((double)RAND_MAX);
    }
    printf("Wylosowana tabela Tab = [");

    for(int i = 0; i < ROZMIAR; i++){
        printf("% .1f ", tab[i]);
    }
    printf("]\n\n");
    return tab;
}

void sortowanie(float tab[]){
    //algorytm sortowania insert sort
    for(int i = 1;i < ROZMIAR; i++) {
        int j = i;
        while(j > 0 && tab[j] < tab[j-1]) {
            int temp = tab[j];
            tab[j] = tab[j-1];
            tab[j-1] = temp;
            j--;
        }
    }
    printf("Posortowana tabela Tab = [");
    for(int i = 0; i < ROZMIAR; i++){
        printf(" %.1f ", tab[i]);
    }
    printf("]\n\n");
}

void zadanie4(){
    int tab[26], ile_znakow;
    char znak;

    //zerowanie elemntow tablicy
    for(int i = 0; i <=26; i++)
        tab[i] = 0;

    //wczytywanie ciagu liczb i zliczanie
    printf("Podaj ciag znakow(zakoncz klikajac ESC)\n");
    Sleep(100);
    printf(": ");
    while(znak != 27){
        znak = getch();
        printf("%c", znak);
        if(znak >= 97 && znak <= 122){
            znak -= 32;
        }
        if (znak>=65 && znak <=90){
            tab[znak-65]++;
        }
    }

    //wypisywanie danych i tworzenie tabeli
    printf("l\n");
    for(int i = 0; i <= 25; i++){
        ile_znakow = 0;
        for(int j = 0; j < tab[i]; j++){
            ile_znakow++;
        }
        printf("\n litera %c %3d %2c", i + 65, ile_znakow, ' ');
        for(int j = 0; j < tab[i]; j++){
            printf("#");
        }
    }
    printf("\n\n");

}
