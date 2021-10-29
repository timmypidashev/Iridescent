# Create defines based on platform
if (CMAKE_SYSTEM_NAME MATCHES "Windows") 
	set(TARGET_PLATFORM_WINDOWS 1) 
	add_compile_definitions(TARGET_PLATFORM_WINDOWS)
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
	set(TARGET_PLATFORM_LINUX 1)
	add_compile_definitions(TARGET_PLATFORM_LINUX)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
	set(TARGET_PLATFORM_MACOS 1)
	add_compile_definitions(TARGET_PLATFORM_MACOS)
elseif (CMAKE_SYSTEM_NAME MATCHES "Xbone")
	set(TARGET_PLATFORM_XBONE 1)
	add_compile_definitions(TARGET_PLATFORM_XBONE)
endif ()


