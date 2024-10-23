///////////////////////////////////////////////////////////
//  TransformCmd.cpp
//  Implementation of the Class TransformCmd
//  Created on:      08-nov.-2018 21:05:11
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "TransformCmd.h"
#include "TransformedIcone3D.h"

namespace PolyIcone3D
{

	TransformCmd::TransformCmd(Icone3DIterator objIter, const Point3D & translat, float scal)
		: m_objIter(objIter), m_translate(translat), m_scale(scal)
	{
	}

	TransformCmd::~TransformCmd()
	{
	}

	void TransformCmd::cancel()
	{
		try
		{
			// Verifier si l'objet sur lequel pointe l'iterateur est un objet transforme
			TransformedIcone3D& objTransformed = dynamic_cast<TransformedIcone3D&> (*m_objIter);

			// Construire un nouvel objet transforme en ajoutant un decorateur
			PrimitiveAbs& primitive = objTransformed.getIcone3D();

			// Remplacer l'objet sur lequel pointe l'iterateur par l'objet transforme
			primitive.getParent().replaceChild(m_objIter, primitive);
		}
		catch (std::bad_cast& err)
		{
			std::cerr << "Erreur en annulant une commande de transformation: l'iterateur ne pointe pas sur un objet transforme"
				<< std::endl << err.what() << std::endl;
		}
	}

	void TransformCmd::execute()
	{
		try
		{
			// Verifier si l'objet sur lequel pointe l'iterateur est une primitive
			PrimitiveAbs& primitive = dynamic_cast<PrimitiveAbs&> (*m_objIter);

			// Construire un nouvel objet transforme en ajoutant un decorateur
			TransformedIcone3D objTransformed(primitive.getParent(), primitive, m_translate, m_scale);

			// Remplacer l'objet sur lequel pointe l'iterateur par l'objet transforme
			primitive.getParent().replaceChild(m_objIter, objTransformed);
		}
		catch (std::bad_cast& err)
		{
			std::cerr << "Erreur en executant une commande de transformation: l'objet a transformer n'est pas une primitive"
				<< std::endl << err.what() << std::endl;
		}
	}

} // namespace PolyIcone3D