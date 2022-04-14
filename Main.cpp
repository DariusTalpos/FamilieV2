#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "UI.h"
#include "Teste.h"
#include <iostream>
using namespace std;
void testare_program()
{
	Repository test_repository, direct_repository;
	ValidatorFilme test_val;
	Service test_service{ test_repository, test_val };
	Teste test{ test_service, direct_repository };
	test.teste();
	cout << "Teste efectuate cu succes!\n\n";
}
void pornire_program() noexcept
{
	ValidatorFilme val;
	Repository repository;
	Service service{ repository, val };
	UI ui{ service };
	ui.run();
}
int main()
{
	testare_program();
	pornire_program();
	_CrtDumpMemoryLeaks();
	return 0;
}