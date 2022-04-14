#include "UI.h"
#include <iostream>
#include <string>
using namespace std;

void UI::run()
{
	int rulare = 1;
	int ok = 0;
	string comanda;
	cout << "Aceasta aplicatie are rolul de a ajuta in gestionarea unei liste de filme pentru inchirieri\n";
	cout << "Aveti la dispozitie urmatoarele comenzi:\n";
	while (rulare == 1)
	{
		ok = 0;
		cout << "1. Adaugarea unui film nou\n";
		cout << "2. Modificarea unui film existent\n";
		cout << "3. Stergerea unui film existent\n";
		cout << "4. Cautarea unui film existent\n";
		cout << "5. Filtrarea listei de filme\n";
		cout << "6. Sortarea listei de filme\n";
		cout << "7. Afisarea listei de filme\n";
		cout << "8. Inchiderea aplicatiei\n";
		cout << "Comanda este: ";
		getline(cin, comanda);
		if (comanda == "1")
		{
			ui_add();
			ok = 1;
		}
		if (comanda == "2")
		{
			ui_modify();
			ok = 1;
		}
		if (comanda == "3")
		{
			ui_delete();
			ok = 1;
		}
		if (comanda == "4")
		{
			ui_search();
			ok = 1;
		}
		if (comanda == "5")
		{
			ui_filter();
			ok = 1;
		}
		if (comanda == "6")
		{
			ui_sort();
			ok = 1;
		}
		if (comanda == "7")
		{
			ui_print(service.service_get());
			ok = 1;
		}
		if (comanda == "8")
		{
			rulare = 0;
			break;
		}
		if (ok == 0)
			cout << "Comanda gresita.\n";
		cout << "\n";
	}
}

void UI::ui_add()
{
	string titlu, gen, an, actor;
	cout << "\nAti ales sa adaugati un nou film.\n";
	cout << "Titlul filmului este: ";
	getline(cin, titlu);
	cout << "Genul filmului este: ";
	getline(cin, gen);
	cout << "Anul aparitiei filmului este: ";
	getline(cin, an);
	cout << "Actorul principal al filmului este: ";
	getline(cin, actor);
	try
	{
		service.service_add(titlu, gen, actor, an);
		cout << "Film adaugat cu succes.\n";
	}
	catch (ValidatorExceptii& ve)
	{
		cout << "\n" << ve.getErori();
	}
}

void UI::ui_modify()
{
	if (service.service_lungime() == 0)
	{
		cout << "Lista de filme este goala.\n";
		return;
	}
	string titlu, gen, an, actor, pozitie;
	cout << "\nAti ales sa modificati un film existent.\n";
	ui_print(service.service_get());
	cout << "Numarul filmului pe care doriti sa il modificati este: ";
	getline(cin, pozitie);
	cout << "Titlul filmului este: ";
	getline(cin, titlu);
	cout << "Genul filmului este: ";
	getline(cin, gen);
	cout << "Anul aparitiei filmului este: ";
	getline(cin, an);
	cout << "Actorul principal al filmului este: ";
	getline(cin, actor);
	try
	{
		service.service_modify(titlu, gen, actor, an, pozitie);
		cout << "Film modificat cu succes.";
	}
	catch (ValidatorExceptii& ve)
	{
		cout << "\n" << ve.getErori();
	}
}

void UI::ui_delete()
{
	if (service.service_lungime() == 0)
	{
		cout << "Lista de filme este goala.\n";
		return;
	}
	string pozitie;
	cout << "\nAti ales sa stergeti un film existent.\n";
	ui_print(service.service_get());
	cout << "Numarul filmului pe care doriti sa il stergeti este: ";
	getline(cin, pozitie);
	try
	{
		service.service_delete(pozitie);
		cout << "Film sters cu succes.\n";
	}
	catch (ValidatorExceptii& ve)
	{
		cout << "\n" << ve.getErori();
	}
}

void UI::ui_search()
{
	if (service.service_lungime() == 0)
	{
		cout << "Lista de filme este goala.\n";
		return;
	}
	cout << "\nAti ales sa cautati un film.\n";
	string titlu,actor;
	cout << "Titlul filmului este: ";
	getline(cin, titlu);
	cout << "Actorul principal al filmului este: ";
	getline(cin, actor);
	Film rezultat{ service.service_search(titlu, actor) };
	if (rezultat.getTitlu() == "")
	{
		cout << "\nNu exista acest film.\n";
	}
	else
	{
		cout << "\nFilmul este: \n";
		cout << "Titlu: " << rezultat.getTitlu() << "\n";
		cout << "Gen: " << rezultat.getGen() << "\n";
		cout << "An aparitie: " << rezultat.getAn() << "\n";
		cout << "Actor principal: " << rezultat.getActor() << "\n";
	}
}

void UI::ui_filter()
{
	cout << "\n";
	if (service.service_lungime() == 0)
	{
		cout << "Lista de filme este goala.\n";
		return;
	}
	string proprietate, obiect;
	cout << "Ati ales sa filtrari lista dupa o proprietate.\n";
	cout << "Proprietatile posibile sunt: titlu, an\n";
	cout << "1. Cele care au un anumit titlu \n";
	cout << "2. Cele care nu au un anumit titlu \n";
	cout << "3. Cele care au aparut inainte sau intr-un an anume\n";
	cout << "4. Cele care au aparut dupa un anumit an\n";
	cout << "Proprietatea este: ";
	getline(cin, proprietate);
	cout << "\nTitlul/anul este: ";
	getline(cin, obiect);
	try
	{
		VectorDinamic<Film> filtrat = service.service_filter(proprietate, obiect);
		cout << "\nRezultatul filtrarii este:\n";
		ui_print(filtrat);
	}
	catch (ValidatorExceptii& ve)
	{
		cout << "\n" << ve.getErori();
	}
}

void UI::ui_sort()
{
	cout << "\n";
	if (service.service_lungime() == 0)
	{
		cout << "Lista de filme este goala.\n";
		return;
	}
	string proprietate;
	cout << "Ati ales sa sortati lista dupa o proprietate.\n";
	cout << "Proprietatile posibile sunt: titlu, actor, an+gen.\n";
	cout << "Proprietatea aleasa este: ";
	getline(cin, proprietate);
	string ordine;
	cout << "Lista poate fi sortata crescator sau descrecator.\n";
	cout << "Lista va fi sortata: ";
	getline(cin, ordine);
	try
	{
		VectorDinamic<Film> sortat = service.service_sort(proprietate, ordine);
		ui_print(sortat);
	}
	catch (ValidatorExceptii& ve)
	{
		cout << "\n" << ve.getErori();
	}
}

void UI::ui_print(VectorDinamic<Film> lista)
{
	cout << "\n";
	if (lista.size() == 0)
	{
		cout << "Lista este goala.\n";
		return;
	}
	for (int i=0;i< lista.size();i++)
	{
		cout << "Filmul nr. " << i + 1 <<":\n";
		cout << "Titlu: " << lista.at(i).getTitlu() << "\n";
		cout << "Gen: " << lista.at(i).getGen() << "\n";
		cout << "An aparitie: " << lista.at(i).getAn() << "\n";
		cout << "Actor principal: " << lista.at(i).getActor() << "\n";
	}
}

void UI::golire_buffer() noexcept
{
	while (getchar() != '\n');
}
