﻿#include <widget_font.h>

QString WidgetFont::kWin32Family = "Copperplate Gothic Bold";
QString WidgetFont::kLinuxFamily = "Ubuntu";

QFont WidgetFont::kWin32Font;
QFont WidgetFont::kLinuxFont;

QFont WidgetFont::SetFont(int font_point_size_pt) {
  SetFamily();
#ifdef WIN32
  kWin32Font.setPointSize(font_point_size_pt);
  return kWin32Font;
#else
  kLinuxFont.setPointSize(font_point_size_pt);
  return kLinuxFont;
#endif
}

void WidgetFont::SetFamily() {
  kWin32Font.setFamily(kWin32Family);
  kLinuxFont.setFamily(kLinuxFamily);
}
