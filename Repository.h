#pragma once
#include "Domain.h"
#include "VectorDinamic.h"
//#include <vector>
using namespace std;

class Repository
{
private:
	VectorDinamic<Film> lista_filme;
public:
	/*
	* Constructor pentru repository
	*/
	Repository() = default;
	/*
	* Returneaza lungimea vectorului
	*/
	const size_t repo_lungime() noexcept;
	//Film copy_film(Film film);
	/*
	* Adauga in vector filmul dat
	* @film - referinta la un obiect de tip film
	*/
	void repo_add(const Film& film);
	/*
	* Modifica in vector filmul de pe pozitia data
	* @film - referinta la un obiect de tip film
	* @pozitie - pozitia din vector a filmului
	*/
	void repo_modify(const Film& film,int pozitie);
	/*
	* Sterge din vector filmul de pe pozitia data
	* @pozitie - pozitia din lista a vectorului
	*/
	void repo_delete(int pozitie) noexcept;
	/*
	* Cauta in vector filmul cu titlul si actorul dat
	* Returneaza:
	* filmul, daca este gasit
    * un film care are campuri goale, altfel
	*/
	Film repo_search(string titlu, string actor);
	VectorDinamic<Film> repo_filter_titlu(string modalitate,string titlu);
	VectorDinamic<Film> repo_filter_an(string modalitate,int an);

	VectorDinamic<Film> repo_sort(bool(*f_cmp)(const Film&, const Film&));

	/*
	* Returneaza vectorul de filme
	*/
	const VectorDinamic<Film>& repo_get() noexcept;
	/*
	* Reseteaza vectorul de filme (pentru teste)
	*/
	void repo_reset() noexcept;
};