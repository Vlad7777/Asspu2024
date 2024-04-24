//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Project1.res");
USEUNIT("Week.cpp");
USEUNIT("Bibodfn.cpp");
USEUNIT("Blab.cpp");
USEUNIT("Blab1.cpp");
USEUNIT("Blab5.cpp");
USEUNIT("Burst.cpp");
USEUNIT("Critr.cpp");
USEUNIT("Delta.cpp");
USEUNIT("Dned.cpp");
USEUNIT("Dnires.cpp");
USEUNIT("Early.cpp");
USEUNIT("Ekviv.cpp");
USEUNIT("Flow.cpp");
USEUNIT("Good.cpp");
USEUNIT("Grupp1.cpp");
USEUNIT("Helpb.cpp");
USEUNIT("Helpu.cpp");
USEUNIT("Hweek.cpp");
USEUNIT("Inda.cpp");
USEUNIT("Indb.cpp");
USEUNIT("Kalenp.cpp");
USEUNIT("Kalenr.cpp");
USEUNIT("Maxtim.cpp");
USEUNIT("Mdtjob.cpp");
USEUNIT("Middle.cpp");
USEUNIT("Mysort.cpp");
USEUNIT("partproject.cpp");
USEUNIT("Polres.cpp");
USEUNIT("Rang.cpp");
USEUNIT("Sozset.cpp");
USEFORM("spudmunit.cpp", SPUDM); /* TDataModule: DesignClass */
USEUNIT("Bbod1f.cpp");
USEFORM("PartUnit.cpp", PartForm);
USEUNIT("Mall_vd.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TSPUDM), &SPUDM);
                 Application->CreateForm(__classid(TPartForm), &PartForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
