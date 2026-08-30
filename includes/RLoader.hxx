#pragma once

template <typename ParserType>
bool
RLoader::ParseFile ()
{
        ParserType parser (this);
    
    return parser.Parse ();
}

template <typename ResultType>
ResultType
RLoader::GetParserResult ()
{
    return (ResultType) vParserResult;
}