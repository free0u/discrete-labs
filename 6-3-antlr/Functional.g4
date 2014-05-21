grammar Functional;

options
{
    language = Java;
}

init
    : functions
    ;

functions
    : (function)*
    ;

function
    : descr stmts
    ;

descr
    : ID '::' arg_type ret_type
    ;

arg_type
    : (ID '->')*
    ;

ret_type
    : ID
    ;

stmts
    : (stmt)+
    ;

stmt
    : ID stmt_args '=' expr
    | ID stmt_args '=' expr
    ;

stmt_args
    : (ID | INT)*
    ;

expr
    : expr ('*' | '/') expr
    | expr ('+' | '-') expr
    | INT
    | ID
    | call
    | '(' expr ')'
    ;

call
    : ID '(' expr (',' expr)* ')'
    | ID '(' ')'
    ;

ID: [a-zA-Z_]+;

INT :
[0-9]+ ;

WS :
[ \t\r\n]+ -> skip ;