///////////////////////////////////////////////////////////
//  PrimitiveAbs.cpp
//  Implementation of the Class PrimitiveAbs
//  Created on:      25-oct.-2018 20:47:13
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "PrimitiveAbs.h"
#include "Icone3DVisitorAbs.h"

namespace PolyIcone3D
{

	// Declaration d'un conteneur vide pour retourner des iterateurs toujours valides
	Icone3DContainer PrimitiveAbs::m_emptyContainer;

	PrimitiveAbs::PrimitiveAbs(const Point3D & pt)
		: Icone3DAbs(), m_center(pt)
	{
	}

	PrimitiveAbs::PrimitiveAbs(Icone3DAbs& parent)
		: Icone3DAbs(parent)
	{
	}

	PrimitiveAbs::PrimitiveAbs(Icone3DAbs& parent, const Point3D& c)
		: Icone3DAbs(parent), m_center(c)
	{

	}

	PrimitiveAbs::~PrimitiveAbs() {

	}

	void PrimitiveAbs::addChild(const Icone3DAbs& obj3d) {
		// Echoue silencieusement
	}

	Icone3DIterator PrimitiveAbs::begin() {

		return m_emptyContainer.end();
	}

	Icone3DIterator_const PrimitiveAbs::cbegin() const {

		return m_emptyContainer.cend();
	}

	Icone3DIterator_const PrimitiveAbs::cend() const {

		return m_emptyContainer.cend();
	}

	Icone3DIterator PrimitiveAbs::end() {

		return m_emptyContainer.end();
	}

	void PrimitiveAbs::removeChild(Icone3DIterator_const obj3dIt) {
		// Echoue silencieusement
	}

	void PrimitiveAbs::replaceChild(Icone3DIterator obj3dIt, const Icone3DAbs & newObj)
	{
		// Echoue silencieusement
	}

	Point3D PrimitiveAbs::getCenter() const {

		return  m_center;
	}

	void PrimitiveAbs::moveCenter(const Point3D & delta)
	{
		m_center += delta;
	}

	void PrimitiveAbs::setCenter(const Point3D& center) {
		m_center = center;
	}

	void PrimitiveAbs::accept(Icone3DVisitorAbs & vis) const
	{
		vis.visitPrimitive(*this);
	}

	void PrimitiveAbs::accept(Icone3DVisitorAbs & vis)
	{
		vis.visitPrimitive(*this);
	}

#if 0
	std::ostream & operator<<(std::ostream & o, const Icone3DAbs& obj3d)
	{
		return obj3d.toStream(o);
	}
#endif

} // namespace PolyIcone3D