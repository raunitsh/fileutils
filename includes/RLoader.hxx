#pragma once

template <typename ParserType>
bool
RLoader::ParseFile ()
{
        ParserType parser (this);
    
    return parser.Parse ();
}