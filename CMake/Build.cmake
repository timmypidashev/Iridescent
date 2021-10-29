
# MultiConfig generator detection
get_property(IRID_GENERATOR_IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(IRID_GENERATOR_IS_MULTI_CONFIG)
    message(STATUS "Current CMake generator is multi-config generator(${CMAKE_GENERATOR})")
    message(STATUS "CMAKE_BUILD_TYPE variable is ignored!")
else ()
	message(STATUS "Current CMake generator is single-config generator(${CMAKE_GENERATOR})")
endif ()

# Updating Build types
set(CUSTOM_BUILD_TYPES "Debug;Release")
if(IRID_GENERATOR_IS_MULTI_CONFIG)
    foreach (BUILD_TYPE IN LISTS CUSTOM_BUILD_TYPES)
        if (NOT "${BUILD_TYPE}" IN_LIST CMAKE_CONFIGURATION_TYPES)
            set(CMAKE_CONFIGURATION_TYPES ${CUSTOM_BUILD_TYPES} CACHE STRING "" FORCE)
        endif ()
    endforeach ()
else ()
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${CUSTOM_BUILD_TYPES}")

    if (NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
    elseif (NOT CMAKE_BUILD_TYPE IN_LIST CUSTOM_BUILD_TYPES)
        message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE} (Supported: ${CUSTOM_BUILD_TYPES})")
    endif ()
endif ()

foreach (BUILD_TYPE IN LISTS CUSTOM_BUILD_TYPES)
	string(TOUPPER "${BUILD_TYPE}" BUILD_TYPE_UPPERCASE)
	set(CMAKE_SHARED_LINKER_FLAGS_${BUILD_TYPE_UPPERCASE} "${DEFAULT_LINKER_OPTIONS}")
	set(CMAKE_EXE_LINKER_FLAGS_${BUILD_TYPE_UPPERCASE} "${DEFAULT_LINKER_OPTIONS}")
endforeach ()