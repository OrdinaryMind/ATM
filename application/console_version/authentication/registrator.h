﻿#ifndef REGISTRATOR_H
#define REGISTRATOR_H

#include <string>

#include <authentication_handler.h>
#include <menu_input_handler.h>
#include <user_input_handler.h>

class Registrator {
 public:
  bool IsRegistrationStatusOk() const;

  std::string GetUserLogin() const;

  void RunRegistrationMenu();

 private:
  enum RegistrationMenuPoints { kSymbolQuit, kStartRegistration, kDigitQuit };

  void SetRegistrationStatus(bool is_correct_registration);
  void ConfirmRegistration();
  void RunRegistrationProcedure();
  void GetLoginStringFromUser();
  void GetPasswordStringFromUser();

  UserInputHandler user_input_;
  MenuInputHandler menu_input_;
  AuthenticationHandler authenticaton_handler_;

  std::string login_ = "user";
  std::string password_ = "password";

  bool is_registration_status_ok = false;
};

#endif  // REGISTRATOR_H