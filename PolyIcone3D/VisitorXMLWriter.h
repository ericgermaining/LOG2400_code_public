///////////////////////////////////////////////////////////
//  VisitorXMLWriter.h
//  Implementation of the Class VisitorXMLWriter
//  Created on:      07-nov.-2018 11:41:44
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_7F5A2279_5330_4346_887A_F677087C8B1F__INCLUDED_)
#define EA_7F5A2279_5330_4346_887A_F677087C8B1F__INCLUDED_

#include "Icone3DVisitorAbs.h"

namespace PolyIcone3D
{
	class VisitorXMLWriter : public Icone3DVisitorAbs
	{

	public:
		VisitorXMLWriter(std::ostream& o);
		virtual ~VisitorXMLWriter();

		// Seules les methodes traitant des objets const sont definies
		// Par defaut, les methodes traitant des objets non-const pointent sur celles-ci
		virtual void visitCube(const class Cube& cub);
		virtual void visitCylinder(const class Cylinder& cyl);
		virtual void visitObjComposite(const class Icone3DComposite& comp);
		virtual void visitSphere(const class Sphere& sph);
		virtual void visitTransformedIcone3D(const class TransformedIcone3D& tobj);

	protected:
		virtual void visitPrimitive(const class PrimitiveAbs& prim);
		std::ostream& indentation(void);
		std::ostream& outputPoint(const std::string& tag, const class Point3D& c) const;

		std::ostream& m_outputStream;
		size_t m_indentLevel;
	};
}
#endif // !defined(EA_7F5A2279_5330_4346_887A_F677087C8B1F__INCLUDED_)
