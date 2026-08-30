#pragma once

template <typename ParserType, typename LexerType>
bool
RLoader::ParseFile ()
{
        LexerType lexer;
        ParserType parser (this, &lexer);
    
    return parser.Parse ();
}

template <typename ResultType>
ResultType
RLoader::GetParserResult ()
{
    return (ResultType) vParserResult;
}