/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef S60SYMBIANCERTIFICATE_H
#define S60SYMBIANCERTIFICATE_H

#include <QtCore/QStringList>

QT_FORWARD_DECLARE_CLASS(QDateTime)

class S60SymbianCertificatePrivate;

namespace Qt4ProjectManager {
namespace Internal {

class S60SymbianCertificate
{
public:
    explicit S60SymbianCertificate(const QString &filename);
    ~S60SymbianCertificate();

    bool isValid() const;

    QString errorString() const;

    QStringList subjectInfo(const QString &name);
    QStringList issuerInfo(const QString &name);

    QDateTime startTime();
    QDateTime endTime();

    quint32 certificateVersion();
    bool isSelfSigned();
    bool isCaCert();

private:
    QDateTime parseTime(const QByteArray &time);

protected:
    S60SymbianCertificatePrivate const *m_d;
    QString m_errorString;
};

} // namespace Internal
} // namespace Qt4ProjectManager

#endif // S60SYMBIANCERTIFICATE_H
