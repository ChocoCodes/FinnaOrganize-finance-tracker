#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Store User Information
struct User {
    char name[100];
    int age;
    string school;
};

// Store Transaction Details
struct Transactions {
    string date;
    string description;
    string type;
    float amount;
};

// Create User Profile
int createProfile(vector<User>& user)
{
    User newUser;
    int subchoice;

    do{
        cout << "Please enter valid details in creating your profile.\n";
        cout << "[1.] Continue \n";
        cout << "[2.] Back \n";
        cout << "Enter choice: ";
        cin >> subchoice;
        cin.ignore();

        switch (subchoice){
            case 1:
                cout << "Enter Full Name: ";
                cin.get (newUser.name, 100);
                cout << "Enter Age: ";
                cin >> newUser.age;
                cout << "Enter School: ";
                cin >> newUser.school;
                cout << "Welcome, " << newUser.name << "! \n";
                cin.ignore();
                user.push_back(newUser);
                return 0; 
            case 2:
                return 0; 
            default:
                cout << "Invalid Input. Try Again! \n"; //Serves as an error message when the user input a number that is not declared
                break;
        } 
    } while (subchoice != 2);
    return 0;
}

int addTransactions(vector<Transactions>& transactions)
{
    Transactions newTransaction;
    int subchoice2;
    do{
        cout << "[1.] Continue \n";
        cout << "[2.] Back \n";
        cout << "Enter choice: ";
        cin >> subchoice2;
        cin.ignore();

        switch (subchoice2)
        {
            case 1:
                cout << "Enter date of transaction: ";
                getline(cin, newTransaction.date);
                cout << "Enter transaction description: ";
                getline(cin, newTransaction.description);
                cout << "Enter transaction amount: ";
                cin >> newTransaction.amount;
                cin.ignore();
                newTransaction.type = "Unidentified";
                transactions.push_back(newTransaction);

                // Check if the inputs are correct
                while(cin.fail() || newTransaction.amount < 0) {
                    cout << "Invalid. Enter a Valid Number. \n";
                    cin >> newTransaction.amount;
                    cin.ignore();
                }
                return 0;
            case 2:
            return 0;
            default:
                cout << "Invalid Input. Try Again! \n"; 
            break;
        }
    } while (subchoice2 != 2);
    return 0;
}

// Search for important keywords in the transaction description and store them accordingly
string getType(const string& description)
{
    if(description.find("food") != string::npos || description.find("ingredients") != string::npos || 
    description.find("restaurant") != string::npos || description.find("lunch") != string::npos || 
    description.find("breakfast") != string::npos || description.find("dinner") != string::npos || 
    description.find("beverage") != string::npos || description.find("take out") != string::npos || 
    description.find("delivery") != string::npos || description.find("dine in") != string::npos){
        return "Food";
    } else if (description.find("fare") != string::npos || description.find("gas") != string::npos || 
    description.find("jeep") != string::npos || description.find("taxi") != string::npos || 
    description.find("car") != string::npos || description.find("commute") != string::npos || description.find("tricycle") != string::npos || 
    description.find("pedicab") != string::npos) {
        return "Transportation";
    } else if (description.find("electricity") != string::npos || 
    description.find("rent") != string::npos || description.find("water") != string::npos ||
    description.find("internet") != string::npos || description.find("maintenance") != string::npos) {
        return "Utilities";
    } else if (description.find("savings") != string::npos || description.find("crypto") != string::npos|| 
    description.find("deposits") != string::npos || description.find("life insurance") != string::npos) {
        return "Investments";
    }else {
        return "Miscellaneous";
    }
}

//Sort Transactions
void classify(vector<Transactions>& transactions)
{
    for (auto& Transactions : transactions) {
       Transactions.type = getType(Transactions.description);
    }
}

// Show All Transactions
void displayUserTransactions(const vector<User>& user, const vector<Transactions>& transactions)
{
    for (const auto& User : user) {
        cout << "Profile: \n Name: " << User.name << "\n Age: " << User.age << "\n School: " << User.school << "\n";  
        } 
    cout << "==============================================================" << endl;
    cout << "Transactions: " << "\n";
     cout << "Date  \t Amount  \t Description  \t Type  \n ";
    for (const auto& Transactions : transactions){
         cout << Transactions.date << "\t" << Transactions.amount << "\t" << Transactions.description << "\t" << Transactions.type << "\n";

        }
}

int computeBalance(const vector<Transactions>& transactions)
{                                          
    float balance, allowance, remaining;

    int subchoice3;
    do {
        cout << "[1.] Continue \n";
        cout << "[2.] Back \n";
        cout << "Enter choice: ";
        cin >> subchoice3;
        cin.ignore();

        switch (subchoice3){
            case 1:
                cout << "Enter your monthly allowance: ";
                cin >> allowance;

                for (const auto& Transactions : transactions) {
                    balance += Transactions.amount;
                }
                
                remaining = allowance - balance;
                if (remaining > allowance){
                    cout << "Remaining balance: " << remaining << "\n";
                    cout << "You have exceed your monthly allowance!";
                } else if (remaining == allowance) {
                    cout << "Remaining balance: " << remaining << "\n";
                    cout << "You have no remaining balance! \n";
                } else {
                    cout << "Remaining balance: " << remaining << "\n";
                }
            return 0;
            case 2:
            return 0;
            default:
                cout << "Invalid Input. Try Again! \n"; 
            break;
        }
    }while (subchoice3 != 2);
    return 0;
}

int main()
{

    vector<User> user;
    vector<Transactions> transactions;
    int choice;

    cout << "\t\t==============================================================\t\t" << endl;
    cout << "\t\t   WELCOME TO FINNA ORGANIZE! YOUR BUDGET TRACKING PROGRAM!   \t\t" << endl;
    cout << "\t\t==============================================================\t\t" << endl;

        do {
            cout << "Choose an option:\n";
            cout << "[1.] Create Profile\n";
            cout << "[2.] Add Transactions\n";
            cout << "[3.] Classify Transactions\n";
            cout << "[4.] Display Profile and Transactions\n";
            cout << "[5.] Compute Balance\n";
            cout << "[6.] Quit\n";

            cin >> choice;

            if (choice == 1) {
                createProfile(user);
            }else if (choice == 2) {
                addTransactions(transactions);
            }else if (choice == 3) {
                classify(transactions);
            }else if (choice == 4) {
                displayUserTransactions(user, transactions);
            }else if (choice == 5) {
                computeBalance(transactions);
            }else if(choice == 6) {
                break;
            }else {
                cout << "Invalid Choice! Try Again";
            }
        } while (choice != 6);
            
}