// AirportDatabase.cpp:
#include <string>
#include <map>
#include <iostream>;
using namespace std;

struct Airport
{
    string Name{};
    string City{};
    string Country{};
    double Latitude{};
    double Longitude{};
    int AltitudeFeet{};

    Airport() = default;

    Airport(string const& name, string const& city, string const& country,
        double latitude, double longitude, int altitudeFeet)
        : Name(name), City(city), Country(country),
        Latitude(latitude), Longitude(longitude), AltitudeFeet(altitudeFeet) {};
};

int main()
{
    // Use of key-values
    map<string, Airport> airportDatabase
    {
        {
            "SEA",
            {
                "Seattle-Tacoma International Airport", "Seattle", "United States",
                47.449, -122.308, 433
            }
        },
        {
            "LAX",
            {
                "Los Angeles International Airport", "Los Angeles", "United States",
                33.943, -118.408, 125
            }
        },
        {
            "FCO",
            {
                "Leonardo da Vinci - Fiumicino Airport", "Rome", "Italy",
                41.800, 12.238, 13
            }
        },
        {
            "LHR",
            {
                "Londond Heathrow Airport", "London", "United Kingdom",
                51.470, -0.461, 83
            }
        }
    };

    cout << " Airport Database Demo \n";
    cout << " --------------------- \n\n";

    cout << " Airport unique code: ";
    string code{};
    cin >> code;
    cout << '\n';

    // Look up airport information 
    auto it = airportDatabase.find(code);
    if (it != airportDatabase.end())
    {
        Airport const& airport = it->second;
        cout << " Airport name: " << airport.Name << '\n';
        cout << " City: " << airport.City<< '\n';
        cout << " Country: " << airport.Country << '\n';
        cout << " Latitude: " << airport.Latitude << '\n';
        cout << " Longitude: " << airport.Longitude << '\n';
        cout << " Elevation (ft): " << airport.AltitudeFeet << '\n';    
    }
    else
    {
        cout << " Sorry, airport code cannot be found. \n";
    }
}