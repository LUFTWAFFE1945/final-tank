#include "cos.h"
//nie używać go to!!!!!!!!!!!!!!!!!

int sprawdz_wypełnione(maciora*m)
{
    /* zwracam 0 jak nie ma
       zwracam 1 jak  ma
    */
    int j,i;
    i = 0;
    j = 0;
    for (i; i<m->r; i++)
    {
        for (j; j<m->c; j++)
        {
            if (m->tab[i][j]==0)
            return 0;
        }
    }
    return 1;
}

int check_border(maciora*m)
{
    /* zwracam 0 jak nie ma
       zwracam 1 jak  ma
    */
    for( int i=0; i<m->my_c; i++)
    {
        if(m->tab[0][i]!=1)
            return 0;
        if(m->tab[m->r][i]!=1)
            return 0;
    }
    for( int i=0; i<m->r; i++)
    {
        if(m->tab[i][0]!=1)
            return 0;
        if(m->tab[i][m->c]!=1)
            return 0;
    }
    return 1;
}
/*
s-1
w-2
n-3
e-4
*/
int can_I_go(maciora*m)
{
    if(m->zwrot_lufy=="1")
    {
        if(m->tab[m->my_r-1][m->my_c]==1)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy=="2")
    {
        if(m->tab[m->my_r][m->my_c-1]==1)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy=="3")
    {
        if(m->tab[m->my_r+1][m->my_c]==1)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy=="4")
    {
        if(m->tab[m->my_r][m->my_c+1]==1)
            return 0;
        else
            return 1;   
    }

}
int check_front(maciora*m,Dane*D)
{
   if(m->zwrot_lufy=="1")
   {
       if(m->tab[m->my_r-1][m->my_c-1]!=1)
       {
            if(m->tab[m->my_r-1][m->my_c+1]==1) 
                return 1;
            else
                return 2;           
       }
       else
       {
           if(m->tab[m->my_r][m->my_c-1]==1)
               return 4;
           else
               return 3;   
       }
   }
   if(m->zwrot_lufy=="2")
   {
       if(m->tab[m->my_r][m->my_c-1]!=1)
       {
            if(m->tab[m->my_r-1][m->my_c-1]==1) 
                return 1;
            else
                return 2;           
       }
       else
       {
           if(m->tab[m->my_r+1][m->my_c]==1)
               return 4;
           else
               return 3;   
       }
   }
   if(m->zwrot_lufy=="3")
   {
        if(m->tab[m->my_r+1][m->my_c]!=1)
       {
            if(m->tab[m->my_r+1][m->my_c-1]==1) 
                return 1;
            else
                return 2;           
       }
       else
       {
           if(m->tab[m->my_r][m->my_c+1]==1)
               return 4;
           else
               return 3;   
       }
   }
   if(m->zwrot_lufy=="4")
   {
       if(m->tab[m->my_r][m->my_c+1]!=1)
       {
            if(m->tab[m->my_r+1][m->my_c+1]==1) 
                return 1;
            else
                return 2;           
       }
       else
       {
           if(m->tab[m->my_r-1][m->my_c]==1)
               return 4;
           else
               return 3;   
       }
   }
}
    /*
    make_fram i check_front
    przedemną nic i lp ściana -> 1
    przedemną nic i lp pusto -> 2
    przedemną ściana i lp ściana p pusto ->3
    przedemną ściana i lp ściana p ścian ->4
    */
int go_aroud (maciora*m,Dane*D,char*tok)
{

    if (check_front(m,D)==1)
    {
        move(tok);
    }
    if (check_front(m,D)==2)
    {
        move(tok);
        rotate(tok,"left");
    }
    if (check_front(m,D)==3)
    {
        rotate(tok,"right");
        move(tok);
    }
    if (check_front(m,D)==4)
    {
        rotate(tok,"right");
        rotate(tok,"right");
    }


}
int have_you_been_here(maciora*m)
{
    if(m->zwrot_lufy=="1")
    {
        if(m->tab2[m->my_r-1][m->my_c-1]==0)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy=="2")
    {
        if(m->tab2[m->my_r][m->my_c-1]==0)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy=="3")
    {
        if(m->tab2[m->my_r+1][m->my_c]==0)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy=="4")
    {
        if(m->tab2[m->my_r][m->my_c+1]==0)
            return 0;
        else
            return 1;   
    }

}
make_fram(maciora*m,Dane*D,char*tok)
{
    rotate(tok,"right");
    info(tok,m);
    
    while(have_you_been_here(m)!=1)
    {
        expolre(tok,m);
        go_aroud (m,D,tok);
    }
     rotate(tok,"right");
}

algorytm_ruchu2(maciora*m,Dane*D,char*tok)
{
    while (check_border!=1)  //zwraca 1 jęśli mamy graniec świata
    { 
        info(tok,m);
        expolre(tok,m);
        while (sprawdz_wypełnione==0) //jęli nie wypełnione
        { 
            if (can_I_go(m)==1)
            {
                if(have_you_been_here == 0)
                move(tok);
                else
                {
                    rotate(tok,"right");
                }
                             
            } else {
                make_fram(m,D,tok);
            }
        }

    }
    printf ("gotowe");
}
  