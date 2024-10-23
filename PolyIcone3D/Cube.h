///////////////////////////////////////////////////////////
//  Cube.h
//  Implementation of the Class Cube
//  Created on:      25-oct.-2018 20:47:57
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_8099F38C_C8A3_47d0_948F_F38A0B83FFB2__INCLUDED_)
#define EA_8099F38C_C8A3_47d0_948F_F38A0B83FFB2__INCLUDED_

#include "PrimitiveAbs.h"

namespace PolyIcone3D
{
	class Cube : public PrimitiveAbs
	{

	public:
		Cube(const Point3D& pt, float ln, float lg, float ht);
		Cube(Icone3DAbs& parent, const Point3D& pt, float ln, float lg, float ht);
		Cube(Icone3DAbs& parent, const Cube& cub);
		virtual ~Cube();
		virtual Cube* clone(Icone3DAbs& parent) const;

		virtual size_t getNbParameters() const;
		virtual PrimitiveParams getParameters() const;
		virtual void setParameter(size_t pIndex, float pValue);

		virtual void accept(class Icone3DVisitorAbs& vis) const;
		virtual void accept(class Icone3DVisitorAbs& vis);

	private:
		virtual std::ostream& toStream(std::ostream& o) const;

		float m_dimensions[3];
	};
}
#endif // !defined(EA_8099F38C_C8A3_47d0_948F_F38A0B83FFB2__INCLUDED_)
