///////////////////////////////////////////////////////////
//  TransformedIcone3D.cpp
//  Implementation of the Class TransformedIcone3D
//  Created on:      26-oct.-2018 17:42:19
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "TransformedIcone3D.h"
#include "Icone3DVisitorAbs.h"

namespace PolyIcone3D
{

	TransformedIcone3D::TransformedIcone3D(const PrimitiveAbs& obj3d, const Point3D & translat, float scal)
		: PrimitiveAbs(obj3d.getCenter()), m_Icone3d(obj3d.clone(const_cast<Icone3DAbs&>(obj3d.getParent()))),
		m_translation(translat), m_scale(scal)
	{
	}

	TransformedIcone3D::TransformedIcone3D(Icone3DAbs& parent, const PrimitiveAbs& obj3d, const Point3D & translat, float scal)
		: PrimitiveAbs(parent, obj3d.getCenter()), m_Icone3d(obj3d.clone(parent)), m_translation(translat), m_scale(scal)
	{
	}

	TransformedIcone3D::TransformedIcone3D(Icone3DAbs& parent, const TransformedIcone3D & mdd)
		: PrimitiveAbs(parent, mdd.m_Icone3d->getCenter()), m_Icone3d(mdd.m_Icone3d->clone(parent)),
		m_scale(mdd.m_scale), m_translation(mdd.m_translation)
	{
	}

	TransformedIcone3D::~TransformedIcone3D() {

	}

	TransformedIcone3D* TransformedIcone3D::clone(Icone3DAbs& parent) const
	{
		return new TransformedIcone3D(parent, *this);
	}

	void TransformedIcone3D::addChild(const Icone3DAbs& obj3d) {
		// Deleguer a l'Objet decore la tache d'ajouter un enfant
		m_Icone3d->addChild(obj3d);
	}


	Icone3DIterator TransformedIcone3D::begin() {

		return  m_Icone3d->begin();
	}


	Icone3DIterator_const TransformedIcone3D::cbegin() const {

		return m_Icone3d->cbegin();
	}


	Icone3DIterator_const TransformedIcone3D::cend() const {

		return m_Icone3d->cend();
	}




	Icone3DIterator TransformedIcone3D::end()
	{
		return m_Icone3d->end();
	}


	Point3D TransformedIcone3D::getCenter() const
	{
		return m_Icone3d->getCenter() + m_translation;
	}


	size_t TransformedIcone3D::getNbParameters() const
	{
		return m_Icone3d->getNbParameters();
	}


	PrimitiveParams TransformedIcone3D::getParameters() const
	{
		PrimitiveParams params = m_Icone3d->getParameters();
		for (int iparam = 0; iparam < params.size(); ++iparam)
			params[iparam] *= m_scale;
		return params;
	}


	void TransformedIcone3D::moveCenter(const Point3D& delta) {
		m_translation += delta;
	}


	void TransformedIcone3D::removeChild(Icone3DIterator_const obj3dIt)
	{
		// Deleguer a l'Icone decore la tache d'eliminer un enfant
		m_Icone3d->removeChild(obj3dIt);
	}


	void TransformedIcone3D::setCenter(const Point3D& center) {
		m_Icone3d->setCenter(center);
	}


	void TransformedIcone3D::setParameter(size_t pIndex, float pValue)
	{
		m_Icone3d->setParameter(pIndex, pValue);
	}

	float TransformedIcone3D::getScale() const
	{
		return m_scale;
	}

	void TransformedIcone3D::setScale(float scal)
	{
		m_scale = scal;
	}

	Point3D TransformedIcone3D::getTranslation() const
	{
		return m_translation;
	}

	void TransformedIcone3D::setTranslation(const Point3D & translat)
	{
		m_translation = translat;
	}

	PrimitiveAbs& TransformedIcone3D::getIcone3D()
	{
		return *m_Icone3d;
	}

	const PrimitiveAbs& TransformedIcone3D::getIcone3D() const
	{
		return *m_Icone3d;
	}

	void TransformedIcone3D::accept(Icone3DVisitorAbs & vis) const
	{
		vis.visitTransformedIcone3D(*this);
	}

	void TransformedIcone3D::accept(Icone3DVisitorAbs & vis)
	{
		vis.visitTransformedIcone3D(*this);
	}

#if 0
	std::ostream& TransformedIcone3D::toStream(std::ostream& o) const
	{
		o << "Transformed Icone: Icone={ " << *m_Icone3d
			<< " }, Translation = " << m_translation << ", Scale = " << m_scale << " }" << std::endl;

		return  o;
	}
#endif

} // namespace PolyIcone3D