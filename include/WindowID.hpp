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


#ifndef WINDOWID_HPP
#define WINDOWID_HPP


// Window ID values used throughout the program
enum {
	LOG_FRAME_ID	=	101,
	LOG_INPUT_ID	=	102,

	// Log input panel fields
	QSONR_ID	=	201,
	TIME_STR_ID	=	202,
	CALL_INPUT_ID	=	203,
	EXCH1_INPUT_ID	=	204,
	EXCH2_INPUT_ID	=	205,
	EXCH3_INPUT_ID	=	206,
	EXCH4_INPUT_ID	=	207,
	EXCH5_INPUT_ID	=	208,
};


#endif		// WINDOWID_HPP
