#include "Service.h"

const size_t Service::service_lungime() noexcept
{
	return this->repository.repo_lungime();
}

void Service::service_add(string titlu, string gen, string actor_principal,string an_aparitie)
{
	int an = transformare_string_numar(an_aparitie);
	Film film(titlu, gen, actor_principal, an);
	validator.validare_film(film);
	repository.repo_add(film);
}

void Service::service_modify(string titlu, string gen, string actor_principal, string an_aparitie,string pozitie)
{
	int poz = transformare_string_numar(pozitie);
	int an = transformare_string_numar(an_aparitie);
	Film film(titlu, gen, actor_principal, an);
	validator.validare_pozitie(poz,repository.repo_lungime());
	poz--;
	validator.validare_film(film);
	repository.repo_modify(film, poz);
}

void Service::service_delete(string pozitie) 
{
	int poz = transformare_string_numar(pozitie);
	validator.validare_pozitie(poz, repository.repo_lungime());
	poz--;
	this->repository.repo_delete(poz);
}

Film Service::service_search(string titlu, string actor)
{
	return this->repository.repo_search(titlu, actor);
}

VectorDinamic<Film> Service::service_filter(string proprietate, string obiect)
{
	validator.validare_proprietate1(proprietate);
	if (proprietate == "1")
		return repository.repo_filter_titlu("1", obiect);
	else if (proprietate == "2")
		return repository.repo_filter_titlu("2", obiect);
	else if (proprietate == "3")
		return repository.repo_filter_an("1", transformare_string_numar(obiect));
	return repository.repo_filter_an("2", transformare_string_numar(obiect));
}

VectorDinamic<Film> Service::service_sort(string proprietate, string ordine)
{
	validator.validare_proprietate_ordine(proprietate, ordine);
	if (proprietate == "titlu")
	{
		if (ordine == "crescator")
			return repository.repo_sort(cmpTitluCrescator);
		else
			return repository.repo_sort(cmpTitluDescrescator);
	}
	if (proprietate == "actor")
	{
		if (ordine == "crescator")
			return repository.repo_sort(cmpActorCrescator);
		else
			return repository.repo_sort(cmpActorDescrescator);
	}
	if (proprietate == "an+gen" && ordine == "crescator")
		return repository.repo_sort(cmpAnGenCrescator);

	return repository.repo_sort(cmpAnGenDescrescator);
}


const VectorDinamic<Film>& Service::service_get() noexcept
{
	return this->repository.repo_get();
}

void Service::service_reset() noexcept
{
	this->repository.repo_reset();
}


int transformare_string_numar(string str)
{
	int numar = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] > 57 || str[i] < 48)
			return -1;
		else
			numar = numar * 10 + (str[i] - '0');
	}
	return numar;
}
