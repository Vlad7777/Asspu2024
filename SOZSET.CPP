		  /* function SOZSET.CPP  */

#include <stdio.h>

#include <string.h>
#include <dir.h>
#include <stdlib.h>

//#include <owl\owlpch.h>     BCB!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <stdlib.h>
#include <stdio.h>
#include <dir.h>
#include <mem.h>
#include <string.h>
//#include <dos.h>          BCB !!!!!!!!!!!!

//#include "file_dbf.h"      BCB!!!!!!!!!!!!!!!!!!!!!!
#include "smuzi.str"
#include "smuzl_my.str"
#include "speci.str"
//#include "pack.str"
//#include "brigade.str"

#include "all_defi.h"
//#include "part.h"         BCB !!!!!!!!!!!!!!!!!!



// void zfnsi(void);

#include "PartUnit.h"

void __fastcall TPartForm::Sozset(void)

 {


#include "str_sset.cpp"
#include "str_fedi.cpp"

 struct sset s;
 struct fedi fe;
 long rKK7,rNR,rKKEND;
 long cl,R1,R2 ;
 char prob;
 int i;

 int irKKEND,icl;
 int alarm;

	FILE  *fseti;


		  // Choosing Yes means to running SOZSET !!!
 fe.nr=fe.ns=fe.mr=fe.mxr=fe.rb0=0; fe.ny=fe.nb=0;
 fe.kza=fe.vzob=fe.kn=fe.tdir=fe.rsrv=0;
 fe.amn=fe.amx=fe.b1=fe.b3=0;
 fe.kk1=fe.kk2=fe.kk3=fe.kk4=fe.kk5=fe.kk6=fe.kk7=fe.kk8=0;
 fe.kstan=fe.dnd=fe.dod=0;
 fe.kagr=fe.god1=fe.dob=0;
 fe.kk9=fe.kk10=fe.kk21=fe.kk22=fe.kk23=fe.kk24=fe.kk25=0;
 fe.god1=fe.dkr=0;
 fe.kvd5=fe.kvd6=0;
 fe.kran=fe.krem=0;
 fe.rrq=0;

 s.Number=0;
 s.a1=s.a2=0;
 prob='\0';
 strnset(s.a3,prob,MY_SIZE);
 s.a4=s.a5=s.a6=s.a7=s.a8=0;
 for(i=0;i<MY_MR;i++){
 s.a10[i]=0;
 s.a11[i]=0; s.a12[i]=0; s.a13[i]=0;s.a30[i]=s.a31[i]=s.a32[i]=0;
 }
 s.a14=s.a15=s.a16=s.a17=s.a18=s.a19=s.a20=0;
 s.a21=s.a22=s.a23=s.a24=s.a25=s.a26=s.a27=s.a28=s.a29=0;

  //    printf("work program SOZSET \r");

		fseti= fopen(MY_NF0,"w");

		R1=MY_KK7; R2=MY_SZFSETI;
		rKK7=R1*R2 ;
		R1=MY_KKEND; R2= MY_SZFSETI;
		rKKEND=R1*R2  ;
		 cl=MY_KK00;

		 fseek(fseti,cl,0);
	 #include "sprffedi.cpp"
	 irKKEND=R1;
  //	 HCURSOR hcurSave=::SetCursor(LoadCursor(NULL,IDC_WAIT));
	 for (cl=0,icl=0; cl< rKKEND; cl= cl+MY_SZFSETI,icl++) {
	 fseek(fseti,cl,0);
	 #include "sprfsset.cpp"
	 }
	 fclose(fseti);
//	 ::SetCursor(hcurSave);

//	 zfnsi();     // !!!
 return;
  
 }



