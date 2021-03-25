#include "pagemanager.h"
#include <QDebug>

PageManager::PageManager(QObject *parent)
    : QObject(parent)
{
    connect(&m_delegateOverrideTimer, &QTimer::timeout, this, [this](){
        qDebug() << "Got A Timeout";
        m_delegateOverrideTimer.stop();
        emit delegateTimeoutCompleted();
    });
}

PageManager::~PageManager()
{
}

void PageManager::setDelegateOverride(const QVariant &override)
{
    qDebug() << "In Set Delegate Override";
    qDebug() << override.userType();
    switch(override.userType()){
        case QMetaType::Bool:
            delegateOverrideHard(override.toBool());
            break;
        case QMetaType::Int:
        case QMetaType::UInt:
        case QMetaType::LongLong:
        case QMetaType::ULongLong:
        case QMetaType::Float:
        case QMetaType::Double:
            delegateOverrideSoft(override.toInt());
            break;
    }
}

void PageManager::delegateOverrideHard(const bool &fixed)
{
    qDebug() << "Got Delegate Override Hard" << fixed;
}

void PageManager::delegateOverrideSoft(const int &timeout)
{
    if(m_delegateOverrideTimer.isActive()){
        qDebug() << "Found an active timer, canceling previous";
        m_delegateOverrideTimer.stop();
    };
    int override_timeout = timeout * 1000;
    qDebug() << "Override Timeout Set For Milliseconds:" << override_timeout;
    m_delegateOverrideTimer.setInterval(override_timeout);
    m_delegateOverrideTimer.start();
    qDebug() << "Got Delegate Override Soft" << timeout;
}
