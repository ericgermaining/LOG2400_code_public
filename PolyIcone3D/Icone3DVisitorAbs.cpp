///////////////////////////////////////////////////////////
//  Icone3DVisitorAbs.cpp
//  Implementation of the Class Icone3DVisitorAbs
//  Created on:      02-nov.-2018 17:57:42
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Icone3DVisitorAbs.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Icone3DComposite.h"
#include "TransformedIcone3D.h"

namespace PolyIcone3D
{

	void Icone3DVisitorAbs::visitCube(const Cube& cub)
	{
		visitPrimitive(cub);
	}

	void Icone3DVisitorAbs::visitCylinder(const Cylinder& cyl)
	{
		visitPrimitive(cyl);
	}

	void Icone3DVisitorAbs::visitSphere(const Sphere& sph)
	{
		visitPrimitive(sph);
	}

	void Icone3DVisitorAbs::visitTransformedIcone3D(const class TransformedIcone3D& tobj)
	{
		//visitPrimitive(tobj); 
	}

	void Icone3DVisitorAbs::visitCube(class Cube& cub)
	{
		visitCube((const Cube&)cub);
	}

	void Icone3DVisitorAbs::visitCylinder(class Cylinder& cyl)
	{
		visitCylinder((const Cylinder&)cyl);
	}

	void Icone3DVisitorAbs::visitObjComposite(class Icone3DComposite& comp)
	{
		visitObjComposite((const Icone3DComposite&)comp);
	}

	void Icone3DVisitorAbs::visitSphere(class Sphere& sph)
	{
		visitSphere((const Sphere&)sph);
	}

	void Icone3DVisitorAbs::visitTransformedIcone3D(class TransformedIcone3D& tobj)
	{
		visitTransformedIcone3D((const TransformedIcone3D&)tobj);
	}

	void Icone3DVisitorAbs::visitPrimitive(PrimitiveAbs& prim)
	{
		visitPrimitive((const PrimitiveAbs&)prim);
	};

	void Icone3DVisitorAbs::defaultVisitObjComposite(const Icone3DComposite & comp)
	{
		for (auto it = comp.cbegin(); it != comp.cend(); ++it)
			it->accept(*this);
	}

} // namespace PolyIcone3D