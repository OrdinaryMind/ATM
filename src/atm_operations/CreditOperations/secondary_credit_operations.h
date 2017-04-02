﻿#ifndef SECONDARY_CREDIT_OPERATIONS_H
#define SECONDARY_CREDIT_OPERATIONS_H

#include "credit_messenger.h"
#include "user_input.h"

class SecondaryCreditOperations {
 public:
  int GetAmountCreditByMode(const int maximal_sum_of_credit,
                            const int credit_mode) const;

  int GetAmountCreditMonths() const;

  double CalculateMonthlyPayment(const int sum_of_credit,
                                 const int amount_of_credit_months) const;

 private:
  int GetCreditSumFromUser(int maximal_sum_of_credit) const;

  static const int kInvalidValue = -1;
  static const int kUserCredit = 1;
  static const int kRatePerYear = 14;
  static const int kFullRate = 100;
  static const int kOneYear = 12;
  static const int kMaximalCreditTerm = 61;
  static bool IsMonthCorrect(int months);

  UserInput user_input_;
  CreditMessanger credit_messenger_;
};

#endif  // SECONDARY_CREDIT_OPERATIONS_H
