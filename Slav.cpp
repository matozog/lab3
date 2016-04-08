#include "Slav.h"
#include <fstream>
#include <iterator>
#include <time.h>
#include <cstdlib>

using namespace std;

vector <string> Slav::names;
int Slav::_counter = 0;

void Slav::init()
{
	srand(time(NULL));
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Slav::Slav()
{
	static int amountOfNames = (init(), names.size());
	// lazy initialization, wykonuje sie tylko raz w programie,
	//zmiennej zostanie przypisana wartość funkcji name.size().
	_name = names[rand() % amountOfNames];
	_id = _counter++;
}

string Slav::description()
{
	return string("  ") + _name + " [" + to_string(_id) + "]";
}
sex Slav::get()
{
	if(_name.back()=='a') return famale;
	return male;
}