
	    /* bbod1f function */
#include "all_defi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <alloc.h>

void bbod1f(int *pNR, int *pNS, int *pNY, int *ptdir, int ip[], int jp[],
		 int tn[], int tno[], int  res[], float cen[], int prior[],
		 char prs[], unsigned long ni[], int nt[], float q[],
		 float pot[], char zn[], int cod[], int gg[])
		{
//////////////Debug//////////////////////////////////
//	FILE *stream;
//	stream = fopen("DUMMY.FIL", "w+");

//  	int tnR[KOLV];
//	tn = &tnR[0];
////////////////////////////////////////////////////
  FILE  *fseti;
  #include "str_sset.cpp"
  #include "str_fedi.cpp"
  struct sset s;
  struct fedi fe;
  long rKK7,rNR;
  long cl,R1,R2;
float zona,rq,rq1,cen1;
double to,d8=8,d16=16,cen2;
int i,j,k,jj,jr,n;
////////////////////////////////////////////////////////////////
//unsigned long l;            So WAS !!!!!!!!!!!!!!!!!!!!
////////////////////////////////////////////////////////////////
int l;
int rb,r1,r2,r3,rj;
int NR,NS,NY,tdir;
/* int brig[KOLUZ],rbrig[KOLUZ];  */
		 /*  str_uzl     */
 /*
	 int kry[KOLU];
	float pzona[KOLU];
	 int rry[KOLU];
 */
 long *pkj; // pkj[MXNS];
 int *kry;
 float *pzona;
 int *rry;
/**char    sry[KOLU][TXTUS];  *************************
	char    pry[KOLU][TXTU];     **********************************/
int kvd5,kvd6;
int d1,t1,d2,t2;
double min,opt,max,d;
int a1,a2;
	 if ((pkj = (long *) malloc(MY_MXNS * 4)) == NULL)
	{
//      cprintf("Недостаточно XMS памяти для размещения буфера - pkj \r\n");
		exit(1);  /* terminate program if out of memory */
	}

	 if ((kry = (int *) malloc(MY_KOLU * 2)) == NULL)
	{
 //     cprintf("Недостаточно XMS памяти для размещения буфера - pkj \r\n");
		exit(1);  /* terminate program if out of memory */
	}

	 if ((pzona = (float *) malloc(MY_KOLU * 4)) == NULL)
	{
  //    cprintf("Недостаточно XMS памяти для размещения буфера - pzona \r\n");
		exit(1);  /* terminate program if out of memory */
	}

	if ((rry = (int *) malloc(MY_KOLU * 2)) == NULL)
	{
  //    cprintf("Недостаточно XMS памяти для размещения буфера - rry \r\n");
		exit(1);  /* terminate program if out of memory */
	}

//   #include "defwind.cpp"
  //	cprintf (" work BBOD1F  \r");
	fseti= fopen(MY_NF0,"r+");
	  R1=MY_KK7;  R2=MY_SZFSETI;
		rKK7= R1*R2; /*  KK7*SZFSETI;  */
//	 getche();
		 cl=0;
		 fseek(fseti,cl,0);
	#include "sscffedi.cpp"
  NR= fe.nr;  NS= fe.ns;   tdir=fe.kn;  /*  fe.tdir; */
  NY=fe.ny;   kvd5=fe.kvd5; kvd6=fe.kvd6;
  *pNR=NR; *pNS=NS; *ptdir=tdir;
		R1=NR;
		rNR=R1*R2; /*  NR*SZFSETI;    */

//   cprintf ("work 1");
//   getche();

 /* SENI  */
  R1=MY_KK1;
 cl=R1*R2;  /*  KK1*SZFSETI;  */
 fseek(fseti,cl,0);
 for (k=0;k<NS;k++) {
// cprintf("for1\r ");
// getche();
fscanf(fseti,"%ld",(pkj+k));
// *(pkj+k)=(long) k;
// cprintf("pkj[k]= %ld ",*(pkj+k));
 }

//	 getche();

for(i=0;i<NR;i++) gg[i]=1;
zona=  0.0;       /*  !!!!!!!!!!!!!!!!!!!  VAR !!!!!!!!!!!!!!! */
 t1=0;t2=0;cen1=0;cen2=0;
for(l=0;l<MY_KOLV;l++) {tn[l]=0;tno[l]=0;res[l]=0; }
fw3: i=0;l=0;for(k=0;k<NR;k++) ni[k]=0;
//	 getche();
	 /*    yzl    */
//  cprintf("\n   ремонтируемые узлы - \n");/***************/
	R1=MY_KK9;
	cl=R1* R2; /*  KK9*SZFSETI; */
	fseek(fseti,cl,0);

		for (i=0; i<NY; i++)  {

	 fscanf (fseti,"%d %f %d ",
	 &kry[i],&pzona[i],&rry[i]);
//   cprintf ("kry[i]= %d \n",kry[i]);
//    cprintf ("pzona[i]= %f \n",pzona[i]);
//   cprintf ("rry[i]= %d \n",rry[i]);


	if (kry[i]== MY_EOFU) {
	  NY=i; goto m53; }
	 }
 m53: ;
  //	 getche();
		*pNY=NY;
		 /* read file f.seti */
		i=0; l=0;
		for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
		fseek(fseti,cl,0);
		 #include "sscfsset.cpp"
////////////////////////////////////
//	  fprintf(stream," i = %d s.a1= %ld   s.a2= %ld \n", i, s.a1,s.a2);
/////////////////////////////////////////////
	  prior[i]=s.a26;
for(j=0;j<NS;j++) {
if(s.a1==pkj[j]) { ip[i]=j; goto fw5; }}
fw5: for(j=0;j<NS;j++) {
if(s.a2==pkj[j]) { jp[i]=j; goto fw6; }}
fw6: rb=s.a6+s.a8-s.a7; r1=0;r2=0;r3=0;
for(k=0;k<MY_MR;k++) {
if(s.a10[k]==0) goto fw00;
r1=r1+s.a11[k]; r2=r2+s.a13[k]; r3=r3+s.a12[k]; }
fw00: d1=r1+r2+r3;
/* cprintf("d1=%d \n",d1); */
if(rb<=0) {
cen[i]=0;ni[i]=l;res[l]=0;tn[l]=0;tno[l]=0;
if(d1!=0) {
tno[l]=0;tn[l]=0;l=l+1; goto bnd; }
if(s.a5==4) {
cen[i]=0;ni[i]=l;tn[l]=0;tno[l]=0;
res[l]=0; l=l+1; goto bnd; }
/////////////////////////// Think ////////////////////////////////////
/*
 a1=s.a1/100;  a2=s.a2/100; // временно выд. код узла
if((a1==0)&&(a2!=0)) { // связь с под. раб.
for(jj=0;jj<NY;jj++) {     // was error   Unit no a2 !!!!!!!
if(a2==kry[jj]) {
if((rb<=0)&&(d1==0)) gg[i]=0;
if(rry[jj]==5) tn[l]=kvd5*24;
if(rry[jj]==6) tn[l]=kvd6*24;
// cprintf(" a1= %d  a2= %d  tn[l]= %d\n",a1,a2,tn[l]);
res[l]=800; l=l+1; goto bnd;
}}}
*/
//////////////////////////////////////////////////////////////////////////
res[l]=800; tno[l]=s.a15;
tn[l]=s.a15; l=l+1; goto bnd;  }
  a1=s.a1/100;  a2=s.a2/100; /* temp. kod uzla */
for(k=0;k<NY;k++) {
if(kry[k]==-1) { zona=0; goto fw8; }
if((kry[k]==a1)&&(kry[k]==a2)) {
zona=pzona[k]/100; goto fw8; }}
////////////////////////////////////////////////////////////////
fw8:         zona = 0 ;  // Temporary !!!!!!!!!!!!!!!!!!
////////////////////////////////////////////////////////////////
if(r1!=0) { cen2=rb/r1;  min=cen2;    min=floor(cen2);
if(min==0) min=1; min=min+zona*min; }
if(r2!=0) { cen2=rb/r2;  opt=cen2;    opt=floor(cen2);
if(opt==0) opt=1; opt=opt+zona*opt; }
if(r3!=0) { cen2=rb/r3;  max=cen2;   max=floor(cen2);
if(max==0) max=1; max=max+zona*max; }
fw0:
if(s.a29==3) goto ab1;
if(r1!=0) {
res[l]=r1;tno[l]=min;to=min;t1=min/8;
 d=fmod(to,d8);
if(d==0) tn[l]=t1*16+min;
else tn[l]=t1*16+min+8;tn[l]=tn[l]+16;
if(ni[i]==0) { ni[i]=l;
if(tn[l]==0) {
tn[l]=1;tno[l]=1;l=l+1;
goto fw4; }}
 l=l+1; }
if(r2!=0) {
res[l]=r2+100; tno[l]=opt; t1=opt/8; to=opt;
 d=fmod(to,d8);
 if(d==0) tn[l]=t1*16+opt;
else tn[l]=t1*16+opt+8; tn[l]=tn[l]+16;
if(ni[i]==0) { /* ni[i]=l; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    */
if (tn[l]==0) {tn[l]=1; tno[l]=1; l=l+1 ;
 goto fw4; }}
  if (tn[l]==0) goto fw4;
if(tn[l]!=tn[l-1]) l=l+1; }
if(r3!=0) {
res[l]=r3+200; tno[l]=max;to=max;t1=max/8;
  d=fmod(to,d8);
 if(d==0) tn[l]=t1*16+max;
else tn[l]=t1*16+max+8;
tn[l]=tn[l]+16;
if(ni[i]==0) {
/*  ni[i]=l; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
  if(tn[l]==0) {
tn[l]=1; tno[l]=1; l=l+1; goto fw4; }}
if(tn[l]==0) goto fw4;
if(tn[l]!=tn[l-1]) l=l+1; }
if(s.a29==1) goto fw4;  /* 010 */
if(r2!=0) {
res[l]=2*r2+400; tno[l]=opt; to=opt; t1=opt/16;
 d=fmod(to,d16);
 if(d==0)  tn[l]=t1*8+opt;
else tn[l]=t1*8+opt+8;
tn[l]=tn[l]+8;
if(tn[l]==0) goto fw4;
if(tn[l]!=tn[l-1]) l=l+1; }
if(r3!=0) {
res[l]=2*r3+500;tno[l]=max;to=max;t1=max/16;
  d=fmod(to,d16);
if(d==0) tn[l]=t1*8+max; else tn[l]=t1*8+max+8;
tn[l]=tn[l]+8;
if(tn[l]==0) goto fw4;
if(tn[l]!=tn[l-1]) l=l+1; }
if(s.a29==2) goto fw4;
ab1:
if(r2!=0) {
res[l]=3*r2+700; tn[l]=opt;tno[l]=opt;
if ((ni[i]==0)&&(s.a29==3)) { ni[i]=l;
if(tn[l]==0) { tno[l]=1; tn[l]=1; l=l+1; goto fw4; }
goto ab3; }
if(tn[l]==0) goto fw4;
if(tn[l]!=tn[l-1]) l=l+1; }
ab3:
if(r3!=0) {
res[l]=3*r3+800; tn[l]=max; tno[l]=max;
if(tn[l]==0) goto fw4;
if(tn[l]!=tn[l-1]) l=l+1; }
fw4: n=0;
k=ni[i]; if(k==l-1) goto bnd;
ab:
/***************************************************************************/
// cprintf("Iteration \r ");
// getche();
 goto bnd;
 /*************** BYPASS !!!!*******************************************/
	 t1=tn[k]; d1=res[k]/100; cen1=res[k]-d1*100;
rq1=99999; for(j=k+1;j<l-1;j++) { /*att!j<l-2*/
d2=res[j]/100; d1=res[j]-d2*100;
if(t1==tn[j]) goto bnd;
rq=(d1-cen1)/(t1-tn[j]); if(rq1>(rq*1.01)) {
rq1=rq; rj=j; }}
n=rj-k-1; for(j=k+1;j<l-1;j++) {/*att.l-2*/
tno[j]=tno[j+n]; tn[j]=tn[j+n]; res[j]=res[j+n]; }
l=l-n;k=k+1;
if(k==l-1)/*or l-2?????????????????*/ goto bnd;else goto ab;
/////////////////////////////////////////////////////////////////////////
bnd:;
 i++;  }
	  /*i=i+1; cnd; *pseti */
i=ni[NR-1]+1;
for(l=i;l<MY_KOLV;l++) { if(tn[l]==0) goto fw7; }
fw7: ni[NR]=l;  /*att!NR*/
for(i=0;i<NR;i++) { l=ni[i];
///////////////////////////////////
//  fprintf(stream, "i=%d l=%d  tn[l]=%d  tno[l]=%d  res[l]=%d \n",i,l,tn[l],tno[l], res[l]);
/////////////////////////////////////////
if((tn[l]==0)||(res[l]==0)) {
nt[i]=0; goto sli; }
if((tn[l]!=0)&&(res[l]==800)) {
nt[i]=8; goto sli; }
t1=tn[l]; nt[i]=res[l]/100;
if((l+1==ni[i+1])&&(res[l]!=0))   {
cen[i]=99999; /*att!*/ goto sli; }
cen2=res[l]-nt[i]*100; t2=res[l+1]/100;
cen1=res[l+1]-t2*100; t2=tn[l+1];
if(t1==t2) cen[i]=99999; else cen[i]=(cen1-cen2)/(t1-t2);
sli: ;
  }
avar: ;
/////////////////////////////////////////////////////
//	for(l=0;l<ni[NR];l++)
// fprintf(stream, " l= %d  ni[l]= %d  tn[l]= %d tno[l]= %d res[l]= %d  \n",l,ni[l],tn[l],tno[l],res[l]);
/////////////////////////////////////////////////////
// for(i=0;i<NR;i++)
// cprintf("i= %d ni= %d cen= %f \r\n",i,ni[i],cen[i]);
	 /*bbod2f*/
for(jj=0;jj<NS;jj++) {
 prs[jj]=' ';
 zn[jj]=' ';
 cod[jj]=0;
 q[jj]=0;
 }
for(i=0;i<NR;i++) pot[i]=0;
fclose(fseti);
return ;
}


















































