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


#ifndef CONTESTDEFINITION_HPP
#define CONTESTDEFINITION_HPP


// This class holds the values from the defs/*.def files.  Each is a key/value
// pair where the private values declared here mirror the names used in the
// definition file and those values are stored here.

class ContestDefinition
{
public:
	void SetFileVersion(wxString ver);
	wxString const GetFileVersion() const;

	void SetContestID(wxString id);
	wxString const GetContestID() const;

	void SetExch1(wxString ex1);
	wxString const GetExch1() const;

	void SetExch2(wxString ex2);
	wxString const GetExch2() const;

	// Opens passed file name of contest definition
	void build_def(wxString def_file);

private:
	wxString FileVersion;
	wxString ContestID;
	wxString Exch1;
	wxString Exch2;
};

#endif		// CONTESTDEFINITION_HPP
