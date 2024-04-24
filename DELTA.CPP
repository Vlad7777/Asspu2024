	      /* delta function */
#include <stdio.h>
#include "all_defi.h"
/*  #define KOLV 15000   NR*8           NOW  80000 !!!!!!  */

void delta(int NR, int NS, int ip[], int jp[], int tn[], int tj[],
		 unsigned long ni[], int nt[], int res[], int rk[], int rs[],
		 float cen[], char prs[])
	 {
int j,i,dlt,d1,t2,d2,ii,t1;
unsigned long l;
float cen1,cen2;
//  #include "defwind.cpp"
dlt=9999; for(i=0;i<NR;i++) {
if(prs[ip[i]]!='*') goto del2;
if((rk[i]<0)||(rs[i]<0)) {  /* проверь !!! */
if(prs[jp[i]]=='*') goto del3; }
else goto del3; /* проверь? */
if(rk[i]>=0) goto del5;  /* посм. всю логику! */
if(dlt>-rk[i]) {
dlt=-rk[i];/*m=i;*/ }
del5: if(rs[i]>=0) goto del3;
if(dlt>-rs[i]) {
dlt=-rs[i];/*m=i;*/ } goto del3;
del2: if(rk[i]<=0) goto del3;
if(prs[jp[i]]!='*') goto del3;
if(dlt>rk[i]) dlt=rk[i];
del3: ; }
for(j=1;j<NS;j++) {   /* j=1! */
if (prs[j]!='*') tj[j]=tj[j]-dlt;}
for(j=0;j<NS;j++) prs[j]=' ';
// printf("критический путь=%d\r",tj[NS-1]);
for(i=0;i<NR;i++) {
if((tn[ni[i]]==0)||(ni[i]==ni[i+1]-1)||(ni[i]==ni[i+1]-2))
goto jj4; t1=tj[jp[i]]-tj[ip[i]];
for(l=ni[i];l<ni[i+1]-1;l++) { /* будь внимателен с l!*/
d1=res[l]/100;
if(nt[i]==d1) {
if(l==ni[i+1]-2) goto jj4; d1=tn[l+1];goto jj3; }}
jj3: if(t1==d1) {
l=l+1;nt[i]=res[l]/100;  /*rper=rper+1?*/
cen2=res[l]-nt[i]*100; l=l+1; t2=res[l]/100;
if(t2>2) {d2=10; ii=10; }
else {d2=1; ii=0; };
if(t2>5) {d2=100;ii=100; }
cen1=res[l]-t2*100; t2=tn[l];
if(d1==t2) { cen[i]=99999; }
else {
cen[i]=(cen1-cen2)/(d1-t2);
cen[i]=cen[i]*d2+ii; }}
jj4: ; }
return ;
}
