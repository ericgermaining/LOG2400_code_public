///////////////////////////////////////////////////////////
//  VisitorPrimitiveSelector.h
//  Implementation of the Class VisitorPrimitiveSelector
//  Created on:      07-nov.-2018 21:20:38
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_27096F43_E15A_4f6a_8F5C_7F9753E53238__INCLUDED_)
#define EA_27096F43_E15A_4f6a_8F5C_7F9753E53238__INCLUDED_

#include <list>

#include "Icone3DVisitorAbs.h"
#include "Icone3DContainer.h"
#include "PrimitiveType.h"

namespace PolyIcone3D
{
	// Configuration d'un conteneur d'iterateurs sur des objets
	using Obj3DIteratorContainer = std::list<Icone3DIterator>;

	class VisitorPrimitiveSelector : public Icone3DVisitorAbs
	{

	public:
		VisitorPrimitiveSelector(PRIMITIVE_TYPE typ);
		virtual ~VisitorPrimitiveSelector();

		virtual void setType(PRIMITIVE_TYPE typ) { m_type = typ; }
		virtual PRIMITIVE_TYPE getType() { return m_type; }

		virtual void visitObjComposite(const class Icone3DComposite& comp);

		virtual void visitCube(class Cube& cub);
		virtual void visitCylinder(class Cylinder& cyl);
		virtual void visitObjComposite(class Icone3DComposite& comp);
		virtual void visitSphere(class Sphere& sph);
		virtual void visitTransformedIcone3D(class TransformedIcone3D& tobj);

		virtual void getSelectIcones(Obj3DIteratorContainer& objContainer);
		virtual void clearSelectIcones() { m_selectObjContainer.clear(); };

	protected:
		virtual void visitPrimitive(const class PrimitiveAbs& prim);
		virtual void visitPrimitive(class PrimitiveAbs& prim);

		PRIMITIVE_TYPE m_type;
		Obj3DIteratorContainer m_currentObjStack;
		Obj3DIteratorContainer m_selectObjContainer;
	};
}
#endif // !defined(EA_27096F43_E15A_4f6a_8F5C_7F9753E53238__INCLUDED_)
