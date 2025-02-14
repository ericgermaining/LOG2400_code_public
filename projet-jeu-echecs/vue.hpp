/*
* Fichier contenant les classes de la Vue du projet final et leurs fonctions.
* file    vue.hpp
*/
#pragma warning(push, 0)
#include <QApplication>
#include <QPushButton>
#include <Qwidget.h>
#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QColor>
#include <QPalette>
#include <QStack>
#include <QGridLayout>
#pragma pop()
#include "modele.hpp"

namespace vue {

	class Case : public QPushButton, public modele::Observateur {
		Q_OBJECT
	public:
		Case(QWidget* parent, int positionX, int positionY);
		~Case() override = default;
		std::pair<int, int> getPosition();
		void couleurNormal(int ligne, int colonne);
		void couleurCaseSelectionne();
		void initialiserTaille(QFont font);
		void mettreAJourCouleur(QColor couleur);
		void miseAJourVue() override;

	private:
		int positionX_;
		int positionY_;
	};

	class VueEchiquier : public QMainWindow, public modele::Observateur {
		Q_OBJECT
	public:
		VueEchiquier(QWidget* parent, modele::Echiquier& echiquier);
		~VueEchiquier() override = default;
		void miseAJourVue() override;

	protected slots:
		void caseSelectionnee();

	private:
		modele::Echiquier& echiquier_;
		bool premierClickFait_ = false;
		bool tourDesBlancs_ = true;
		std::pair<int, int> positionChoisie_; // position sur l echiquier de la piece qu on veutb bouger
		std::pair<int, int> positionVoulue_; // position ou on deplace la piece prealablement choisie
		Case* matriceCases_[nLignes][nColonnes];
		QPushButton* creerCase(QGridLayout* gridLayout, QString nomCase, int positionY);
		void initialiserPartie(std::string fichier);
		void identifierPiece(QChar& pieceVue, int colonne, int ligne) const;
		void ajouterCase(Case* casePtr, int ligne, int colonne);
		bool tourATour();
		void mettrePieces();
	};
}
