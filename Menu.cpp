/********************************************/
/* Titre :  Menu.cpp - Travail Pratique #   */
/* Date :   09 Janvier 2019                 */
/* Auteur : Karl Dunkelmann 1893306         */
/********************************************/

#include "..\Menu.h"

using namespace std;


Menu::Menu()
{
	capacite_ = 0;
	listePlats_ [MAXPLAT];
	nbPlats_ = 0;
	type_ = Matin;
}

Menu::Menu(string fichier, TypeMenu type)
{
	/*que faire du fichier */
	ifstream nomFichier(fichier);
	type_ = type;
}

int Menu::getNbPlats()
{
	return nbPlats_;
}

// Une méthode permettant de trouver un plat en passant le nom du plat
Plat * Menu::trouverPlat(string & nom)
{
	// elle retourne un pointeur vers le plat en question 
	for (unsigned int i = 0; i < nbPlats_; i++) {
		if (nom == listePlats_[i]->getNom()) {
			return listePlats_[i];
		}
		else
		{return nullptr;}// pointeur nul si le plat n’est pas trouvé
	}
}

//ajout de plat : une utilisant un plat 
void Menu::ajouterPlat(Plat & plat)
{
	if (nbPlats_ >= capacite_) {
		//int* test = new int[5]; pointeur vers un tableau de 5 entrees
		Plat ** NewListePlats = new Plat*[capacite_ * 2];
		for (unsigned int i = 0; i < MAXPLAT; i++) {
			NewListePlats[i] = listePlats_[i];
		}
		delete listePlats_;
		listePlats_ = NewListePlats;
	}

	else {
		listePlats_[MAXPLAT] = new Plat (plat);
	}
}

//ajout de plat : une utilisant le nom, le prix et le cout
void Menu::ajouterPlat(string & nom, double montant, double cout)
{
	if (nbPlats_ >= capacite_) {
		//int* test = new int[5]; pointeur vers un tableau de 5 entrees
		Plat ** NewListePlats = new Plat*[capacite_*2] ;
		for (unsigned int i = 0; i < MAXPLAT; i++) {
			NewListePlats[i] = listePlats_[i];
		}
		delete listePlats_;
		listePlats_ = NewListePlats;
	}
	else{
		listePlats_[MAXPLAT] = new Plat(nom, montant, cout);
	}
}

bool Menu::lireMenu(string & fichier)
{
	ifstream nomFichier(fichier);
	if (nomFichier.fail()) {
		return false;
	} else { 
		return true; 
	}
}		

void Menu::afficher()
{
	cout << type_ << " :\n\t\t"<< endl;
	for (unsigned int i=0;i < nbPlats_;i++){//nbplat pas sur
		listePlats_[i]->afficher();
	}
}