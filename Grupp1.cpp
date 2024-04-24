		 /*    function grupp1    */
 #include <stdio.h>
 #include <stdio.h>
 #include <alloc.h>
 #include <stdlib.h>
 #include "all_defi.h"

void  early(int NS, int NR, int lZ, int dNREM, int tij[], int tnr[],
		 int tor[], int axy[], int rr[], int axr[], int pms[], int qq5[],
		 int dnr[], int ip[], int jp[], int vaxr[], int vdnr[],
		 int kRR);
void maxtim(int NS, int NR, int lZ, int dNREM, int tij[], int axy[], int mj[],
		 int mij[], int dnp[], int qq5[], int rr[], int pms[], int ip[],
		 int jp[], int pnr[]);
void polres(int NS, int NR, int lZ, int dNREM, int tij[], int tpl[],
		 int pnr[],
		 int tnr[], int rr[], int pms[], int ind5[], int ind6[],
		 int ind7[], int fLAG);
void kalenr(int ix1, int ix2,int ix3, int *piy1, int *piy2);
void kalenp(int ix1, int ix2,int ix3, int *piy1, int *piy2);
 int dned  (int iz1, int dNREM);

void bgckas(float gcka[], float rab[], long mat[], int tnr[], int tor[],
		int tij[], int pnr[], int axy[], int pms[], int *sw, int rr[],
		int ind5[], int ind6[], int ind7[],
		int mj[], int jp[], int kn, int lZ, int intt[], float pkxy[]);

void celf  (long mat[], int tnr[], int rr[], int tor[], int ind5[], int ind6[],
		int ind7[], float gcka[], double  *pfa, float gckaf[]);
void cikper(int cw[][MY_MR], int *sw, int lZ);

void bskor1(int *sw, float gcka[], float rab[], int ind5[], int ind6[],
		int ind7[], int lZ, int w, int kn, int skorst[]) ;

void bskor (int tnr[], int tor[], int *sw, int pms[], int rr[],
		int ind5[], int ind6[], int ind7[], float gcka[], float rab[],
		int lZ, int kn, int w, int NS, int NR, int dNREM,
		int tij[], int axy[], int axr[], int vaxr[], int ip[], int jp[],
		int dnr[], int vdnr[], int qq5[], int kRR, int skorst[]);

void blvsr (int *cw, int *sw, long mat[], int vrs[], int rbs,
		int u, long * matr);

void good  (int *sw, int vss[], int tij[], int jj, int NR, int pja4[],
		long *matr);

void door  (long mat[], int u, long *matr);

 #include "str_fedi.cpp"
 void grupp1( struct fedi *pfe, int *cw, int *sw, int pms[],
		 int tij[], int tpl[], int tnr[], int tor[], int pnr[], int axy[],
		 int mij[], int  axr[], int mj[], int dnr[], int dnp[], int rr[],
		 int vaxr[], int vdnr[], int ind5[], int ind6[], int ind7[],
		 int qq5[], int qq6[], int ip[], int jp[], int  NR, int pja4[],
		 int sbr[])

 {

// #include "str_fedi.cpp"
	 int i,j,jj,jz,  NS,NB;
	 int axyz,maxold,ifz,max,maxk,k;
    int dNREM,dKREM,kRR,lZ,fLAG=0;
    int kn,tdir;
    int end1,end2,tkr;
    int dmtpl,xxx1,mtpl;

    long *mat;  // MAXRB
    long *matr; // KOLB * MAXRB
    char *screen_save_area;

    int rbs=0; /* temporary !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

      /*long or float duble? */
   double  fa,mfa,farr,fr,msrg;
//   float  rab[KSMEN],skorst[KSMEN];
   float  *rab;    // [KSMEN]
   int *skorst;    // [KSMEN]   & [TT]  !!!!!!!!!!!!!????????????????



//   float  pkxy[TT],gcka[TT]; /*or Ho f ?*/
   float  *pkxy, *gcka , *gckaf;  // [TT]
//   int intt[TT];
   int *intt;   // [TT]


    /*str-vasi?*/   /* uss, vrs */
//   int vrs[MXR];   /* temporary */
   int *vrs; // [MXR]
//   int vss[99];   // !!!!! kol-vo  brigad ?
   int *vss;  // * 99


   int q,h,ax,by,ki,rk,dlina,per,r1,vrr,tn,tk;
   int   r,un,uk,ug,ur,u,t,w;
    /*str-frosi*/
      /*   str_frosi    */
//   int uzls[KOLU];
  int *uzls;    // [KOLU]

  /*str_mani   */
//   int uzlr[KOLU];
   int *uzlr;      //  [KOLU]

  /*   str_vasi    */
//   int vro[KORES],vo[KORES];
   int *vro, *vo;  //  [KORES]


    /*  STR_TANI  */
/*  int  sbr[KOLB];*/
    /*str-fedi*/
 /*    #include "str_fedi.c"  */
 /*   struct fedi fe;       */
   int maxz,ilz;
   int itij,isw,itnr,itor,ix1,ix3,tnr1,ip1,pms1,tij1,axy1,tor1;
   int nsw,nnt,ntij,klu,lsw,nmax,iint;

	   // Describe of screen
//   int step=0;
//   int z11=15,d11=5,z22=68,d22=21;

   FILE  *pseti;

  if ((matr = (long *) malloc(MY_KOLB * MY_MAXRB * 4)) == NULL)
   {
		printf("Недостаточно XMS памяти для размещения буфера - matr \r\n");
		exit(1);
	}


  if ((mat = (long *) malloc(MY_MAXRB * 4)) == NULL)
	{
		printf("Недостаточно XMS памяти для размещения буфера - mat \r\n");
		exit(1);
   }


    if ((rab = (float *) malloc(MY_KSMEN * 4)) == NULL)
   {
		printf("Недостаточно XMS памяти для размещения буфера - rab \r\n");
		exit(1);  /* terminate program if out of memory */
	}

	 if ((skorst = (int *) malloc(MY_KSMEN * 2)) == NULL)
	{
		printf("Недостаточно XMS памяти для размещения буфера - skorst \r\n");
		exit(1);
	}

	if ((pkxy = (float *) malloc(MY_TT * 4)) == NULL)
	{
		printf("Недостаточно XMS памяти для размещения буфера - pkxy \r\n");
		exit(1);  /* terminate program if out of memory */
	}

   if ((gcka = (float *) malloc(MY_TT * 4)) == NULL)
   {
		printf("Недостаточно XMS памяти для размещения буфера - gcka \r\n");
		exit(1);  /* terminate program if out of memory */
	}
	if ((gckaf = (float *) malloc(MY_TT * 4)) == NULL)
	{
		printf("Недостаточно XMS памяти для размещения буфера - gckaf \r\n");
		exit(1);  /* terminate program if out of memory */
	}

	 if ((intt = (int *) malloc(MY_TT * 2)) == NULL)
	{
		printf("Недостаточно XMS памяти для размещения буфера - intt \r\n");
		exit(1);  /* terminate program if out of memory */
	}

	 if ((vrs = (int *) malloc(MY_MXR * 2)) == NULL)
	{
		printf("Недостаточно XMS памяти для размещения буфера - vrs \r\n");
		exit(1);  /* terminate program if out of memory */
	}
	 if ((vss = (int *) malloc(99 * 2)) == NULL)
	{
		printf("Недостаточно XMS памяти для размещения буфера - vss \r\n");
		exit(1);  /* terminate program if out of memory */
   }

    if ((uzls = (int *) malloc(MY_KOLU * 2)) == NULL)
   {
		printf("Недостаточно XMS памяти для размещения буфера - uzls \r\n");
		exit(1);  /* terminate program if out of memory */
	}

	  if ((uzlr = (int *) malloc(MY_KOLU * 2)) == NULL)
	{
		printf("Недостаточно XMS памяти для размещения буфера - uzlr \r\n");
		exit(1);  /* terminate program if out of memory */
	}

	 if ((vro = (int *) malloc(MY_KORES * 2)) == NULL)
	{
		printf("Недостаточно XMS памяти для размещения буфера - vro \r\n");
		exit(1);  /* terminate program if out of memory */
	}

	 if ((vo = (int *) malloc(MY_KORES * 2)) == NULL)
	{
		printf("Недостаточно XMS памяти для размещения буфера - vo \r\n");
		exit(1);  /* terminate program if out of memory */
	}

	pseti=fopen(MY_PS,"w");
	dNREM=pfe->dr;
	dKREM=pfe->dkr;
	kn= (pfe->kn+7)/8;
	tdir=pfe->tdir;
	NS=pfe->ns;
	NB=pfe->nb;
	vrs[0]=25; /* temporary  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  */
	 for(i=0;i<NB;i++) { /* all-tempopary! */
	 if(sbr[i]==9999) goto met1;
	 vss[i]=sbr[i]; }
  met1: jj=i;  /*    was  -1;  !!!!!!!!!!! */
// printf(" jj= %d \n",jj);
//     getche();

	good(sw, vss, tij, jj, NR, pja4, matr);
//   for (i=0;i<NR;i++)  {
//   if ((tpl[i]==0)&&(tij[i]!=0))  axy[i]=tnr[i]; }
	  lZ=0; fLAG=0; // Was flaG 1 ?????????????????????????
		kRR=0;
	#include "valera.cpp"
// printf(" valera over \n",jj);
// getche();

	  /*   blvsr  in  bot  */
	  w=0;   /* begin !! !  */

//  zastavka(z11,d11,z22,d22);

//printf("Zastavka over ");
//getche();

	  for (u=0; u<jj; u++)  {        //  So was !!!
/**************************************************************************/
//    step=timer(z11,d11,z22,d22,u,step,jj);      //  DYNAMO!!!!!!!!
/**************************************************************************/
	  /*   call blvsr    */
		blvsr(cw,sw,mat,vrs,rbs,u,matr);
// printf(" BLVSR over  jj= %d rbs= %d \n",jj,rbs);
// getche();

	  gp3:  for (r=0; r<=rbs; r++)  {
	  if (mat[0]==0) goto gp4;
//    printf ("оптимизируется бригада %d \n",vss[u]);
//    getche();
	fprintf(pseti,"оптимизируется бригада %d \n",vss[u]);
//    printf("Optimization scheduling of brigade %d \r\n",vss[u]);

  /*************** DEBUG ***************************************/
  //   if (vss[u]==101) continue;   // !!!!!!!!!!!!!!!!!!!!!!!!
  /**************************************************************/

//     mfa=999999999;   OVERFLOW !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		 mfa=9999999;
	  for (jz=1; jz<=mat[0]; jz++) { /* was  <  !!!!!!!!!!!!!!!!!  */
	  lZ= mat[jz];
  //   if (sw[lZ][0]==0) continue;
	if (*(sw+lZ * MY_MR ) ==0) continue;

//      printf("анализиpуется pабота  %d \r",lZ);
      fprintf(pseti,"анализиpуется pабота  %d \n",lZ);

/* mls1: ???*/  if (axy[lZ]!=0) goto mls2;
   if (tpl[lZ]==0) {
   axy[lZ]= tnr[lZ]; goto mls2; }

   // NEW OPERATOR - add !!!! 4.11.92     if reserv <  48 houres
////////////////////////////////////////////////////////////////////////////
    if (tpl[lZ] <= 24)  goto mls2;   // Was 48 !!!!!!!!!!!!!!!!!!!!!!!!!!!!
////////////////////////////////////////////////////////////////////////////

//  Analise executive job !!!!!!!!!!!!!!!! if (s.a5 ==3) { axy[lZ]=tnr[lZ];}

   axy[lZ] =tnr[lZ]; tn=axy[lZ];
   tk=pnr[lZ];
   kRR=0;
   for (i=tn; i< tk  /* -24 */ ; i=i+24) { /*  4.11.1993 !!!!!!!!!!!!! */
   axy[lZ]=i;
   if (rr[lZ]==5) {
		      //  Attention please  j-1 !!!!!!!!!!!!!!!!
		   j=(i+23)/24;  if ( ind5[j-1]==0)   goto ml5;
		   else goto ml6;}
   if (rr[lZ]==6) {
		   j=(i+23)/24; if  (ind6[j-1]==0)   goto ml5;
		   else goto ml6;}
   if (rr[lZ]==7) {
		   j=(i+23)/24; if  (ind7[j-1]==0)  goto ml5;
		   else goto ml6;}
	 ml6:  if (i==tn)  {
 kRR=1;
 bgckas(gcka, rab,mat,tnr,tor,tij,pnr,axy,pms,sw,rr,
	ind5,ind6,ind7,mj,jp,kn,lZ,intt,pkxy);
// DEBUG  for (k=0;k<TT;k++)   rab[k]=rab[k]*1000;
  bskor(tnr,tor,sw,pms,rr,ind5,ind6,ind7,gcka,rab,lZ,kn,w,NS,NR,dNREM,
	tij,axy,axr,vaxr,ip,jp,dnr,vdnr,qq5,kRR,skorst);
	fa=kn; // KUAES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 celf(mat,tnr,rr,tor,ind5,ind6,ind7,gcka,&fa,gckaf);
   fprintf(pseti,"  fa_0= %f \n", fa);
   fprintf(pseti," mfa_0= %f \n", fa);
 mfa=fa; axyz=i; goto ml5;
  }
 kRR=0; /* NEW OPERATOR !!! */
   bskor(tnr,tor,sw,pms,rr,ind5,ind6,ind7,gcka,rab,lZ,kn,w,NS,NR,dNREM,
      tij,axy,axr,vaxr,ip,jp,dnr,vdnr,qq5,kRR,skorst);
	fa=kn; // KUAES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  celf(mat,tnr,rr,tor,ind5,ind6,ind7,gcka,&fa,gckaf);
   fprintf(pseti," fa= %f \n", fa);
 if (fa<mfa) {
 mfa=fa;
//    printf ("mfa= %f \r",mfa);
    fprintf(pseti,"mfa= %f \n",mfa);
  axyz=i;  }
 ml5: ; }
 kRR=2;
 axy[lZ]=axyz;

   early(NS,NR,lZ,dNREM,tij,tnr,tor,axy,rr,axr,pms,qq5,dnr,ip,jp,
   vaxr,vdnr,kRR);
/****************************************************************************/
/*     experiment for KAES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!           */
/*     wstavka     MAXTIM  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!           */
 if (tdir>=axr[NS-1]) {       // Normal complete !!!
    for (i=0; i<NS; i++) {
//   mj[i]=axr[NS-1]; dnp[i]=dnr[NS-1];
    mj[i]=tdir; dnp[i]=dKREM;
		   }}
	else {
    for (i=0; i<NS; i++) {
    mj[i]=axr[NS-1]; dnp[i]=dnr[NS-1];

	  }}
/*	                                                                    */
	  maxtim(NS,NR,lZ,dNREM,tij,axy,mj,mij,dnp,qq5,rr,pms,ip,jp,pnr);
/**********************  experiment for KAES  *******************************/

 /*  CALL POLRES ???????!!!!!!!!! */
	  /* call polres*/
	   polres(NS,NR,lZ,dNREM,tij,tpl,pnr,tnr,rr,pms,ind5,ind6,ind7,fLAG);

 mls2: ;
  } // cikle for ????? job or brigade !!

  if (tdir>=axr[NS-1]) {       // Normal complete !!!
    for (i=0; i<NS; i++) {
//   mj[i]=axr[NS-1]; dnp[i]=dnr[NS-1];
    mj[i]=tdir; dnp[i]=dKREM;
		   }}
	else {
    for (i=0; i<NS; i++) {
    mj[i]=axr[NS-1]; dnp[i]=dnr[NS-1];

	  }}

	  /* call maxtim */
	  maxtim(NS,NR,lZ,dNREM,tij,axy,mj,mij,dnp,qq5,rr,pms,ip,jp,pnr);
		  /* call polres*/
	  polres(NS,NR,lZ,dNREM,tij,tpl,pnr,tnr,rr,pms,ind5,ind6,ind7,fLAG);


 }
 /**************************************************************************/
//    goto gp4; /*  temporary in hour !!!!!! */
  continue;
 /**************************************************************************/
 maxold =0; /* no translated in houres !!! */
 slmax: ifz =0;   /*  defind middle pers  */
 lZ=9999;
 bgckas(gcka,rab,mat,tnr,tor,tij,pnr,axy,pms,sw,rr,ind5,ind6,ind7,
	 mj,jp,kn,lZ,intt,pkxy); /* all axy */
 for (k=0;k<kn;k++)  gcka[k]=rab[k]; /* for celf */ /*  for elem  */
 max =0;
 for (k=0;k<kn;k=k+3) {
 rab[k]=rab[k]+rab[k+1]+rab[k+2];
 if (rab[k]>max) {
 max= rab[k];  maxk =k; }}
 if ((maxold==maxk)&&(ifz==0)) goto bceend;
 maxz=max; maxold=maxk;
 for (jz=1; jz<=mat[0]; jz++) {
 lZ= mat[jz];
 if ((tnr[lZ]<=maxk)&&(tor[lZ]>=maxk)) {
 ix1= dnr[ip[lZ]];  ix3= rr[lZ]; tnr1=axr[ip[lZ]];
 axy1=0; ip1=ip[lZ]; pms1=pms[lZ];
// if (sw[lZ][w]==0)  goto sledr;
   if (*(sw + lZ * MY_MR + w)==0)  goto sledr;
/*  swtij(lZ,nsw,nnt,ntij,klu); */ /* !!!!!!!!!!!!!!! number !!!!!!!!!! */
/*********************************/
 if (klu==0) goto sledr;
 tij1=ntij;  /*   att! early1  */
/*  early1(); */   /*  (dnrem,s18,s4);*/
/***************************************************/
 if (tor1>=axr[jp[lZ]]) goto sledr;
 lsw=*(sw + lZ * MY_MR + w);  *(sw + lZ * MY_MR + w)=nsw;
 bgckas(gcka,rab,mat,tnr,tor,tij,pnr,axy,pms,sw,rr,ind5,ind6,ind7,
	 mj,jp,kn,lZ,intt,pkxy);
 bskor1(sw,gcka,rab,ind5,ind6,ind7,lZ,w,kn,skorst);
 max=0;
 for (k=0; k<kn; k=k+3)  {
 nmax= gcka[k]+ gcka[k+1] + gcka[k+2];
 if (nmax>max) max=nmax;}
 celf(mat,tnr,rr,tor,ind5,ind6,ind7,gcka ,&fa,gckaf);
 if (( max<=maxz)&&(fa<mfa)) {
 ifz=1; ilz=lZ; mfa=fa; isw=nsw;
 itij=ntij; maxz= max; iint=nnt;
 itnr=tnr1; itor=tor1;
 *(sw + lZ * MY_MR + w)=lsw;}}
 sledr: ; }
 if (ifz== 0) goto slmax;
 lZ=ilz; tij[lZ]=itij; *(sw + lZ * MY_MR + w)=isw;
 tnr[lZ]=itnr; tor[lZ]=itor;
 axy[lZ]=itnr;
 /* wwnt(); */ /*   call wwnt(ilz,iint); */
 /************************************************************************/
 goto slmax;
 bceend: ;
 #include "valers.cpp"
 for (jz=1;jz<=mat[0];jz++) {
 lZ= mat[jz]; ix1= dnr[ip[lZ]];
 ix3=rr[lZ]; axyz= axy[lZ];
 tnr1=axr[ip[lZ]]; ip1=ip[lZ];
 pms1=pms[lZ]; tij1=tij[lZ]; axy1=0;
 /*  early1(); (dnrem,s18,s4) */
 /********************************************************************/
 bgckas(gcka,rab,mat,tnr,tor,tij,pnr,axy,pms,sw,rr,
	ind5,ind6,ind7,mj,jp,kn,lZ,intt,pkxy);

 bskor1(sw,gcka,rab,ind5,ind6,ind7,lZ,w,kn,skorst);
 celf(mat,tnr,rr,tor,ind5,ind6,ind7,gcka,&fa,gckaf);
 if (fa<mfa) {
 mfa=fa; axyz= tnr1;}
 mg1: axy1=tnr1+1;
 /*  early1();  */
 /**********************************************************************/
 if (tor1>=axr[jp[lZ]])   goto mg2;
 bskor1(sw,gcka,rab,ind5,ind6,ind7,lZ,w,kn,skorst);
 celf(mat,tnr,rr,tor,ind5,ind6,ind7,gcka,&fa,gckaf);
 axy1=tnr1;
 if (fa<mfa) { mfa=fa; axyz=axy1;}
 goto mg1;
 mg2: if (axyz!=axy[lZ]) {
 ifz=1; axy[lZ]=axyz; }
 mg3: ;  }
 #include "valers.cpp"
 gp4: ; }
// finita(z11,d11,z22,d22,jj);  !!!!!!!!!!!   // function Vitalia

 fclose(pseti);
 return;
 }   /*    end of grupp1  */

void bgckas(float gcka[], float rab[], long mat[], int tnr[], int tor[],
	   int tij[], int pnr[], int axy[], int pms[], int *sw, int rr[],
	   int ind5[], int ind6[], int ind7[],
	   int mj[], int jp[], int kn, int lZ, int intt[], float pkxy[])

 {
     float rk,h,q; /*   Not int !!!! */
    int i,k,jl,l,w,j,tnrs,tors,ax,by,r1,per,ki,t;
 for (i=0;i<MY_TT;i++) gcka[i]=0;   // was kn !!!!!!!!!!!!!!
 w=0;
 for (k=0;k<MY_TT;k++) rab[k]=0;     // was kn !!!!!!!!!!!!!!!
 for (jl=1; jl<=mat[0]; jl++) {    /* !!!!!!!!!!!!!!! " <= "   */
  l=mat[jl];
 for (k=0;k<MY_TT;k++)   gcka[k]=0; // !!!!!!!!!!!!!!!  TT, a Was  - kn
 if (l==lZ) goto bo2N;   /* NEW LABEL !!!!!!!! */
 tnrs= (tnr[l]+7)/8;  tors =(tor[l]+7)/8;
 if (axy[l]!=0) {
 if (pms[l]==10) {
 for (k=tnrs;k<=tors; k=k+3) {
 gcka[k]=  *(sw + l * MY_MR + w);
 }
  goto  bs2; }
 if (pms[l]==111)   {
 for ( k=tnrs;k<= tors ;k++) {
 gcka[k]=  *(sw + l * MY_MR + w);
 }
   goto bs2; }
 for (k=tnrs; k<= tors; k++) {
 r1 =k/3; r1=k-r1*3;
 if (r1!=1) gcka[k]= *(sw + l * MY_MR + w);
 }
 bs2: if (rr[l]==7) goto bs3;  /* bypass */
 for ( k=tnrs; k<= tors; k++) {
 j=(k+2)/3;
 if  (rr[l]==5) gcka[k]=gcka[k]*ind5[j-1];
 if  (rr[l]==7) gcka[k]=gcka[k]*ind7[j-1];
 if  (rr[l]==6) gcka[k]=gcka[k]*ind6[j-1];
 }
 bs3: ;
 goto bo2; }
 ax= (tnr[l]+7)/8; by=(mj[jp[l]]+7)/8;
 by=by-1;
 r1=tij[l];rk=r1/8;     /* ????????????????????? */
 if (rk==0) rk=1;
// if (pms[l]==10) tij[l]=rk*3-2;      /* ?????????????????????  RK  */
// if (pms[l]==11) tij[l]=(3*rk-1)/2;    /* ?????????????????????  RK  */

 if (pms[l]==10) tij[l]=tij[l]*3-2;
 if (pms[l]==11) tij[l]=(3*tij[l]-1)/2;

 rk=(pnr[l]+7)/8;
 q = rk-ax+1;
 if (q==0)  q=1;
 if (rr[l]==7) goto bix;
 per=(by-ax)/21;
 if  (rr[l]==5) per= per*6;
 if (rr[l]==6) per=per*3;
 tij[l]=tij[l]+per;
 bix: ;
 for(t=0;t<MY_TT;t++) { pkxy[t]=0;  intt[t]=0; }
 if (q<tij[l]) h=q; else h=tij[l];
 tij[l]=r1;
 if (h!=1) goto pb1;   t=1; ki=0;
 pb2: intt[t]=ax+ki;  pkxy[t]=1/q;
 if (intt[t]>by-1) goto pb3;
 ki=ki+1; t=t+1; goto pb2;
 pb1:  if (h!=2)  goto pb4;
 t=1; intt[t]=ax;  pkxy[t] =1/q;  ki=1;  t=t+1;
 pb5: intt[t]=ax+ki; pkxy[t]=2/q;
 if (intt[t]<=(by-2)) {
 ki=ki+1;  t=t+1; goto pb5; }
 intt[t]=ax+ki; pkxy[t]=1/q; goto pb3;
 pb4: t=1; intt[t]=ax;  pkxy[t]=1/q;
 rk=1; t=t+1;  ki=1;
 pb6: if ((ax+ki) <= (ax+h-2)) {
 intt[t]=ax+ki; rk=rk+1;
 pkxy[t]=rk/q; ki=ki+1; t=t+1; goto pb6; }
 pb7: if ((ax+ki)<= (by-h)) {
 intt[t]=ax+ki; pkxy[t]=h/q;ki=ki+1;
 t=t+1;  goto pb7; }
 pb8:  if ((ax+ki) <=(by-1)) {
 intt[t]=ax+ki;
pkxy[t]= rk/q; rk=rk-1; ki=ki+1; t=t+1;
goto pb8;
}
pb3: if (pms[l]==10) {
t=1;
for (k=ax; k<=(by-1); k=k+3) {
//gcka[k]=sw[l][w]*pkxy[t]; t=t+3;}
gcka[k]=*(sw +l * MY_MR + w) * pkxy[t]; t=t+3;}
goto bs4;}
if (pms[l]==111 ) {
t=1;
for (k=ax; k<=(by-1);k++) {
gcka[k]=*(sw +l * MY_MR + w) * pkxy[t]; t++;}
goto bs4;}
t=1;    /*  pms[l]= 11 */
for (k=ax; k<=(by-1); k++) {
r1=k/3; r1=k-r1*3;
if (r1 !=1) {
gcka[k]= *(sw +l * MY_MR + w)*pkxy[t]; }
t++;}
bs4: if (rr[l]==7) goto bo2;
for (k=ax; k<=(by-1);k++) {
j=(k+2)/3;
if (rr[l]==5) gcka[k]=gcka[k]*ind5[j-1];
else gcka[k]=gcka[k]*ind6[j-1]; }
bo2: for (k=1; k<=kn; k++)
rab[k]=rab[k]+gcka[k];
bo2N:; /* New label ->  bypass lead job  */
}
return;
} /* end bgckas */      /* ATT !!!!!!!!! */

void celf  (long mat[], int tnr[], int rr[], int tor[], int ind5[], int ind6[],
	   int ind7[], float gcka[], double  *pfa, float gckaf[])

   {
// float  gckaf[TT];
 double farr,fa,fr;
 int mint,maxt,irr,krd,tnrs,tors;
 int jc,l,lh,lk,j,k;
  FILE  *fopen(), *cseti;

fa=0; mint=9999; maxt=0;
for (l=0;l<MY_TT;l++) gckaf[l]=0;
for (jc=1;jc<=mat[0]; jc++) {
l= mat[jc]; tnrs= (tnr[l]+7)/8;
fa=fa+rr[l];
if (tnrs<mint) mint=tnrs;
tors=(tor[l]+7)/8;
if (tors>maxt) maxt=tors; }

//ADD for KUAES !!!!!!!!!!!!!!!!!!  maxt =  kn * 8;  Extended time !!!
// kn in smenax !!!    pfa ==== kn
	    maxt = *pfa - 1 ;
//************************************************************************/

if (mint==0) mint=1;
fa=fa/mat[0]; /* was -1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
irr=7; /*temporary !!!!!! irr=floor(fa);!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
lh =(mint +2)/3;   lk=(maxt+2)/3;krd=0;
if (irr==5) {
for (l=lh; l<=lk; l++) krd= krd+ind5[l-1];
goto cf1; }
if (irr==6) {
for (l=lh ;l<=lk; l++) krd=krd+ind6[l-1];
goto cf1;}
if (irr==7) {
for (l=lh;l<=lk;l++) krd=krd+ind7[l-1];
}
cf1: ;
fa=0;
//for (k=mint; k<maxt; k++) fa=fa+gcka[k];  // <= !!!!!!!!!     WAS
  for (k=mint; k<maxt; k++) fa=fa+gcka[k];//*10;  // OPTIMIZATION !!!!!!!!
fa=fa/krd; j=mint/3; j=mint-j*3;
if (j==2) mint=mint-1;
if (j==0) mint=mint-2;
j=maxt/3; j=maxt-j*3;
if(j==2) maxt=maxt+1;
if(j==1) maxt=maxt+2;
l=1;
for (k=mint; k<maxt; k=k+3) {     // <= !!!!!!!!!!!!!!!!!!!!!!!1
gckaf[l]=gcka[k]+gcka[k+1]+gcka[k+2];
//gckaf[l]=gckaf[l]*10;                         // OPTIMIZATION !!!!!!!!
if (gckaf[l]!=0) l++; }
farr=0;
for (l=1;l<krd; l++)  {   // <= !!!!!!!!!!!!!!!!!!!!
fr=(gckaf[l]-fa);
// printf("fr= %f \n",fr);

farr= farr+fr*fr;/* *fr*fr; */   /*(gckaf[l]-fa)*(gckaf[l]-fa);  ???? */
  }
// printf("farr= %f \n",farr);
fa=farr;
*pfa=fa; /* pointer !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
// printf("fa= %f \n",fa);
/********* cseti= fopen(PS,"a");
	   fprintf(cseti,"fa= %f \n",fa); **************/
return;
} /* end celf */



  void  cikper(int cw[][MY_MR], int sw[][MY_MR], int lZ)
{
int w,rk,vrr;
w=0;vrr=cw[lZ][w];  rk=sw[lZ][w];
for (w=0; w<=MY_MR-2;w++) { /*?*/
if (cw[lZ][w+1]==0) {
cw[lZ][w]=vrr; sw[lZ][w]=rk; goto cp1;}
cw[lZ][w]=cw[lZ][w+1]; sw[lZ][w]=sw[lZ][w+1]; }
cw[lZ][MY_MR-1]=vrr; sw[lZ][MY_MR-1]=rk;
cp1: ;  w=0;
return;
}  /* end cikper */

void bskor1(int *sw, float gcka[], float rab[], int ind5[], int ind6[],
	   int ind7[], int lZ, int w, int kn, int skorst[])

{

int pms1,tnr1,tor1,r1,k,ix3,j;

for (k=0;k<MY_TT;k++)  skorst[k]=0; /* arrrr  */     // KSMEN == TT !!!!!!!!!!!
if (pms1==10) {
for ( k=tnr1; k<=tor1; k=k+3)
skorst[k]= *(sw +lZ * MY_MR + w);
goto b11; }
if(pms1==111) {
for (k=tnr1; k<=tor1; k++)
skorst[k]=*(sw +lZ * MY_MR + w);
goto b11;}
for (k=tnr1; k<=tor1; k++) {
r1=k/3; r1=k-r1*3;
if (r1!=1) skorst[k]=*(sw +lZ * MY_MR + w); }
b11:  if (ix3==7) goto b12;
for (k=tnr1; k<=tor1;k++) {
j=(k+2)/3;
if (ix3==5) {skorst[k]=skorst[k]*ind5[j-1]; }
if (ix3==7) {skorst[k]=skorst[k]*ind7[j-1]; }
if (ix3==6) {skorst[k]=skorst[k]*ind6[j-1]; }}
b12: ;
for (k=0; k<kn;k++)
    gcka[k]=rab[k]+skorst[k];
return;
    }  /*  ehd bskor1 */


void bskor (int tnr[], int tor[], int *sw, int pms[], int rr[],
	   int ind5[], int ind6[], int ind7[], float gcka[], float rab[],
	   int lZ, int kn, int w, int NS, int NR, int dNREM,
	   int tij[], int axy[], int axr[], int vaxr[], int ip[], int jp[],
	   int dnr[], int vdnr[], int qq5[], int kRR, int skorst[])

{
int inr,ins,j,k,tnrs,tors,r1;
for (k=0;k<MY_KSMEN;/*or TT?? */k++)    skorst[k]=0;
for (k=0;k<MY_TT;k++)    gcka[k]=0;    // NEW !!!!!!!!!!!!!!!!!
 inr=lZ+1; ins=NS;  /*  only  lZ +1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */


/* calll  early */
early(NS,inr,lZ,dNREM,tij,tnr,tor,axy,rr,axr,pms,qq5,dnr,ip,jp,vaxr,vdnr,kRR);

tnrs=(tnr[lZ]+7)/8; tors=(tor[lZ]+7)/8;
if (pms[lZ]==10) {
for (k=tnrs; k<=tors; k=k+3) skorst[k]=*(sw + lZ * MY_MR + w);
goto br1; }
if (pms[lZ]==111) {
for (k=tnrs; k<=tors; k++) skorst[k]=*(sw + lZ * MY_MR + w);
goto br1; }
if (pms[lZ]==11) {
for (k=tnrs; k<=tors; k++) {
r1=k/3; r1=k-r1*3;
 if (r1!=1)   skorst[k]=*(sw + lZ * MY_MR + w);
 }}
br1: ;
if (rr[lZ]==7) goto br2;
for (k=tnrs; k<=tors; k++) {
j=(k+2)/3;
if (rr[lZ]==5) {skorst[k]=skorst[k]*ind5[j-1];  }
if (rr[lZ]==6) {skorst[k]=skorst[k]*ind6[j-1];  }
if (rr[lZ]==7) {skorst[k]=skorst[k]*ind7[j-1];  }
}
br2: ;
for (k=1; k<=kn; k++) gcka[k]=rab[k]+skorst[k];
return;
} /* end bskor */
void blvsr(int *cw, int *sw, long mat[], int vrs[], int rbs, int u,
	  long * matr)
 {
 int jl,l,w,vcr;
 rbs=0; vrs[0]=25;   /* temporary !!!!!!!!!! */
 /*  call  door(mat,u)   */
//  printf(" DOOR begin \n");
// getche();

  door(mat,u,matr);
 /******************************************************************/
 for (jl=1; jl<=mat[0]; jl++) {  /* !!!!!!!!!!!!!!!!!  <= !!!!!!!!!!! */
 l=mat[jl]; vcr=0;
 for (w=0; w<MY_MR;w++)  vcr=vcr+*(sw + l * MY_MR + w);
 *(sw + l * MY_MR + 0)=vcr;  /* tempor!!!!!! */
 if (vcr!=0)/* cw[l][0]=25;*/   *(cw + l * MY_MR + 0) = 25;
 al2:; }
 /* temp !!!!1 */ goto vov4;
/****  for (l=0;l<NR;l++) {
* ppi=pi[l]/100;
*for (u=un;u<uk;u++) {
* if (ppi==uzls[u]) goto buk2; }
* goto buk3;
 buk2: for (w=0;w<MR;w++) {
 if (cw[l][w]==0) goto buk3;
 for (r=0;r<MXR;r++)
 if (vrs[r]==cw[l][w]) goto buk4;
 if (vrs[r]==0) {
 vrs[r]=cw[l][w];
 vss[r]=vss[r]+sw[l][w]*tij[l]; goto buk4;}}
 buk4:;}
 buk3:;
 }
 for (r=0;r<MXR;r++)  if (vrs[r]==0) break;
 buk5; rbs=r; ************ att!!!!!!!! *******************
 buk6: h=0;
 for (r=0;r<rbs;r++) {
 if (vss[r+1]>vss[r]) {
 vrr=vrs[r]; vcr=vss[r]; vrs[r]=vrs[r+1];
 vss[r]=vss[r+1];vrs[r+1]=vrr;vss[r+1]=vcr;
 h=1;  }}
 if (h!=0) goto buk6;
 for (l=0;l<NR; l++) {
 ppi=pi[l]/100;
 for (u=un; u<=uk;u++) {
 if (ppi==uzls[u]) goto buk7; }
 goto buk8;
 buk7: h=0;
 for (w=0;w<MR-1; w++) {
 for (r=0; r<rbs; r++) {
 if (cw[l][w+1]==0) {
 if (w==0) goto buk8; else goto buk9;}
 if (cw[l][w]==vrs[r]) goto buk10;}
 buk10: vcr=vss[r];
   for (r=0; r<rbs; r++) if (cw[l][w+1]==vrs[r]) goto buk11;
 buk11: if (vcr<vss[r])  {
 h=1; vrr=cw[l][w]; vcr=sw[l][w];
 cw[l][w]=cw[l][w+1]; sw[l][w]=sw[l][w+1];
 cw[l][w+1]=vrr; sw[l][w+1]=vcr; }
 }
* buk9: if (h!=0) goto buk7;
* buk8:;  }
***********************************************************************/
 vov4: ;

 return;
 } /* end blvsr */
/*  gp1: ;
}
 */














