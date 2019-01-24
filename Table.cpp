/********************************************/
/* Titre :  main.cpp - Travail Pratique #   */
/* Date :   09 Janvier 2019                 */
/* Auteur : Karl Dunkelmann 1893306         */
/********************************************/


#include "Table.h"

using namespace std;


Table::Table()
{
	commande_;
	capacite_ = 0;
	nbPlats_ = 0;
	id_ = -1;
	nbPlaces_ = 1;
	occupee_ = false;
}

Table::Table(int id, int nbPlaces)
{
	id_ = id;
	nbPlaces_ = nbPlaces;
	capacite_ = nbPlaces;
	commande_ = new Plat*[capacite_];
	// Menu menu;

}

int Table::getId()
{
	return id_;
}

int Table::getNbPlaces()
{
	return nbPlaces_;
}

bool Table::estOccupee()
{
	return occupee_;
}

void Table::libererTable()
{
	occupee_ = false;

}

void Table::placerClient()
{
}

void Table::setId(int id)
{
	id_ = id;
}

void Table::commander(Plat * plat)
{
	if (nbPlats_ > capacite_) {
		Plat** commandeTemp = new Plat*[capacite_];
		for (int i = 0; i < capacite_; i++) {
			commandeTemp[i] = commande_[i];
		}
		capacite_ = 2 * capacite_;
		commande_ = new Plat*[capacite_];
		for (int j = 0; j < capacite_; j++) {
			commande_[j] = commandeTemp[j];
		}
		delete[] commandeTemp;
		commandeTemp = NULL;
	}

	commande_[nbPlats_] = plat;
	nbPlats_++;

}

double Table::getChiffreAffaire()
{
	double chiffreTable = 0.00;

	for (int k = 0; k < nbPlats_; k++) {
		chiffreTable = chiffreTable + (commande_[k]->getPrix() - commande_[k]->getPrix());
	}
	
	return chiffreTable;
}

void Table::afficher()
{
	cout << "La table numéro " << id_ << " est ";
	if (occupee_ == false) {
		cout << "libre." << endl << endl;
	}
	else {
		cout << "occupée. Voici la commande passée par les clients :" << endl;

		for (int i = 0; i < nbPlats_; i++) {
			commande_[i]->afficher();
		}
	}

}
