#include "includes/Loader.hpp"


Loader::Loader ()
{
    vFilePath.SetString ("");
    vHandle = nullptr;
    vCursor = -1;
}

Loader::~Loader ()
{

}

void
Loader::SetFilePath (RString& pFilePath)
{
    vFilePath.SetString (pFilePath.GetPointer ());
}

bool
Loader::OpenFileRO ()
{    
    vHandle = fopen (vFilePath.GetPointer (), "rb");    

    if (!vHandle)
    {
        return false;
    }

    return true;
}

void
Loader::CloseFile ()
{
    fclose (vHandle);
    vHandle = nullptr;
    vCursor = -1;
    vFilePath.SetString ("");
}

template<typename ParserType>
bool
Loader::ParseFile ()
{
        ParserType parser;

    return parser.Parse ();
}

int
Loader::InternalReadAndAdvance ()
{
    return fgetc (vHandle);
}