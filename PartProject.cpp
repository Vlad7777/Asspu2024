//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("PartProject.res");
USEFORM("PartUnit.cpp", PartForm);
USEUNIT("Sozset.cpp");
USEFORM("SPUDMUnit.cpp", SPUDM); /* TDataModule: DesignClass */
USEUNIT("Critr.cpp");
USEUNIT("Flow.cpp");
USEUNIT("Middle.cpp");
USEUNIT("Rang.cpp");
USEUNIT("Week.cpp");
USEUNIT("Bbod1f.cpp");
USEUNIT("Bibodfn.cpp");
USEUNIT("Blab.cpp");
USEUNIT("Blab1.cpp");
USEUNIT("Blab5.cpp");
USEUNIT("Burst.cpp");
USEUNIT("Delta.cpp");
USEUNIT("Dned.cpp");
USEUNIT("Dnires.cpp");
USEUNIT("Early.cpp");
USEUNIT("Ekviv.cpp");
USEUNIT("Good.cpp");
USEUNIT("Grupp1.cpp");
USEUNIT("Helpb.cpp");
USEUNIT("Helpu.cpp");
USEUNIT("Hweek.cpp");
USEUNIT("Inda.cpp");
USEUNIT("Indb.cpp");
USEUNIT("Kalenp.cpp");
USEUNIT("Kalenr.cpp");
USEUNIT("Mallc_my.cpp");
USEUNIT("Maxtim.cpp");
USEUNIT("Mdtjob.cpp");
USEUNIT("Polres.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TPartForm), &PartForm);
        Application->CreateForm(__classid(TSPUDM), &SPUDM);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
