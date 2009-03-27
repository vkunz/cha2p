#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

//(*Headers(ConnectDialog)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include <wx/string.h>

class ConnectDialog: public wxDialog
{
	public:

		ConnectDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ConnectDialog();

		wxString getAddress();

		//(*Declarations(ConnectDialog)
		wxTextCtrl* TextCtrl4;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticText* StaticText5;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(ConnectDialog)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(ConnectDialog)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
