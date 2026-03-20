#include <iostream>

#include "BankAccount.h"

int main() {
    demo::BankAccount checking("Avery", 5000);

    checking.deposit(2500);
    checking.withdraw(1200);

    std::cout << "Demo account state\n";
    std::cout << checking.summary() << '\n';

    return 0;
}
