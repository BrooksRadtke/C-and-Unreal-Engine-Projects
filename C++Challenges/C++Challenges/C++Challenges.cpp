#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using std::string;
using namespace std;

// This program makes up a series of challenges and exercises ranging from basic to difficult;

void SayHello()
{
    cout << "Hello!\n";
}

void MyCats(string cat1, string cat2)
{
    cout << cat1 << " and " << cat2 << " are buddies.\n";
}

int addFive(int x)
{
    return x + 5;
    cout << "\n";
}

void SayHello(string var1, string var2)
{
    cout << var1 << " and " << var2 << " occasionally say hello.\n";
}

// Create a class
class SomeCats
{
public:
    int ageOfCat;
    string nameOfCat;

    void SayMeow()
    {
        cout << "Meow, pilgrim.\n";
    }

protected:
    string birthPlace;
};

// Create a constructor
class CatConstructor
{
public:
    string catName;
    int catAge;
    CatConstructor(string catName, int catAge);

    // Use private keyword
private:
    double birthday;
};

CatConstructor::CatConstructor(string x, int y)
{
    catName = x;
    catAge = y;
}

// Inheritance
class neighborCats : public SomeCats
{
    int ageOfCat = 1;
};

// Multilevel inheritance
class myOtherNeighborsCats : public neighborCats
{
public:
    void setBirthPlace(string b)
    {
        birthPlace = b;
    }
    string getBirthPlace()
    {
        return birthPlace;
    }
};

// Derive a class from more than one base class
class myNeighborsNeighborsCats : public myOtherNeighborsCats, public neighborCats
{

};

// Utilizes polymorphism
class myDog : public SomeCats
{
public:
    void SayMeow()
    {
        cout << "Bow-wow, pilgrim.\n";
    }
};

class Dog
{
public:
    string Breed;
    string Color;
    double Height;
    double Weight;

    void Shake()
    {
        cout << "Shake!\n";
    }

    void Sit()
    {
        cout << "Sit!\n";
    }

    void LayDown()
    {
        cout << "Lay down!\n";
    }
};

int main()
{
    // *****Basic*****
    // Print Hello world and utilize 'cout <<'
    // Use '\n' to insert a new line
    cout << "Hello World!\n\n";

    // Basic - Variables
    // Declare a variable and display it's value in the console
    string greeting = "Hi there! This is my first string!\n\n";
    cout << greeting;

    // Utilize different datatypes and keywords
    char myChar = 'B';
    int myInt = 28;
    double myDouble = 16.9;
    bool isBool = true;
    string myName = "Brooks";
    float myFloat = 22.2;

    // Utilize const
    const int yearOfGreatTesting = 2020;

    // Create a basic program that accepts user input
    cout << "To whom do I have the pleasure of meeting?\n\n";
    string response;
    cin >> response;
    cout << "Of course! Hello " << response << "!\n\n";

    // Concatenate strings
    string concat1 = "You'll need to excuse me ";
    string concat2 = "while I put a few strings together.";
    string fullConcat = concat1 + concat2;
    cout << fullConcat << '\n';

    // Utilize the length() function and display the output in the console.
    cout << "Did you know that there are " << fullConcat.length() << " characters in the above sentence?\n";
    // Access and print the third character in one of your strings in the console.
    cout << "Or that the 3rd character in the sentence is a " << fullConcat[2] << "?\n\n";
    // Change the value of a specific character in a string.
    cout << "What is we replace all the vowels of that sentence with 'x'? It would look like this: \n\n";
    replace(fullConcat.begin(), fullConcat.end(), 'a', 'x');
    replace(fullConcat.begin(), fullConcat.end(), 'e', 'x');
    replace(fullConcat.begin(), fullConcat.end(), 'i', 'x');
    replace(fullConcat.begin(), fullConcat.end(), 'o', 'x');
    replace(fullConcat.begin(), fullConcat.end(), 'u', 'x');
    cout << fullConcat << endl;

    // *****Math Operators*****
    // Utilize each of the operators and display their result
    int myInt1 = 5;
    int myInt2 = 3;

    cout << "Now for some math!\n";
    cout << myInt1 << " + " << myInt2 << " = " << myInt1 + myInt2 << '\n';
    cout << myInt1 << " - " << myInt2 << " = " << myInt1 - myInt2 << '\n';
    cout << myInt1 << " * " << myInt2 << " = " << myInt1 * myInt2 << '\n';
    cout << myInt1 << " / " << myInt2 << " = " << myInt1 / myInt2 << '\n';
    ++myInt1;
    cout << myInt1 << '\n';

    // Utilize comparison operators
    if (myInt1 > myInt2)
    {
        cout << myInt1 << " is greater than " << myInt2 << '\n';
    }

    if (myInt1 <= myInt2)
    {
        cout << myInt1 << " is less than or equal to " << myInt2 << '\n';
    }

    if (myInt1 == myInt2)
    {
        cout << myInt1 << " is equal to " << myInt2 << '\n';
    }

    if (myInt1 != myInt2)
    {
        cout << myInt1 << " is not equal " << myInt2 << '\n';
    }
    myInt1 += 5;
    cout << myInt1 << '\n';

    myInt1 &= 2;
    cout << myInt1 << '\n';

    myInt1 <<= 2;
    cout << myInt1 << endl << '\n';

    // Logical operators
    if (myInt1 < 5 && myInt2 < 10)
    {
        cout << "myInt1 < 5 && myInt2 < 10\n";
    }

    if (myInt1 < 5 || myInt2 < 10)
    {
        cout << "myInt1 < 5 || myInt2 < 10\n";
    }

    if (!(myInt1 < 5 && myInt2 < 10))
    {
        cout << "!myInt1 < 5 && myInt2 < 10\n";
    }

    // *****Harder Challenges*****
    /*This
        is
        a
        multi-
        line
        comment!*/

    // Using getline()
    string userName;
    cout << "Sorry, could you remind me your name?\n";
    getline(cin, userName);
    cout << "Oh, that's right. What can I say? The first thing to go is the memory?\n";

    // Utilize the max(x,y) function
    // finds highest value
    cout << max(5, 10) << '\n';
    // squareroot of element
    cout << sqrt(144) << '\n';
    // rounds element
    cout << round(9.9) << '\n';
    // x to power of y
    cout << pow(2, 9) << '\n';

    // Conditional Statements
    int catLives;
    cout << "How many lives does your cat have left?\n";
    cin >> catLives;
    switch (catLives)
    {
    case 1:
        cout << "Unfortunate, he's not long for this world...\n";
        break;
    case 2:
        cout << "Perhaps I missed it with my rear tires?\n";
        break;
    case 3:
        cout << "Well, you know in some countries, cats are gods...or delicacies.\n";
        break;
    case 4:
        cout << "That's nice.\n";
        break;
    case 5:
        cout << "I think I left something on the stove.\n";
        break;
    case 6:
        cout << "I heard they came to this planet looking for intelligent life,"
            << "and that they made a mistake!\n";
        break;
    case 7:
        cout << "There once was a parable about a cat, and it went like this:\n";
        break;
    case 8:
        cout << "I'm sure where else to take the conversation.\n";
        break;
    case 9:
        cout << "Excellent! A happy and healthy creature on God's green earth.\n";
        break;
    default:
        cout << "Are we even talking about the same thing??\n";
        break;
    }
    if (catLives > 5)
    {
        cout << "Can we please talk about something else?\n";
    }
    else if (catLives <= 4)
    {
        cout << "I'm sure we will laugh about all this someday in found memory of you're"
            << "... kitty.\n";
    }
    else
    {
        cout << "Again, I have no idea what you are talking about.\n";
    }
    // use of ternary
    auto catResponse = (catLives < 4) ? "Me-ouch!!\n" : "Meow.\n";
    cout << catResponse << endl;

    // Use of while loop
    int whileLoop = 0;
    while (whileLoop < 5)
    {
        cout << whileLoop << ' ';
        whileLoop++;
    }
    cout << '\n';

    int anotherWhileLoop = 0;
    do
    {
        cout << anotherWhileLoop << " ";
        anotherWhileLoop++;
    }     
    while (anotherWhileLoop < 10);
    cout << '\n';

    // Use of For loop
    int yetAnotherWhileLoop = 0;
    for (int yetAnotherWhileLoop = 0; yetAnotherWhileLoop < 5; yetAnotherWhileLoop++)
    {
        cout << yetAnotherWhileLoop << " ";
    }
    cout << '\n';

    // Use of Break/Continue
    for (int i = 0; i < 10; i++)
    {
        // skips this number if value is equal
        if (i == 6)
        {
            continue;
        }
        // breaks loop if value is equal
        if (i == 8)
        {
            break;
        }
        cout << i << "\n";
    }

    // Create an array and display one of it's elements
    string myCats[4] = { "My first cat", "My second cat", "My third cat", "The last of my cats" };
    cout << myCats[3] << "\n";

    // Loop through and print array
    for (int i = 0; i < 4; i++)
    {
        cout << myCats[i] << "\n";
    }

    // Create reference variable
    string currentCat = "Mackie";
    string &cats = currentCat;

    cout << currentCat << "\n";
    cout << cats << "\n";

    // *****Diffifult Challenges*****
    // Utilize the & operator to get the memory address of a variable
    cout << &currentCat << "\n";
    // Utilize the * operator to create a pointer variable
    string* ptr = &currentCat;
    cout << ptr << "\n";
    // Utilize the dereference operator
    cout << *ptr << "\n\n";

    SayHello();

    // Declare a function with multiple parameters
    MyCats("Paul", "Silas");

    // Utilize return in a function
    addFive(10);

    SayHello("Bob", "Phil");

    SomeCats firstCat;
    firstCat.ageOfCat = 15;
    firstCat.nameOfCat = "Stockholm";

    SomeCats secondCat;
    secondCat.ageOfCat = 2;
    secondCat.nameOfCat = "New Guy";

    cout << "I have two cats: " << firstCat.nameOfCat << " and " << secondCat.nameOfCat << ".\n";
    cout << firstCat.nameOfCat << " is " << firstCat.ageOfCat << " years old, while " << secondCat.nameOfCat
        << " is only " << secondCat.ageOfCat << " years old.\n";
    // Define a function outside of a class
    firstCat.SayMeow();

    // Call constuctor
    CatConstructor kitty("Phil", 10);
    cout << kitty.catName << " is " << kitty.catAge << " years old.\n";

    // Access the protected specifier in an inherited class. 
    myNeighborsNeighborsCats sillyCat;
    sillyCat.setBirthPlace("San Diego");
    cout << sillyCat.getBirthPlace() << "\n";

    myDog peet;
    peet.SayMeow();

    // Use try, catch, throw
    try 
    {
        int age = 17;
        if (age >= 18)
        {
            cout << "Welcome to the jungle.\n";
        }
        else
        {
            throw(age);
        }
    }
    catch (int num)
    {
        cout << "Sorry kiddo, come back when you're old enough\n";
        cout << " because your are currently: " << num << ".\n";
    }

    // *****OOP Challenges*****
    Dog TBone;
    string Breed("Retriever");
    string Color("Gold");
    double Height(23.55);
    double Weight(45);
    TBone.Shake();
    TBone.Sit();
    TBone.LayDown();
}