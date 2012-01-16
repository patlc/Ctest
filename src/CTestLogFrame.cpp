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

#include "CTestLogFrame.hpp"


// PACKAGE_* and VERSION macros
#if HAVE_CONFIG_H
# include <config.h>
#endif


// Main logging application frame class.  This is the main desktop
// window where logging and user interaction takes place.
//
// Let the windowing system determine the placement of the frame.
// Set wxFrame size of 640x480 pixels.

CTestLogFrame::CTestLogFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxPoint(-1, -1), wxSize(640, 480))
{
	menubar = new wxMenuBar();
	file = new wxMenu();
	help = new wxMenu();

	file->Append(wxID_EXIT, _("&Quit"));
	help->Append(wxID_ABOUT, _("&About"));

	menubar->Append(file, _("&File"));
	menubar->Append(help, _("&Help"));
	SetMenuBar(menubar);

	// Separate the status bar into three fields
	CreateStatusBar(3);
	// Place welcome text in the leftmost field
	SetStatusText(_("Welcome to CTest"), 0);
}

void CTestLogFrame::OnQuit(wxCommandEvent & WXUNUSED(event))
{
	Close(TRUE);
}

void CTestLogFrame::OnAbout(wxCommandEvent & WXUNUSED(event))
{
	wxString msgtxt;
	wxString msgdlgstr;

	// Build the message box text using Autoconf generated package macros
	msgtxt.Append(_(PACKAGE_STRING));
	msgtxt.Append(_(", a contest logging application for radio amateurs\n\n"));
	msgtxt.Append(_(PACKAGE_NAME));
	msgtxt.Append(_(" is free software, see the file COPYING for details.\n"));
	msgtxt.Append(_(PACKAGE_NAME));
	msgtxt.Append(_(" Copyright \u00A9 "));
	msgtxt.Append(_(PACKAGE_COPYRIGHT_YEARS));
	msgtxt.Append(_(" Nate Bargmann, N0NB.\n\n"));
	msgtxt.Append(_("Report bugs to: "));
	msgtxt.Append(_(PACKAGE_BUGREPORT));
	msgtxt.Append(_("\nHomepage: "));
	msgtxt.Append(_(PACKAGE_URL));

	// Build the wxMessageBox title string
	msgdlgstr.Append(_("About "));
	msgdlgstr.Append(_(PACKAGE_NAME));

	wxMessageBox(msgtxt, msgdlgstr, wxOK | wxICON_INFORMATION, this);
}

BEGIN_EVENT_TABLE(CTestLogFrame, wxFrame)
	EVT_MENU(wxID_EXIT,	CTestLogFrame::OnQuit)
	EVT_MENU(wxID_ABOUT,	CTestLogFrame::OnAbout)
END_EVENT_TABLE()
