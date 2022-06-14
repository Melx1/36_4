//
// Created by Melx on 14.06.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Qcircle.h" resolved

#include "qcircle.h"
#include "ui_Qcircle.h"


QCircle::QCircle(QWidget *parent) :
        QWidget(parent), ui(new Ui::Qcircle) {
    ui->setupUi(this);
}

QCircle::~QCircle() {
    delete ui;
}

