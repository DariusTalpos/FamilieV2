#pragma once
#include "Repository.h"
#include "Validare.h"
class Service
{
private:
	Repository& repository;
	ValidatorFilme& validator;
public:
	/*
	* Constructor pentru service
	* @repository - referinta la obiect de tip Repository
	* @validator - referinta la obiect de tip ValidatorFilme
	*/
	Service(Repository& repository, ValidatorFilme& validator) noexcept : repository{ repository }, validator{ validator } {};
	/*
	* Preia din repo lungimea vectorului de filme
	*/
	const size_t service_lungime() noexcept;
	/*
	* Valideaza datele si, daca acestea sunt corecte, apeleaza repository pentru adaugarea filmului in vector
	*/
	void service_add(string titlu, string gen, string actor_principal, string an_aparitie);
	/*
	* Valideaza datele si, daca acestea sunt corecte, apeleaza repository pentru modificarea filmului de pe pozitia data
	*/
	void service_modify(string titlu, string gen, string actor_principal, string an_aparitie,string pozitie);
	/*
	* Sterge filmul de pe pozitia data
	*/
	void service_delete(string pozitie);
	/*
	* Apeleaza repository-ul pentru a cauta filmul cu titlul si actorul corespunzator
	* Returneaza:
	*			  filmul, daca este gasit
    * un film care are campuri goale, altfel
	*/
	Film service_search(string titlu, string actor);

	VectorDinamic<Film> service_filter(string proprietate, string obiect);
	
	VectorDinamic<Film> service_sort(string proprietate, string ordine);

	/*
	* Preia din repository lista de filme
	*/
	const VectorDinamic<Film>& service_get() noexcept;
	/*
	* reseteaza vectorul din repository(pentru filme)
	*/
	void service_reset() noexcept;
};


int transformare_string_numar(string str);