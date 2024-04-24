//#include <owl\owlpch.h>
#include <stdlib.h>
#include <stdio.h>
#include <dir.h>
#include <mem.h>
#include <string.h>
#include <dos.h>

#include "file_dbf.h"
#include "smuzi.str"
#include "smuzl_my.str"
#include "speci.str"
//#include "pack.str"
//#include "brigade.str"
#include "all_defi.h"
//#include "part.h"
#include "PartUnit.h"

void __fastcall TPartForm::SpuRead()

	{
//	HCURSOR hcurSave=::SetCursor(LoadCursor(NULL,IDC_WAIT));
	char StringTmp[ 12 ];
	StringTmp[ 11 ] = '\0';

	char StringTmp2[ 2 ];
	StringTmp2[ 1 ] = '\0';

	#include "str_fedi.cpp"
	struct fedi fe;

	 /* str_fedi */
	fe.nr=fe.ns=fe.mr=fe.mxr=fe.rb0=0;   fe.ny=fe.nb=0;
	fe.kza=fe.vzob=fe.kn=fe.tdir=fe.rsrv=0;
//	fe.amn=fe.amx=fe.b1=fe.b3=0;   ???
	fe.kk1=fe.kk2=fe.kk3=fe.kk4=fe.kk5=fe.kk6=fe.kk7=fe.kk8=0;
	fe.kstan=fe.dnd=fe.dod=0;
	fe.kagr=fe.god1=fe.dob=0;
	fe.kk9=fe.kk10=fe.kk21=fe.kk22=fe.kk23=fe.kk24=fe.kk25=0;
	fe.god1=fe.dkr=fe.dr=0;
	fe.kvd5=fe.kvd6=0;
	fe.kran=fe.krem=0;
	fe.rrq=0;
/************************* TEMPORARY **************************************/

	fe.ny = fe.nb = 8;
//	fe.dnd = 710;
//	fe.dod = 725;
	fe.kagr = 2001;
//	fe.god1= 1995;
	fe.dob = 701;
	fe.dkr = 2;
	fe.dr  = 1;
/*********************************************************************/

	FileDBF *file = new FileDBF( "smuzi.dbf" );
	struct smuzi SmuziStruct, *indexSmuziStruct = &SmuziStruct;
	file->readDBF( 0, (void *)indexSmuziStruct );
	strncpy( StringTmp, SmuziStruct.StartTime, 11 );
	unsigned long 	StartTimeBlock	 = atol( StringTmp ) ;
	strncpy( StringTmp, SmuziStruct.FinishTime, 11 );
	unsigned long 	FinishTimeBlock = atol( StringTmp ) ;
	delete file;

	struct date StrDate;
	struct time StrTime;
	unixtodos ( StartTimeBlock , &StrDate, &StrTime );
	fe.dnd = (int)StrDate.da_day + (int)StrDate.da_mon * 100;       // 710;
	fe.god1 = StrDate.da_year;                                      // 1995
	unixtodos ( FinishTimeBlock , &StrDate, &StrTime );
	fe.dod = (int)StrDate.da_day + (int)StrDate.da_mon * 100;       // 725;

	long cl;
	int NR = 0;
	long R1= MY_KK7;
	long R2=MY_SZFSETI;
	long rKK7=R1*R2; /*  KK7*SZFSETI;   */
//	R1=NR;
//	rNR=R1*R2;  /* NR*SZFSETI;  */

	FILE *fseti = fopen(MY_NF0,"r+");

	#include "str_sset.cpp"
	struct sset s;

	file = new FileDBF( "smuzl.dbf" );
	struct smuzl_my SmuzlStruct, *indexSmuzlStruct = &SmuzlStruct;
	long i = 0;
	unsigned long Number;
	unsigned long VolumeTmp;
	cl=rKK7;

	int  sbr[MY_KOLB];
	int NB = 0;
/*
	R1=KK13;   R2=SZFSETI;
	cl=R1*R2;

	  fseek (fseti,cl,0);
	  for (int ii=0;ii<KOLB;ii++ ) {
	  fscanf(fseti," %d ",&sbr[ii]);
	  if (sbr[ii]==0) break;
	  }
	 NB=ii;
 */
	 R1= MY_KK7;
	 R2=MY_SZFSETI;
	 rKK7=R1*R2; /*  KK7*SZFSETI;   */


	while ( file->readDBF( i, (void *)indexSmuzlStruct ) )
		if ( !file->IsDelRecord( i++ ) )
			{

	/****************    initial  sset   **********************************/
	s.Number = s.a1=s.a2=0;       char prob='\0';
	  strnset(s.a3,prob,MY_SIZE); /*  copy ' '  into s.a3 */
	s.a4=s.a5=s.a6=s.a7=s.a8=0;
	for(int ji=0;ji<MY_MR;ji++){  s.a10[ji]=0;
	s.a11[ji]=0; s.a12[ji]=0; s.a13[ji]=0;s.a30[ji]=s.a31[ji]=s.a32[ji]=0; }
	s.a14=s.a15=s.a16=s.a17=s.a18=s.a19=s.a20=0;
	s.a21=s.a22=s.a23=s.a24=s.a25=s.a26=s.a27=s.a28=s.a29=0;
	VolumeTmp = 0;
  /**************************************************************************/

	strncpy( StringTmp, SmuzlStruct.Number, 11 );
///////////  s.a7  ->  NUMBER   !!!  WAS !!!!!!!!!
						  s.Number  = atoi( StringTmp ) ;     // TEMPORARY  in s.a7!!!
	strncpy( s.a3 , SmuzlStruct.Name, MY_SIZE );
	s.a3[MY_SIZE-1]='\0';
	strncpy( StringTmp2, SmuzlStruct.Priz, 1 );
						  s.a5  = atoi( StringTmp2 ) ;
	strncpy( StringTmp, SmuzlStruct.StartKnot, 11 );
						  s.a1  = atol( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.FinishKnot, 11 );
						  s.a2  = atol( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.Duration, 11 );
						  s.a15 = atol( StringTmp ) / 3600 ;
	strncpy( StringTmp, SmuzlStruct.Kodorg, 11 );
						  s.a4	= atol( StringTmp );
	strncpy( StringTmp, SmuzlStruct.IndexShift, 11 );
						  s.a29		= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.Kodspec1, 11 );
						  s.a10[0]	= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceMin1, 11 );
						  s.a11[0]	= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceMax1, 11 );
						  s.a12[0]  = atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceOpt1, 11 );
						  s.a13[0]	= atoi( StringTmp ) ;
		// Average !!!!  AND  REST!!!!  s.a13[0]	= (s.a11[0] +	s.a12[0])/2;
	strncpy( StringTmp, SmuzlStruct.Volume1, 11 );
					 VolumeTmp  += atol( StringTmp );
	strncpy( StringTmp, SmuzlStruct.Kodspec2, 11 );
						  s.a10[1]	= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceMin2, 11 );
						  s.a11[1]		= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceMax2, 11 );
						  s.a12[1]		= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceOpt2, 11 );
					  //	  s.a13[1]		= atoi( StringTmp ) ;
						  s.a13[1]	= (s.a11[1] +	s.a12[1])/2;
	strncpy( StringTmp, SmuzlStruct.Volume2, 11 );
						  VolumeTmp  += atol( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.Kodspec3, 11 );
						  s.a10[2]		= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceMin3, 11 );
						  s.a11[2]		= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceMax3, 11 );
						  s.a12[2]		= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceOpt3, 11 );
					  //	  s.a13[2]		= atoi( StringTmp ) ;
						  s.a13[2]	= (s.a11[2] +	s.a12[2])/2;
	strncpy( StringTmp, SmuzlStruct.Volume3, 11 );
						  VolumeTmp += atol( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.Kodspec4, 11 );
						  s.a10[3]	= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceMin4, 11 );
						  s.a11[3]	= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceMax4, 11 );
						  s.a12[3]		= atoi( StringTmp ) ;
	strncpy( StringTmp, SmuzlStruct.ResourceOpt4, 11 );
					 //	  s.a13[3]		= atoi( StringTmp ) ;
						  s.a13[3]	= (s.a11[3] +	s.a12[3])/2;
	strncpy( StringTmp, SmuzlStruct.Volume4, 11 );
						  VolumeTmp += atol( StringTmp );
//	strncpy( StringTmp, SmuzlStruct.Kodob, 11 );
//								= atol( StringTmp ) ;

	strncpy( StringTmp, SmuzlStruct.Kodpack, 11 );
						  s.a32[3] = atoi( StringTmp ) ;

						  s.a6  = VolumeTmp / 3600;


 /***************** form   SBR   *************************************/
	  for (int jj=0; jj<MY_KOLB; jj++) {
	  if (sbr[jj]==s.a4) break;
	  if (sbr[jj]==0) {
	  sbr[jj]=s.a4; NB++;
	  break;
	  }}

 //  Rewrite FSETI from   SSET  key  CL
	fseek(fseti,cl,0);
	#include "sprfsset.cpp"
	cl= cl+MY_SZFSETI;
	NR ++;
		}

//  printf("NR= %d NS=%d \r",NR ,NR);
  if (NB!=0) {
	 R1=MY_KK13;   R2=MY_SZFSETI;
	 cl=R1*R2;
	 fseek (fseti,cl,0);
	 for (i=0;i<NB;i++ ) {
	 fprintf(fseti,"\n %d ",sbr[i]); // THINK !!! SBR create ore restore ???
	 }}


//	int NR;
	fe.nr = NR;
	fe.ns = NR;
	fe.nb = NB;
	cl=0;
// Rewrite FSETI from  FEDI  key  CL
	fseek(fseti,cl,0);
	#include "sprffedi.cpp"


	fclose( fseti );
	delete file;
//	::SetCursor(hcurSave);
	return ;
	}


