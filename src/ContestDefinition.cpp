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


#include <wx/string.h>

#include "ContestDefinition.hpp"

// PACKAGE_* and VERSION macros
#if HAVE_CONFIG_H
# include <config.h>
#endif


// Contest definition class accessor definitions.  These names
// mirror those defined in the various def/*.def files

// ContestID is the ADIF name for this event
void ContestDefinition::SetContestID(wxString id)
{
	ContestID = id;
}

wxString ContestDefinition::GetContestID()
{
	return ContestID;
}

// Exch1 is often the RS(T) but may be named otherwise
// such as Field Day class, ARRL SS S/N, etc.
void ContestDefinition::SetExch1(wxString ex1)
{
	Exch1 = ex1;
}

wxString ContestDefinition::GetExch1()
{
	return Exch1;
}

// Exch2 could be a zone or section/state/power, ARRL SS Prec, etc.
void ContestDefinition::SetExch2(wxString ex2)
{
	Exch2 = ex2;
}

wxString ContestDefinition::GetExch2()
{
	return Exch2;
}

