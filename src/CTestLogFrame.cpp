//=============================================================================
//    CTest--an amateur radio contest logging database and rig control app.
//
//    Copyright (C) 2012 Nate Bargmann, N0NB, n0nb@n0nb.us
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//=============================================================================


#include <wx/frame.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/msgdlg.h>
#include <wx/sizer.h>

// Needed for CTestLogInputPanel
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
#include <wx/stattext.h>

#include "CTestLogFrame.hpp"
#include "CTestLogInputPanel.hpp"
#include "CTestWindowID.hpp"

// PACKAGE_* and VERSION macros
#if HAVE_CONFIG_H
# include <config.h>
#endif


// Main logging application frame class.  This is the main desktop
// window where logging and user interaction takes place.
//
// Let the windowing system determine the placement of the frame.
// wxFrame size determined by the contained windows.

CTestLogFrame::CTestLogFrame(wxWindowID id, const wxString& title)
	: wxFrame(NULL, id, title)
{
	wxString status_str;

	wxMenuBar	*menubar = new wxMenuBar();
	wxMenu		*file = new wxMenu();
	wxMenu		*help = new wxMenu();
	CTestLogInputPanel *log_input = new CTestLogInputPanel(this, LOG_INPUT_ID);
	wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);

	// Place windows in order from top to bottom
	// Grow in proportion to other contained windows
	// Apply border to all sides
	// Border is 5 pixels
	topSizer->Add(log_input, 1, wxALL, 5);

	file->Append(wxID_EXIT, _("E&xit\tAlt-X"));
	help->Append(wxID_ABOUT, _("&About"));

	menubar->Append(file, _("&File"));
	menubar->Append(help, _("&Help"));
	SetMenuBar(menubar);

	// Separate the status bar into three fields
	CreateStatusBar(3);
	// Place welcome text in the leftmost field
	status_str.Append(_("Welcome to "));
	status_str.Append(_(PACKAGE_NAME));
	status_str.Append(_("!"));
	SetStatusText(status_str, 0);

	SetSizer(topSizer);		// use the sizer for layout
	topSizer->Fit(this);		// fit the dialog to the contents
	topSizer->SetSizeHints(this);	// set hints to honor min size
}

// Handles all close events from window controls and Alt-F4.
// The Exit/Alt-X menu item eventually gets here as well.
void CTestLogFrame::OnClose(wxCloseEvent& event)
{
	wxString quit_title;

	quit_title.Append(_("Exit "));
	quit_title.Append(_(PACKAGE_NAME));

	// Create quit dialog on the heap
	wxMessageDialog *quit_dialog = new wxMessageDialog(this,
	                _("Are you sure?"), quit_title,
	                wxNO_DEFAULT | wxYES_NO | wxICON_QUESTION);

	int ret = quit_dialog->ShowModal();
	quit_dialog->Destroy();

	if (ret == wxID_YES)
		Destroy();
	else
		event.Veto();
}

// Actual exit dialog will be handled by CTestLogFrame::OnClose()
void CTestLogFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(TRUE);
}

void CTestLogFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxString about_txt;
	wxString about_dlg_str;

	// Build the message box text using Autoconf generated package macros
	about_txt.Append(_(PACKAGE_STRING));
	about_txt.Append(_(", a contest logging application for radio amateurs\n\n"));
	about_txt.Append(_(PACKAGE_NAME));
	about_txt.Append(_(" is free software, see the file COPYING for details.\n"));
	about_txt.Append(_(PACKAGE_NAME));
	about_txt.Append(_(" Copyright \u00A9 "));
	about_txt.Append(_(PACKAGE_COPYRIGHT_YEARS));
	about_txt.Append(_(" Nate Bargmann, N0NB.\n\n"));
	about_txt.Append(_("Report bugs to: "));
	about_txt.Append(_(PACKAGE_BUGREPORT));
	about_txt.Append(_("\nHomepage: "));
	about_txt.Append(_(PACKAGE_URL));

	// Build the wxMessageBox title string
	about_dlg_str.Append(_("About "));
	about_dlg_str.Append(_(PACKAGE_NAME));

	wxMessageBox(about_txt, about_dlg_str, wxOK | wxICON_INFORMATION, this);
}

BEGIN_EVENT_TABLE(CTestLogFrame, wxFrame)
	EVT_MENU(wxID_EXIT,	CTestLogFrame::OnQuit)
	EVT_MENU(wxID_ABOUT,	CTestLogFrame::OnAbout)
	EVT_CLOSE(		CTestLogFrame::OnClose)
END_EVENT_TABLE()
