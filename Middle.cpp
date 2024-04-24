			 /* function middle */
//	 #include <owl\owlpch.h>
	 #include <stdio.h>
	 #include <conio.h>
	 #include <alloc.h>
	 #include <stdlib.h>
	 #include "all_defi.h"
     #include "PartUnit.h"

 void *malloc_void(int Size_type, int Size_I, int Size_J = 1);
 void hweek(int qq5[], int qq6[], int ind5[], int ind6[], int ind7[]);

 /* OLD ????
 void screen_save(int x1, int x2,int y1,int y2);
 void rectang(int x1,int y1,int x2,int y2,int phone);
 void border(int x1,int y1,int x2,int y2,int phone,int type_border);
 void destroy_box(int x1, int x2,int y1,int y2);
 void shadow(int x1,int y1,int x2,int y2,int colore);
 int  need_position(int *cursor_x,int *cursor_y,int *x1,int *x2,int *y2);
  */
 // int  timer (int x1,int y1,int x2,int y2,int i,int step,int max);
// void zastavka(int x1,int y1,int x2,int y2);
// int  finita(int x1,int y1,int x2,int y2,int max);

#include "str_fedi.cpp"

void grupp1 (struct fedi *pfe, int *cw, int *sw, int pms[],
		 int tij[], int tpl[], int tnr[], int tor[], int pnr[], int axy[],
		 int mij[], int  axr[], int mj[], int dnr[], int dnp[], int rr[],
		 int vaxr[], int vdnr[], int ind5[], int ind6[], int ind7[],
		 int qq5[], int qq6[], int ip[], int jp[], int  NR, int pja4[],
		 int sbr[]);

void polres(int NS, int NR, int lZ, int dNREM, int tij[], int tpl[],
		 int pnr[],
		 int tnr[], int rr[], int pms[], int ind5[], int ind6[],
		 int ind7[], int fLAG);

//  long huge matr[MY_KOLB][MAXRB];
	 int ipR[MY_MXNR],jpR[MY_MXNR] ;
	 int pmsR[MY_MXNR];
//  long pkj[MY_MXNS];
////////////////////////////////////////////////////////////////////////
//int tijR[MY_MXNR],axyR[MY_MXNR],tplR[MY_MXNR],tnrR[MY_MXNR],torR[MY_MXNR],pnrR[MY_MXNR]; // TEMP!!!!!!!!!
//  int tnrR[MY_MXNR];
///////////////////////////////////////////////////////////////////////
/*
static far int pms[MY_MXNR],tij[MY_MXNR],tpl[MY_MXNR],tnr[MY_MXNR],tor[MY_MXNR],pnr[MY_MXNR],
	 axy[MY_MXNR],
	 axr[MY_MXNS], mj[MY_MXNS];
/*
int static far axr[MY_MXNS],mj[MY_MXNS],dnr[MY_MXNS],dnp[MY_MXNS],rr[MY_MXNR];
int static far vaxr[MY_MXNS],vdnr[MY_MXNS];
int static far ind5[MY_TMAX],ind6[MY_TMAX],ind7[MY_TMAX];
int static far qq5[REST],qq6[REST];
 */

void __fastcall TPartForm::Seti(void)
	 {
//	 HCURSOR hcurSave=::SetCursor(LoadCursor(NULL,IDC_WAIT));
	 /* str-fedi */
	 /*
	 int cw[MY_MXNR][MR];
	 int sw[MY_MXNR][MR];
	 long matr[MY_KOLB][MAXRB];
     */
//    int (*cw)[MY_MXNR][MR], (*sw)[MY_MXNR][MR]; // MY_MXNR * MR * 2
    int *cw, *sw; // MY_MXNR * MR * 2
//    long *matr;   // MY_KOLB * MAXRB * 4
    /* all dcl week */
    int NR,NS;
 #include "str_sset.cpp"
// #include "str_fedi.cpp"
 struct sset s;
 struct fedi fe;
 long rKK7,rNR;
 long cl,R1,R2;
 /**************************** EXTERN **************************************/
// extern long pi[MY_MXNR],pj[MY_MXNR] ;
// extern long pkj[MY_MXNS];
 /**************************************************************************/
// int ip[MY_MXNR],jp[MY_MXNR];
// int isp[MY_MXNR];  //  axyw[MY_MXNR]; ???
 int i ,j,k;
 int rb,r11,r2,r3,t2,t3;
 /*
 int   kry[MY_KOLU];
 float pzona[MY_KOLU];
 int   rry[MY_KOLU];
 */
// long *pi, *pj;  //   * MY_MXNR
 long *pkj;      //   * MY_MXNS
 int  *ip, *jp;  //   * MY_MXNR
 int  *isp;      //   * MY_MXNR

 int   *kry;     //   * MY_KOLU
 float *pzona;   //   * MY_KOLU
 int   *rry;     //   * MY_KOLU

int kvd5,kvd6;
float zona;
/* ca// blab5 */
int x,kv5,kv6,irr,iff,rq;
//int sbr[MY_KOLB];

int *sbr;  // * MY_KOLB

int war,iu,min,l,NU,NB,NY,jl,ib;

int dnrem,dkrem;
int a1,a2;
float frq;
int *ptrX;
int dob,dnd,dod,god;
int dNREM,dKREM,kRR,lZ,fLAG=0;
int end1,end2,tkr;
int dmtpl,xxx1,mtpl;
/////////////////////////////////////////////////////////////////////////////
/*
static int tij[MY_MXNR], tpl[MY_MXNR],tnr[MY_MXNR],tor[MY_MXNR],pnr[MY_MXNR],
    axy[MY_MXNR],pms[MY_MXNR]; //,mij[MY_MXNR];
int axr[MY_MXNS],mj[MY_MXNS],dnr[MY_MXNS],dnp[MY_MXNS],rr[MY_MXNR];
int vaxr[MY_MXNS],vdnr[MY_MXNS];
int ind5[MY_TMAX],ind6[MY_TMAX],ind7[MY_TMAX];
int qq5[REST],qq6[REST];
*/
////////////////////////////////////////////////////////////////////////


int *pms, *tij, *tpl, *tnr, *tor, *pnr, *rr, *axy, *mij;   //MY_MXNR
int  *axr, *mj, *dnr, *dnp, *vaxr, *vdnr;   //MY_MXNS
int *ind5, *ind6, *ind7;   //MY_TMAX
int *qq5, *qq6;   //REST

int rsrv;
int kn,tdir;

   FILE  *fseti, *pseti, *pkrit;

   // printf (" Working MIDDLE \n\r");
    // Please use the malloc_my !!!
    cw  = (int *)  malloc_void(2, MY_MXNR, MY_MR);
    sw  = (int *)  malloc_void(2, MY_MXNR, MY_MR);
    sbr = (int *)  malloc_void(2, MY_KOLB);
//  pi  = (long *) malloc_void(4, MY_MXNR);           Not need!!!
//  pj  = (long *) malloc_void(4, MY_MXNR);           Not need!!!
    pkj = (long *) malloc_void(4, MY_MXNR);
    ip  = //(int *)  malloc_void(2, MY_MXNR);
	    &ipR[0];
    jp  = //(int *)  malloc_void(2, MY_MXNR);
	    &jpR[0];
    isp = (int *)  malloc_void(2, MY_MXNR);
    kry = (int *)  malloc_void(2, MY_KOLU);
    pzona = (float *) malloc_void(4, MY_KOLU);
    rry = (int *)  malloc_void(2, MY_KOLU);
//////////////////////////////////////////////////////////////////////////
/* */
    pms = //(int *)  malloc_void(2, MY_MXNR);
          &pmsR[0];
    tij = (int *)  malloc_void(2, MY_MXNR);
	  //&tijR[0];
    tpl = (int *)  malloc_void(2, MY_MXNR);
	  //&tplR[0];
    tnr = (int *)  malloc_void(2, MY_MXNR);
	  //&tnrR[0];
    tor = (int *)  malloc_void(2, MY_MXNR);
	  //&torR[0];
    pnr = (int *)  malloc_void(2, MY_MXNR);
	  //&pnrR[0];
    axy = (int *)  malloc_void(2, MY_MXNR);
	  //&axyR[0];
/**/
//////////////////////////////////////////////////////////////////////////
    rr  = (int *)  malloc_void(2, MY_MXNR);
          //&rrR[0];
    mij = (int *)  malloc_void(2, MY_MXNR);
    axr = (int *)  malloc_void(2, MY_MXNS);
    mj  = (int *)  malloc_void(2, MY_MXNS);
    dnr = (int *)  malloc_void(2, MY_MXNS);
    dnp = (int *)  malloc_void(2, MY_MXNS);
    vaxr= (int *)  malloc_void(2, MY_MXNS);
    vdnr= (int *)  malloc_void(2, MY_MXNS);
    ind5= (int *)  malloc_void(2, MY_TMAX);
    ind6= (int *)  malloc_void(2, MY_TMAX);
    ind7= (int *)  malloc_void(2, MY_TMAX);
    qq5 = (int *)  malloc_void(2, MY_REST);
    qq6 = (int *)  malloc_void(2, MY_REST);

//   hweek(qq5,qq6,ind5,ind6,ind7);  /*    replace !!!!!!!!!!!! */
      fseti= fopen(MY_NF0,"r+");

    R1=MY_KK22; R2=MY_SZFSETI;
     cl= R1*R2;    /*  KK22*SZFSETI;   */
   fseek(fseti,cl,0);
   for (i=0;i<MY_TMAX;i++){
   fscanf(fseti,"%d %d ",&ind5[i],&ind6[i]);
   }
   /* read ind,qq,ind7 */
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

   ///////////////////////////////////////??????  BAG!!!!
   for (i=0;i<MY_TMAX;i++){
   ind7[i] = 1;   //  Temporary  !!!!
   //fscanf(fseti,"%d ",&ind7[i]);
   }

    ///////////////////////////////////////////////!!!///////////////
    //  pkrit= fopen(MY_PK,"w");  I don't write  pkrit !!! 30/03/99
        cl=MY_KK00;
       fseek(fseti,cl,0);
   #include "sscffedi.cpp"
//  printf (" \n more !!!!!!!!!! fe.nr= %d \n",fe.nr);
  if (fe.kran ==1)  {
// printf ("BНИМАНИЕ -!\n\r");
// printf ("Повторите ,пожалуйста,задание РКВВОД \n\r");
// printf ("возможны ошибки в топологии сетевой модели \n\r");
  goto avar;}
  NR=fe.nr; NS=fe.ns; NY=fe.ny;  NB=fe.nb;

// printf ("NR= %d \n",NR);
// getche();

     R1=MY_KK7;  R2=MY_SZFSETI;
     rKK7= R1*R2;  /* KK7*SZFSETI; */
     R1=NR;
     rNR=R1*R2; /* NR*SZFSETI;  */
//    printf  (" rKK7 = %ld  rNR = %ld \n",rKK7,rNR);
//  for (i=0; i<NR; i++) axyw[i]=0;     //???????????????????
  dNREM=fe.dr;
  dKREM=fe.dkr;
  fe.kn= fe.tdir;   //  in FLOW !!!!!!!!!!!!!!!!!!!!!!!!
  kn=fe.kn;
  kn= fe.tdir; //  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! from dir term !!!!
  tdir=fe.tdir;
    /* read fseti into sset */
   /* calll number  defined tij sw nt arrows !!!!!!!!!!!!!! */
/*************************************************************************/
 /* SENI  */
 R1=MY_KK1; R2=MY_SZFSETI;
 cl=R1 * R2; /* KK1*SZFSETI;*/
 fseek(fseti,cl,0);
 for (k=0;k<NS;k++) {
 fscanf(fseti,"%ld",&pkj[k]);
// printf (" %ld",pkj[k]);
 }
	 /*    yzl    */
//  printf ("\n   ремонтируемые узлы - \n");
   R1=MY_KK9;
   cl=R1* R2; /*  KK9*SZFSETI; */
   fseek(fseti,cl,0);
      for (i=0; i<NY; i++)  {

    fscanf (fseti,"%d %f %d ",
	 &kry[i],&pzona[i],&rry[i]);
//    fgets(sry[i],TXTUS,fseti);            ?????????????????
//   printf  ("sry[i]=  %s \n",sry[i]);
//     fgets(pry[i],TXTU,fseti);             ????????????????
//   printf ("pry[i]= %s \n",pry[i]);
	if (kry[i]== MY_EOFU) {
	  NY=i; goto m53; }
	 }
 m53: ;

 for(i=0;i<NR;i++) axy[i]=0; // NEW OPERATOR  !!!!
 /*     sbr       */
//    printf  ("коды бригад  и фио бригадиров  \n");
//    getche();

	  R1=MY_KK13;   R2=MY_SZFSETI;
	 cl=R1*R2; /*   KK13*SZFSETI;   */
	 fseek (fseti,cl,0);
	 for (i=0;i<NB;i++ ) {
	 fscanf(fseti," %d",&sbr[i]);
//   printf ("sbr[i]=  %d",sbr[i]);
	 }
//   printf (" NB= %d \n",NB);
//   getche();
	 i=0;
//   printf  ("rKK7= %ld rNR= %ld  NR= %d \n",rKK7,rNR,NR);
		for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
		fseek(fseti,cl,0);
		 #include "sscfsset.cpp"
//   printf ("iteracia i= %d \n",i);

//    if (ind7[0]!=1) {
//   printf ("STOP \n");  }

//       pi[i]=s.a1; pj[i]=s.a2;         OUT        !!!!
	 rr[i]=s.a26;
    isp[i]=s.a4;    /* !!!!!!!! */
	  for (j=0;j<NS;j++){
	   if (s.a1==pkj[j]){
		ip[i]=j; goto fw5;}}
	  fw5:
		for (j=0;j<NS;j++){
		 if (s.a2==pkj[j]){
		   jp[i]=j; goto fw6; }}
	  fw6:;
// printf ("массивы ip,jp готовы\n");
// getche();
    if(s.a14<=2) pms[i]=10;
    if((s.a14>2)&&(s.a14<=5)) pms[i]=11;
    if(s.a14>5) pms[i]=111;
    if(rsrv==1) tpl[i]=s.a24; else tpl[i]=s.a25;

    if (s.a5==3) {
    axy[i]=s.a22;   // If the job is doing , so she begin in early term !!!
     }              // CHECK !!!!!!!!!!!!!!!!!!!!!!!!!

    if(s.a5==4) {
    tij[i]=0;
    for(k=0;k<MY_MR;k++) {
//    cw[i][k]=0; sw[i][k]=0;
    *(cw+i*MY_MR+k)=0;
    *(sw+i*MY_MR+k)=0;
	}
     goto bix4;
     }
    if(s.a15==0) {
    tij[i]=0;
    for(k=0;k<MY_MR;k++) {
//    cw[i][k]=0; sw[i][k]=0; } goto bix4; }
    *(cw+i*MY_MR+k)=0; *(sw+i*MY_MR+k)=0; } goto bix4; }
    tij[i]=s.a15;
    for(k=0;k<MY_MR;k++) {
//    cw[i][k]=s.a30[k];
//    sw[i][k]=s.a31[k]; }
    *(cw+i*MY_MR+k)=s.a30[k];
    *(sw+i*MY_MR+k)=s.a31[k];
    }
    bix4:; i++; }  /*cl=cl+1;*/

    /* call valera */
      lZ=0; fLAG=1; kRR=0;

    #include "valera.cpp"   /*  mj[i]=axr[NS], */
    /* call grupp1(s2,s3,s4,s5,fedi,frosi) */
//    printf ("Grupp1 begin \n");
//    getche();
    grupp1(&fe,cw,sw,pms,tij,tpl,tnr,tor,pnr,axy,mij, axr,mj,dnr,dnp,rr,
	    vaxr,vdnr,ind5,ind6,ind7, qq5,qq6,ip,jp, NR,isp,sbr);
    /* cl=0; read fseti into fedi */

       cl=MY_KK00;
       fseek(fseti,cl,0);
   #include "sscffedi.cpp"
//   printf (" more !!!!!!!!!! fe.nr= %d \n",fe.nr);
    fe.kn=axr[NS-1];
    /* cl=0; rewrite fseti  from fedi */
       cl=MY_KK00;
       fseek(fseti,cl,0);
   #include "sprffedi.cpp"
/* ************************************************************** */
    /* save tpl[ ]l pkj[ ] */
    /* recount polres */
	  /* save tpl */
     for(i=0;i<NR;i++) pkj[i]=tpl[i];
     fLAG=1;
     polres(NS,NR,lZ,dNREM,tij,tpl,pnr,tnr,rr,pms,ind5,ind6,ind7,fLAG);
	 /* rewrite fseti sset */
	 /* !!!!!!!!!!!!!!!!!! */
//      printf (" result of job MIDDLE \r");
       pseti=fopen(MY_PS,"a");
//      printf (" РЕЗУЛЬТАТ оптимизации по ресурсам \r");
      fprintf(pseti," РЕЗУЛЬТАТ оптимизации по ресурсам \n");
//     printf ("--pi---pj----tij---tnr---tor---pnr---rr---pms---");
//     printf ("tpl--tsv--nt--\r");
      fprintf(pseti,"--pi---pj----tij---tnr---tor---pnr---rr---pms---");
      fprintf(pseti,"tpl--tsv--nt--\n");
	i=0;
      for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
      fseek(fseti,cl,0);
       #include "sscfsset.cpp"

    if(s.a5==4) goto bix7;
    s.a22=tnr[i]; s.a23=tor[i];
    s.a18=tpl[i]; s.a24=pkj[i];/* tpl */
    /* s.a15=tij[i]; call ntsw(i,int,pers);
    a14=int; for(k=0;k<MR;k++) s.a31[k]=pers[k]; */
    /* rewrite fseti sset */
     fseek(fseti,cl,0);
       #include "sprfsset.cpp"
    bix7:;   /* cl>cl+1; */
      /* print file FSETI */
// printf ("\r%3ld %3ld %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d",
// s.a1,s.a2,s.a15,s.a22,s.a23,pnr[i],rr[i],pms[i],
// s.a24,s.a25,s.a18,s.a14);
 fprintf(pseti,"\n %3ld %3ld %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d",
s.a1,s.a2,s.a15,s.a22,s.a23,pnr[i],rr[i],pms[i],
s.a24,s.a25,s.a18,s.a14);
i++;
     }
    avar:;   /*  вставка bibodf for PLOTTER !!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    fclose (fseti);
	 fclose(pseti);
//    ::SetCursor(hcurSave);
	 return;
	}