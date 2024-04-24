			   /* function good   */

#include  <stdio.h>
#include  <conio.h>
#include "all_defi.h"
   void good  (int *sw, int vss[], int tij[], int jj, int NR, int pja4[],
	    long *matr )

   {

    int j,jl,l;
//   extern long huge matr[KOLB][MAXRB];
//     #include "defwind.c"

//   cprintf(" attention work good !!!\r");
//   getche();
     for (j=0; j<jj; j++) {
   jl=1;
   for (l=0;l<NR;l++){
   if((vss[j]==pja4[l])&&(tij[l]!=0)&&(sw + l * MY_MR + 0 !=0 )){
//   matr[j][jl]=l;jl++;}}
  *( matr+j * MY_MAXRB +jl )=l;jl++;}}
//   if(jl==1) matr[j][0]=0;else matr[j][0]=jl-1;}
   if(jl==1) *(matr+j * MY_MAXRB) = 0; else *(matr+j * MY_MAXRB) =jl-1;}
   return;
   }
  void  door(long mat[], int u, long *matr)

   {
     int i;
//   extern long huge matr[KOLB][MAXRB];
//   cprintf(" attention work door !!! \r");
//   getche();

   for(i=0; i<=*(matr + u * MY_MAXRB) + 1; i++)
   mat[i]= *(matr + u * MY_MAXRB + i);
//   cprintf("   door over !!! \r");
//   getche();
   return;
   }

