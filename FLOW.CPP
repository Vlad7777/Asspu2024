				  /* flow function */
//#include <owl\owlpch.h>
#include <stdio.h>
#include <io.h>
#include <alloc.h>
#include <stdlib.h>
#include "all_defi.h"
#include "PartUnit.h"

void bbod1f(int *pNR, int *pNS, int *pNY, int *ptdir, int ip[], int jp[],
		 int tn[], int tno[], int  res[], float cen[], int prior[],
		 char prs[], unsigned long ni[], int nt[], float q[],
		 float pot[], char zn[], int cod[], int gg[]);

void inda(int NR, int ip[], int jp[], int cod[], float q[], char zn[],
		 int rs[], char prs[]);
void indb(int NR, int NS, int ip[], int jp[], float pot[], float q[],
	  int cod[], char zn[], int rk[], int rs[], float cen[], char prs[]);
void mdtjob(int NR, int NS, int ip[], int jp[], int tn[], int tj[],
	  unsigned long ni[], int nt[], int res[], int tij[]);
void delta(int NR, int NS, int ip[], int jp[], int tn[], int tj[],
		 unsigned long ni[], int nt[], int res[], int rk[], int rs[],
		 float cen[], char prs[]);
void bibodfn(int  NR, int NS, int tdir, int ip[], int jp[], int tij[],
		 int tno[], int res[], int prior[], unsigned long ni[], int nt[],
		 int gg[]);

void __fastcall TPartForm::Flow(void)
{
#include "str_sset.cpp"
#include "str_fedi.cpp"
 struct sset s;
 struct fedi fe;
 long rKK7,rNR;
 long cl;
 unsigned long l,k,m;
 int i,d1,d2,j;
 int tdir,t1,NR,NS,NY;
// int end2;  /****   ext;   !!!!  ****/
 int *res  = new int[MY_KOLV];
 int *tn   = new int[MY_KOLV];
 int *tno  = new int[MY_KOLV];
 unsigned long *ni = new unsigned long[MY_KOLV];   // for TN, RES , TNO
 int *rk   = new int[MY_MXNR];
 int *rs   = new int[MY_MXNR];
 int *tij  = new int[MY_MXNR];
 int *prior= new int[MY_MXNR];
 int *tj   = new int[MY_MXNR];
 int *gg   = new int[MY_MXNR];
 int *nt   = new int[MY_MXNR];
 int *cod  = new int[MY_MXNR];
 int *ip   = new int[MY_MXNR];
 int *jp   = new int[MY_MXNR];
 char *prs = new char[MY_MXNR];
 char *zn  = new char[MY_MXNR];
 float *cen = new float[MY_MXNR];
 float *q   = new float[MY_MXNR];
 float *pot = new float[MY_MXNR];


//   printf ("  work  FLOW   \r\n");
//	printf("%c Начало оптимизации \r\n",BEEP);

bbod1f(&NR,&NS,&NY,&tdir,ip,jp,tn,tno,res,cen,prior,
	prs,ni,nt,q,pot,zn,cod,gg);
for(i=0;i<NR;i++) {  /* appendiks */
l=ni[i+1]-1; tij[i]=tn[l]; nt[i]=res[l]/100;}
for(j=0;j<NS;j++) tj[j]=0;
for(i=0; i<NR; i++) {
t1=tj[ip[i]]+tij[i]; if(t1>tj[jp[i]]) tj[jp[i]]=t1;}
for(i=0;i<NR;i++) {
l=ni[i];tij[i]=tn[l]; nt[i]=res[l]/100; }
for(j=0;j<NS;j++) tj[j]=0;
for(i=0;i<NR;i++) {
t1=tj[ip[i]]+tij[i];
if(t1>tj[jp[i]]) tj[jp[i]]=t1; }
fw2:
for(i=0;i<NR; i++) {
k=ni[i]; m=ni[i+1];  /*  was -1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
if((tn[k]==0)||(k==m-1)) {   /*   was k==m !!!!!!!!!!!!!!!!!!!!  */
d1=tn[k]; d2=d1; goto bd3; }
for(l=k;l<m;l++) {
d1=res[l]/100; if(nt[i]==d1) {
d1=tn[l]; d2=tn[l+1]; goto bd3; }}
bd3: rk[i]=d1+tj[ip[i]]-tj[jp[i]];
rs[i]=d2+ tj[ip[i]] - tj[jp[i]]; }
inda(NR,ip,jp,cod,q,zn,rs,prs);
if(prs[NS-1]=='*') {
mdtjob(NR,NS,ip,jp,tn,tj,ni,nt,res,tij);
for(i=0; i<NR;i++) {
if((res[ni[i]]==800)&&(tij[i]!=0)) goto kon;
k=ni[i]; m=ni[i+1]  /* was -1 !!!!!!!!!!!!!!! */ ;
for(l=k;l<m;l++) {
d1=res[l]/100;if(nt[i]==d1) {
tij[i]=tno[l]; goto kon; }}
kon: ; } /* end2=1;*/ /*ext!*/ goto itog; }
 indb (NR,NS,ip,jp,pot,q,cod,zn,rk,rs,cen,prs);  /* att!*/
delta(NR,NS,ip,jp,tn,tj,ni,nt,res,rk,rs,cen,prs);
if(tj[NS-1]>tdir) goto fw2;
mdtjob(NR,NS,ip,jp,tn,tj,ni,nt,res,tij);
for(i=0;i<NR;i++) {
if((res[ni[i]]==800)&&(tij[i]!=0)) goto obx;
k=ni[i]; m=ni[i+1] /* !!!!!!  was -1 !!!!!!!!!!!!! */ ;
for(l=k;l<m;l++) {
d1=res[l]/100; if(nt[i]==d1) {
tij[i]=tno[l];
 goto obx; }}
obx: ; }
itog: ;
bibodfn(NR,NS,tdir,ip,jp,tij,tno,res,prior,ni,nt,gg);
fw3: ;
return;
}

