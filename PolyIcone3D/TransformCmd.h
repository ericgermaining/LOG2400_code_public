///////////////////////////////////////////////////////////
//  TransformCmd.h
//  Implementation of the Class TransformCmd
//  Created on:      08-nov.-2018 21:05:10
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_074942D3_3CE7_4e21_8AF1_7B621E4A7592__INCLUDED_)
#define EA_074942D3_3CE7_4e21_8AF1_7B621E4A7592__INCLUDED_

#include "CommandAbs.h"
#include "Icone3DAbs.h"

namespace PolyIcone3D
{
	class TransformCmd : public CommandAbs
	{

	public:
		TransformCmd(Icone3DIterator objIter, const Point3D& translat, float scal);
		virtual ~TransformCmd();

		virtual void cancel();
		virtual void execute();

	private:
		Icone3DIterator m_objIter;
		Point3D m_translate;
		float m_scale;
	};
}
#endif // !defined(EA_074942D3_3CE7_4e21_8AF1_7B621E4A7592__INCLUDED_)
