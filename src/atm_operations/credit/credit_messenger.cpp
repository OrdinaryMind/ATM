#include "credit_messenger.h"

void CreditMessanger::RefusToGrantAnotherCredit() const {
  utility_.WriteTextWithDelay(
      "\n #Sorry, but you have already a "
      "loan in our bank.\n"
      " #You can't get a second loan, "
      "while your first loan "
      "not complete.\n");
}

void CreditMessanger::ShowNotifyAboutCredit() const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# You can get a loan in our bank if your\n"
      "  balance more than $1000.\n"
      "# We draw your attention to the fact that\n"
      "  our bank may refuse you in getting a loan\n"
      "  without giving any reason.\n"
      "# Nowadays, the all loans are set on 14% per year\n"
      "# The loan depend from sum on account at the moment.\n");
  std::cout << "\n\t*********************\n"
               "\t*   Continue?       *\n"
               "\t*                   *\n"
               "\t*   1. Yes          *\n"
               "\t*   2. No           *\n"
               "\t*                   *\n"
               "\t*********************\n"
               "\tEnter: ";
}

void CreditMessanger::ShowCreditConditions(int maximal_sum_of_credit) const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# Your balance more than 1000$. You can afford to take the\n"
      "# credit in our bank. The maximum amount for you is:");
  utility_.Sleep(kHalfASecond);
  std::cout << "----------------------------------------------------------\n";
  std::cout << " \t\t\t $" << maximal_sum_of_credit << "\n";
  std::cout << "----------------------------------------------------------\n";
  utility_.Sleep(kHalfASecond);
  utility_.WriteTextWithDelay(
      "\n# Do you prefer get all sum or you want to change the sum of "
      "loan?\n\n"
      "# 1. Get all sum\n"
      "# 2. Change the sum of loan\n"
      "# 3. Exit credit menu\n");
  std::cout << "# Enter: ";
}

void CreditMessanger::ShowInfoAboutCredit(
    const CreditMessanger::string &user_login, int max_sum) const {
  std::cout << "\t             Consumer credit\n"
               "\t* Profile: "
            << user_login << "\n\t* Sum $: " << max_sum
            << "\n\t* Persent per year: 14%\n\n ";
}

CreditMessanger::string CreditMessanger::SuggestToConfirmACredit() const {
  string menu_text(
      "\n\t# Do you confirm the loan?\n"
      "\t1. Yes, I confirm.\n"
      "\t2. Repeal a credit.\n"
      "\t Enter: ");
  return menu_text;
}

void CreditMessanger::ShowCreditTitle(const CreditMessanger::string &user_login,
                                      int sum_of_credit) const {
  utility_.ClearScreen();
  std::cout << "\t\tConsumer Credit\n\n";
  utility_.Sleep(kHalfASecond);
  std::cout << "Profile: " << user_login << "\n";
  utility_.Sleep(kHalfASecond);
  std::cout << "Sum $: " << sum_of_credit << "\n";
  utility_.Sleep(kHalfASecond);
  std::cout << "Persent per year: 14%\n\n";
  utility_.Sleep(kHalfASecond);
}

void CreditMessanger::ShowEnrollACredit() const {
  utility_.WriteTextWithDelay(
      "\n# The loan was successfully transferred on your account.\n"
      "# You might cash your credit in our nearest bank.");
}

void CreditMessanger::ShowRepealACreadit() const {
  utility_.WriteTextWithDelay("\n\t# Credit is repealed...\n");
}

void CreditMessanger::ShowRefuseACredit(int sum_of_cash) const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("# We checked your balance.\n");
  utility_.Sleep(kHalfASecond);
  std::cout << "# Available cash = $" << sum_of_cash << "\n";
  utility_.WriteTextWithDelay(
      "# Sorry, for getting a loan your balance must be "
      "$1000 or more.\n");
  utility_.Sleep(kHalfASecond);
}

void CreditMessanger::ShowTableOfCredit(const double pay_per_month,
                                        const double amount_of_months) const {
  double all_payment = 0.0;
  for (int i = kNull; i < amount_of_months; ++i) {
    std::cout << "\t* Payment month: " << i + 1 << "\tPayment sum: ";
    std::cout << pay_per_month << " $\n";
    utility_.Sleep(kSleep);
    all_payment += pay_per_month;
  }
  std::cout << "\t\t\tTotal: " << all_payment << " $\n\n";
}

void CreditMessanger::ShowAmountOfMonthToPayACredit() const {
  std::cout << "The number of months to repay the loan: ";
}

void CreditMessanger::ShowResultOfUserChoice(int decision_of_user) const {
  if (decision_of_user == 1) {
    ShowEnrollACredit();
  } else {
    ShowRepealACreadit();
  }
}

void CreditMessanger::ShowIncorrectCashInformation(
    const CashOperator &cash_operator) const {
  utility_.WriteSymbolsNTimes('-', 30);
  std::cout << "Balance: " << cash_operator.GetCash();
  utility_.WriteSymbolsNTimes('-', 30);
}

CreditMessanger::string CreditMessanger::ShowEnter() const {
  return "\t# Enter: ";
}
