
#include "kalenp.cpp"
//  #include "dned.c"
#include "all_defi.h"
#include "conio.h"

void kalenp(int ix1, int ix2, int ix3, int *piy1, int *piy2);
 int dned(int iz1, int dNREM);

void maxtim(int NS, int NR, int lZ, int dNREM, int tij[], int axy[], int mj[],
	    int mij[], int dnp[], int qq5[], int rr[], int rms[], int ip[],
	    int jp[], int pnr[])
{
int i,iq,jq;
int ix1,ix2,ix3,xx,xa,iz1,iz6,iy2,iy1,xa1;
int ipnr,dpnr,pnr2,dlt,jd1,jd2,jd3;

// #include "defwind.c"

   for(i=0;i<MY_REST;i++) qq5[i]=0; /*  TEMPORARY!!!!!!!!!!!!!!!!! */
	 for(i=0;i<NS;i++) mij[i]=0;
	 for(i=NR-1;i>=0;i--){
	 ix3=rr[i];
	 if(tij[i]==0){
	 if(mj[jp[i]]<mj[ip[i]]) {
	 mj[ip[i]]=mj[jp[i]];
	 dnp[ip[i]]=dnp[jp[i]];}
	 pnr[i]=mj[jp[i]];goto ms3;}
	 pnr[i]=mj[jp[i]]; ix1=dnp[jp[i]]; ix3=rr[i];
 /*****	cprintf(" mj[ip[i]]=%d dnp[ip[i]]=%d pnr[i]=%d mij[ip[i]=%d \n",
	   mj[ip[i]],dnp[ip[i]],pnr[i],mij[ip[i]]); ************************/
	 if((mij[jp[i]]==1)||(mj[jp[i]]!=mj[NS-1])){
	 pnr[i]=pnr[i]-1; ix3=rr[i];
	 xx=(pnr[i]+7)/8; xa=xx/3;xx=xx-xa*3;
	 ipnr=(pnr[i]-1)/24;
	 dpnr=pnr[i]-ipnr*24;
	 if(rms[i]==111){
	 if(dpnr==24){
	 if(ix1==1) ix1=7; else ix1=ix1-1;
	 }}
	 if(rms[i]==10){
	 if(dpnr<9){
	 pnr[i]=pnr[i]-dpnr-8;
	 if(ix1==1) ix1=7;  else  ix1=ix1-1; }
	 if(dpnr>16&&dpnr<25){
	 pnr[i]=pnr[i]-dpnr+16;
	 if(dpnr==24){
	 if(ix1==1) ix1=7; else ix1=ix1-1;}}}
	   if(rms[i]==11){
	   if(dpnr<9){ pnr[i]=pnr[i]-dpnr;
	   if(ix1==1) ix1=7; else ix1=ix1-1; }}
	   }
	   else {
	   ipnr=(pnr[i]-1)/24; dpnr=pnr[i]-ipnr*24;
	   xx=(mj[jp[i]]+7)/8; xa=xx/3; xx=xx-xa*3;}
	   ipnr=(pnr[i]-1)/24;  dpnr=pnr[i]-ipnr*24;
ms5:
	   if(ix3==6&&ix1==7){
	   pnr[i]=pnr[i]-dpnr; if(rms[i]==10) pnr[i]=pnr[i]-8;
	   ix1=6;  goto ms4;}
	   if(ix3==5&&ix1==7){
	   pnr[i]=pnr[i]-24-dpnr; if(rms[i]==10) pnr[i]=pnr[i]-8;
	   ix1=5; goto ms4;}
	   if(ix3==5&&ix1==6) {
	   pnr[i]=pnr[i]-dpnr; if(rms[i]==10) pnr[i]=pnr[i]-8;
	   ix1=5; goto ms4;}
ms4:  if(axy[i]!=0) {
   //	   if(mij[ip[i]]>axy[i]){      ///!!!! WAS  ERROR  !!!!
	   if(mj[ip[i]]>axy[i]){     // 10.12.1993 !!!!!!!!!
	   mj[ip[i]]=axy[i]; iz1=(axy[i]+23)/24;
	   iz6=dned(iz1,dNREM);
/**********	 cprintf("iz6=%d  \n ",iz6);***********************/

	   dnp[ip[i]]=iz6;}}
	   ipnr=(pnr[i]-1)/24; dpnr=pnr[i]-ipnr*24;
	   pnr2=pnr[i]; jq=0;
	   if(rr[i]==7&&rms[i]==111) goto ms6;
	   for(iq=0;iq<MY_REST;iq++) {
	   if(qq5[iq]==0) goto ms6;
	   xa=(pnr2+23)/24;
	   if(xa==qq5[iq]){
	   xx=(pnr2+7)/8; xa1=xx/3; xx=xx-xa1*3;
	   ipnr=(pnr2-1)/24; dpnr=pnr2-ipnr*24;
	   pnr2=pnr2-dpnr; ix1=ix1-1;
	   if(ix1==0) ix1=7;
	   jq=1; /* goto ? */
	   }}
ms6:
	   pnr[i]=pnr2;
	   if(jq==1){ ipnr=(pnr2-1)/24;
	   dpnr=pnr2-ipnr*24; goto ms5;}
	   if(rms[i]==111){ pnr[i]=pnr[i]-tij[i]+1;
	   goto ms1;}
	   if(rms[i]==10){
	   ipnr=(pnr[i]-1)/24; dpnr=pnr[i]-ipnr*24;
	   dlt=dpnr-8;
	   if(dlt>=tij[i]){
	   pnr[i]=pnr[i]-tij[i]+1; goto ms1;}
	   else{
	   jd1=tij[i]-dlt; jd2=jd1/8;
	   jd3=jd1-jd2*8;
	   if (jd3==0) pnr[i]=(ipnr-jd2)*24+9;
	   else pnr[i]=(ipnr-jd2)*24-jd3-7;
	   goto ms1;
	   }}
	   else {ipnr=(pnr[i]-1)/24;
	   dpnr=pnr[i]-ipnr*24;
	   dlt=dpnr-8;
	   if (dlt>=tij[i]) {
	   pnr[i]=pnr[i]-tij[i]+1;
	   goto ms1; }

	  jd1=tij[i]-dlt; jd2=jd1/16; jd3=jd1-jd2*16;
	  if (jd3==0) pnr[i]=(ipnr-jd2)*24+9;
	  else pnr[i]=(ipnr-jd2)*24-jd3+1;
	  goto ms1;}
ms1:
	  xa=(pnr[i]+23)/24; ix2=(pnr2+23)/24;
	  ix2=ix2-xa+1;
	  kalenp(ix1,ix2,ix3,&iy1,&iy2);
	  xx=pnr[i]-(iy2-ix2)*24; pnr[i]=xx;
	  if(rr[i]==7&&rms[i]==111) goto ms8;
	     for(iq=0;iq<MY_REST;iq++) {
	     if(qq5[iq]==0) goto ms8;
	     xa=(pnr2+23)/24; xa1=(xx+23)/24;
	     if(xa1<=qq5[iq]&&qq5[iq]<=xa){
	     iz1=qq5[iq]; iz6=dned(iz1,dNREM);

	     if(ix3==5&&iz6==6) goto ms7;
	     if(ix3==5&&iz6==7) goto ms7;
	     if(ix3==6&&iz6==7) goto ms7;
	     ix1=iy1;
	     ix2=2; /* prover */
	     pnr[i]=pnr[i]-24;
	     kalenp(ix1,ix2,ix3,&iy1,&iy2);
	     xx=pnr[i]-(iy2-ix2)*24;}
    ms7: ;   }
ms8:
	  if(xx<mj[ip[i]]){
	  mj[ip[i]]=xx; dnp[ip[i]]=iy1;}
	  pnr[i]=xx; mij[ip[i]]=1;
/*********  cprintf(" mj[ip[i]]=%d dnp[ip[i]]=%d pnr[i]=%d mij[ip[i]=%d \n",
	   mj[ip[i]],dnp[ip[i]],pnr[i],mij[ip[i]]);  *********************/
ms3:;
}
return ;
}