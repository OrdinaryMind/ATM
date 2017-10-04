﻿#ifndef USER_REGISTRATOR_H
#define USER_REGISTRATOR_H

#include <string>

class AtmUser;

class UserRegistrator {
 public:
  static void RegisterUser(AtmUser* user,
                           const std::string& login,
                           const std::string& password,
                           const std::string& password_tooltip);

 private:
  static void AssignLogin(AtmUser* user, const std::string& login);
  static void AssignPassword(AtmUser* user, const std::string& password);
  static void AssignPasswordTooltip(AtmUser* user,
                                    const std::string& password_tooltip);
};

#endif  // USER_REGISTRATOR_H
