/*
  $NiH$

  zip_name_locate.c -- get index by name
  Copyright (C) 1999 Dieter Baron and Thomas Klaunser

  This file is part of libzip, a library to manipulate ZIP files.
  The authors can be contacted at <nih@giga.or.at>

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
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/



#include <string.h>

#include "zip.h"
#include "zipint.h"



int
zip_name_locate(struct zip *zf, char *fname, int case_sens)
{
    int i;

    for (i=0; i<zf->nentry; i++)
	if ((case_sens ? strcmp : strcasecmp)(fname, zf->entry[i].fn) == 0)
	    return i;

    return -1;
}
