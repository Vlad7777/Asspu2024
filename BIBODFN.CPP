		       /*bibodf function*/
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
 int dned(int iz1, int dNREM);

void bibodfn(int  NR, int NS, int tdir, int ip[], int jp[], int tij[],
	    int tno[], int res[], int rr[], unsigned long ni[], int nt[],
	    int gg[])
	    {
FILE  *lst, *fseti, *pflow, *primer;  // *pkrit,
#include "str_sset.cpp"
#include "str_fedi.cpp"
 struct sset s;
 struct fedi fe;
 long rKK7,rNR;
 long cl,R1,R2;
unsigned long d1,dd1,dd2;
int i,j;  //was ULong !!!!!!!!!!!!!!!!!!!!!
unsigned long il;
int dNREM,dKREM,kRR,lZ,fLAG=0;
int  end1, tkr; //end2,
long dmtpl,  mtpl;  // xxx1,
int www,rrr;
/*
int pms[MY_MXNR],tpl[MY_MXNR],tnr[MY_MXNR],tor[MY_MXNR],pnr[MY_MXNR],
	  axy[MY_MXNR],mij[MY_MXNR];
int axr[MY_MXNS],mj[MY_MXNS],dnr[MY_MXNS],dnp[MY_MXNS];
int vaxr[1],vdnr[1];
int ind5[MY_MXNR],ind6[MY_MXNR],ind7[MY_MXNR];
int qq5[REST],qq6[REST];
*/
 int *pms = new int [MY_MXNR];
 int *tpl = new int [MY_MXNR];
 int *tnr = new int [MY_MXNR];
 int *tor = new int [MY_MXNR];
 int *pnr = new int [MY_MXNR];
 int *axy = new int [MY_MXNR];
 int *mij = new int [MY_MXNR];
 int *axr = new int [MY_MXNS];
 int *mj  = new int [MY_MXNS];
 int *dnr = new int [MY_MXNS];
 int *dnp = new int [MY_MXNS];
 int *vaxr= new int [MY_MXNS];
 int *vdnr= new int [MY_MXNS];


 int *ind5= new int[MY_MXNR];
 int *ind6= new int[MY_MXNR];
 int *ind7= new int[MY_MXNR];
 int *qq5 = new int[MY_REST];
 int *qq6 = new int[MY_REST];


		fseti=  fopen(MY_NF0, "r+");

	 R1=MY_KK22; R2=MY_SZFSETI;
	 cl= R1*R2;    /*  KK22*SZFSETI;   */
	 fseek(fseti,cl,0);
	 for (i=0;i<MY_MXNR;i++){
	 fscanf(fseti,"%d %d ",&ind5[i],&ind6[i]);
	 }
	/* read ind,qq,ind7 */
  //printf (" kk24 !!!!!!!!!!!!  \n");
	  R1=MY_KK24;
	  cl= R1*R2;  /*  KK24*SZFSETI;  */
	fseek(fseti,cl,0);
	for (i=0;i<MY_REST;i++){
 /*  fscanf(fseti,"%d %d ",&qq5[i],&qq6[i]); */
	 }
//   printf (" kk25 !!!!!!!!!!!!  \n");
		R1=MY_KK25;
		cl=R1*R2;  /*  KK25*SZFSETI; */
	fseek(fseti,cl,0);
	for (i=0;i<MY_MXNR;i++){
	fscanf(fseti,"%d ",&ind7[i]);      }
//printf("Step1\r");
//getche();

/*************** for (i=0;i<REST;i++) printf(" %d ",qq5[i]);************/
		 cl=MY_KK00;
		 fseek(fseti,cl,0);
	#include "sscffedi.cpp"
//printf("Step2\r");
//getche();

 lZ=0; /*fLAG=1;*/ kRR=0;    dNREM=fe.dr;  dKREM=fe.dkr;
for(i=0;i<NR;i++) tij[i]=tij[i]*gg[i];
/* for(i=0;i<NR;i++) rr[i]=prior[i]; */
   dmtpl=0;

for(i=0;i<NR;i++) {
if(nt[i]<=2) pms[i]=10;
if((nt[i]>2)&&(nt[i]<=5)) pms[i]=11;
if(nt[i]>5) pms[i]=111;}
//printf("Step3\r");
//getche();

//printf("Точная оптимизация\r");
//getche();
  pflow =fopen(MY_PF,"w");
//  pkrit= fopen(PK,"w");
  fprintf(pflow,"точная оптимизация\n");
bgn1: www=1; // xxx1=0;
    /*  temporary !!! write file rr,pms,tij,dnrem,dkrem  */
 /************************************************************************/
//   printf("Write file for primer ? 0-Yes,1- No\n");
//   getche();
    www=1; rrr=1;
  /*   scanf("%d",&www);  !!!!!!!!!!!!!!!!!! */
     if (www==0) {
       primer= fopen("fprimer.f", "w");
   for(i=0;i<NR;i++) {
    fprintf(primer,"%d %d %d %d\n",i,tij[i],rr[i],pms[i]);}
      fclose(primer);
     }
//    printf("Read file for primer ? 0-Yes,1-No\n");
  /*   scanf("%d",&rrr);  !!!!!!!!!!!!!!!!!!!!!  */
     if (rrr==0) {
      primer= fopen("fprimer.f", "r");
   for(i=0;i<NR;i++) {
    fscanf(primer,"%d %d %d %d\n",&i,&tij[i],&rr[i],&pms[i]); }
     fclose(primer);
    }
/**************************************************************************/
   /*call valera*/
//#include "valera.c"

  #include "valerc.cpp" //  for KurAES   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//       Kurskaya AES
// printf("axr[NS-1]=%d \r\n",axr[NS-1]);
// getche();
if(axr[NS-1]<=tdir) goto fw9;

mtpl=99999; for(i=0;i<NR;i++) {
if((mtpl>tpl[i])&&(tij[i]!=0)) mtpl=tpl[i]; }
//  printf("mtpl=%d \r\n",mtpl);
// getche();

for(i=0;i<NR;i++) {  /*1-й просмотр */
// printf("tpl=%d\r\n",tpl[i]);

if(tpl[i]<=mtpl+dmtpl+3) {  /* att!dmtpl+3*//*раб.отр.зоны*/
if(tij[i]==0) goto iis;   /*fic.job*/
if((res[ni[i]]==800)&&(tij[i]!=0)) goto iis; /*ожидание*/
if(ni[i]==ni[i+1] /* !!!!! -1 ???????????!!!!! */ ) goto iis;  /* one point */
for(il=ni[i];il<ni[i+1]-1 /* was -2 !!!!!!!!!! */;il++) {
d1=res[il]/100;
if(nt[i]==d1) {
//xxx1=1;
//  printf("iteracia i= %d \r\n",i);
//  getche();

dd1=tij[i];end1=nt[i];dd2=pms[i];
tij[i]=tno[il+1];  /*new duration*/
nt[i]=res[il+1]/100; goto jj3; }}
goto iis;
jj3: if(nt[i]<3) pms[i]=10;
if((nt[i]>2)&&(nt[i]<6)) pms[i]=11;
if(nt[i]>5) pms[i]=111;
if((tij[i]>dd1)&&(pms[i]==dd2)) {
// printf("увеличение Тij \r\n");
// getche();

tij[i]=dd1; nt[i]=end1; pms[i]=dd2; goto iis; }
for(j=0;j<NR;j++) { tnr[j]=1;tor[j]=1;
pnr[j]=0; axy[j]=0; }
for(j=0;j<NS;j++) {
axr[j]=1; mj[j]=tdir; dnr[j]=0; dnp[j]=0; }
lZ=0; dnr[0]=dNREM;kRR=0;

//printf("Step3\r");
//getche();

	  /* call early */
early(NS,NR,lZ,dNREM,tij,tnr,tor,axy,rr,axr,pms,qq5,dnr,ip,jp,vaxr,vdnr,kRR);

if(axr[NS-1]<=tdir) goto fw9; }
iis: ;}

//printf("Step4\r");
//getche();

// printf("dmtpl=%d \r\n",dmtpl);
if((mtpl<0)&&(abs(mtpl)>=dmtpl))   {
dmtpl=dmtpl+8; goto bgn1; }

//printf("Step5\r");
//getche();


dmtpl=0;
bgn2:// xxx1=0;
/*call valera*/
//  #include "valera.c"
 #include "valerc.cpp" //  for KurAES
mtpl=9999; for(i=0;i<NR;i++) {
if((mtpl>tpl[i])&&(tij[i]!=0))mtpl=tpl[i]; }
// printf("mtpl2=%d\n",mtpl);
for(i=0;i<NR;i++)  {  /*2-й просмотр*/
if(tpl[i]<=(mtpl+dmtpl)) {  /* jobs negative sone */
if((res[ni[i]]==800)&&(tij[i]!=0)) goto vis; /*ожидание*/
if(tij[i]==0) goto vis;  /*fix.job*/
if(rr[i]==7) goto vis;
rr[i]=rr[i]+1;
// printf("i=%\n",i);
//xxx1=1;
for(j=0;j<NR;j++) { tnr[j]=1;tor[j]=1;pnr[j]=0;axr[j]=1; }
for(j=0;j<NS;j++) { axr[j]=1;mj[j]=tdir;
dnr[j]=0;dnp[j]=0; }
lZ=0; dnr[0]=dNREM; kRR=0;
	  /* call early */
		 /*	  early(NS,NR,LZ,DNREM,tij,tnr,tor,axy,rr,axr,pms,qq5,
			dnr,ip,jp,vaxr,vdnr);       */
 early(NS,NR,lZ,dNREM,tij,tnr,tor,axy,rr,axr,pms,qq5,dnr,ip,jp,vaxr,vdnr,kRR);
if(axr[NS-1]<=tdir) goto fw9;
vis: ; }}
if((mtpl<0)&&(abs(mtpl)>=dmtpl)) {
dmtpl=dmtpl+8; goto bgn2; }
/* valera: proe;
	end valera;  */
//printf("достигнут минимальный критический путь=%d\r",tdir);
fprintf(pflow,"достигнут минимальный критический путь=%d\n",tdir);
 for(i=0;i<NS;i++) {
 dnp[i]=dnr[NS-1]; mj[i]=axr[NS-1]; }
 goto fw10; // Bypass for minimal critical path !!!!!!!!!!!!!!!
		 // Data of complet is anything !!!!!!!!!!!!!!!!
fw9: for(i=0;i<NS;i++) {
// dnp[i]=dnr[NS-1]; mj[i]=axr[NS-1]; }
//  for KuAES  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  mj[i]= tdir; dnp[i]=dKREM;}

fw10:
	  maxtim(NS,NR,lZ,dNREM,tij,axy,mj,mij,dnp,qq5,rr,pms,ip,jp,pnr);
		 //    or dKREM !!!!!!!!!!!!???????????
	  /* call polres*/
		polres(NS,NR,lZ,dNREM,tij,tpl,pnr,tnr,rr,pms,ind5,ind6,ind7,fLAG);
		  fprintf(pflow,"      j       axr        mj           ");
  //	   printf("dnr    dnp");
	  fprintf(pflow,"dnr      dnp\n");
			 for(j=0;j<NS;j++) {
	  fprintf(pflow,"%9d %9d %9d %9d %9d\n",j,axr[j],mj[j],dnr[j],dnp[j]);
	  /*printf("%9d %9d %9d %9d %9d\n",j,axr[j],mj[j],dnr[j],dnp[j]);  */
			}
// end2=1; /*indicator*/
/*cl=kk7*/
		for(j=0;j<NR;j++)       axy[j] =  tpl[j];     // ADD !!!
fLAG=1;
	polres(NS,NR,lZ,dNREM,tij,tpl,pnr,tnr,rr,pms,ind5,ind6,ind7,fLAG);
/***************************************************************************/
/* write axr,mj     !!!!!!!!     for     plotter !!!                       */
/***************************************************************************/
		/* вывод результатов */
//	  printf("%c окончание оптимизации\r",BEEP);
//	 printf("results of deside network\r");
//	 printf("      i=    tij    tnr    tor      pnr         tpl");
//	 printf("    rr     pms\r");
//		for(i=0;i<NR;i++) {
//	 printf("%9d %9d %9d %9d %9d %9d %9d\r",
//		i,tij[i],tnr[i],tor[i],pnr[i],tpl[i],rr[i],pms[i]);
//		}
//	 printf("      j       axr       mj         ");
//		printf("dnr    dnp\r");
//			 for(j=0;j<NS;j++) {
//	 printf("%9d %9d %9d %9d %9d\r",j,axr[j],mj[j],dnr[j],dnp[j]);
//		  }
//	 printf(" PRIMER завершил работу\r");
/***************************************************************************/

	  R1=MY_KK7;  R2= MY_SZFSETI;
rKK7= R1*R2;     /* KK7*SZFSETI;  */
R1=NR;
rNR=R1 * R2;    /*  NR*SZFSETI;  */
	i=0;
/*read fseti into sset*/
		for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
		fseek(fseti,cl,0);
		 #include "sscfsset.cpp"
s.a14=nt[i]; s.a15=tij[i]; s.a22=tnr[i]; s.a23=tor[i];
s.a24=tpl[i];
s.a16= axy[i];
s.a17=tpl[i]; s.a18=tpl[i];
s.a26=rr[i]; s.a28=pms[i];
for (j=0;j<MY_MR;j++ )     s.a30[j]=s.a10[j];
if((nt[i]==0)||(nt[i]==3)||(nt[i]==6)) for(j=0;j<MY_MR;j++ ) s.a31[j]=s.a11[j];
if((nt[i]==1)||(nt[i]==4)||(nt[i]==7)) for (j=0;j<MY_MR;j++ )s.a31[j]=s.a13[j];
if((nt[i]==2)||(nt[i]==5)||(nt[i]==8)) for (j=0;j<MY_MR;j++ )s.a31[j]=s.a12[j];
  /*rewrite fseti from sset*/
		fseek(fseti,cl,0);
	  #include "sprfsset.cpp"
		 i++;
		 }
tkr=tdir;
/*cl=0 read fseti(FEDI)*/

fe.tdir=tkr; fe.kn=tkr;
/*rewrite fseti(FEDI)*/
		 cl=MY_KK00;
		 fseek(fseti,cl,0);
  #include "sprffedi.cpp"


//printf("результат оптимизации по длительности простоя\r");
//printf("критическое время=%d\r",axr[NS-1]);
//printf("директивное время=%d\r",tkr);
//printf("-pi--pj-------tij---alf--");
//printf("--tpl--tsv--nt---personal-------------rr--pms--pnr\r");
fprintf(pflow,"результат оптимизации по длительности простоя\n");
fprintf(pflow,"критическое время=%d\n",axr[NS-1]);
fprintf(pflow,"директивное время=%d\n",tkr);
fprintf(pflow,"-pi--pj-------tij---alf--");
fprintf(pflow,"--tpl--tsv--nt---personal-------------rr--pms--pnr\n");
/* read file fseti */
	  i=0;

		for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
		fseek(fseti,cl,0);
		 #include "sscfsset.cpp"
//printf("%5ld %5ld %5d %5d %5d %5d %2d %2d %2d",
//s.a1,s.a2,s.a15,s.a22,s.a24,s.a25,s.a14,s.a30[0],s.a30[1]);
//printf("%2d %2d %2d %2d %2d %2d %2d %5d %5d\r",
//s.a30[2],s.a30[3],s.a31[0],s.a31[1],s.a31[2],s.a31[3],s.a26,s.a28,pnr[i]);
fprintf(pflow,"%5ld %5ld %5d %5d %5d %5d %2d %2d %2d",
s.a1,s.a2,s.a15,s.a22,s.a24,s.a25,s.a14,s.a30[0],s.a30[1]);
fprintf(pflow,"%2d %2d %2d %2d %2d %2d %2d %5d %5d\n",
s.a30[2],s.a30[3],s.a31[0],s.a31[1],s.a31[2],s.a31[3],s.a26,s.a28,pnr[i]);

i++; }
//printf("*******************************************************************");
fclose(fseti);
fclose(pflow);
// printf("%c окончание FLOW \r",BEEP);
 delete[] res;

 delete[] pms;
 delete[] tpl;
 delete[] tnr;
 delete[] tor;
 delete[] pnr;
 delete[] axy;
 delete[] mij;
 delete[] axr;
 delete[] mj;
 delete[] dnr;
 delete[] dnp,
 delete[] vaxr;
 delete[] vdnr;
 delete[] ind5;
 delete[] ind6;
 delete[] ind7;
 delete[] qq5;
 delete[] qq6;

return ;
}


