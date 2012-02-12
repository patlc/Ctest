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


#ifndef LOGINPUTPANEL_HPP
#define LOGINPUTPANEL_HPP


class LogInputPanel : public wxPanel
{
public:
	LogInputPanel(wxWindow* parent, wxWindowID id);

	void UpdateClock();

	// event handlers
	void OnChar(wxKeyEvent& event);
	void OnTimer(wxTimerEvent& WXUNUSED(event));

private:
	// Variables needed to be visible to other functions
	wxStaticText *qnr_str;
	wxStaticText *band_str;
	wxStaticText *time_str;

	wxTextCtrl *call_input;
	wxTextCtrl *exch1_input;
	wxTextCtrl *exch2_input;
	wxTextCtrl *exch3_input;
	wxTextCtrl *exch4_input;
	wxTextCtrl *exch5_input;

	wxTimer clck_timer;

	DECLARE_EVENT_TABLE()
};

#endif		// LOGINPUTPANEL_HPP
