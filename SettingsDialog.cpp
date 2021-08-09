#include "SettingsDialog.h"

//(*InternalHeaders(SettingsDialog)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(SettingsDialog)
const long SettingsDialog::ID_CHECKBOX2 = wxNewId();
const long SettingsDialog::ID_CHECKBOX1 = wxNewId();
const long SettingsDialog::ID_CHECKBOX5 = wxNewId();
const long SettingsDialog::ID_CHECKBOX4 = wxNewId();
const long SettingsDialog::ID_CHECKBOX6 = wxNewId();
const long SettingsDialog::ID_STATICTEXT1 = wxNewId();
const long SettingsDialog::ID_TEXTCTRL1 = wxNewId();
const long SettingsDialog::ID_BUTTON2 = wxNewId();
const long SettingsDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SettingsDialog,wxDialog)
	//(*EventTable(SettingsDialog)
	//*)
END_EVENT_TABLE()

SettingsDialog::SettingsDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SettingsDialog)
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, _("Change settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Settings"));
	CheckBoxLength = new wxCheckBox(this, ID_CHECKBOX2, _("Export \'length\' variable"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckBoxLength->SetValue(true);
	StaticBoxSizer1->Add(CheckBoxLength, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	CheckBoxStringLiterals = new wxCheckBox(this, ID_CHECKBOX1, _("Use string literals"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBoxStringLiterals->SetValue(true);
	CheckBoxStringLiterals->SetToolTip(_("This can help reduce the size of the generated files quite a bit.\n\nNote: \"unsigned\" type is ommited for _data."));
	StaticBoxSizer1->Add(CheckBoxStringLiterals, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	CheckBoxHexValues = new wxCheckBox(this, ID_CHECKBOX5, _("Use hex values instead of decimal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
	CheckBoxHexValues->SetValue(false);
	CheckBoxHexValues->Disable();
	StaticBoxSizer1->Add(CheckBoxHexValues, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	CheckBoxConst = new wxCheckBox(this, ID_CHECKBOX4, _("Add \"const\" to variable names"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	CheckBoxConst->SetValue(false);
	BoxSizer4->Add(CheckBoxConst, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	CheckBoxIncludeGuards = new wxCheckBox(this, ID_CHECKBOX6, _("Export #include guards in header"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
	CheckBoxIncludeGuards->SetValue(false);
	StaticBoxSizer1->Add(CheckBoxIncludeGuards, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Max characters per line:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlMaxChars = new wxTextCtrl(this, ID_TEXTCTRL1, _("100"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrlMaxChars->SetToolTip(_("Indicates the max length of the lines in the source file."));
	BoxSizer3->Add(TextCtrlMaxChars, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ButtonRestoreDefaults = new wxButton(this, ID_BUTTON2, _("Restore defaults"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(ButtonRestoreDefaults, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonClose = new wxButton(this, ID_BUTTON1, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(ButtonClose, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SettingsDialog::OnCheckBoxStringLiteralsClick);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SettingsDialog::OnTextCtrlMaxCharsText);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsDialog::OnButtonRestoreDefaultsClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsDialog::OnButtonCloseClick);
	//*)
}

SettingsDialog::~SettingsDialog()
{
	//(*Destroy(SettingsDialog)
	//*)
}

void SettingsDialog::OnButtonCloseClick(wxCommandEvent& event)
{
    long val;

    if (!TextCtrlMaxChars->GetValue().ToLong(&val, 10))
    {
        TextCtrlMaxChars->ChangeValue(wxT("80"));
    }
    else
    {
        if (val < 40)
        {
            TextCtrlMaxChars->ChangeValue(wxT("40"));
        }
        else if (val > 1024)
        {
            TextCtrlMaxChars->ChangeValue(wxT("1024"));
        }
    }

    EndModal(wxID_OK);
}

void SettingsDialog::OnButtonRestoreDefaultsClick(wxCommandEvent& event)
{
    CheckBoxLength->SetValue(true);
    CheckBoxStringLiterals->SetValue(true);
    CheckBoxConst->SetValue(false);
    CheckBoxHexValues->SetValue(false);
    CheckBoxIncludeGuards->SetValue(false);

    TextCtrlMaxChars->ChangeValue(wxT("100"));
}

void SettingsDialog::OnCheckBoxStringLiteralsClick(wxCommandEvent& event)
{
   if (!CheckBoxStringLiterals->GetValue()) {
      CheckBoxHexValues->Enable();
   } else {
      CheckBoxHexValues->Enable(false);
   }
}

void SettingsDialog::OnTextCtrlMaxCharsText(wxCommandEvent& event)
{
}
