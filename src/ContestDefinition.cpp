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
#include <wx/textfile.h>
#include <wx/regex.h>
#include <iostream>

#include "ContestDefinition.hpp"

// PACKAGE_* and VERSION macros
#if HAVE_CONFIG_H
# include <config.h>
#endif


// Contest definition class accessor definitions.  These names
// mirror those defined in the various def/*.def files

// FileVersion is the definition version for this event
void ContestDefinition::SetFileVersion(wxString ver)
{
	FileVersion = ver;
}

wxString const ContestDefinition::GetFileVersion() const
{
	return FileVersion;
}

// ContestID is the ADIF name for this event
void ContestDefinition::SetContestID(wxString id)
{
	ContestID = id;
}

wxString const ContestDefinition::GetContestID() const
{
	return ContestID;
}

// Exch1 is often the RS(T) but may be named otherwise
// such as Field Day class, ARRL SS S/N, etc.
void ContestDefinition::SetExch1(wxString ex1)
{
	Exch1 = ex1;
}

wxString const ContestDefinition::GetExch1() const
{
	return Exch1;
}

// Exch2 could be a zone or section/state/power, ARRL SS Prec, etc.
void ContestDefinition::SetExch2(wxString ex2)
{
	Exch2 = ex2;
}

wxString const ContestDefinition::GetExch2() const
{
	return Exch2;
}

void ContestDefinition::build_def(wxString def_file)
{
	wxString str;
	wxTextFile dfile;

	// Comment lines could have zero or more leading spaces or tabs
	wxRegEx reComment(wxT("^[[:blank:]]*#.*$"), wxRE_ADVANCED);

	// Blank lines
	wxRegEx reBlank(wxT("^[[:blank:]]*$"), wxRE_ADVANCED);

	// Key/Value pairs (what we're looking for)
	// Values are contained in double quotes ("") and may contain
	// letters, digits, '-', '_', or ' ' in any combination or quantity
	wxRegEx reKeyVal(wxT("^[[:blank:]]*([[:alnum:]_-]+)[[:blank:]]*=[[:blank:]]*(\"[[:alnum:][:blank:]_-]+\").*$"),
	                 wxRE_ADVANCED | wxRE_ICASE);

#ifdef DEBUG
	if (!reComment.IsValid())
		std::cerr << "reComment is not a valid regex!\n" << std::endl;
	else if (!reBlank.IsValid())
		std::cerr << "reBlank is not a valid regex!\n" << std::endl;
	else if (!reKeyVal.IsValid())
		std::cerr << "reKeyVal is not a valid regex!\n" << std::endl;
#endif

	// open the definition file
	dfile.Open(def_file);

	for ( str = dfile.GetFirstLine(); !dfile.Eof(); str = dfile.GetNextLine() ) {
		// Test for comment line with leading '#' and ignore
		if (reComment.Matches(str) || reBlank.Matches(str)) {
#if 0
			std::cerr << str.mb_str() << std::endl;
#endif
			continue;
		} else if (reKeyVal.Matches(str)) {
#if 0
			std::cerr << str.mb_str() << std::endl;
#endif
			wxString key = reKeyVal.GetMatch(str, 1);
			wxString val = reKeyVal.GetMatch(str, 2);

#ifdef DEBUG
			std::cerr << "Key: " << key.mb_str() << std::endl;
#endif
			if (key.IsSameAs(wxT("FileVersion"), FALSE)) {
				SetFileVersion(val);
#ifdef DEBUG
				wxString fv_val = GetFileVersion();
				std::cerr << "Val: " << fv_val.mb_str() << std::endl;
#endif
			} else if (key.IsSameAs(wxT("ContestID"), FALSE)) {
				SetContestID(val);
#ifdef DEBUG
				wxString fv_val = GetContestID();
				std::cerr << "Val: " << fv_val.mb_str() << std::endl;
#endif
			} else if (key.IsSameAs(wxT("Exch1"), FALSE)) {
				SetExch1(val);
#ifdef DEBUG
				wxString fv_val = GetExch1();
				std::cerr << "Val: " << fv_val.mb_str() << std::endl;
#endif
			} else if (key.IsSameAs(wxT("Exch2"), FALSE)) {
				SetExch2(val);
#ifdef DEBUG
				wxString fv_val = GetExch2();
				std::cerr << "Val: " << fv_val.mb_str() << std::endl;
#endif
			}
		}
#ifdef DEBUG
		 else
			std::cerr << "Invalid line: " << str.mb_str() << std::endl;
#endif
	}
#if 0
	std::cerr << std::endl << "wxUSE_STD_IOSTREAM=" << (wxUSE_STD_IOSTREAM)
	<< " wxUSE_UNICODE=" << (wxUSE_UNICODE) << std::endl;
#endif

	// close the definition file
	dfile.Close();
}
