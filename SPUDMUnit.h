//---------------------------------------------------------------------------
#ifndef SPUDMUnitH
#define SPUDMUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TSPUDM : public TDataModule
{
__published:	// IDE-managed Components
    TDatabase *Database1;
    TTable *SmuziTable;
    TDataSource *DataSource1;
    TDataSource *DataSource2;
    TTable *SmuzlTable;
    TTable *PackTable;
    TDataSource *DataSource3;
    TDataSource *DataSource4;
    TTable *BrigadeTable;
private:	// User declarations
public:		// User declarations
    __fastcall TSPUDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSPUDM *SPUDM;
//---------------------------------------------------------------------------
#endif
