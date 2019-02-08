/*
* Titre : Menu.h - Travail Pratique #2
* Date : 8 fevrier 2019
* Auteur : Dunkelmann Karl 1893306
*/

#ifndef MENU_H
#define MENU_H
#include <vector>
#include "Plat.h"
#include <fstream>

enum TypeMenu{Matin, Midi, Soir};
const int MAXPLAT = 5;
class Menu {
public:
	// constructeurs
	Menu();
	Menu(string fichier, TypeMenu type);
	Menu(const Menu& menu);

	//destructeur
	~Menu();

	//getters
	int getNbPlats() const;

	//affichage
	friend ostream& operator<<(ostream& o, const Menu& m);

	//methodes en plus
	Plat * trouverPlat(const string& nom) const; // A MODIFIER
	Plat * trouverPlatMoinsCher() const; // Utilise les vecteurs (NE PAS MODIFIER)
	Menu & operator+=(const Plat & plat); // A MODIFIER
	bool lireMenu(const string& fichier);
	/*L’opérateur = qui écrase les attributs du menu par les attributs du menu passé en paramètre 
	et qui renvoie ensuite une référence au menu.*/
	Menu & operator=(const Menu & menu); // A MODIFIER


private :
	// A MODIFIER
	vector<Plat*> listePlats_;
	TypeMenu type_;

};

#endif // !MENU_H
