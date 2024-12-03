///////////////////////////////////////////////////////////
//  SelectPrimitiveCmd.h
//  Implementation of the Class SelectPrimitiveCmd
//  Created on:      08-nov.-2018 21:05:01
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_24201D1A_E7D2_457d_9E66_340F0179D94B__INCLUDED_)
#define EA_24201D1A_E7D2_457d_9E66_340F0179D94B__INCLUDED_

#include "CommandAbs.h"
#include "Icone3DAbs.h"
#include "VisitorPrimitiveSelector.h"
#include "PrimitiveType.h"

namespace PolyIcone3D
{
	class SelectPrimitiveCmd : public CommandAbs
	{

	public:
		SelectPrimitiveCmd(PRIMITIVE_TYPE typ, Icone3DAbs& obj3d);
		virtual ~SelectPrimitiveCmd();

		virtual void cancel();
		virtual void execute();

		virtual void getSelectIcones(Obj3DIteratorContainer& objContainer);
		virtual void clearSelectIcones() { m_selectObjContainer.clear(); };

	private:
		PRIMITIVE_TYPE m_type;
		Icone3DAbs& m_obj3d;
		Obj3DIteratorContainer m_selectObjContainer;
	};
}
#endif // !defined(EA_24201D1A_E7D2_457d_9E66_340F0179D94B__INCLUDED_)
