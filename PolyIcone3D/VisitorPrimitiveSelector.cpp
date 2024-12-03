///////////////////////////////////////////////////////////
//  VisitorPrimitiveSelector.cpp
//  Implementation of the Class VisitorPrimitiveSelector
//  Created on:      07-nov.-2018 21:20:38
//  Original author: p482457
///////////////////////////////////////////////////////////

#include <exception>

#include "VisitorPrimitiveSelector.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Icone3DComposite.h"
#include "TransformedIcone3D.h"

namespace PolyIcone3D
{

	VisitorPrimitiveSelector::VisitorPrimitiveSelector(PRIMITIVE_TYPE typ)
		: m_type(typ)
	{
	}

	VisitorPrimitiveSelector::~VisitorPrimitiveSelector()
	{
	}

	void VisitorPrimitiveSelector::visitCube(class Cube& cub)
	{
		if (!m_currentObjStack.empty())
			if (m_type == PRIMITIVE_TYPE::Cube_t)
				m_selectObjContainer.push_back(m_currentObjStack.front());
	}

	void VisitorPrimitiveSelector::visitCylinder(class Cylinder& cyl)
	{
		if (!m_currentObjStack.empty())
			if (m_type == PRIMITIVE_TYPE::Cylinder_t)
				m_selectObjContainer.push_back(m_currentObjStack.front());
	}

	void VisitorPrimitiveSelector::visitObjComposite(const Icone3DComposite& comp)
	{
		throw(std::invalid_argument("VisitorPrimitiveSelector cannot process const Icones"));
	}

	void VisitorPrimitiveSelector::visitObjComposite(class Icone3DComposite& comp)
	{
		for (auto it = comp.begin(); it != comp.end(); ++it)
		{
			m_currentObjStack.push_front(it);
			it->accept(*this);
			m_currentObjStack.pop_front();
		}
	}

	void VisitorPrimitiveSelector::visitPrimitive(const class PrimitiveAbs& prim)
	{
		throw(std::invalid_argument("VisitorPrimitiveSelector cannot process const Icones"));
	}

	void VisitorPrimitiveSelector::visitPrimitive(class PrimitiveAbs& prim)
	{
		// Type de primitive inconnue... cette primitive n'est pas selectionnee
	}

	void VisitorPrimitiveSelector::visitSphere(class Sphere& sph)
	{
		if (!m_currentObjStack.empty())
			if (m_type == PRIMITIVE_TYPE::Sphere_t)
				m_selectObjContainer.push_back(m_currentObjStack.front());
	}

	void VisitorPrimitiveSelector::visitTransformedIcone3D(class TransformedIcone3D& tobj)
	{
		tobj.getIcone3D().accept(*this);
	}

	void VisitorPrimitiveSelector::getSelectIcones(Obj3DIteratorContainer & objContainer)
	{
		for (auto& it : m_selectObjContainer)
			objContainer.push_back(it);
	}
} // namespace PolyIcone3D
