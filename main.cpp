// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);
void sort(Slav * slavs, int n);

int main(int argc, char const *argv[])
{
	int n = (2 * atoi(argv[1]));
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);
	sort(slavs,n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	srand(time(NULL));
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");
	vectorOfSlavs.push_back(slavs);
	// Umieść Słowian w losowej kolejności w wektorze.
	for (int i=0; i<n; i++)
	{
		int j=rand()%vectorOfSlavs.size();
		vectorOfSlavs.insert(vectorOfSlavs.begin()+j,&slavs[i]);
	}
	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
	vector <Slav *>::iterator _it;
	for (_it=vectorOfSlavs.begin(); _it!= vectorOfSlavs.end(); _it++)
	{
		cout<<(*_it)->description()<<endl;
	}
	REPORT_CONTAINERS;
	printf("## set\n");
	// Przenieś wszystkich Słowian z wektoru do zbioru.
	for (int i=0; i<n;i++)
	{
		setOfSlavs.insert(vectorOfSlavs[i]);

	}
	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	set <Slav *>::iterator it1;
	for(it1=setOfSlavs.begin(); it1!=setOfSlavs.end() ;it1++)
	{
		mapOfSlavs[(*it1)]=*(++it1);
	}
	setOfSlavs.clear();
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
	map<Slav *,Slav *>::iterator it3;
	for(it3=mapOfSlavs.begin(); it3!=mapOfSlavs.end(); it3++)
	{

		cout<<(*it3).first->description()<<" "<<(*it3).second->description()<<endl;
	
	}
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
	for(int i=0; i<n; i++)
	{
		queueOfSlavs.push(slavs+i);
	}
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.
	while(queueOfSlavs.size())
	{
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();

	}
	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.
	while(stackOfSlavs.size())
	{
		cout<<stackOfSlavs.top()->description()<<endl;
		stackOfSlavs.pop();
	} 
	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
void sort(Slav * slavs, int n)
{
	map<sex, vector<Slav *>> mySlavs;
	for (int i=0; i<n; i++)
	{
		if(slavs[i].get()==famale) mySlavs[famale].push_back(&slavs[i]);
		else mySlavs[male].push_back(&slavs[i]);
	}
}