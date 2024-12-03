///////////////////////////////////////////////////////////
//  XMLPrintCmd.cpp
//  Implementation of the Class XMLPrintCmd
//  Created on:      08-nov.-2018 21:04:53
//  Original author: p482457
///////////////////////////////////////////////////////////

#include <iostream>

#include "XMLPrintCmd.h"
#include "VisitorXMLWriter.h"

namespace PolyIcone3D
{

	XMLPrintCmd::XMLPrintCmd(const Icone3DAbs & obj3d)
		: m_obj3d(obj3d)
	{
	}

	void XMLPrintCmd::cancel()
	{
		std::cerr << "La commande print n'est pas annulable" << std::endl;
	}


	void XMLPrintCmd::execute()
	{
		VisitorXMLWriter visWriter(std::cout);
		m_obj3d.accept(visWriter);
	}

} // namespace PolyIcone3D