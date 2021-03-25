/*
 * Copyright 2021 by Aditya Mehra <aix.m@outlook.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include <QObject>
#include <QTimer>

class AbstractSkillView;

class PageManager : public QObject
{
    Q_OBJECT

public:
    explicit PageManager(QObject *parent=0);
    virtual ~PageManager();

    void setDelegateOverride(const QVariant &override);
    void delegateOverrideHard(const bool &fixed);
    void delegateOverrideSoft(const int &timeout);

signals:
    void delegateTimeoutCompleted();

private:
    QTimer m_delegateOverrideTimer;

};
