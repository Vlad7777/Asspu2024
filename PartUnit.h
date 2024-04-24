//---------------------------------------------------------------------------
#ifndef PartUnitH
#define PartUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TPartForm : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TProgressBar *ProgressBar1;
    TBitBtn *BitBtn1;
    TDBGrid *DBGrid1;
    TDBGrid *DBGrid2;
    TDBGrid *DBGrid3;
    TDBNavigator *DBNavigator1;
    TDBGrid *DBGrid4;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
    __fastcall TPartForm(TComponent* Owner);

 //  My  functions
     void __fastcall ReadDB_FSETI(void);
  //   void __fastcall SpuRead(void);
     void __fastcall Sozset(void);
     void __fastcall Rang(void);
     void __fastcall Week(void);
     void __fastcall Krit(void);
     void __fastcall Flow(void);
     void __fastcall Seti(void);
  //   void __fastcall SpuWrite(void);
     void __fastcall WriteFSETI_DB(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TPartForm *PartForm;
//---------------------------------------------------------------------------
#endif
