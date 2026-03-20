#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

namespace demo {

class BankAccount {
public:
    BankAccount(std::string owner, int opening_balance_cents = 0);

    const std::string& owner() const;
    int balance_cents() const;
    int transaction_count() const;

    bool deposit(int cents);
    bool withdraw(int cents);
    std::string summary() const;

private:
    std::string owner_;
    int balance_cents_;
    int transaction_count_;
};

}  // namespace demo

#endif
