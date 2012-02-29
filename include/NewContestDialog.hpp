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


#ifndef NEWCONTESTDIALOG_HPP
#define NEWCONTESTDIALOG_HPP

// Dialog for getting new contest data from a definition file and the user.
//
// Used by LogFrame::OnNew()

class NewContestDialog : public wxDialog
{
	DECLARE_CLASS(NewContestDialog)
	DECLARE_EVENT_TABLE()

public:
	//Constructors
	NewContestDialog();
	NewContestDialog(wxWindow *parent,
	                   wxWindowID id = wxID_ANY,
	                   const wxString& title = _("New Contest Configuration"),
	                   const wxPoint& pos = wxDefaultPosition,
	                   const wxSize& size = wxDefaultSize,
                           long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU);

	// Member initialization
	void Init();

	// Creation
	bool Create(wxWindow *parent,
	            wxWindowID id = wxID_ANY,
	            const wxString& title = _("New Contest Configuration"),
	            const wxPoint& pos = wxDefaultPosition,
	            const wxSize& size = wxDefaultSize,
                    long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU);

	// Creates the controls and sizers
	void CreateControls();


};

#endif		// NEWCONTESTDIALOG_HPP

