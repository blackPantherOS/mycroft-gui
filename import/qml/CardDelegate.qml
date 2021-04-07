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

import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12 as Controls
import org.kde.kirigami 2.12 as Kirigami
import QtGraphicalEffects 1.12

Delegate {
    id: root
    leftPadding: 0
    bottomPadding: 0
    topPadding: 0
    rightPadding: 0
    
    rightInset: 30
    leftInset: 30
    topInset: 30
    bottomInset: 35
    
    // Allows cards to set the background image of only the card
    // Allows setting a color overlay for card background
    property alias cardBackgoundBorderColor: cardBackgound.color
    property alias cardBackgroundOverlayColor: backgroundColor.color
    property alias cardBackgroundImage: backgroundImage.source
    property int cardRadius: 20
    
    background: Rectangle {
        id: cardBackgound
        anchors.fill: parent
        color: "black"
        z: 1
            
        Image {
            id: backgroundImage
            anchors.fill: parent
            anchors.leftMargin: root.leftInset
            anchors.rightMargin: root.rightInset
            anchors.topMargin: root.topInset
            anchors.bottomMargin: root.bottomInset
            source: ""
            layer.enabled: true
            layer.effect: OpacityMask {
                maskSource: Rectangle {
                    width: backgroundImage.width
                    height: backgroundImage.height
                    visible: false
                    radius: cardRadius
                }
            }
        }
        
        Rectangle {
            id: backgroundColor
            anchors.fill: parent
            anchors.leftMargin: root.leftInset
            anchors.rightMargin: root.rightInset
            anchors.topMargin: root.topInset
            anchors.bottomMargin: root.bottomInset
            color: Qt.rgba(255, 255, 255, 0.5)
            radius: cardRadius
        }
    }

    contentItem: Item {
        z: 2
    }
}
