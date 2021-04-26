#include <iostream>
#include <ostream>
#include <set>
#include <string>
using namespace std;

ostream& operator<<(ostream& os, const set<string>& strings)
{
    os << '{';

    bool isFirst = true;
    for (const auto& s : strings)
    {
        if (isFirst)
        {
            os << s;
            isFirst = false;
        }
        else
        {
            os << ", " << s;
        }
    }

    os << '}';
    return os;
}

int main()
{
    set<string> colors{ "red","blue","yellow" };
    cout << " Initial colors: \n";
    cout << " " << colors << "\n\n";

    colors.insert("green");
    cout << " After inserting green: \n";
    cout << " " << colors << "\n\n";

    colors.insert("green");
    cout << " After trying to insert green again: \n";
    cout << " " << colors << "\n\n";

    colors.erase("red");
    cout << " After removing red: \n";
    cout << " " << colors << "\n\n";

    auto it = colors.find("blue");
    if (it != colors.end())
    {
        cout << " The set contains the color blue.\n";
    }
    else
    {
        cout << " The set doesn't contain the color blue.\n";
    }
}