#ifndef USER_REGISTRATOR_H
#define USER_REGISTRATOR_H

#include "cash_operator.h"
#include "notifier.h"
#include "registration_messenger.h"
#include "user_identifier.h"

class UserRegistrator {
 public:
  void RegisterUser(CashOperator &cash_operator,
                    UserIdentifier &user_identifier);

  bool IsNormalRegistration();

 private:
  void EnterLogin(UserIdentifier &user_identifier);
  bool IsNormalLogin(UserIdentifier &user_identifier);

  void EnterPassword(UserIdentifier &user_identifier);
  bool IsNormalPassword(UserIdentifier &user_identifier);

  Notifier notifier_;
  RegistrationMessenger registation_messenger_;

  bool correct_registration_;
};

#endif  // USER_REGISTRATOR_H