///////////////////////////////////////////////////////////
//  Sphere.cpp
//  Implementation of the Class Sphere
//  Created on:      25-oct.-2018 20:47:54
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Sphere.h"
#include "Icone3DVisitorAbs.h"

namespace PolyIcone3D
{

	Sphere::Sphere(const Point3D & pt, float r)
		: PrimitiveAbs(pt), m_radius(r)
	{
		if (r < 0.0)
			throw std::range_error("Invalid radius value for sphere. Must be larger than 0");
	}

	Sphere::Sphere(Icone3DAbs& parent, const Point3D& pt, float r)
		: PrimitiveAbs(parent, pt), m_radius(r)
	{
		if (r < 0.0)
			throw std::range_error("Invalid radius value for sphere. Must be larger than 0");
	}

	Sphere::Sphere(Icone3DAbs & parent, const Sphere & sph)
		: PrimitiveAbs(parent, sph.m_center), m_radius(sph.m_radius)
	{
	}

	Sphere::~Sphere() {

	}

	Sphere * Sphere::clone(Icone3DAbs& parent) const
	{
		return new Sphere(parent, *this);
	}

	size_t Sphere::getNbParameters() const {

		return 1;
	}

	PrimitiveParams Sphere::getParameters() const {

		return PrimitiveParams(1, m_radius);
	}

	void Sphere::setParameter(size_t pIndex, float pValue) {
		if (pIndex != 0)
			throw std::range_error("Invalid parameter index for sphere. Must be 0");

		if (pValue < 0.0)
			throw std::range_error("Invalid radius value for sphere. Must be larger than 0");

		m_radius = pValue;

	}

	void Sphere::accept(Icone3DVisitorAbs & vis) const
	{
		vis.visitSphere(*this);
	}

	void Sphere::accept(Icone3DVisitorAbs & vis)
	{
		vis.visitSphere(*this);
	}

	std::ostream & Sphere::toStream(std::ostream & o) const
	{
		return o << "Sphere:    center = " << m_center << "; r = " << m_radius << ";";
	}

} // namespace PolyIcone3D