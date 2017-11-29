﻿#ifndef ATM_BUTTON_H
#define ATM_BUTTON_H

#include <QPushButton>

class QRect;
class QString;
class QWidget;
class QFont;

class AtmButton : public QPushButton {
  Q_OBJECT
 public:
  enum OffsetSide { kNone = 0, kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

  AtmButton(const QString& text, QWidget* widget = nullptr);

  void SetFont(const QFont& font);

  void SetOffsetSide(unsigned int offset_side);

  void SetXHoverOffset(int x_offset = 2);
  void SetYHoverOffset(int y_offset = 2);

  ~AtmButton();

 protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);
  void resizeEvent(QResizeEvent* event);

 private:
  void SetSizePolicy();
  void OffsetButton();
  void ReturnToInitialPosition();

  int x_offset_ = 1;
  int y_offset_ = 1;
  unsigned int offset_side_ = 0;
  unsigned int font_size_px_ = 0;

  bool is_focus_ = false;
};

#endif  // ATM_BUTTON_H
