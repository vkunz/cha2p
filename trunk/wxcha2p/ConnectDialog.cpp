#include "ConnectDialog.h"

//(*InternalHeaders(ConnectDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ConnectDialog)
const long ConnectDialog::ID_TEXTCTRL1 = wxNewId();
const long ConnectDialog::ID_TEXTCTRL2 = wxNewId();
const long ConnectDialog::ID_TEXTCTRL3 = wxNewId();
const long ConnectDialog::ID_TEXTCTRL4 = wxNewId();
const long ConnectDialog::ID_STATICTEXT1 = wxNewId();
const long ConnectDialog::ID_STATICTEXT2 = wxNewId();
const long ConnectDialog::ID_STATICTEXT3 = wxNewId();
const long ConnectDialog::ID_STATICTEXT4 = wxNewId();
const long ConnectDialog::ID_BUTTON1 = wxNewId();
const long ConnectDialog::ID_STATICTEXT6 = wxNewId();
const long ConnectDialog::ID_TEXTCTRL5 = wxNewId();
const long ConnectDialog::ID_STATICTEXT5 = wxNewId();
const long ConnectDialog::ID_TEXTCTRL6 = wxNewId();
const long ConnectDialog::ID_RADIOBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ConnectDialog,wxDialog)
	//(*EventTable(ConnectDialog)
	//*)
	EVT_BUTTON(ID_BUTTON1, ConnectDialog::OnButton1Click)
END_EVENT_TABLE()

ConnectDialog::ConnectDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ConnectDialog)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(389,159));
	wxString __wxRadioBoxChoices_1[2] =
	{
		_("DynDNS"),
		_("Client")
	};
	RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, wxEmptyString, wxPoint(40,0), wxSize(240,33), 2, __wxRadioBoxChoices_1, 2, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	RadioBox1->SetSelection(0);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(80,48), wxSize(40,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(128,48), wxSize(40,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(176,48), wxSize(40,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(224,48), wxSize(40,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("."), wxPoint(122,55), wxSize(5,13), 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("."), wxPoint(170,55), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("."), wxPoint(218,55), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("IP-Adresse"), wxPoint(16,52), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Channel"), wxPoint(16,83), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(80,80), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Nickname:"), wxPoint(16,115), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(80,112), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Verbinden"), wxPoint(296,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	//*)
}

ConnectDialog::~ConnectDialog()
{
	//(*Destroy(ConnectDialog)
	//*)
}

void ConnectDialog::OnButton1Click(wxCommandEvent& event)
{
    EndModal(0);
}

wxString ConnectDialog::getAddress() {
    wxString str;
    str = TextCtrl1->GetValue() + wxT(".") + TextCtrl2->GetValue() + wxT(".") + TextCtrl3->GetValue();
    str += wxT(".") + TextCtrl4->GetValue();
    return str;
}

wxString ConnectDialog::getNickname() {
    return TextCtrl5->GetValue();
}

wxString ConnectDialog::getChannel() {
    return TextCtrl6->GetValue();
}

int ConnectDialog::getConnMethod() {
    return RadioBox1->GetSelection();
}
