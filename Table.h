/*
* Titre : Table.h - Travail Pratique #2
* Date : 8 fevrier 2019
* Auteur : Dunkelmann Karl 1893306
*/

#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include "Plat.h"
const  int MAXCAP = 5;
class Table {
public:
	///constructeurs
	Table();
	Table(int id, int nbPlaces);

	///destructeur
	~Table();

	///getters
	int getId() const;
	int getNbPlaces() const;
	int getnbClientATable() const;
	bool estPleine() const;
	bool estOccupee() const;

	///setters
	void libererTable(); // A MODIFIER
	void placerClient(int nbClients);
	void setId(int id);

	///autres methodes
	void commander(Plat* plat); // A MODIFIER
	double getChiffreAffaire() const;

	///affichage
	friend ostream& operator<<(ostream& o, const Table& t);


private :
	//A MODIFIER
	int capacite_;
	
	vector<Plat*> commande_;
	int nbPlats_;
	int id_;
	int nbPlaces_;
	int nbClientsATable_;
};
#endif // !TABLE_H
