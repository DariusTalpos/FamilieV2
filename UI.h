#pragma once
#include "Service.h"
class UI
{
private:
	Service& service;
public:
	/*
	* Constructor UI
	* @param service - referinta la un obiect de tip service
	*/
	UI(Service& service) noexcept: service{service} 
	{
		//if (this->service == nullptr)
	};

	/*
	* Ruleaza aplcatia
	*/
	void run();
	/*
	* Rezolva prima cerinta a aplicatiei
	*/
	void ui_add();
	/*
	* Rezolva a doua cerinta a aplicatiei
	*/
	void ui_modify();
	/*
	* Rezolva a treia cerinta a aplicatiei
	*/
	void ui_delete();
	/*
	* Rezolva a patra cerinta a aplicatiei
	*/
	void ui_search();
	/*
	* TBA
	*/
	void ui_filter();
	/*
	* TBA
	*/
	void ui_sort();
	/*
	* Afiseaza toate filmele din vectorul dat
	*/
	void ui_print(VectorDinamic<Film> lista);
	/*
	* goleste buffer-ul
	*/
	void golire_buffer() noexcept;
};