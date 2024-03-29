﻿#include <iostream>
#include <ctime>
#include <string>
using namespace std;

string Bagels(int n, int m) {
    string s = to_string(n);
    string st = to_string(m);
    string ans;
    int y = 0;
    if (s.compare(st) == 0) {
        ans += "You got it!";
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (s[i] == st[j] && i != j) {
                    ans += "Pico ";
                    break;
                }
                if (s[i] == st[j] && i == j) {
                    ans += "Fermi ";
                    break;
                }
                if (s[i] != st[j] && i == j) {
                    y++;
                }
            }
            if (y == 3) {
                ans += "Bagels ";
            }
        }
        y = 0;
    }
    return ans;
};


int main()
{
    srand(time(NULL));
    string bl;
    int secret = 0;
    int x;
    int numguess = 1;
    cout << "Hello in the game 'Bagels'" << endl << "You should guess secret number" << endl << "You have 10 tries to do that" << endl;
    cout << "Here are some clues:" << endl;
    cout << "When I say:" << "     " << "That means:" << endl;
    cout << "  Pico" << "         " << "One digit is correct but in the wrong position." << endl;
    cout << "  Fermi" << "        " << "One digit is correct and in the right position." << endl;
    cout << "  Bagels" << "       " << "No digit is correct." << endl;
    cout << "Have fun!" << endl;
    cout << "Print your number:" << endl;
    secret = 100 + rand() % 999;
    while (numguess <= 10) {
        cout << "Guess #" << numguess << ":" << endl;
        cin >> x;
        string answer = Bagels(x, secret);
        cout << answer << endl;
        if (answer == "You got it!") {
            system("cls");
            cout << answer << endl;
            cout << "Do you want play again? (yes or no)" << endl;
            cin >> bl;
            if (bl == "no") {
                break;
            }
            else {
                system("cls");
                cout << "Hello in the game 'Bagels'" << endl << "You should guess secret number" << endl << "You have 10 tries to do that" << endl;
                cout << "Here are some clues:" << endl;
                cout << "When I say:" << "     " << "That means:" << endl;
                cout << "  Pico" << "         " << "One digit is correct but in the wrong position." << endl;
                cout << "  Fermi" << "        " << "One digit is correct and in the right position." << endl;
                cout << "  Bagels" << "       " << "No digit is correct." << endl;
                cout << "Have fun!" << endl;
                cout << "Print your number:" << endl;
                numguess = 0;
                secret = rand() % 999 + 100;
            }
        }
        if (numguess == 10) {
            system("cls");
            cout << "You loose!" << endl;
            cout << "Secret number was:     " << secret << endl;
            cout << "Do you want play again? (yes or no)" << endl;
            cin >> bl;
            if (bl == "no") {
                break;
            }
            else {
                system("cls");
                cout << "Hello in the game 'Bagels'" << endl << "You should guess secret number" << endl << "You have 10 tries to do that" << endl;
                cout << "Here are some clues:" << endl;
                cout << "When I say:" << "     " << "That means:" << endl;
                cout << "  Pico" << "         " << "One digit is correct but in the wrong position." << endl;
                cout << "  Fermi" << "        " << "One digit is correct and in the right position." << endl;
                cout << "  Bagels" << "       " << "No digit is correct." << endl;
                cout << "Have fun!" << endl;
                cout << "Print your number:" << endl;
                numguess = 0;
                secret = rand() % 999 + 100;
            }
        }
        numguess++;
    }
    return 0;
}