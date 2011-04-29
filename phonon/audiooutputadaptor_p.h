/*
 * This file was generated by dbusidl2cpp version 0.4
 * when processing input file org.kde.Phonon.AudioOutput.xml
 *
 * dbusidl2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file. This file has been hand-edited.
 */

#ifndef AUDIOOUTPUTADAPTOR_P_H
#define AUDIOOUTPUTADAPTOR_P_H

#include "phononconfig_p.h"

#include <QtCore/QObject>

#ifndef PHONON_NO_DBUS
#include <QtDBus/QtDBus>

QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE

class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;

namespace Phonon
{
    class AudioOutputPrivate;
    class AudioOutput;

/*
 * Adaptor class for interface org.kde.Phonon.AudioOutput
 */
class AudioOutputAdaptor: public QDBusAbstractAdaptor
{
    friend class Phonon::AudioOutputPrivate;
    friend class Phonon::AudioOutput;
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.Phonon.AudioOutput")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"org.kde.Phonon.AudioOutput\" >\n"
"    <property access=\"readwrite\" type=\"d\" name=\"volume\" />\n"
"    <property access=\"readwrite\" type=\"b\" name=\"muted\" />\n"
"    <property access=\"readwrite\" type=\"i\" name=\"outputDeviceIndex\" />\n"
"    <signal name=\"volumeChanged\" >\n"
"      <arg direction=\"out\" type=\"d\" />\n"
"    </signal>\n"
"    <signal name=\"mutedChanged\" >\n"
"      <arg direction=\"out\" type=\"b\" />\n"
"    </signal>\n"
"    <signal name=\"outputDeviceIndexChanged\" >\n"
"      <arg direction=\"out\" type=\"i\" />\n"
"    </signal>\n"
"    <signal name=\"nameChanged\" >\n"
"      <arg direction=\"out\" type=\"s\" name=\"newName\" />\n"
"    </signal>\n"
"    <signal name=\"newOutputAvailable\" >\n"
"      <arg direction=\"out\" type=\"s\" name=\"service\" />\n"
"      <arg direction=\"out\" type=\"s\" name=\"path\" />\n"
"    </signal>\n"
"    <signal name=\"outputDestroyed\" >\n"
"    </signal>\n"
"    <method name=\"category\" >\n"
"      <arg direction=\"out\" type=\"s\" />\n"
"    </method>\n"
"    <method name=\"name\" >\n"
"      <arg direction=\"out\" type=\"s\" />\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    AudioOutputAdaptor(QObject *parent);
    virtual ~AudioOutputAdaptor();

public: // PROPERTIES
    Q_PROPERTY(bool muted READ muted WRITE setMuted)
    bool muted() const;
    void setMuted(bool value);

    Q_PROPERTY(int outputDeviceIndex READ outputDeviceIndex WRITE setOutputDeviceIndex)
    int outputDeviceIndex() const;
    void setOutputDeviceIndex(int value);

    Q_PROPERTY(double volume READ volume WRITE setVolume)
    double volume() const;
    void setVolume(double value);

public Q_SLOTS: // METHODS
    QString category();
    QString name();
Q_SIGNALS: // SIGNALS
    void mutedChanged(bool in0);
    void nameChanged(const QString &newName);
    void newOutputAvailable(const QString &service, const QString &path);
    void outputDestroyed();
    void outputDeviceIndexChanged(int in0);
    void volumeChanged(qreal in0);
};

} // namespace Phonon

QT_END_NAMESPACE
QT_END_HEADER

#endif // PHONON_NO_DBUS

#endif // AUDIOOUTPUTADAPTOR_P_H
