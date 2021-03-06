// Yacc Program to check the syntax of while loop
// 1. File name : while.l
// 2. Program :

%{
%}
%%
"while" {return key;}
"(" {return ob;}
")" {return cb;}
" " {return sp;}
";" {return sc;}
"int"|"char"|"float" {return dec;}
"&&"|"||" {return tt;}
[a-z]+ {return vb;}
[0-9]+ {return nu;}
">"|"<"|">="|"<="|"="|"!=" {return op;}
"{" {return co;}
"}" {return cc;}
%%




// 3. File name : while.y
// 4. Program :

%{
#include<stdio.h>
%}
%token key
%token ob
%token op
%token vb
%token cb
%token nu
%token co
%token cc
%token cn
%token tt
%token sp
%token sc
%token dec
%%
line:key ob rp cb co a cc {printf("\n correct");}
    ;
a:vb
    |nu
    |vb nu
    |a a
    |dec sp vrb sc
    ;
vrb:vb nu
    |vb
    ;
rp:ob vrb op a cb
    |rp tt rp
    |vb op nu
    |vrb op vrb
    |vrb op nu
    ;
%%
#include"lex.yy.c"
int main()
{
yyparse();
}
int yywrap()
{
return 1;
}
int yyerror()
{
return 1;
}


// 5. Compilation Steps :
                   
lex while.l
yacc -d while.y
cc y.tab.c
./a.out

// 6. Output :

while(2>1)
{
printf("Hello World");
}