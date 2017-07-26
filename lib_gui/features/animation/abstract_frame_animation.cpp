﻿#include <abstract_frame_animation.h>

#include <QPropertyAnimation>
#include <QWidget>

AbstractFrameAnimation::AbstractFrameAnimation(QWidget* parent)
    : QObject(parent), property_animation_(new QPropertyAnimation) {}

AbstractFrameAnimation::~AbstractFrameAnimation() {
  delete property_animation_;
}

void AbstractFrameAnimation::SetWidgetForAnimation(QWidget* widget) {
  property_animation_->setTargetObject(widget);
}

int AbstractFrameAnimation::CheckOnPositiveValue(int value) {
  if (value < 0) {
    value = 0;
  }
  return value;
}

QPropertyAnimation* AbstractFrameAnimation::PropertyAnimation() const {
  return property_animation_;
}
