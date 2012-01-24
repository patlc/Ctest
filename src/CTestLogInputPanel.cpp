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


#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/font.h>
#include <wx/window.h>
#include <wx/frame.h>

// Standard library
#include <iostream>

#include "CTestWindowID.hpp"
#include "CTestLogInputPanel.hpp"


CTestLogInputPanel::CTestLogInputPanel(wxWindow* parent, wxWindowID id)
	: wxPanel(parent, id)
{
	int x, y;

	// Create top-level flex grid sizer
	// 2 rows, columns as needed, vgap of 0 pixels, hgap of 5 pixels
	wxFlexGridSizer *flexGridSizer = new wxFlexGridSizer(2, 0, 0, 5);
	this->SetSizer(flexGridSizer);

	// Fixed proportion font to make sizing easy.
	wxFont font(-1, wxFONTFAMILY_MODERN, wxNORMAL, wxNORMAL);
	SetFont(font);

	// Labels on row above each entry box.  The length of the label
	// strings sets the width of the second row fields (except for
	// "Time".  The wxTextCtrl box border width requires the label text
	// be longer.  For example, add a space after RST to make the input
	// box big enough to show three digits without scrolling.
	wxStaticText *time_txt = new wxStaticText(this, wxID_ANY, _("Time"));
	wxStaticText *call_txt = new wxStaticText(this, wxID_ANY, _("Callsign       "));
	wxStaticText *exch1_txt = new wxStaticText(this, wxID_ANY, _("RST "));
	wxStaticText *exch2_txt = new wxStaticText(this, wxID_ANY, _("Power"));

	// Entry box row
	wxStaticText *time_str = new wxStaticText(this, TIME_STR_ID, _("00:00:00z"));

	// For each of the entry boxes, calculate the width of the label
	// above each box and set its width accordingly.
	call_txt->GetSize(&x, &y);
	wxTextCtrl *call_input = new wxTextCtrl(this, CALL_INPUT_ID, wxT(""),
	                                        wxDefaultPosition, wxSize(x, y + 6),
	                                        wxTE_MULTILINE);
	exch1_txt->GetSize(&x, &y);
	wxTextCtrl *exch1_input = new wxTextCtrl(this, EXCH1_INPUT_ID, wxT(""),
	                                         wxDefaultPosition, wxSize(x, y + 6),
	                                        wxTE_MULTILINE);
	exch2_txt->GetSize(&x, &y);
	wxTextCtrl *exch2_input = new wxTextCtrl(this, EXCH2_INPUT_ID, wxT(""),
	                                         wxDefaultPosition, wxSize(x, y + 6),
	                                        wxTE_MULTILINE);

	call_input->SetFocus();

	// Add each window into the first row of the grid.  Order matters!
	flexGridSizer->Add(time_txt, 0, wxALIGN_CENTER_HORIZONTAL  | wxALIGN_BOTTOM, 0);
	flexGridSizer->Add(call_txt, 0, wxALIGN_LEFT | wxALIGN_BOTTOM, 0);
	flexGridSizer->Add(exch1_txt, 0, wxALIGN_LEFT | wxALIGN_BOTTOM, 0);
	flexGridSizer->Add(exch2_txt, 0, wxALIGN_LEFT | wxALIGN_BOTTOM, 0);

	// Add each window into the second row of the grid.  Order matters!
	flexGridSizer->Add(time_str, 0, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 0);
	flexGridSizer->Add(call_input, 0, wxALIGN_LEFT | wxEXPAND, 0);
	flexGridSizer->Add(exch1_input, 0, wxALIGN_LEFT | wxEXPAND, 0);
	flexGridSizer->Add(exch2_input, 0, wxALIGN_LEFT | wxEXPAND, 0);

	// Capture and direct wxTextCtrl events

	// The call_input field requires that all keystrokes are examined.
	call_input->Connect(CALL_INPUT_ID, wxEVT_CHAR,
	                    wxCharEventHandler(CTestLogInputPanel::OnChar));

}


void CTestLogInputPanel::OnChar(wxKeyEvent& event)
{
	std::cerr << "Got keycode!\n";

	event.Skip();
}
