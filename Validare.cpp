#pragma once
#include "Validare.h"

ValidatorExceptii::ValidatorExceptii(vector<string> erori)
{
	this->erori = erori;
}

string ValidatorExceptii::getErori()
{
	string mesaj = "";
	for (const string eroare : erori)
		mesaj += eroare + "\n";
	return mesaj;
}

void ValidatorFilme::validare_film(const Film& film)
{
	vector<string> erori;
	if (film.getTitlu().length() < 2)
		erori.push_back("Titlul filmului trebuie sa aiba minim doua caractere.");
	if (film.getGen().length() < 2)
		erori.push_back("Genul filmului trebuie sa aiba minim doua caractere.");
	if (film.getActor().length() < 2)
		erori.push_back("Actorul filmului trebuie sa aiba minim doua caractere.");
	if (film.getAn() < 1900 || film.getAn() > 2050)
		erori.push_back("Filmul trebuie sa fi aparut intr-un an realist...");

	if (erori.size() > 0)
		throw ValidatorExceptii(erori);
}

void ValidatorFilme::validare_pozitie(const int poz, const size_t pozitii)
{
	vector<string> erori;
	if(poz-1>pozitii || poz-1<0)
		erori.push_back("Nu exista aceasta pozitie in lista.");

	if (erori.size() > 0)
		throw ValidatorExceptii(erori);
}

void ValidatorFilme::validare_proprietate1(const string proprietate)
{
	vector<string> erori;
	if (proprietate <"1" || proprietate > "4")
		erori.push_back("Proprietate incorecta.");
	if (erori.size() > 0)
		throw ValidatorExceptii(erori);
}

void ValidatorFilme::validare_proprietate_ordine(const string proprietate, const string ordine)
{
	vector<string> erori;
	if (proprietate != "titlu" && proprietate != "actor" && proprietate != "an+gen")
		erori.push_back("Proprietate incorecta.");
	if (ordine != "crescator" && ordine != "descrescator")
		erori.push_back("Ordine incorecta.");
	if (erori.size() > 0)
		throw ValidatorExceptii(erori);
}
