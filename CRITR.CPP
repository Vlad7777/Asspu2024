									 /* critr function */
#include <alloc.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <ctype.h>
#define  NOB "nazvob.dbf"  /* Узлы */
#include "math.h"
#define  LKUZL 4       /* Длина кода узла */
#include <mem.h>
#include <string.h>
//#include <bios.h>

#include "all_defi.h"
#include "PartUnit.h"

 void *malloc_void(int Size_type, int Size_I, int Size_J = 1);
 void prcr(int tdir, int kn, int knr, long klu[], int tij[], int tnr[],
		int tor[], int rms[], int tpl[], int koduz[]);
 void blab5(int *ptrX, int dob, long dnd, long dod, int god);
 substr( char ctp[], int ip, int ik, char ctpp[]);
 void  hweek(int qq5[], int qq6[], int ind5[], int ind6[], int ind7[]);
 void  early(int NS, int NR, int lZ, int dNREM, int tij[], int tnr[],
		 int tor[], int axy[], int rr[], int axr[], int pms[], int qq5[],
		 int dnr[], int ip[], int jp[], int vaxr[], int vdnr[],
		 int kRR);
void maxtim(int NS, int NR, int lZ, int dNREM, int tij[], int axy[], int mj[],
		 int mij[], int dnp[], int qq5[], int rr[], int pms[], int ip[],
		 int jp[], int pnr[]);
void polres(int NS, int NR, int lZ, int dNREM, int tij[], int tpl[],
		 int pnr[], int tnr[], int rr[], int rms[],
		 int ind5[], int ind6[], int ind7[], int fLAG);

void __fastcall TPartForm::Krit()
	 {
//  HCURSOR hcurSave=::SetCursor(LoadCursor(NULL,IDC_WAIT));
	  struct zagdbf {
/* char zag0; */  /*    0-й заголовочный байт */
 char zagGG ;/* год          */
 char zagMM ; /* month */
 char zagDD ;  /* day */
 unsigned long zagKOLZ ; /*   quality  */
 unsigned short zagFLZ ; /* full  length zagolovka  */
 unsigned short zagDLZ ; /*   dlina zapisi */
 char zagRES[20]; /*  reserv  */
 }  hdbf;

	struct NOBdbf { char kodob[12];
			char koduz[4];
			char snaim[8];
			char pnaim[40];
			char vidob[4];
			char urtkod;
					} nob;
	struct NUSLTRdbf { char kodusltr[1];
				char usltr[3];
				char nameusltr[20];
					} nut;

	struct zagdbf    *udbf;
	struct NOBdbf    *unob;
	struct NUSLTRdbf *unut;

  int Nusltr;
  int Nob;
  int nb;
  long off=1L;
  char ch;
  int  fdbf;

 char krychar[LKUZL+1];
 int kry[MY_KOLU];
 float pzona[1];
 int rry[1];
 int   kodusltr[MY_NUSL];
 float usltr[MY_NUSL];

	 /* str-uzl */
	 /* str-fedi */
	 /* str-seni */   /* pkj */
	 int azon;
	 long kkc;
//    int  pms[MY_MXNR],mpi[MY_MXNR] ;
//     long klu[MY_MXNR];
//     int koduz[MY_MXNR];

int *pms   =  new int[MY_MXNR];
int *mpi   =  new int[MY_MXNR];
int *koduz =  new int[MY_MXNR];
long *klu  =  new long[MY_MXNR];

	 int knr, f;
	 int kkt;
	 /*analiz kran from week !*/
	 /* vstweek page 1,2,3,*/
	 int NR,NS;

#include "str_sset.cpp"
#include "str_fedi.cpp"
 struct sset s;
 struct fedi fe;
 long rKK7,rNR;
 long cl,R1,R2;
// int ip[MY_MXNR],jp[MY_MXNR];
// long   pi[MY_MXNR],pj[MY_MXNR] ;
// long   pkj[MY_MXNS];
// int isp[MY_MXNR],axyw[MY_MXNR];
 int *isp  =  (int *)  malloc_void(2, MY_MXNR);
 int *axyw =  (int *)  malloc_void(2, MY_MXNR);

// int koduz[MY_MXNR];
 int i ,j,k;
 int rb,r11,r2,r3;
 double t1,t2,t3;

int kvd5,kvd6;
float zona;
long double ldzona;
int tdir,kn,x,kv5,kv6,irr,iff,rq;

//int sbr[KOLB];
int war,iu,min,l,NU,NB,NY,jl,ib;

int dnrem,dkrem;
long a1,a2;
float frq;
int *ptrX;
int dob;
long dnd,dod;
int god;
int dNREM,kRR,lZ,fLAG=1,dKREM;    // Was 0 !!!!!!!!!!!!!!!!!!!
int end1,end2,tkr;
int dmtpl,xxx1,mtpl;
/*int  tij[MY_MXNR],tpl[MY_MXNR],tnr[MY_MXNR],tor[MY_MXNR],pnr[MY_MXNR],
	  axy[MY_MXNR],mij[MY_MXNR];

int axr[MY_MXNS],mj[MY_MXNS],dnr[MY_MXNS],dnp[MY_MXNS],rr[MY_MXNR];
int vaxr[MY_MXNS],vdnr[MY_MXNS];
int ind5[MY_TMAX],ind6[MY_TMAX],ind7[MY_TMAX];
int qq5[REST],qq6[REST];
*/
/////////////////////////////////////////////CG
 int *tij =  new int[MY_MXNR];
 int *tpl =  new int[MY_MXNR];
 int *tnr =  new int[MY_MXNR];
 int *tor =  new int[MY_MXNR];
 int *pnr =  new int[MY_MXNR];
 int *axy =  new int[MY_MXNR];
 int *rr  =  new int[MY_MXNR];
 int *mij =  new int[MY_MXNR];
 int *axr =  new int[MY_MXNS];
 int *mj  =  new int[MY_MXNS];
 int *dnr =  new int[MY_MXNS];
 int *dnp =  new int[MY_MXNS];
 int *vaxr=  new int[MY_MXNS];
 int *vdnr=  new int[MY_MXNS];
 int *ind5= new int[MY_TMAX];
 int *ind6= new int[MY_TMAX];
 int *ind7= new int[MY_TMAX];
 int *qq5 = new int[MY_REST];
 int *qq6 = new int[MY_REST];


//char string[51];
//char string1[5];

	FILE *fseti;
	fseti= fopen("fseti.fff","r+");
//   pkrit=fopen(PK,"w");
long *pi =  new long[MY_MXNR];
long *pj =  new long[MY_MXNR];
long *pkj=  new long[MY_MXNS];
int  *ip =  new int[MY_MXNR];
int  *jp =  new int[MY_MXNR];
int *sbr =  new int[MY_MXNR];

/*    lst=fopen("prn","w");  */
//  #include "defwind.c"
		 cl=MY_KK00;
		 fseek(fseti,cl,0);
	#include "sscffedi.cpp"
//  cprintf(" more !!!!!!!!!! fe.nr= %d \n",fe.nr);
  if (fe.kran ==1)  {
// printf("BНИМАНИЕ -!\r");
// printf("Повторите ,пожалуйста,задание РКВВОД \r");
// printf("возможны ошибки в топологии сетевой модели \r");
// getche();
 goto avar;}
  NR=fe.nr; NS=fe.ns;  NY=fe.ny; NB=fe.nb;

  for (j=0;j<MY_MXNR;j++) klu[j]=0;
// printf("NR= %d \n",NR);
	  R1=MY_KK7;  R2=MY_SZFSETI;
		rKK7= R1*R2;  /* KK7*SZFSETI; */
		 R1=NR;
		rNR=R1*R2; /* NR*SZFSETI;  */
//    printf (" rKK7 = %ld  rNR = %ld \n",rKK7,rNR);
  dNREM=fe.dr;
// printf("dNREM=%d \n",dNREM);
  dKREM=fe.dkr;  /*  !!!!!!!!!!!!!!!!  dr &  dkr  no  work  !!!!!!!!!!!!!!! */
// printf("dKREM=%d \n",dKREM);

  /*   call blab5;   x=30; */  /* tempor */
	  dob=fe.dob; dnd=fe.dnd; dod=fe.dod; god=fe.god1;
	 blab5(&x,dob,dnd,dod,god);

	fe.tdir=tdir=24*x;
//   printf("Директивный срок=%d часов \r",tdir);

//   printf("укажите величину отклонения\r от критического пути  xxx часов \r ");
//     cscanf ("%d",&azon);
//   azon=0;
//string[0]=49;
	  azon=24;   // !!!!!!!!!!!!!!!!!!!!  DEFAULT = 24 !!!!!!!!!!!!!!!!!!!!!
//Input_String( 15,10,67,14,string);
//  substr(string,3,5,string1);
//    azon= atoi( string1);
	 /*вст. pg.3. */  /* ip,jp,pkj,tij */
	  hweek(qq5,qq6,ind5,ind6,ind7);
  /* SENI  */
	R1=MY_KK1; R2=MY_SZFSETI;
 cl=R1 * R2; /* KK1*SZFSETI;*/
 fseek(fseti,cl,0);
 for (k=0;k<NS;k++) {
 fscanf(fseti,"%ld",(pkj+k));
// printf(" %ld",pkj[k]);
 }
 k=2;
	 /*    yzl    */
/**********************************printf("\n   ремонтируемые узлы - \n");
	R1=KK9;
	cl=R1* R2;
	fseek(fseti,cl,0);
		for (i=0; i<NY; i++)  {

	 fscanf (fseti,"%d %f %d ",
	 &kry[i],&pzona[i],&rry[i]);
	printf ("kry[i]= %d \n",kry[i]);
	 printf ("pzona[i]= %f \n",pzona[i]);
	printf ("rry[i]= %d \n",rry[i]);
	 fgets(sry[i],TXTUS,fseti);
	printf ("sry[i]=  %s \n",sry[i]);
	  fgets(pry[i],TXTU,fseti);
	printf("pry[i]= %s \n",pry[i]);
	if (kry[i]== EOFU) {
	  NY=i; goto m53; }
	 }
 m53: ;
		 **************************************************************/

		/*  Чтение наименований ОБОРУДОВАНИЯ(УЗЛОВ)*/
 /*************************************************************************/
	 fdbf=open(NOB/*"nazvob.dbf"*/,O_RDWR| O_BINARY );   /*для чтения и записи*/
	off=1L;
	lseek(fdbf,off,0);
	nb=sizeof(hdbf);
	  udbf=&hdbf;
	read(fdbf,udbf,nb);
	  Nob=hdbf.zagKOLZ;
		unob=&nob;
	nb=sizeof(nob);
	off=hdbf.zagFLZ+1;
	lseek(fdbf,off,0);
	 for (i=0;i<Nob;i++)     {
	read(fdbf,unob,nb);
	strncpy(krychar,nob.koduz,LKUZL);
   krychar[LKUZL] = '\0'; // CG !!!!!!!!!!!
	kry[i]=atoi(krychar);
	if ((kry[i]==0)&&(i>0)) { Nob=i; break; } /****  EXIT *********/
	  /*	strncpy(sry[i],nob.snaim,LSNAIMU);
	strncpy(pry[i],nob.pnaim,LPNAIMU);  */
	off=hdbf.zagDLZ+off;
	lseek(fdbf,off,0);
		}
	 close(fdbf);
	  NY=Nob;
 /*************************************************************************/
			// Read conditions of labor
	fdbf=open("usltrud.dbf",O_RDWR| O_BINARY );   /*для чтения и записи*/
	off=1L;
	lseek(fdbf,off,0);
	nb=sizeof(hdbf);
	udbf=&hdbf;
	read(fdbf,udbf,nb);
	Nusltr=hdbf.zagKOLZ;
	unut=&nut;
	nb=sizeof(nut);
	off=hdbf.zagFLZ+1;
	lseek(fdbf,off,0);
	for (i=0;i<Nusltr;i++)     {
	read(fdbf,unut,nb);
	strncpy(krychar,nut.kodusltr,1);
	kodusltr[i]=atoi(krychar);
	strncpy(krychar,nut.usltr,3);
	ldzona = _atold(krychar);   // CG !!!!!!!!!!!!!!!!

	off=hdbf.zagDLZ+off;
	lseek(fdbf,off,0);
		}
	 close(fdbf);

				 /*****    sbr  ********/
/******************    printf ("коды бригад  и фио бригадиров  \n");
	  R1=KK13;   R2=SZFSETI;
	 cl=R1*R2;
	 fseek (fseti,cl,0);
	 for (i=0;i<NB;i++ ) {
	 fscanf(fseti,"%d",&sbr[i]);
	printf("sbr[i]=  %d ",sbr[i]);
	 }
	 NB=i;
	printf(" NB= %d \n",NB);
	 ***********************************************************/
	 i=0;
//   printf(" time out ???????? \n");
//   printf ("rKK7= %ld rNR= %ld  NR= %d \n",rKK7,rNR,NR);
		for (cl=rKK7; cl<rKK7+rNR; cl= cl+MY_SZFSETI) {
		fseek(fseti,cl,0);
		 #include "sscfsset.cpp"
//   printf("iteracia i= %d \n",i);
		 /* ввод или активизация данных */
		 /* tij,ip,rms,rr,v,kry,rona, */
		 /* call valera */
	pms[i]=111;
	if (s.a29==3) pms[i]=111;
	if (s.a29==1) pms[i]=10;
	if (s.a29==2) pms[i]=11;
	isp[i]=s.a4;
/*   pms[i]=rms[i]; !!!!!!!!!!!!!!!!!!!!! */
   rr[i]=7;
   pi[i]=s.a1;
   pj[i]=s.a2;
   koduz[i]=s.a32[3]; /// NEW !!!!!!!!!!!!!!!!!!!!!!!
//   kodusltr[i]=s.a32[1]; /// NEW !!!!!!!!!!!!!!!!!!!!!!!

//  printf ("pi[i]=   %ld   pj[i]=   %ld  isp[i]= %d \n",pi[i],pj[i],isp[i]);
   rb=s.a6 +s.a8 -s.a7;
	  for (j=0;j<NS;j++){
	   if (pi[i]==pkj[j]){
		ip[i]=j; goto fw5;}}
	  fw5:
		for (j=0;j<NS;j++){
		 if (pj[i]==pkj[j]){
			jp[i]=j; goto fw6; }}
	  fw6:;
 if (s.a5==4) { tij[i]=0; goto sli;   }
 r11=0; r2=0; r3=0;
 for (k=0;k<MY_MR;k++ ) r11=r11 + s.a12[k];
// printf (" rb= %d r11= %d \n",rb,r11);
 if (rb<=0) {
 if (r11 !=0) {tij[i]=0; goto sli;}
 tij[i] =s.a15; goto sli;}
 if  (r11==0) {tij[i]=0; goto sli; }
 axyw[i]=1;
  a1 =s.a1/100; a2=s.a2/100;   ///     OUT !!!!!


/* a1=s.a1;a2=s.a2;    */
// for (k=0;k<NY;k++)  {
// if ((kry[k]==a1)&&(kry[k]==a2)) {
// zona= pzona[k]/100; goto fw7; }}
// fw7:
	for (k=0;k<Nusltr;k++)  {
	if (kodusltr[k]==s.a32[1]) {

//	 ldzona = _atold(usltr[k]);   ??????????????????????
	 zona=ldzona;
	 break;
	 }}
  ///////////////////////////////////////////////////////////
  zona = 0; /////////////////////// TMP !!!!!!!!!!!!
  t2= rb/r11;
/*printf(" t2= %d \n",t2);*/
  t3= t2 * zona; //
  t2=t2+t3;                         //  + 0.5;   ???????????
/* printf(" t2= %d \n",t2); */
  t1=floor(t2);
  tij[i]=t1;
// printf(" tij[i]= %d \n",tij[i]);
/*  printf(" t2= %d \n",t2);*/
		if (tij[i]==0) tij[i]=1;
  sli: ;
  i++;
  }
//  for (i=0;i<NR;i++)
// printf ("pi= %ld   Pj= %ld   tij= %d  \n",pi[i],pj[i],tij[i]);
// for (i=0;i<NR;i++)
// printf ("ip= %d   jp= %d    \n",ip[i],jp[i]);
	 #include "valerc.cpp"   /* or valerc.c  '<tdir */
	 kn=axr[NS-1];
	 for(i=0;i<NR;i++)  mpi[i]=0;
	 mtpl=9999;
	 for(i=0;i<NR;i++)
	 if((mtpl>tpl[i])&&(tij[i]!=0)) mtpl=tpl[i];
//   printf("mtpl=%d  \n",mtpl);
	 knr=0; mtpl=mtpl+azon;
	 for(i=0;i<NR;i++) {
	 if((mtpl>=tpl[i])&&(tij[i]!=0))  {
	 mpi[i]=1;
//   printf("mpi[i]= %d    ",mpi[i]);
	  knr++; }}

//////////////////////////// Add  Win ////////////////////////////////
		for (cl = rKK7, i =0; cl < rKK7+rNR; cl = cl+MY_SZFSETI, i++) {
		fseek(fseti,cl,0);
		#include "sscfsset.cpp"
		if (mpi[i] == 1)
		s.a32[0] = 1;         // Temporary !!!!!!!!!!!!!!
		fseek(fseti,cl,0);
		#include "sprfsset.cpp"
		}
//////////////////////////////////////////////////////////////////////////


	 j=0;
	 for(cl=rKK7; cl<rKK7+rNR;cl=cl+MY_SZFSETI)  {
	 klu[j]=cl;
//   printf("klu[j]= %ld  ",klu[j]);
		j++;  }
	 k=0;  for(i=0;i<NR;i++)  {
	 if(mpi[i]==1)  {   //   printf("\n  assignment for i !!!!!!!! ");
	 klu[k]=klu[i]; tnr[k]=tnr[i]; tor[k]=tor[i];
	 tij[k]=tij[i]; pi[k]=pi[i]; pj[k]=pj[i]; pms[k]=pms[i];
	 tpl[k]=tpl[i];  koduz[k] = koduz[i];
//   printf("tpl[k]=%d ",tpl[k]);
	  k++;  }}
	 /* atten!!! режим вывода? goto sor2; for KAES! */
	 if(knr==0) goto sor2;
	 sor1: f=0;   /* sort by key */
	 for(i=0;i<knr-1;i++)  {
//    if(pi[i]>pi[i+1])  {    // sort by assemblies !!!!!!!!!!!!!
		 if(tnr[i]>tnr[i+1]) {     // sort by begining dates
	 f=1;
	 a2=pi[i]; pi[i]=pi[i+1];pi[i+1]=a2;
	 a2=pj[i]; pj[i]=pj[i+1]; pj[i+1]=a2;
	 kkc=klu[i];klu[i]=klu[i+1]; klu[i+1]=kkc;
	 kkt=tnr[i]; tnr[i]=tnr[i+1]; tnr[i+1]=kkt;
	 kkt=tor[i]; tor[i]=tor[i+1]; tor[i+1]=kkt;
	 kkt=tij[i]; tij[i]=tij[i+1]; tij[i+1]=kkt;
	 kkt=pms[i]; pms[i]=pms[i+1]; pms[i+1]=kkt;
	 kkt=tpl[i];  tpl[i]=tpl[i+1]; tpl[i+1]=kkt;
	 kkt=koduz[i]; koduz[i]=koduz[i+1]; koduz[i+1]=kkt;

//   printf(" where is  tpl[i]=%d kkt=%d ?  \n",tpl[i],kkt);
	 }}
	 if(f==1) goto sor1;
	 sor2: ;  /* call prcr!*/
	 /* print result! */


//   printf(" print result !!!!!!!! \n");
	 for(i=0; i<knr; i++) {
//printf("klu=%ld pi[i]=%ld pj[i]=%ld tij[i]=%d tnr[i]=%d tor[i]=%d pms[i]=%d tpl[i]=%d \r",
//  klu[i],pi[i],pj[i], tij[i],tnr[i],tor[i],pms[i],tpl[i]);
//  printf("  tpl=%d \n",tpl[i]);
//fprintf(pkrit,"pi[i]=%ld pj[i]=%ld tij[i]=%d tpl[i]=%d tnr[i]=%d tor[i]=%d pms[i]=%d  \n",
//pi[i],pj[i], tij[i],tpl[i],tnr[i],tor[i],pms[i]);
/* fprintf(lst,"pi[i]=%ld pj[i]=%ld tij[i]=%d tpl[i]=%d tnr[i]=%d tor[i]=%d pms[i]=%d  \n",
pi[i],pj[i], tij[i],tpl[i],tnr[i],tor[i],pms[i]);  */
	 }
	 avar: ;
	fclose(fseti); //   fclose(pkrit);
//   fclose(lst);
 delete[] tij;
 delete[] tpl;
 delete[] tnr;
 delete[] tor;
 delete[] pnr;
 delete[] axy;
 delete[] rr;
 delete[] mij;
 delete[] axr;
 delete[] mj;
 delete[] dnr;
 delete[] dnp;
 delete[] vaxr;
 delete[] vdnr;
 delete[] ind5;
 delete[] ind6;
 delete[] ind7;
 delete[] qq5 ;
 delete[] qq6;
 delete[] pms ;
 delete[] mpi ;
 delete[] koduz ;
 delete[] klu ;
 delete[] pi ;
 delete[] pj ;
 delete[] pkj;
 delete[] ip;
 delete[] jp ;
 delete[] sbr;

// prcr(tdir,kn,knr,klu,tij,tnr,tor,pms,tpl,koduz);
// ::SetCursor(hcurSave);
  return;
	 }

