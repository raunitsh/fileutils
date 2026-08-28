#include "includes/Loader.hpp"

int
main ()
{
        Loader  loader;
        FILE*   handle;
        RString path;

    path.SetString ("../test.json");
    
    loader.SetFilePath (path);
    loader.OpenFileRO ();
    
    return 0;
}