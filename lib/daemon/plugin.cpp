/**
 * vim: ft=cpp tw=78
 * Copyright (C) 2013 Jacky Alciné <me@jalcine.me>
 *
 * Wintermute is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Wintermute is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Wintermute.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "plugin.hpp"
#include "globals.hpp"
#include "module.hpp"
#include "plugin.moc"

using Wintermute::Daemon::Plugin;
using Wintermute::Daemon::Module;
using Wintermute::Version;

Plugin::Plugin()
{
  module = new Daemon::Module ( this );
  module->connect(this, SIGNAL(started()), SLOT(start()));
}

QString
Plugin::name() const
{
  return "wintermute-daemon";
}

void
Plugin::stop()
{
}

void
Plugin::start()
{
  // TODO Ask for the loading of a messaging plug-in.
}

Version
Plugin::version() const
{
  return Version::fromString ( configuration()->value ( "Version/Plugin" ).toString() );
}

Version
Plugin::systemVersion() const
{
  return Version::fromString ( configuration()->value ( "Version/System" ).toString() );
}

Plugin::State
Plugin::state() const
{
  return Loaded;
}

Plugin::Type
Plugin::type() const
{
  return Module;
}

Q_EXPORT_PLUGIN2 ( wintermute-daemon, Wintermute::Daemon::Plugin );
