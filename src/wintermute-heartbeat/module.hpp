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

#ifndef WINTERMUTE_HEARTBEAT_MODULE_HPP_
# define WINTERMUTE_HEARTBEAT_MODULE_HPP_

#include <wintermutecore/module.hpp>
#include "globals.hpp"

namespace Wintermute
{
namespace Heartbeat
{
class ModulePrivate;
class PongMessage;
class Module : public Wintermute::Module
{
  friend class PongMessage;
  W_DEF_PRIVATE(Wintermute::Heartbeat::Module)
  W_DECL_PTR_TYPE(Wintermute::Heartbeat::Module)

  public:
    explicit Module();
    virtual ~Module();

  protected:
    string obtainUuid() const;
    virtual bool sendMessage(const Message& message);
    virtual bool receiveMessage(const Message& message) const;
};
}
}

#endif
