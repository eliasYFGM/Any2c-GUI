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

#include <wx/arrstr.h>
#include <wx/file.h>
#include <wx/filename.h>

//(*Headers(Raw2cDialog)
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
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

        wxArrayString files;
        wxString MakeVarString(wxString);
        bool ExportSourceData(wxFile&);
        bool ExportHeaderData(wxFile&, wxFileName&);

        //(*Handlers(Raw2cDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnCheckBoxDefaultSettingsClick(wxCommandEvent& event);
        void OnButtonBrowseClick(wxCommandEvent& event);
        void OnButtonExportClick(wxCommandEvent& event);
        void OnCheckBoxSStructClick(wxCommandEvent& event);
        void OnButtonExportHClick(wxCommandEvent& event);
        void OnCheckBoxDefaultsClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(Raw2cDialog)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_CHECKBOX1;
        static const long ID_CHECKBOX6;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_CHECKBOX4;
        static const long ID_CHECKBOX2;
        static const long ID_CHECKBOX3;
        static const long ID_CHECKBOX5;
        static const long ID_BUTTON2;
        static const long ID_BUTTON5;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        //*)

        //(*Declarations(Raw2cDialog)
        wxCheckBox* CheckBoxLengthVar;
        wxButton* ButtonExportH;
        wxCheckBox* CheckBoxHexValues;
        wxTextCtrl* TextCtrlFilename;
        wxCheckBox* CheckBoxSStruct;
        wxButton* Button2;
        wxButton* ButtonBrowse;
        wxStaticText* StaticText1;
        wxFileDialog* FileDialog1;
        wxTextCtrl* TextCtrlVarName;
        wxButton* ButtonExport;
        wxFileDialog* FileDialog2;
        wxCheckBox* CheckBoxConst;
        wxBoxSizer* BoxSizer1;
        wxStaticText* StaticText2;
        wxCheckBox* CheckBoxDefaults;
        wxButton* ButtonQuit;
        wxCheckBox* CheckBoxExportIncludeGuards;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // RAW2CMAIN_H
