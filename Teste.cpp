#include "Teste.h"
#include <assert.h>
#include <iostream>
using namespace std;

void Teste::teste()
{
	testeDomain();
	testeRepository();
	testeService();
	testGetErori();
}

void Teste::testeDomain()
{
	testDomainGetSetActor();
	testDomainGetSetAn();
	testDomainGetSetGen();
	testDomainGetSetTitlu();
}

void Teste::testeRepository()
{
	testRepositoryAddGet();
	testRepositoryResetLungime();
	testRepositoryModify();
	testRepositoryDelete();
	testRepositorySearch();
	testRepositoryFilterTitlu();
	testRepositoryFilterAn();
	testRepositorySort();
}

void Teste::testeService()
{
	testServiceAddGet();
	testServiceResetLungime();
	testServiceModify();
	testServiceDelete();
	testServiceSearch();
	testServiceFilter();
	testServiceSort();
}

void Teste::testDomainGetSetActor()
{
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	assert(test.getActor() == "Keanu Reeves");
	test.setActor("Reanu Keeves");
	assert(test.getActor() == "Reanu Keeves");
}

void Teste::testDomainGetSetAn()
{
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	assert(test.getAn() == 2010);
	test.setAn(1984);
	assert(test.getAn() == 1984);
}

void Teste::testDomainGetSetGen()
{
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	assert(test.getGen() == "actiune");
	test.setGen("comedie romantica");
	assert(test.getGen() == "comedie romantica");
}

void Teste::testDomainGetSetTitlu()
{
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	assert(test.getTitlu() == "John Wick");
	test.setTitlu("Shrek");
	assert(test.getTitlu() == "Shrek");
}


void Teste::testRepositoryAddGet()
{
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	for(int i=1;i<=11;i++)
		direct_repository.repo_add(test);
	VectorDinamic<Film> test_filme = direct_repository.repo_get();
	assert(test_filme.at(0).getTitlu() == "John Wick");
	assert(test_filme.at(0).getGen() == "actiune");
	assert(test_filme.at(0).getActor() == "Keanu Reeves");
	assert(test_filme.at(0).getAn() == 2010);
}

void Teste::testRepositoryResetLungime() noexcept
{
	size_t lungime = direct_repository.repo_lungime();
	assert(lungime == 11);
	direct_repository.repo_reset();
	lungime = direct_repository.repo_lungime();
	assert(lungime == 0);

}

void Teste::testRepositoryModify()
{
	direct_repository.repo_reset();
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	direct_repository.repo_add(test);
	Film test2("Shrek", "horror", "Will Smith", 1984);
	direct_repository.repo_modify(test2, 0);
	VectorDinamic<Film> test_filme = direct_repository.repo_get();
	assert(test_filme.at(0).getTitlu() == "Shrek");
	assert(test_filme.at(0).getGen() == "horror");
	assert(test_filme.at(0).getActor() == "Will Smith");
	assert(test_filme.at(0).getAn() == 1984);
}

void Teste::testRepositoryDelete()
{
	direct_repository.repo_reset();
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	direct_repository.repo_add(test);
	Film test2("Shrek", "horror", "Will Smith", 1984);
	direct_repository.repo_add(test2);
	direct_repository.repo_delete(0);
	const size_t lungime = direct_repository.repo_lungime();
	assert(lungime == 1);
	VectorDinamic<Film> test_filme = direct_repository.repo_get();
	assert(test_filme.at(0).getTitlu() == "Shrek");
	assert(test_filme.at(0).getGen() == "horror");
	assert(test_filme.at(0).getActor() == "Will Smith");
	assert(test_filme.at(0).getAn() == 1984);
}

void Teste::testRepositorySearch()
{
	direct_repository.repo_reset();
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	direct_repository.repo_add(test);
	Film rezultat = direct_repository.repo_search("John Wick", "Keanu Reeves");
	assert(rezultat.getTitlu() == "John Wick");
	assert(rezultat.getGen() == "actiune");
	assert(rezultat.getActor() == "Keanu Reeves");
	assert(rezultat.getAn() == 2010);
	rezultat = direct_repository.repo_search("Sonic 2", "Tom Holland");
	assert(rezultat.getTitlu() == "");
	assert(rezultat.getGen() == "");
	assert(rezultat.getActor() == "");
	assert(rezultat.getAn() == 0);
}

void Teste::testRepositoryFilterTitlu()
{
	direct_repository.repo_reset();
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	direct_repository.repo_add(test);
	VectorDinamic<Film> rez = direct_repository.repo_filter_titlu("1", "John Wick");
	assert(rez.size() == 1);
	VectorDinamic<Film> rez2 = direct_repository.repo_filter_titlu("2", "John Wick");
	assert(rez2.size() == 0);
	VectorDinamic<Film> rez3 = direct_repository.repo_filter_titlu("1", "Shrek");
	assert(rez3.size() == 0);
	VectorDinamic<Film> rez4 = direct_repository.repo_filter_titlu("2", "Shrek");
	assert(rez4.size() == 1);
}

void Teste::testRepositoryFilterAn()
{
	direct_repository.repo_reset();
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	direct_repository.repo_add(test);
	VectorDinamic<Film> rez = direct_repository.repo_filter_an("1", 2030);
	assert(rez.size() == 1);
	VectorDinamic<Film> rez2 = direct_repository.repo_filter_an("2", 2030);
	assert(rez2.size() == 0);
	VectorDinamic<Film> rez3 = direct_repository.repo_filter_an("1", 2000);
	assert(rez3.size() == 0);
	VectorDinamic<Film> rez4 = direct_repository.repo_filter_an("2", 2000);
	assert(rez4.size() == 1);
}

void Teste::testRepositorySort()
{
	direct_repository.repo_reset();
	Film test("John Wick", "actiune", "Keanu Reeves", 2010);
	direct_repository.repo_add(test);
	Film test2("Sonic 2", "aventura", "Jim Carrey", 2020);
	direct_repository.repo_add(test2);
	VectorDinamic<Film> sortat = direct_repository.repo_sort(cmpTitluCrescator);
	assert(sortat.size() == 2);

	assert(sortat.at(0).getTitlu() == "John Wick");
	assert(sortat.at(0).getGen() == "actiune");
	assert(sortat.at(0).getActor() == "Keanu Reeves");
	assert(sortat.at(0).getAn() == 2010);
	assert(sortat.at(1).getTitlu() == "Sonic 2");
	assert(sortat.at(1).getGen() == "aventura");
	assert(sortat.at(1).getActor() == "Jim Carrey");
	assert(sortat.at(1).getAn() == 2020);

	VectorDinamic<Film> sortat1 = direct_repository.repo_sort(cmpTitluDescrescator);
	assert(sortat1.size() == 2);
	assert(sortat1.at(0).getTitlu() == "Sonic 2");
	assert(sortat1.at(0).getGen() == "aventura");
	assert(sortat1.at(0).getActor() == "Jim Carrey");
	assert(sortat1.at(0).getAn() == 2020);
	assert(sortat1.at(1).getTitlu() == "John Wick");
	assert(sortat1.at(1).getGen() == "actiune");
	assert(sortat1.at(1).getActor() == "Keanu Reeves");
	assert(sortat1.at(1).getAn() == 2010);

	VectorDinamic<Film> sortat2 = direct_repository.repo_sort(cmpActorCrescator);
	assert(sortat2.size() == 2);
	assert(sortat2.at(0).getTitlu() == "Sonic 2");
	assert(sortat2.at(0).getGen() == "aventura");
	assert(sortat2.at(0).getActor() == "Jim Carrey");
	assert(sortat2.at(0).getAn() == 2020);
	assert(sortat2.at(1).getTitlu() == "John Wick");
	assert(sortat2.at(1).getGen() == "actiune");
	assert(sortat2.at(1).getActor() == "Keanu Reeves");
	assert(sortat2.at(1).getAn() == 2010);

	VectorDinamic<Film> sortat3 = direct_repository.repo_sort(cmpActorDescrescator);
	assert(sortat3.size() == 2);
	assert(sortat3.at(0).getTitlu() == "John Wick");
	assert(sortat3.at(0).getGen() == "actiune");
	assert(sortat3.at(0).getActor() == "Keanu Reeves");
	assert(sortat3.at(0).getAn() == 2010);
	assert(sortat3.at(1).getTitlu() == "Sonic 2");
	assert(sortat3.at(1).getGen() == "aventura");
	assert(sortat3.at(1).getActor() == "Jim Carrey");
	assert(sortat3.at(1).getAn() == 2020);

	VectorDinamic<Film> sortat4 = direct_repository.repo_sort(cmpAnGenCrescator);
	assert(sortat4.size() == 2);
	assert(sortat4.at(0).getTitlu() == "John Wick");
	assert(sortat4.at(0).getGen() == "actiune");
	assert(sortat4.at(0).getActor() == "Keanu Reeves");
	assert(sortat4.at(0).getAn() == 2010);
	assert(sortat4.at(1).getTitlu() == "Sonic 2");
	assert(sortat4.at(1).getGen() == "aventura");
	assert(sortat4.at(1).getActor() == "Jim Carrey");
	assert(sortat4.at(1).getAn() == 2020);

	VectorDinamic<Film> sortat5 = direct_repository.repo_sort(cmpAnGenDescrescator);
	assert(sortat5.size() == 2);
	assert(sortat5.at(0).getTitlu() == "Sonic 2");
	assert(sortat5.at(0).getGen() == "aventura");
	assert(sortat5.at(0).getActor() == "Jim Carrey");
	assert(sortat5.at(0).getAn() == 2020);
	assert(sortat5.at(1).getTitlu() == "John Wick");
	assert(sortat5.at(1).getGen() == "actiune");
	assert(sortat5.at(1).getActor() == "Keanu Reeves");
	assert(sortat5.at(1).getAn() == 2010);

	direct_repository.repo_reset();
	Film test3("John Wick", "actiune", "Keanu Reeves", 2010);
	direct_repository.repo_add(test3);
	Film test4("Sonic 2", "aventura", "Jim Carrey", 2010);
	direct_repository.repo_add(test4);

	VectorDinamic<Film> sortat6 = direct_repository.repo_sort(cmpAnGenCrescator);
	assert(sortat6.size() == 2);
	assert(sortat6.at(0).getTitlu() == "John Wick");
	assert(sortat6.at(0).getGen() == "actiune");
	assert(sortat6.at(0).getActor() == "Keanu Reeves");
	assert(sortat6.at(0).getAn() == 2010);
	assert(sortat6.at(1).getTitlu() == "Sonic 2");
	assert(sortat6.at(1).getGen() == "aventura");
	assert(sortat6.at(1).getActor() == "Jim Carrey");
	assert(sortat6.at(1).getAn() == 2010);

	VectorDinamic<Film> sortat7 = direct_repository.repo_sort(cmpAnGenDescrescator);
	assert(sortat7.size() == 2);
	assert(sortat7.at(0).getTitlu() == "Sonic 2");
	assert(sortat7.at(0).getGen() == "aventura");
	assert(sortat7.at(0).getActor() == "Jim Carrey");
	assert(sortat7.at(0).getAn() == 2010);
	assert(sortat7.at(1).getTitlu() == "John Wick");
	assert(sortat7.at(1).getGen() == "actiune");
	assert(sortat7.at(1).getActor() == "Keanu Reeves");
	assert(sortat7.at(1).getAn() == 2010);

}

void Teste::testServiceAddGet()
{
	service.service_add("John Wick", "actiune", "Keanu Reeves", "2010");
	VectorDinamic<Film> test_filme = service.service_get();
	assert(test_filme.at(0).getTitlu() == "John Wick");
	assert(test_filme.at(0).getGen() == "actiune");
	assert(test_filme.at(0).getActor() == "Keanu Reeves");
	assert(test_filme.at(0).getAn() == 2010);
	try
	{
		service.service_add("", "actiune", "Keanu Reeves", "2010");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		service.service_add("John Wick", "a", "Keanu Reeves", "2010");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		service.service_add("John Wick", "actiune", "K", "2010");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		service.service_add("John Wick", "actiune", "Keanu Reeves", "o suta");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		service.service_add("John Wick", "actiune", "Keanu Reeves", "5000");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		service.service_add("John Wick", "actiune", "Keanu Reeves", "150");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}

}

void Teste::testServiceResetLungime() noexcept
{
	size_t lungime = service.service_lungime();
	assert(lungime == 1);
	service.service_reset();
	lungime = service.service_lungime();
	assert(lungime == 0);
}

void Teste::testServiceModify()
{
	service.service_reset();
	service.service_add("John Wick", "actiune", "Keanu Reeves", "2010");
	service.service_modify("Shrek", "horror", "Will Smith", "1984", "1");
	VectorDinamic<Film> test_filme = service.service_get();
	assert(test_filme.at(0).getTitlu() == "Shrek");
	assert(test_filme.at(0).getGen() == "horror");
	assert(test_filme.at(0).getActor() == "Will Smith");
	assert(test_filme.at(0).getAn() == 1984);
	try
	{
		service.service_modify("Sonic 3", "aventura", "Barrack Obama", "1977", "0");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		service.service_modify("", "aventura", "Barrack Obama", "1977", "1");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		service.service_modify("Sonic 3", "a", "Barrack Obama", "1977", "0");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		service.service_modify("Sonic 3", "aventura", "B", "1977", "0");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		service.service_modify("Sonic 3", "aventura", "Barrack Obama", "o mie", "0");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
}


void Teste::testServiceDelete()
{
	service.service_reset();
	service.service_add("John Wick", "actiune", "Keanu Reeves", "2010");
	service.service_add("Shrek", "horror", "Will Smith", "1984");
	service.service_delete("1");
	const size_t lungime = service.service_lungime();
	assert(lungime == 1);
	VectorDinamic<Film> test_filme = service.service_get();
	assert(test_filme.at(0).getTitlu() == "Shrek");
	assert(test_filme.at(0).getGen() == "horror");
	assert(test_filme.at(0).getActor() == "Will Smith");
	assert(test_filme.at(0).getAn() == 1984);
	try
	{
		service.service_delete("0");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		service.service_delete("3");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
}

void Teste::testServiceSearch()
{
	service.service_reset();
	service.service_add("John Wick", "actiune", "Keanu Reeves", "2010");
	Film rezultat = service.service_search("John Wick", "Keanu Reeves");
	assert(rezultat.getTitlu() == "John Wick");
	assert(rezultat.getGen() == "actiune");
	assert(rezultat.getActor() == "Keanu Reeves");
	assert(rezultat.getAn() == 2010);
	rezultat = service.service_search("Sonic 2", "Tom Holland");
	assert(rezultat.getTitlu() == "");
	assert(rezultat.getGen() == "");
	assert(rezultat.getActor() == "");
	assert(rezultat.getAn() == 0);
}

void Teste::testServiceFilter()
{
	service.service_reset();
	service.service_add("John Wick", "actiune", "Keanu Reeves", "2010");
	VectorDinamic<Film> rez = service.service_filter("1", "John Wick");
	assert(rez.size() == 1);
	VectorDinamic<Film> rez2 = service.service_filter("2", "John Wick");
	assert(rez2.size() == 0);
	VectorDinamic<Film> rez3 = service.service_filter("1", "Shrek");
	assert(rez3.size() == 0);
	VectorDinamic<Film> rez4 = service.service_filter("2", "Shrek");
	assert(rez4.size() == 1);
	VectorDinamic<Film> rez5 = service.service_filter("3", "2030");
	assert(rez5.size() == 1);
	VectorDinamic<Film> rez6 = service.service_filter("4", "2030");
	assert(rez6.size() == 0);
	VectorDinamic<Film> rez7 = service.service_filter("3", "2000");
	assert(rez7.size() == 0);
	VectorDinamic<Film> rez8 = service.service_filter("4", "2000");
	assert(rez8.size() == 1);

	try
	{
		rez = service.service_filter("a", "IDK");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		rez = service.service_filter("5", "2010");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
}

void Teste::testServiceSort()
{
	service.service_reset();
	service.service_add("John Wick", "actiune", "Keanu Reeves", "2010");
	service.service_add("Sonic 2", "aventura", "Jim Carrey", "2020");

	VectorDinamic<Film> sortat = service.service_sort("titlu", "crescator");
	assert(sortat.size() == 2);

	assert(sortat.at(0).getTitlu() == "John Wick");
	assert(sortat.at(0).getGen() == "actiune");
	assert(sortat.at(0).getActor() == "Keanu Reeves");
	assert(sortat.at(0).getAn() == 2010);
	assert(sortat.at(1).getTitlu() == "Sonic 2");
	assert(sortat.at(1).getGen() == "aventura");
	assert(sortat.at(1).getActor() == "Jim Carrey");

	assert(sortat.at(1).getAn() == 2020);

	VectorDinamic<Film> sortat2 = service.service_sort("titlu", "descrescator");
	assert(sortat2.size() == 2);
	assert(sortat2.at(0).getTitlu() == "Sonic 2");
	assert(sortat2.at(0).getGen() == "aventura");
	assert(sortat2.at(0).getActor() == "Jim Carrey");
	assert(sortat2.at(0).getAn() == 2020);
	assert(sortat2.at(1).getTitlu() == "John Wick");
	assert(sortat2.at(1).getGen() == "actiune");
	assert(sortat2.at(1).getActor() == "Keanu Reeves");
	assert(sortat2.at(1).getAn() == 2010);

	VectorDinamic<Film> sortat3 = service.service_sort("actor", "crescator");
	assert(sortat3.size() == 2);
	assert(sortat3.at(0).getTitlu() == "Sonic 2");
	assert(sortat3.at(0).getGen() == "aventura");
	assert(sortat3.at(0).getActor() == "Jim Carrey");
	assert(sortat3.at(0).getAn() == 2020);
	assert(sortat3.at(1).getTitlu() == "John Wick");
	assert(sortat3.at(1).getGen() == "actiune");
	assert(sortat3.at(1).getActor() == "Keanu Reeves");
	assert(sortat3.at(1).getAn() == 2010);

	VectorDinamic<Film> sortat4 = service.service_sort("actor", "descrescator");
	assert(sortat4.size() == 2);
	assert(sortat4.at(0).getTitlu() == "John Wick");
	assert(sortat4.at(0).getGen() == "actiune");
	assert(sortat4.at(0).getActor() == "Keanu Reeves");
	assert(sortat4.at(0).getAn() == 2010);
	assert(sortat4.at(1).getTitlu() == "Sonic 2");
	assert(sortat4.at(1).getGen() == "aventura");
	assert(sortat4.at(1).getActor() == "Jim Carrey");
	assert(sortat4.at(1).getAn() == 2020);

	VectorDinamic<Film> sortat5 = service.service_sort("an+gen", "crescator");
	assert(sortat5.size() == 2);
	assert(sortat5.at(0).getTitlu() == "John Wick");
	assert(sortat5.at(0).getGen() == "actiune");
	assert(sortat5.at(0).getActor() == "Keanu Reeves");
	assert(sortat5.at(0).getAn() == 2010);
	assert(sortat5.at(1).getTitlu() == "Sonic 2");
	assert(sortat5.at(1).getGen() == "aventura");
	assert(sortat5.at(1).getActor() == "Jim Carrey");
	assert(sortat5.at(1).getAn() == 2020);

	VectorDinamic<Film> sortat6 = service.service_sort("an+gen", "descrescator");
	assert(sortat6.size() == 2);
	assert(sortat6.at(0).getTitlu() == "Sonic 2");
	assert(sortat6.at(0).getGen() == "aventura");
	assert(sortat6.at(0).getActor() == "Jim Carrey");
	assert(sortat6.at(0).getAn() == 2020);
	assert(sortat6.at(1).getTitlu() == "John Wick");
	assert(sortat6.at(1).getGen() == "actiune");
	assert(sortat6.at(1).getActor() == "Keanu Reeves");
	assert(sortat6.at(1).getAn() == 2010);

	service.service_reset();
	service.service_add("John Wick", "actiune", "Keanu Reeves", "2010");
	service.service_add("Sonic 2", "aventura", "Jim Carrey", "2010");

	VectorDinamic<Film> sortat7 = service.service_sort("an+gen", "crescator");
	assert(sortat7.size() == 2);
	assert(sortat7.at(0).getTitlu() == "John Wick");
	assert(sortat7.at(0).getGen() == "actiune");
	assert(sortat7.at(0).getActor() == "Keanu Reeves");
	assert(sortat7.at(0).getAn() == 2010);
	assert(sortat7.at(1).getTitlu() == "Sonic 2");
	assert(sortat7.at(1).getGen() == "aventura");
	assert(sortat7.at(1).getActor() == "Jim Carrey");
	assert(sortat7.at(1).getAn() == 2010);

	VectorDinamic<Film> sortat8 = service.service_sort("an+gen", "descrescator");
	assert(sortat8.size() == 2);
	assert(sortat8.at(0).getTitlu() == "Sonic 2");
	assert(sortat8.at(0).getGen() == "aventura");
	assert(sortat8.at(0).getActor() == "Jim Carrey");
	assert(sortat8.at(0).getAn() == 2010);
	assert(sortat8.at(1).getTitlu() == "John Wick");
	assert(sortat8.at(1).getGen() == "actiune");
	assert(sortat8.at(1).getActor() == "Keanu Reeves");
	assert(sortat8.at(1).getAn() == 2010);

	try
	{
		sortat = service.service_sort("epic", "descrescator");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}
	try
	{
		sortat = service.service_sort("titlu", "cator");
	}
	catch (ValidatorExceptii)
	{
		assert(true);
	}

}

void Teste::testGetErori()
{
	service.service_reset();
	try
	{
		service.service_add("John Wick", "actiune", "Keanu Reeves", "5000");
	}
	catch (ValidatorExceptii& val)
	{
		assert(true);
		assert(val.getErori() == "Filmul trebuie sa fi aparut intr-un an realist...\n");
	}

}