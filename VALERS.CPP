

	  /* call early */
  early(NS,NR,lZ,dNREM,tij,tnr,tor,axy,rr,axr,pms,qq5,dnr,ip,jp,vaxr,vdnr,kRR);
	  for(j=0;j<NS;j++){
   //  mj[j]=axr[NS-1];dnp[j]=dnr[NS-1];
      mj[j]=pfe->tdir; dnp[j]=dKREM;

     }

	  /* call maxtim */
	  maxtim(NS,NR,lZ,dNREM,tij,axy,mj,mij,dnp,qq5,rr,pms,ip,jp,pnr);
	  /* call polres*/
	   polres(NS,NR,lZ,dNREM,tij,tpl,pnr,tnr,rr,pms,ind5,ind6,ind7,fLAG);