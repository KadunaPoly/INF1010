/*
* Titre : Plat.h - Travail Pratique #2
* Date : 8 fevrier 2019
* Auteur : Dunkelmann Karl 1893306
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std;

class Plat {
public:
	/// constructeurs
	Plat();
	Plat(string nom, double prix, double cout);

	///getters
	string getNom() const;
	double getPrix() const;
	double getCout() const;

	///setters
	void setNom(string nom);
	void setPrix(double prix);

	///methodes en plus
	//affichage
	friend ostream& operator<<(ostream& o, const Plat& p);
	//L’opérateur < qui compare 2 plats selon leur prix de vente.
	friend bool & operator<(const Plat& p1, const Plat& p2);
private:
	string nom_;
	double prix_;
	double cout_;

};

#endif // !PLAT_H
