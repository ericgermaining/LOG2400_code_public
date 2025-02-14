/*
* Fichier contenant l'implementation des methode des classes de la Vue du projet final.
* file   vue.cpp
*/
#include "vue.hpp"
# include "modele.hpp"

static constexpr int tailleCase = 100;
static constexpr int tailleTexte = 45;
static constexpr int tailleCases = 120;

namespace vue {

	// methodes de la classe Case

	Case::Case(QWidget* parent, int positionX, int positionY) : QPushButton(parent) {
		positionX_ = positionX;
		positionY_ = positionY;
	}

	std::pair<int, int> Case::getPosition() {
		return { positionX_, positionY_ };
	}

	void Case::mettreAJourCouleur(QColor couleur) {
		QPalette couleurVue = palette();
		couleurVue.setColor(QPalette::Button, couleur);
		setPalette(couleurVue);
		miseAJourVue();
	}

	void Case::couleurNormal(int ligne, int colonne) {
		QColor couleur;
		(ligne % 2) == (colonne % 2) ? couleur = QColor(200, 200, 229) : couleur = QColor(255, 255, 255); // violet et blanc
		mettreAJourCouleur(couleur);
	}

	void Case::couleurCaseSelectionne() {
		QColor couleur = QColor(255, 190, 125); // orange
		mettreAJourCouleur(couleur);
	}

	void Case::miseAJourVue() {
		setAutoFillBackground(true);
		setFlat(true);
	}

	void Case::initialiserTaille(QFont font) {
		font.setPointSize(tailleTexte);
		setFont(font);
		QSize taille = QSize(tailleCase, tailleCase);
		setFixedSize(taille);
	}


	// methodes de la classe VueEchiquier

	VueEchiquier::VueEchiquier(QWidget* parent, modele::Echiquier& echiquier) : echiquier_(echiquier), QMainWindow(parent) {

		auto widget = new QWidget(this);
		auto layout = new QVBoxLayout(widget);
		auto gridLayout = new QGridLayout();

		layout->addLayout(gridLayout);
		gridLayout->setVerticalSpacing(0);
		gridLayout->setHorizontalSpacing(0);

		for (int ligne = 0; ligne < nLignes; ligne++) 
		{
			for (int colonne = 0; colonne < nColonnes; colonne++)
			{
				Case* casePtr = new Case(this, colonne, ligne);

				QFont font = VueEchiquier::font();
				casePtr->initialiserTaille(font);
				casePtr->couleurNormal(ligne, colonne);

				gridLayout->addWidget(casePtr, nColonnes - 1 - colonne, ligne);
				ajouterCase(casePtr, ligne, colonne);

				connect(casePtr, &QPushButton::clicked, this, &VueEchiquier::caseSelectionnee);
			}
		}
		setCentralWidget(widget);
		setWindowTitle("Jeu d'Echec");
		initialiserPartie("PartieStandard.txt");
	}

	QPushButton* VueEchiquier::creerCase(QGridLayout* gridLayout, QString nomCase, int positionY) {
		QPushButton* casePtr = new QPushButton(nomCase);
		gridLayout->addWidget(casePtr, positionY, nColonnes + 1);
		casePtr->setFixedSize(QSize(tailleCases, tailleCase));
		return casePtr;
	}

	void VueEchiquier::identifierPiece(QChar & pieceVue, int colonne, int ligne) const {
		modele::Piece* piece = echiquier_.getPiece(colonne, ligne);
		if (piece)
		{
			bool couleur = piece->getCouleur();
			if (dynamic_cast<modele::Roi*>(piece)) {
				couleur ? pieceVue = QChar(0x265A) : pieceVue = QChar(0x2654); // unicode de roi blanc ou noir
			}
			else if (dynamic_cast<modele::Tour*>(piece)) {
				couleur ? pieceVue = QChar(0x265C) : pieceVue = QChar(0x2656); // unicode de tour blanche ou noire
			}
			else if (dynamic_cast<modele::Cavalier*>(piece)) {
				couleur ? pieceVue = QChar(0x265E) : pieceVue = QChar(0x2658); // unicode de cavalier blanc ou noir
			}
			else if (dynamic_cast<modele::Fou*>(piece)) {
				couleur ? pieceVue = QChar(0x265D) : pieceVue = QChar(0x2657); // unicode de fou blanc ou noir
			}
			else if (dynamic_cast<modele::Pion*>(piece)) {
				couleur ? pieceVue = QChar(0x265F) : pieceVue = QChar(0x2659); // unicode de pion blanc ou noir
			}
			else if (dynamic_cast<modele::Reine*>(piece)) {
				couleur ? pieceVue = QChar(0x265B) : pieceVue = QChar(0x2655); // unicode de reine blanc ou noir
			}
		}
	}

	void VueEchiquier::ajouterCase(Case * casePtr, int ligne, int colonne) {
		matriceCases_[ligne][colonne] = casePtr;

		for (int ligne = 0; ligne < nLignes; ++ligne) {
			for (int colonne = 0; colonne < nColonnes; ++colonne) {
				echiquier_.ajouterObservateur(matriceCases_[ligne][colonne]);
			}
		}
	}

	// methode appellee lors l'usager selectionne une case
	void VueEchiquier::caseSelectionnee() {

		Case* caseSelectionnee = qobject_cast<Case*>(sender());
		if (premierClickFait_) {
			premierClickFait_ = false;
			matriceCases_[positionChoisie_.second][positionChoisie_.first]->couleurNormal(positionChoisie_.first, positionChoisie_.second);
			positionVoulue_ = caseSelectionnee->getPosition();
			miseAJourVue();
		}
		else {
			positionChoisie_ = caseSelectionnee->getPosition();
			if (tourATour()) {
				premierClickFait_ = true;
				caseSelectionnee->couleurCaseSelectionne();
			}
		}
	}

	bool VueEchiquier::tourATour() {
		modele::Piece* piece = echiquier_.getPiece(positionChoisie_.first, positionChoisie_.second);
		if (piece) { // si cette position de l echiquier est vide cela retourne un nullptr, equivalent donc a false
			bool couleur = piece->getCouleur(); // retourne faux si blanc et vrai si noir
			if (!couleur == tourDesBlancs_) { // on inverse donc la variable couleur pour savoir si c est le tour de la couleur selectionnee de jouer (blanc est 0 selon limplementation faites plus tot alors que si cest au tour des blancs, la variable tourDesBlancs est a true)
				tourDesBlancs_ = !tourDesBlancs_;
				return true;
			}
			std::cout << "Ce n'est pas à votre tour de jouer." << std::endl;
			return false;
		}
		else {
			std::cout << "Case vide sélectionnée." << std::endl;
			return false;
		}
	}

	void VueEchiquier::mettrePieces() {
		for (int ligne = 0; ligne < nLignes; ligne++) {
			for (int colonne = 0; colonne < nColonnes; colonne++)
			{
				QChar pieceVue;
				identifierPiece(pieceVue, colonne, ligne);
				matriceCases_[ligne][colonne]->setText(pieceVue);
				matriceCases_[ligne][colonne]->couleurNormal(ligne, colonne); //on remet les bonnes couleurs si jamais une des cases avaient une couleur orange (case selectionnee)
			}
		}
	}

	void VueEchiquier::miseAJourVue() {
		bool mouvementFait = echiquier_.effectuerMouvement(positionChoisie_.first, positionChoisie_.second, positionVoulue_.first, positionVoulue_.second);
		if (mouvementFait) {
			mettrePieces();
		}
		else {
			std::cout << "Mouvement invalide." << std::endl;
			tourDesBlancs_ = !tourDesBlancs_; // on change le booleen pour que la couleur entrain de jouer doive reprendre son coup jusqu'a ce qu'il soit valide
		}
	}

	void VueEchiquier::initialiserPartie(std::string fichier) {
		echiquier_.modifierEchiquier(fichier); //on met les pieces dans lechiquier selon le fichier en parametre
		mettrePieces(); //on met les pieces dans la vue de lechiquier
		tourDesBlancs_ = true; 
		premierClickFait_ = false;
	}
}