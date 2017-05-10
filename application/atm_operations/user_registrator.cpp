﻿#include <user_registrator.h>

#include <identification_messenger.h>
#include <registration_messenger.h>

void UserRegistrator::RegisterUser(AtmUser& atm_user) {
  set_is_correct_registration(false);

  RegistrationMessenger::ShowRegistrationScreen();

  EnterLogin(atm_user);
  if (atm_user.IsNormalLogin()) {
    EnterPassword(atm_user);
    if (atm_user.IsNormalPass()) {
      notice_messenger_.ShowAcceptableMessageFrame();
      set_is_correct_registration(true);
    } else {
      notice_messenger_.ShowIncorrectFormatPassword();
    }
  } else {
    notice_messenger_.ShowIncorrectLoginFrame();
  }
}

bool UserRegistrator::IsCorrectRegistration() const {
  return correct_registration_;
}

void UserRegistrator::EnterLogin(AtmUser& atm_user) {
  IdentificationMessenger::ShowInitialLoginText();
  atm_user.SetLogin(provider_.GetLoginFromUser());
}

void UserRegistrator::EnterPassword(AtmUser& atm_user) {
  IdentificationMessenger::ShowInitialPasswordText();
  atm_user.SetPassword(provider_.GetPasswordFromUser());
}

void UserRegistrator::set_is_correct_registration(bool correct_registration) {
  correct_registration_ = correct_registration;
}