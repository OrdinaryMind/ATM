﻿#include <registration_description_label.h>

#include <QWidget>

#include <atm_color_designer.h>
#include <atm_composer.h>
#include <registration_menu_geometry.h>
#include <widget_font.h>

#include <QDebug>

QString RegistrationDescriptionLabel::kDescriptionText =
    "Familiarize with registration rules:\n"
    "- Length of login: 6-35 latin symbols inclusively\n"
    "- Length of password: 6 symbols\n"
    "- Length of tooltip: no more than 50 symbols\n"
    "- Login must not contain special symbols\n"
    "( e.g. ; - % # ! and so on )\n"
    "- Password must not contain space symbols\n"
    "- Password may contain both latin alphabet symbols and arabic digits";

RegistrationDescriptionLabel::RegistrationDescriptionLabel(QWidget* parent)
    : QLabel(parent) {
  SetInitialSettings();
}

RegistrationDescriptionLabel::~RegistrationDescriptionLabel() {}

void RegistrationDescriptionLabel::ChangeGeometry() {
  AtmComposer::StretchWidget(RegistrationMenuGeometry::DesctiptionLabel(),
                             Side::kRight | Side::kDown, 1.0, 0.7, this);

  size_controller_.ControlFontSize(kInitialLabelFont, 3.0, 200, this);

  qDebug() << "Label:\n"
              "width: "
           << this->width() << "height: " << this->height() << "\n\n";

  // font testing
  QFontMetrics font_metrics_(font());

  qDebug() << "Avarage char width: " << font_metrics_.averageCharWidth();
}

void RegistrationDescriptionLabel::SetInitialSettings() {
  AtmColorDesigner::PaintSingleWidget(this);
  setText(kDescriptionText);
  setFont(WidgetFont::SetFont(kInitialLabelFont));
  setGeometry(RegistrationMenuGeometry::DesctiptionLabel());
  setAlignment(Qt::AlignLeft | Qt::AlignTop);
  setWordWrap(true);
}
