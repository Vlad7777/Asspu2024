		/* function burst */
#include "all_defi.h"
#include <stdio.h>
#include <io.h>

   burst( int dob, long dnd, long dod, int god)

   {
   int i,k1,m1;
   int RESTP;
 #include "str_sset.cpp"
#include "str_fedi.cpp"
 struct sset s;
 struct fedi fe;
 long rKK7,rNR;
 long cl,R1,R2;
   /*struct fedi */
//////////////////////////////////CG!!!!
//   int qq5[REST],qq6[REST];
//   int ind5[MY_TMAX],ind6[MY_TMAX],ind7[MY_TMAX];
////////////////////////////////////////////CG
 int *ind5= new int[MY_TMAX];
 int *ind6= new int[MY_TMAX];
 int *ind7= new int[MY_TMAX];
 int *qq5 = new int[MY_REST];
 int *qq6 = new int[MY_REST];



   int praz,vsc,mat[13][4];
   int iv,iw,ih,ii;
   int ddob,mdob,g1,g2,g3,g,r,m;
   long ddnd,mdnd,ddod,mdod,tdnd,tdod;
   int kw1,kw2,gdn,dkr;
   int tdd,tdm;
   ////////////////////////////CG
     int  mpd[MY_REST];
     int  mpm[MY_REST];
     int  mrd[MY_REST];
     int  mrm[MY_REST];
   /* check dimension ! */
///////////////////////////////////////////////////////////////
   /* read tkp,tkr,from fseti */
   FILE  *fseti;
//    #include "defwind.c"
     fseti= fopen(MY_NF0,"r+");
//   printf("work burst \r");
//   cprintf("  dob= %d dnd=  %ld  dod= %ld  god= %d \n", dob,dnd,dod,god);

       cl=MY_KK00;
       fseek(fseti,cl,0);
   #include "sscffedi.cpp"
//  cprintf (" fe.nr= %d \n",fe.nr);
 /*  for (i=0;i<REST;i++){   */
   R1=MY_KK20;  R2= MY_SZFSETI;
   cl=R1*R2; /*   KK20*SZFSETI;   */
   fseek(fseti,cl,0);
   for (i=0;i<MY_REST;i++){
 //  Think   for  CodeGuard  !!!!!!!!!!!!!!!!!
 //  fscanf(fseti,"%d %d ",&mpd[i],&mpm[i]);   //  CG???

   if (mpd[i]==MY_EOFP){
   RESTP=i; break;}}
   ///////////////////////////////////// CG
   for (i=0;i<MY_REST;i++)
   mrd[i]=mrm[i]=0;
   /////////////////////////////////////

   /* read ind5,ind6,ind7 */
   /* read qq */
   praz=0;vsc=0;iv=0;iw=0;
   for(i=0;i<MY_TMAX;i++)  {
   ind5[i]=1;ind6[i]=1;ind7[i]=1; }
   /* qq5=qq6=0 ? */
   for (i=0;i<MY_REST;i++){
   qq5[i]=0; qq6[i]=0; }
   for (i=1;i<13;i++) mat[i][1]=i;
   for(i=1;i<13;i++) mat[i][3]=31;
   mat[4][3]=30;mat[6][3]=30;mat[9][3]=30;mat[11][3]=30;
   mat[2][3]=28;
   mat[1][2]=1;mat[2][2]=4;mat[3][2]=4;
   mat[4][2]=0;mat[5][2]=2;mat[6][2]=5;mat[7][2]=0;
   mat[8][2]=3;mat[9][2]=6;mat[10][2]=1;
   mat[11][2]=4;mat[12][2]=6;
   g1=god/100;g1=g1*100;g=god-g1;
/*   ddob=dob/100;mdob=ddob*100;mdob=dob-mdob; */
    mdob=dob/100; ddob=mdob*100; ddob=dob-ddob;

/*   ddnd=dnd/100;mdnd=ddnd*100;mdnd=dnd-mdnd;
   tdnd=dnd/10000;tdnd=tdnd*10000;
   ddnd=dnd/100;ddnd=ddnd*100;
   ddnd=ddnd-tdnd;ddnd=ddnd/100;   */
   mdnd=dnd/100; ddnd=mdnd*100; ddnd=dnd-ddnd;

   if (mdob>mdnd) {
   r=ddob;m=mdob;goto n1; }
   if (mdob<mdnd) {
   r=ddnd;m=mdnd;goto n1; }
   if (ddob>ddnd) {
   r=ddob;m=mdnd; }
   else { r=ddnd;m=mdnd; }
   n1: ;
   g1=g/12;g2=g1*12; g2=g-g2; g1=g1+g2;
   g2=g2/4; g1=g1+g2;
   if (g1>=7) {
   g2=g1/7; g3=g2*7; g1=g1-g3; }
   for (i=1; i<13; i++) {
   if (m==mat[i][1]) g1=g1+mat[i][2]; }
   if (g1>=7) { g2=g1/7; g3=g2*7; g1=g1-g3; }
   g1=g1+r;
   if (g1>=7) {
   g2=g1/7; g1=g1-g2*7; }
   /* поправкв на высокосность года */
   if (( m==1)||(m==2)) {
   g3=g/4; g2=g3*4; g2=g-g2;
   if (g2==0) {
   vsc=1;
   if(g1==0)   g1=6; else g1=g1-1;
   }}
   ih=0; if (g1==0) {       /*were ih=1 ?!!!!!!!!!!!! */
   ind5[0]=0; ind5[1]=0;    /* ? */
   ih=ih+7;
   ind6[1]=0;  /* ? */ goto m10; }
   if (g1==1) {
   ind5[0]=0; ind6[0]=0; ih=ih+6; goto m10; }
   ih=0; k1=g1;
   m2: for (i=k1+1; i<7; i++) {          /*   <=  */
   ih=ih+1;
   if (i==1) {
   ind5[ih]=0; ih=ih+1; ind5[ih]=0;
   ind6[ih]=0; ih=ih+6; goto m10; }}
   k1=0; goto m2;
   m10: for (i=ih; i<MY_TMAX; i=i+7) {
   ind5[i]=0; ind5[i+1]=0;ind6[i+1]=0; }
   /* учет праздничных и рабочих дней */
   ////////////////////////////////////////////CG !!!!
   praz=0; //  was 1  CG !!!

 /*  ddod=dod/100; mdod=ddod*100;
   mdod=dod-mdod;
   tdod=dod/10000; tdod=tdod*10000;
   ddod=dod/100; ddod=ddod*100;
   ddod=ddod-tdod; ddod=ddod/100;    */
    mdod=dod/100; ddod=mdod*100; ddod=dod-ddod;

   kw1=mdod; kw2=ddod;
   m3: for (ii=0; ii<=MY_REST; ii++) {
   if (praz==1) { tdd=mpd[ii]; tdm=mpm[ii]; }
   else { tdd=mrd[ii]; tdm=mrm[ii]; }
   if (tdm==0) goto m4;
   if (kw1<tdm) goto m5;
   if (m>tdm) goto m5;
   if ((kw1==tdm)&&(tdd>kw2)) goto m5;
   if ((m==tdm)&&(r>tdd)) goto m5;
   m1=m; ih=1; g2=g;
   if (m1==tdm) {
   ih=tdd-r+1;
   if (praz==1) {
   ind5[ih]=0; ind6[ih]=0; ind7[ih]=0;
   qq5[iv]=ih; iv=iv+1; }
   else {
   ind5[ih]=1; ind6[ih]=1; qq6[iw]=ih;
   iw=iw+1; } goto m5; }
   for (i=1; i<=12; i++) {
   if (m1==mat[i][1]) {
   if ((m1==2)&&(vsc==1)) ih=29-r+2;
   else ih=mat[i][3]-r+2;
   if (m1==12) {
   m1=1; g2=g2+1; vsc=0; }
   else { m1=m1+1; } goto m6; }}
   m6: if (m1==1) {
   g3=g2/4; g3=g3+4; g3=g2-g3;
   if (g3==0) vsc=1; }
   if (m1==tdm) {
   ih=ih+tdd-1;
   if (praz==1) {
   ind5[ih]=0; ind6[ih]=0; ind7[ih]=0;
   qq5[iv]=ih; iv=iv+1; }
   else { ind5[ih]=1; ind6[ih]=1; }
   goto m5; }
   for (i=1; i<=12; i++) {
   if (m1==mat[i][1]) {
   if ((m1==2)&&(vsc==1)) ih=ih+29;
   else ih=ih+mat[i][3];
   if (m1==12) { m1=1; g2=g2+1; vsc=0; }
   else { m1=m1+1; }
   goto m6; }} m5: ; }
   m4: if (praz==1) { praz=0; goto m3; }
   /* rewrite fseti from ind */
   /* kk22 to kk23 */
//  cprintf (" kk22 !!!!!!!!!!!!  \n");
    R1=MY_KK22;  R2=MY_SZFSETI;

     cl=R1*R2; /*  KK22*SZFSETI;  */
   fseek(fseti,cl,0);
   for (i=0;i<MY_TMAX;i++){
   fprintf(fseti,"%d %d ",ind5[i],ind6[i]);
//  cprintf("%d %d ",ind5[i],ind6[i]);
   }
   n3: /* question? */
   /* rewrite ind,qq,ind7 */
//  cprintf (" kk24 !!!!!!!!!!!!  \n");
    R1=MY_KK24;
     cl=R1*R2; /*  KK24*SZFSETI;   */
   fseek(fseti,cl,0);
   for (i=0;i<MY_REST;i++){
   fprintf(fseti,"%d %d ",qq5[i],qq6[i]);
//  cprintf("%d %d ",qq5[i],qq6[i]);
    }
//    cprintf (" kk25 !!!!!!!!!!!!  \n");
     R1=MY_KK25;
      cl=R1 * R2 ; /*    KK25*SZFSETI; */
   fseek(fseti,cl,0);
   for (i=0;i<MY_TMAX;i++){
   fprintf(fseti,"%d ",ind7[i]);
//   cprintf("%d ",ind7[i]);
   }

   if (g1>1) { g1=g1-1; }
   else { if (g1==0) g1=6;
   if (g1==1) g1=7; }
   m=mdod; r=ddod;
   fe.dr=g1;  /*   save ? */
   g1=g/12; g2=g1*12; g2=g-g2; g1=g1+g2;
   g2=g2/4; g1=g1+g2;
   if (g1>=7) { g2=g1/7; g3=g2*7; g1=g1-g3; }
   for (i=1; i<=12; i++) {
   if (m==mat[i][1]) {
   g1=g1+mat[i][2]; }}
   if (g1>=7) {
   g2=g1/7; g3=g2*7; g1=g1-g3; }
   g1=g1+r;
   if (g1>=7) {
   g2=g1/7; g1=g1-g2*7; }
   /* поправка на высокосность года */
   if ((m==1)||(m==2)) {
   g3=g/4; g2=g3*4; g2=g-g2;
   if (g2==0) {
   vsc=1; if (g1==0) g1=6; else g1=g1-1; }}
   if (g1>1) { g1=g1-1; } else {
   if (g1==0) g1=6;
   if (g1==1) g1=7; }
 fe.dkr=g1;
   /* cl=KK00; rewrite fseti from fedi */
   cl=MY_KK00;
   fseek(fseti,cl,0);
  #include "sprffedi.cpp"
//  cprintf ("fe.nr= %d \n",fe.nr);
   /* temporary */
	 cl=MY_KK00;
       fseek(fseti,cl,0);
   #include "sscffedi.cpp"
//  cprintf (" fe.nr= %d \n",fe.nr);
    fclose(fseti);

//      cprintf (" end of  job   BURST  !!!!!!!!!!!!  \n");

 delete[] ind5;
 delete[] ind6;
 delete[] ind7;
 delete[] qq5 ;
 delete[] qq6 ;

   return 0;
   }

