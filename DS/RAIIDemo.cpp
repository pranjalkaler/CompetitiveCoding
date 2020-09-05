#include <iostream>

class ResourceAllocator 
{
	public:
		int *p;
		ResourceAllocator(int val)
		{
			p = new int[val];
		}

		~ResourceAllocator()
		{
			delete[] p;
		}
};

int main(){
	ResourceAllocator ra(1);
}
