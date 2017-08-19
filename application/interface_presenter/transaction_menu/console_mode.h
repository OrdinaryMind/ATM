﻿#ifndef CONSOLE_MODE_H
#define CONSOLE_MODE_H

#include <memory>

#include "atm_user.h"
//#include "demo_menu.h"
#include "registrator.h"

#include "account_informator.h"
#include "refill.h"
#include "user_statement.h"
#include "withdrawal.h"

#include "cli_credit_department.h"

// ================ New Code ================

#include <console_initial_presenter.h>
#include <menu_input_handler.h>
#include <user_input_handler.h>

class AtmInteractor;
class UserInputHandler;
class MenuInputHandler;

class ConsoleMode {
 public:
  ConsoleMode();
  ~ConsoleMode();

  void RunATM();

 private:
  enum InitialProgramSection { kQuit, kDemo, kRegistration };
  enum ResultOfUserInput { kMainMenu = 1, kSubMenuQuit };
  enum AtmOperations {
    kAccount = 1,
    kRefill,
    kCredit,
    kWidthdrawal,
    kStatement,
    kExitProgram,
  };

  bool IsCorrectRegistration() const;
  void EndProgram() const;
  void ShowIncorrectRegistration() const;

  void RunProgram();
  void RunSectionBasedOn(int user_choice);
  void RunDemoMenu();
  void RegistrateUser();
  void MainProgramMenu();
  void ExecuteOperation(int user_choice);
  void SuggestToQuit();

  //  DemoMenu demo_mode_;
  AtmUser user_;
  Registrator registrator_;
  AccountInformator account_informator_;
  Refill refill_;
  Withdrawal withdrawal_;
  UserStatement statement_;
  CLICreditDepartment credit_department_;

  bool user_want_to_exit_ = true;

  // ============= New Code ==================
  std::unique_ptr<AtmInteractor> atm_;

  ConsoleInitialPresenter initial_menu_;

  UserInputHandler user_input_;
  MenuInputHandler quit_menu_handler_;
};

#endif  // CONSOLE_MODE_H
