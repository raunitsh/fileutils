#include "RLoader.hpp"


RLoader::RLoader ()
{
    vFilePath.SetString ("");
    vHandle = nullptr;
    vFileBuffer = nullptr;
    vCursor = 0;
    vBytesRead = 0;
}

RLoader::~RLoader ()
{
    if (vFileBuffer)
    {
        delete[] vFileBuffer;
    }

    vCursor = 0;
    vBytesRead = 0;
    vFileBuffer = nullptr;
    vHandle = nullptr;
}

void
RLoader::SetFilePath (RString& pFilePath)
{
    vFilePath.SetString (pFilePath.GetPointer ());
}

bool
RLoader::OpenFileRO ()
{    
    vHandle = fopen (vFilePath.GetPointer (), "rb");    
    vFileBuffer = new char [FILE_BUFF_SIZE];

    if (!vHandle || !vFileBuffer)
    {
        return false;
    }

    vCursor = 0;
    vBytesRead = 0;

    return true;
}

void
RLoader::CloseFile ()
{
    if (vHandle)
    {
        fclose (vHandle);
        vHandle = nullptr;
    }

    if (vFileBuffer)
    {
        delete[] vFileBuffer;
        vFileBuffer = nullptr;
    }

    vCursor = 0;
    vBytesRead = 0;
    vFilePath.SetString ("");
}

int
RLoader::ReadByteAndAdvance ()
{
    if (!vHandle || !vFileBuffer)
        return EOF;

    if (vCursor >= vBytesRead)
    {
        vBytesRead = fread (vFileBuffer, 1, FILE_BUFF_SIZE, vHandle);
        vCursor = 0;

        if (vBytesRead == 0)
            return EOF;
    }

    return (unsigned char) vFileBuffer [vCursor++];
}

void
RLoader::SetParserResult (void * pParserResult)
{
    vParserResult = pParserResult;
}