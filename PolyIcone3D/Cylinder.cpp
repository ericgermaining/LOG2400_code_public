///////////////////////////////////////////////////////////
//  Cylinder.cpp
//  Implementation of the Class Cylinder
//  Created on:      25-oct.-2018 20:47:26
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Cylinder.h"
#include "Icone3DVisitorAbs.h"

namespace PolyIcone3D
{

	Cylinder::Cylinder(const Point3D & pt, float r, float ht)
		: PrimitiveAbs(pt)
	{
		if (r < 0.0 || ht < 0.0)
			throw std::range_error("Invalid parameter value for cylinder. Must be larger than 0");

		m_dimensions[0] = r;
		m_dimensions[1] = ht;
	}

	Cylinder::Cylinder(Icone3DAbs& parent, const Point3D& pt, float r, float ht)
		: PrimitiveAbs(parent, pt)
	{
		if (r < 0.0 || ht < 0.0)
			throw std::range_error("Invalid parameter value for cylinder. Must be larger than 0");

		m_dimensions[0] = r;
		m_dimensions[1] = ht;
	}

	Cylinder::Cylinder(Icone3DAbs & parent, const Cylinder & cyl)
		: PrimitiveAbs(parent, cyl.getCenter())
	{
		m_dimensions[0] = cyl.m_dimensions[0];
		m_dimensions[1] = cyl.m_dimensions[1];
	}

	Cylinder::~Cylinder() {

	}

	Cylinder * Cylinder::clone(Icone3DAbs& parent) const
	{
		return new Cylinder(parent, *this);
	}

	size_t Cylinder::getNbParameters() const {

		return 2;
	}

	PrimitiveParams Cylinder::getParameters() const
	{
		PrimitiveParams params;
		params.push_back(m_dimensions[0]);
		params.push_back(m_dimensions[1]);

		return params;
	}

	void Cylinder::setParameter(size_t pIndex, float pValue) {
		if (pIndex < 0 || pIndex > 1)
			throw std::range_error("Invalid parameter index for cylinder. Must be between 0 and 1");

		if (pValue < 0.0)
			throw std::range_error("Invalid parameter value for cylinder. Must be larger than 0");

		m_dimensions[pIndex] = pValue;

	}

	void Cylinder::accept(Icone3DVisitorAbs & vis) const
	{
		vis.visitCylinder(*this);
	}

	void Cylinder::accept(Icone3DVisitorAbs & vis)
	{
		vis.visitCylinder(*this);
	}

	std::ostream & Cylinder::toStream(std::ostream & o) const
	{
		return o << "Cylinder:  center = " << m_center
			<< "; r = " << m_dimensions[0]
			<< "; ht = " << m_dimensions[1] << ";";
	}

} // namespace PolyIcone3D