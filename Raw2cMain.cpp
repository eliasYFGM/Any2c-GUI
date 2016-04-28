/***************************************************************
 * Name:      Raw2cMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Elias (eliasyfgm@gmail.com)
 * Created:   2016-04-23
 * Copyright: Elias ()
 * License:
 **************************************************************/

#include "Raw2cMain.h"
#include <wx/msgdlg.h>
#include <wx/filename.h>
#include <wx/aboutdlg.h>

//(*InternalHeaders(Raw2cDialog)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Raw2cDialog)
const long Raw2cDialog::ID_STATICTEXT1 = wxNewId();
const long Raw2cDialog::ID_TEXTCTRL1 = wxNewId();
const long Raw2cDialog::ID_BUTTON1 = wxNewId();
const long Raw2cDialog::ID_STATICTEXT2 = wxNewId();
const long Raw2cDialog::ID_TEXTCTRL2 = wxNewId();
const long Raw2cDialog::ID_STATICTEXT3 = wxNewId();
const long Raw2cDialog::ID_TEXTCTRL3 = wxNewId();
const long Raw2cDialog::ID_CHECKBOX4 = wxNewId();
const long Raw2cDialog::ID_CHECKBOX2 = wxNewId();
const long Raw2cDialog::ID_CHECKBOX3 = wxNewId();
const long Raw2cDialog::ID_CHECKBOX5 = wxNewId();
const long Raw2cDialog::ID_BUTTON2 = wxNewId();
const long Raw2cDialog::ID_BUTTON5 = wxNewId();
const long Raw2cDialog::ID_BUTTON3 = wxNewId();
const long Raw2cDialog::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Raw2cDialog,wxDialog)
    //(*EventTable(Raw2cDialog)
    //*)
END_EVENT_TABLE()

Raw2cDialog::Raw2cDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Raw2cDialog)
    wxGridSizer* GridSizer1;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, _("Any2c GUI"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Filename(s):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlFilename = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(TextCtrlFilename, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonBrowse = new wxButton(this, ID_BUTTON1, _("Browse"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    ButtonBrowse->SetToolTip(_("You can choose multiple files by holding \"Ctrl\" or \"Shift\"."));
    BoxSizer2->Add(ButtonBrowse, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Settings"));
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Variable prefix:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlVarName = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrlVarName->SetToolTip(_("This is also used to prefix _length and _data variables, too.\n\nNote: Default names are used when selecting multiple files."));
    BoxSizer3->Add(TextCtrlVarName, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Header macro:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer5->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlHeaderMacro = new wxTextCtrl(this, ID_TEXTCTRL3, _("_DATA_H"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrlHeaderMacro->SetToolTip(_("Macro to use when exporting a header."));
    BoxSizer5->Add(TextCtrlHeaderMacro, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1 = new wxGridSizer(2, 2, 0, 0);
    CheckBoxLengthVar = new wxCheckBox(this, ID_CHECKBOX4, _("Export [_length] variable"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    CheckBoxLengthVar->SetValue(true);
    CheckBoxLengthVar->SetToolTip(_("Use this if you prefer to have a \"_length\" variable instead of calling sizeof(*_data)."));
    GridSizer1->Add(CheckBoxLengthVar, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CheckBoxSStruct = new wxCheckBox(this, ID_CHECKBOX2, _("Use [static] data"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBoxSStruct->SetValue(false);
    CheckBoxSStruct->SetToolTip(_("This will add the [static] keyword to the data values.\n\nWarning: Static data may cause code duplication if used as a header!"));
    GridSizer1->Add(CheckBoxSStruct, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CheckBoxConst = new wxCheckBox(this, ID_CHECKBOX3, _("Constant values"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CheckBoxConst->SetValue(false);
    GridSizer1->Add(CheckBoxConst, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CheckBoxHexValues = new wxCheckBox(this, ID_CHECKBOX5, _("Data in hexadecimal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    CheckBoxHexValues->SetValue(false);
    CheckBoxHexValues->SetToolTip(_("This will produce much larger sources, although with fixed lines."));
    GridSizer1->Add(CheckBoxHexValues, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(GridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    ButtonExport = new wxButton(this, ID_BUTTON2, _("Export"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont ButtonExportFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !ButtonExportFont.Ok() ) ButtonExportFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    ButtonExportFont.SetWeight(wxBOLD);
    ButtonExport->SetFont(ButtonExportFont);
    BoxSizer4->Add(ButtonExport, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonExportH = new wxButton(this, ID_BUTTON5, _("Export .h"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    wxFont ButtonExportHFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !ButtonExportHFont.Ok() ) ButtonExportHFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    ButtonExportHFont.SetWeight(wxBOLD);
    ButtonExportH->SetFont(ButtonExportHFont);
    ButtonExportH->SetToolTip(_("Creates a C header file with [extern] declarations of the data (does not export the actual data!)."));
    BoxSizer4->Add(ButtonExportH, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON3, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer4->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonQuit = new wxButton(this, ID_BUTTON4, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer4->Add(ButtonQuit, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_MULTIPLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog2 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnButtonBrowseClick);
    Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnCheckBoxSStructClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnButtonExportClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnButtonExportHClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnAbout);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnQuit);
    //*)
}

Raw2cDialog::~Raw2cDialog()
{
    //(*Destroy(Raw2cDialog)
    //*)
}

wxString Raw2cDialog::MakeVarString(wxString str)
{
    for (wxString::size_type i=0; i<str.Len(); ++i)
    {
        if ( (str[i] < 0x30)
          || (str[i] > 0x39 && str[i] < 0x41)
          || (str[i] > 0x5a && str[i] < 0x61)
          || (str[i] > 0x7a) )
        {
            str.SetChar(i, '_');
        }
    }

    if (str[0] >= 0x30 && str[0] <= 0x39)
    {
        str = wxString::Format(wxT("_%s"), str.c_str());
    }

    return str;
}

bool Raw2cDialog::ExportSourceData(wxFile& out)
{
    if (!files.GetCount() || !out.IsOpened())
    {
        return false;
    }

    for (wxArrayString::size_type i=0; i<files.GetCount(); ++i)
    {
        wxString str;

        wxFile file(files[i]);
        wxFileOffset length = file.Length();

        wxFileName name(files[i]);
        wxString varname = MakeVarString(name.GetFullName());

        str << wxT("/*\n");
        str << wxT("  ") << name.GetFullName() << wxT("\n");
        str << wxT("  ") << length << wxT(" bytes\n");
        str << wxT("*/\n\n");

        if (CheckBoxLengthVar->GetValue())
        {
            if (CheckBoxSStruct->GetValue()) str << wxT("static ");
            if (CheckBoxConst->GetValue()) str << wxT("const ");
            str << wxT("unsigned int ") << varname << wxT("_length = ")
              << length << wxT(";\n");
        }

        if (CheckBoxSStruct->GetValue()) str << wxT("static ");
        if (CheckBoxConst->GetValue()) str << wxT("const ");
        str << wxT("unsigned char ") << varname << wxT("_data[")
          << length << wxT("] =\n");
        str << wxT("{\n");
        str << wxT("  ");

        int bytes_on_line = 0;
        int max_bytes_on_line = CheckBoxHexValues->GetValue() ? 15 : 20;
        int charc = 0;

        while (!file.Eof())
        {
            unsigned char c;
            wxString byte_str;

            file.Read(&c, 1);

            if (CheckBoxHexValues->GetValue())
            {
                byte_str = wxString::Format(wxT("0x%02x"), c);
            }
            else
            {
                byte_str = wxString::Format(wxT("%u"), c);
                charc += byte_str.Len();
            }

            if (file.Tell() != length)
            {
                byte_str << wxT(",");
                ++charc;
            }

            str << byte_str;

            if (CheckBoxHexValues->GetValue())
            {
                ++bytes_on_line;

                if (bytes_on_line == max_bytes_on_line && file.Tell() != length)
                {
                    str << wxT("\n  ");
                    bytes_on_line = 0;
                }
            }
            else
            {
                if (charc >= 75 && file.Tell() != length)
                {
                    str << wxT("\n  ");
                    charc = 0;
                }
            }
        }

        str << wxT("\n};\n\n");

        out.Write(str);

        file.Close();
    }

    return true;
}

bool Raw2cDialog::ExportHeaderData(wxFile& out)
{
    if (!out.IsOpened())
    {
        return false;
    }

    wxString str;

    str << wxT("#ifndef ") << TextCtrlHeaderMacro->GetValue() << wxT("\n");
    str << wxT("#define ") << TextCtrlHeaderMacro->GetValue() << wxT("\n");
    str << wxT("\n");

    for (wxArrayString::size_type i=0; i<files.GetCount(); ++i)
    {
        wxFile file(files[i]);
        wxFileOffset length = file.Length();
        file.Close();

        wxFileName name(files[i]);
        wxString varname = MakeVarString(name.GetFullName());

        if (CheckBoxLengthVar->GetValue())
        {
            str << wxT("extern ");

            if (CheckBoxConst->GetValue())
            {
                str << wxT("const ");
            }

            str << wxT("unsigned int ") << varname << wxT("_length;\n");
        }

        str << wxT("extern ");

        if (CheckBoxConst->GetValue())
        {
            str << wxT("const ");
        }

        str << wxT("unsigned char ") << varname << wxT("_data[") << length
          << wxT("];\n");

        if (CheckBoxLengthVar->GetValue())
        {
            str << wxT("\n");
        }
    }

    if (!CheckBoxLengthVar->GetValue())
    {
        str << wxT("\n");
    }

    str << wxT("#endif /* ") << TextCtrlHeaderMacro->GetValue()
      << wxT(" */\n");

    out.Write(str);

    return true;
}

void Raw2cDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Raw2cDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg;

    msg << wxT("Any2c GUI (git)\n");
    msg << wxT("Utility to convert any file(s) to a C/C++ byte array.\n");
    msg << wxT("(C) 2014-2016 Elias O. <eliasyfgm@gmail.com>");

    wxMessageBox(msg, wxT("About Any2c"), wxOK | wxCENTRE, this);
}

void Raw2cDialog::OnButtonBrowseClick(wxCommandEvent& event)
{
    if (FileDialog1->ShowModal() == wxID_OK)
    {
        FileDialog1->GetPaths(files);

        if (files.GetCount() > 1)
        {
            wxString str;

            for (wxArrayString::size_type i=0; i<files.GetCount(); ++i)
            {
                str << wxT("\"") << files[i] << wxT("\"") << wxT(" ");
            }

            TextCtrlFilename->SetValue(str);
            TextCtrlVarName->SetValue(wxT("<Multiple files selected>"));
            TextCtrlVarName->Enable(false);
        }
        else
        {
            TextCtrlFilename->SetValue(FileDialog1->GetPath());
            wxFileName fn(FileDialog1->GetPath());
            TextCtrlVarName->SetValue(MakeVarString(fn.GetFullName()));
            TextCtrlVarName->Enable(true);
        }
    }
}

void Raw2cDialog::OnButtonExportClick(wxCommandEvent& event)
{
    if (!files.GetCount())
    {
        wxMessageBox(wxT("No file(s) choosen"), wxMessageBoxCaptionStr,
            wxOK | wxCENTRE, this);

        return;
    }

    if (FileDialog2->ShowModal() == wxID_OK)
    {
        wxFile file_source(FileDialog2->GetPath(), wxFile::write);

        if (ExportSourceData(file_source))
        {
            wxString msg;

            if (!CheckBoxSStruct->GetValue())
            {
                msg << wxT("Source file created succesfully!");
                msg << wxT("\n\nWould you like to create a header file now?");

                if (wxMessageBox(msg, wxMessageBoxCaptionStr,
                  wxYES_NO | wxCENTRE, this) == wxYES)
                {
                    OnButtonExportHClick(event);
                }
            }
            else
            {
                msg << wxT("Source file created succesfully!");

                wxMessageBox(msg, wxMessageBoxCaptionStr, wxOK | wxCENTRE,
                  this);
            }
        }

        file_source.Close();
    }
}

void Raw2cDialog::OnCheckBoxSStructClick(wxCommandEvent& event)
{
    if (CheckBoxSStruct->GetValue())
    {
        TextCtrlHeaderMacro->Enable(false);
        ButtonExportH->Enable(false);
    }
    else
    {
        TextCtrlHeaderMacro->Enable(true);
        ButtonExportH->Enable(true);
    }
}

void Raw2cDialog::OnButtonExportHClick(wxCommandEvent& event)
{
    if (!files.GetCount())
    {
        wxMessageBox(wxT("No file(s) choosen"), wxMessageBoxCaptionStr,
            wxOK | wxCENTRE, this);

        return;
    }

    if (FileDialog2->ShowModal() == wxID_OK)
    {
        wxFile file_header(FileDialog2->GetPath(), wxFile::write);

        if (ExportHeaderData(file_header))
        {
            wxMessageBox(wxT("Header file exported succesfully!"),
              wxMessageBoxCaptionStr, wxOK | wxCENTRE, this);
        }

        file_header.Close();
    }
}
