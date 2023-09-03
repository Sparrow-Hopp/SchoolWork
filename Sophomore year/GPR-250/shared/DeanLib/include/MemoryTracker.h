#pragma once

#include <map>
#include <iostream>


struct AllocationRecord
{
	AllocationRecord( int theNum, size_t theSize ): num(theNum), size(theSize){};
	int num;
	size_t size;
};

class MemoryTracker
{
public:
	static MemoryTracker* getInstance();
	void addAllocation( void* ptr, size_t size );
	void removeAllocation( void* ptr );
	
	void reportAllocations( std::ostream& stream );

private:
	MemoryTracker();
	~MemoryTracker();

	//copying not allowed
	MemoryTracker( const MemoryTracker& );
	MemoryTracker& operator=( const MemoryTracker& );

	std::map<void*,AllocationRecord> mAllocations;

	static int msAllocationNum;
	static MemoryTracker* mspInstance;
};

