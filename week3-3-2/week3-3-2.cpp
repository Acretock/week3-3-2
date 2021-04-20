#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Person
{
public:
	Person();
	~Person();
	void ChangeFirstName(int year, const string& name) {
		//First = name;
		First.insert({ year,name });
	}
	void ChangeLastName(int year, const string& last){
		//Last = last;
		Last.insert({ year,last });
	}
	string GetFullName(int year) {
		if ((First.lower_bound(year)->first <= year))/*&& (Last.lower_bound(year)->first <= year))*/ {
			string tmp = Last.lower_bound(year)->second + " wiht unnown last name";
			return tmp;
		}
		if ((Last.count(year) == 0)&&(First.count(year) != 0)) {
			string tmp = First.find(year)->second + " with unnown first name";
			return tmp;
		}
		if ((Last.count(year) == 0) && (First.count(year) == 0))
			return "Incognito";
		if ((First.lower_bound(year)->first <= year) && (Last.lower_bound(year)->first <= year)) {
			string tmp = First.find(year)->second + Last.find(year)->second;
			return tmp;
		}

	}
private:
	map<int,string> First;
	map<int,string> Last;
	//string First;
	//string Last;
};

Person::Person()
{
}

Person::~Person()
{
}


int main()
{
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : { 1900, 1965, 1990 }) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : { 1969, 1970 }) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : { 1969, 1970 }) {
		cout << person.GetFullName(year) << endl;
	}
	return 0;
}
