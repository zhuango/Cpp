// driverTri.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <memory>

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
std::tr1::shared_ptr<ResourceNeedRelease> finalPointer;
void TestSharePtrMethod()
{
	std::tr1::shared_ptr<ResourceNeedRelease> ptrToResource(ResourceNeedReleaseFactory::CreateResourceNeedRelease("2"));
	std::tr1::shared_ptr<ResourceNeedRelease> ptrToResource2(ptrToResource);
	ptrToResource.get()->id = "4";
	std::cout << ptrToResource2.get()->id << std::endl;

	finalPointer = ptrToResource2;
	std::cout << finalPointer.use_count() << std::endl;
	ptrToResource2.~shared_ptr();
	
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
}

void main()
{
	TestAutoPtrMethod();
	TestSharePtrMethod();

	ResourceNeedRelease *p = finalPointer.get();
	std::cout << finalPointer.use_count() << std::endl;
	if(finalPointer.get() != NULL)
	{
		try 
		{
			std::cout << finalPointer.get()->id << std::endl;
			throw 1;
		}
		catch(...)
		{
		}
	}
	finalPointer.~shared_ptr();
}