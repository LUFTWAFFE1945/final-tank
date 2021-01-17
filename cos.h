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

}Dane;
typedef struct Maciora {
    int r;
    int c;
    int **tab;
    int zwrot_lufy;
    int my_x;
    int my_y;

}maciora;
typedef struct _Memory
{
    char *response;
    size_t size;
} Memory;
// dodać to takie fajne zabezpieczenie