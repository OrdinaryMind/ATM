﻿#ifndef INITIAL_FRAME_GEOMETRY_H
#define INITIAL_FRAME_GEOMETRY_H

#include <QRect>

class InitialFrameGeometry {
 public:
  static QRect InitialFrame();
  static QRect SignInButton();
  static QRect RegistrationButton();
  static QRect DemoButton();

 private:
  static QRect kInitialFrame;
  static QRect kSignInButton;
  static QRect kRegistrationButton;
  static QRect kDemoButton;
};

#endif  // INITIAL_FRAME_GEOMETRY_H
