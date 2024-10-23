///////////////////////////////////////////////////////////
//  TransformedIcone3D.h
//  Implementation of the Class TransformedIcone3D
//  Created on:      26-oct.-2018 17:42:18
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_DC6E4A6D_4996_480d_BD21_2346CACBC75F__INCLUDED_)
#define EA_DC6E4A6D_4996_480d_BD21_2346CACBC75F__INCLUDED_

#include "PrimitiveAbs.h"

namespace PolyIcone3D
{
	class TransformedIcone3D : public PrimitiveAbs
	{

	public:
		TransformedIcone3D(const PrimitiveAbs& primitiv, const Point3D& translat, float scal);
		TransformedIcone3D(Icone3DAbs& parent, const PrimitiveAbs& primitiv, const Point3D& translat, float scal);
		TransformedIcone3D(Icone3DAbs& parent, const TransformedIcone3D& mdd);
		virtual ~TransformedIcone3D();
		virtual TransformedIcone3D* clone(Icone3DAbs& parent) const;

		virtual void addChild(const Icone3DAbs& obj3d);
		virtual Icone3DIterator begin();
		virtual Icone3DIterator_const cbegin() const;
		virtual Icone3DIterator_const cend() const;
		virtual Icone3DIterator end();
		virtual void removeChild(Icone3DIterator_const obj3dIt);

		virtual void accept(class Icone3DVisitorAbs& vis);
		virtual void accept(class Icone3DVisitorAbs& vis) const;

		virtual Point3D getCenter() const;
		virtual void moveCenter(const Point3D& delta);
		virtual void setCenter(const Point3D& center);

		virtual size_t getNbParameters() const;
		virtual PrimitiveParams getParameters() const;
		virtual void setParameter(size_t pIndex, float pValue);

		virtual float getScale() const;
		virtual void setScale(float scal);
		virtual Point3D getTranslation() const;
		virtual void setTranslation(const Point3D& translat);
		virtual PrimitiveAbs& getIcone3D();
		virtual const PrimitiveAbs& getIcone3D() const;

	private:
		float m_scale;
		Point3D m_translation;
		std::unique_ptr<PrimitiveAbs> m_Icone3d;
	};
}
#endif // !defined(EA_DC6E4A6D_4996_480d_BD21_2346CACBC75F__INCLUDED_)
