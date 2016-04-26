/***************************************************************
 * Name:      Raw2cApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Elias (eliasyfgm@gmail.com)
 * Created:   2016-04-23
 * Copyright: Elias ()
 * License:
 **************************************************************/

#include "Raw2cApp.h"

//(*AppHeaders
#include "Raw2cMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Raw2cApp);

bool Raw2cApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Raw2cDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
