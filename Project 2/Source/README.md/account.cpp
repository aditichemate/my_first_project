#include <iostream>
using namespace std;

int main() {
    int sticks = 21;
    int user, computer;

    cout << "MATCHSTICK GAME\n";

    while (sticks > 0) {
        cout << "\nRemaining sticks: " << sticks;
        cout << "\nPick 1 to 4 sticks: ";
        cin >> user;

        if (user < 1 || user > 4 || user > sticks) {
            cout << "Invalid choice!\n";
            continue;
        }

        sticks -= user;

        if (sticks == 0) {
            cout << "You picked the last stick. You lose!\n";
            break;
        }

        computer = 5 - user;

        if (computer > sticks)
            computer = sticks;

        cout << "Computer picks "
             << computer << " sticks.\n";

        sticks -= computer;

        if (sticks == 0) {
            cout << "Computer picked the last stick. You win!\n";
            break;
        }
    }

    return 0;
}
