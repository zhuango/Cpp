// driverTri.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::string;
using namespace std;

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
	std::string id;
};

class ResourceNeedReleaseFactory
{
public:
	//will new a instance of resource.
	static ResourceNeedRelease * CreateResourceNeedRelease(string uniqueId)
	{
		return new ResourceNeedRelease(uniqueId);
	}
};

// std::auto_ptr’ is deprecated deprecated.
void TestAutoPtrMethod()
{
	ResourceNeedRelease *resource = ResourceNeedReleaseFactory::CreateResourceNeedRelease("1");
	//delete resource;

	std::auto_ptr<ResourceNeedRelease> ptrToResource(ResourceNeedReleaseFactory::CreateResourceNeedRelease("2"));
	if(ptrToResource.get() != NULL)
	{
		std::cout << "pointer has been set." << std::endl;
	}

	std::auto_ptr<ResourceNeedRelease> ptr2(ptrToResource);
	if(ptrToResource.get() == NULL)
	{
		std::cout << "pointer has been removed." << std::endl;
	}
	//not normal copy behavior, remove copy maintain the pointer being managed by only on auto_ptr.
	ptrToResource = ptr2;
	if(ptr2.get() == NULL)
	{
		std::cout << "ptr2 is null." << std::endl;
	}
}
void TestSharePtrMethod()
{
	std::shared_ptr<ResourceNeedRelease> finalPointer;
	std::shared_ptr<ResourceNeedRelease> ptrToResource(ResourceNeedReleaseFactory::CreateResourceNeedRelease("2"));
	std::shared_ptr<ResourceNeedRelease> ptrToResource2(ptrToResource);
	ptrToResource.get()->id = "4";
	// id = 4
	std::cout << ptrToResource2.get()->id << std::endl;

	finalPointer = ptrToResource2;
	// print 3, finalPointer ptrToResource2 ptrToResource.
	std::cout << finalPointer.use_count() << std::endl;
	// ptrToResource2 release the pointer.
	ptrToResource2.~shared_ptr();
	// print 2, ptrToResource2 release the pointer.
	std::cout << finalPointer.use_count() << std::endl;
	try
	{
		std::cout << ptrToResource.get()->id << std::endl;
	}
	catch(...)
	{
		std::cout << "another point is bad." << std::endl;
	}
	std::cout << finalPointer.use_count() << std::endl;
	if (finalPointer.unique())
	{
		cout << "final pointer is unique pointer to object." << endl;
	}
}

void TestMakeSharedMethod1()
{
	int a = 100;
	auto ptr = make_shared<int>(a);
}

int main()
{
	TestAutoPtrMethod();
	cout << "++++++++++++++++++++++++++++" << endl;
	TestSharePtrMethod();
	return 0;
}