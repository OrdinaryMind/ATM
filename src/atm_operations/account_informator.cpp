#include "account_informator.h"

void AccountInformator::DisplayAccountInformation(AtmUser *atm_user) {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();
  screen_.DisplayLogin(atm_user->GetLogin());
  screen_.DisplayPassword(atm_user->GetPassword());
  screen_.DisplayCash(atm_user->GetCash());
  screen_.DisplayCredit(atm_user->GetCredit());
  screen_.DisplayPayment(atm_user->GetMonthlyPayment());
  screen_.DisplayCreditMonth(atm_user->GetAmountOfCreditMonth());
}
