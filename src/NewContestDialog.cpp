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

#include <wx/dialog.h>
#include <wx/string.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/sizer.h>
#include <wx/dir.h>
#include <wx/msgdlg.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/filedlg.h>

// #include "ContestDefinition.hpp"
#include "NewContestDialog.hpp"


IMPLEMENT_CLASS(NewContestDialog, wxDialog)

BEGIN_EVENT_TABLE(NewContestDialog, wxDialog)
END_EVENT_TABLE()


// Implement wx style class with a default constructor
NewContestDialog::NewContestDialog()
{
	Init();
}

// Initialize any variables and call the Create() method
NewContestDialog::NewContestDialog(wxWindow *parent,
                                       wxWindowID id,
                                       const wxString& title,
                                       const wxPoint& pos,
                                       const wxSize& size,
                                       long style)
{
	Init();

	Create(parent, id, title, pos, size, style);
}

// Initializes variables
void NewContestDialog::Init()
{
}

// wx style class Create method to create the dialog
bool NewContestDialog::Create(wxWindow *parent,
                           wxWindowID id,
                           const wxString& title,
                           const wxPoint& pos,
                           const wxSize& size,
                           long style)
{
	// Block events before creating the dialog
	// so they are handled here and not in the Frame
	SetExtraStyle(wxWS_EX_BLOCK_EVENTS);

	if (!wxDialog::Create( parent, id, title, pos, size, style ))
		return false;

	CreateControls();

	// Fit the dialog to the minimum size dictated by the sizers
	GetSizer()->Fit(this);

	// Ensure the dialog cannot be sized smaller than the minimum size
	GetSizer()->SetSizeHints(this);

	// Centre the dialog on the Frame
	Centre();

	return true;
}

void NewContestDialog::CreateControls()
{
	// Top level sizer for this dialog
	wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);

	// A static box to give a nice outline of the controls
//	wxStaticBox *sBox = new wxStaticBox(this, wxID_ANY, _("Setup new contest"));
//	wxBoxSizer *sBoxSizer = new wxStaticBoxSizer(sBox, wxVERTICAL);
//	topSizer->Add(sBoxSizer, 0, wxALL, 5);

	// DEFS_DIR is defined in ./Makefile.am AM_CPPFLAGS and is comprised
	// of an Autoconf path variable pointing to the configured
	// installation path for .def files
	wxDir m_dir(_(DEFS_DIR));

	if (!m_dir.IsOpened()) {
		wxString msg_text;

		msg_text.Append(_("Unable to open "));
		msg_text.Append(_(DEFS_DIR));
		msg_text.Append(_("\n"));

		wxMessageDialog m_msg(this,
		                      msg_text,
		                      _("Defs dir open error"),
		                      wxOK);
		return;
	}

	// Populate the Choice control with filenames from default installation
	wxArrayString m_files;

	m_dir.GetAllFiles(_(DEFS_DIR), &m_files, _("*.def"), wxDIR_FILES);
	m_files.Sort();

	wxChoice *m_file_choice = new wxChoice(this, wxID_ANY, wxDefaultPosition,
	                                        wxDefaultSize, m_files);
	m_file_choice->SetStringSelection(m_files.Item(0));

	// Instruction text default defs
	wxBoxSizer *fileTextSizer1 = new wxBoxSizer(wxHORIZONTAL);

	fileTextSizer1->Add(new wxStaticText(this, wxID_ANY,
	                   _("Select a default contest definition file:")), 0,
	                   wxALL|wxALIGN_CENTER_VERTICAL,
	                   5);

	// Default contest definition selection
	wxBoxSizer *fileSizer1 = new wxBoxSizer(wxHORIZONTAL);

	fileSizer1->Add(m_file_choice, 0,
	               wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5);

	// Instruction text customized defs
//	wxBoxSizer *fileTextSizer2 = new wxBoxSizer(wxHORIZONTAL);

	// Custom contest definition file selector
//	fileTextSizer2->Add(new wxStaticText(this, wxID_ANY,
//	                   _("Select a customized contest definition file:")), 0,
//	                   wxALL|wxALIGN_CENTER_VERTICAL,
//	                   5);

	// Dialog buttons
	wxBoxSizer *buttonBox = new wxBoxSizer(wxHORIZONTAL);

	wxButton *OK_btn = new wxButton(this, wxID_OK, wxEmptyString);
	wxButton *Cancel_btn = new wxButton(this, wxID_CANCEL, wxEmptyString);

	buttonBox->Add(Cancel_btn, wxALIGN_RIGHT);
	buttonBox->Add(OK_btn, wxALIGN_RIGHT);

	// Final layout
	topSizer->Add(fileTextSizer1, 0, wxGROW|wxALIGN_CENTER, 5);
	topSizer->Add(fileSizer1, 0, wxGROW|wxALIGN_CENTER, 5);
//	topSizer->Add(fileTextSizer2, 0, wxGROW|wxALIGN_CENTER, 5);
	topSizer->Add(buttonBox, 0, wxGROW, 5);

	SetSizer(topSizer);		// use the sizer for layout
	topSizer->Fit(this);		// fit the dialog to the contents
//	topSizer->SetSizeHints(this);	// set hints to honor min size
}


// Code for future button in dialog to open a customized definition
//	wxString        def_file;

//	wxFileDialog    fdlog(this, _("Open Contest Definition"),
//	                      _(DEFS_DIR), _(""),
//	                      _("DEF files (*.def)|*.def"),
//	                      wxFD_FILE_MUST_EXIST);

	// show file dialog and get the path to
	// the file that was selected.
//	if(fdlog.ShowModal() != wxID_OK) return;

//	def_file.Clear();
//	def_file = fdlog.GetPath();

