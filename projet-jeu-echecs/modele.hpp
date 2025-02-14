/*
* Fichier contenant les classes du modele du projet final et leurs fonctions.
* file classes_projet.hpp
*/
#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

static constexpr int blanc = 0;
static constexpr int noir = 1;
static constexpr int nLignes = 8;
static constexpr int nColonnes = 8;
static constexpr int avantDerniereCase = 7;
static constexpr int nRoi = 2;
static constexpr int zeroEnASCII = 48;

namespace modele {

	class Observateur {
	public:
		virtual ~Observateur() {}
		virtual void miseAJourVue() = 0;
	};

	class DeplacementStrategie {
	public:
		virtual ~DeplacementStrategie() = default;
		virtual bool mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const = 0;
	};


	class ConstructionInvalide : public std::logic_error {
	public:
		using std::logic_error::logic_error;
	};

	class Piece {
	public:
		Piece(bool couleur, int positionLigne, int positionColonne, std::unique_ptr<DeplacementStrategie> strategieDeplacement);
		virtual ~Piece() = default;
		bool setPosition(int positionLigne, int positionColonne);
		std::pair<int, int> getPosition() const;
		bool getCouleur() const;
		bool mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const {
			return strategieDeplacement_->mouvementValide(positionLigne, positionColonne, positionLigneVoulue, positionColonneVoulue);
		}

	protected:
		int positionLigne_ = 0;
		int positionColonne_ = 0;
		bool couleurNoire_; //0 = blanc, 1 = noir
		std::unique_ptr<DeplacementStrategie> strategieDeplacement_;
	};

	class MouvementValidePion : public DeplacementStrategie {
	private:
		bool couleurNoire_;

	public:
		MouvementValidePion(bool couleurNoire) : couleurNoire_(couleurNoire) {}

		bool mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const override;
	};

	class MouvementValideRoi : public DeplacementStrategie {
	public:
		bool mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const override;
	};

	class MouvementValideReine : public DeplacementStrategie {
	public:
		bool mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const override;
	};

	class MouvementValideTour : public DeplacementStrategie {
	public:
		bool mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const override;
	};

	class MouvementValideFou : public DeplacementStrategie {
	public:
		bool mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const override;
	};

	class MouvementValideCavalier : public DeplacementStrategie {
	public:
		bool mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const override;
	};

	class Roi : public Piece {
	public:
		Roi(bool couleur, int positionLigne, int positionColonne);
		~Roi();
		mutable bool aDejaBouge = false;
	private:
		bool mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const {
			if (strategieDeplacement_->mouvementValide(positionLigne, positionColonne, positionLigneVoulue, positionColonneVoulue)) {
				aDejaBouge = true;
				return true;
			}
			return false;
		}
		

	private:
		static int compteur_;
	};

	class Cavalier : public Piece {
	public:
		Cavalier(bool couleur, int positionLigne, int positionColonne);
	};

	class Tour : public Piece {
	public:
		Tour(bool couleur, int positionLigne, int positionColonne);
	};

	class Pion : public Piece {
	public:
		Pion(bool couleur, int positionLigne, int positionColonne);
	};


	class Fou : public Piece {
	public:
		Fou(bool couleur, int positionLigne, int positionColonne);
	};

	class Reine : public Piece {
	public:
		Reine(bool couleur, int positionLigne, int positionColonne);
	};

	class PieceFactory {
	public:
		static Piece* creerPiece(char type, bool couleur, int positionLigne, int positionColonne) {
			switch (type) {
			case 'r': return new Roi(couleur, positionLigne, positionColonne);
			case 'c': return new Cavalier(couleur, positionLigne, positionColonne);
			case 't': return new Tour(couleur, positionLigne, positionColonne);
			case 'f': return new Fou(couleur, positionLigne, positionColonne);
			case 'q': return new Reine(couleur, positionLigne, positionColonne);
			case 'p': return new Pion(couleur, positionLigne, positionColonne);
			case 'R': return new Roi(couleur, positionLigne, positionColonne);
			case 'C': return new Cavalier(couleur, positionLigne, positionColonne);
			case 'T': return new Tour(couleur, positionLigne, positionColonne);
			case 'F': return new Fou(couleur, positionLigne, positionColonne);
			case 'Q': return new Reine(couleur, positionLigne, positionColonne);
			case 'P': return new Pion(couleur, positionLigne, positionColonne);
			default: return nullptr; // Type de pièce invalide
			}
		}
	};

	class Echiquier {
	public:
		~Echiquier();
		static Echiquier& getInstance();
		static void libererInstance();
		Piece* getPiece(int ligne, int colonne);
		void modifierEchiquier(std::string nomFichier); //place des pieces aux bonnes position selon le fichier passe en parametre
		bool effectuerMouvement(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY);
		void ajouterObservateur(Observateur* observateur);
		void notifierObservateurs();

	private:
		static Echiquier* instance_;
		Piece* echiquier_[nLignes][nColonnes]; // nLignes, nColonnes = 8, car jeu d'échecs a 64 cases
		std::vector<Observateur*> observateurs;
		Echiquier(); // construit un echiquier avec la position des pieces standard de début de partie
		void copieProfonde(Piece* nouveauEchiquier[nLignes][nColonnes], Piece* echiquier[nLignes][nColonnes]);
		bool pieceEnChemin(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY);
		bool echangerPiece(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY);
		bool miseEnEchec(bool couleur);
		void promotionEnReine();
		bool effectuerRoc(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY);
		void grandRoc(int positionX);
		void petitRoc(int positionX);
		bool enCheminPion(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY);
		bool enCheminTour(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY);
		bool enCheminFou(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY);
		bool enCheminReine(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY);
		std::pair<int, int> getPositionRoi(bool couleur);
	};
}
