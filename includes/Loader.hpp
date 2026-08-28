#pragma once

#include "datatypes/RString.hpp"

#include <cstdio>

class Loader {

public:

                Loader                  ();
                ~Loader                 ();

    bool        OpenFileRO              ();
    void        CloseFile               ();
    void        SetFilePath             (RString& pFilePath);

    template <typename ParserType>
    bool        ParseFile               ();

private:

    int         InternalReadAndAdvance  ();

    
    int         vCursor;
    RString     vFilePath;
    FILE*       vHandle;
};