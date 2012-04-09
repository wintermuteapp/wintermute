/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp dbus.xml -a dbus -p dbus_proxy
 *
 * qdbusxml2cpp is Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "interfaces.hpp"
#include "config.hpp"
#include <ipc.hpp>
#include <plugins.hpp>

using Wintermute::Linguistics::SystemInterface;

SystemInterface::SystemInterface()
    : QDBusAbstractInterface (WNTRLING_DBUS_SERVICE, "/System", staticInterfaceName(), *IPC::System::bus(), Plugins::Factory::currentPlugin())
{
}

void SystemInterface::start()
{
    QList<QVariant> argumentList;
    callWithArgumentList (QDBus::NoBlock, QLatin1String ("start"), argumentList);
}

void SystemInterface::stop()
{
    QList<QVariant> argumentList;
    callWithArgumentList (QDBus::NoBlock, QLatin1String ("stop"), argumentList);
}

QDBusPendingReply<> SystemInterface::tellSystem (const QString& in0)
{
    QList<QVariant> argumentList;
    argumentList << qVariantFromValue (in0);
    return asyncCallWithArgumentList (QLatin1String ("tellSystem"), argumentList);
}


SystemInterface::~SystemInterface()
{
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 