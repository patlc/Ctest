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


#ifndef LOGFRAME_HPP
#define LOGFRAME_HPP


// Main logging application frame class.  This is the main desktop
// window where logging and user interaction takes place.
//
// Used by LogFrame.cpp

class LogFrame : public wxFrame, public ContestDefinition
{
public:
	LogFrame(wxWindowID id, const wxString& title);
	~LogFrame();

	// Frame generated event
	void OnClose(wxCloseEvent& event);

	// MenuBar items generated events
	void OnNew(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

private:
	ContestDefinition *ct_def;
	DECLARE_EVENT_TABLE()
};


#endif		// LOGFRAME_HPP
