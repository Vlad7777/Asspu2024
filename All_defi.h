			 /*  all_defi.c */

#define MY_MXNR 2000 //10000  ╩юышўхёЄтю ЁрсюЄ т ёхЄш
#define MY_MXNS 2000 //10000   /*  10000 */  /* 1900 well */
#define MY_MXLN 1000    /* м кс. кол-во р бот */
#define MY_MXCL 20     /* м кс. кол-во предшествующих р бот */
#define MY_NUN 1111    /* номер узл  н ч льный */
#define MY_NUK 9999    /* номер узл  конечный */
#define MY_NK -1       /* последний номер события в сети */
#define YES 1       /* д  */
#define NO 0        /* нет */
#define MY_SIZE1 80    /* р змер н именов ния р боты */
#define MY_SIZE2 46    /* р змер информ ционной строки */
#define MY_SIZE3 5     /* р змер код  узл  */
#define MY_TUP 200  /*  200  */   /* & for loop  also !!!!!!!!!!!!!!!!!!! */
#define MY_REST 30         /*  holydays */
#define MY_TMAX 100  //???175 //??? + TT    /* need 200  max t dir  */
#define MY_KOLRU  2000 // was 400 May be 2000 end more !!!!!!!!!!!!!!!!!!!!!!!!!!
#define MY_KOLRB  2000 // was 400
#define MY_MXNU 300 //70  /*   max  uzlov   need 250 */
#define MY_MXNB 150    /* max brigade   need 150 */
#define MY_MR 4    /*   const !  */
#define MY_MXR 100     /* was 25!  */   /*  max kol resurs */
#define MY_KOLU 300         /*  analog maxnu ??????????? */
#define MY_KOLB 150     /*  -------- \ -----*/    /*  analog maxnb ??????????? */
#define MY_KSMEN 600      /* 600  */      /* like TT ? */
#define MY_TT 100 //???? 175  //  tmax 200         /*  like  tmax */ // TT !!!!!

//////////////////////  2000 !!!!!//////////////////////////////////
#define MY_MAXRU 500 //2000 // was 400  /*  more !!!!!!!!!!!! */   /*  analog KOLRU !!!!!!*/
//////////////////////////////////////   2000 ///////////
#define MY_MAXRB 500 //2000  // was 400   /*  analog KOLRB !!!!!!*/
////////////////////////////////////////////////////////////////////

#define MY_MAXRO 50        /* max remont organizacii */
///////////////////////////////  2000 //////////////////////////////////////
#define MY_KOLV 15000 //80000         /*   need 15000 for 2000 jobs !!!!! */
//////////////////////////////////////////////////////////////////////////
#define MY_NUSL 10 // "словия труд
#define MY_NF0 "fseti.fff"
#define MY_NFY "floy.fff"

#define MY_NFNR "fnes.f"
#define MY_NF "fpkbbod.fff"
#define MY_ID "smuzl.dbf"      /*  without f: !!!!!!!!!!!!  */
#define MY_NFU "fupi.f"
#define MY_NFN "fnsi.f"
#define MY_NSI "fpnsi.fff"

/********************************************************************/
/* #define MY_IRA "fdatr.f"                                            */
/* #define MY_IRA "fdatk.f"                                            */
/********************************************************************/
/* #define MY_IRA "fmax.f"                                             */
/********************************************************************/
#define MY_IRA "pkbbod.f"
#define MY_PF "pflow.f"
#define MY_PK "pkrit.f"
#define MY_PS "pseti.f"
#define MY_PW "pweek.f"
#define MY_PI "pincjob.f"
#define MY_PA "panaliz.f"
#define MY_PLAN "planz.f"
#define MY_ZAGR "pzagr.f"
#define MY_PGANT "pgant.f"
#define MY_SZFSETI 250
//////////////////////////////////////////BCB  !!!!!!!!!!!$$$$$$$$$!!!!

#define MY_SIZE 80     /*   WAS  SIZE !!!               I would like   80 !?????????????????   */
#define MY_KK00 0   /*  336  EXPERIMENT */
#define MY_KK01 1
#define MY_KK02 2
#define MY_KK03 3
#define MY_KK1 7
#define MY_KK2 35
#define MY_KK3 36
#define MY_KK4 66
#define MY_KK5 2245 /*    305  */    /*    2245       */
#define MY_KK6 2275  /* 335 */     /*       2275    */
#define MY_KK7 158
#define MY_KK8 2242  /* 300  */   /*  temporary ,will be       2242   */
#define MY_KK9 78
#define MY_KK10 157
#define MY_KK11 4
#define MY_KK12 6
#define MY_KK13 2250    // 74  !!!!!!!!!!!!!
#define MY_KK14 77
#define MY_KK20 67
#define MY_KK21 68
#define MY_KK22 69
#define MY_KK23 71
#define MY_KK24 72
#define MY_KK25 73
#define MY_KKEND 2300     /* 335    */       /*      2300        */
#define MY_TXTU 41   /*  add 1 byte !!!!!!!!!!!!!!!!!!!!!!!  */
#define MY_TXTUS 10    /*  add 1 byte !!!!!!!!!!!!!!!!!!!!!!!  */
#define MY_KORES 25
#define MY_EOFU 999
#define MY_EOFRS 999
#define MY_EOFP 99
#define MY_EOFB 9999

	       /*  define for FLOY   */
#define MY_KL1 1          /*   THINK   ABOUT    CONST !!!!!!!!!!!!! */
#define MY_KL2 11
#define MY_KL3 12
#define MY_KL4 40
#define MY_KL5 41
#define MY_KL6 2125
#define MY_KKENDFLOY 2300          /*      2300        */
#define MY_SZFLOY   250  /*   250  */

#define MY_TXTTIP  2    /* Длин  текст  тип   */
#define	MY_TXTST  13    /* Длин  текст  н именов ния электрост нции */
#define	MY_KOLSTAN  10   /* Количество электрост нций */    /* was 20  !!!!! */
#define	MY_KOLTIP  20   /* Количество типов  грег тов */
#define	MY_TXTPR  17    /* Длин  текст  плоного н именов ния профессии */
#define	MY_TXTPRS  6    /* Длин  текст  сокр щенного н именов ния профессии */
#define	MY_KOLPR  99    /* Количество видов профессий */
#define	MY_KOLORG  50   /* 99 */   /* Количество видов орг низ ций */
#define	MY_TXTORGS  6   /* Длин  текст  сокр щенного н именов ния орг низ ции */
#define	MY_TXTORG  25   /* Длин  текст  полного н именов ния орг низ ции */
#define	MY_KOLFIO  120  /* Количество ф милий бриг диров */
#define	MY_TXTFIO  21   /* Длин  текст  ф.и.о. */



