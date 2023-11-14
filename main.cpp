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
#include<conio.h>
#define ROZMIAR 10

int deklaracajRozmiar();
float *wpisywanie();
void wypisywanie(float tab[]);
void sprawdzanieElementow(float tab[]);
float *losowanie();
void sortowanie(float tab[]);
void zadanie4();

int main(){
    bool petla = true, petla_wyboru = true;
    int wybor_1, wybor_2;
    float *Tab;

    while(petla_wyboru){
        system("cls");
        printf("Wprowadz dane recznie, program wylosuje je za ciebie lub wybierz zadanie 4(dla ambitnych)"
               "\n1 - Wprowadz dane recznie\n2 - Losowe dane\n3 - zadanie 4\nWybor: ");
        scanf("%d", &wybor_1);
        switch(wybor_1){
            case 1:
                system("cls");
                Tab = wpisywanie();
                petla_wyboru = false;
                break;
            case 2:
                system("cls");
                Tab = losowanie();
                petla_wyboru = false;
                break;
            case 3:
                system("cls");
                zadanie4();
                break;
            default:
                system("cls");
                printf("Niepoprawne dane\n\n");
                system("pause");
                break;
        }
    }

    while(petla){
        system("cls");
        printf("Autor: Grzegorz Wszoła\n\n");
        printf("Ktore zadanie chcesz wybrac\n");
        printf("Aktualna tablica: ");wypisywanie(Tab);
        printf("1 - Wprowadzanie danych do tablicy\n2 - Wypisywanie wprowadzonych danych\n3 - "
               "Sprawdz dane tablicy\n4 - Uzupelnienie tablicy losowymi danymi\n5 - Sortowanie tabeli\n6 - Zakoncz\nWybierz liczbe: ");
        scanf("%d", &wybor_2);
        printf("\n\n");
        switch(wybor_2){
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
                Tab = losowanie();
                break;
            case 5:
                sortowanie(Tab);
                break;
            case 6:
                system("cls");
                printf("Dziekuje!\n\n");
                system("pause");
                petla = false;
                break;
            default:
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
    system("pause");
    return tab;
}

void sortowanie(float tab[]){
    for(int i = 1;i < ROZMIAR; i++) {
        int j = i;
        while(j > 0 && tab[j] < tab[j-1]) {
            int temp = tab[j];
            tab[j] = tab[j-1];
            tab[j-1] = temp;
            j--;
        }
    }
    printf("Posortowanie tabela Tab = [");
    for(int i = 0; i < ROZMIAR; i++){
        printf(" %.1f ", tab[i]);
    }
    printf("]\n\n");
    system("pause");
}

void zadanie4(){
    int tab[26], ile_znakow;
    char znak;

    printf("Podaj ciag znakow(zakoncz klikajac ESC): ");
    while(znak != 27){
        znak = getch();
        if ((znak >= 65 && znak <= 90) || (znak >= 97 && znak <= 122)){
            printf("%c", znak);
        }
        if(znak >= 97 && znak <= 122){
            znak -= 32;
        }
        if (znak>=65 && znak <=90){
            tab[znak-65]++;
            ile_znakow++;
        }
    }
    for(int i = 0; i <= 25; i++){
        printf("\nlitera %c ", i + 65);
        for(int j = 0; j < tab[i]; j++){
            printf("#");
        }
    }

    printf("\n\n");
    system("pause");
}