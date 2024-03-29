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
#include <wx/aboutdlg.h>
#include <wx/textfile.h>

//(*InternalHeaders(Raw2cDialog)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//helper functions
enum wxbuildinfoformat {
   short_f, long_f
};

wxString wxbuildinfo( wxbuildinfoformat format )
{
   wxString wxbuild( wxVERSION_STRING );

   if ( format == long_f ) {
#if defined(__WXMSW__)
      wxbuild << _T( "-Windows" );
#elif defined(__UNIX__)
      wxbuild << _T( "-Linux" );
#endif

#if wxUSE_UNICODE
      wxbuild << _T( "-Unicode build" );
#else
      wxbuild << _T( "-ANSI build" );
#endif // wxUSE_UNICODE
   }

   return wxbuild;
}

//(*IdInit(Raw2cDialog)
const long Raw2cDialog::ID_STATICTEXT1 = wxNewId();
const long Raw2cDialog::ID_BITMAPBUTTON1 = wxNewId();
const long Raw2cDialog::ID_BUTTON6 = wxNewId();
const long Raw2cDialog::ID_TEXTCTRL1 = wxNewId();
const long Raw2cDialog::ID_STATICTEXT2 = wxNewId();
const long Raw2cDialog::ID_RADIOBUTTON1 = wxNewId();
const long Raw2cDialog::ID_RADIOBUTTON2 = wxNewId();
const long Raw2cDialog::ID_BUTTON2 = wxNewId();
const long Raw2cDialog::ID_BUTTON1 = wxNewId();
const long Raw2cDialog::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE( Raw2cDialog,wxDialog )
   //(*EventTable(Raw2cDialog)
   //*)
END_EVENT_TABLE()

Raw2cDialog::Raw2cDialog( wxWindow* parent,wxWindowID id )
{
   //(*Initialize(Raw2cDialog)
   wxBoxSizer* BoxSizer3;
   wxBoxSizer* BoxSizer2;
   wxBoxSizer* BoxSizer4;

   Create(parent, wxID_ANY, _("Any2c GUI"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
   BoxSizer1 = new wxBoxSizer(wxVERTICAL);
   BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
   StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("File(s):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
   BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   BitmapButtonBrowse = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
   BoxSizer2->Add(BitmapButtonBrowse, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   ButtonChangeSettings = new wxButton(this, ID_BUTTON6, _("Change settings"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
   BoxSizer2->Add(ButtonChangeSettings, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   TextCtrlFilenames = new wxTextCtrl(this, ID_TEXTCTRL1, _("Click the folder button to choose the file(s) to convert"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_DONTWRAP, wxDefaultValidator, _T("ID_TEXTCTRL1"));
   TextCtrlFilenames->SetMinSize(wxSize(300,150));
   BoxSizer1->Add(TextCtrlFilenames, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
   StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Source extension:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
   BoxSizer3->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   RadioButtonC = new wxRadioButton(this, ID_RADIOBUTTON1, _(".c"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
   RadioButtonC->SetValue(true);
   RadioButtonC->SetToolTip(_("Exports the data in the form of a .c source file."));
   BoxSizer3->Add(RadioButtonC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   RadioButtonCpp = new wxRadioButton(this, ID_RADIOBUTTON2, _(".cpp"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
   RadioButtonCpp->SetToolTip(_("Exports data in the form of a header file (declarations only- will not export the actual data!)"));
   BoxSizer3->Add(RadioButtonCpp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   BoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
   ButtonExport = new wxButton(this, ID_BUTTON2, _("Export"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
   wxFont ButtonExportFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
   if ( !ButtonExportFont.Ok() ) ButtonExportFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
   ButtonExportFont.SetWeight(wxBOLD);
   ButtonExport->SetFont(ButtonExportFont);
   BoxSizer4->Add(ButtonExport, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   ButtonAbout = new wxButton(this, ID_BUTTON1, _("About..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
   BoxSizer4->Add(ButtonAbout, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   ButtonQuit = new wxButton(this, ID_BUTTON4, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
   BoxSizer4->Add(ButtonQuit, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   BoxSizer1->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   SetSizer(BoxSizer1);
   FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_MULTIPLE, wxDefaultPosition, wxDefaultSize);
   FileDialog2 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_SAVE, wxDefaultPosition, wxDefaultSize);
   BoxSizer1->Fit(this);
   BoxSizer1->SetSizeHints(this);

   Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnButtonBrowseClick);
   Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnButtonChangeSettingsClick);
   Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnButtonExportClick);
   Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnButtonAboutClick);
   Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Raw2cDialog::OnQuit);
   //*)

   settings_dlg = new SettingsDialog( this );
}

Raw2cDialog::~Raw2cDialog()
{
   //(*Destroy(Raw2cDialog)
   //*)

   settings_dlg->Destroy();
}

wxString Raw2cDialog::MakeVarString( wxString str )
{
   for ( wxString::size_type i=0; i<str.Len(); ++i ) {
      if ( ( str[i] < 0x30 )
        || ( str[i] > 0x39 && str[i] < 0x41 )
        || ( str[i] > 0x5a && str[i] < 0x61 )
        || ( str[i] > 0x7a ) ) {
         str.SetChar( i, '_' );
      }
   }

   if ( str[0] >= 0x30 && str[0] <= 0x39 ) {
      str = wxString::Format( "_%s", str.c_str() );
   }

   return str;
}

bool Raw2cDialog::WriteSourceData( std::ofstream& out )
{
   long max_length;

   settings_dlg->TextCtrlMaxChars->GetValue().ToLong( &max_length, 10 );

   for ( wxArrayString::size_type i=0; i<files.GetCount(); ++i ) {
      wxString str;

      wxFile file( files[i] );
      if ( !file.IsOpened() ) {
         wxString msg;

         msg << "Error reading \"" << files[i] << "\".\n\n";
         msg << "Do you want to skip it?";

         if ( wxMessageBox( msg, wxMessageBoxCaptionStr, wxYES_NO, this ) == wxYES ) {
            continue;
         } else {
            wxMessageBox( "Aborted" );
            return false;
         }
      }

      // Allocate buffer
      wxFileOffset length = file.Length();
      unsigned char* buffer = new unsigned char[length];
      file.Read( buffer, length );
      file.Close();

      wxFileName name( files[i] );
      wxString varname = MakeVarString( name.GetFullName() );

      out << "/*\n";
      out << "  " << name.GetFullName().mb_str() << "\n";
      out << "  " << length << " bytes\n";
      out << "*/\n\n";

      wxString vartype;

      // [const]
      if ( settings_dlg->CheckBoxConst->GetValue() ) vartype << "const ";

      // Standard keywords
      if ( settings_dlg->CheckBoxLength->GetValue() ) {
         out << vartype.mb_str() << "unsigned int " << varname.mb_str()
             << "_length = " << length << ";\n";
      }

      out << vartype.mb_str();

      if ( !settings_dlg->CheckBoxStringLiterals->GetValue() ) {
         out << "unsigned ";
      }

      out << "char " << varname.mb_str() << "_data[" << length << "] =\n";
      out << "{\n";

      if ( settings_dlg->CheckBoxStringLiterals->GetValue() ) {
         out << "\"";
      } else {
         out << "  ";
      }

      int charc = 0;

      for ( int i=0; i<length; ++i ) {
         wxString byte_str;

         if ( settings_dlg->CheckBoxStringLiterals->GetValue() ) {
            if ( buffer[i] >= 0x20 && buffer[i] <= 0x7e ) {
               // Quotation mark
               if ( buffer[i] == 0x22 ) {
                  byte_str << "\\\"";
               }
               // Numbers
               else if ( buffer[i] >= '0' && buffer[i] <= '9' ) {
                  // Check if the next character is a number
                  if ( buffer[i+1] >= '0' && buffer[i+1] <= '9' ) {
                     byte_str = wxString::Format( "\\%03o", buffer[i] );
                  } else {
                     byte_str = wxString::Format( "\\%o", buffer[i] );
                  }
               }
               // "Escape-sequence" mark
               else if ( buffer[i] == 0x5c ) {
                  byte_str << wxT( "\\\\" );
               }
               // Any other character in the range 0x20 - 0x7e
               else {
                  byte_str = wxString::Format( "%c", buffer[i] );
               }
            }
            // Default output
            else {
               byte_str = wxString::Format( "\\%o", buffer[i] );
            }
         } else {
            if ( settings_dlg->CheckBoxHexValues->GetValue() ) {
               byte_str = wxString::Format( "0x%02x", buffer[i] );
            } else {
               byte_str = wxString::Format( "%u", buffer[i] );
            }

            if ( i != length - 1 ) {
               byte_str << wxT( "," );
            }
         }

         charc += byte_str.Len();
         out << byte_str.mb_str();

         if ( charc >= ( max_length - 5 ) && i != length - 1 ) {
            if ( settings_dlg->CheckBoxStringLiterals->GetValue() ) {
               out << "\"\n\"";
            } else {
               out << "\n  ";
            }

            charc = 0;
         }
      }

      if ( settings_dlg->CheckBoxStringLiterals->GetValue() ) {
         out << "\"";
      }

      out << "\n};\n\n";

      delete[] buffer;
   }

   return true;
}

bool Raw2cDialog::WriteHeaderData( std::ofstream& out, wxFileName& filename )
{
   wxString header_name;

   header_name = MakeVarString( filename.GetFullName().Upper() );

   if ( settings_dlg->CheckBoxIncludeGuards->GetValue() ) {
      out << "#ifndef " << header_name.mb_str() << "_INCLUDED\n";
      out << "#define " << header_name.mb_str() << "_INCLUDED\n\n";
   }

   for ( wxArrayString::size_type i=0; i<files.GetCount(); ++i ) {
      wxFile file( files[i] );

      if ( !file.IsOpened() ) {
         wxString msg;

         msg << "Error reading: \"" << files[i] << "\".\n\n";
         msg << "Do you want to skip it?";

         if ( wxMessageBox( msg, wxMessageBoxCaptionStr, wxYES_NO, this ) == wxYES ) {
            continue;
         } else {
            wxMessageBox( "Aborted" );
            return false;
         }
      }

      wxFileOffset length = file.Length();
      file.Close();

      wxFileName name( files[i] );
      wxString varname = MakeVarString( name.GetFullName() );

      wxString vartype;
      vartype << "extern ";
      if ( settings_dlg->CheckBoxConst->GetValue() ) {
         vartype << "const ";
      }

      if ( settings_dlg->CheckBoxLength->GetValue() ) {
         out << vartype.mb_str() << "unsigned int " << varname.mb_str()
             << "_length;\n";
      }

      out << vartype.mb_str();

      if ( !settings_dlg->CheckBoxStringLiterals->GetValue() ) {
         out << "unsigned ";
      }

      out << "char " << varname.mb_str() << "_data[" << length << "];\n";

      if ( settings_dlg->CheckBoxLength->GetValue() ) {
         out << "\n";
      }
   }

   if ( !settings_dlg->CheckBoxLength->GetValue() ) {
      out << "\n";
   }

   if ( settings_dlg->CheckBoxIncludeGuards->GetValue() ) {
      out << "#endif /* " << header_name.mb_str() << "_INCLUDED" << " */\n";
   }

   return true;
}

void Raw2cDialog::DoExportSource()
{
   if ( FileDialog2->ShowModal() == wxID_OK ) {
      wxFileName fname( FileDialog2->GetPath() );

      if ( RadioButtonC->GetValue() ) {
         fname.SetExt( wxT( "c" ) );
      } else {
         fname.SetExt( wxT( "cpp" ) );
      }

      std::ofstream file_source( fname.GetFullPath().mb_str() );

      if ( file_source.is_open() ) {
         if ( WriteSourceData( file_source ) ) {
            fname.SetExt( wxT( "h" ) );
            DoExportHeader( fname );
            wxString msg;
            msg << "Source files created succesfully!";
            wxMessageBox( msg );
         }
      }

      file_source.close();
   }
}

void Raw2cDialog::DoExportHeader(wxFileName fn)
{
   std::ofstream file_header( fn.GetFullPath().mb_str() );

   if ( file_header.is_open() ) {
      WriteHeaderData( file_header, fn );
      file_header.close();
   }
}

void Raw2cDialog::OnQuit( wxCommandEvent& event )
{
   Close();
}

void Raw2cDialog::OnButtonBrowseClick( wxCommandEvent& event )
{
   if ( FileDialog1->ShowModal() == wxID_OK ) {
      FileDialog1->GetPaths( files );

      if ( files.GetCount() > 1 ) {
         wxString str, tooltip_str;

         for ( wxArrayString::size_type i=0; i<files.GetCount(); ++i ) {
            str << "\"" << files[i] << "\"" << " ";

            tooltip_str << files[i];

            if ( i < files.GetCount() - 1 ) {
               tooltip_str << "\n";
            }
         }

         TextCtrlFilenames->ChangeValue( tooltip_str );
      } else {
         TextCtrlFilenames->ChangeValue( FileDialog1->GetPath() );
      }
   }
}

void Raw2cDialog::OnButtonExportClick( wxCommandEvent& event )
{
   if ( !files.GetCount() ) {
      wxMessageBox( "No file(s) choosen", wxMessageBoxCaptionStr,
                    wxOK | wxCENTRE, this );

      return;
   }

   DoExportSource();
}

void Raw2cDialog::OnButtonChangeSettingsClick( wxCommandEvent& event )
{
   settings_dlg->ShowModal();
}

void Raw2cDialog::OnButtonAboutClick(wxCommandEvent& event)
{
   wxString aboutmsg;

   aboutmsg << wxString::Format(wxT("Any2c GUI 1.1 (%s)\n\n"), __DATE__);
   aboutmsg << wxT("Embed any file(s) into a C or C++ application by turning them into byte arrays.\n\n");
   aboutmsg << wxT("(C) 2017-2021 Elias Orz (Elias_YFGM)");

   wxMessageBox(aboutmsg, wxMessageBoxCaptionStr, wxOK | wxCENTRE, this);

   /*wxAboutDialogInfo info;

   info.SetName(wxT("Any2c GUI"));
   info.SetVersion(wxString::Format(wxT("1.1 (%s)"), __DATE__));
   info.SetDescription(wxT("Embed any file(s) into a C or C++ application by turning them into byte arrays."));
   info.SetCopyright(wxT("(C) 2017-2021 Elias Orz (Elias_YFGM)"));

   wxAboutBox(info, this);*/
}
