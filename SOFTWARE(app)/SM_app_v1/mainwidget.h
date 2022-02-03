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

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtCharts/QChartGlobal>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGraphicsGridLayout>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QValueAxis>
#include <QtCore/QTextStream>
#include <QtCore/QDebug>
#include <QtCharts/QXYLegendMarker>
#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QUrl>
#include <QList>
#include <QMainWindow>
#include <QStringList>
#include <QFileDialog>
#include <QApplication>
#include <QFileDialog>
#include <QSlider>
#include <QtWidgets>
#include <string>
#include"iostream"


QT_CHARTS_USE_NAMESPACE



class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);

public slots:
    void clear();
    void connectSerial();
    void searchSerial();
    void sendLED1(int val);
    void sendLED2(int val);
    void sendLED3(int val);

private:
    //Layout
    QGridLayout *m_mainLayout;

    //Buttons & Switches
    QPushButton *connectButton;
    QPushButton *searchButton;
    QCheckBox *toggle_LED1;
    QCheckBox *toggle_LED2;
    QCheckBox *toggle_LED3;
    QSlider *LED1;
    QLCDNumber *LCD1;
    QSlider *LED2;
    QLCDNumber *LCD2;
    QSlider *LED3;
    QLCDNumber *LCD3;
    QComboBox  *serialCombo;

    //Variables
    QSerialPort *device;
    QLabel *text;
    QString nazwaPortu;
    QList<QSerialPortInfo> dostepne;
    int value_LED1 = 0;
    int value_LED2 = 0;
    int value_LED3 = 0;
    bool connected = false;
};

#endif // MAINWIDGET_H
