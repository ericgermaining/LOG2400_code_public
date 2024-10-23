///////////////////////////////////////////////////////////
//  Sphere.h
//  Implementation of the Class Sphere
//  Created on:      25-oct.-2018 20:47:54
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_04686388_23AD_43a5_8FD6_FCF2B104C036__INCLUDED_)
#define EA_04686388_23AD_43a5_8FD6_FCF2B104C036__INCLUDED_

#include "PrimitiveAbs.h"

namespace PolyIcone3D
{
	class Sphere : public PrimitiveAbs
	{

	public:
		Sphere(const Point3D& pt, float r);
		Sphere(Icone3DAbs& parent, const Point3D& pt, float r);
		Sphere(Icone3DAbs& parent, const Sphere& sph);
		virtual ~Sphere();
		virtual Sphere* clone(Icone3DAbs& parent) const;

		virtual size_t getNbParameters() const;
		virtual PrimitiveParams getParameters() const;
		virtual void setParameter(size_t pIndex, float pValue);

		virtual void accept(class Icone3DVisitorAbs& vis) const;
		virtual void accept(class Icone3DVisitorAbs& vis);

	private:
		virtual std::ostream& toStream(std::ostream& o) const;

		float m_radius;
	};
}
#endif // !defined(EA_04686388_23AD_43a5_8FD6_FCF2B104C036__INCLUDED_)
