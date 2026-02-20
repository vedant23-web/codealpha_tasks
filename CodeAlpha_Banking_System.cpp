/*Banking System 
● Design classes for Customer, Account and Transaction with necessary attributes. 
● Implement functions to create and manage customers and accounts. 
● Include features for deposits, withdrawals and fund transfers. 
● Store transaction history and allow users to view recent transactions. 
● Display account information like balance and transaction details to customers. */

#include <iostream>
#include <vector>
#include <string>

class Transaction {
public:
    std::string type;
    double amount;

    Transaction(std::string t, double a) {
        type = t;
        amount = a;
    }

    void displayTransaction() {
        std::cout << "Type: " << type << " | Amount: " << amount << std::endl;
    }
};

class Account {
private:
    int accountNumber;
    double balance;
    std::vector<Transaction> transactions;

public:
    Account(int accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        std::cout << "Deposit Successful!\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient Balance!\n";
            return;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));
        std::cout << "Withdrawal Successful!\n";
    }

    void transfer(Account &receiver, double amount) {
        if (amount > balance) {
            std::cout << "Insufficient Balance for Transfer!\n";
            return;
        }
        balance -= amount;
        receiver.balance += amount;

        transactions.push_back(Transaction("Transfer Sent", amount));
        receiver.transactions.push_back(Transaction("Transfer Received", amount));

        std::cout << "Transfer Successful!\n";
    }

    void showTransactions() {
        std::cout << "\n--- Transaction History ---\n";
        for (auto &t : transactions) {
            t.displayTransaction();
        }
    }

    void displayAccount() {
        std::cout << "\nAccount Number: " << accountNumber;
        std::cout << "\nBalance: " << balance << std::endl;
    }
};

class Customer {
private:
    int customerID;
    std::string name;
    Account account;

public:
    Customer(int id, std::string n, int accNo, double balance)
        : customerID(id), name(n), account(accNo, balance) {}

    int getCustomerID() {
        return customerID;
    }

    Account& getAccount() {
        return account;
    }

    void displayCustomer() {
        std::cout << "\nCustomer ID: " << customerID;
        std::cout << "\nCustomer Name: " << name << std::endl;
        account.displayAccount();
    }
};

int main() {
    std::vector<Customer> customers;
    int choice;

    do {
        std::cout << "\n====== BANKING SYSTEM ======\n";
        std::cout << "1. Create Customer & Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Transfer Funds\n";
        std::cout << "5. View Account Details\n";
        std::cout << "6. View Transaction History\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int id, accNo;
            std::string name;
            double balance;

            std::cout << "Enter Customer ID: ";
            std::cin >> id;
            std::cout << "Enter Name: ";
            std::cin >> name;
            std::cout << "Enter Account Number: ";
            std::cin >> accNo;
            std::cout << "Enter Initial Balance: ";
            std::cin >> balance;

            customers.push_back(Customer(id, name, accNo, balance));
            std::cout << "Customer & Account Created Successfully!\n";
        }

        else if (choice >= 2 && choice <= 6) {
            int id;
            std::cout << "Enter Customer ID: ";
            std::cin >> id;

            bool found = false;

            for (auto &cust : customers) {
                if (cust.getCustomerID() == id) {
                    found = true;

                    if (choice == 2) {
                        double amt;
                        std::cout << "Enter amount to deposit: ";
                        std::cin >> amt;
                        cust.getAccount().deposit(amt);
                    }

                    else if (choice == 3) {
                        double amt;
                        std::cout << "Enter amount to withdraw: ";
                        std::cin >> amt;
                        cust.getAccount().withdraw(amt);
                    }

                    else if (choice == 4) {
                        int receiverID;
                        double amt;

                        std::cout << "Enter Receiver Customer ID: ";
                        std::cin >> receiverID;
                        std::cout << "Enter amount to transfer: ";
                        std::cin >> amt;

                        for (auto &receiver : customers) {
                            if (receiver.getCustomerID() == receiverID) {
                                cust.getAccount().transfer(receiver.getAccount(), amt);
                                break;
                            }
                        }
                    }

                    else if (choice == 5) {
                        cust.displayCustomer();
                    }

                    else if (choice == 6) {
                        cust.getAccount().showTransactions();
                    }

                    break;
                }
            }

            if (!found) {
                std::cout << "Customer Not Found!\n";
            }
        }

    } while (choice != 7);

    std::cout << "Thank you for using Banking System!\n";
    return 0;
}

