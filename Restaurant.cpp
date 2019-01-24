/********************************************/
/* Titre :  main.cpp - Travail Pratique #   */
/* Date :   09 Janvier 2019                 */
/* Auteur : Karl Dunkelmann 1893306         */
/********************************************/


#include "..\Restaurant.h"

using namespace std;

Restaurant::Restaurant()
{
	nom_ ;
	chiffreAffaire_ = 0.0;
	momentJournee_;
	menuMatin_;
	menuMidi_;
	menuSoir_;
	capaciteTables_ = 0;
	tables_;
	nbTables_ = 0;

}

Restaurant::Restaurant(string & fichier, string & nom, TypeMenu moment)
{
	nom_ = &nom;
	momentJournee_ = moment;
	ifstream nom

}

void Restaurant::setMoment(TypeMenu moment)
{
	momentJournee_ = moment;
}

string Restaurant::getNom()
{
	return *nom_;
}

TypeMenu Restaurant::getMoment()
{
	return momentJournee_;
}

void Restaurant::lireTable(string & fichier)
{
}

void Restaurant::ajouterTable(int id, int nbPlaces)
{
}

void Restaurant::libererTable(int id)
{
	//delete la table i de du restaurant 
}

void Restaurant::commanderPlat(string & nom, int idTable)
{

}

void Restaurant::placerClients(int nbClients)
{
}

void Restaurant::afficher()
{
	cout << " Voici son menu : " << "\n\t\t" << endl;
	menuMatin_->afficher();
	menuMidi_ ->afficher();
	menuSoir_->afficher();
}
