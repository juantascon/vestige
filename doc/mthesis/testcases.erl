-module(testcases).
-export([test/0]).

BEGIN-REV
reverse(L)       -> reverse(L,   []).
reverse([I|L],T) -> reverse(L,[I|T]);
reverse(   [],T) -> T.
END-REV

BEGIN-JOIN
join(L,M)           -> join(    L  M,    []).
join(L,[I|M],    T) -> join(    L, M, [I|T]);
join(L,   [],[I|T]) -> join([I|L],[],     T);
join(L,   [],   []) -> L.
END-JOIN

BEGIN-REMALL
remall(L,E)             -> remall( L,E,   [],   []).
remall(   [],_,   [],P) -> P;
remall(   [],E,[I|T],P) -> remall([],E,    T,[I|P]);
remall([E|L],E,    T,P) -> remall( L,E,    T,    P);
remall([I|L],E,    T,P) -> remall( L,E,[I|T],    P).
END-REMALL

BEGIN-COMPRESS
compress(L)             -> compress( L,   [],   []).
compress(   [],   [],P) -> P;
compress(   [],[I|T],P) -> compress([],    T,[I|P]);
compress([I|L],[I|T],P) -> compress( L,[I|T],    P);
compress([I|L],    T,P) -> compress( L,[I|T],    P).
END-COMPRESS

BEGIN-ISORT
isort(L)                          -> isort(    L,   [],   []).
isort(   [],   [],    Q)          -> Q;
isort(   [],[J|P],    Q)          -> isort(   [],    P,[J|Q]);
isort([I|L],    P,[K|Q]) when K>I -> isort([I|L],[K|P],    Q);
isort([I|L],[J|P],    Q) when I>J -> isort([I|L],    P,[J|Q]);
isort([I|L],    P,    Q)          -> isort(    L,    P,[I|Q]).
END-ISORT

test() -> [
           reverse([1,2,3,4,5,6]),
           join([5,6,7,8], [1,2,3,4]),
           remall([1,2,3,4,5,5,5,6,7,8], 5),
           compress([1,2,3,3,3,4,5,6,7,7,8,8,8,8]),
           isort([1,4,2,18,12,10,17,16,0,3,6,7,14,15,19,20,9,5,8,11,13])
          ].
