
	 /*    helpb function  */
#include "all_defi.h"

 void helpb(int NR, int NB, int sbr[], int axyw[], int isp[], int *matrb)

/*   int matrb[KOLB][];   */
{
// int matrb[KOLB][MAXRB] ;

 int t1,t2,jl,j,l;
// #include "defwind.c"
// printf("work helpb \r");
  for (j=0;j<NB;j++) {
  jl=1;   /*    ATTTT !!!!!  */
  for (l=0; l<NR;l++)  {
  if (axyw[l]==1) {
  if (sbr[j]==isp[l]) {
//  matrb[j][jl]=l;
	 *(matrb + j * MY_MAXRB +jl) = l;
//  cprintf ("matrb[j][jl]= %d \n",matrb[j][jl]);
	jl=jl+1;
  }}}
  if (jl==1)  *(matrb + j * MY_MAXRB) = 0;
  else  *(matrb + j * MY_MAXRB) = jl-1;
//    cprintf ("matrb[j][0]= %d \n",matrb[j][0]);

  }
  return ;
  }   /* skobki funkciii */


  void linebr(int lnb[], int ib, int *matrb)

	 {
//    int matrb[KOLB][MAXRB] ;
	 int i;
//    printf("work linebr \r");
	 for (i=0; i<= *(matrb + ib * MY_MAXRB) +1; i++)
//    lnb[i]=matrb[ib][i];
	 lnb[i]=*(matrb + ib * MY_MAXRB + i);
	 return ;
	 }
