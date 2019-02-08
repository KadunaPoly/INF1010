/*
* Titre : Restaurant.h - Travail Pratique #2
* Date : 8 fevrier 2019
* Auteur : Dunkelmann Karl 1893306
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <vector>
#include "Table.h"
#include "Menu.h"
const int INTTABLES = 6;
class Restaurant {
public:
	//constructeurs
	Restaurant();
	Restaurant(const string& fichier, const string& nom, TypeMenu moment);
	Restaurant(const Restaurant& r1);

	//destructeur
	~Restaurant();

	//setters
	void setMoment(TypeMenu moment);
	void setNom(const string& nom) const;
	//getters
	string getNom() const;
	TypeMenu getMoment() const;

	//Autres methodes
	void lireTable(const string& fichier);
	Restaurant & operator+=(const Table & table);
	friend bool& operator<(const Restaurant& r1, const Restaurant& r2);
	Restaurant & operator=(const Restaurant & r);

	void libererTable(int id);
	friend ostream& operator<<(ostream& o, const Restaurant& r);
	void commanderPlat(const string& nom, int idTable);

	void placerClients(int nbClients);




private:
	string * nom_;

	double chiffreAffaire_;
	TypeMenu momentJournee_;

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_;
	Menu* menuMidi_;
	Menu* menuSoir_;

	// A MODIFIER

	//liste des tables
	vector<Table*> tables_;

};
#endif // !RESTAURANT_H
bool& operator<(const Restaurant& r1, const Restaurant& r2);
