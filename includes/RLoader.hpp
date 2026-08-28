#pragma once

#include "RCppUtilsLib.hpp"

#include <cstdio>

#define         FILE_BUFF_SIZE          16 // 16B

class RLoader {

public:

                RLoader                 ();
                ~RLoader                ();

    bool        OpenFileRO              ();
    void        CloseFile               ();
    void        SetFilePath             (RString& pFilePath);

    template <typename ParserType>
    bool        ParseFile               ();

    int         ReadAndAdvance          ();

private:
    
    RString     vFilePath;
    FILE*       vHandle;

    size_t      vCursor;
    size_t      vBytesRead;
    char*       vFileBuffer;
};

#include "RLoader.hxx"