/*
* Fichier contenant l'implementation des methode des classes du modele du projet final.
* file   modele.cpp
*/
#include "modele.hpp"

namespace modele {

	// methodes de la classe Piece 

	Piece::Piece(bool couleur, int positionLigne, int positionColonne, std::unique_ptr<DeplacementStrategie> strategieDeplacement)
		: couleurNoire_(couleur), positionLigne_(positionLigne), positionColonne_(positionColonne), strategieDeplacement_(std::move(strategieDeplacement)) {
		couleurNoire_ = couleur;
		positionLigne_ = positionLigne;
		positionColonne_ = positionColonne;
	}

	bool Piece::setPosition(int positionLigne, int positionColonne) {
		if (this->mouvementValide(positionLigne_, positionColonne_, positionLigne, positionColonne)) {
			positionLigne_ = positionLigne;
			positionColonne_ = positionColonne;
			return true;
		}
		else {
			return false;
		}
	}

	std::pair<int, int> Piece::getPosition() const { return { positionLigne_, positionColonne_ }; }

	bool Piece::getCouleur() const { return couleurNoire_; }

	bool DeplacementStrategie::mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const {
		if ((positionLigneVoulue < 0) | (positionLigneVoulue >= nLignes)) return false;
		else if ((positionColonneVoulue < 0) | (positionColonneVoulue >= nColonnes)) return false;
		else if ((positionColonneVoulue == positionColonne && positionLigneVoulue == positionLigne)) return false;
		return true;
	}

	//  methodes de la classe Roi

	Roi::Roi(bool couleur, int positionLigne, int positionColonne)
		: Piece(couleur, positionLigne, positionColonne, std::make_unique<MouvementValideRoi>()) {

		if (compteur_ >= nRoi) throw ConstructionInvalide("Plus de deux instances de Roi.");
		compteur_++;
	}

	Roi::~Roi() {
		compteur_--;
	}

	bool MouvementValideRoi::mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const {
		if (DeplacementStrategie::mouvementValide(positionLigne, positionColonne, positionLigneVoulue, positionColonneVoulue)) {

			bool validationLigne = abs(positionLigne - positionLigneVoulue) <= 1;
			bool validationColonne = abs(positionColonne - positionColonneVoulue) <= 1;

			if (validationLigne && validationColonne) {
				return true;
			}
		}
		return false;
	}

	//  methodes de la classe Cavalier

	Cavalier::Cavalier(bool couleur, int positionLigne, int positionColonne)
		: Piece(couleur, positionLigne, positionColonne, std::make_unique<MouvementValideCavalier>()) {}

	bool MouvementValideCavalier::mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const {
		if (DeplacementStrategie::mouvementValide(positionLigne, positionColonne, positionLigneVoulue, positionColonneVoulue)) {
			int variationLigne = abs(positionLigne - positionLigneVoulue);
			int variationColonne = abs(positionColonne - positionColonneVoulue);

			bool validationLigne = (variationLigne == 2) | (variationLigne == 1);
			bool validationColonne = (variationColonne == 2) | (variationColonne == 1);
			bool validationMouvement = variationColonne != variationLigne;

			if (validationColonne && validationLigne && validationMouvement) {
				return true;
			}
		}
		return false;
	}

	//methodes de la classe Pion 

	Pion::Pion(bool couleur, int positionLigne, int positionColonne)
		: Piece(couleur, positionLigne, positionColonne, std::make_unique<MouvementValidePion>(couleur)) {}

	bool MouvementValidePion::mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const {
		if (DeplacementStrategie::mouvementValide(positionLigne, positionColonne, positionLigneVoulue, positionColonneVoulue)) {
			if (couleurNoire_ && (positionLigneVoulue >= positionLigne)) return false;   // ces deux conditions sassurent qu une piece avance
			else if (!couleurNoire_ && positionLigneVoulue <= positionLigne) return false;
			int variationLigne = abs(positionLigne - positionLigneVoulue);
			int variationColonne = abs(positionColonne - positionColonneVoulue);
			if (variationColonne == 0) { //et quil ny a pas de piece la, a ajouter
				if (variationLigne == 1) return true;
				else if ((variationLigne == 2) && couleurNoire_ && (positionLigne == 6)) return true;  // double saut au debut pour les noirs
				else if ((variationLigne == 2) && !couleurNoire_ && (positionLigne == 1)) return true; //double saut a lavant pour les blancs
			}
			if (variationColonne == 1 && variationLigne == 1) //et quil y a une piece la
				return true;
		}
		return false;
	}

	//  methodes de la classe Tour

	Tour::Tour(bool couleur, int positionLigne, int positionColonne)
		: Piece(couleur, positionLigne, positionColonne, std::make_unique<MouvementValideTour>()) {}

	bool MouvementValideTour::mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const {
		if (DeplacementStrategie::mouvementValide(positionLigne, positionColonne, positionLigneVoulue, positionColonneVoulue)) {
			int variationLigne = abs(positionLigne - positionLigneVoulue);
			int variationColonne = abs(positionColonne - positionColonneVoulue);

			if ((variationColonne == 0 && variationLigne > 0) | (variationLigne == 0 && variationColonne > 0))
				return true;
		}
		return false;
	}

	// methodes de la classe Fou

	Fou::Fou(bool couleur, int positionLigne, int positionColonne)
		: Piece(couleur, positionLigne, positionColonne, std::make_unique<MouvementValideFou>()) {}

	bool MouvementValideFou::mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const {
		if (DeplacementStrategie::mouvementValide(positionLigne, positionColonne, positionLigneVoulue, positionColonneVoulue)) {
			int variationLigne = abs(positionLigne - positionLigneVoulue);
			int variationColonne = abs(positionColonne - positionColonneVoulue);
			if (variationColonne == variationLigne)
				return true;
		}
		return false;
	}

	//methode de la classe Reine

	Reine::Reine(bool couleur, int positionLigne, int positionColonne)
		: Piece(couleur, positionLigne, positionColonne, std::make_unique<MouvementValideReine>()) {}

	bool MouvementValideReine::mouvementValide(int positionLigne, int positionColonne, int positionLigneVoulue, int positionColonneVoulue) const {
		if (!DeplacementStrategie::mouvementValide(positionLigne, positionColonne, positionLigneVoulue, positionColonneVoulue)) return false;
		bool mouvementFou;
		int variationLigne = abs(positionLigne - positionLigneVoulue);
		int variationColonne = abs(positionColonne - positionColonneVoulue);
		if (variationColonne == variationLigne)
			mouvementFou = true;
		else mouvementFou = false;

		bool mouvementTour;
		if ((variationColonne == 0 && variationLigne > 0) | (variationLigne == 0 && variationColonne > 0))
			mouvementTour = true;
		else mouvementTour = false;

		return mouvementFou ^ mouvementTour;
	}

	// methodes de la classe Echiquier

	Echiquier* Echiquier::instance_ = nullptr;

	Echiquier& Echiquier::getInstance() {
		if (instance_ == nullptr) {
			instance_ = new Echiquier();
		}

		return *instance_;
	}

	void Echiquier::libererInstance() {
		delete instance_;
		instance_ = nullptr;
	}
	
	Echiquier::Echiquier() { // construction d'un echiquier vide de pieces
		for (int ligne = 0; ligne < nLignes; ligne++) {
			for (int colonne = 0; colonne < nColonnes; colonne++) {
					echiquier_[ligne][colonne] = nullptr;
			}
		}
	}

	Echiquier::~Echiquier() {
		for (int ligne = 0; ligne < nLignes; ligne++) {
			for (int colonne = 0; colonne < nColonnes; colonne++) {
				delete echiquier_[ligne][colonne];
				echiquier_[ligne][colonne] = nullptr;
			}
		}
	}

	void Echiquier::modifierEchiquier(std::string nomFichier) { // la lecture des positions se fait selon une notation tres similaire a la notation FEN (une notation pour generer des endgames au echecs)
		// NOTATION DE LECTURE DE FICHIER

		/* le fichier .txt se lit ainsi:
		* la lecture de chaque ligne de l'echiquier est separé par un '/', la lecture commence par remplir la ligne du bas de l'echiquier vers le haut
		* les caractere entre les '/' servent a remplir les cases de cette ligne de l'echiquier, il doivent donc remplir 8 cases entre les '/'
		* chaque chiffre represente un nombre de case vide
		* chaque caractere alphabetique represente une piece, si le caractere est majuscule c'est une piece blanche et s'il est minuscule il est noir (r = roi noir, R = roi blanc, c = cavalier noir, etc.)
		* le remplissage se fait de gauche a droite comme la lecture du fichier
		* exemple de lecture des deux premieres lignes:                  2rt4/T5Cc/
		* la lecture de ce fichier donnerait le remplissage suivant: 
		*	**lecture de gauche a droite et de bas vers le haut**
		* 
		*									premiere ligne (2rt4) :     case vide | case vide | roi noir | tour noir | case vide | case vide | case vide      | case vide
		* 
		*									deuxieme ligne (T5Cc) :  tour blanche | case vide | case vide|case vide  | case vide | case vide | cavalier blanc | cavalier noir
		*																
		*/

		this->~Echiquier(); // on libere l'espace memoire de toutes les pieces precedemment placees sur l'echiquier

		// allocation des pieces sur l'echiquier selon la lecture du fichier .txt
		std::ifstream fichier(nomFichier);
		for (int ligne = 0; ligne < nLignes; ligne++) {
			for (int colonne = 0; colonne < nColonnes; colonne++) {
				try
				{
					char caractereFEN;
					fichier >> caractereFEN;
					int couleur = (islower(caractereFEN)) ? noir : blanc;

					if (caractereFEN == '/') colonne -= 1; // ce caractere sert a delimiter une nouvelle ligne dans notre fichier, on veut donc qu'il agisse comme iteration vide
					else if (isdigit(caractereFEN)) { // caractereFEN est necessairement un chiffre
						int iterations = caractereFEN - zeroEnASCII;
						for (int i = 0; i < iterations; i++)
						{
							echiquier_[ligne][colonne + i] = nullptr;
						}
						colonne += iterations - 1;
					}
					else { 
						echiquier_[ligne][colonne] = PieceFactory::creerPiece(caractereFEN, couleur, ligne, colonne);
					}
				}
				catch (ConstructionInvalide& e) // on attrape l erreur de creation de plus de 2 rois
				{
					std::cout << "Erreur: " << e.what() << "Cette construction a ete bloque.";
				}
			}
		}
	}

	//est surtout utilisee pour les tests puisque lechiquier est prive
	Piece* Echiquier::getPiece(int ligne, int colonne) {
		return echiquier_[ligne][colonne];
	}

	void Echiquier::copieProfonde(Piece* nouveauEchiquier[nLignes][nColonnes], Piece* echiquier[nLignes][nColonnes]) {
		for (int ligne = 0; ligne < nLignes; ligne++)
		{
			for (int colonne = 0; colonne < nColonnes; colonne++)
			{
				nouveauEchiquier[ligne][colonne] = echiquier[ligne][colonne];
			}
		}
	}

	bool Echiquier::effectuerMouvement(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY) {
		bool retour;
		Piece* echiquierTemporaire[8][8];
		copieProfonde(echiquierTemporaire, echiquier_);

		if (echiquier_[positionActuelleX][positionActuelleY] == nullptr) return false; //peut pas bouger une piece qui existe pas
		if (effectuerRoc(positionActuelleX, positionActuelleY, positionVoulueX, positionVoulueY)) return true;
		bool couleur = echiquier_[positionActuelleX][positionActuelleY]->getCouleur();
		if (pieceEnChemin(positionActuelleX, positionActuelleY, positionVoulueX, positionVoulueY)) return false;
		else if (echiquier_[positionVoulueX][positionVoulueY] != nullptr) { //donc il y a une piece
			bool memeCouleur = echiquier_[positionVoulueX][positionVoulueY]->getCouleur() == couleur;
			if (memeCouleur)
				return false; //peut pas bouger sur une piece de ta couleur
		}

		Piece* pieceVoulue = echiquier_[positionVoulueX][positionVoulueY]; //on prend une copie du pointeur de la case a la position voulue
		retour = echangerPiece(positionActuelleX, positionActuelleY, positionVoulueX, positionVoulueY); //on effectue le mouvement

		//on regarde si la derniere modification a genere un echec
		if (retour && miseEnEchec(couleur)) {
			// on est alors en echec
			// on veut remettre les pieces a letat initial et retourner faux
			copieProfonde(echiquier_, echiquierTemporaire);
			echiquier_[positionActuelleX][positionActuelleY]->setPosition(positionActuelleX, positionActuelleY); // on remet les attributs de la piece en question a leur valeur initiale pusique le coup est impossible 
			return false;
		}
		//on est alors pas en echec et le mouvement peut se faire
		else if (retour) delete pieceVoulue; //on libere l'espace memoire associe a la case ou notre piece a ete bougée
		promotionEnReine();
		return retour; 
	}

	bool Echiquier::echangerPiece(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY) {
		int variationColonne = abs(positionActuelleY - positionVoulueY);
		if (dynamic_cast<Pion*>(echiquier_[positionActuelleX][positionActuelleY]) && variationColonne > 0 && echiquier_[positionVoulueX][positionVoulueY] == nullptr)
			return false;

		if (echiquier_[positionActuelleX][positionActuelleY]->setPosition(positionVoulueX, positionVoulueY)) { //on change les attributs de la piece quon bouge si le mouvement est valide
			echiquier_[positionVoulueX][positionVoulueY] = echiquier_[positionActuelleX][positionActuelleY]; //on change sa position dans la matrice
			echiquier_[positionActuelleX][positionActuelleY] = nullptr; //il y a maintenant rien a la position actuelle
			return true;
		}
		return false;
	}

	bool Echiquier::enCheminPion(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY) {
		int variationColonne = abs(positionActuelleY - positionVoulueY);
		int variationLigne = abs(positionActuelleX - positionVoulueX);
		bool couleurNoire = echiquier_[positionActuelleX][positionActuelleY]->getCouleur();
		if (variationLigne && variationColonne == 0)
			if (echiquier_[positionVoulueX][positionVoulueY] != nullptr) return true;
			if (variationLigne == 2) {
				if (couleurNoire && echiquier_[positionVoulueX + 1][positionVoulueY] != nullptr) return true; //marche juste pour les blancs, pour les noirs ca doit etre +1
				else if (!couleurNoire && echiquier_[positionVoulueX - 1][positionVoulueY] != nullptr) return true;
			}
		return false;
	}

	bool Echiquier::enCheminTour(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY) {
		std::pair<int, int> position;
		int variationLigne = abs(positionActuelleX - positionVoulueX);
		variationLigne > 0 ? position = std::minmax(positionActuelleX, positionVoulueX) : position = std::minmax(positionActuelleY, positionVoulueY);

		bool enChemin;
		for (int i = position.first + 1; i < position.second; i++) { //on ne regarde pas sil y a une piece a la positon actuelle ni voulu, car ceci est deja considerer dans la fonction effectuerMouvement
			variationLigne > 0 ? enChemin = (echiquier_[i][positionActuelleY] != nullptr) : enChemin = (echiquier_[positionActuelleX][i] != nullptr);
			if (enChemin) return true;
		}
		return false;
	}

	bool Echiquier::enCheminFou(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY) {
		int variationColonne = positionVoulueY - positionActuelleY;
		int variationLigne = positionVoulueX - positionActuelleX;
		int mouvement = variationColonne * variationLigne; // si mouvement est positif alors '/' si negatif "backslash"
		std::pair<int, int> departX = std::minmax(positionActuelleX, positionVoulueX);
		std::pair<int, int> departY = std::minmax(positionActuelleY, positionVoulueY);

		bool enChemin;
		for (int i = departX.first + 1; i < departX.second; i++) // etablie un nb diterations
		{
			mouvement > 0 ? enChemin = (echiquier_[++departX.first][++departY.first] != nullptr) : enChemin = (echiquier_[++departX.first][--departY.second] != nullptr);
			if (enChemin) return true;
		}
		return false;
	}

	bool Echiquier::enCheminReine(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY) {
		int variationLigne = abs(positionActuelleX - positionVoulueX);
		int variationColonne = abs(positionActuelleY - positionVoulueY);
		bool cheminFou = enCheminFou(positionActuelleX, positionActuelleY, positionVoulueX, positionVoulueY);
		bool cheminTour = enCheminTour(positionActuelleX, positionActuelleY, positionVoulueX, positionVoulueY);
		if (variationColonne && variationLigne) return cheminFou;
		else return cheminTour;
	}

	bool Echiquier::pieceEnChemin(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY) {
		if (dynamic_cast<Pion*>(echiquier_[positionActuelleX][positionActuelleY])) return enCheminPion(positionActuelleX, positionActuelleY, positionVoulueX, positionVoulueY);
		else if (dynamic_cast<Tour*>(echiquier_[positionActuelleX][positionActuelleY])) return enCheminTour(positionActuelleX, positionActuelleY, positionVoulueX, positionVoulueY); // on regarde ce critere seulement si la piece en question est une tour
		else if (dynamic_cast<Fou*>(echiquier_[positionActuelleX][positionActuelleY])) return enCheminFou(positionActuelleX, positionActuelleY, positionVoulueX, positionVoulueY);
		else if (dynamic_cast<Reine*>(echiquier_[positionActuelleX][positionActuelleY])) return enCheminReine(positionActuelleX, positionActuelleY, positionVoulueX, positionVoulueY);
		return false;
	}

	std::pair<int, int> Echiquier::getPositionRoi(bool couleur) {
		for (int ligne = 0; ligne < nLignes; ligne++)
		{
			for (int colonne = 0; colonne < nColonnes; colonne++)
			{
				if (dynamic_cast<Roi*>(echiquier_[ligne][colonne]) && echiquier_[ligne][colonne]->getCouleur() == couleur )
					return echiquier_[ligne][colonne]->getPosition();
			}
		}
		return {}; //pour eviter le warning "les chemins de code ne retourne pas tous une valeur"
	}

	bool Echiquier::miseEnEchec(bool couleur) {
		std::pair<int, int> positionRoi = getPositionRoi(couleur);
		int positionRoiX = positionRoi.first;
		int positionRoiY = positionRoi.second;
		for (int ligne = 0; ligne < nLignes; ligne++)
		{
			for (int colonne = 0; colonne < nColonnes; colonne++)
			{
				if (!echiquier_[ligne][colonne] || echiquier_[ligne][colonne]->getCouleur() == couleur) continue;
				else if (!pieceEnChemin(ligne, colonne, positionRoiX, positionRoiY) && echiquier_[ligne][colonne]->mouvementValide(ligne, colonne, positionRoiX, positionRoiY)) {
					std::cout << "Vous etes en echec: ";
					return true;
				}
			}
		}
		return false;
	}

	void Echiquier::promotionEnReine() {
		for (int i = 0; i <= avantDerniereCase; i++) {
			if (dynamic_cast<Pion*>(echiquier_[0][i])) {
				if (echiquier_[0][i]->getCouleur() == noir) {
					delete echiquier_[0][i];
					echiquier_[0][i] = new Reine(noir, 0, i);
				}
			}
			else if (dynamic_cast<Pion*>(echiquier_[avantDerniereCase][i])) {
				if (echiquier_[avantDerniereCase][i]->getCouleur() == blanc) {
					delete echiquier_[avantDerniereCase][i];
					echiquier_[avantDerniereCase][i] = new Reine(blanc, avantDerniereCase, i);
				}
			}
		}
	}

	bool Echiquier::effectuerRoc(int positionActuelleX, int positionActuelleY, int positionVoulueX, int positionVoulueY) {
		Roi* roiActuel = dynamic_cast<Roi*>(echiquier_[positionActuelleX][positionActuelleY]);
		if (roiActuel != nullptr && !roiActuel->aDejaBouge) {
			if (positionVoulueY == 2 && !enCheminTour(positionActuelleX, positionActuelleY, positionVoulueX, 0)) {
				grandRoc(positionActuelleX);
			}
			else if (positionVoulueY == 6 && !enCheminTour(positionActuelleX, positionActuelleY, positionVoulueX, avantDerniereCase)) {
				petitRoc(positionActuelleX);
			}
			roiActuel->aDejaBouge = true;
			return true;
		}
		return false;
	}

	void Echiquier::grandRoc(int positionX) {
		delete echiquier_[positionX][0];
		echiquier_[positionX][0] = nullptr;
		delete echiquier_[positionX][4];
		echiquier_[positionX][4] = nullptr;
		bool couleurNoire;
		positionX == 0 ? couleurNoire = false : couleurNoire = true;
		echiquier_[positionX][2] = new Roi(couleurNoire, positionX, 2);
		echiquier_[positionX][3] = new Tour(couleurNoire, positionX, 3);
	
	}

	void Echiquier::petitRoc(int positionX) {
		delete echiquier_[positionX][avantDerniereCase];
		echiquier_[positionX][avantDerniereCase] = nullptr;
		delete echiquier_[positionX][4];
		echiquier_[positionX][4] = nullptr;
		bool couleurNoire;
		positionX == 0 ? couleurNoire = false : couleurNoire = true;
		echiquier_[positionX][6] = new Roi(couleurNoire, positionX, 6);
		echiquier_[positionX][5] = new Tour(couleurNoire, positionX, 5);
	}

	void Echiquier::ajouterObservateur(Observateur* observateur) {
		observateurs.push_back(observateur);
	}

	void Echiquier::notifierObservateurs() {
		for (Observateur* observateur : observateurs) {
			observateur->miseAJourVue();
		}
	}
}