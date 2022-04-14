#include "Repository.h"

const VectorDinamic<Film>& Repository::repo_get() noexcept
{
	return this->lista_filme;
}

const size_t Repository::repo_lungime() noexcept
{
	return this->lista_filme.size();
}

void Repository::repo_add(const Film& film)
{
	lista_filme.push_back(film);
}

void Repository::repo_modify(const Film& film, int pozitie)
{
	lista_filme.at(pozitie).setActor(film.getActor());
	lista_filme.at(pozitie).setAn(film.getAn());
	lista_filme.at(pozitie).setGen(film.getGen());
	lista_filme.at(pozitie).setTitlu(film.getTitlu());
}

void Repository::repo_delete(int pozitie) noexcept
{
	lista_filme.erase(pozitie);
}

Film Repository::repo_search(string titlu, string actor)
{
	const size_t lungime{ repo_lungime() };
	for (int i = 0; i < lungime; i++)
		if (lista_filme.at(i).getTitlu() == titlu && lista_filme.at(i).getActor() == actor)
			return lista_filme.at(i);
	Film film("","","",0);
	return film;
}

VectorDinamic<Film> Repository::repo_filter_titlu(string modalitate,string titlu)
{
	VectorDinamic<Film> rezultat;
	if (modalitate == "1")
	{
		const size_t lungime = repo_lungime();
		for (int i = 0; i < lungime; i++)
			if (lista_filme.at(i).getTitlu() == titlu)
				rezultat.push_back(lista_filme.at(i));
	}
	else
	{
		const size_t lungime = repo_lungime();
		for (int i = 0; i < lungime; i++)
			if (lista_filme.at(i).getTitlu() != titlu)
			{
				Film gasit = Film(lista_filme.at(i));
				rezultat.push_back(gasit);
			}
	}
	return rezultat;

}

VectorDinamic<Film> Repository::repo_filter_an(string modalitate,int an)
{
	VectorDinamic<Film> rezultat;
	if (modalitate == "1")
	{
		const size_t lungime = repo_lungime();
		for (int i = 0; i < lungime; i++)
			if (lista_filme.at(i).getAn() <= an)
			{
				Film gasit = Film(lista_filme.at(i));
				rezultat.push_back(gasit);
			}
	}
	else
	{
		const size_t lungime = repo_lungime();
		for (int i = 0; i < lungime; i++)
			if (lista_filme.at(i).getAn() > an)
			{
				Film gasit = Film(lista_filme.at(i));
				rezultat.push_back(gasit);
			}
	}
	return rezultat;
}

VectorDinamic<Film> Repository::repo_sort(bool(*f_cmp)(const Film&, const Film&))
{
	VectorDinamic<Film> filme = repo_get();
	for(int i=0;i<filme.size()-1;i++)
		for(int j=i+1;j<=filme.size()-1;j++)
			if (!f_cmp(filme.at(i), filme.at(j)))
			{
				Film aux = filme.at(i);
				filme.at(i) = filme.at(j);
				filme.at(j) = aux;
			}
	return filme;
}

void Repository::repo_reset() noexcept
{
	lista_filme.reset();
}
