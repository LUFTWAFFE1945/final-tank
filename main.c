#include "cos.h"


int main()
{
    char*chunk=(char*)malloc(sizeof(char*));
    char*nazwa_pliku="macierztestowa.txt";
    struct macierz *plansza;
    struct Dane *D;
    printf("%d\n",plikIstnieje(nazwa_pliku));
    if(plikIstnieje(nazwa_pliku)==1){
        plansza = wczytaj(nazwa_pliku);
    }
    else{
        plansza = utworz();
    }
     
    algorytm_ruchu2(plansza,D,"qwerty_20");
    save_to_file(plansza,nazwa_pliku);
    smash_all(plansza,D);///JESZCZE NIE NAPISANE

}
 
    //a=wczytaj(fin);
   // algorytm( macierz_ogólne(maciora))
    //zapisz do pliku