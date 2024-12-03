///////////////////////////////////////////////////////////
//  VisitorXMLWriter.cpp
//  Implementation of the Class VisitorXMLWriter
//  Created on:      07-nov.-2018 11:41:44
//  Original author: francois
///////////////////////////////////////////////////////////

#include <iostream>

#include "VisitorXMLWriter.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Icone3DComposite.h"
#include "TransformedIcone3D.h"

namespace PolyIcone3D
{

	VisitorXMLWriter::VisitorXMLWriter(std::ostream& o)
		: m_outputStream(o), m_indentLevel(0)
	{
	}

	VisitorXMLWriter::~VisitorXMLWriter()
	{
	}

	std::ostream& VisitorXMLWriter::indentation()
	{
		for (auto iindent = 0; iindent < m_indentLevel; ++iindent)
			m_outputStream << "\t";
		return m_outputStream;
	}

	std::ostream& VisitorXMLWriter::outputPoint(const std::string& tag, const Point3D & c) const
	{
		return m_outputStream << "<Center x=\"" << c.x() << "\" y= \"" << c.y() << "\" z= \"" << c.z() << "\" />";
	}

	void VisitorXMLWriter::visitCube(const Cube& cub)
	{
		PrimitiveParams params = cub.getParameters();
		indentation() << "<Cube length=\"" << params[0]
			<< "\" width=\"" << params[1]
			<< "\" heigth=\"" << params[2] << "\">" << std::endl; ++m_indentLevel;
		indentation(); outputPoint("Center", cub.getCenter()) << std::endl; --m_indentLevel;
		indentation() << "</Cube>" << std::endl;
	}

	void VisitorXMLWriter::visitCylinder(const class Cylinder& cyl)
	{
		PrimitiveParams params = cyl.getParameters();
		indentation() << "<Cylinder radius=\"" << params[0]
			<< "\" heigth=\"" << params[1] << "\">" << std::endl; ++m_indentLevel;
		indentation(); outputPoint("Center", cyl.getCenter()) << std::endl; --m_indentLevel;
		indentation() << "</Cylinder>" << std::endl;
	}


	void VisitorXMLWriter::visitObjComposite(const Icone3DComposite& comp)
	{
		indentation() << "<Composite>" << std::endl;
		++m_indentLevel;
		defaultVisitObjComposite(comp);
		--m_indentLevel;
		indentation() << "</Composite>" << std::endl;
	}

	void VisitorXMLWriter::visitPrimitive(const PrimitiveAbs& prim)
	{
		PrimitiveParams params = prim.getParameters();
		indentation() << "<Primitive>" << std::endl; ++m_indentLevel;
		for (auto i = 0; i < prim.getNbParameters(); ++i)
			indentation() << "<Param>" << params[i] << "</Param>" << std::endl;
		indentation(); outputPoint("Center", prim.getCenter()) << std::endl; --m_indentLevel;
		indentation() << "</Primitive>" << std::endl;
	}

	void VisitorXMLWriter::visitSphere(const Sphere& sph)
	{
		PrimitiveParams params = sph.getParameters();
		indentation() << "<Sphere radius=\"" << params[0] << "\">" << std::endl; ++m_indentLevel;
		indentation(); outputPoint("Center", sph.getCenter()) << std::endl; --m_indentLevel;
		indentation() << "</Sphere>" << std::endl;
	}

	void VisitorXMLWriter::visitTransformedIcone3D(const class TransformedIcone3D& tobj)
	{
		indentation() << "<Transformed>" << std::endl; ++m_indentLevel;
		indentation() << "<Scale factor=\"" << tobj.getScale() << "\"/>" << std::endl;
		indentation(); outputPoint("Translation", tobj.getTranslation()) << std::endl;
		tobj.getIcone3D().accept(*this);
		--m_indentLevel;
		indentation() << "</Transformed>" << std::endl;
	}

} // namespace PolyIcone3D