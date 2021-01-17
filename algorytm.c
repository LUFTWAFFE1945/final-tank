
#include "cos.h"





algorytm_ruchu(maciora*m,Dane*D,char*tok)
//if sprawdam czy jests obramowanie i wypełnione w srodku
//jeśli tak to konin
/*jeśli nie kolejny if
    {
        sprawdzam czy przedemną ściana
        jeli nie ma to move
        algorytm_ruchu
        jeśli jest to
        {
            skręcam w prawo
            explor
            if z przodu z lewej i zprzodu pusto
            {move 
             w levo
             algorytm ruchu
             if sprawdam czy bgyłeem
             jesłi tak{
                 prawo 
                 algorytm ruchu
             }
             jesli nie{
                 algorytm ruchu
             }
             }
             jęśli z przodu pusto a zlewej ściana 
                {
                    algorytm ruch
                }
             jeśli z przodu ściana
             {
                 prawo
                 algorytm ruchu
             }

         }
    }
*/ // i teraz jak to zrobić
// żęby to działało
////////////////////////////////////////////////////
info(tok,m)
sprawdż czy peła
jeśli tal -- go to full
jeśli nie -- go to empty
  

full:
printf("udało się odkryć")
//zapisuje do pliku
}

empty:
czy jest obramowanie
jeśli tak go to fence
jeśli nie go to make_fence


fence:
rotate(tok, right)
go to make_fance

make_fence:
explore(tok, m)
if (m->zwrot_lufy == N)
{
    if(m->[m->my_x+1][m->my_y]="w")
    go to obrysowywanie
    else
    {
        move(tok)
        explore(tok, m)
        go to make_fence
    }
}
if (m->zwrot_lufy == S)
{
    if(m->[m->my_x-1][m->my_y]="w")
    go to obrysowywanie
    else
    {
        move(tok)
        explore(tok, m)
        go to make_fence
    }
}
if (m->zwrot_lufy == W)
{
    if(m->[m->my_x][m->my_y-1]="w")
    go to obrysowywanie
    else
    {
        move(tok)
        explore(tok, m)
        go to make_fence
    }
}
if (m->zwrot_lufy == E)
{
    if(m->[m->my_x+1][m->my_y+1]="w")
    go to obrysowywanie
    else
    {
        move(tok)
        explore(tok, m)
        go to make_fence
    }
}
obrysowywanie:
rotate(tok;righ)
if (m->zwrot_lufy == N)
{
    if(m->[m->my_x+1][m->my_y]="w")
    go to obrysowywanie
    else
    {
       go to prosto_przy_obramowaniu
    }
}
if (m->zwrot_lufy == S)
{
    if(m->[m->my_x-1][m->my_y]="w")
    
    else
    {
       go to prosto_przy_obramowaniu
    }
}
if (m->zwrot_lufy == W)
{
    if(m->[m->my_x][m->my_y-1]="w")
   
    else
    {
        go to prosto_przy_obramowaniu
    }
}
if (m->zwrot_lufy == E)
{
    if(m->[m->my_x+1][m->my_y+1]="w")
    
    else
    {
        go to prosto_przy_obramowaniu
    }
}
prosto_przy_obramowaniu:
if (m->zwrot_lufy == N)
{
    if(m->[m->my_x+1][m->my_y-1]="w")
    go to obrysowywanie
    else
    {
       go to prosto_przy_obramowaniu
    }
}
if (m->zwrot_lufy == S)
{
    if(m->[m->my_x-1][m->my_y+1]="w")
    
    else
    {
       go to prosto_przy_obramowaniu
    }
}
if (m->zwrot_lufy == W)
{
    if(m->[m->my_x-1][m->my_y-1]="w")
   
    else
    {
        go to prosto_przy_obramowaniu
    }
}
if (m->zwrot_lufy == E)
{
    if(m->[m->my_x+1][m->my_y+1]="w")
    
    else
    {
        go to prosto_przy_obramowaniu
    }
}
