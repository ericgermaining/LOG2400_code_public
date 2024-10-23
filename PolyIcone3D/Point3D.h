///////////////////////////////////////////////////////////
//  Point3D.h
//  Implementation of the Class Point3D
//  Created on:      12-mars-2018 21:52:37
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_EC549877_0E18_4d65_9501_C16390E0E256__INCLUDED_)
#define EA_EC549877_0E18_4d65_9501_C16390E0E256__INCLUDED_

#include <iostream>

namespace PolyIcone3D
{
	class Point3D
	{

	public:
		Point3D(float x = 0.0, float y = 0.0, float z = 0.0);

		const float* coords(void) const { return m_coord; }
		const float& x(void) const { return m_coord[0]; }
		const float& y(void) const { return m_coord[1]; }
		const float& z(void) const { return m_coord[2]; }
		float* coords(void) { return m_coord; }
		float& x(void) { return m_coord[0]; }
		float& y(void) { return m_coord[1]; }
		float& z(void) { return m_coord[2]; }

		Point3D& operator*=(float fact);
		Point3D& operator/=(float divid);
		Point3D& operator+=(const Point3D& pt);

	private:
		float m_coord[3];
	};

	std::ostream& operator<<(std::ostream& o, const Point3D& s);
	Point3D operator+(const Point3D& p1, const Point3D& p2);
	Point3D operator-(const Point3D& p1, const Point3D& p2);
	bool operator==(const Point3D& p1, const Point3D& p2);
	bool operator!=(const Point3D& p1, const Point3D& p2);
}
#endif // !defined(EA_EC549877_0E18_4d65_9501_C16390E0E256__INCLUDED_)
