#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct VarStructure
{
	char str[1];
}VarStructure;

class VarClass
{
public:
protected:
private:
	char str[1];
};
void testVarLengthArray()
{
	VarStructure *vs = (VarStructure*)malloc(sizeof(VarStructure) + 10);
	strcpy_s(vs->str, 8, "liuzhuang");
	printf("%d\n", sizeof(vs));
	//printf("%c\n", vs->str[4]);

	VarClass *vc = (VarClass*)malloc(sizeof(VarClass) + 10);
	strcpy_s((char*)vc, 8, "liuzhuang");
}
