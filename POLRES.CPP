		/* polres function */
#include "conio.h"
void polres(int NS, int NR, int lZ, int dNREM, int tij[], int tpl[],
	    int pnr[],
	    int tnr[], int rr[], int rms[], int ind5[], int ind6[],
	    int ind7[], int fLAG)

{
int i,ii;
int idl,xx,xa,ixa,ixb;
//  #include "defwind.c"
	if(fLAG==1) goto ps8;
	for(i=lZ;i<NR;i++){ tpl[i]=0;
	if(tij==0) goto ps1;
	if((pnr[i]-tnr[i])>=0&&(pnr[i]-tnr[i])<24){
	if(pnr[i]==tnr[i]) goto ps1;
	if(rms[i]==111){tpl[i]=pnr[i]-tnr[i];  goto ps1;}
	tpl[i]=8; goto ps1;}
	idl=0; xx=(tnr[i]+23)/24; xa=(pnr[i]+23)/24;
	if(rms[i]==111){tpl[i]=pnr[i]-tnr[i];
	if(rr[i]==7) {
	for(ii=xx;ii<xa;ii++){    /*<=*/
	if(ind7[ii]==0) idl++; }
	goto ps2;}
	if(rr[i]==6){
	for(ii=xx;ii<xa;ii++){     /*  <= */
	if(ind6[ii]==0) idl++;}
	goto ps2;}
	for(ii=xx;ii<xa;ii++) {     /* <=  */
	if(ind5[ii]==0) idl++;}
ps2:
	tpl[i]=tpl[i]-idl*24; goto ps1;}
   if(rms[i]==10){ tpl[i]=8*(xa-xx);  /* ˆ‘€‚œ € Š€‘ ˆ €‘ !!! */
	if(rr[i]==7) {
	for(ii=xx;ii<xa;ii++){       /*  <=  */
	if(ind7[ii]==0) idl++;}
	goto ps3;}
	if(rr[i]==6) {
	for(ii=xx;ii<xa;ii++){    /* <=*/
	if(ind6[ii]==0) idl++;}
	goto ps3;}
	for(ii=xx;ii<xa;ii++){          /*  <=  */
	if(ind5[ii]==0) idl++;}
ps3:                     /*  tpl ¢ áãâª å !!!!!!!!!!!!! !*/
	tpl[i]=tpl[i]-idl*8;  /*¯à®¢¥àì */ goto ps1; }   /* NO ERROR  */
	if(rms[i]==11){tpl[i]=(xa-xx-1)*16;
	ixa=(tnr[i]+7)/8; ixb=ixa/3; ixa=ixa-ixb*3;
	if(ixa==2) tpl[i]=tpl[i]+8;
	ixa=(pnr[i]+7)/8; ixb=ixa/3; ixa=ixa-ixb/3;
	if(ixa==0) tpl[i]=tpl[i]+16;
	else tpl[i]=tpl[i]+8;
	if(rr[i]==7){
	for(ii=xx;ii<xa;ii++){         /*  <=  */
	if(ind7[ii]==0) idl++;}
	goto ps4;}
	if(rr[i]==6){
	for(ii=xx;ii<xa;ii++){             /*  <=  */
	if(ind6[ii]==0) idl++;}
	goto ps4;}
	for(ii=xx;ii<xa;ii++){             /*  <=  */
	if(ind5[ii]==0) idl++; }
ps4:
	tpl[i]=tpl[i]-idl*16;
	}
ps1:;
}
	goto ps9;
ps8:
	for(i=lZ;i<NR;i++){
	tpl[i]=0;
	if(tij[i]==0) goto ww2;
	tpl[i]=pnr[i]-tnr[i]; xx=(tnr[i]+23)/24;
	xa=(pnr[i]+23)/24; idl=0;
	for(ii=xx;ii<xa;ii++){          /*  <=  */
	if(ind7[ii]==0) idl++;}
	tpl[i]=tpl[i]-idl*24;
ww2:;
}
ps9:;
return;
}
