///////////////////////////////////////////////////////////
//  SelectPrimitiveCmd.cpp
//  Implementation of the Class SelectPrimitiveCmd
//  Created on:      08-nov.-2018 21:05:02
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "SelectPrimitiveCmd.h"
#include "VisitorPrimitiveSelector.h"

namespace PolyIcone3D
{

	SelectPrimitiveCmd::SelectPrimitiveCmd(PRIMITIVE_TYPE typ, Icone3DAbs & obj3d)
		: m_type(typ), m_obj3d(obj3d)
	{
	}

	SelectPrimitiveCmd::~SelectPrimitiveCmd()
	{
	}

	void SelectPrimitiveCmd::cancel()
	{
		clearSelectIcones();
		std::cerr << "La selection a ete annulee" << std::endl;
	}


	void SelectPrimitiveCmd::execute()
	{
		VisitorPrimitiveSelector visSelec(m_type);
		m_obj3d.accept(visSelec);
		visSelec.getSelectIcones(m_selectObjContainer);
	}

	void SelectPrimitiveCmd::getSelectIcones(Obj3DIteratorContainer & objContainer)
	{
		for (auto& it : m_selectObjContainer)
			objContainer.push_back(it);
	}

} // namespace PolyIcone3D
