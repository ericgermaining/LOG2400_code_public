///////////////////////////////////////////////////////////
//  Cube.cpp
//  Implementation of the Class Cube
//  Created on:      25-oct.-2018 20:47:57
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Cube.h"
#include "Icone3DVisitorAbs.h"

namespace PolyIcone3D
{

	Cube::Cube(const Point3D & pt, float ln, float lg, float ht)
		: PrimitiveAbs(pt)
	{
		if (ln < 0.0 || lg < 0.0 || ht < 0.0)
			throw std::range_error("Invalid dimension value for cube. Must be larger than 0");

		m_dimensions[0] = ln;
		m_dimensions[1] = lg;
		m_dimensions[2] = ht;
	}

	Cube::Cube(Icone3DAbs& parent, const Point3D& pt, float ln, float lg, float ht)
		: PrimitiveAbs(parent, pt)
	{
		if (ln < 0.0 || lg < 0.0 || ht < 0.0)
			throw std::range_error("Invalid dimension value for cube. Must be larger than 0");

		m_dimensions[0] = ln;
		m_dimensions[1] = lg;
		m_dimensions[2] = ht;
	}

	Cube::Cube(Icone3DAbs & parent, const Cube & cub)
		: PrimitiveAbs(parent, cub.m_center)
	{
		m_dimensions[0] = cub.m_dimensions[0];
		m_dimensions[1] = cub.m_dimensions[1];
		m_dimensions[2] = cub.m_dimensions[2];
	}

	Cube::~Cube() {

	}

	Cube * Cube::clone(Icone3DAbs& parent) const
	{
		return new Cube(parent, *this);
	}

	size_t Cube::getNbParameters() const {

		return 3;
	}

	PrimitiveParams Cube::getParameters() const
	{
		PrimitiveParams params;
		params.push_back(m_dimensions[0]);
		params.push_back(m_dimensions[1]);
		params.push_back(m_dimensions[2]);

		return params;
	}

	void Cube::setParameter(size_t pIndex, float pValue) {
		if (pIndex < 0 || pIndex > 2)
			throw std::range_error("Invalid parameter index for cube. Must be between 0 and 2");

		if (pValue < 0.0)
			throw std::range_error("Invalid dimension value for cube. Must be larger than 0");

		m_dimensions[pIndex] = pValue;
	}

	void Cube::accept(Icone3DVisitorAbs & vis) const
	{
		vis.visitCube(*this);
	}

	void Cube::accept(Icone3DVisitorAbs & vis)
	{
		vis.visitCube(*this);
	}

	std::ostream & Cube::toStream(std::ostream & o) const
	{
		return o << "Cube:      center = " << m_center
			<< "; ln = " << m_dimensions[0]
			<< "; lg = " << m_dimensions[1]
			<< "; ht = " << m_dimensions[2] << ";";
	}

} // namespace PolyIcone3D
