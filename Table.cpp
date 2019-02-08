/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 8 fevrier 2019
* Auteur : Dunkelmann Karl 1893306
*/

#include "Table.h"

//constructeurs
Table::Table() {
	capacite_ = MAXCAP;
	nbPlats_ = 0;
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

Table::Table(int id, int nbPlaces) {
	capacite_ = MAXCAP;
	vector<Plat*> commande_(capacite_);
	nbPlats_ = 0;
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
}

//destructeur
//rien a faire le pointeur se vide tout seul a la fin du programme
Table::~Table() {
	//delete[] commande_;
}

//getters
int Table::getId() const {
	return id_;
}

int Table::getNbPlaces() const {
	return nbPlaces_;
}

int Table::getnbClientATable() const
{
	return nbClientsATable_;
}

bool Table::estPleine() const {
	return nbPlaces_==0;
}

bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

//setters
void Table::setId(int id) {
	id_ = id;
}

void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	//A MODIFIER
	for (int i = 0; i < commande_.size(); i++) {
		commande_[i] = nullptr;
	}
	nbPlats_ = 0;
}

void Table::placerClient(int nbClients) {
	nbClientsATable_ = nbClients;
	nbPlaces_ -= nbClients;
}

//autres methodes
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
}

double Table::getChiffreAffaire() const {
	double chiffre = 0;
	for (int i = 0; i < commande_.size(); i++) {
		chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffre;
}

//affichage
ostream & operator<<(ostream & o, const Table & t)
{
	o << "La table numero " << t.id_;
	if (t.estOccupee()) {
		o << " est occupee. ";
		if (t.commande_.size() != 0) {
			o << "Voici la commande passee par les clients : " << endl;
			for (int i = 0; i < t.commande_.size(); i++) {
				o << "\t" << *t.commande_[i];
			}
		}
		else
			o << "Mais ils n'ont rien conmmande pour l'instant. " << endl;
	}
	else {
		o << " est libre. " << endl;
	}

	return o;
}
