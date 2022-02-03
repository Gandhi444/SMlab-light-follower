/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwidget.h"



QT_CHARTS_USE_NAMESPACE

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{

    LCD1 = new QLCDNumber();
    LCD1->setSegmentStyle(QLCDNumber::Flat);
    LCD1->setAutoFillBackground(0);
    LCD1->display(0);
    LCD2 = new QLCDNumber();
    LCD2->setSegmentStyle(QLCDNumber::Flat);
    LCD2->setAutoFillBackground(0);
    LCD2->display(0);
    LCD3 = new QLCDNumber();
    LCD3->setSegmentStyle(QLCDNumber::Flat);
    LCD3->setAutoFillBackground(0);
    LCD3->display(0);
    connectButton = new QPushButton(tr("Connect"));
    connectButton->setToolTip(tr("Connect with avalible STM32"));
    connect(connectButton, &QPushButton::clicked, this, &MainWidget::connectSerial);
    searchButton = new QPushButton(tr("Search"));
    connectButton->setToolTip(tr("Search avaible serial port devices"));
    connect(searchButton, &QPushButton::clicked, this, &MainWidget::searchSerial);
    LED1 = new QSlider(Qt::Vertical);
    LED1->setRange(0, 100);
    LED1->setValue(0);
    LED2 = new QSlider(Qt::Vertical);
    LED2->setRange(0, 100);
    LED2->setValue(0);
    LED3 = new QSlider(Qt::Vertical);
    LED3->setRange(0, 100);
    LED3->setValue(0);
    connect(LED1, SIGNAL(valueChanged(int)), LCD1, SLOT(display(int)));
    connect(LED2, SIGNAL(valueChanged(int)), LCD2, SLOT(display(int)));
    connect(LED3, SIGNAL(valueChanged(int)), LCD3, SLOT(display(int)));
    connect(LED1, SIGNAL(valueChanged(int)), LCD1, SLOT(display(int)));
    connect(LED1, SIGNAL(valueChanged(int)), this, SLOT(sendLED1(int)));
    connect(LED1, SIGNAL(valueChanged(int)), this, SLOT(sendLED2(int)));
    connect(LED1, SIGNAL(valueChanged(int)), this, SLOT(sendLED3(int)));
    text = new QLabel;
    text->setText("");
    serialCombo = new QComboBox;
    device = new QSerialPort;

    m_mainLayout = new QGridLayout();

    setLayout(m_mainLayout);
    m_mainLayout->addWidget(searchButton, 0, 0);
    m_mainLayout->addWidget(connectButton, 0, 1);
    m_mainLayout->addWidget(text,1, 0);
    m_mainLayout->addWidget(serialCombo);
    m_mainLayout->addWidget(LED1);
    m_mainLayout->addWidget(LCD1);
    m_mainLayout->addWidget(LED2);
    m_mainLayout->addWidget(LCD2);
    m_mainLayout->addWidget(LED3);
    m_mainLayout->addWidget(LCD3);
}

void MainWidget::clear()
{

}

void MainWidget::searchSerial()
{
    dostepne.clear();
    serialCombo->clear();
    dostepne = QSerialPortInfo::availablePorts();
    if(dostepne.count()) {
        for (int i = 0; i < dostepne.count(); i++) {
            text->setText("dostepne:");
            serialCombo->addItem(dostepne.at(i).portName());
        }
    }
    else {
        text->setText("brak dostepnych urzaden");
        serialCombo->clear();
    }
}

void MainWidget::connectSerial()
{
    device->close();
    text->setText("");
    if(serialCombo->currentIndex()!=-1)
    {
        nazwaPortu = serialCombo->currentText();
        device->setPortName(nazwaPortu);
        device->setBaudRate(QSerialPort::Baud115200);
        device->setDataBits(QSerialPort::Data8);
        device->setParity(QSerialPort::NoParity);
        device->setFlowControl(QSerialPort::NoFlowControl);
        device->setStopBits(QSerialPort::OneStop);
        if (device->open(QSerialPort::ReadWrite)) {
            QString message = "Polaczono z :";
            message.append(dostepne.at(serialCombo->currentIndex()).portName());
            text->setText(message);
            connected = true;
        }
    }
    else
    {
        connected = false;
        text->setText("brak urzadzen");
    }
}

void MainWidget::sendLED1(int val)
{
    value_LED1=val;
    /*
    QByteArray message = QByteArray::number(value_LED1);
    QByteArray count("LED1");
    text->setText(message);
    */
    if(connected && device->isOpen())
    {
            QByteArray message = QByteArray::number(value_LED1);
            QByteArray count("LED1");
            message.insert(3, QByteArray("message"));
            device->write(message);
    }
}

void MainWidget::sendLED2(int val)
{
    value_LED2=val;
    if(connected && device->isOpen())
    {
            QByteArray message = QByteArray::number(value_LED2);
            QByteArray count("LED2");
            message.insert(3, QByteArray("message"));
            device->write(message);
    }
}

void MainWidget::sendLED3(int val)
{
    value_LED3=val;
    if(connected && device->isOpen())
    {
            QByteArray message = QByteArray::number(value_LED3);
            QByteArray count("LED3");
            message.insert(3, QByteArray("message"));
            device->write(message);
    }
}



