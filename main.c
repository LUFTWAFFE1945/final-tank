#include "cos.h"

maciora*utworz(){
    maciora*m =(maciora*) malloc(sizeof(maciora));
    m->r=1;
    m->c=1;
    m->tab = (int**) calloc(m->r, sizeof(int*));
    for (int i=0;i<m->r;i++)
    m->tab[i] = (int*) calloc(m->c, sizeof(int)); 
    m->tab[0][0]=0;
    return m;
}

int plikIstnieje (char* nazwa){
    FILE* plik;
    plik = fopen(nazwa, "r");  
    if (plik)
    {
        fclose(plik);
        return 1;
    }
    return 0;
}
maciora*wczytaj(char*nazwa){
    FILE* plik;
    maciora*m =(maciora*) malloc(sizeof(maciora));
    plik = fopen(nazwa, "r");  
    fscanf(plik, "%d", &m->r);
    fscanf(plik, "%d", &m->c);
    m->tab = (int**) calloc(m->r, sizeof(int*));
    for (int i=0;i<m->r;i++)
    m->tab[i] = (int*) calloc(m->c, sizeof(int)); 
    // wczytanie
    for (int i=(m->r)-1; i >=0; i--) 
    {
        for (int j=0; j < m->c; j++) 
        {
            fscanf(plik, "%d", &m->tab[i][j]);
        }
    }
    fclose(plik);
    return m;
}
int main()
{
    char*chunk=(char*)malloc(sizeof(char*));
    char*nazwa_pliku="macierztestowa.txt";
    struct macierz *plansza;
    printf("%d\n",plikIstnieje(nazwa_pliku));
    if(plikIstnieje(nazwa_pliku)==1){
        plansza = wczytaj(nazwa_pliku);
    }
    else{
        plansza = utworz();
    }



}
 
    //a=wczytaj(fin);
   // algorytm( macierz_ogólne(maciora))
    //zapisz do pliku