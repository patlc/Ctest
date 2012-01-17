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


#ifndef CTESTLOGFRAME_HPP
#define CTESTLOGFRAME_HPP


// Main logging application frame class.  This is the main desktop
// window where logging and user interaction takes place.
//
// Used by CTestLogFrame.cpp

class CTestLogFrame : public wxFrame
{
public:
	CTestLogFrame(const wxString& title);

	// Frame generated event
	void OnClose(wxCloseEvent& event);

	// MenuBar items generated events
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	wxMenuBar *menubar;
	wxMenu *file;
	wxMenu *help;

	wxStatusBar *statusbar;

private:
	DECLARE_EVENT_TABLE()
};

#endif		// CTESTLOGFRAME_HPP
