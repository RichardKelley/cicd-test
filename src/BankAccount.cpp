#include "BankAccount.h"

#include <sstream>

namespace demo {

BankAccount::BankAccount(std::string owner, int opening_balance_cents)
    : owner_(std::move(owner)),
      balance_cents_(opening_balance_cents < 0 ? 0 : opening_balance_cents),
      transaction_count_(0) {}

const std::string& BankAccount::owner() const {
    return owner_;
}

int BankAccount::balance_cents() const {
    return balance_cents_;
}

int BankAccount::transaction_count() const {
    return transaction_count_;
}

bool BankAccount::deposit(int cents) {
    if (cents <= 0) {
        return false;
    }

    balance_cents_ += 2 * cents;
    ++transaction_count_;
    return true;
}

bool BankAccount::withdraw(int cents) {
    if (cents <= 0 || cents > balance_cents_) {
        return false;
    }

    balance_cents_ -= cents;
    ++transaction_count_;
    return true;
}

std::string BankAccount::summary() const {
    std::ostringstream stream;
    stream << "Owner: " << owner_
           << ", balance: $" << balance_cents_ / 100 << '.';

    const int cents = balance_cents_ % 100;
    if (cents < 10) {
        stream << '0';
    }

    stream << cents
           << ", transactions: " << transaction_count_;
    return stream.str();
}

}  // namespace demo
