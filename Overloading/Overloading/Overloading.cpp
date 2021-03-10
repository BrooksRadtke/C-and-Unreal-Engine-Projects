// Overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Functions.h"
using std::cout;
using std::cin;
using std::string;


int main()
{
    int total = add(3, 4);
    cout << "3 + 4 is " << total << '\n';

    double another = add(1.2, 3.4);
    {
        cout << '\n';
        cout << "1.2 + 3.4 is " << another << '\n';
    }
    double totalOfThree = add(1.1, 2.2, 3.3);
    {
        cout << "1.1 + 2.2 + 3.3 is " << totalOfThree << '\n';
    }

    if (test(true))
    {
        cout << "true passes the test" << '\n';
    }
    if (test(3.2))
    {
        cout << "3.2 passes the test" << '\n';
    }
    // Cannot implicity convert type
    /*if (test(3))
    {
        cout << "3 passes the test" << '\n';
    }*/

    // Testing strings
    string name;
    cout << "Who are you? ";
    cin >> name;
    string greeting = "Hello, " + name;
    if (name == "Brooks")
    {
        greeting += ", I know you!";
    }
    cout << greeting << '\n';

    int l = greeting.length();
    cout << "\"" + greeting + "\" is " << l << " characters long." << '\n';
    string beginning = greeting.substr(greeting.find(' ') + 1);
    cout << beginning << '\n';
    if (beginning == name)
    {
        cout << "expected result." << '\n';
    }

    string phrase1;
    string phrase2;

    /*cout << "Hello! We are going to compare the legnth of 2 words! Please enter the fist word: \n";
    cin >> str1;
    cout << "Great! Please enter the second word: \n";
    cin >> str2;*/

    cout << "Hello! We are going to compare the length of 2 phrase! Please enter the fist phrase: \n";
    getline(cin, phrase1);
    cout << "Great! Please enter the second phrase: \n";
    getline(cin, phrase2);


    if (phrase1.length() > phrase2.length())
    {
        cout << "Wow! The first phrase was longer than the second one! " << phrase1.length() 
            << " characters long compare to " << phrase2.length() << " characters!\n";
    }
    if (phrase1.length() < phrase2.length())
    {
        cout << "Interesting! The first phrase was less than than the second one in length! " << phrase1.length() 
            << " characters long to " << phrase2.length() << " characters!\n";
    }
    if (phrase1.length() == phrase2.length())
    {
        cout << "How unusual, yet perfectly balanced!" << phrase1.length() << " to " << phrase2.length()
            << " characters!\n";
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
