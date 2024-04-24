

	  /* обращение к PRIMERу */
	  for(i=0;i<NR;i++){
	  tnr[i]=1; tor[i]=1; pnr[i]=0; axy[i]=0;}
	  for(j=0;j<NS;j++){
	  axr[j]=1;dnr[j]=dNREM; dnp[j]=dKREM;}
	   kRR=0;lZ=0;
	  /* call early */
	  early(NS,NR,lZ,dNREM,tij,tnr,tor,axy,rr,axr,pms,qq5,
			dnr,ip,jp,vaxr,vdnr,kRR);
	  for(j=0;j<NS;j++){
	  mj[j]= fe.tdir; dnp[j]=dKREM;}
	  /* call maxtim */
	  maxtim(NS,NR,lZ,dNREM,tij,axy,mj,mij,dnp,qq5,rr,pms,ip,jp,pnr);
	  /* call polres*/
	   polres(NS,NR,lZ,dNREM,tij,tpl,pnr,tnr,rr,pms,ind5,ind6,ind7,fLAG);
	   /* вывод результатов */
  /*   fprintf(lst,"results of deside networks\n"); !!!!!!!!!!!!!!!!!!! */
//	  fprintf(pkrit,"results of deside networks\n");
//	  fprintf(pkrit,"    i=       tij       tnr       tor      pnr        tpl ");


//	  fprintf(pkrit,"    rr       rms\n");
//	 cprintf("results of deside network\r");
//	 cprintf("    i=        tij       tnr       tor         pnr           tpl");
    /* fprintf(lst,"       i=       tij       tnr       tor      pnr        tpl ");*/
       /*	  fprintf(lst,"     rr       rms\n"); !!!!!!!!!!!!!!!!!!!! */
//       cprintf("       rr       rms\r");
//		for(i=0;i<NR;i++) {
    /*	  fprintf(lst,"%9d %9d %9d %9d %9d %9d %9d %9d\n",
	  i,tij[i],tnr[i],tor[i],pnr[i],tpl[i],rr[i],rms[i]);!!!!!!!!!!! */

//	  fprintf(pkrit,"%2d %9d %9d %9d %9d %9d %9d %9d\n",
//	  i,tij[i],tnr[i],tor[i],pnr[i],tpl[i],rr[i],pms[i]);

//	  cprintf("%2d %9d %9d %9d %9d %9d %9d %9d\r",
//		i,tij[i],tnr[i],tor[i],pnr[i],tpl[i],rr[i],pms[i]);
//	       }
//	  cprintf("      j       axr       mj         ");
    /*	  fprintf(lst,"      j       axr        mj           ");!!!!!!!!!!!*/
//	    cprintf("dnr    dnp\r");
    /*	  fprintf(lst,"dnr      dnp\n");!!!!!!!!!!!!!!!!!!!!!!!!!!! */
//			 for(j=0;j<NS;j++) {
  /*	  fprintf(lst,"%9d %9d %9d %9d %9d\n",j,axr[j],mj[j],dnr[j],dnp[j]);*/
///	  cprintf("%9d %9d %9d %9d %9d\r",j,axr[j],mj[j],dnr[j],dnp[j]);
//			   }
//	  cprintf(" PRIMER завершил работу\r");
   /*	  fprintf(lst,"PRIMER ended\n");!!!!!!!!!!!!!!!!!!!!!!!!! */
     /*	  fclose(lst);  */
