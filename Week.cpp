
			 /* week function */
//#include <owl\owlpch.h>
#include <alloc.h>
#include <stdlib.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
//#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <ctype.h>
#define NOB "nazvob.dbf"  /* Узлы */
#include "math.h"

#include "all_defi.h"
#include "PartUnit.h"

#define LKUZL 4       /* Длина кода узла */


void *malloc_void(int Size_type, int Size_I, int Size_J);
void dnires(int NS, int NR, int lZ, int dNREM, int tij[], int tpl[], int pnr[],
		 int tnr[], int rr[], int ind5[], int ind6[], int ind7[]);
void  hweek(int qq5[], int qq6[], int ind5[], int ind6[], int ind7[]);
void  early(int NS, int NR, int lZ, int dNREM, int tij[], int tnr[],
		 int tor[], int axy[], int rr[], int axr[], int pms[], int qq5[],
		 int dnr[], int ip[], int jp[], int vaxr[], int vdnr[],
		 int kRR);
void maxtim(int NS, int NR, int lZ, int dNREM, int tij[], int axy[], int mj[],
		 int mij[], int dnp[], int qq5[], int rr[], int pms[], int ip[],
		 int jp[], int pnr[]);
void blab5(int *ptrX, int dob, long dnd, long dod, int god);

void helpb(int NR, int NB, int sbr[], int axyw[], int isp[], int *matrb);
void helpu(int NR, int NY, int axyw[], long pi[], long pj[], int kry[],
		int kod_paketa[] , int *matru);
void linebr(int lnb[], int ib, int *matrb);
void lineuz(int lnu[], int iu, int *matru);

#include "helpu.cpp"
#include "helpb.cpp"

 static  int Omatru[MY_KOLU][MY_MAXRU];    // THINK !!!!!!!!!!!!!!!!!!!!!!!
// void  main(void)

void __fastcall TPartForm::Week(void)
 {
// HCURSOR hcurSave=::SetCursor(LoadCursor(NULL,IDC_WAIT));
/*
 int matru[KOLU][MAXRU];
 int matrb[KOLB][MAXRB];
*/
	  // I had to done it !!!!!!!!!!!!!!!!!!!!!!!!??????????
 int *matru =//(int *)  malloc_void(2, KOLU, MAXRU);
			&Omatru[0][0];
 int *matrb = (int *)  malloc_void(2, MY_KOLB, MY_MAXRB);

 struct zagdbf {
/* char zag0; */  /*    0-й заголовочный байт */
 char zagGG ;/* год          */
 char zagMM ; /* month */
 char zagDD ;  /* day */
 unsigned long zagKOLZ ; /*   quality  */
 unsigned short zagFLZ ; /* full  length zagolovka  */
 unsigned short zagDLZ ; /*   dlina zapisi */
 char zagRES[20]; /*  reserv  */
 }  hdbf;
   struct zagdbf  *udbf;

    struct NOBdbf { char kodob[12];
		    char koduz[4];
		     char snaim[8];
		     char pnaim[40];
		     char vidob[4];
		     char urtkod;
		      } nob;
  struct NOBdbf  *unob;
  int Nob;
  int nb;
  long off=1L;
  char ch;
  int  fdbf;

  char  krychar[LKUZL+1];
  int   kry[MY_KOLU];
  float pzona[MY_KOLU];
  int   rry[MY_KOLU];
/* char sry[KOLU][TXTUS];
 char pry[KOLU][TXTU]; */

int NR,NS;

#include "str_sset.cpp"
#include "str_fedi.cpp"
 struct sset s;
 struct fedi fe;
 long rKK7,rNR;
 long cl,R1,R2;

  long *pi   =  new long[MY_MXNR];
  long *pj   =  new long[MY_MXNR];
  long *pkj  =  new long[MY_MXNR];
  int  *ip   =  new int[MY_MXNR];
  int  *jp   =  new int[MY_MXNR];
  int  *isp  =  new int[MY_MXNR];
  int  *axyw =  new int[MY_MXNR];
  int  *lnu  =  new int[MY_MXNR];
  int  *lnb  =  new int[MY_MXNR];
  int  *sbr  =  new int[MY_MXNR];
  int *kod_paketa  =  new int[MY_MXNR];


 int i ,j,k;
 int rb,r11,r2,r3;

int kvd5,kvd6;
float zona,t3;
double t1,t2,frq,irr;
int tdir,x,kv5,kv6,iff,rq;

int war,iu,min,l,NB,NY,jl,ib;

int dnrem,dkrem;
int a1,a2,RRR;
int *ptrX;
int dob;
long dnd,dod;
int  god;
int  dNREM,dKREM,kRR,lZ,fLAG=0;
int  end1,end2,tkr;
int dmtpl,xxx1,mtpl;
////////////////////////////////////////////////CG
 int *rms = new int[MY_MXNR];
 int *tij = new int[MY_MXNR];
 int *tpl = new int[MY_MXNR];
 int *tnr = new int[MY_MXNR];
 int *tor = new int[MY_MXNR];
 int *pnr = new int[MY_MXNR];
 int *axy = new int[MY_MXNR];
 int *rr  = new int[MY_MXNR];
 int *mij = new int[MY_MXNR];
 int *axr = new int[MY_MXNS];
 int *mj  = new int[MY_MXNS];
 int *dnr = new int[MY_MXNS];
 int *dnp = new int[MY_MXNS];
 int *vaxr= new int[MY_MXNS];
 int *vdnr= new int[MY_MXNS];
 int *ind5= new int[MY_TMAX];
 int *ind6= new int[MY_TMAX];
 int *ind7= new int[MY_TMAX];
 int *qq5 = new int[MY_REST];
 int *qq6 = new int[MY_REST];


	FILE  *fseti;
		//  #include "defwind.c"
  nb=sizeof(hdbf);
  udbf=&hdbf;

	fseti= fopen(MY_NF0,"r+");

		 cl=MY_KK00;
		 fseek(fseti,cl,0);
	#include "sscffedi.cpp"
//   printf(" more !!!!!!!!!! fe.nr= %d \n",fe.nr);
  if (fe.kran ==1)  {
//  printf("BНИМАНИЕ -!\r");
//  printf("Повторите ,пожалуйста,задание РКВВОД \r");
//  printf("возможны ошибки в топологии сетевой модели \r");
//  getche();
	 goto avar;}
	 NR=fe.nr; NS=fe.ns;   NY= fe.ny; NB= fe.nb;
//  printf("NR= %d \n",NR);
	  R1=MY_KK7;  R2=MY_SZFSETI;
		rKK7= R1*R2;  /* KK7*SZFSETI; */
		 R1=NR;
		rNR=R1*R2; /* NR*SZFSETI;  */
//     printf (" rKK7 = %ld  rNR = %ld \n",rKK7,rNR);
  for (i=0; i<NR; i++) axyw[i]=0;
  dNREM=fe.dr;
  dKREM=fe.dkr;
  dob=fe.dob; dnd=fe.dnd; dod=fe.dod; god=fe.god1;

	hweek(qq5,qq6,ind5,ind6,ind7);
	blab5(&x,dob,dnd,dod,god);

	tdir=24*x;
// printf("Директивный срок=%d часов \r",tdir);
// printf("Directive time is =%d часов \r",tdir);
	kv5=0;kv6=0;for(i=0;i<x;i++){
	kv5=kv5+ind5[i];kv6=kv6+ind6[i];}
	kvd5=x-kv5; kvd6=x-kv6;
	if(kvd5>0) kvd5=kvd5-1;if(kvd6>0)kvd6=kvd6-1; // Think !!!!!!!!!!!!!!!!
	cl=MY_KK00;
	fseek(fseti,cl,0);
	fe.kvd5=kvd5;
	fe.kvd6=kvd6;
	fe.kn=tdir;
	#include "sprffedi.cpp"
	/* SENI  */
	R1=MY_KK1; R2=MY_SZFSETI;
	cl=R1 * R2; /* KK1*SZFSETI;*/
	fseek(fseti,cl,0);
	for (k=0;k<NS;k++) {
	fscanf(fseti,"%ld",&pkj[k]);
// printf(" %ld",pkj[k]);
	}

		/*  Чтение наименований ОБОРУДОВАНИЯ(УЗЛОВ)*/
 /*************************************************************************/
    fdbf=open(NOB/*"nazvob.dbf"*/,O_RDWR| O_BINARY);   /*для чтения и записи*/
//   fdbf=open("tipuzla.dbf",O_RDWR| O_BINARY);
   off=1L;
   lseek(fdbf,off,0);
   nb=sizeof(hdbf);
   read(fdbf,udbf,nb);
     Nob=hdbf.zagKOLZ;
      unob=&nob;
	nb=sizeof(nob);
	off=hdbf.zagFLZ+1;
	lseek(fdbf,off,0);
    for (i=0;i<Nob;i++)     {
	read(fdbf,unob,nb);
	strncpy(krychar,nob.koduz,LKUZL);
   krychar[LKUZL] = '\0'; // CG !!!!!!!!!!!
	kry[i]=atoi(krychar);
	if ((kry[i]==0)&&(i>0)) { Nob=i; break; } /****  EXIT *********/
     /*	strncpy(sry[i],nob.snaim,LSNAIMU);
	strncpy(pry[i],nob.pnaim,LPNAIMU);  */
	off=hdbf.zagDLZ+off;
	lseek(fdbf,off,0);
      }
    close(fdbf);
     NY=Nob;

     ////////////////  CHECK !!!
 /*
     kry[0] = 16;
     NY = 1;
 */

 /*     sbr       */      /* read from FSETI !!!!!!!!!!!!!!!!!! */
//     printf ("коды бригад    \n");
     R1=MY_KK13;   R2=MY_SZFSETI;
    cl=R1*R2; /*   KK13*SZFSETI;   */
    fseek (fseti,cl,0);
    for (i=0;i<NB;i++ ) {
    fscanf(fseti,"%d",&sbr[i]);
//    printf("sbr[i]=  %d ",sbr[i]);
    }

//    printf(" NB= %d \n",NB);
    i=0;
     fe.nb= NB; fe.ny=NY; fe.kn=tdir;
       cl=MY_KK00;
  fseek(fseti,cl,0);
 #include "sprffedi.cpp"

//    printf ("rKK7= %ld rNR= %ld  NR= %d \n",rKK7,rNR,NR);
      for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
      fseek(fseti,cl,0);
       #include "sscfsset.cpp"
//    printf("iteracia i= %d \n",i);
//    printf ("s.a12(1)=%d \n",s.a12[1]);
       /* ввод или активизация данных */
       /* tij,ip,rms,rr,v,kry,rona, */
       /* call helpb,helpu */
       /* call valera */
   rms[i]=111;
   if (s.a29==3) rms[i]=111;
   if (s.a29==1) rms[i]=10;
   if (s.a29==2) rms[i]=11;
//   printf(" s.a29=%d \n",s.a29);
   isp[i]=s.a4;
   rr[i]=7;
   pi[i]=s.a1;
   pj[i]=s.a2;
// printf ("pi[i]=   %ld   pj[i]=   %ld  isp[i]= %d \n",pi[i],pj[i],isp[i]);
// ADD !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  kod_paketa[i] = s.a32[3];
   rb=s.a6 +s.a8 -s.a7;
	  for (j=0;j<NS;j++){
	   if (pi[i]==pkj[j]){
		ip[i]=j; goto fw5;}}
	  fw5:
		for (j=0;j<NS;j++){
		 if (pj[i]==pkj[j]){
		   jp[i]=j; goto fw6; }}
	  fw6:;
// printf("массивы ip,jp готовы\n");
 if (s.a5==4) { tij[i]=0; goto sli;   }
 r11=0; r2=0; r3=0;
/* printf(" r11=%d \n",r11);*/
 for (k=0;k<MY_MR;k++ ){
/*  printf(" r11=%d \n",r11);*/
  r11=r11 + s.a12[k];}
// printf (" rb= %d r11= %d s.a12[k]=%d \n",rb,r11,s.a12[k]);
 if (rb<=0) {
 if (r11 !=0) {tij[i]=0; goto sli;}
 if (s.a15!=0) {  /* ???????????????? !!!!!!!!!!!!!!!!!!!!!!!! */
 /*  axyw[i]=1;!!!!!!!???*/ tij[i] =s.a15; goto sli;} /* ???? ERROR !!!!!!! */
 if  (r11==0) {tij[i]=0; goto sli; }
  }
 axyw[i]=1;
//  a1 =s.a1/100; a2=s.a2/100;
  zona=0;
// a1=s.a1;a2=s.a2;
 for (k=0;k<NY;k++)  {
// if ((kry[k]==a1)&&(kry[k]==a2)) {
 if (kry[k]==s.a32[3]) {
 zona= pzona[k]/100; goto fw7; }}
 fw7:
 t2= (double) rb/r11;
//////////////////////////////////////////////////////
 zona = 0; //  !!!!!!!!! TMP !!!!!!!!!!!!!!
//////////////////////////////////////////////////////
/* printf(" t2= %d \n",t2);*/
  t3= t2*zona;
  t2=t2+t3;
/*  printf(" t2= %d \n",t2);*/
  t1=( t2 - floor(t2) >= 0.5 ) ?  floor(t2) +1:  floor(t2);
// Same FLOW , SETI, KRIT, ANALIZ, WEEK, !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  t1=ceil(t2);
  tij[i]=t1;

//  printf(" TIJ[I]= %d \n",tij[i]);
 if (tij[i]==0) tij[i]=1;
  sli: ;
  i++;
  }
//  for (i=0;i<NR;i++)
// printf ("pi= %ld Pj= %ld tij= %d  axyw= %d \n",pi[i],pj[i],tij[i],axyw[i]);
//  printf ( "укажите режим работы программы \r");
//  printf ( "1- расчет недель по узлам, 0 - по бригадам \r" );
//  printf ( "Point the regim of programm \r");
//  printf ( "1- calculation of weeks by units, 0 - by brigades \r" );


/* scanf ("%d", &war); !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
   war=1;  /*  по узлам !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!      */
//   war = 0; // calculation on brigade !!!
//   printf (" NR= %d NY = %d NB = %d \n",NR,NY,NB);
//   for (i=0; i<NY;i++) printf (" kry[i]= %d \n",kry[i]);
//     printf("передача управления HELPU \n");
     helpu(NR,NY,axyw,pi,pj,kry,kod_paketa,matru);
//     for (i=0; i<NB;i++) printf (" sbr[i]= %d \n",sbr[i]);
     helpb(NR,NB,sbr,axyw,isp,matrb);
     #include "valerw.cpp"

if(war==1){   /* вариант по узлам */
for(iu=0;iu<NY;iu++) {
  /* call lineuz(lNU,iu)*/
     lineuz(lnu,iu,matru);

min=9999;
for(jl=1;jl<=lnu[0];jl++) {  /*  was < !!!!!!!!!!!!!!!!!!!!!!!! */
l=lnu[jl]; if(tpl[l]<min) min=tpl[l]; }
if(min<kvd6) {

for(jl=1;jl<=lnu[0];jl++) {    /*  was <   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
l=lnu[jl];rr[l]=7; }
goto nok; }
if((min>=kvd6)&&(min<kvd5)) {
for(jl=1;jl<=lnu[0];jl++) {      /* was < !!!!!!!!!!!!!!!!!!!!!!!!!! */
l=lnu[jl];rr[l]=7;    // Was 6-ka  - change for RAES !!!!!!!!!!
} goto nok;}
if(min>=kvd5) {
for(jl=1;jl<=lnu[0];jl++) rr[lnu[jl]]=5; }    /* was < !!!!!!!!!!!!!!!!!! */
nok:  ;   }
     /* call valera */
      #include "valerw.cpp"
for(iu=0;iu<NY;iu++)  {
  /* call lincuz(lnu,iu) */
    lineuz(lnu,iu,matru);

min=9999; um: iff=0;
min=9999;
if(lnu[0]==0) goto sluz;
rq=0; for(jl=1;jl<=lnu[0];jl++) {    /*    was <  !!!!!!!!!!!!!!!!!!! */
l=lnu[jl]; if(tpl[l]<min) min=tpl[l];
rq=rq+rr[l]; }
frq=rq/lnu[0]; /*  was -1);   */

 irr=floor(frq);
// printf("irr=%f\n",irr);
if(min<0 && irr==7) {
// printf(" изменить режим сменности для узла - %d\r",iu);
goto kohec; }
if(min<0) {
iff=1; for(jl=1;jl<=lnu[0];jl++) {      /*    was < !!!!!!!!!!!!!!!!!! */
l=lnu[jl];rr[l]=rr[l]+1; }
      /* call valera */
  #include "valerw.cpp"
  goto um; }
sluz:   ; }}
else {    /* вариант по бригадам */
for(ib=0;ib<NB;ib++) {
 /* call linebr(lnb,ib); */
   linebr(lnb,ib,matrb);

min=9999;
for(jl=1;jl<=lnb[0];jl++) {    /* was < !!!!!!!!!!!!!!!!!!!!!!!!!! */
l=lnb[jl];
if(tpl[l]<min) min=tpl[l];}
if (min<kvd6){
for (jl=1;jl<=lnb[0];jl++){    /* was <  !!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
l=lnb[jl]; rr[l]=7;
}
goto koh;}

if((min>=kvd6)&&(min<kvd5)) {
for(jl=1;jl<=lnb[0];jl++) {       /*  <    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
l=lnb[jl];rr[l]=7;  // Was 6-ka for PAES
 }
goto koh; }
if(min>=kvd5) {
for(jl=1;jl<=lnb[0];jl++)
 rr[lnb[jl]]=5;
 }  /*  <   !!!!!!!!!!!!!!!!!!!!! */
koh: ; }
      /* call valera */
 #include "valerw.cpp"
      for(ib=0;ib<NB;ib++) {
       /* call /inebr(lnb,ib); */
       linebr(lnb,ib,matrb);

min=9999; bm: iff=0; rq=0;
min=9999;if(lnb[0]==0) goto slbr;
for(jl=1;jl<=lnb[0];jl++) {   /* was <  !!!!!!!!!!!!!!!!!!!!!!!!!!! */
l=lnb[jl];if(tpl[l]<min) min=tpl[l];
rq=rq+rr[l]; } frq=rq/lnb[0];  /*  was -1);   */
 irr=floor(frq);
if((min<0)&&(irr==7)) {
// printf (" измените режим сменности для бригады - %d\n",ib);
goto kohec; }
if(min<0) {
// printf ( "изм. режим работы для бригады \r",ib);
iff=1;for(jl=1;jl<=lnb[0];jl++) {    /*  < !!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
l=lnb[jl]; rr[l]=rr[l]+1; }
     /* call valera */
 #include "valerw.cpp"
goto bm; } slbr: ;  }}
     /* revrite fseti */
//     printf("REWRITE FSETI !!!!!!!!!!!! \n");
	 i=0;
//    printf ("rKK7= %ld rNR= %ld  NR= %d \n",rKK7,rNR,NR);
      for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
      fseek(fseti,cl,0);
       #include "sscfsset.cpp"
//    printf("iteracia i= %d \n",i);
    s.a26=rr[i];
//    printf("s.a26=%d \n",s.a26);
      fseek(fseti,cl,0);
      #include "sprfsset.cpp"
      i++;    }
     /* valera procedure (call dnires!) */
//     printf(" I see the end !!!!!!!!!!!!!! \n");
for(iu=0;iu<NY;iu++) {
  /* call lineuz(lnu,iu); */
   lineuz(lnu,iu,matru);
rq=9999;
// printf(" where is the uzles? \n");
 if(lnu[0]==0) goto psluz;
// printf("lnu[0]=%d \n",lnu[0]);
for(jl=1;jl<=lnu[0];jl++) {   /* <   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1 */
l=lnu[jl];if( rr[l]<rq) rq=rr[l]; }
rry[iu]=rq;
// printf(" код узла - kry[iu]=%d rry[iu]=%d -дневка \r",kry[iu],rry[iu]);
psluz:  ;  }
   /* write uzl[j], rry[j] */
// printf("write uzl[j] & rry[j]  \n" );/*******************!!!!!!!!!!!!!!*******/
   R1=MY_KK9;
   cl=R1* R2; /*  KK9*SZFSETI; */
   fseek(fseti,cl,0);
	for (i=0; i<NY; i++)  {

		 fprintf (fseti,"\n%d %f %d\n",
	 kry[i],pzona[i],rry[i]);
/*    fputs(sry[i],fseti);
	 fputs(pry[i],fseti);   */

	 }

kohec: ;
avar:  ;
fclose (fseti);
// printf(" END OF WEEK !!! ");
//::SetCursor(hcurSave);

 delete[] pi;
 delete[] pj;
 delete[] pkj;
 delete[] ip;
 delete[] jp;
 delete[] isp;
 delete[] axyw;
 delete[] lnu ;
 delete[] lnb ;
 delete[] sbr ;
 delete[] kod_paketa ;
 delete[] rms ;
 delete[] tij ;
 delete[] tpl ;
 delete[] tnr ;
 delete[] tor ;
 delete[] pnr ;
 delete[] axy ;
 delete[] rr  ;
 delete[] mij ;
 delete[] axr ;
 delete[] mj  ;
 delete[] dnr ;
 delete[] dnp ;
 delete[] vaxr;
 delete[] vdnr;
 delete[] ind5;
 delete[] ind6;
 delete[] ind7;
 delete[] qq5 ;
 delete[] qq6 ;

 return;
}


