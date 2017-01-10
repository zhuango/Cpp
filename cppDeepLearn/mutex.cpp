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

class Mutex
{
public:
	bool mutex;
};

class Locker
{
public:
	Locker(Mutex &mutex)
		:mMutex(&mutex, unlock)
	{
		lock(mMutex.get());
	}
private:
	static void lock(Mutex *mMutex)
	{
		mMutex->mutex = true;
		std::cout << "lock it." << std::endl;
	}
	static void unlock(Mutex *mMutex)
	{
		mMutex->mutex = false;
		std::cout << "unlock it." << std::endl;
	}
	std::tr1::shared_ptr<Mutex> mMutex;
};

void testLocker()
{
	Mutex mutex;
	Locker *locker = new Locker(mutex);
	Locker locker2 = *locker;
	delete locker;
	//do something.

}

void main()
{
	testLocker();
}