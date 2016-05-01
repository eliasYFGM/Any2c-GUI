#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

//(*Headers(SettingsDialog)
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
//*)

class SettingsDialog: public wxDialog
{
	public:

		SettingsDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SettingsDialog();

		//(*Declarations(SettingsDialog)
		wxCheckBox* CheckBoxStringLiterals;
		wxButton* ButtonClose;
		wxCheckBox* CheckBoxHexValues;
		wxCheckBox* CheckBoxSStruct;
		wxButton* ButtonRestoreDefaults;
		wxCheckBox* CheckBoxLength;
		wxCheckBox* CheckBoxIncludeGuards;
		wxCheckBox* CheckBoxConst;
		//*)

	protected:

		//(*Identifiers(SettingsDialog)
		static const long ID_CHECKBOX6;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX4;
		static const long ID_CHECKBOX5;
		static const long ID_CHECKBOX1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(SettingsDialog)
		void OnButtonCloseClick(wxCommandEvent& event);
		void OnButtonRestoreDefaultsClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
