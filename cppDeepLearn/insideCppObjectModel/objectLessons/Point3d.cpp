#pragma once
#include <iostream>
using namespace std;

namespace ObjectLessons
{
	class Point3d
	{
	public:
		Point3d(float x = 0.0, float y = 0.0, float z = 0.0)
			: _x(x), _y(y), _z(z) {}
		float x() const { return _x; }
		float y() const { return _y; }
		float z() const { return _z; }

		void x(float xval) { _x = xval; }
		void y(float yval) { _y = yval; }
		void z(float zval) { _z = zval; }
	private:
		float _x;
		float _y;
		float _z;
	};

	inline ostream & operator << (ostream &os, const Point3d &pt)
	{
		os << "( " << pt.x() << ", "
			<< pt.y() << ", " << pt.z() << " )";
		return os;
	}

	void testPoint3d()
	{
		Point3d p;
		p.x(12.2);
		p.y(13.3);
		p.z(32.2);

		cout << p << endl;
	}
}
