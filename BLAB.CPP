		  /*         blab  function   */

  #include "stdio.h"
  #include "conio.h"
  #include "all_defi.h"
   int mat[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  blab(int ti, int dob, long dnd, int *ptrR, int *ptrM)
  {
  /* струк  TKP     from BURST   KK20 */
  /* str    QQ  */
  /*    mat[13]   */

   int ddob,mdob;
   long ddnd,mdnd,ddod,mdod,tdnd,tdod;
   int tdd,tdm,mpd[MY_REST],mpm[MY_REST],mrd[MY_REST],mrm[MY_REST];/* check dimension ! */
   int qq5[MY_REST],qq6[MY_REST],q5[MY_REST];
   long rKK7,rNR;
   long cl,R1,R2;
   int r,m,i,rnr,MY_RESTP,praz,m1;
   /*   FILE  */
   FILE  *bseti;
   bseti= fopen(MY_NF0,"r+");

//    #include "defwind.c"

   R1=MY_KK20;  R2= MY_SZFSETI;
   cl=R1*R2; /*   KK20*SZFSETI;   */
   fseek(bseti,cl,0);
   for (i=0;i<MY_REST;i++){
   fscanf(bseti,"%d %d ",&mpd[i],&mpm[i]);
   if (mpd[i]==MY_EOFP){
   MY_RESTP=i; break;}}

	     /* chek  visocosnost ??????????????????????????? */
 /* ddob=dob/100;mdob=ddob*100;mdob=dob-mdob;
  ddnd=dnd/100;mdnd=ddnd*100;mdnd=dnd-mdnd;
  tdnd=dnd/10000; tdnd=tdnd*10000;
  ddnd=dnd/100; ddnd=ddnd*100;
  ddnd=ddnd-tdnd; ddnd=ddnd/100; */

    mdob=dob/100; ddob=mdob*100; ddob=dob-ddob;
    mdnd=dnd/100; ddnd=mdnd*100; ddnd=dnd-ddnd;

  if(mdob>mdnd){
  r=ddob;  m=mdob; goto n1;}
  if (mdob<mdnd){
  r=ddnd; m=mdnd; goto n1;}
  if (ddob>ddnd) {
  r= ddob; m= mdob; }
  else {
  r = ddnd; m= mdnd; }
  n1: ;     /*   ?  if (per==0) {       per==0 ?????????????????????????
  per=1;  READ QQ  FSETI QQ6 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  */
  n2: ;
  /*   пятидневка     */
  /*  m1=m;  r1=r;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  */
  if (ti==0)   goto n4;
  rnr=7;  /* ? */
  if (rnr==5) r=r+q5[ti]-1;
  if (rnr==7) r=r+ti-1;
n5: ;
   if (r<=mat[m]) goto n3;   /* ????????????????????   38.05.92  */
   r=r-mat[m]; m=m+1;
   if (m==13)  m=1;    /* !!!!!  change jear !!!!!!  */
    goto n5;
n3: ;
    /* rr=r1; */  goto n4; /*  EXIT !!!!!!!!!!!!!!!!!!!! */
	   /* APPENDIKS !!!!!!!!!  */
  if (rnr==7) {
  if (praz==0) {
  praz=1;
  for (i=1 /*!!!!!!!!!!*/ ; i<=30/* !!!!!!!!! */; i++) {
  if (mpm[i]==0) goto n5;
  if ((mpm[i]>m1)||(mpm[i]<m))  goto n6;
  if ((mpm[i]==m1)&&(mpd[i]>r)) goto n6;
  if ((r==mpd[i])&&(m1==mpm[i])) {
  r=r+1; ti= ti+1 ; }
  r=r+1;
n6: ; }}}
   /*  rr2=rr1; */
n4: ;
   *ptrR = r;  *ptrM = m;
//  cprintf ( " ti = %d  r = %d m = %d \r ", ti,r,m);
   fclose(bseti);
   return 0;
   }

















