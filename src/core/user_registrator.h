#ifndef USER_REGISTRATOR_H
#define USER_REGISTRATOR_H

#include "user_data/atm_user.h"
#include "messengers/identification_messenger.h"
#include "messengers/registration_messenger.h"
#include "core/user_identification_data_provider.h"

#include "messengers/notice_messenger.h"

class UserRegistrator {
 public:
  void RegisterUser(AtmUser &atm_user);

  bool IsCorrectRegistration() const;

 private:
  static void AssignInitialValues(AtmUser &atm_user);

  void EnterLogin(AtmUser &atm_user);
  void EnterPassword(AtmUser &atm_user);
  void set_is_correct_registration(bool is_correct_registration);


  bool correct_registration_ = false;

  RegistrationMessenger registation_messenger_;
  UserIdentificationDataProvider provider_;
  IdentificationMessenger identification_messenger_;

  NoticeMessenger notice_messenger_;

};

#endif  // USER_REGISTRATOR_H