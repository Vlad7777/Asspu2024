//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PartUnit.h"
#include "SPUDMUnit.h"

////////////////////////// For  DB -> FSETI !!!!  /////////////////////
//#include "file_dbf.h"   // TMP !!!!!!!!!!!
#include <stdlib.h>
#include <stdio.h>
#include <dir.h>
#include <mem.h>
#include <string.h>
#include <dos.h>
//////////////////////////////////////////////////////////
#include "smuzi.str"
#include "smuzl_my.str"
#include "speci.str"
#include "pack.str"
#include "brigade.str"
#include "all_defi.h"
////////////////////////////////////////////////

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPartForm *PartForm;
//---------------------------------------------------------------------------
__fastcall TPartForm::TPartForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPartForm::Button1Click(TObject *Sender)
{

  Sozset();     //   It is  need  to  make  the SWICH !!!
  ReadDB_FSETI();
  Rang();
  Week();
  Krit();
  Flow();
  Seti();
  WriteFSETI_DB();

}
//---------------------------------------------------------------------------
void __fastcall TPartForm::ReadDB_FSETI(void)

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
/*************************$$$$$$$$########### TEMPORARY  !!!!! ****
	fe.ny = fe.nb = 8;    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	fe.dnd = 710;
//	fe.dod = 725;
	fe.kagr = 2001;
//	fe.god1= 1995;
	fe.dob = 701;
	fe.dkr = 2;
	fe.dr  = 1;
/*********************************************************************/

//	FileDBF *file = new FileDBF( "smuzi.dbf" );   //?????????

//    SPUDM->Database1->Open();
    SPUDM->SmuziTable->Open();

	struct smuzi SmuziStruct, *indexSmuziStruct = &SmuziStruct;
   ///	file->readDBF( 0, (void *)indexSmuziStruct );

    unsigned long StartTime, FinishTime;

    StartTime =  SPUDM->SmuziTable->FieldByName("StartTime")->AsInteger;
    FinishTime =  SPUDM->SmuziTable->FieldByName("FinishTime")->AsInteger;
    SPUDM->SmuziTable->Close(); // !!!!!!!!!!!!
 //   SPUDM->Database1->Close();


 //	strncpy( StringTmp, SmuziStruct.StartTime, 11 );
 //	unsigned long 	StartTimeBlock	 = atol( StringTmp ) ;
    unsigned long 	StartTimeBlock =  StartTime;
 //	strncpy( StringTmp, SmuziStruct.FinishTime, 11 );
 //	unsigned long 	FinishTimeBlock = atol( StringTmp ) ;
    unsigned long 	FinishTimeBlock =  FinishTime;
   //	delete file;

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

//	file = new FileDBF( "smuzl.dbf" );

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

/*
	while ( file->readDBF( i, (void *)indexSmuzlStruct ) )
		if ( !file->IsDelRecord( i++ ) )
			{
*/   int rr;
     SPUDM->SmuzlTable->Open();
     for ( rr = 0; rr < SPUDM->SmuzlTable->RecordCount; rr++ )
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

  // ????	strncpy( StringTmp, SmuzlStruct.Number, 11 );
    //  s.a7  ->  NUMBER   !!!  WAS !!!!!!!!!
	//  s.Number  = atoi( StringTmp ) ;     // TEMPORARY  in s.a7!!!
     s.Number = SPUDM->SmuzlTable->FieldByName("Numbr")->AsInteger;
//	strncpy( s.a3 , SmuzlStruct.Name, MY_SIZE );
// 	s.a3[MY_SIZE-1]='\0';
    //  1 variant
//    AnsiString S =  SPUDM->SmuzlTable->FieldByName("Naimrab")->AsString;
//    strcpy (  s.a3 , S.c_str());
    // 2 variant the same
    strncpy( s.a3 , SPUDM->SmuzlTable->FieldByName("Naimrab")->AsString.c_str(), MY_SIZE ); //!!!!!!!!
    //	strncpy( StringTmp2, SmuzlStruct.Priz, 1 );
//						  s.a5  = atoi( StringTmp2 ) ;
    s.a5 = SPUDM->SmuzlTable->FieldByName("Priz")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.StartKnot, 11 );
//						  s.a1  = atol( StringTmp ) ;
    s.a1 = SPUDM->SmuzlTable->FieldByName("Kodrab_pi")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.FinishKnot, 11 );
//						  s.a2  = atol( StringTmp ) ;
    s.a2 = SPUDM->SmuzlTable->FieldByName("Kodrab_pj")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.Duration, 11 );
//						  s.a15 = atol( StringTmp ) / 3600 ;
    s.a15 = SPUDM->SmuzlTable->FieldByName("Prodoj")->AsInteger / 3600;
//	strncpy( StringTmp, SmuzlStruct.Kodorg, 11 );
//						  s.a4	= atol( StringTmp );
    s.a4 = SPUDM->SmuzlTable->FieldByName("Kodorg")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.IndexShift, 11 );
//						  s.a29		= atoi( StringTmp ) ;
    s.a29 = SPUDM->SmuzlTable->FieldByName("Trebsm")->AsInteger;
//////////////////////////////////////////////////////////////////
//	strncpy( StringTmp, SmuzlStruct.Kodspec1, 11 );
//						  s.a10[0]	= atoi( StringTmp ) ;
    s.a10[0] = SPUDM->SmuzlTable->FieldByName("Kodspec1")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceMin1, 11 );
//						  s.a11[0]	= atoi( StringTmp ) ;
    s.a11[0] = SPUDM->SmuzlTable->FieldByName("Min1")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceMax1, 11 );
//						  s.a12[0]  = atoi( StringTmp ) ;
    s.a12[0] = SPUDM->SmuzlTable->FieldByName("Max1")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceOpt1, 11 );
//						  s.a13[0]	= atoi( StringTmp ) ;
    s.a13[0] = SPUDM->SmuzlTable->FieldByName("Opt1")->AsInteger;
		// Average !!!!  AND  REST!!!!  s.a13[0]	= (s.a11[0] +	s.a12[0])/2;
//	strncpy( StringTmp, SmuzlStruct.Volume1, 11 );
//					 VolumeTmp  += atol( StringTmp );
    VolumeTmp  += SPUDM->SmuzlTable->FieldByName("Volume1")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.Kodspec2, 11 );
//						  s.a10[1]	= atoi( StringTmp ) ;
    s.a10[1] = SPUDM->SmuzlTable->FieldByName("Kodspec2")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceMin2, 11 );
//						  s.a11[1]		= atoi( StringTmp ) ;
    s.a11[1] = SPUDM->SmuzlTable->FieldByName("Min2")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceMax2, 11 );
//						  s.a12[1]		= atoi( StringTmp ) ;
    s.a12[1] = SPUDM->SmuzlTable->FieldByName("Max2")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceOpt2, 11 );
					  //	  s.a13[1]		= atoi( StringTmp ) ;
    s.a13[1] = SPUDM->SmuzlTable->FieldByName("Opt2")->AsInteger;
						  s.a13[1]	= (s.a11[1] +	s.a12[1])/2;
//	strncpy( StringTmp, SmuzlStruct.Volume2, 11 );
//						  VolumeTmp  += atol( StringTmp ) ;
    VolumeTmp  += SPUDM->SmuzlTable->FieldByName("Volume2")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.Kodspec3, 11 );
//						  s.a10[2]		= atoi( StringTmp ) ;
    s.a10[2] = SPUDM->SmuzlTable->FieldByName("Kodspec3")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceMin3, 11 );
//						  s.a11[2]		= atoi( StringTmp ) ;
    s.a11[2] = SPUDM->SmuzlTable->FieldByName("Min3")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceMax3, 11 );
//						  s.a12[2]		= atoi( StringTmp ) ;
    s.a12[2] = SPUDM->SmuzlTable->FieldByName("Max3")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceOpt3, 11 );
					  //	  s.a13[2]		= atoi( StringTmp ) ;
    s.a13[2] = SPUDM->SmuzlTable->FieldByName("Opt3")->AsInteger;
						  s.a13[2]	= (s.a11[2] +	s.a12[2])/2;
//	strncpy( StringTmp, SmuzlStruct.Volume3, 11 );
//						  VolumeTmp += atol( StringTmp ) ;
    VolumeTmp  += SPUDM->SmuzlTable->FieldByName("Volume3")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.Kodspec4, 11 );
//						  s.a10[3]	= atoi( StringTmp ) ;
    s.a10[3] = SPUDM->SmuzlTable->FieldByName("Kodspec4")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceMin4, 11 );
//						  s.a11[3]	= atoi( StringTmp ) ;
    s.a11[3] = SPUDM->SmuzlTable->FieldByName("Min4")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceMax4, 11 );
//						  s.a12[3] 	= atoi( StringTmp ) ;
    s.a12[3] = SPUDM->SmuzlTable->FieldByName("Max4")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.ResourceOpt4, 11 );
					 //	  s.a13[3]		= atoi( StringTmp ) ;
    s.a13[3] = SPUDM->SmuzlTable->FieldByName("Opt4")->AsInteger;
						  s.a13[3]	= (s.a11[3] +	s.a12[3])/2;
//	strncpy( StringTmp, SmuzlStruct.Volume4, 11 );
//						  VolumeTmp += atol( StringTmp );
    VolumeTmp  += SPUDM->SmuzlTable->FieldByName("Volume4")->AsInteger;
//	strncpy( StringTmp, SmuzlStruct.Kodob, 11 );
//								= atol( StringTmp ) ;
       //  where  s.aX  for kodob ?????

//	strncpy( StringTmp, SmuzlStruct.Kodpack, 11 );
//						  s.a32[3] = atoi( StringTmp ) ;
    s.a32[3] = SPUDM->SmuzlTable->FieldByName("Kodpack")->AsInteger;

                          // OK !!!
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
    SPUDM->SmuzlTable->Next();
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
//	delete file;

    SPUDM->SmuzlTable->Close();
  //  SPUDM->Database1->Close();

    //	::SetCursor(hcurSave);
	return ;

}
//---------------------------------------------------------------------------
void __fastcall TPartForm::WriteFSETI_DB(void)
	{
//   HCURSOR hcurSave=::SetCursor(LoadCursor(NULL,IDC_WAIT));
/////////////////////////////////////////////////////////////////////////
	long cl;
	int NR;
	long R1 = MY_KK7;
	long R2 = MY_SZFSETI;
	long rKK7 = R1*R2; /*  KK7*SZFSETI;   */
	FILE *fseti = fopen(MY_NF0,"r+");
	#include "str_sset.cpp"
	struct sset s;
//////////////////////////////////////////////////////////////////////////


	#include "str_fedi.cpp"
	struct fedi fe;
	cl=0; fseek(fseti,cl,0);
    #include "sscffedi.cpp"
//   (UL) CriticalTime = (UL) fe.kn;

	unsigned long StartTimeBlock;
	char StringTmp[ 12 ];
//	FileDBF *file = new FileDBF( "smuzi.dbf" );
	struct smuzi SmuziStruct, *indexSmuziStruct = &SmuziStruct;

//  SPUDM->Database1->Open();
    SPUDM->SmuziTable->Open();

    sprintf (SmuziStruct.Name, "%s", SPUDM->SmuziTable->FieldByName("NamePack")->AsString );
    sprintf (SmuziStruct.StartTime, "%s", SPUDM->SmuziTable->FieldByName("StartTime")->AsString );
    sprintf (SmuziStruct.FinishTime, "%s", SPUDM->SmuziTable->FieldByName("FinishTime")->AsString );


  //	file->readDBF( 0, (void *)indexSmuziStruct );
    //  NOT DONE !!!!!
	strncpy( StringTmp, SmuziStruct.StartTime, 11 );
	StartTimeBlock = atol( StringTmp ) ;  // Day of begin maitenance block
// ultoa(CriticalTime, SmuziStruct.CriticalTime, 10 );// TKrit

//	file->writeDBF( 0, (void *)indexSmuziStruct );
//	delete file;

 //   SPUDM->SmuziTable->FieldByName("StartTime")->AsInteger  =  StartTime;
    SPUDM->SmuziTable->Close(); // !!!!!!!!!!!!
//  SPUDM->Database1->Close();

//	file = new FileDBF( "smuzl.dbf" );   // !!! USER !!!!
	struct smuzl_my SmuzlStruct, *indexSmuzlStruct = &SmuzlStruct;
       		 long i = 0;
	unsigned long Number = 0; // !!!
	unsigned long ShiftStart;
	unsigned long ShiftFinish;
	unsigned long Duration;
    		 int  WeekEnd;
	unsigned long StartTime;
	unsigned long FinishTime;
             int  Critical;
             int  Shift;
    //  char  Namerab[200];   // New !!!!!!!!!!!

//////////////////////////////// NEW BCB !!!!//////////////////////
  //  SPUDM->Database1->Open();   // Second Open !!!???
    int rr;

 //	while ( file->readDBF( i, (void *)indexSmuzlStruct ) ) {
       SPUDM->SmuzlTable->Open();
//???        SPUDM->DataSource2->DataSet->Active = true;
    //    SPUDM->SmuzlTable->Edit(); // ????
    ////////////////    while (!SPUDM->SmuzlTable->Eof){
    for ( rr = 0; rr < SPUDM->SmuzlTable->RecordCount; rr++ )
          {
          SPUDM->SmuzlTable->Edit(); //

		//if ( !file->IsDelRecord( i ) )
          if (  Number >= 0) //  lipa !!!!!!!!!!!!!!!!!!!
			{
		 	//Number = atol( SmuzlStruct.Number );
            Number = SPUDM->SmuzlTable->FieldByName("Numbr")->AsInteger;
		 	if ( Number != 0 )
           		{
		 //   Read FSETI key  CL
				cl=rKK7;
			while (fseti)
			  {
              fseek(fseti, cl,0);
			  #include "sscfsset.cpp"
				 	if ( Number == s.Number ) //
                      {

       //   ################ Write Name !!!!!!!!!!!!
       // strncpy( Namerab,  s.a3 , MY_SIZE );  //??????????
       // Namerab[MY_SIZE] = '\0';  //string[3] = '\0';

       ///////////////////24.04.99 Double of letters in name !!!????????
      //  s.a3[MY_SIZE] = '\0';
      //  SPUDM->SmuzlTable->FieldByName("Naimrab")->AsString = s.a3;  // s.a3 + '\0 '  !!!;
      ///////////////////////////////////////////////////////////////////
			//	Use functions dostounix, unixtodos
						// s.a15==0 && s.a22 > s.a23
						if (s.a22 > s.a23 )  s.a23 = s.a22; //  !!!!!!!!!
						StartTime = StartTimeBlock + (unsigned long)--s.a22 * 3600;
 					  //ultoa( StartTime, SmuzlStruct.StartTime, 10 );
                        SPUDM->SmuzlTable->FieldByName("StartTime")->AsInteger  =  StartTime;

						FinishTime = StartTimeBlock + (unsigned long)--s.a23 * 3600;
					  //ultoa( FinishTime, SmuzlStruct.FinishTime, 10 );
                        SPUDM->SmuzlTable->FieldByName("FinishTime")->AsInteger  =  FinishTime;

/////////////////////////////  New fields !!! ////////////////////
        int start_int = StartTime / 86400;
        int finish_int = FinishTime / 86400;
//    Table1Date_Start->AsDateTime = StrToDateTime("01.01.1970") + Table1STARTTIME->AsInteger / 86400;
//    Table1Date_Finish->AsDateTime = StrToDateTime("01.01.1970") + Table1FINISHTIME->AsInteger / 86400;
      SPUDM->SmuzlTable->FieldByName("DateStart")->AsDateTime  =  StrToDateTime("01.01.1970") +  start_int; // StartTime / 86400;
      SPUDM->SmuzlTable->FieldByName("DateFinish")->AsDateTime =  StrToDateTime("01.01.1970") +  finish_int; // FinishTime / 86400;

//        SPUDM->SmuzlTableDATESTART->AsDateTime = StrToDateTime("01.01.1970") +  start_int;
//        SPUDM->SmuzlTableDATEFINISH->AsDateTime = StrToDateTime("01.01.1970") +  finish_int;
////////////////////////////////////////////////////////////////////////////////////////////
						Duration  = (unsigned long)s.a15 * 3600;
					  //	ultoa( Duration , SmuzlStruct.Duration, 10 );
                        SPUDM->SmuzlTable->FieldByName("Prodoj")->AsInteger  =  Duration;

		     		 //  ????!!!! s.a7	itoa(  s.a7  , SmuzlStruct.Percent, 10 );
						if ( s.a28 == 10 )
							 {
                             Shift = 1;
							 ShiftStart  = 28800;
							 ShiftFinish = 57600;
							 }
					  if ( s.a28 == 11 )
							 {
                             Shift = 2;
							 ShiftStart  = 28800;
							 ShiftFinish = 86400;
							 }
					  if ( s.a28 == 111 )
							 {
                             Shift = 3;
							 ShiftStart  = 0;
							 ShiftFinish = 86400;
							 }
				  //ultoa( ShiftStart, SmuzlStruct.ShiftStart,  10 );
                    SPUDM->SmuzlTable->FieldByName("ShiftStart")->AsInteger  =  ShiftStart;
				  //ultoa( ShiftFinish, SmuzlStruct.ShiftFinish, 10 );
                    SPUDM->SmuzlTable->FieldByName("ShiftFin")->AsInteger  =  ShiftFinish;
                    SPUDM->SmuzlTable->FieldByName("Trebsm")->AsInteger  =  Shift;

					  if ( s.a32[0] == 1 )  Critical = 4;
                         else  Critical = 0;
				   //itoa( Critical, SmuzlStruct.Critical, 10 );
                      SPUDM->SmuzlTable->FieldByName("Critical")->AsInteger  =  Critical;



						//  5 -> 1,   CHECK !!!  7  -> 0
						if ( s.a26 == 5) WeekEnd = 1;
						else  WeekEnd = 0;   // 7 - full week !!!
					//itoa( WeekEnd, SmuzlStruct.WeekEnd, 10 );
                       SPUDM->SmuzlTable->FieldByName("Week")->AsInteger  = WeekEnd;
						//	opt resource  a31[] !!!
					//ultoa( (unsigned long)s.a31[0], SmuzlStruct.Resource1, 10 );
                      SPUDM->SmuzlTable->FieldByName("Select1")->AsInteger  = s.a31[0];
					//ultoa( (unsigned long)s.a31[1], SmuzlStruct.Resource2, 10 );
                      SPUDM->SmuzlTable->FieldByName("Select2")->AsInteger  = s.a31[1];
					//ultoa( (unsigned long)s.a31[2], SmuzlStruct.Resource3, 10 );
                      SPUDM->SmuzlTable->FieldByName("Select3")->AsInteger  = s.a31[2];
					//ultoa( (unsigned long)s.a31[3], SmuzlStruct.Resource4, 10 );
                      SPUDM->SmuzlTable->FieldByName("Select4")->AsInteger  = s.a31[3];

						break;    //?
							}
						cl += MY_SZFSETI;
                       	 }
             //		file->writeDBF( i, (void *)indexSmuzlStruct );
             // writeDBF() ; // !!!!!!!!!!!!!!!!!!
                    SPUDM->SmuzlTable->Next();
					 }
		// ?? file->DelRecord( i );
				 }
			i++;
		}

     SPUDM->SmuzlTable->Close(); // !!!!!!!!!!!!
 //    SPUDM->Database1->Close();

	fclose( fseti );     //!!!
//	delete file;        !!!!!  Not EXIST !!!!
//	::SetCursor(hcurSave);
	return;


}
//---------------------------------------------------------------------------

void __fastcall TPartForm::BitBtn1Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

