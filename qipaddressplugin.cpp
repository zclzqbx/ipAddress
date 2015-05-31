#include "qipaddress.h"
#include "qipaddressplugin.h"

#include <QtPlugin>

QIpAddressPlugin::QIpAddressPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QIpAddressPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QIpAddressPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QIpAddressPlugin::createWidget(QWidget *parent)
{
    return new QIpAddress(parent);
}

QString QIpAddressPlugin::name() const
{
    return QLatin1String("QIpAddress");
}

QString QIpAddressPlugin::group() const
{
    return QLatin1String("");
}

QIcon QIpAddressPlugin::icon() const
{
    return QIcon();
}

QString QIpAddressPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QIpAddressPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QIpAddressPlugin::isContainer() const
{
    return false;
}

QString QIpAddressPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QIpAddress\" name=\"qIpAddress\">\n</widget>\n");
}

QString QIpAddressPlugin::includeFile() const
{
    return QLatin1String("qipaddress.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qipaddressplugin, QIpAddressPlugin)
#endif // QT_VERSION < 0x050000
