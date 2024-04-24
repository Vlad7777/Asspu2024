//#include <owl\owlpch.h>
#include <stdlib.h>
#include <stdio.h>
#include <dir.h>
#include <mem.h>
#include <string.h>

#include "file_dbf.h"
#include "smuzi.str"
#include "smuzl_my.str"
#include "speci.str"
//#include "pack.str"
//#include "brigade.str"
#include "all_defi.h"
#include "PartUnit.h"

void __fastcall TPartForm::SpuWrite()
	{
//   HCURSOR hcurSave=::SetCursor(LoadCursor(NULL,IDC_WAIT));
	#include "str_fedi.cpp"
	struct fedi fe;
/*	cl=0; fseek(fseti,cl,0); #include "sscffedi.cpp"
	(UL) CriticalTime = (UL) fe.kn;
*/
	unsigned long StartTimeBlock;
	char StringTmp[ 12 ];
	FileDBF *file = new FileDBF( "smuzi.dbf" );
	struct smuzi SmuziStruct, *indexSmuziStruct = &SmuziStruct;
	file->readDBF( 0, (void *)indexSmuziStruct );
	strncpy( StringTmp, SmuziStruct.StartTime, 11 );
	StartTimeBlock = atol( StringTmp ) ;  // Day of begin maitenance block
// ultoa(CriticalTime, SmuziStruct.CriticalTime, 10 );// TKrit
	file->writeDBF( 0, (void *)indexSmuziStruct );
	delete file;
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
	file = new FileDBF( "smuzl.dbf" );
	struct smuzl_my SmuzlStruct, *indexSmuzlStruct = &SmuzlStruct;
				long i = 0;
	unsigned long Number;
	unsigned long ShiftStart;
	unsigned long ShiftFinish;
	unsigned long Duration;
    		 int  WeekEnd;
	unsigned long StartTime;
	unsigned long FinishTime;
             int Critical;

	while ( file->readDBF( i, (void *)indexSmuzlStruct ) )
		{
		if ( !file->IsDelRecord( i ) )
			{
			Number = atol( SmuzlStruct.Number );
			if ( Number != 0 )
				{
		 //   Read FSETI key  CL
				cl=rKK7;
			while (fseti)
			  {
			  fseek(fseti,cl,0);
			  #include "sscfsset.cpp"
					if ( Number == s.Number /* temp  number !!! */)
						  {
			//	   use functions dostounix, unixtodos
						// s.a15==0 && s.a22 > s.a23
						if (s.a22 > s.a23 )  s.a23 = s.a22; //  !!!!!!!!!
						StartTime = StartTimeBlock + (unsigned long)--s.a22 * 3600;
						ultoa( StartTime, SmuzlStruct.StartTime, 10 );
						FinishTime = StartTimeBlock + (unsigned long)--s.a23 * 3600;
						ultoa( FinishTime, SmuzlStruct.FinishTime, 10 );
						Duration  = (unsigned long)s.a15 * 3600;
						ultoa( Duration , SmuzlStruct.Duration, 10 );
		  //			itoa(  s.a7 /*!!!?*/ , SmuzlStruct.Percent, 10 );
						if ( s.a28 == 10 )
							 {
							 ShiftStart  = 28800;
							 ShiftFinish = 57600;
							 }
					  if ( s.a28 == 11 )
							 {
							 ShiftStart  = 28800;
							 ShiftFinish = 86400;
							 }
					  if ( s.a28 == 111 )
							 {
							 ShiftStart  = 0;
							 ShiftFinish = 86400;
							 }
					  ultoa( ShiftStart, SmuzlStruct.ShiftStart,  10 );
					  ultoa( ShiftFinish, SmuzlStruct.ShiftFinish, 10 );

					  if ( s.a32[0] == 1 )
							{
				 // 4 ???   Check
							 Critical = 4;
					  itoa( Critical, SmuzlStruct.Critical, 10 );
							}
						//  5 -> 1,   CHECK !!!  7  -> 0
						if ( s.a26 == 5) WeekEnd = 1;
						else  WeekEnd = 0;   // 7 - full week !!!
					  itoa( WeekEnd, SmuzlStruct.WeekEnd, 10 );
						//	opt resource  a31[] !!!
					ultoa( (unsigned long)s.a31[0], SmuzlStruct.Resource1, 10 );
					ultoa( (unsigned long)s.a31[1], SmuzlStruct.Resource2, 10 );
					ultoa( (unsigned long)s.a31[2], SmuzlStruct.Resource3, 10 );
					ultoa( (unsigned long)s.a31[3], SmuzlStruct.Resource4, 10 );
						break;
							}
						cl += MY_SZFSETI;

						 }
						file->writeDBF( i, (void *)indexSmuzlStruct );
					 }
		//		file->DelRecord( i );
				 }
			i++;
		}

	fclose( fseti );
	delete file;
//	::SetCursor(hcurSave);
	return;
	}


