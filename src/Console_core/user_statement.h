#ifndef USER_STATEMENT_H
#define USER_STATEMENT_H

#include <string>

#include "cash_operator.h"
#include "console_editor.h"
#include "statement_messenger.h"
#include "user_input.h"

class UserStatement {
  using string = std::string;

 public:
  void ShowStatement(CashOperator &cash_operator);

 private:
  static const int kNull = 0;
  static const int kSizeOfCheckField = 12;

  string GetSpaces(int convertation_cash_to_space) const;
  int NumberOfDigits(int value) const;

  UserInput user_input_;
  StatementMessenger statement_messenger_;
  ConsoleEditor console_editor_;
};

#endif  // USER_STATEMENT_H