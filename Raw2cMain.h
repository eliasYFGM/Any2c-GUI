/***************************************************************
 * Name:      Raw2cMain.h
 * Purpose:   Defines Application Frame
 * Author:    Elias (eliasyfgm@gmail.com)
 * Created:   2016-04-23
 * Copyright: Elias ()
 * License:
 **************************************************************/

#ifndef RAW2CMAIN_H
#define RAW2CMAIN_H

#include "SettingsDialog.h"

#include <fstream>
#include <wx/arrstr.h>
#include <wx/file.h>
#include <wx/filename.h>

//(*Headers(Raw2cDialog)
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Raw2cDialog: public wxDialog
{
    public:

        Raw2cDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~Raw2cDialog();

    private:

        SettingsDialog* settings_dlg;

        wxArrayString files;
        wxString MakeVarString(wxString);
        bool WriteSourceData(std::ofstream&);
        bool WriteHeaderData(std::ofstream&, wxFileName&);
        void DoExportSource();
        void DoExportHeader();

        //(*Handlers(Raw2cDialog)
        void OnQuit(wxCommandEvent& event);
        void OnButtonBrowseClick(wxCommandEvent& event);
        void OnButtonExportClick(wxCommandEvent& event);
        void OnButtonChangeSettingsClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(Raw2cDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BUTTON6;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_BUTTON2;
        static const long ID_BUTTON4;
        //*)

        //(*Declarations(Raw2cDialog)
        wxRadioButton* RadioButtonSource;
        wxRadioButton* RadioButtonHeader;
        wxTextCtrl* TextCtrlFilenames;
        wxButton* ButtonChangeSettings;
        wxStaticText* StaticText1;
        wxBitmapButton* BitmapButtonBrowse;
        wxFileDialog* FileDialog1;
        wxButton* ButtonExport;
        wxFileDialog* FileDialog2;
        wxBoxSizer* BoxSizer1;
        wxStaticText* StaticText2;
        wxButton* ButtonQuit;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // RAW2CMAIN_H
