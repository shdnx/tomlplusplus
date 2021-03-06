#ifdef TARTANLLAMA_OPTIONAL
	#if __has_include(<tloptional/include/tl/optional.hpp>)
		#include <tloptional/include/tl/optional.hpp>
	#else
		#error TartanLlama/optional is missing! You probably need to fetch submodules ("git submodule update --init extern/tloptional")
	#endif
	#define TOML_OPTIONAL_TYPE tl::optional
#endif

#include <cassert> //so TOML_ASSERT() maps to assert()
#define TOML_ALL_INLINE 0
#define TOML_IMPLEMENTATION
#include "../include/toml++/toml.h"

#define CATCH_CONFIG_RUNNER
#include "catch2.h"

int main(int argc, char* argv[])
{
	#ifdef _WIN32
	SetConsoleOutputCP(65001);
	#endif

	return Catch::Session().run(argc, argv);
}
