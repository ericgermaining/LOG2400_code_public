///////////////////////////////////////////////////////////
//  Icone3DContainer.h
//  Implementation of the Class Icone3DContainer
//  Created on:      25-oct.-2018 20:29:07
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_)
#define EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_

#include <vector>
#include<list>
#include <memory>

namespace PolyIcone3D
{
	// Configuration du stockage des enfants des Icones composites
	using Icone3DPtr = std::unique_ptr<class Icone3DAbs>;
	using Icone3DContainer = std::vector<Icone3DPtr>;
	using Icone3DBaseIterator = Icone3DContainer::iterator;
	using Icone3DBaseIterator_const = Icone3DContainer::const_iterator;

	class Icone3DIterator : public Icone3DBaseIterator
	{
	public:
		Icone3DIterator(const Icone3DContainer::iterator& it) : Icone3DBaseIterator(it) {}

		// Operateurs simplifiant l'acces a l'Icone 3D sur lequel pointe l'iterateur
		// pour Icone3DIterator it;
		//    *it est l'Icone 3D
		//    it-> permet d'invoquer une methode sur l'Icone 3D
		class Icone3DAbs& operator*() { return *((*(Icone3DBaseIterator(*this))).get()); }
		class Icone3DAbs* operator->() { return (*(Icone3DBaseIterator(*this))).get(); }
	};

	class Icone3DIterator_const : public Icone3DBaseIterator_const
	{
	public:
		Icone3DIterator_const(const Icone3DContainer::const_iterator& it) : Icone3DBaseIterator_const(it) {}

		// Operateurs simplifiant l'acces a l'Icone 3D sur lequel pointe l'iterateur
		// pour Icone3DIterator_const it;
		//    *it est l'Icone 3D constant
		//    it-> permet d'invoquer une methode const sur l'Icone 3D
		const class Icone3DAbs& operator*() { return *((*(Icone3DBaseIterator_const(*this))).get()); }
		const class Icone3DAbs* operator->() { return (*(Icone3DBaseIterator_const(*this))).get(); }
	};

	// Configuration d'un format d'externalisation des parametres des primitives
	using PrimitiveParams = std::vector<float>;
}
#endif // !defined(EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_)
