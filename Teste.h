#pragma once
#include "Service.h"
class Teste
{
private:
	Service& service;
	Repository& direct_repository;
public:
	Teste(Service& service, Repository& direct_repository) noexcept: service{ service }, direct_repository{direct_repository}{};
	void teste();
	void testeService();
	void testeRepository();
	void testeDomain();

	void testServiceAddGet();
	void testServiceResetLungime() noexcept;
	void testServiceModify();
	void testServiceDelete();
	void testServiceSearch();
	void testServiceFilter();
	void testServiceSort();

	void testRepositoryAddGet();
	void testRepositoryResetLungime() noexcept;
	void testRepositoryModify();
	void testRepositoryDelete();
	void testRepositorySearch();
	void testRepositoryFilterTitlu();
	void testRepositoryFilterAn();
	void testRepositorySort();
	
	void testDomainGetSetTitlu();
	void testDomainGetSetGen();
	void testDomainGetSetActor();
	void testDomainGetSetAn();

	void testGetErori();
};