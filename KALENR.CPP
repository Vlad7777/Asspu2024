	/* function KALENR */
#include <stdio.h>
#include <conio.h>
	/* обращение kalenr(ix1,ix2,ix3,&iy1,&iy2); */
 void kalenr(int ix1, int ix2,int ix3, int *piy1, int *piy2)

	  {
	  int id1,id3,id4,iy1,iy2;
//   #include "defwind.c"
//   cprintf("function KALENR\r");
	 iy2=8-ix1; id1=iy2-7+ix3;
	 if(id1>=ix2){
	 iy2=ix2; iy1=ix1+ix2-1; goto konec;}
	 if(id1<0) id1=0;
	 id3=ix2-id1; id4=id3/ix3; iy2=iy2+id4*7;
	 iy1=id3-id4*ix3;iy2=iy2+iy1;
	 if(iy1==0){iy1=ix3;iy2=iy2-7+ix3;}
  konec:
	 *piy1=iy1;*piy2=iy2;
    /*	 fprintf(lst,"%5d %5d %5d %5d %5d\n",ix1,ix2,ix3,iy1,iy2); */
    // cprintf("ix1=%d ix2=%d ix3=%d iy1=%d iy2=%d\n",ix1,ix2,ix3,iy1,iy2);
	     /*	 fclose(lst); */
	 return ;
	 }
