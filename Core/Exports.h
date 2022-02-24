#if !defined(IRID_EXPORT)
	#define IRID_EXPORT /* NOTHING */

	#if defined(WIN32) || defined(WIN64)
		#undef IRID_EXPORT
		#if defined(IRID_EXPORTS)
			#define IRID_EXPORT __declspec(dllexport)
		#else
			#define IRID_EXPORT __declspec(dllimport)
		#endif // defined(IRID_EXPORTS)
	#endif // defined(WIN32) || defined(WIN64)

	#if defined(__GNUC__) || defined(__APPLE__) || defined(LINUX)
		#if defined(IRID_EXPORTS)
			#undef IRID_EXPORT
			#define IRID_EXPORT __attribute__((visibility("default")))
		#endif // defined(IRID_EXPORTS)
	#endif // defined(__GNUC__) || defined(__APPLE__) || defined(LINUX)

#endif // !defined(IRID_EXPORT)

#ifdef IRID_ENABLE_ASSERTS
	#define IRID_ASSERT(x, ...) { if(!(x)) { IRID_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define IRID_CORE_ASSERT(x, ...) { if(!(x)) { IRID_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define IRID_ASSERT(x, ...)
	#define IRID_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define IRID_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
