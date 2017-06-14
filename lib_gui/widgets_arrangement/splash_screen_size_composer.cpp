﻿#include <splash_screen_size_composer.h>

#include <QFrame>
#include <QPushButton>

void SplashScreenSizeComposer::RememberInitialGeometry(
    const QRect& splash_screen,
    const QRect& version_label,
    const QRect& company_name_label,
    const QRect& time_date_label,
    const QRect& atm_label,
    const QRect& text_label,
    const QRect& frame) {
  splash_screen_ = splash_screen;
  version_label_ = version_label;
  company_name_label_ = company_name_label;
  time_date_label_ = time_date_label;
  atm_label_ = atm_label;
  text_label_ = text_label;
  frame_ = frame;
}

void SplashScreenSizeComposer::InitializeControlButtonsGeometry(
    const QRect& exit_button,
    const QRect& minimize_button,
    const QRect& maximaze_button) {
  window_button_composer_.InitializeButtons(exit_button, minimize_button,
                                            maximaze_button);
}

void SplashScreenSizeComposer::ResizeFrame(QFrame* frame) {
  frame->setGeometry(frame_.x(), frame->y(), frame_.width() + extra_width_,
                     frame_.height() + extra_height_);
}

void SplashScreenSizeComposer::ResizeControlButtons(
    QPushButton* exit_button,
    QPushButton* minimize_button,
    QPushButton* maximize_button) {
  window_button_composer_.SetExtraGeometryButtonSize(extra_width_,
                                                     extra_height_);
  window_button_composer_.ResizeExitButton(exit_button);
  window_button_composer_.ResizeMinimizeButton(minimize_button);
  window_button_composer_.ResizeMaximizeButton(maximize_button);
}

void SplashScreenSizeComposer::SetExtraGeometrySize(int extra_width,
                                                    int extra_height) {
  extra_width_ = extra_width - splash_screen_.width();
  extra_height_ = extra_height - splash_screen_.height();
}