
	  /* ®¡à é¥­¨¥ ª PRIMERã */
	  for(i=0;i<NR;i++){
	  tnr[i]=1; tor[i]=1; pnr[i]=0; axy[i]=0;}
	  for(j=0;j<NS;j++){
	  axr[j]=1;dnr[j]=0;dnp[j]=0;}
	  dnr[0]=dNREM;/* krr=0; */
	  lZ=0; kRR=0;
	  /* call early */
	  early(NS,NR,lZ,dNREM,tij,tnr,tor,axy,rr,axr,rms,qq5,
			dnr,ip,jp,vaxr,vdnr,kRR);

//     cprintf("axr[NS-1]= %d  dnr[NS-1]= %d \n",axr[NS-1], dnr[NS-1]);
	  for(j=0;j<NS;j++){
	  mj[j]=tdir;
	  dnp[j]=dKREM;
	  }
	  /* call maxtim */
	  maxtim(NS,NR,lZ,dNREM,tij,axy,mj,mij,dnp,qq5,rr,rms,ip,jp,pnr);
	  /* call dnires*/
	  dnires(NS,NR,lZ,dNREM,tij,tpl,pnr,tnr,rr,ind5,ind6,ind7);
					       /*  ??????????? FLAG !!!!!! */
