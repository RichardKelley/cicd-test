#include <iostream>
#include <string>

#include "BankAccount.h"

namespace {

int failures = 0;

void expect_true(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "FAIL: " << message << '\n';
        ++failures;
    }
}

void expect_equal(int actual, int expected, const std::string& message) {
    if (actual != expected) {
        std::cerr << "FAIL: " << message
                  << " (expected " << expected
                  << ", got " << actual << ")\n";
        ++failures;
    }
}

void expect_equal(const std::string& actual,
                  const std::string& expected,
                  const std::string& message) {
    if (actual != expected) {
        std::cerr << "FAIL: " << message
                  << " (expected \"" << expected
                  << "\", got \"" << actual << "\")\n";
        ++failures;
    }
}

void test_opening_balance() {
    demo::BankAccount account("Sam", 1500);

    expect_equal(account.owner(), "Sam", "owner should match constructor input");
    expect_equal(account.balance_cents(), 1500, "opening balance should be preserved");
    expect_equal(account.transaction_count(), 0, "new account should have zero transactions");
}

void test_invalid_opening_balance_becomes_zero() {
    demo::BankAccount account("Riley", -500);

    expect_equal(account.balance_cents(), 0, "negative opening balance should clamp to zero");
}

void test_deposit() {
    demo::BankAccount account("Alex", 1000);

    expect_true(account.deposit(250), "deposit should succeed for a positive amount");
    expect_equal(account.balance_cents(), 1250, "deposit should increase the balance");
    expect_equal(account.transaction_count(), 1, "deposit should count as a transaction");
}

void test_invalid_deposit() {
    demo::BankAccount account("Jordan", 1000);

    expect_true(!account.deposit(0), "zero deposit should fail");
    expect_equal(account.balance_cents(), 1000, "failed deposit should not change balance");
    expect_equal(account.transaction_count(), 0, "failed deposit should not count as a transaction");
}

void test_withdraw() {
    demo::BankAccount account("Taylor", 2000);

    expect_true(account.withdraw(750), "withdraw should succeed when funds are available");
    expect_equal(account.balance_cents(), 1250, "withdraw should reduce the balance");
    expect_equal(account.transaction_count(), 1, "withdraw should count as a transaction");
}

void test_overdraft_is_rejected() {
    demo::BankAccount account("Morgan", 2000);

    expect_true(!account.withdraw(2500), "overdraft should fail");
    expect_equal(account.balance_cents(), 2000, "failed withdraw should not change balance");
    expect_equal(account.transaction_count(), 0, "failed withdraw should not count as a transaction");
}

void test_summary() {
    demo::BankAccount account("Casey", 900);
    account.deposit(25);

    expect_equal(
        account.summary(),
        "Owner: Casey, balance: $9.25, transactions: 1",
        "summary should format dollars, cents, and transaction count");
}

}  // namespace

int main() {
    test_opening_balance();
    test_invalid_opening_balance_becomes_zero();
    test_deposit();
    test_invalid_deposit();
    test_withdraw();
    test_overdraft_is_rejected();
    test_summary();

    if (failures == 0) {
        std::cout << "All tests passed.\n";
        return 0;
    }

    std::cerr << failures << " test(s) failed.\n";
    return 1;
}
