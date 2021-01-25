#include "cos.h"
//nie używać go to!!!!!!!!!!!!!!!!!

int sprawdz_wypelnione(maciora*m)
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
    
    if(m->zwrot_lufy==1)
    {
        printf("blablablablalba\n");
        if(m->tab[m->my_r-1][m->my_c]==1)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy==2)
    {
        if(m->tab[m->my_r][m->my_c-1]==1)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy==3)
    {
        printf("wchodze\n");
        if(m->tab[m->my_r+1][m->my_c]==1){
        printf("nie moge jechać\n"); 
        return 0;
        }
            
        else{
        printf("mogę jechać bo nie ma przede mną ściany\n");
        return 1;  
    }
    }
    if(m->zwrot_lufy==4)
    {
        printf("wchodze\n");
        if(m->tab[m->my_r][m->my_c+1]==1){
                    printf("nie moge jechać\n"); 
        return 0;
        }
        
            
        else{
        printf("mogę jechać bo nie ma przede mną ściany\n");
        return 1;  
        }
 
    }

}
int check_front(maciora*m,Dane*D)
{
   if(m->zwrot_lufy==1)
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
   if(m->zwrot_lufy==2)
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
   if(m->zwrot_lufy==3)
   {
        if(m->tab[m->my_r+1][m->my_c]!=1)
       {
            if(m->tab[m->my_r+1][m->my_c-1]==1) 
                return 1;
            else
                return 2;           
       }
       else//jęśli jest ściana przed
       {
           if(m->tab[m->my_r][m->my_c+1]==1)
               return 4;
           else
               return 3;   
       }
   }
   if(m->zwrot_lufy==4)
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
        explore(tok,m,D);
    }
    if (check_front(m,D)==2)
    {
        move(tok);
        rotate(tok,"left");
        explore(tok,m,D);
    }
    if (check_front(m,D)==3)
    {
        rotate(tok,"right");
        move(tok);
        explore(tok,m,D);
    }
    if (check_front(m,D)==4)
    {
        rotate(tok,"right");
        rotate(tok,"right");
        move(tok);
        rotate(tok,"right");

        

    }


}
int have_you_been_here(maciora*m)
{
    if(m->zwrot_lufy==1)
    {
        if(m->tab2[m->my_r-1][m->my_c-1]==0)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy==2)
    {
        if(m->tab2[m->my_r][m->my_c-1]==0)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy==3)
    {
        if(m->tab2[m->my_r+1][m->my_c]==0)
            return 0;
        else
            return 1;   
    }
    if(m->zwrot_lufy==4)
    {
        if(m->tab2[m->my_r][m->my_c+1]==0)
            return 0;
        else
            return 1;   
    }

}
void make_fram(maciora*m,Dane*D,char*tok)
{
    rotate(tok,"right");
    info(tok,m,D);
    explore(tok,m,D);
    int x = m->my_r;
    int y = m->my_c;
    printf("x %d   y%d\n", x,y);
    while(m->my_r!=x)
   { while(m->my_c!=y)
    {
        explore(tok,m,D);
        go_aroud (m,D,tok);
    }
     rotate(tok,"right");
   }
}

void algorytm_ruchu2(maciora*m,Dane*D,char*tok)
{
    while (check_border(m)!=1)  //zwraca 1 jęśli mamy graniec świata
    { 
            printf("algorytm1\n");     
        info(tok,m,D);
        printf("algorytm2\n");
        explore(tok,m,D);
        pokaz_macierz(m);
        printf("algorytm3\n");
        while (sprawdz_wypelnione(m)==0) //jęli nie wypełnione
        { 
                  printf("algorytm4\n");
            if (can_I_go(m)==1)
            {
                  printf("algorytm5\n");
               // if(have_you_been_here(m) == 0){
                    printf("algorytm5.5\n");
                move(tok);
                explore(tok,m,D);
                printf("algorytm6\n");

                }
                
               /* else
                {
                    printf("algorytm7\n");
                    rotate(tok,"right");
                    explore(tok,m,D);
                    printf("algorytm8\n");
                }
                */             
            else {
                rotate(tok,"right");
                printf("algorytm9\n");
                printf("robie ramkę\n");
                make_fram(m,D,tok);
                printf("algorytm10\n");}
        }
    printf ("gotowe");
    }
}
  