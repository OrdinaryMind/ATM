﻿#ifndef IDENTIFICATION_DATA_H
#define IDENTIFICATION_DATA_H

#include <string>

class IdentificationData {
 public:
  IdentificationData();
  IdentificationData(const std::string& login, const std::string& password);

  void SetLogin(const std::string& login);
  void SetPassword(const std::string& password);

 private:
  std::string login_;
  std::string password_;
};

#endif  // IDENTIFICATION_DATA_H
