#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
public:
	Person() = default;

	Person(const string& name, int age)
		: m_name(name), m_age(age)
	{}

	const string& Name() const
	{
		return m_name;
	}

	int Age() const
	{
		return m_age;
	}

	void SayHi() const
	{
		cout << "Hi! My name is " << m_name <<
			" and I am " << m_age << " years old. \n";
	}

private:
	string m_name{};
	int m_age{};
};

int main()
{
	vector<Person> persons
	{
		{"Connie", 30},
		{"Rita", 10},
		{"Mona Lisa", 516}
	};

	persons.push_back(Person{ "John", 40 });

	for (const auto& p : persons)
	{
		p.SayHi();
	}
}
