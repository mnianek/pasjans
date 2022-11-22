#pragma once
class cards
{
public:
	int repC = 5;			//zmienna sto³u (karty w wierszu)
	struct rozklad {		//stworzenie zmiennej przechowujacej: polozenie karty i czy jest odkryta(true) czy zakryta (false)
		int numKr;
		bool view = false;
	};
	
	struct rozklad karta[7][7];
	char wyglad[44][130] = { ' '};
	void create_cards();	//tworzenie talii kart
	void table();			//storzenie sto³u(bez stosów)
	void sprawdz();
};

