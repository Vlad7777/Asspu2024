       /*   EARLY function */
 #include <stdio.h>
 #include <conio.h>
 #include "dned.cpp"
 #include "kalenr.cpp"
 #include "all_defi.h"

void kalenr(int ix1, int ix2,int ix3, int *piy1, int *piy2);
 int dned(int iz1, int dNREM);

void  early(int NS, int NR, int lZ, int dNREM, int tij[], int tnr[],
	    int tor[], int axy[], int rr[], int axr[], int rms[], int qq5[],
	    int dnr[], int ip[], int jp[], int vaxr[], int vdnr[],
	    int kRR)
{
//   FILE  *lst;
int ll,i,iq,jq;
int ix1,ix3,iz1,iz6,itnrs,idtnr,xx,xa,xa1,ix2;
int jd1,jd2,jd3,iy1,iy2,jd;
/* int ix;  TEMPORARY vary !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
	 /* EARLY */
 /*   lst=fopen("prn","w");   */
/*   fprintf(lst,"function EARLY\n"); */

//  #include "defwind.c"
//    cprintf("function EARLY\r");
//    cprintf("kRR=%d lZ=%d \n",kRR,lZ);
   for(i=0;i<MY_REST;i++) qq5[i]=0; /*  TEMPORARY!!!!!!!!!!!!!!!!!!!!!!!!!!!! */




	 /* NS,NR,LZ,DNREM,s3,s4,s5 */
	 if(lZ==0) {
   for(i=0;i<NR;i++){
   dnr[i]=dNREM;axr[i]=0;}
}
	if(kRR==0) goto dal;

	     if(kRR==1) {
	for(ll=0;ll<NS;ll++){
	vaxr[ll]=axr[ll];vdnr[ll]=dnr[ll];}
	goto dal;}
	for(ll=0;ll<NS;ll++){
	axr[ll]=vaxr[ll];dnr[ll]=vdnr[ll];}
dal:
//	cprintf("kRR= %d\n",kRR);
	for(i=lZ;i<NR;i++) {
	//	cprintf("job NO.I= %d\n",i);
	if(tij[i]==0){
	tnr[i]=axr[ip[i]];tor[i]=tnr[i];
	if(tnr[i]>axr[jp[i]]){
	axr[jp[i]]=tnr[i];
	dnr[jp[i]]=dnr[ip[i]];goto mi1;}}
	/*  ресурсные или работы ожидания  */
	ix1=dnr[ip[i]];ix3=rr[i];
	tnr[i]=axr[ip[i]]+1;
    /*	fprintf(lst,"ix1= %d ix3= %d tnr[i]= %d",ix1,ix3,tnr[i]); */
//	cprintf("ix1= %d ix3= %d tnr[i]= %d",ix1,ix3,tnr[i]);
//	getche();
/* for(ll=0;ll<NS;ll++) cprintf("dnr[ll]=%d ip[ll]=%d ",dnr[ll],ip[ll]);*/
	if(axy[i]!=0){
	tnr[i]=axy[i];iz1=(axy[i]+23)/24;
	/* call DNTD */
	iz6=dned(iz1,dNREM);
     /*	fprintf(lst,"iz1= %d axy[i]= %d iz6= %d",iz1,axy[i],iz6); */
//     cprintf("iz1= %d axy[i]= %d iz6= %d",iz1,axy[i],iz6);
//	getche();
	ix1=iz6;}
	if(rms[i]!=111){
	itnrs=(tnr[i]-1)/24;
	idtnr=tnr[i]-itnrs*24;
	if(rms[i]==10){
	if(idtnr<9){
	tnr[i]=tnr[i]+9-idtnr;
	if(axr[ip[i]]!=0&&axy[i]==0&&idtnr==1){
	ix1=ix1+1;
	if(ix1>7){ix1=ix1-7;}}}
	if(idtnr>16){
	tnr[i]=tnr[i]+33-idtnr;
	ix1=ix1+1;
	if(ix1>7) ix1=ix1-7;
	}}
	/* двухсменная работа */
	else{
	if(idtnr<9){
	tnr[i]=tnr[i]+9-idtnr;
	if(axr[ip[i]]!=0&&axy[i]==0&&idtnr==1){
	ix1=ix1+1;
	if(ix1>7) ix1=ix1-7;}
	}}}
	xx=(tnr[i]+7)/8;xa=xx/3;xx=xx-xa*3;
	itnrs=(tnr[i]-1)/24;idtnr=tnr[i]-itnrs*24;
	if(rms[i]==111){
	if(axr[ip[i]]!=0&&axy[i]==0&&idtnr==1){
	ix1=ix1+1;      /* TEMPORARY ERROR  ix !!!!!!!!!!!!!!!!!!! */
	if(ix1>7) ix1=ix1-7;
	}}
   /*	fprintf(lst,"xx= %d\n",xx);    */
   //  cprintf("xx= %d\n",xx);
   /*	switch(xx){
	case 1: goto mi8; break;
	case 0: goto mi6; break;
	case 2: break;
	default: cprintf("ошибка xx!\n");
	break;}     */
	if (xx==1) goto mi8;
	if (xx==0) goto mi6;
	   /*  xx=2  */
	if(rr[i]==5&&ix1==6){
	ix1=1;tnr[i]=tnr[i]+49-idtnr;
	goto mi3;}
	if((rr[i]==5&&ix1==7)||(rr[i]==6&&ix1==7)){
	ix1=1;tnr[i]=tnr[i]+25-idtnr;
	goto mi3; }
mi5:
	if(rms[i]==111){
	tor[i]=tnr[i]+tij[i]-1;
	goto mi4;}
	/*  проверка начала работы за 2 часа до начала смены  */
/********************************************************************/
	itnrs=(tnr[i]-1)/24;
	idtnr=tnr[i]-itnrs*24;
/********************************************************************
	if(rms[i]==10){
  //	if(idtnr>14&&idtnr<17){
	if(idtnr>15&&idtnr<17){
	tnr[i]=tnr[i]+33-idtnr;
	ix1=ix1+1;
	if(ix1>7) ix1=ix1-7;
	}}
	if(rms[i]==11){
//	if(idtnr>22&&idtnr<25){
	if(idtnr>23&&idtnr<25){
	tnr[i]=tnr[i]+33-idtnr;  ix1=ix1+1;
	if(ix1>7) ix1=ix1-7;
	}}
 ************************************************************/
// ..................END. BLOKA ???......................................
	if((rr[i]==5&&ix1==7)||(rr[i]==6&&ix1==7)){
	ix1=1;tnr[i]=tnr[i]+24;}
	if ((rr[i]==5)&&(ix1==6)) {
	ix1=1; tnr[i]=tnr[i]+48;}
/************************************************************************/
	itnrs=(tnr[i]-1)/24;idtnr=tnr[i]-itnrs*24;
	if(rms[i]==10){
	jd=17-idtnr;
	if(jd>=tij[i]){
	tor[i]=tnr[i]+tij[i]-1;goto mi4;}
	else{   jd1=tij[i]-jd;jd2=jd1/8;jd3=jd1-jd2*8;
		 if(jd3==0) tor[i]=(itnrs+jd2)*24+16;
		 else  tor[i]=(itnrs+jd2)*24+jd3+32;
		 goto mi4;}}
	else{jd=25-idtnr;
		if(jd>=tij[i]){
		tor[i]=tnr[i]+tij[i]-1;goto mi4;}
	else{jd1=tij[i]-jd;
	jd2=jd1/16;jd3=jd1-jd2*16;
	if(jd3==0) tor[i]=(itnrs+jd2+1)*24;
	else tor[i]=(itnrs+jd2)*24+jd3+32;
	goto mi4;}}
mi8:
	if(rr[i]==5&&ix1==6){
	ix1=1;tnr[i]=tnr[i]+49-idtnr;
	goto mi3;}
	if((rr[i]==5&&ix1==7)||(rr[i]==6&&ix1==7)){
	ix1=1;tnr[i]=tnr[i]+25-idtnr;goto mi3;}
	goto mi5;
mi3:
	if(rms[i]==111){
	tor[i]=tnr[i]+tij[i]-1;goto mi4;}
	else{tnr[i]=tnr[i]+8;goto mi5;}
mi6:
	if(rr[i]==5&&ix1==6){
	ix1=1;tnr[i]=tnr[i]+49-idtnr;
	goto mi3;}
	if((rr[i]==5&&ix1==7)||(rr[i]==6&&ix1==7)){
	ix1=1;tnr[i]=tnr[i]+25-idtnr;
	goto mi3;}
	goto mi5;
mi4:     jq=0;
	itnrs=(tnr[i]-1)/24;idtnr=tnr[i]-itnrs*24;
	xa=(tnr[i]+23)/24;idtnr=tnr[i]-itnrs*24;
	xa=(tnr[i]+23)/24;
	if(rr[i]==7&&rms[i]==111) goto mi9;
	for(iq=0;iq<MY_REST;iq++){
	if(qq5[iq]==0) goto mi9;
	if(qq5[iq]==xa){
	jq=1;tnr[i]=tnr[i]+25-idtnr;ix1=ix1+1;
	if(ix1>7) ix1=ix1-7;
	goto mi9;}}
mi9:
	if(jq==1){
	itnrs=(tnr[i]-1)/24;idtnr=tnr[i]-itnrs*24;
	goto mi8;}
	xa=(tnr[i]+23)/24;ix2=(tor[i]+23)/24;
	ix2=ix2-xa+1;
	kalenr(ix1,ix2,ix3,&iy1,&iy2);
	tor[i]=tor[i]+(iy2-ix2)*24;
	xa1=(tor[i]+23)/24;
	if(rr[i]==7&&rms[i]==111) goto mi15;
	for(iq=0;iq<MY_REST;iq++){
	if(qq5[iq]==0) goto mi15;
	if(qq5[iq]>=xa&&qq5[iq]<=xa1){
	iz1=qq5[iq];iz6=dned(iz1,dNREM);
	if(rr[i]==5&&iz6==6) goto mi10;
	if(rr[i]==5&&iz6==7) goto mi10;
	if(rr[i]==6&&iz6==7) goto mi10;
	/* вопрос открыт */
	ix1=iy1;ix2=2;tor[i]=tor[i]+24;
	kalenr(ix1,ix2,ix3,&iy1,&iy2);
	tor[i]=tor[i]+(iy2-ix2)*24;
	}
mi10: ;	}
mi15:
	if(tor[i]>axr[jp[i]]){
	axr[jp[i]]=tor[i];dnr[jp[i]]=iy1;}
/****	fprintf(lst,"axr[jp[i]]= %d dnr[jp[i]]= %d",axr[jp[i]],dnr[jp[i]]);
*	fprintf(lst,"tnr[i]= %d tor[i]= %d",tnr[i],tor[i]);
*	fprintf(lst,"rr[i]= %d rms[i]= %d\n",rr[i],rms[i]);
*****/
//	cprintf("axr[jp[i]]= %d dnr[jp[i]]= %d",axr[jp[i]],dnr[jp[i]]);
//	cprintf("tnr[i]= %d  tij[i]=%d tor[i]= %d",tnr[i],tij[i],tor[i]);
//	cprintf("rr[i]= %d rms[i]= %d\n",rr[i],rms[i]);

mi1:;}
/*  fclose(lst);!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
// for(i=0;i<NS;i++)
//  cprintf("i=%d axr[i]= %d dnr[i]= %d\n",i,axr[i],dnr[i]);
return ;
}
