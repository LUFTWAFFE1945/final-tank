#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../cJSON/cJSON.h"

int moj_globalny_int;
char moj_globalny_char;  //h

typedef struct dane{
    int x[3]; 
    int y[3];
    char* field[3]; 
    char kierunek_lufy;
    int website_x;
    int website_y;
    int ile_min_y;
    int ile_min_x;


}Dane;
/*
Dane *d;
wykonuje operacje -> otrzymuje jeden element
d[0].x[0]
d[0].x[1]
d[0].x[2]
d[0].y[0]
d[0].y[1]
d[0].y[2]
d[0].field[0]
d[0].field[1]
d[0].field[2]
char kierunek_lufy;
    int website_x;
    int website_y;
    int ile_min_y;
    int ile_min_x;
*/

typedef struct Maciora {
    int r;
    int c;
    int **tab; // ŚCIANA- 1  TRAWA-2  PIACH-3[r][c]
    int **tab2;  //mapa gdzie byłem czołgiem jeżeli zero to nie byłem jeżeli 1 to byłem
    int zwrot_lufy; // S-1,W-2,N-3,E-4
    int my_r;
    int my_c;

}maciora;
typedef struct _Memory
{
    char *response;
    size_t size;
} Memory;
typedef struct _Memory
{
    char *response;
    size_t size;
} Memory;
// dodać to takie fajne zabezpieczenie
char* info(char *token, maciora*p);
char* explore(char *token, maciora*p);
char* move(char *token);
char* rotate(char *token, char *direction);
