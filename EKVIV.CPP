	  /*ekviv function */
#include <alloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "all_defi.h"

 void *malloc_void(int Size_type, int Size_I, int Size_J = 1);
 burst( int dob, long dnd, long dod, int god);

 ekviv (long pi[], long pkj[], int NR, int NS)
{
#include "str_sset.cpp"
#include "str_fedi.cpp"
 struct sset s;
 struct sset aa;
 struct fedi fe;
 /* !!!!!!!! */
 int dob;
 long dnd,dod;
 int god;
 long rKK7,rNR;
 long cl,R1,R2;
 char  ch_sset[MY_SZFSETI];
 FILE  *fseti;
/*
 long *sj   = (long *) malloc_void(4, MY_MXNR);
 long *nom  = (long *) malloc_void(4, MY_MXNR);
 long *bs   = (long *) malloc_void(4, MY_MXNR);
 long *ncl  = (long *) malloc_void(4, MY_MXNR);
 long *ccl  = (long *) malloc_void(4, MY_MXNR);
*/

 long *sj   = new long[MY_MXNR];
 long *nom  = new long[MY_MXNR];
 long *bs   = new long[MY_MXNR];
 long *ncl  = new long[MY_MXNR];
 long *ccl  = new long[MY_MXNR];


 long i,j,fl,r1,k;
 long kcl,r2;
 int ii;
 //  #include "defwind.c"
	 fseti= fopen(MY_NF0,"r+");
 /*   lst=fopen("prn","w");!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
		R1=MY_KK7;  R2=MY_SZFSETI;
		rKK7= R1*R2;  /* KK7*SZFSETI;  */
		R1=NR;
		rNR=R1*R2; /* NR*SZFSETI;    */
		 cl=MY_KK00;
		 fseek(fseti,cl,0);
	#include "sscffedi.cpp"
	dob=fe.dob;dnd=fe.dnd;dod=fe.dod;god=fe.god1;
 //   cprintf("dob=%d dnd=%ld  dod=%ld god=%d \n",dob,dnd,dod,god);
		i=0;
		for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
		fseek(fseti,cl,0);
		 #include "sscfsset.cpp"
//      cprintf("s.a1= %ld   s.a2= %ld   ",s.a1,s.a2);
		 i++;
		 }

j=0;  for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
//cprintf("cl= %ld \n",cl);
  ncl[j]=cl; ccl[j]=cl;
// cprintf("ncl[j]= %ld \n ccl[j]= %ld  \n",ncl[j],ccl[j]);
  ncl[j]=ccl[j]=cl;
// cprintf("ncl[j]= %ld ccl[j]= %ld\n",ncl[j],ccl[j]);
  j=j+1;}
/*****/
// for (i=0;i<NR;i++) cprintf("ccl[i]= %ld  ",ccl[i]);
/*****/
for(j=0;j<NS;j++) nom[j]=j;
      /* overnumber arrow works */
for(i=0;i<NR;i++){
for(j=0;j<NS;j++){
if(pi[i]==pkj[j]){
sj[i]=nom[j];
//cprintf("sj[i]= %ld ",sj[i]);
//cprintf("pi[i]= %ld  \n ",pi[i]);

    goto m1;}}
m1:; }
	/*     TEMPORARY !!!!!!!!!!!!!!!!!   */
    /*   goto m4;  bypass !!!!!!!!!!!!!!!!!! */
      /*sort array worrs & keys */
m2: fl=0; for(j=0;j<NR-1;j++){
if(sj[j]>sj[j+1]){
fl=1; r1=sj[j]; r2=ncl[j]; sj[j]=sj[j+1];
ncl[j]=ncl[j+1]; sj[j+1]=r1; ncl[j+1]=r2;}}
if(fl==1) goto m2;
// for (i=0;i<NR;i++) cprintf("Nsj[i]= %ld ccl=  %ld ncl= %ld\n ",
// sj[i],ccl[i],ncl[i]);
/* verificasion according */
for(i=0; i<NR; i++){
if(ncl[i]==ccl[i]) bs[i]=1;
else bs[i]=0;}
kcl=ccl[0];
mm3: cl=kcl;
  /*   sset=mfseti[cl];  */
// cprintf("mm3 cl= %ld \n",cl);
  fseek(fseti,cl,0);
  #include "sscfsset.cpp"
// cprintf("----  sscfsset------\n");
// cprintf("s.a1=%ld s.a2=%ld \n",s.a1,s.a2);

 m3: for(j=0; j<NR; j++){
     if(kcl==ncl[j]){
     if(bs[j]==1){
     for(i=0;i<NR; i++) {
     if(bs[i]==0){ kcl=ccl[i]; goto mm3;}}
     goto m4; }
      cl=ccl[j];
//   cprintf("ccl[j]= %ld  \n",ccl[j]);
  /*    aa=mfseti[cl];
	  mfseti[cl]=sset;      */

  /*  fscanf(fseti,"%s ",ch_sset);   */
// cprintf("cl=  %ld   \n",cl);
    fseek(fseti,cl,0);
   #include "sscfaa.cpp"
//   cprintf("aa.a1=%ld aa.a2=%ld \n",aa.a1,aa.a2);

// cprintf("s.a1=%ld s.a2=%ld \n",s.a1,s.a2);
       fseek(fseti,cl,0);
    #include "sprfsset.cpp"
//    cprintf("------sprfsset-----------\n");
     bs[j]=1; kcl=cl;
//   cprintf("s.a1=%ld s.a2=%ld aa.a1=%ld aa.a2=%ld \n",
//    s.a1,s.a2,aa.a1,aa.a2);
  s.Number = aa.Number;
  s.a1=aa.a1;
  s.a2=aa.a2;
  strcpy(s.a3,aa.a3);  /*  copy  aa.a3 ->  s.a3  */
 s.a4=aa.a4;s.a5=aa.a5;s.a6=aa.a6;s.a7=aa.a7;s.a8=aa.a8;
	for(ii=0;ii<MY_MR;ii++)	{     s.a10[ii]=aa.a10[ii];
 s.a11[ii]=aa.a11[ii];s.a12[ii]=aa.a12[ii];s.a13[ii]=aa.a13[ii]; }
 s.a14=aa.a14;s.a15=aa.a15;s.a16=aa.a16;s.a17=aa.a17;s.a18=aa.a18;
 s.a19=aa.a19;s.a20=aa.a20;
 s.a21=aa.a21;s.a22=aa.a22;s.a23=aa.a23;s.a24=aa.a24;
 s.a25=aa.a25;s.a26=aa.a26;s.a27=aa.a27;s.a28=aa.a28;s.a29=aa.a29;
for (ii=0;ii<MY_MR; ii++)	{   s.a30[ii]=aa.a30[ii];
s.a31[ii]=aa.a31[ii]; s.a32[ii]=aa.a32[ii];    }
		 goto m3;}}
	m4: ;
		/* SENI  */
  R1=MY_KK1;  R2=MY_SZFSETI;
 cl=R1*R2;/*  KK1*SZFSETI;   */
 fseek(fseti,cl,0);
 for (k=0;k<NS;k++)
 fprintf(fseti,"\n %ld ",pkj[k]);  /* ????????????????*/
	  cl=MY_KK00;
	 fe.ns=NS;
	  fseek(fseti,cl,0);
	  #include "sprffedi.cpp"
	 i=0;
		for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
		fseek(fseti,cl,0);
		 #include "sscfsset.cpp"
//      cprintf("s.a1= %ld   s.a2= %ld  \n ",s.a1,s.a2);
		 i++;
		 }
	  cl=MY_KK00;
	  fseek(fseti,cl,0);
	  #include "sscffedi.cpp"
//     cprintf(" fe.nr= %d  \n",fe.nr);
//     cprintf(" fe.ns= %d  \n",fe.ns);
		fclose(fseti);
  /*    fclose(lst);!!!!!!!!!!!!!!!!!!!!!!!!! */
		dob=fe.dob;dnd=fe.dnd;dod=fe.dod;god=fe.god1;
//   cprintf("dob=%d dnd=%ld  dod=%ld god=%d \n",dob,dnd,dod,god);

//	  printf("begin BURST \r");
	  burst(dob,dnd,dod,god);
	  delete[] sj;
	  delete[] nom;
	  delete[] bs;
	  delete[] ncl;
	  delete[] ccl;

	  return 0;
	  }