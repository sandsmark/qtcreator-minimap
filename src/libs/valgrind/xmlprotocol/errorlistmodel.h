/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** Author: Frank Osterfeld, KDAB (frank.osterfeld@kdab.com)
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** No Commercial Usage
**
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**************************************************************************/

#ifndef LIBVALGRIND_PROTOCOL_ERRORLISTMODEL_H
#define LIBVALGRIND_PROTOCOL_ERRORLISTMODEL_H

#include "../valgrind_global.h"

#include <QtCore/QAbstractItemModel>
#include <QtCore/QSharedPointer>

namespace Valgrind {
namespace XmlProtocol {

class Error;
class Frame;

class VALGRINDSHARED_EXPORT ErrorListModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum Column {
        WhatColumn=0,
        LocationColumn,
        AbsoluteFilePathColumn,
        LineColumn,
        UniqueColumn,
        TidColumn,
        KindColumn,
        LeakedBlocksColumn,
        LeakedBytesColumn,
        HelgrindThreadIdColumn,
        ColumnCount
    };

    enum Role {
        ErrorRole=Qt::UserRole,
        AbsoluteFilePathRole,
        FileRole,
        LineRole
    };

    class RelevantFrameFinder
    {
    public:
        virtual ~RelevantFrameFinder() {}
        virtual Frame findRelevant(const Error &error) const = 0;
    };

    explicit ErrorListModel(QObject *parent=0);
    ~ErrorListModel();

    QSharedPointer<const RelevantFrameFinder> relevantFrameFinder() const;
    void setRelevantFrameFinder(const QSharedPointer<const RelevantFrameFinder> &finder);

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

    Error error(const QModelIndex &index) const;

    Frame findRelevantFrame(const Error &error) const;

    void clear();

public Q_SLOTS:
    void addError(const Valgrind::XmlProtocol::Error &error);

private:
    class Private;
    Private *const d;
};

}
}

#endif // LIBVALGRIND_PROTOCOL_ERRORLISTMODEL_H
