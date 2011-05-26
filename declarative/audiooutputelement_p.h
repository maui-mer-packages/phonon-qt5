/*
    Copyright (C) 2011 Harald Sitter <sitter@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), Nokia Corporation
    (or its successors, if any) and the KDE Free Qt Foundation, which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef AUDIOOUTPUTELEMENT_H
#define AUDIOOUTPUTELEMENT_H

#include <QtDeclarative/QDeclarativeItem>

namespace Phonon {

class MediaObject;
class AudioOutput;

namespace Declarative {

class AudioOutputElement : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
public:
    AudioOutputElement(QDeclarativeItem *parent = 0);
    ~AudioOutputElement();

    QUrl source() const;
    void setSource(const QUrl &url);

signals:
    void sourceChanged();

public slots:
    void play();
    void stop();

private:
    void init();

    // TODO: can go to a possible base class
    MediaObject *m_mediaObject;

    AudioOutput *m_audioOutput;

    QUrl m_source;
};

} // namespace Declarative
} // namespace Phonon

#endif // AUDIOOUTPUTELEMENT_H
