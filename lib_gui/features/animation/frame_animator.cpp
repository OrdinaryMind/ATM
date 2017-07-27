﻿#include <frame_animator.h>

#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QTimer>
#include <QWidget>

#include <side.h>

FrameAnimator::FrameAnimator(QWidget* parent)
    : QObject(parent), animation_(new QPropertyAnimation) {}

FrameAnimator::~FrameAnimator() { delete animation_; }

void FrameAnimator::SetWidgetForAnimation(QWidget* widget,
                                          AnimationType animation_type) {
  animation_->setTargetObject(widget);
  animation_->setPropertyName("geometry");
  animation_->setEasingCurve(QEasingCurve::OutCirc);
  animation_->setDuration(animation_duration_msec_);

  animation_type_ = animation_type;
}

void FrameAnimator::SetAnimationCurve(QEasingCurve animation_curve) {
  animation_->setEasingCurve(animation_curve);
}

void FrameAnimator::SetAnimationDirection(unsigned int animation_direction) {
  animation_direction_ = CheckOnPositiveValue(animation_direction);
}

void FrameAnimator::HideFrame(const QRect& geometry) {
  SetAnimationGeometry(geometry);
  animation_->start();
  QTimer::singleShot(animation_duration_msec_, this, SLOT(EndAnimation()));
}

void FrameAnimator::EndAnimation() { emit AnimationComplete(); }

void FrameAnimator::SetAnimationGeometry(const QRect& geometry) {
  SetStartAnimationGeometry(geometry);
  SetEndAnimationGeometry(geometry);
}

void FrameAnimator::SetStartAnimationGeometry(const QRect& start_geometry) {
  switch (animation_type_) {
    case kHideFrame:
      SetStartHideGeometry(start_geometry);
      break;
    case kExtrudeFrame:
    // SetStartExtrudeGeometry(start_geometry);
    // break;
    default:
      break;
  }
}

void FrameAnimator::SetEndAnimationGeometry(const QRect& end_geometry) {
  switch (animation_type_) {
    case kHideFrame:
      SetEndHideGeometry(end_geometry);
      break;
    case kExtrudeFrame:
    // SetEndExtrudeGeometry();
    // break;
    default:
      break;
  }
}

void FrameAnimator::SetStartHideGeometry(const QRect& start_geometry) {
  animation_->setStartValue(start_geometry);
}

void FrameAnimator::SetEndHideGeometry(const QRect& end_geometry) {
  int x = end_geometry.x();
  int y = end_geometry.y();
  int width = end_geometry.width();
  int height = end_geometry.height();

  if (animation_direction_ & Side::kUp) {
    height = 0;
  }
  if (animation_direction_ & Side::kDown) {
    y += height;
    height = 0;
  }
  if (animation_direction_ & Side::kLeft) {
    width = 0;
  }
  if (animation_direction_ & Side::kRight) {
    x += width;
    width = 0;
  }

  animation_->setEndValue(QRect(x, y, width, height));
}

void FrameAnimator::SetDuration(unsigned int animation_duration_msec) {
  animation_duration_msec_ = CheckOnPositiveValue(animation_duration_msec);
  animation_->setDuration(animation_duration_msec_);
}

int FrameAnimator::CheckOnPositiveValue(int value) {
  if (value < 0) {
    value = 0;
  }
  return value;
}
