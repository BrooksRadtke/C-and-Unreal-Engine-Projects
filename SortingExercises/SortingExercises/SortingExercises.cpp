#include <iostream>
#include <string>
#include <vector>

// Exercise 1 : Write a program to sort the value of 3 variables of any value (numbers or literals)
template < class T >

void sort3Var(T& x, T& y, T& z)
{
    std::vector<T> v;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);

    bool b = true;
    while (b)
    {
        b = false;
        for (size_t i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                T t = v[i];
                v[i] = v[i + 1];
                v[i + 1] = t;
                b = true;
            }
        }
    }

    x = v[0]; y = v[1]; z = v[2];
}

int main(int argc, char* argv[])
{
    // Generate random int to sort
    int x = rand() % 100;
    int y = rand() % 100;
    int z = rand() % 100;

    sort3Var(x, y, z);
    std::cout << x << " " << y << " " << z << "\n\n";

    // Generate random float to sort
    float i = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 2));
    float j = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 2));
    float k = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 2));

    sort3Var(i, j, k);
    std::cout << i << " " << j << " " << k << "\n\n";

    std::string xstr, ystr, zstr;
    xstr = "abc, ABC, xyz";
    ystr = "abc@example.com";
    zstr = "(abcdef)";

    sort3Var(xstr, ystr, zstr);
    std::cout << xstr << "\n" << ystr << "\n" << zstr << "\n\n";
}