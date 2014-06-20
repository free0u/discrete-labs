grammar Grammar;

options {
    language = Java;
}

start
    : HEADER? MEMBERS? rules;

HEADER: 'header{' ANY '}' WS;
MEMBERS: 'members{' ANY '}' WS;

fragment ANY : .*?;

rules
    : rule_+;

rule_
    : NONTERM RETURN_SYM? ':' rrule  ('|' rrule )* ';' WS
    ;

rrule
    : terms+
    ;

terms
    : (NONTERM | TOKEN | SYM | EPS | WS)
    ;

SYM
    : '{' (.*?) '}'
    ;

RETURN_SYM
    : '[' (.*?) ']'
    ;

NONTERM : [A-Z_]+;
INT : [0-9]+;
TOKEN : '\'' .+ ?'\'';

EPS : 'eps';

WS :
[ \t\r\n]+;