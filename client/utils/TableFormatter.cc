/*
 * Copyright (c) [2019-2020] SUSE LLC
 *
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, contact Novell, Inc.
 *
 * To contact Novell about this file by physical or electronic mail, you may
 * find current contact information at www.novell.com.
 */

#include <sstream>

#include "client/utils/TableFormatter.h"


namespace snapper
{

    using namespace std;


    namespace cli
    {

	const TableStyle TableFormatter::default_style = Ascii;


	string
	TableFormatter::str() const
	{
	    Table table;
	    table.set_style(style);

	    TableHeader table_header;

	    for (const pair<string, TableAlign>& column : header)
		table_header.add(column.first, column.second);

	    table.setHeader(table_header);

	    for (const vector<string>& row : rows)
	    {
		TableRow table_row;

		for (const string& value : row)
		    table_row.add(value);

		table.add(table_row);
	    }

	    ostringstream stream;
	    stream << table;
	    return stream.str();
	}

    }

}
