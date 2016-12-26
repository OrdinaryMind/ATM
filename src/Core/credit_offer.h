#ifndef CREDIT_OFFER_H
#define CREDIT_OFFER_H

#include "atm_user.h"
#include "credit_messenger.h"
#include "secondary_credit_operations.h"

class CreditOffer {
 public:
  void SuggestACredit(AtmUser &atm_user, const std::string &user_login,
                      int sum_of_credit, int amount_of_months) const;

 private:
  enum CreditSolution { kEnroll = 1, kRepeal };

  void EnrollCredit(AtmUser &atm_user, int sum_of_credit,
                         double pay_per_month) const;
  void RepealCredit(AtmUser &atm_user) const;

  CreditMessanger credit_messenger_;
  SecondaryCreditOperations secondary_credit_operation_;
  UserInput user_input_;
  NoticeMessenger notice_messenger_;
};

#endif  // CREDIT_OFFER_H