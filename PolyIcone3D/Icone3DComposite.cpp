///////////////////////////////////////////////////////////
//  Icone3DComposite.cpp
//  Implementation of the Class Icone3DComposite
//  Created on:      25-oct.-2018 20:40:33
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Icone3DComposite.h"
#include "Icone3DVisitorAbs.h"

namespace PolyIcone3D
{

	Icone3DComposite::Icone3DComposite()
	{
	}

	Icone3DComposite::Icone3DComposite(Icone3DAbs& parent)
		: Icone3DAbs(parent)
	{
	}

	Icone3DComposite::Icone3DComposite(Icone3DAbs& parent, const Icone3DComposite & mdd)
		: Icone3DAbs(parent)
	{
		for (auto it = mdd.cbegin(); it != mdd.cend(); ++it)
			addChild(*it);
	}

	Icone3DComposite::~Icone3DComposite() {

	}

	Icone3DComposite * Icone3DComposite::clone(Icone3DAbs& parent) const
	{
		return new Icone3DComposite(parent, *this);
	}

	void Icone3DComposite::addChild(const Icone3DAbs& obj3d)
	{
		m_iconeContainer.push_back(Icone3DPtr(obj3d.clone(*this)));
	}

	Icone3DIterator Icone3DComposite::begin() {

		return m_iconeContainer.begin();
	}

	Icone3DIterator_const Icone3DComposite::cbegin() const {

		return m_iconeContainer.cbegin();
	}

	Icone3DIterator_const Icone3DComposite::cend() const {

		return m_iconeContainer.cend();
	}

	Icone3DIterator Icone3DComposite::end() {

		return m_iconeContainer.end();
	}

	Point3D Icone3DComposite::getCenter() const {

		return computeCenter();
	}

	size_t Icone3DComposite::getNbParameters() const
	{
		return 0;
	}

	PrimitiveParams Icone3DComposite::getParameters() const {

		return  PrimitiveParams();
	}

	void Icone3DComposite::removeChild(Icone3DIterator_const obj3dIt)
	{
		m_iconeContainer.erase(obj3dIt);
	}

	void Icone3DComposite::replaceChild(Icone3DIterator obj3dIt, const Icone3DAbs & newObj)
	{
		Icone3DBaseIterator itBase(obj3dIt);
		Icone3DPtr& objp = *itBase;
		objp.reset(newObj.clone(*this));
	}

	void Icone3DComposite::moveCenter(const Point3D & delta)
	{
		for (auto it = begin(); it != end(); ++it)
			it->moveCenter(delta);
	}

	void Icone3DComposite::setCenter(const Point3D& center) {
		auto delta = center - computeCenter();
		moveCenter(delta);
	}

	void Icone3DComposite::setParameter(size_t pIndex, float pValue) {

	}

	void Icone3DComposite::accept(Icone3DVisitorAbs & vis) const
	{
		vis.visitObjComposite(*this);
	}

	void Icone3DComposite::accept(Icone3DVisitorAbs & vis)
	{
		vis.visitObjComposite(*this);
	}

	Point3D Icone3DComposite::computeCenter() const
	{
		// Calcul la moyenne des centres de tous les enfants
		// S'il n'y a pas d'enfant, initialise a (0,0,0)
		Point3D m_center;
		int nChildren = 0;
		for (auto it = cbegin(); it != cend(); ++it, ++nChildren)
			m_center += it->getCenter();

		if (nChildren > 0)
			m_center /= float(nChildren);

		return m_center;
	}

#if 0
	// Variable statique permettant de stocker le niveau d'indentation
	size_t Icone3DComposite::outputIndent = 0;

	std::ostream& indentation(std::ostream& o, size_t indentLevel)
	{
		for (auto iindent = 0; iindent < indentLevel; ++iindent)
			o << "\t";
		return o;
	}

	std::ostream & Icone3DComposite::toStream(std::ostream & o) const
	{
		o << "Composite: center = " << computeCenter() << ": {" << std::endl;
		++outputIndent;
		for (auto it = cbegin(); it != cend(); ++it)
			indentation(o, outputIndent) << *it << std::endl;
		--outputIndent;
		indentation(o, outputIndent) << "}";

		return o;
	}
#endif
}