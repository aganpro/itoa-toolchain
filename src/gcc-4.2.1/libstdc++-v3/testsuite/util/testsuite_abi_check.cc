// -*- C++ -*-

// Copyright (C) 2004 Free Software Foundation, Inc.

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.

// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to
// the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
// MA 02110-1301, USA.

// As a special exception, you may use this file as part of a free
// software library without restriction.  Specifically, if other files
// instantiate templates or use macros or inline functions from this
// file, or you compile this file and link it with other files to
// produce an executable, this file does not by itself cause the
// resulting executable to be covered by the GNU General Public
// License.  This exception does not however invalidate any other
// reasons why the executable file might be covered by the GNU General
// Public License.

// Benjamin Kosnik  <bkoz@redhat.com>
// Blame subsequent hacks on Loren J. Rittle <ljrittle@acm.org>, Phil
// Edwards <pme@gcc.gnu.org>, and a cast of dozens at libstdc++@gcc.gnu.org.
 
#include "testsuite_abi.h"
#include <iostream>
#include <unistd.h>    // for access(2)

int
main(int argc, char** argv)
{
  using namespace std;

  // Get arguments.  (Heading towards getopt_long, I can feel it.)
  string argv1 = argc > 1 ? argv[1] : "";
  if (argv1 == "--help" || argc < 4)
    {
      cerr << "usage: abi_check --check         current baseline\n"
              "                 --check-verbose current baseline\n"
              "                 --examine       symbol current\n"
              "                 --help\n"
	      "\n"
              "All arguments are string literals.\n"
	      "CURRENT is a file generated byextract_symvers.\n"
              "BASELINE is a file from config/abi.\n"
              "SYMBOL is a mangled name.\n"
	   << endl;
      exit(1);
    }
  
  if (argv1.find("--check") != string::npos)
    {
      bool verbose = false;
      if (argv1 == "--check-verbose")
	verbose = true;
      
      // Quick sanity/setup check for arguments.
      const char* test_file = argv[2];
      const char* baseline_file = argv[3];
      if (access(test_file, R_OK) != 0)
	{
	  cerr << "Cannot read symbols file " << test_file
	       << ", did you forget to build first?" << endl;
	  exit(1);
	}
      if (access(baseline_file, R_OK) != 0)
	{
	  cerr << "Cannot read baseline file " << baseline_file << endl;
	exit(1);
	}
      if (!compare_symbols(baseline_file, test_file, verbose))
	exit (1);
    }
  
  if (argv1 == "--examine")
    {
      const char* file = argv[3];
      if (access(file, R_OK) != 0)
	{
	  cerr << "Cannot read symbol file " << file << endl;
	  exit(1);
	}
      examine_symbol(argv[2], file);
    }
  return 0;
}
