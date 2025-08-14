## A. The Spacy Language (spacy)

### 题目描述

The task is to format a piece of code in spacy language, and all sets
mentioned in the statement are string sets. Here, $A\oplus B$ means the string obtained by
appending $B$ to the end of $A$.For convenience, here are some definitions:
- $\epsilon$ means the empty string.
- $c(A,B)$ is the set $\{S\oplus T|S\in A,T\in B\}$.
- $C(A_1,A_2,\dots,A_n)$ is the set $c(A_1,c(A_2,c(\dots,A_n)))$.
- $R(A,l,r)$ is $\bigcup_{l\le k\le r}A^k$ where $A^0=\{\epsilon\}, A^k = \{S \oplus T | S \in A^{k-1}, T \in A\}$.
- $r(A,l)$ is $\bigcup_{l\le k}A^k$.
- We define the set that the phrase \'one of the following\' describes
    as the union of the sets described below.
- A + B stands for $c(A,B)$. A + B + D
    stands for $C(A,B,D)$, and so on.

S.P.A.C.Y. found an ancient programming language called the Spacy
Language. Here, we will describe the language by the definition $W=$ the set of all non-empty strings
consisting of spaces (ASCII 32), tabs (ASCII 9), and linefeeds (ASCII
10), and $S=L=E=W \cup \{\epsilon\}$. In the
final problem, there will be differences among them.Let $T$ be the set of Latin letters and
underscore, $D$ be the set of $10$ digits,$U$ be the set of all visible characters (except \'/\'), spaces, tabs, and
linefeeds.**identifier** is $c(T,r(T\cup D,0))\setminus\{\texttt{if},\texttt{otherwise},\texttt{repeat},\texttt{while},\texttt{return}\}$.**number** is $r(D,1)$.**comment** is $C(\texttt{/*},r(U,0),\texttt{*/})$.*decl* is **identifier** + $W$ +
**identifier**.

*expr* is one of the following:

1.  **identifier**;
2.  **number**;
3.  *expr* + $S$ + $\{\texttt{+},\texttt{\&},\texttt{/},\texttt{==}\}$ + $S$ + *expr*;
4.  *expr* + $S$ + $\{\texttt{=}\}$ + $S$ +
    *expr*;
5.  **identifier **+ $E$ + $\{\texttt{(}\}$ + $E$ + $\{\texttt{)}\}$;
6.  **identifier** + $E$ + $\{\texttt{(}\}$ + $E$ +
    *expr* + $E$ + $\{\texttt{)}\}$;
7.  **identifier** + $E$ + $\{\texttt{[}\}$ + $E$ +
    *expr* + $E$ + $\{\texttt{]}\}$;
8.  *expr* + $E$ + $\{\texttt{,}\}$ + $S$ +
    *expr*;
9.  $\{\texttt{*}\}$ + $E$ +
    *expr*;
10. $\{\texttt{(}\}$ + $E$ +
    *expr* + $E$ + $\{\texttt{)}\}$;
11. **identifier** + $E$ + $\{\texttt{++}\}$;
12. *expr* + $E$ + $\{\texttt{!}\}$.

*block* is $\{\texttt{\{}\}$ + $L$ + $r($*stmt* + $L,0)$ + $\{\texttt{\}}\}$.*cond* is $\{\texttt{(}\}$ + $E$ + *expr* + $E$ + $\{\texttt{)}\}$.*stmt* is one of the following:
1.  *decl* + $E$ + $\{\texttt{?}\}$;
2.  *decl* + $S$ + $\{\texttt{=}\}$ + $S$ +
    *expr* + $E$ + $\{\texttt{?}\}$;
3.  *expr* + $E$ + $\{\texttt{?}\}$;
4.  $\{\texttt{if}\}$ + $S$ +
    *cond* + $S$ +
    *block* + $r(S$ + $\{{\texttt{otherwise}\}}$ + $W$ + $\{\texttt{if}\}$ + $S$ +
    *cond* + $S$ +
    *block*$,0)$ + $R(S$ + $\{\texttt{otherwise}\}$ + $S$ +
    *block*$,0,1)$;
5.  $\{\texttt{repeat}\}$ + $S$ +
    *block* + $S$ + $\{\texttt{while}\}$ + $S$ +
    *cond* + $E$ + $\{\texttt{?}\}$;
6.  $\{\texttt{while}\}$ + $S$ +
    *cond* + $S$ + *block*;
7.  $\{\texttt{return}\}$ + $W$ +
    *expr* + $E$ + $\{\texttt{?}\}$;
8.  $\{\texttt{!}\}$.

*codeblock* is one of the following:
1.  *decl* + $E$ + $\{\texttt{(}\}$ + $E$ + $\{\texttt{)}\}$ + $S$ + *block*;
2.  *decl* + $E$ + $\{\texttt{(}\}$ + $E$ +
    *decl* + $E$ + $r(\{\texttt{,}\}$ + $S$ +
    *decl*$,0)$ + $E$ + $\{\texttt{)}\}$ + $S$ +
    *block*;
3.  $\{\texttt{main}\}$ + $E$ + $\{\texttt{(}\}$ + $E$ + $\{\texttt{)}\}$ + $S$ +
    *block*.

*program* is **comment** + $r(L$ +
*codeblock*$,1)$ + $E$.*program*, *codeblock*, *stmt*, *cond*, *block*, *expr*, and *decl* are
**nonterminal symbols**. Other symbols (e.g. **identifier**, $E$, $\{\texttt{?}\}$) are **terminal**
**symbols**. Now we can generate a piece of code using the following
method:
1.  Generate a list and initialize it as $[$*program*$]$.
2.  Keep looking for the first **nonterminal** **symbol** in the list
    and replace it according to the formulae mentioned above (for
    example $[$*decl*$]$ can
    be replaced
    by $[$**identifier**, $W$,
    **identifier**$]$), until no
    **nonterminal** **symbols** exist.
3.  Replace each element in the list with a string from its
    corresponding set.

Concatenating the strings in the list in sequence gives a piece of code,
and the list is called a decomposition of the code. It can be proved
that the decomposition of a certain piece of code is unique.Two pieces of code are considered equal iff their decompositions are of
equal length, and for two strings at corresponding positions in the
decompositions, either the two strings are equal, or none of them
contain characters besides space, tab, and linefeed.*half-formatted program* is the set of *program* when $S=W=\{$space$\}$, $L=\{$linefeed$\}$, $E=\{\epsilon\}$.A piece of code is *well-formatted* if and only if it can be obtained by
inserting $k\times x$ spaces after each
linefeed (ASCII 10) in a piece of code belonging to *half-formatted
program*, where $x$ denotes the number of
*blocks* the linefeed is in (specifically, if the linefeed is the last
one in a *block*, that *block* will not be counted in $x$), and $k$ is a
given number.Given a piece of code, find a *well-formatted* piece which is equal to
the given code.

### 输入描述

The first line, a single non-negative integer $k$.

From the second to end of file, is the given code.

It is guaranteed that the input size will not exceed $10^5$ bytes.

### 输出描述

A *well-formatted* piece which is equal to the given code.  **Note that
extra spaces, tabs, and linefeeds are not allowed. **

****

It is guaranteed that the output size will not exceed $2\times 10^5$ bytes.

### 示例1

#### 输入

```plain
3
/* Awa! Yis code iz riten by Spacy */
lovely  cat( )
{
           *
        *
      *
   *
   meow?!!!!
}
```

#### 输出

```plain
/* Awa! Yis code iz riten by Spacy */
lovely cat() {
   ****meow?
   !
   !
   !
   !
}
```

### 示例2

#### 输入

```plain
3
/*this contest is:*/supported by(xi an){main guan?!}
```

#### 输出

```plain
/*this contest is:*/
supported by(xi an) {
   main guan?
   !
}
```

### 示例3

#### 输入

```plain
3
/*expression 	 	 	test*/
    define 	 	 pinkierabbit
      (int		rating){
	1/* 	       1!=0?
  	  sleep	      ()?
	114?514?!1919?810?!
  Pinkie(	           negrating[
2,1,3,5],		   2,E_space(3)
)=154,      154=   155,       *155=
154444?   		      (1+1
    )!!!    		   !?!!!!
     rating++?yuanshen_qidong()
      ?!!!rating=rating+154?}
```

#### 输出

```plain
/*expression 	 	 	test*/
define pinkierabbit(int rating) {
   1 / *1! = 0?
   sleep()?
   114?
   514?
   !
   1919?
   810?
   !
   Pinkie(negrating[2, 1, 3, 5], 2, E_space(3)) = 154, 154 = 155, *155 = 154444?
   (1 + 1)!!!!?
   !
   !
   !
   !
   rating++?
   yuanshen_qidong()?
   !
   !
   !
   rating = rating + 154?
}
```

### 示例4

#### 输入

```plain
2
/*01 backpack*/
signed main(int
argv)
{
f[200,000]?tmp[200,000]?
f_0=1?
while(i=1,i!=n,i++)
   {x=a_i?
while(j=0,j!=V,j++){tmp_j=f_j?}
if(n/x){while(j=0,j+x!=V+1,j++){tmp_j+x=tmp_j   +1?}}

while(j=0,j!=V,j++){f_j=tmp_j?}
}
return f_n?
     }

main(){main()?}
```

#### 输出

```plain
/*01 backpack*/
signed main(int argv) {
  f[200, 000]?
  tmp[200, 000]?
  f_0 = 1?
  while (i = 1, i! = n, i++) {
    x = a_i?
    while (j = 0, j! = V, j++) {
      tmp_j = f_j?
    }
    if (n / x) {
      while (j = 0, j + x! = V + 1, j++) {
        tmp_j + x = tmp_j + 1?
      }
    }
    while (j = 0, j! = V, j++) {
      f_j = tmp_j?
    }
  }
  return f_n?
}
main() {
  main()?
}
```

### 备注



