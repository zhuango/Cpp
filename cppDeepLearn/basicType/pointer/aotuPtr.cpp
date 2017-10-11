#include <iostream>
#include <string>
using std::string;

class  ResourceNeedRelease
{
public:
	ResourceNeedRelease(string uniqueId)
		:id(uniqueId)
	{
	}
	~ResourceNeedRelease()
	{
		std::cout << "resource release ID: " << id << std::endl;
	}
private:
	std::string id;
};

class ResourceNeedReleaseFactory
{
public:
	static ResourceNeedRelease * CreateResourceNeedRelease(string uniqueId)
	{
		return new ResourceNeedRelease(uniqueId);
	}
};


void TestMethod()
{
	ResourceNeedRelease *resource = ResourceNeedReleaseFactory::CreateResourceNeedRelease("1");
	//delete resource;

	std::auto_ptr<ResourceNeedRelease> ptrToResource(ResourceNeedReleaseFactory::CreateResourceNeedRelease("2"));
}

void main()  
{
	TestMethod();
}