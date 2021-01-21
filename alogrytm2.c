#include "cos.h"
//nie używać go to!!!!!!!!!!!!!!!!!

int sprawdz_wypełnione()
{

}

int sprawdz_bariere()
{

}
int can_I_go()
{

}
int check_front(maciora*m,Dane*D,char*tok)
{
    explore(tok,m);
   if(m->zwrot_lufy=="1")
   {
       if(m->tab[m->my_r-1][m->my_c-1]!=1)
       {
            if(m->tab[m->my_r-1][m->my_c+1]==1) 
            {
                return 1;
            } 
            else
            {
                return 2;
            }             
       }
       else
       {
           if(m->tab[m->my_r][m->my_c-1]==1)
           {
               return 4;
           }
           else
           {
               return 3;
           }
           
       }
       

      
   }
}
int make_fram (maciora*m,Dane*D,char*tok)
{
    /*
    przedemną nic i lp ściana -> 1
    przedemną nic i lp pusto -> 2
    przedemną ściana i lp ściana pp pusto ->3
    przedemną ściana i lp ściana pp ścian ->4


    */



}

algorytm_ruchu2(maciora*m,Dane*D,char*tok){
    if(sprawdz_wypełnione==1)//nie używać go to 
    {
        printf ("gotowe");
        zapisz(m);///chyba nie ma jeszcze tej funkcji
    }
    else
    {
        while (sprawdz_wypełnione==0) //jęli nie wypełnione
        { 
            info(tok,m);
            expolre(tok,m);
            if (can_I_go()==1)
            {
                move(tok);               
            } else {
                make_fram(m,D,tok);
                break;
            }
        }
        printf ("gotowe");
        zapisz(m);

    }
    