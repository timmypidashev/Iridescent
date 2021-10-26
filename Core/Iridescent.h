#pragma once

#ifdef TARGET_PLATFORM_WINDOWS
    #define IRIDESCENT_API __declspec(dllexport)
#else
    #define IRIDESCENT_API __declspec(dllexport)
#endif

namespace Iridescent  
{

    class IRIDESCENT_API Iridescent 
    {
    public:

        // Constructor
        Iridescent();

        // Virtual Destructor
        virtual ~Iridescent();

        // Run
        void Run();
    };
}