///////////////////////////////////////////////////////////
//  PrimitiveAbs.h
//  Implementation of the Class PrimitiveAbs
//  Created on:      25-oct.-2018 20:47:13
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_6BDCBA85_2DD8_4e3e_B271_E0601FF9CA6C__INCLUDED_)
#define EA_6BDCBA85_2DD8_4e3e_B271_E0601FF9CA6C__INCLUDED_

#include "Icone3DAbs.h"

namespace PolyIcone3D
{
	class PrimitiveAbs : public Icone3DAbs
	{
	public:
		PrimitiveAbs(const Point3D& pt);
		PrimitiveAbs(Icone3DAbs& parent);
		PrimitiveAbs(Icone3DAbs& parent, const Point3D& pt);
		virtual ~PrimitiveAbs();
		virtual PrimitiveAbs* clone(Icone3DAbs& parent) const = 0;

		// Toutes les methodes de gestion des enfants ne font rien
		virtual void addChild(const Icone3DAbs& obj3d);
		virtual Icone3DIterator begin();
		virtual Icone3DIterator_const cbegin() const;
		virtual Icone3DIterator_const cend() const;
		virtual Icone3DIterator end();
		virtual void removeChild(Icone3DIterator_const obj3dIt);
		virtual void replaceChild(Icone3DIterator obj3dIt, const Icone3DAbs& newObj);

		virtual Point3D getCenter() const;
		virtual void moveCenter(const Point3D& delta);
		virtual void setCenter(const Point3D& center);

		virtual void accept(class Icone3DVisitorAbs& vis) const;
		virtual void accept(class Icone3DVisitorAbs& vis);

	protected:
		Point3D m_center;

	private:
		static Icone3DContainer m_emptyContainer;
	};
}
#endif // !defined(EA_6BDCBA85_2DD8_4e3e_B271_E0601FF9CA6C__INCLUDED_)
