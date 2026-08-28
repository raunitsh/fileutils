#include "RLoader.hpp"


RLoader::RLoader ()
{
    vFilePath.SetString ("");
    vHandle = nullptr;
    vCursor = -1;
}

RLoader::~RLoader ()
{

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

    if (!vHandle)
    {
        return false;
    }

    return true;
}

void
RLoader::CloseFile ()
{
    fclose (vHandle);
    vHandle = nullptr;
    vCursor = -1;
    vFilePath.SetString ("");
}

template<typename ParserType>
bool
RLoader::ParseFile ()
{
        ParserType parser;

    return parser.Parse ();
}

int
RLoader::InternalReadAndAdvance ()
{
    return fgetc (vHandle);
}