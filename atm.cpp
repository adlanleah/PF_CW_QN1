#include <iostream>
#include <string>
#include <map>

using namespace std;

//Function for New Account
void createAccount(map<string, string>& accounts){
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;
    accounts[userId] = password;
    cout << "Thank you! Your account has been created!" << endl;
}

//Function for an existing account
bool login(map<string, string>& accounts, string userId, string password){
    if(accounts.find(userId) != accounts.end() && accounts[userId] ==password){
        return true;
    }
    return false;
}

//Function to display the main Menu
void displayMenu(){
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
}

//Function for handling user input
void handleUserInput(map<string, string>& accounts, string userId){
    char choice;
    double balance = 0.0;
    while (true){
        displayMenu();
        cin >> choice;
        switch (choice)
        {case 'd':{
            double amount;
            cout <<"Amount of deposit: $";
            cin >> amount;
            balance =+ amount;
            break;
        }
        case 'w':{
            double amount;
            cout <<"Amount of withdrawal: $";
            cin >> amount;
            if(amount > balance){
                cout <<"Insufficient balance!" << endl;
            }else{
                balance -= amount;
            }
            break;
        }
        case 'r':
            cout <<"Your balance is  $" << balance << endl;
             break;
        case 'q':
            return;
        default:
            cout <<"Invalid choice. Please try again." << endl;
        }
    }
}

int main(){
    map<string, string> accounts;
    while (true){
        cout <<"Hi! Welcome to ATM Machiine!" << endl;
        cout <<"Please select an option from the menu below:" << endl;
        cout <<"l -> Login" << endl;
        cout <<"c -> Create New Account" << endl;
        cout <<"q -> Quit" << endl;
        char choice;
        cin >> choice;
        switch (choice){
            case 'l':{
                string userId, password;
                cout <<"Please enter your user id: ";
                cin >> userId;
                cout <<"Please enter your password: ";
                cin >> password;
                if (login(accounts, userId, password)){
                    cout <<"Access Granted!" << endl;
                    handleUserInput(accounts, userId);
                }else{
                    cout <<"*** LOGIN FAILED! ***" << endl;
                }
                break;
            }
            case 'c':
                createAccount(accounts);
                break;
            case 'q':
                return  0;
            default:
                cout <<"Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}