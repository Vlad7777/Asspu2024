	/*    helpu function  */
#include "all_defi.h"
#include "conio.h"
 void helpu(int NR, int NY, int axyw[], long pi[], long pj[], int kry[],
		int kod_paketa[] , int *matru)
{
//  int matru[KOLU][MAXRU];

int t1,t2,jl,j,l;
// #include "defwind.c"
// printf ("work helpu  \r");
  for (j=0;j<NY;j++) {
  jl=1;   /*    ATTTT !!!!!  */
  for (l=0; l<NR;l++)  {
//  t1=pi[l]/100;  t2=pj[l]/100;

//  cprintf("t1=%d t2=%d \n",t1,t2);
  if (axyw[l]==1) {
//  if ((kry[j]==t1)&&(kry[j]==t2)) {
  if (kry[j]==kod_paketa[l]) {
//  matru[j][jl]=l;
  *(matru + j * MY_MAXRU + jl) = l ;
//  cprintf (" matru[j][jl]= %d  \n",matru[j][jl]);
  jl++;
  }}}
//  if (jl==1) matru[j][0]=0;
  if (jl==1)
	  *(matru + j * MY_MAXRU ) = 0;
  else
	  *(matru + j * MY_MAXRU ) =jl-1;
//  cprintf (" matru[j][0]= %d  \n",matru[j][0]);
  }
  return ;
  }   /* skobki funkciii */

  void lineuz(int lnu[], int iu, int *matru)

  {
//   int matru[KOLU][MAXRU];
   int i;
//    cprintf ("work lineuz  \r");
//    for (i=0; i<=matru[iu][0] +1; i++)
    for (i=0; i<=*(matru + iu * MY_MAXRU ) +1; i++)
//    lnu[i]=matru[iu][i];
       lnu[i]=*(matru + iu * MY_MAXRU + i);
//    cprintf("choose from lnu[i]=%d elementov \n",lnu[0]);
	 return ;
  }
