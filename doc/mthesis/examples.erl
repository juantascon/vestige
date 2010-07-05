-module(examples).
-export([test/0]).

BEGIN-FIRSTG
firstg([I|L],N) when I>N -> I;
firstg([_|L],N)          -> firstg(L,N).
END-FIRSTG

BEGIN-ADD
add(I,   []) -> [I];
add(I,[I|L]) -> [I|L];
add(I,[J|L]) -> [J|add(I,L)];
END-ADD

test() -> [
           
          ].
