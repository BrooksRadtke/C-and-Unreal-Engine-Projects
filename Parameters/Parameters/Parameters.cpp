#include <iostream>
#include "Transaction.h"
using std::cout;
using std::cin;

void TryToChangeTransaction(Transaction t)
{
    t.DoubleAmount();
}

void ChangeTransaction(Transaction& t)
{
    t.DoubleAmount();
}

int main()
{
    Transaction Deposit(50, "Deposit");
    cout << "Original: " << Deposit.Report() << '\n';
    TryToChangeTransaction(Deposit);
    cout << "After pass by value: " << Deposit.Report() << '\n';
    ChangeTransaction(Deposit);
    cout << "After pass by reference: " << Deposit.Report() << '\n';

    return 0;
}