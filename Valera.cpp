void  early(int NS, int NR, int lZ, int dNREM, int tij[], int tnr[],
	    int tor[], int axy[], int rr[], int axr[], int pms[], int qq5[],
	    int dnr[], int ip[], int jp[], int vaxr[], int vdnr[],
	    int kRR);
void maxtim(int NS, int NR, int lZ, int dNREM, int tij[], int axy[], int mj[],
	    int mij[], int dnp[], int qq5[], int rr[], int pms[], int ip[],
	    int jp[], int pnr[]);


	  
	  /* ®¡à é¥­¨¥ ª PRIMERã */
	  for(i=0;i<NR;i++){
	  tnr[i]=1; tor[i]=1; pnr[i]=0;  /* axy[i]=0; */
	   }                             // AS axy[]=tnr[[]; if s.a3==3 !!!
	  for(j=0;j<NS;j++){
	  axr[j]=1;dnr[j]=0;dnp[j]=0;}
	  dnr[0]=dNREM;/* krr=0; */
	  /* call early */
  early(NS,NR,lZ,dNREM,tij,tnr,tor,axy,rr,axr,pms,qq5,dnr,ip,jp,
	vaxr,vdnr,kRR);
 ///////////////////////// ATTENTION !!! ///////////////////////////////////
 /*************************************************************************/
 if (tdir>=axr[NS-1]) {       // Normal complete !!!
	  for(j=0;j<NS;j++){
   //	  mj[j]=axr[NS-1];dnp[j]=dnr[NS-1];
	   mj[j]=tdir; dnp[j]=dKREM;
	  }}
      else {
	  for(j=0;j<NS;j++){
	  mj[j]=axr[NS-1];dnp[j]=dnr[NS-1]; // Assign any krit time !!!!!

	   }}
 ///////////////////////////////////////////////////////////////////////////
	  /* call maxtim */
	  maxtim(NS,NR,lZ,dNREM,tij,axy,mj,mij,dnp,qq5,rr,pms,ip,jp,pnr);
	  /* call polres*/
	  polres(NS,NR,lZ,dNREM,tij,tpl,pnr,tnr,rr,pms,ind5,ind6,ind7,fLAG);