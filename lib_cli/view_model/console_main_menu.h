﻿#ifndef CONSOLE_MAIN_MENU_H
#define CONSOLE_MAIN_MENU_H

#include <memory>

#include <user_input_handler.h>

class ConsoleMainMenu {
 public:
  void RunMainMenu();

  bool UserWantAccountSubMenu();

 private:
  enum MenuOperations {
    kAccountInfo,
    kRefill,
    kCreditApplication,
    kWithdrawal,
    kStatement,
    kLogOut,
    kQuit
  };

  void ProcessMenuUserInput();

  bool IsUserInputContainSubMenu(int user_input);

  std::unique_ptr<UserInputHandler> user_input_handler_;

  bool user_want_account_sub_menu_;
};

#endif  // CONSOLE_MAIN_MENU_H
