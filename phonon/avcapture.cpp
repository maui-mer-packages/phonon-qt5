/*  This file is part of the KDE project
    Copyright (C) 2011 Casian Andrei <skeletk13@gmail.com>

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

#ifndef PHONON_NO_CAPTURE

#include "avcapture.h"
#include "avcaptureinterface.h"
#include "avcapture_p.h"
#include "factory_p.h"
#include "globalconfig.h"
#include "phononnamespace_p.h"

#define PHONON_CLASSNAME AvCapture
#define PHONON_INTERFACENAME AvCaptureInterface

namespace Phonon
{
PHONON_OBJECT_IMPL

AvCapture::AvCapture(CaptureCategory category, QObject *parent)
    : QObject(parent), MediaNode(*new AvCapturePrivate())
{
    setCaptureDevices(category);
}

State AvCapture::state() const
{
    K_D(const AvCapture);
    if (d->m_backendObject) {
        return INTERFACE_CALL(state());
    }
    return StoppedState;
}

void AvCapture::start()
{
    K_D(AvCapture);
    if (d->backendObject()) {
        INTERFACE_CALL(start());
    }
}

void AvCapture::pause()
{
    K_D(AvCapture);
    if (d->backendObject()) {
        INTERFACE_CALL(pause());
    }
}

void AvCapture::stop()
{
    K_D(AvCapture);
    if (d->backendObject()) {
        INTERFACE_CALL(stop());
    }
}

void AvCapture::setCaptureDevices(CaptureCategory category)
{
    setAudioCaptureDevice(category);
    setVideoCaptureDevice(category);
}

AudioCaptureDevice AvCapture::audioCaptureDevice() const
{
    K_D(const AvCapture);
    if (d->m_backendObject) {
        return INTERFACE_CALL(audioCaptureDevice());
    }
    return d->audioCaptureDevice;
}

VideoCaptureDevice AvCapture::videoCaptureDevice() const
{
    K_D(const AvCapture);
    if (d->m_backendObject) {
        return INTERFACE_CALL(videoCaptureDevice());
    }
    return d->videoCaptureDevice;
}

void AvCapture::setAudioCaptureDevice(const AudioCaptureDevice &audioCaptureDevice)
{
    K_D(AvCapture);
    d->audioCaptureDevice = audioCaptureDevice;
    if (d->m_backendObject) {
        INTERFACE_CALL(setAudioCaptureDevice(d->audioCaptureDevice));
    }
}

void AvCapture::setAudioCaptureDevice(CaptureCategory category)
{
    K_D(AvCapture);
    d->audioCaptureDevice = AudioCaptureDevice::fromIndex(GlobalConfig().audioCaptureDeviceFor(category));
    if (d->m_backendObject) {
        INTERFACE_CALL(setAudioCaptureDevice(d->audioCaptureDevice));
    }
}

void AvCapture::setVideoCaptureDevice(const VideoCaptureDevice &videoCaptureDevice)
{
    K_D(AvCapture);
    d->videoCaptureDevice = videoCaptureDevice;
    if (d->m_backendObject) {
        INTERFACE_CALL(setVideoCaptureDevice(d->videoCaptureDevice));
    }
}

void AvCapture::setVideoCaptureDevice(CaptureCategory category)
{
    K_D(AvCapture);
    d->videoCaptureDevice = VideoCaptureDevice::fromIndex(GlobalConfig().videoCaptureDeviceFor(category));
    if (d->m_backendObject) {
        INTERFACE_CALL(setVideoCaptureDevice(d->videoCaptureDevice));
    }
}

bool AvCapturePrivate::aboutToDeleteBackendObject()
{
    audioCaptureDevice = pINTERFACE_CALL(audioCaptureDevice());
    videoCaptureDevice = pINTERFACE_CALL(videoCaptureDevice());
    return true;
}

void AvCapturePrivate::setupBackendObject()
{
    Q_Q(AvCapture);
    Q_ASSERT(m_backendObject);

    QObject::connect(m_backendObject, SIGNAL(stateChanged(State, State)), q, SIGNAL(stateChanged(State, State)), Qt::QueuedConnection);

    // set up attributes
    pINTERFACE_CALL(setAudioCaptureDevice(audioCaptureDevice));
    pINTERFACE_CALL(setVideoCaptureDevice(videoCaptureDevice));
}

} // namespace Phonon

#include "moc_avcapture.cpp"

#undef PHONON_CLASSNAME
#undef PHONON_INTERFACENAME

#endif // PHONON_NO_CAPTURE
