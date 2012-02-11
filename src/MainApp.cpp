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


#include <wx/app.h>
#include <wx/frame.h>
#include <wx/string.h>

#include "MainApp.hpp"
#include "ContestDefinition.hpp"
#include "LogFrame.hpp"
#include "WindowID.hpp"


// PACKAGE_* and VERSION macros
#if HAVE_CONFIG_H
# include <config.h>
#endif


IMPLEMENT_APP(MainApp)


// CTest main event loop class
//
// Main program event loop implementation.

bool MainApp::OnInit()
{
	wxString frame_str;

	frame_str.Append(_(PACKAGE_STRING));
	frame_str.Append(_(" by N0NB"));

	LogFrame *log_frame = new LogFrame(LOG_FRAME_ID, frame_str);
	log_frame->Show(true);

	return true;
}
