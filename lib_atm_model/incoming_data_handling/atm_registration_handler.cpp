﻿#include <atm_registration_handler.h>

ATM::RegistrationStatus AtmRegistrationHandler::HandleLoginString(
    const std::string& login) {
  login_status_ = registration_inpector_.InspectLoginString(login);

  CheckLoginString();

  return login_status_;
}

ATM::RegistrationStatus AtmRegistrationHandler::HandlePasswordString(
    const std::string& password) {
  password_status_ = registration_inpector_.InspectPasswordString(password);

  CheckPasswodString();

  return password_status_;
}

void AtmRegistrationHandler::HandlePasswordTooltip(
    const std::string& password_tooltip) {
  is_password_tooltip_correct_ =
      registration_inpector_.IsPasswordTooltipCorrect(
          password_tooltip.length());
}

bool AtmRegistrationHandler::IsRegistrationDataCorrect() const {
  bool correct_registration_data =
      is_login_correct_ && is_password_correct_ && is_password_tooltip_correct_;
  return correct_registration_data;
}

bool AtmRegistrationHandler::PasswordTooltipCondition() const {
  return is_password_tooltip_correct_;
}

void AtmRegistrationHandler::CheckLoginString() {
  if (login_status_ == ATM::RegistrationStatus::kCorrectLogin) {
    is_login_correct_ = true;
  } else {
    is_login_correct_ = false;
  }
}

void AtmRegistrationHandler::CheckPasswodString() {
  if (password_status_ == ATM::RegistrationStatus::kCorrectPassword) {
    is_password_correct_ = true;
  } else {
    is_password_correct_ = false;
  }
}
