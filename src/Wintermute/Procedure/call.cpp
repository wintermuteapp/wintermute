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
#include "Wintermute/application.hpp"
#include "Wintermute/Procedure/call.hpp"
#include "Wintermute/private/Procedure/call.hpp"
#include "Wintermute/Procedure/module.hpp"

using Wintermute::Procedure::Call;
using Wintermute::Procedure::Module;

Call::Call(QObject* parent) : QObject(parent), d_ptr(new CallPrivate(this)) {
}

Call::Call(CallPrivate *d) : QObject(Wintermute::Application::instance()), d_ptr(d) {
}

QVariant
Call::invoke(const QVariantList& arguments){
  Q_D(Call);
  return d->function(arguments);
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
  Q_D(const Call);
  return d->recipient;
}

QString
Call::toString() const {
  Q_D(const Call);
  QJson::Serializer serializer;
  bool ok;

  QMap<QString, QVariant> callMap;
  callMap["type"] = (int) type();
  callMap["recipient"] = d->recipient;
  callMap["data"] = d->data;

  QByteArray json = serializer.serialize(callMap, &ok);

  if (ok)
    return QString(json);
  else
    return QString();
}

QVariant
Call::operator()(const QVariantList& arguments) {
  return this->invoke(arguments);
}

Call::~Call() {
}

#include "Wintermute/Procedure/call.moc"