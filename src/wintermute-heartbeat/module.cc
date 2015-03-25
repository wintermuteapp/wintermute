/*
    Wintermute - A foundation for intelligent computing.
    Copyright (c) 2010 - 2015 by Jacky Alcine

    Wintermute is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    Wintermute is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with Wintermute; if not, write to the
    Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
 */

#include <wintermutecore/globals.hpp>
#include <uuid.h>
#include "module.hh"

using Wintermute::Heartbeat::ModulePrivate;

ModulePrivate::ModulePrivate() : uuid()
{
  generateUuid();
}

ModulePrivate::~ModulePrivate()
{
}

void ModulePrivate::generateUuid()
{
  uuid_t aUuid;
  uuid_generate_time_safe(aUuid);
  //uuid_unparse_lower(aUuid, uuidStr);
  //uuid = uuidStr;
  // TODO: Generate a UUID to be used by this module.
}
