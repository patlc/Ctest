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
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/msgdlg.h>

#include "CTestMainApp.hpp"
#include "CTestLogFrame.hpp"


IMPLEMENT_APP(CTestMainApp)


// CTest main event loop class
//
// Main program event loop implementation.

bool CTestMainApp::OnInit()
{
	CTestLogFrame *logframe = new CTestLogFrame(_("CTest by N0NB"));
	logframe->Show(true);

	return true;
}
