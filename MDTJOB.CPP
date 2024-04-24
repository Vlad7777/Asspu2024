			  /* mdtjob function */
#include <stdio.h>
#include <math.h>
#include "all_defi.h"

void mdtjob(int NR, int NS, int ip[], int jp[], int tn[], int tj[],
	    unsigned long ni[], int nt[], int res[], int tij[])

{
int i,t1,d1,j,d2;
unsigned long l,m,k;
for(i=0;i<NR;i++) {
t1=tj[jp[i]]-tj[ip[i]]; l=ni[i];
 m=ni[i+1];  /* was -1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
if((tn[l]==0)||(l==m)) {
tij[i]=tn[l]; goto td4; }
for(k=l;k<m;k++) {
d1=res[k]/100; if(nt[i]==d1) {
d1=tn[k]; goto td3; }}
td3: if(d1>t1) tij[i]=t1; else tij[i]=d1;
td4: ;   }
for(i=0;i<NR;i++) { d1=9999; /*проверь d1*/
k=ni[i];j=ni[i+1]; /*  was -1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
  for(l=k;l<j;l++) {
d2=tn[l]-tij[i]; d2=abs(d2); /*внимание!abs!*/
if(d2<d1) { d1=d2; t1=tn[l];nt[i]=res[l]/100;
m=l; }} if(d1==0) { tij[i]=t1; } else {
if(m==j) { tij[i]=t1; } else { if(tij[i]>tn[m]) {
tij[i]=t1; } else { tij[i]=tn[m+1];
nt[i]=res[m+1]/100; }}}}
td5:  ;
return ;
 }
