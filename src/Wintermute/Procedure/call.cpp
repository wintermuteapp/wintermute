/**
 * vim: ft=qt.cpp
 * Copyright (C) 2013 Jacky Alcine <me@jalcine.me>
 *
 * This file is part of Wintermute, the extensible AI platform.
 *
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

#include <qjson/serializer.h>
#include "Wintermute/Procedure/call.hpp"
#include "Wintermute/private/Procedure/call.hpp"
#include "Wintermute/Procedure/module.hpp"

using Wintermute::Procedure::Call;
using Wintermute::Procedure::Module;

Call::Call(QObject* parent) : QObject(parent){
}

QVariant
Call::dispatch(QVariantList& arguments){
  return Module::invokeCall(this);
}

void
Call::doDispatch(QVariantList& arguments, Callback callback){
  // TODO: Invoke callback.
  Module::invokeCall(this);
}

void
Call::setRecipient(const QString moduleName){
  Q_D(Call);
  d->recipient = QString(moduleName);
}

Call::Type
Call::type() const {
  return Call::Method;
}

QString
Call::recipient() const {
  return QString();
}

QString
Call::toString() const {
  Q_D(const Call);
  QJson::Serializer serializer;
  bool ok;

  QMap<QString, QVariant> callMap;
  callMap["type"] = (int) type();
  callMap["recipient"] = recipient();
  callMap["data"] = d->data;

  QByteArray json = serializer.serialize(callMap, &ok);

  if (ok)
    return QString(json);
  else
    return QString();
}

Call::~Call() {
}

#include "Wintermute/Procedure/call.moc"
