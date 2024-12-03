

// Programme principal servant a executer les tests

#include "TP5_Test.h"

//#define INTERACTIF

int main(int argc, char** argv)
{
	TP5_Test lesTests;

	if (lesTests.testVisitor() == TP5_Test::RESULTAT::ECHEC)
	{
		std::cout << "Erreur dans les tests du Patron Visiteur" << std::endl << std::endl;
	}
#ifdef INTERACTIF
	else if (lesTests.interactivTestCommand() == TP5_Test::RESULTAT::ECHEC)
#else
	else if (lesTests.testCommand() == TP5_Test::RESULTAT::ECHEC)
#endif
	{
		std::cout << "Erreur dans les tests du Patron Commande" << std::endl << std::endl;
	}
	else
	{
		std::cout << "Tous les tests se sont executes avec SUCCES" << std::endl << std::endl;
	}
}