/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 8 fevrier 2019
* Auteur : Dunkelmann Karl 1893306
*/

#include "Restaurant.h"

//constructeurs
Restaurant::Restaurant() {
	nom_ = new string("Inconnu");

	chiffreAffaire_ = 0;

	momentJournee_ = Matin;

	menuMatin_ = new Menu("menu.txt", Matin);
	menuMidi_ = new Menu("menu.txt", Midi);
	menuSoir_ = new Menu("menu.txt",  Soir);
}
Restaurant::Restaurant(const Restaurant& r1):nom_(r1.nom_),chiffreAffaire_(r1.chiffreAffaire_),momentJournee_(r1.momentJournee_), tables_(r1.tables_.capacity()) {

	menuMatin_ = new Menu(*(r1.menuMatin_));
	menuMidi_ = new Menu(*(r1.menuMidi_));
	menuSoir_ = new Menu(*(r1.menuSoir_));
	for (unsigned int i = 0; i < r1.tables_.size(); i++) {
		tables_[i] = new Table(*(r1.tables_[i]));
	}

}

Restaurant::Restaurant(const string& fichier,  const string& nom, TypeMenu moment) {
	nom_ = new string(nom);

	chiffreAffaire_ = 0;

	momentJournee_ = moment;

	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier,  Midi);
	menuSoir_ = new Menu(fichier,  Soir);

	lireTable(fichier);
}
//destructeur
Restaurant::~Restaurant() {
	delete nom_;
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;

	//A MODIFIER
	for (int i = 0; i < tables_.size(); i++)
	{
		delete tables_[i];
		tables_[i]=nullptr;
	}
}


//setter

void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}
 void  Restaurant::setNom(const string & nom) const{
	*nom_ = nom;
}
//getters
string Restaurant::getNom() const {
	return *nom_;
}

TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}

//autres methodes
bool & operator<(const Restaurant& r1, const Restaurant& r2)
{	
	bool moinsRentable = false;
	if (r1.chiffreAffaire_ < r2.chiffreAffaire_) {
		moinsRentable = true;
	}
	else moinsRentable = false;

	return moinsRentable;

}

void Restaurant::libererTable(int id) {
	for (int i = 0; i < tables_.size(); i++) {
		if (id == tables_[i]->getId()) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->libererTable();
		}
	}
}

void Restaurant::commanderPlat(const string& nom, int idTable) {
	Plat* plat = nullptr;
	int index;
	for (int i = 0; i < tables_.size(); i++) {
		if (idTable == tables_[i]->getId()) {
			index = i;
			switch (momentJournee_) {
			case Matin :
				plat = menuMatin_->trouverPlat(nom);
				break;
			case Midi :
				plat = menuMidi_->trouverPlat(nom);
				break;
			case Soir :
				plat = menuSoir_->trouverPlat(nom);
				break;
			}
		}
	}
	if (plat != nullptr && tables_[index]->estOccupee()) {
		tables_[index]->commander(plat);
	}
	else cout << "Erreur : table non occupee ou plat introuvable" << endl;
}

void Restaurant::lireTable(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (file) {
		string ligne;

		string idString;
		int id;

		string nbPersonnesString;
		int nbPersonnes;

		int curseur;
		while (!file.eof()) {
			getline(file, ligne);
			if (ligne == "-TABLES") {
				while (!file.eof()) {
					getline(file, ligne);
					for (int i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						idString += ligne[i];
					}

					id = stoi(idString);

					nbPersonnesString = ligne.substr(curseur + 1);
					nbPersonnes = stoi(nbPersonnesString);

					*this += (Table(id, nbPersonnes));
					nbPersonnesString = "";
					idString = "";
				}
			}
		}
		file.close();
	}
}



Restaurant & Restaurant::operator+=(const Table & table)
{
	 tables_.push_back(new Table(table));
	 return *this;
}
Restaurant & Restaurant::operator=(const Restaurant & r) {
	for (unsigned int i = 0; i < r.tables_.size(); i++) {
		tables_[i]= r.tables_[i];
	}
	 nom_ = r.nom_;
	 chiffreAffaire_ = r.chiffreAffaire_;
	 momentJournee_ = r.momentJournee_;
	 return *this;
}

void Restaurant::placerClients(int nbClients) {
	int indexTable = -1;
	int minimum = 100;


	for (int i = 0; i < tables_.size(); i++) {
		if (tables_[i]->getNbPlaces() >= nbClients && !tables_[i]->estOccupee() && tables_[i]->getNbPlaces() < minimum) {
			indexTable = i;
			minimum = tables_[i]->getNbPlaces();
		}
	}
	if (indexTable == -1) {
		cout << "Erreur : il n'y a plus/pas de table disponible pour le client. " << endl;
	}else
	tables_[indexTable]->placerClient(nbClients);
}

ostream & operator<<(ostream & o, const Restaurant & r)
{
	o << "Le restaurant " << r.getNom();
	if (r.chiffreAffaire_ != 0)
		o << " a fait un chiffre d'affaire de : " << r.chiffreAffaire_ << "$" << endl;
	else
		o << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
	o << "-Voici les tables : " << endl;
	for (int i = 0; i < r.tables_.size(); i++) {
		o << "\t" << *r.tables_[i]<< endl;
	}
	o << endl;


	o << "-Voici son menu : " << endl;
	o << "Matin : " << *r.menuMatin_;
	o << "Midi : " << *r.menuMidi_;
	o << "Soir : " << *r.menuSoir_;

	return o;
}
