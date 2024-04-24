

		/* rang function */
//#include <owl\owlpch.h>    BCB !!!!!!!!!!!!!!!!!!!!!!!!
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <alloc.h>
#include <stdlib.h>
#include <process.h>
#include <ctype.h>
#include <string.h>
#define END 170

#include "all_defi.h"
//  #include "part.h"     BCB !!!!!!!!!!!!!!!!!

///////////////////////////////////////////////////////////////////

#include "PartUnit.h"  // !!!!!!!!!!!!!!


 void *malloc_void(int Size_type, int Size_I, int Size_J );

 burst( int dob, long dnd, long dod, int god);

 ekviv(long pi[], long pkj[], int NR, int NS);

void __fastcall TPartForm::Rang(void) 

{
// HCURSOR hcurSave=::SetCursor(LoadCursor(NULL,IDC_WAIT));
 struct zagdbf {
/* char zag0; */  /*    0-й заголовочный байт */
 char zagGG;/* год          */
 char zagMM; /* month */
 char zagDD;  /* day */
 unsigned long zagKOLZ ; /*   quantity  */
 unsigned short zagFLZ ; /* full  length zagolovka  */
 unsigned short zagDLZ ; /*   dlina zapisi */
 char zagRES[20]; /*  reserv  */
 }  hdbf;

  struct zagdbf  *udbf;
  int nb;
  long off=1L;
  int  fdbf;
  char bufer[END];
  unsigned long Nline=0L;

  char ERRTOP[END] =

  "      О Ш И Б К И  В  Т О П О Л О Г И И   С Е Т Е В О Й  М О Д Е Л И     " ;

 #include "str_sset.cpp"
 #include "str_fedi.cpp"
                         
 struct sset s;
 struct sset aa;
 struct fedi fe;
 long rKK7,rNR;
 long cl,R1,R2,j,jj;
 FILE  *fseti;
 long r1,a1,a2,p1,r2,fl;

 /////////////////////// was long !!!!!!!!!!!!
/*
 int  *pi  = (int *) malloc_void(2, MY_MXNR ,1);
 int *pj  = (int *) malloc_void(2, MY_MXNR ,1);
 int *pkj = (int *) malloc_void(2, MY_MXNR ,1);
 int *pki = (int *) malloc_void(2, MY_MXNR ,1);
 int *lmj = (int *) malloc_void(2, MY_MXNR ,1);
 int *cikl1 = (int *) malloc_void(2, MY_TUP ,1);
 int *cikl2 = (int *) malloc_void(2, MY_TUP ,1);
 int *tn  = (int *) malloc_void(2, MY_TUP   ,1);
 int *tk  = (int *) malloc_void(2, MY_TUP   ,1);
 int *tp  = (int *) malloc_void(2, MY_TUP   ,1);
 int  *ip  = (int *)  malloc_void(2, MY_MXNR  ,1);
 int  *jp  = (int *)  malloc_void(2, MY_MXNR  ,1);
*/
 long *pi  = new long[MY_MXNR];
 long *pj  = new long[MY_MXNR];
 long *pkj = new long[MY_MXNR];
 long *pki = new long[MY_MXNR];
 long *lmj = new long[MY_MXNR];
 long *cikl1 = new long[MY_TUP];
 long *cikl2 = new long[MY_TUP];
 long *tn  = new long[MY_TUP];
 long *tk  = new long[MY_TUP];
 long *tp  = new long[MY_TUP];
 long *ip  = new long[MY_MXNR];
 long *jp  = new long[MY_MXNR];



 int i,nrr,ii,per,k,m,l,NS,NR;
 int dob;
 long dnd,dod;
 int god;
 char prob= ' ';

	/**********************************************************************/
	fdbf=open(/*TOPOLOG*/"topolog.dbf",O_RDWR|O_BINARY);
	Nline=0L;
	off=1L;
	nb=sizeof(hdbf);
	udbf=&hdbf;
	lseek(fdbf,off,0);
	read(fdbf,udbf,nb);
	off=hdbf.zagFLZ+1;
	lseek(fdbf,off,0);
	nb=sizeof(bufer);
	  /* READY WRITE  LINES !!!!!!!!!!!!!!! */
  /************************************************************************/

	  /* print chapki  ERROR OF TOPOLOGY */
//       for (k=0; k<6; k++) {
	lseek(fdbf,off,0);
	strncpy(bufer,ERRTOP,END-1);
	write(fdbf,bufer,nb);
	off=hdbf.zagDLZ+off;
	Nline++;
//	  }

 sprintf(bufer,"====================================================================================================================================================================");
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

//   #include "defwind.c"
		fseti= fopen(MY_NF0,"r+");
		cl=MY_KK00;
		fseek(fseti,cl,0);
		#include "sscffedi.cpp"
		NR= fe.nr;
		R1=MY_KK7;  R2=MY_SZFSETI;
		rKK7= R1*R2;  /* KK7*SZFSETI;  */
		R1=NR;
		rNR=R1*R2; /* NR*SZFSETI;    */
		i=0;
		for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
		fseek(fseti,cl,0);
		#include "sscfsset.cpp"
		 pi[i]=s.a1; pj[i]=s.a2;
		 i++;
		 }

 j=0;
for(i=0;i<MY_MXNR;i++){

ip[i]=0;jp[i]=0;lmj[i]=0;pkj[i]=0;}

	for(i=0;i<MY_TUP;i++){
tn[i]=0;tk[i]=0;tp[i]=0;}
	/* вставка double - workes */
 i=0;
//  printf (" begin rang \r");
  goto n20; ////////////////////// BYPASS ERROR  !!!!!!!!!!!!!!!!!!!!!!!!
m81: j=i+1;
m82:;
	if((pi[i]==pi[j])&&(pj[i]==pj[j])){
//printf("\r внимание!!! имеются повторяющиеся работы!");
//printf("удаление - автоматически!\r");
//printf(" pi[i]= %ld - pj[i]= %ld i=%d j=%d\r",pi[i],pj[i],i,j);

 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer," Внимание! Имеются повторяющиеся работы! Удаление - автоматически!");
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer," pi[i]= %ld - pj[i]= %ld i=%d j=%d ",pi[i],pj[i],i,j);
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

	 cl=rKK7+rNR-MY_SZFSETI; /*  were  -1; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
	 fseek(fseti,cl,0);
	 #include "sscfsset.cpp"
//  printf("Print last job - s.a1= %ld   s.a2= %ld   ",s.a1,s.a2);
     /*  New variant !!!!!!!!!!!!!!!!!!!!! */
  /******* if ((pi[i]==s.a1)&&(pj[i]==s.a2)) goto metka;*********/
    pi[j]=s.a1; pj[j]=s.a2;
	 jj=j*MY_SZFSETI;
    cl=rKK7+jj-MY_SZFSETI;    /*  were  -1; !!!!!!!!!!!!!!!!!!!!!!!! */
    fseek(fseti,cl,0);
    #include "sprfsset.cpp"
	 /* N.var. */  /********* metka:;****************/
    j=j-1;
    cl=rKK7+rNR-MY_SZFSETI;   /*  were -1;!!!!!!!!!!!!!!!!!!!! */
    s.a1=0; s.a2=0;
    fseek(fseti,cl,0);
    #include "sprfsset.cpp"
    NR=NR-1 ;
    rNR=rNR-MY_SZFSETI; /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    cl=MY_KK00;
    fe.nr=NR;
    fseek(fseti,cl,0);
    #include "sprffedi.cpp"
    }
   j=j+1;
   if(j>=NR){     /* !!!!!!!!!!!!????????????????????? */
   i=i+1;
   if(i>=NR-1) goto n20;  /* ??????????????????????????????????? */
   goto m81;} goto m82;
   n20:;
// printf(" label 20 \n");
/* block - double works*/
for (i=0;i<NR;i++){
for (j=0;j<NR;j++){
if (pkj[j]==0){
pkj[j]=pi[i];ip[i]=j;
goto nm10;}
if(pi[i]==pkj[j]){
ip[i]=j;goto nm10;}}
nm10:;
for (j=0;j<NR;j++){
if(pkj[j]==0){
pkj[j]=pj[i];jp[i]=j;goto nm11;}
if(pj[i]==pkj[j]){
jp[i]=j;goto nm11;}}
nm11: ;    }  /*  think ? */
for(i=0;i<NR;i++){
if(pkj[i]==0) goto nm16;
NS=i+1;}
nm16: ;
//printf("\r число событий в сетевой модели - %d\r",NS);
//printf("\r число работ в сетевой модели - %d\r",NR);
m6: fl=0;
for(i=0;i<NR;i++){
r2=pi[i];ii=ip[i];r1=lmj[ii]+1;
ii=jp[i];
if(r1>lmj[ii]){
lmj[ii]=r1;fl=1;pki[ii]=r2;
if(lmj[ii]> NS){         /*  was  > !!!!!!!!!!!!!!!!!!!! */
r2=pki[ii];p1=pkj[ii];per=1;goto m5;}}}
if(fl==1) goto m6;
		  /* sortirovka */
m22:   //  printf(" label m22  \n" );
fl=0;for(j=0;j<NS-1;j++){
if(lmj[j]>lmj[j+1]){
fl=1;r1=lmj[j];lmj[j]=lmj[j+1];lmj[j+1]=r1;
r2=pkj[j];pkj[j]=pkj[j+1];pkj[j+1]=r2;}}
if(fl==1) goto m22;
// for(j=0;j<NS;j++)  printf("pkj[j]= %ld",pkj[j]);


for(i=0;i<NR;i++){
if(pj[i]==pi[i]){
//printf("\r В сетевой модели имеется петля - %5ld-%5ld\r", pi[i],pj[i]);
//getche();
 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer," В сетевой модели имеется петля!");
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer,"  %5ld-%5ld ", pi[i],pj[i]);
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

per=1;}}
if(per==1) goto n;
fl=0;k=1;for(j=1;j<NS;j++){
if(lmj[0]==lmj[j]){
fl=1;per=1;tn[0]=pkj[0];tn[k]=pkj[j];k=k+1;}}
if(fl==0) goto m13;
//printf("\r В сетевой модели имеется несколько начальных событий \r");
//getche();
 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer,"  В сетевой модели имеется несколько начальных событий!");
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

for(j=0;j<MY_TUP;j++){
if(tn[j]==0) goto m13;
// printf("%9ld\r",tn[j]);
//getche();
 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer,"%9ld",tn[j]);
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;


}
m13: //    printf(" label m13 \n");
k=1;fl=0;
for(j=0;j<NS-1;j++){
if(lmj[NS-1]==lmj[j]){
fl=1;per=1;tk[0]=pkj[NS-1];tk[k]=pkj[j];
k=k+1;}}
if(fl==0) goto m15;
//printf("\r В сетевой модели имеется несколько конечных событий \r");
//getche();
 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer," В сетевой модели имеется несколько конечных событий !");
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

for(j=0;j<MY_TUP;j++){
if(tk[j]==0) goto m15;
//printf("%9ld\r",tk[j]);
//getche();
 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer,"%9ld",tk[j]);
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

}
m15:   // printf(" label m15 \n");
fl=0;k=0;
for(i=0;i<NR;i++){
for(j=0;j<NR;j++){
if(pj[i]==pi[j]) goto m20;}
for(j=0;j<NS;j++){
if(pj[i]==pkj[j]){
if(lmj[j]== lmj[NS-1]) goto m20;
tp[k]=pj[i];k=k++;fl=1;per=1; goto m20;}}
m20: ; }
if(fl==0) goto m17;
//printf("\r В сетевой модели имеются тупиковые события \r");
//getche();
 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer,"В сетевой модели имеются тупиковые события!");
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

for(j=0;j<MY_TUP;j++){
if(tp[j]==0) goto m17;
//printf("%9ld\r",tp[j]);
//getche();
 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer,"%9ld",tp[j]);
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

}
m17: goto n;
m5: /* defind contuir */        r1=1;
cikl1[0]=p1; cikl2[0]=r2;
for(k=1;k<NS;k++){
for(j=0;j<NS;j++){
if(r2==pkj[j]){
p1=pkj[j];r2=pki[j];cikl2[k]=r2;
cikl1[k]=p1;goto n2;}}
n2:if(k>1) goto n3;
else goto n4;
n3: for(j=0;j<k-1;j++){    /* was -2 !!!!!!!!!!!!!!! */
if(r2==cikl2[j]){
m=k;l=j; goto n5;}}
n4: ; }
n5:
//printf("\r Замкнутый контур,\r проверьте, пожалуйста, данные работы \r");
//getche();
 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer,"Замкнутый контур! Проверьте, пожалуйста, данные работы!");
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

//  printf(" l=%d m= %d \r",l,m);
for(i=l;i<m;i++)
//printf("%9ld - %9ld\r",cikl2[i],cikl1[i]);
//getche();
 strnset(bufer,prob,END); /*  copy ' '  into bufer */
 sprintf(bufer,"%9ld - %9ld",cikl2[i],cikl1[i]);
 for (jj=0;jj<END;jj++) if (bufer[jj]=='\0')  bufer[jj]=' ';
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

n: ;
/* сохранить  pkj */
 /* SENI  */
 /*  cl=KK1*SZFSETI;
 fseek(fseti,cl,0);     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!
 for (k=0;k<NS;k++)
 fprintf(fseti,"%ld",pkj[k]);     */

 ////////////////////////////////////////////////////////////////////
 // fclose(fseti);  CGuard !!!!!????
  ekviv(pi,pkj,NR,NS);
  cl=MY_KK00;
  fseek(fseti,cl,0);
  #include "sscffedi.cpp"
  dob=fe.dob;dnd=fe.dnd;dod=fe.dod;god=fe.god1;
//   printf("dob=%d dnd=%ld  dod=%ld god=%d \n",dob,dnd,dod,god);
////////////////////////////////////// CG  /////////////////////////

// burst(dob,dnd,dod,god);

//////////////////////////////////////////////////////////////////

 sprintf(bufer,"====================================================================================================================================================================");
 lseek(fdbf,off,0); write(fdbf,bufer,nb); off=hdbf.zagDLZ+off; Nline++;

  off=1;
  hdbf.zagKOLZ= Nline;    /*  more dd mm gg !!!!!!!!!!!! */
  lseek(fdbf,off,0);
  nb=sizeof(hdbf);
  write(fdbf,udbf,nb);
  close(fdbf);
 // ::SetCursor(hcurSave);
 delete[] pi ;
 delete[] pj ;
 delete[] pkj;
 delete[] pki;
 delete[] lmj;
 delete[] cikl1;
 delete[] cikl2;
 delete[] tn  ;
 delete[] tk  ;
 delete[] tp  ;
 delete[] ip  ;
 delete[] jp  ;

  return;
}
