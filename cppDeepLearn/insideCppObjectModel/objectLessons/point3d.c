#include <stdio.h>

typedef struct point3d
{
	float x;
	float y;
	float z;
} Point3d;

void Point3dPrintFunc(const Point3d *pd)
{
	printf("(%g, %g, %g)", pd->x, pd->y, pd->z);
}
// more efficient
#define Point3d_print(pd) \
	printf("(%g, %g, %g)", pd->x, pd->y, pd->z);

#define X(pd, xval) (pd.x) = (xval)

void testPointFunc()
{
	Point3d p;
	p.y = 123.4;
	p.z = 12.3;
	p.x = 10.2;

	Point3dPrintFunc(&p);

	Point3d *pp = &p;
	Point3d_print(pp);
}