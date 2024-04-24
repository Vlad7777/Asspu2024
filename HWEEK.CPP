     

	   /*      function    hweek    */
#include <stdio.h>
//#include <conio.h>
#include "all_defi.h"


    hweek(int qq5[], int qq6[], int ind5[], int ind6[], int ind7[])
   {
 #include "str_fedi.cpp"
 struct fedi fe;
 long cl,R1,R2;
 int i;

   /* read tkp,tkr,from fseti */
   FILE  *fseti;

//#include "defwind.c"
//    cprintf("work hweek \r");
   fseti= fopen("fseti.fff","r+");
       cl=MY_KK00;
       fseek(fseti,cl,0);

 /*   #include "sscffedi.c"        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
   printf (" fe.nr into HWEEK NR = %d \n",fe.nr); */
     /* read fseti into ind */
   /* kk22 to kk23 */
//   cprintf (" kk22 !!!!!!!!!!!!  \n");
    R1=MY_KK22; R2=MY_SZFSETI;
     cl= R1*R2;    /*  KK22*SZFSETI;   */
   fseek(fseti,cl,0);
   for (i=0;i<MY_TMAX;i++){
   fscanf(fseti,"%d %d ",&ind5[i],&ind6[i]);
   }
   /* read ind,qq,ind7 */
//   cprintf (" kk24 !!!!!!!!!!!!  \n");
     R1=MY_KK24;
     cl= R1*R2;  /*  KK24*SZFSETI;  */
   fseek(fseti,cl,0);
   for (i=0;i<MY_REST;i++){
/*   fscanf(fseti,"%d %d ",&qq5[i],&qq6[i]);*/
    }
//     cprintf (" kk25 !!!!!!!!!!!!  \n");
      R1=MY_KK25;
      cl=R1*R2;  /*  KK25*SZFSETI; */
   fseek(fseti,cl,0);
   for (i=0;i<MY_TMAX;i++){
   fscanf(fseti,"%d ",&ind7[i]);

   }
     fclose(fseti);
   return 0;
   }