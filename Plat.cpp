/********************************************/
/* Titre :  main.cpp - Travail Pratique #   */
/* Date :   09 Janvier 2019                 */
/* Auteur : Karl Dunkelmann 1893306         */
/********************************************/


#include "..\Plat.h"

using namespace std;

Plat::Plat()
{
	 nom_ = "" ;
	 prix_ = 0.0;
	 cout_ = 0.0;
}

Plat::Plat(string nom, double prix, double cout)
{
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

string Plat::getNom()
{
	return nom_;
}

double Plat::getPrix()
{
	return prix_;
}

double Plat::getCout()
{
	return cout_;
}

void Plat::setNom(string nom)
{
	nom_ = nom;
}

void Plat::setPrix(double prix)
{
	prix_ = prix;
}

void Plat::afficher()
{
	// juste prix - coût
	cout <<getNom()<<" - " << getPrix() << "$ (" 
		<< getCout() << "$ pour le restaurant)"
	    << endl; 
}
