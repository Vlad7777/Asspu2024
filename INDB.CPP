		       /* indb function */
#include <stdio.h>
#include <conio.h>

void indb(int NR, int NS, int ip[], int jp[], float pot[], float q[],
int cod[], char zn[], int rk[], int rs[], float cen[], char prs[])

{
int rb,rj,i,f,j;
float rq;
//  #include "defwind.c"
fw1:;
prs[0]='*'; cod[0]=0; q[0]=99999; ib2: f=0;
for(i=0;i<NR;i++) {
if(rk[i]!=0) goto ib3;
if(prs[ip[i]]=='*') goto ib4;
else goto ib5;
ib4: if(pot[i]<cen[i]) rq=q[ip[i]];
else goto ib3;
if(prs[jp[i]]=='*') goto ib1;
f=1; prs[jp[i]]='*'; zn[jp[i]]='+'; cod[jp[i]]=ip[i];
j=jp[i];
if(rq>(cen[i]-pot[i])) q[j]=cen[i]-pot[i];
else q[j]=rq; goto ib1;
ib5: if(pot[i]>0) rj=ip[i];else goto ib1;
if(prs[jp[i]]!='*') goto ib1;
f=1; prs[rj]='*'; zn[rj]='-';
cod[rj]=jp[i];
if(q[jp[i]]>pot[i]) q[rj]=pot[i];
else q[rj]=q[jp[i]]; goto ib1;
ib3: if (rs[i]!=0) goto ib1;
if (prs[ip[i]]=='*') rq=q[ip[i]];
else goto ib9;
if (prs[jp[i]]=='*' ) goto ib1;
f=1; j=jp[i]; prs[j]='*';
zn[j]='+'; cod[j]=ip[i];q[j]=rq; goto ib1;

ib9: if(pot[i]>cen[i]) rj=ip[i];
else goto ib1;
if( prs[jp[i]]!='*') goto ib1;
f=1; prs[rj]='*'; zn[rj]='-'; cod[rj]=jp[i];
j=jp[i];
if(q[j]>(pot[i]-cen[i])) q[rj]=pot[i]-cen[i];
else q[rj]=q[j]; ib1: ; }
if(prs[NS-1]=='*') goto ib12;
if(f==1) goto ib2;
ib12:
if(prs[NS-1]=='*') {
for(i=NR-1;i>=0;i--) {
if((jp[i]==(NS-1))&&(ip[i]==cod[NS-1])) goto iz1; }
 /* ошибка */ printf("ошибка INDB\r"); /*  exit(1); !!!!!!!!!!!!!!!!!!!! */
iz1: pot[i]=pot[i]+q[NS-1]; rb=ip[i]; rq=q[NS-1];
iz2: if(zn[rb]=='+') {
for(i=NR-1;i>=0;i--) {
if((cod[rb]==ip[i])&&(rb==jp[i])) goto iz4;}
iz4: pot[i]=pot[i]+rq; rb=ip[i]; }
else {
for(i=NR-1;i>0;i--) {
if((cod[rb]==jp[i])&&(rb==ip[i])) goto iz5; }
iz5: pot[i]=pot[i]-rq; rb=jp[i]; }
if(ip[i]!=0) /*attention1!!!*/ goto iz2;      /* ??????????????  =1 ????*/
for(j=0;j<NS;j++) prs[j]=' ';
goto fw1; }
return ;
}