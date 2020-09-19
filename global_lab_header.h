#ifndef GLOBAL_LAB_HEADER_H
#define GLOBAL_LAB_HEADER_H
#include <string>

namespace L1
{
	void hello();
	int main();
}

namespace L2
{
	namespace X
	{
		void fibonacci(const char* filename);
		void waiter(const char* filename);
		void sum_appender(const char* filename);
		int main();
	}
	namespace Y1
	{
		void fib();
		void notify();
		int main();
	}
	namespace Y2
	{
		void fib(std::string name);
		void notify(std::string name);
		void app(std::string name);
		int main();
	}
}

namespace L3
{
	void reader(std::string& filename);
	void writer();
	int main();
}

#endif // GLOBAL_LAB_HEADER_H
