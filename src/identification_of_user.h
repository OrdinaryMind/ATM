#ifndef IDENTIFICATION_OF_USER_H
#define IDENTIFICATION_OF_USER_H

#include <iostream>
#include <string>
#include "account_info.h"
#include "user_messanger.h"

using std::cin;
using std::cout;

class IdentificationOfUser {
  using string = std::string;

 public:
  IdentificationOfUser();
  IdentificationOfUser(const string &login);

  void GetLogin();
  void GetPassword();

  bool IsNormalLogin();
  bool IsNormalPass();

  void NoticeAboutIncorrectPassword();
  void NoticeAboutIncorrectLogin();
  void NoticeAboutSuccessfulRegistration();

  AccountInfo account_info_;

 private:
  UserMessanger user_messanger_;
};

#endif  // IDENTIFICATION_OF_USER_H