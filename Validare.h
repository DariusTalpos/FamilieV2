#pragma once

#include "Domain.h"
#include <vector>
#include <string>
using namespace std;

class ValidatorExceptii {
private:
	vector<string> erori;
public:
	ValidatorExceptii(vector<string> erori);
	string getErori();
};

class ValidatorFilme
{
public:
	void validare_film(const Film& film);
	void validare_pozitie(const int poz, const size_t pozitii);
	void validare_proprietate1(const string proprietate);
	void validare_proprietate_ordine(const string proprietate, const string ordine);
};