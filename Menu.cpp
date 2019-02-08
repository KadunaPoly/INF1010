/*
* Titre : Menu.cpp - Travail Pratique #2
* Date : 8 fevrier 2019
* Auteur : Dunkelmann Karl 1893306
*/
#include "Menu.h"

//constructeurs

Menu::Menu() {
	type_ = Matin;
}

Menu::Menu(string fichier, TypeMenu type) {
	type_ = type;

	//lecture du fichier -- creation du menu
	lireMenu(fichier);
}

Menu::Menu(const Menu & menu):type_(menu.type_), listePlats_(menu.listePlats_.capacity())
{
	for (unsigned int i = 0; i < menu.listePlats_.size();i++) {
		listePlats_[i] = new Plat(*(menu.listePlats_[i]));
	}
}

//destructeur
Menu::~Menu() {
	// A MODIFIER
	for (int i = 0; i < listePlats_.size(); i++)
	{
		delete listePlats_[i];
		listePlats_[i] = nullptr;
	}
}

//getters

int Menu::getNbPlats() const {
	return listePlats_.size();
}

//autres methodes

//L’opérateur += (remplace la méthode ajouterPlat(const Plat& plat)).
Menu & Menu::operator+=(const Plat & plat){
	listePlats_.push_back(new Plat(plat));
	return *this;
}


bool Menu::lireMenu(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (!file) {
		//cout << "ERREUR : le fichier n'a pas pu etre ouvert" << endl;
		return false;
	}
	else {
		string type;
		switch (type_) {
		case Matin :
			type = "-MATIN";
			break;
		case Midi :
			type = "-MIDI";
			break;
		case Soir :
			type = "-SOIR";
			break;
		}
		string ligne;

		string nom;

		string prixString;
		double prix;

		string coutString;
		int cout;


		// lecture
		while (!file.eof()) {
			getline(file, ligne);
			//trouver le bon type de menu (section)
			if (ligne == type){
				//commencer a lire -- s'arrete si fin du fichier ou encore si on arrive a une nouvelle section du menu
				getline(file, ligne);
				int curseur;
				while (ligne[0] != '-' && !file.eof()) {
					//trouver le nom
					for (int i = 0; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						nom += ligne[i];
					}
					//trouver le prix

					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						prixString += ligne[i];

					}
					//passer le prixString en double --- indice dans l'enonce
					prix = stof(prixString.c_str());

					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ')
							break;
						coutString += ligne[i];
					}

					cout =int( stof(coutString.c_str()));

				/* utilisation de la dereferecnce de this pour avoir lobjet sur lequel 
					on travail actuellement, en loccurence un menu */
					*this +=(Plat(nom, prix, cout));
					nom = "";
					prixString = "";
					coutString = "";

					getline(file, ligne);
				}
			}
		}

		Plat p;

		p.getCout();

		file.close();
		return true;
	}
}

Menu & Menu::operator=(const Menu & menu)
{
	// TODO: L’opérateur = qui écrase les attributs du menu par 
		//   les attributs du menu passé en paramètre et qui renvoie ensuite une référence au menu.
	for (unsigned int i = 0; i < listePlats_.size(); i++) { 
		 listePlats_[i] = menu.listePlats_[i];
		}
	 type_ = menu.type_;
	 return *this;

}

Plat * Menu::trouverPlatMoinsCher() const
{
	Plat minimum(*listePlats_[0]);
	int found = -1;

	for (unsigned i = 0; i < listePlats_.size(); ++i)
	{
		if (*listePlats_[i] < minimum)
		{
			minimum = *listePlats_[i];
			found = i;
		}
	}

	return listePlats_[found];

}

Plat* Menu::trouverPlat(const string& nom) const {
	for (int i = 0; i <listePlats_.size(); i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	return nullptr;
}

ostream & operator<<(ostream & o, const Menu & m)
{
	for (int i = 0; i < m.listePlats_.size(); i++) {
		o << "\t" << *m.listePlats_[i];
	}

	return o;
}
