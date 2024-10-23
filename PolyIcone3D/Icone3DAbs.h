///////////////////////////////////////////////////////////
//  Icone3DAbs.h
//  Implementation of the Class Icone3DAbs
//  Created on:      25-oct.-2018 10:31:08
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_631D7BD7_EE02_4efc_B70C_753FF41F2621__INCLUDED_)
#define EA_631D7BD7_EE02_4efc_B70C_753FF41F2621__INCLUDED_

#include <iostream>

#include "Point3D.h"
#include "Icone3DContainer.h"

namespace PolyIcone3D
{
	class Icone3DAbs
	{
	public:
		Icone3DAbs() : m_parent(*this) {};
		Icone3DAbs(Icone3DAbs& parent) : m_parent(parent) {};
		virtual ~Icone3DAbs() = default;
		virtual Icone3DAbs* clone(Icone3DAbs& parent) const = 0;

		virtual void addChild(const Icone3DAbs& obj3d) = 0;
		virtual Icone3DIterator begin() = 0;
		virtual Icone3DIterator_const cbegin() const = 0;
		virtual Icone3DIterator_const cend() const = 0;
		virtual Icone3DIterator end() = 0;
		virtual void removeChild(Icone3DIterator_const obj3dIt) = 0;
		virtual void replaceChild(Icone3DIterator obj3dIt, const Icone3DAbs& newObj) = 0;

		virtual void accept(class Icone3DVisitorAbs& vis) = 0;
		virtual void accept(class Icone3DVisitorAbs& vis) const = 0;

		virtual Point3D getCenter() const = 0;
		virtual void moveCenter(const Point3D& delta) = 0;
		virtual void setCenter(const Point3D& center) = 0;

		virtual size_t getNbParameters() const = 0;
		virtual PrimitiveParams getParameters() const = 0;
		virtual void setParameter(size_t pIndex, float pValue) = 0;

		virtual bool isRoot() const { return (&m_parent == this); }
		virtual const Icone3DAbs& getParent() const { return m_parent; }
		virtual Icone3DAbs& getParent() { return m_parent; }

	protected:
		Icone3DAbs& m_parent;
	};
}

#endif // !defined(EA_631D7BD7_EE02_4efc_B70C_753FF41F2621__INCLUDED_)
