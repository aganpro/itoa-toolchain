/* Target-dependent definitions for SuperH running NetBSD, for GDB.
   Copyright (C) 2002 Free Software Foundation, Inc.
   Contributed by Wasabi Systems, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

#ifndef SH_NBSD_TDEP_H
#define SH_NBSD_TDEP_H

void shnbsd_supply_reg (char *, int);
void shnbsd_fill_reg (char *, int);

#endif /* SH_NBSD_TDEP_H */
