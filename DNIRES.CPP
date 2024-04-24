	/* DNIRES function */
#include "conio.h"
#include "stdio.h"

void dnires(int NS, int NR, int lZ, int dNREM, int tij[], int tpl[], int pnr[],
		 int tnr[], int rr[], int ind5[], int ind6[], int ind7[])

{
int i,jt;
int idl,xx,xa;
// #include "defwind.c"
//     printf ("work DNIRES function ");
	for(i=lZ;i<NR;i++)  {
	if(tij[i]==0)	{
	tpl[i]=0; goto ps10;
	}
	if((pnr[i]-tnr[i])<24) {
	 tpl[i]=0; goto ps10;
	 }
	xx=(tnr[i]+23)/24; xa=(pnr[i]+23)/24; idl=0;
	if(rr[i]==7) {
	for(jt=xx;jt<xa;jt++)     /*   ????  <=  */
	idl=idl+ind7[jt];
	tpl[i]=idl-1; goto ps10;
	}
	if(rr[i]==5) {
	for(jt=xx;jt<xa;jt++) idl=idl+ind5[jt];      /*  <=  */
	tpl[i]=idl-1; goto ps10;
	}
	for(jt=xx;jt<xa;jt++) idl=idl+ind6[jt];      /*  <=   */
	tpl[i]=idl-1;

ps10:;
// cprintf(" tpl[i]=%d  ",tpl[i]);
}
return ;
}
