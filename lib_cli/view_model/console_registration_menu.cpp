﻿#include <console_registration_menu.h>

#include <menu_input_handler.h>
#include <registration_messenger.h>
#include <user_input_handler.h>

ConsoleRegistrationMenu::~ConsoleRegistrationMenu() {}

void ConsoleRegistrationMenu::RunRegistrationMenu() {
  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();
  ProcessMenuUserInput();
}

void ConsoleRegistrationMenu::ReceiveRegistrationDataFromUser() {
  input_handler_ = std::unique_ptr<UserInputHandler>(new UserInputHandler);
  RegistrationMessenger::ClearScreen();
  RegistrationMessenger::ShowRegistrationLogo();
  GetLoginStringFromUser();
  GetPasswordStringFromUser();
}

std::string ConsoleRegistrationMenu::LoginString() const { return login_; }

std::string ConsoleRegistrationMenu::PasswordString() const {
  return password_;
}

bool ConsoleRegistrationMenu::IsUserWantToRegistrate() const {
  return user_want_to_registrate_;
}

bool ConsoleRegistrationMenu::IsUserWantToExitProgram() const {
  return user_want_to_exit_;
}

void ConsoleRegistrationMenu::ProcessMenuUserInput() {
  input_handler_ = std::unique_ptr<UserInputHandler>(new MenuInputHandler);
  for (;;) {
    ResetManipulationFlags();
    int user_input = input_handler_->GetDigitInputFromUser();
    if (user_input == kRegistration) {
      user_want_to_registrate_ = true;
      break;
    } else if (user_input == kInitialMenu) {
      break;
    } else if (user_input == kSymbolQuit || user_input == kDigitQuit) {
      user_want_to_exit_ = true;
      break;
    } else {
      RegistrationMessenger::ShowIncorrectInput();
    }
  }
}

void ConsoleRegistrationMenu::ResetManipulationFlags() {
  user_want_to_registrate_ = false;
  user_want_to_exit_ = false;
}

void ConsoleRegistrationMenu::GetLoginStringFromUser() {
  RegistrationMessenger::ShowLoginTitle();
  login_ = input_handler_->GetStringInputFromUser();
}

void ConsoleRegistrationMenu::GetPasswordStringFromUser() {
  RegistrationMessenger::ShowPasswordTitle();
  password_ = input_handler_->GetStringInputFromUser();
}