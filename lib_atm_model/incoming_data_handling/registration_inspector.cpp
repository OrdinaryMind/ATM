﻿#include <registration_inspector.h>

#include <registration_data_length_standard.h>

ATM::RegistrationStatus RegistrationInspector::InspectLoginString(
    const std::string& login) {
  string_analyzer_.AnalyzeString(login);

  if (IsLoginShort(login.length())) {
    return ATM::RegistrationStatus::kShortLogin;
  }
  if (IsLoginLong(login.length())) {
    return ATM::RegistrationStatus::kLongLogin;
  }
  if (IsStringContainSpecialSymbols()) {
    return ATM::RegistrationStatus::kSpecialSymbols;
  }
  if (IsStringBeginWithSpace()) {
    return ATM::RegistrationStatus::kBeginWithSpace;
  }
  if (IsStringEndWithSpace()) {
    return ATM::RegistrationStatus::kEndWithSpace;
  }
  if (IsStringContainAdjacentSpaces()) {
    return ATM::RegistrationStatus::kAdjacentSpaces;
  }
  if (IsStringContainOnlyDigits()) {
    return ATM::RegistrationStatus::kContainOnlyDigits;
  }
  if (IsStringEmpty()) {
    return ATM::RegistrationStatus::kEmptyString;
  }

  return ATM::RegistrationStatus::kCorrectLogin;
}

ATM::RegistrationStatus RegistrationInspector::InspectPasswordString(
    const std::string& password) {
  string_analyzer_.AnalyzeString(password);

  if (IsPasswordShort(password.length())) {
    return ATM::RegistrationStatus::kShortPassword;
  }
  if (IsPasswordLong(password.length())) {
    return ATM::RegistrationStatus::kLongPassword;
  }
  if (IsPasswordContainSpaces()) {
    return ATM::RegistrationStatus::kContainSpaceSymbol;
  }
  if (IsStringContainSpecialSymbols()) {
    return ATM::RegistrationStatus::kSpecialSymbols;
  }
  if (IsStringEmpty()) {
    return ATM::RegistrationStatus::kEmptyString;
  }

  return ATM::RegistrationStatus::kCorrectPassword;
}

bool RegistrationInspector::IsPasswordTooltipCorrect(
    int password_tooltip_length) const {
  return password_tooltip_length <
         RegistrationDataLengthStandard::MaxPasswordTooltipLength();
}

bool RegistrationInspector::IsLoginShort(int login_length) const {
  return login_length < RegistrationDataLengthStandard::MinLoginLength();
}

bool RegistrationInspector::IsLoginLong(int login_length) const {
  return login_length > RegistrationDataLengthStandard::MaxLoginLength();
}

bool RegistrationInspector::IsPasswordShort(int password_length) const {
  return password_length < RegistrationDataLengthStandard::PasswordLength();
}

bool RegistrationInspector::IsPasswordLong(int password_length) const {
  return password_length > RegistrationDataLengthStandard::PasswordLength();
}

bool RegistrationInspector::IsPasswordContainSpaces() const {
  return string_analyzer_.AmountOfSpaces() > 0;
}

bool RegistrationInspector::IsStringContainSpecialSymbols() const {
  return string_analyzer_.IsStringContainSpecialSymbols();
}

bool RegistrationInspector::IsStringBeginWithSpace() const {
  return string_analyzer_.IsStringBeginWithSpace();
}

bool RegistrationInspector::IsStringEndWithSpace() const {
  return string_analyzer_.IsStringEndWithSpace();
}

bool RegistrationInspector::IsStringContainAdjacentSpaces() const {
  return string_analyzer_.IsStringContainAdjacentSpaces();
}

bool RegistrationInspector::IsStringContainOnlyDigits() const {
  return string_analyzer_.IsStringContainOnlyDigits();
}

bool RegistrationInspector::IsStringEmpty() const {
  return string_analyzer_.IsStringEmpty();
}
