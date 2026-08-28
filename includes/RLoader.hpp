#pragma once

#include "RCppUtilsLib.hpp"

#include <cstdio>

class RLoader {

public:

                RLoader                 ();
                ~RLoader                ();

    bool        OpenFileRO              ();
    void        CloseFile               ();
    void        SetFilePath             (RString& pFilePath);

    template <typename ParserType>
    bool        ParseFile               ();

    int         ReadAndAdvance  ();

private:
    
    int         vCursor;
    RString     vFilePath;
    FILE*       vHandle;
};

#include "RLoader.hxx"