﻿#ifndef SPLASH_SCREEN_SIZE_COMPOSER_H
#define SPLASH_SCREEN_SIZE_COMPOSER_H

#include <QRect>

#include <atm_label_stretcher.h>

#include <delta_size.h>
#include <geometry_composer.h>

class QPushButton;
class QLabel;
class QFrame;

class AtmSplashScreen;

class SplashScreenSizeComposer {
 public:
  void ComposeFrame(QFrame* frame);
  void ComposeVersionLabel(QLabel* version_label);
  void ComposeCompanyNameLabel(QLabel* company_name_label);
  void ComposeSplashScreenLabels(QLabel* date_label,
                                 QLabel* time_label,
                                 QLabel* text_label);

  void ComposeAtmLabel(QLabel* atm_label);

  void ComputeDeltas(int extra_width, int extra_height);

 private:
  QRect NewLabelGeometry(const QRect& label);

  static const int kAtmLabelFontSize = 100;

  AtmLabelStretcher atm_label_stretcher_;
  GeometryComposer composer_;
  DeltaSize delta_size_;
};

#endif  // SPLASH_SCREEN_SIZE_COMPOSER_H
