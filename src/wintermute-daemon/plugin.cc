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

#include <wintermute-core/globals.hpp>
#include <wintermute-core/logging.hpp>
#include <wintermute-core/plugin.hpp>
#include <wintermute-core/method.hpp>
#include "plugin.hh"

using Wintermute::Plugin;
using Wintermute::Module;
using Wintermute::Util::Configuration;
using DaemonPluginPrivate = Wintermute::Daemon::PluginPrivate;
using std::to_string;

DaemonPluginPrivate::PluginPrivate() :
  module(make_shared<Wintermute::Daemon::Module>())
{
}

DaemonPluginPrivate::~PluginPrivate()
{
}

void DaemonPluginPrivate::loadHeartbeat()
{
  Plugin::Ptr heartbeatPluginPtr = Plugin::find("wintermute-heartbeat");
  const bool loadedPlugin = !heartbeatPluginPtr;
  if (!loadedPlugin)
  {
    wdebug("Failed to load the heartbeat plugin.");
    return;
  }
  else
  {
    winfo("Heartbeat plugin loaded.");
  }

  // FIXME: So for now, we'll have the heartbeat plugin know whether or not if
  // it should run as the pinger or the pingee by the existence of the daemon
  // plugin. Realistically, there should be only one process on the machine
  // that has the daemon plugin loaded so it's a contract we'll have to find a
  // way to enforce. This way, we'd never have to link the daemon plugin
  // directly to the heartbeat plugin to invoke particular actions on it.
}

void DaemonPluginPrivate::unloadHeartbeat()
{
  const bool unloadedPlugin = Plugin::release("wintermute-heartbeat");
  if (!unloadedPlugin)
  {
    wdebug("Failed to unload the heartbeat plugin.");
    return;
  }
  else
  {
    winfo("Heartbeat plugin unloaded.");
  }
}

Configuration::Ptr DaemonPluginPrivate::config() const
{
  Configuration::Ptr daemonCfg;
  // TODO: Try a collection of options here.
  daemonCfg = Configuration::obtainStore(WINTERMUTE_DAEMON_CFG_PATH);

  return daemonCfg;
}
