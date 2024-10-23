///////////////////////////////////////////////////////////
//  Icone3DComposite.h
//  Implementation of the Class Icone3DComposite
//  Created on:      25-oct.-2018 20:40:33
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_B3F4EF6C_5851_4239_9FC3_5E8BB6446332__INCLUDED_)
#define EA_B3F4EF6C_5851_4239_9FC3_5E8BB6446332__INCLUDED_

#include "Icone3DAbs.h"

namespace PolyIcone3D
{
	class Icone3DComposite : public Icone3DAbs
	{

	public:
		Icone3DComposite();
		Icone3DComposite(Icone3DAbs& parent);
		Icone3DComposite(Icone3DAbs& parent, const Icone3DComposite& mdd);
		virtual ~Icone3DComposite();
		virtual Icone3DComposite* clone(Icone3DAbs& parent) const;

		virtual void addChild(const Icone3DAbs& obj3d);
		virtual Icone3DIterator begin();
		virtual Icone3DIterator_const cbegin() const;
		virtual Icone3DIterator_const cend() const;
		virtual Icone3DIterator end();
		virtual void removeChild(Icone3DIterator_const obj3dIt);
		virtual void replaceChild(Icone3DIterator obj3dIt, const Icone3DAbs& newObj);

		virtual void accept(class Icone3DVisitorAbs& vis) const;
		virtual void accept(class Icone3DVisitorAbs& vis);

		virtual Point3D getCenter() const;
		virtual void moveCenter(const Point3D& delta);
		virtual void setCenter(const Point3D& center);

		virtual size_t getNbParameters() const;
		virtual PrimitiveParams getParameters() const;
		virtual void setParameter(size_t pIndex, float pValue);

	protected:
		Point3D computeCenter() const;
		Icone3DContainer m_iconeContainer;
	};
}
#endif // !defined(EA_B3F4EF6C_5851_4239_9FC3_5E8BB6446332__INCLUDED_)
