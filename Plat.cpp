/*
* Titre : Plat.cpp - Travail Pratique #2
* Date : 8 fevrier 2019
* Auteur : Dunkelmann Karl 1893306
*/

#include "Plat.h"

//constructeurs
Plat::Plat() {
	nom_ = "Inconnu";
	prix_ = 0;
	cout_ = 0;
}

Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}
//getters

string Plat::getNom() const {
	return nom_;
}

double Plat::getPrix() const {
	return prix_;
}

double Plat::getCout() const {
	return cout_;
}
//setters
void Plat::setNom(string nom) {
	nom_ = nom;
}

void Plat::setPrix(double prix) {
	prix_ = prix;
}


//methodes en plus

ostream & operator<<(ostream & o, const Plat & p)
{
	return o << p.getNom() << "- " << p.getPrix() << "$ (" 
		<< p.getCout() << "$ pour le restaurant)" << "\n"<< endl;

	return o;
}

//return bool ou return un plat
bool & operator<(const Plat & p1, const Plat & p2)
{
	bool moinsCher = false;
	// TODO: comparer le plat des prix
	if (p1.getPrix() < p2.getPrix()) 
		moinsCher = true;
	else moinsCher =  false;

	return moinsCher;

}
