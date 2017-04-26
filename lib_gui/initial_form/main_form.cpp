﻿#include "main_form.h"
#include "ui_main_form.h"

#include <QApplication>

#include "timedate_changer.h"
#include "widget_centerer.h"

MainForm::MainForm(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainForm) {
  ui->setupUi(this);

  InitializeObjects();
  SetMainFormProperties();
  SetConnections();
  RunTimers();
}

MainForm::~MainForm() {
  delete ui;
  delete color_timer_;
  delete running_text_timer_;
  delete running_text_;
  delete color_swapper_;
  delete time_date_timer_;
}

void MainForm::ChangeTextColor() {
  color_swapper_->ChangeColor(ui->atm_label, "rgb(138, 226, 52)",
                              "rgb(32, 74, 135)");
}

void MainForm::RunText() { running_text_->UpdateText(ui->running_label); }

void MainForm::ChangeTimeDate() {
  TimeDateChanger::ChangeTimeData(ui->timedate_label);
}

void MainForm::SetMainFormProperties() {
  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  setFixedSize(600, 400);
  WidgetCenterer::MoveToCenter(this);
}

void MainForm::SetConnections() {
  connect(color_timer_, SIGNAL(timeout()), SLOT(ChangeTextColor()));
  connect(running_text_timer_, SIGNAL(timeout()), SLOT(RunText()));
  connect(time_date_timer_, SIGNAL(timeout()), SLOT(ChangeTimeDate()));
}

void MainForm::InitializeObjects() {
  color_timer_ = new QTimer(ui->atm_label);
  running_text_timer_ = new QTimer(ui->running_label);
  running_text_ = new RunningText();
  color_swapper_ = new TextColorSwapper();
  time_date_timer_ = new QTimer(ui->timedate_label);
}

void MainForm::RunTimers() {
  color_timer_->start(350);
  running_text_timer_->start(15);
  time_date_timer_->start(1000);
}
