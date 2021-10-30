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

#define BIT(x) (1 << x)