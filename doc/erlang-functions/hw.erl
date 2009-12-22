% Christian Rinderknecht

-module(hw).
-compile(export_all).

%=====================================================================
% Factorial

% Not tail form.
%
fact1(0)            -> 1;
fact1(N) when N > 0 -> N * fact1(N-1).

% Tail form.
%
fact(N) when N >= 0 -> fact(N,1).

fact(0,A) -> A;
fact(N,A) -> fact(N-1,N*A).

%=====================================================================
% `len(L)' is the number of items in `L'.
%
len(L) -> len(0,L).                 % Clause 1

len(Len,   []) -> Len;              % Clause 2
len(Len,[_|L]) -> len(Len+1,L).     % Clause 3

% `len1(L)' is `len(L)' but is not in tail form.
%
len1(   []) -> 0;             % Clause 1
len1([_|L]) -> 1 + len1(L).   % Clause 2

%=====================================================================
% `last(L)' is the last item in list `L'.
%
last(  [I]) -> I;
last([_|L]) -> last(L).

%=====================================================================
% `penult(L)' is the item just before the last item in list `L'.
%
penult([I,_]) -> I;
penult([_|L]) -> penult(L).

%=====================================================================
% `prod(L)' is the product of the integers in the list `L'.

% Not in tail form.
%
prod1(  [N]) -> N;
prod1([N|L]) -> N * prod1(L).

% In tail form
%
prod([N|L]) -> prod(N,L).

prod(A,   []) -> A;
prod(A,[N|L]) -> prod(N*A,L).
        
%=====================================================================
% `rev_append(L,M)' is the list whose first items are the items of `L'
% reversed, followed by the items of `M' in the same order.
%
rev_append(   [],M) -> M;                    % Clause 1
rev_append([I|L],M) -> rev_append(L,[I|M]).  % Clause 2

%=====================================================================
% `append(L,M)' is the list whose first items are those of `L' in the
% same order, and the following are those of `M' in the same order.
%
append(L,M) -> append([],L,M).                  % Clause 1

append(   [],    [],M) -> M;                    % Clause 2
append([I|A],    [],M) -> append(A,[],[I|M]);   % Clause 3
append(    A, [I|L],M) -> append([I|A],L,M).    % Clause 4

% Another version not in tail form.
%
append2(   [],M) -> M;                 % Clause 1
append2([I|L],M) -> [I|append2(L,M)].  % Clause 2

%=====================================================================
% `rev(L)' is the list containing all the items of `L' reversed.
%
rev(L) -> rev_append(L,[]).

% Another version not in tail form AND inefficient.
%
rev1(   []) -> [];
rev1([I|L]) -> append(rev1(L),[I]).

%=====================================================================
% `rem_fst(L,I)' is the list `L' without its first occurrence of
% item `I'. If `I' is missing from `L', `rem_fst(L,I)' is `L'.
%
rem_fst(L,I) -> rem_fst([],L,I).

rem_fst(A,   [],_) -> rev(A);
rem_fst(A,[I|L],I) -> rev_append(A,L);
rem_fst(A,[J|L],I) -> rem_fst([J|A],L,I).

% This version is not in tail form.
%
rem_fst1(   [],_) -> [];
rem_fst1([I|L],I) -> L;
rem_fst1([J|L],I) -> [J|rem_fst1(L,I)].

%=====================================================================
% `rem_all(L,I)' is the list containing all the items of list `L' in
% the same order, except all items matching `I'.

% This version is in tail form.
%
rem_all(L,I) -> rem_all([],L,I).

rem_all(A,   [],_) -> rev(A);
rem_all(A,[I|L],I) -> rem_all(A,L,I);
rem_all(A,[J|L],I) -> rem_all([J|A],L,I).
    
% This version is not in tail form.
%
rem_all1(   [],_) -> [];
rem_all1([I|L],I) -> rem_all1(L,I);
rem_all1([I|L],J) -> [I|rem_all1(L,J)].

%=====================================================================
% `rem_last(L,I)' is the list containing all the items of list `L',
% except the last occurrence of `I'.

% This version is in tail form.
% 
rem_last(L,I) -> rem_last([],L,I).

rem_last(A,   [],I) -> rem_last_aux([],A,I);
rem_last(A,[J|L],I) -> rem_last([J|A],L,I).

rem_last_aux(A,   [],_) -> A;
rem_last_aux(A,[I|L],I) -> rev_append(L,A);
rem_last_aux(A,[J|L],I) -> rem_last_aux([J|A],L,I).

% This version is not in tail form.
%
rem_last1(L,I) -> rev(rem_fst(rev(L),I)).

%=====================================================================
% `drop(L,P)' is the list made of the items of list `L' in the same
% order, except the items occurring every number `P', the first item
% being counted as occurring at position 1.

% This version is in tail form.
%
drop(L,P) -> drop([],1,L,P).

drop(A,_,   [],_) -> rev(A);
drop(A,P,[_|L],P) -> drop(A,1,L,P);
drop(A,N,[I|L],P) -> drop([I|A],N+1,L,P).

%=====================================================================
% `split(L,N)' is a pair of lists, the first containing the first `N'
% items of `L' in the original order, the second containing the
% remaining items of `L' in the original order. If `N =< 0' or `N =
% len(L)', then `split(L,N)' is undefined (if the latter case were
% allowed, there would be an ambiguity between two possible outcomes:
% {L,[]} and {[],L}). 
%
% This version is NOT in tail form (the call `rev(A)' is inside a
% pair).
%
split(L,N) when N > 0 -> split([],L,N).

split(A,P=[_|_],0) -> {rev(A),P};
split(A,  [I|L],N) -> split([I|A],L,N-1).
    
%=====================================================================
% `rotate(L,N)' is the list containing the items of `L' such that the
% len(L) - N last items of `L' come first (in the original order),
% followed by the N first items of `L' (in the original order).
%

% This is version is not in tail form
%
rotate(L,N) when N < 0 -> Len = len(L), rotate([],L,Len + N rem Len);
rotate(L,N)            -> rotate([],L,N rem len(L)).

rotate([],    L,0) -> L;
rotate( A,    L,0) -> append(L,rev(A));
rotate( A,[I|L],N) -> rotate([I|A],L,N-1).

% This version is in tail form.
%
rotate1(L,N) -> rot1(L,N,L,0).

rot1(L,N,   [],Len) when N < 0 -> rot2([],L,Len + N rem Len);
rot1(L,N,   [],Len)            -> rot2([],L,N rem Len);
rot1(L,N,[_|C],Len)            -> rot1(L,N,C,Len+1).

rot2([],    L,0) -> L;
rot2( A,    L,0) -> rot3(L,A,[]);
rot2( A,[I|L],N) -> rot2([I|A],L,N-1).

rot3(L,   [],B) -> append(L,B);
rot3(L,[I|A],B) -> rot3(L,A,[I|B]).

% Reusing split/2.
%
rotate2(L,N) when N < 0 ->
  Len = len(L), rotate2_(L,(Len + N rem Len) rem Len);
rotate2(L,N) ->
  rotate2_(L,N rem len(L)).

rotate2_(L,0) -> L;
rotate2_(L,N) ->
   {Pre,Suf} = split(L,N), append(Suf,Pre).

%=====================================================================
% `flatten(L)' is a list containing the items of list `L' which are
% not lists themselves, in the original order (if an item `I' of `L'
% is a list, then its items come before the items after `I' in `L').

% This is a version in tail form.
%
flatten(L) -> flatten([],L).

flatten(A,       []) -> rev(A);
flatten(A,   [[]|L]) -> flatten(    A,      L);
flatten(A,  [[I]|L]) -> flatten(    A,  [I|L]); %% Can be omitted
flatten(A,[[I|M]|L]) -> flatten(    A,[I,M|L]);
flatten(A,    [N|L]) -> flatten([N|A],      L).

% This version is not in tail form
%
flatten3(       []) -> [];
flatten3(   [[]|L]) -> flatten3(L);
flatten3([[I|M]|L]) -> flatten3([I,M|L]);
flatten3(    [N|L]) -> [N|flatten3(L)].
    
% This version is not in tail form and slower than flatten/1 if there
% are not many empty lists in the input. Otherwise, it may be faster.
%
flatten1(       []) -> [];
flatten1(   [[]|L]) -> flatten1(L);
flatten1([[I|M]|L]) -> append(flatten1([I|M]),flatten1(L));
flatten1(    [N|L]) -> [N|flatten1(L)].

% This version is not in tail form.
%
flatten2(List) -> flatten2([],List).

flatten2(A,       []) -> rev(A);
flatten2(A,   [[]|L]) -> flatten2(A,L);
flatten2(A,[[I|M]|L]) -> flatten2(flatten2(A,[I|M]),L);
flatten2(A,    [N|L]) -> flatten2([N|A],L).

% This version is in tail form and uses simpler patterns.
% Credit: Jeong Jeong Hi
%
flatten4(L) -> flatten4(L,[],[]).

flatten4(   [],[],Q) -> rev(Q);
flatten4(   [], P,Q) -> flatten4(P,[],Q);
flatten4(  [I], P,Q) -> flatten4(I,    P,    Q);
flatten4([I|L], P,Q) -> flatten4(I,[L|P],    Q);
flatten4(    I, P,Q) -> flatten4(P,   [],[I|Q]).

%=====================================================================
% `compress(L)' is the list containing the items of list `L' in the
% same order but without repeating consecutive items.

% This version is in tail form.
%
compress(L) -> compress([],L).

compress(      A,   []) -> rev(A);
compress([I|_]=A,[I|L]) -> compress(A,L);
compress(      A,[I|L]) -> compress([I|A],L).

% This version is not in tail form.
%
compress1(     []) -> [];
compress1([I,I|L]) -> compress1([I|L]);
% or
% compress1([I|P=[I|_]]) -> compress1(P);
compress1(  [I|L]) -> [I|compress1(L)].
     
%=====================================================================
% `pack(L)' is the list of the lists of repeated items of `L', in the
% same original order.

% This version is in tail form.

pack(L) -> pack([],L).

pack(         A,   []) -> rev(A);
pack([[I|Is]|A],[I|L]) -> pack([[I,I|Is]|A],L);
pack(         A,[I|L]) -> pack([[I]|A],L).

%=====================================================================
% `encode(L)' is the list which contains pairs `{N,I}' of numbers `N'
% and items `I' from `L', such that `N' is the number of consecutively
% repeated occurrences of `I' in `L'.

% This version is in tail form.
%
encode(L) -> encode([],L).

encode(        A,   []) -> rev(A);
encode([{N,I}|A],[I|L]) -> encode([{N+1,I}|A],L);
encode(        A,[I|L]) -> encode([{1,I}|A],L).

%=====================================================================
% `dupli(L)' is the list containing all the items of list `L' in the
% same order but consecutively duplicated.

% This version is in tail form.
%
dupli(L) -> dupli([],L).

dupli(A,   []) -> rev(A);
dupli(A,[I|L]) -> dupli([I,I|A],L).

% This version is not in tail form.
%
% The number of steps is len(L) + 1.
% The number of pushes is 2*len(L).
%
dupli1(   []) -> [];
dupli1([I|L]) -> [I,I|dupli(L)].

%=====================================================================
% `repli(N,L)' is the list containing the items of list `L' in the
% same order but successively duplicated `N' times (in particular,
% `repli(0,L)' is the empty list).
%
repli(N,L) when N >= 0 -> repli1([],N,L).

repli1(A,N,   []) -> repli2([],N,N,A);  % See above.
repli1(A,N,[I|L]) -> repli1([I|A],N,L).

%=====================================================================
% One-way insertion to sort increasingly a list of integers

% This version is not in tail form.
%
isort1(   []) -> [];
isort1([I|L]) -> insert1(I,isort1(L)).

insert1(I,    [])            -> [I];
insert1(I,[J|Su]) when I > J -> [J|insert1(I,Su)];
insert1(I,    Su)            -> [I|Su].
    
% In tail form
%
isort7(L) -> isort7([],[],L).

isort7([],    Su,   [])            -> Su;
isort7(Sd,    [],[I|L])            -> rev_app_sort7(Sd,[I],L);    
isort7(Sd,[J|Su],[I|L]) when I > J -> isort7([J|Sd],Su,[I|L]);
isort7(Sd,    Su,[I|L])            -> rev_app_sort7(Sd,[I|Su],L).

rev_app_sort7(    [],Su,L) -> isort7([],Su,L);
rev_app_sort7([I|Sd],Su,L) -> rev_app_sort7(Sd,[I|Su],L).

%=====================================================================
% Insertion sort for any data type with a comparison function
%
% Not in tail form.
%
isort_g(   [],   _) -> [];
isort_g([I|L],Comp) -> insert_g(I,isort_g(L,Comp),Comp).

insert_g(I,    [],   _) -> [I];
insert_g(I,[J|Su],Comp) ->
  case Comp(I,J) of
    true  -> [I,J|Su];
    false -> [J|insert_g(I,Su,Comp)]
  end.

% Increasing and decreasing sort (instanciation of the comparison)
% They are stable because the comparison includes equality.
%
isort_up(L) -> isort_g(L, fun (X,Y) -> X =< Y end).

isort_down(L) -> isort_g(L, fun (X,Y) -> X >= Y end).

%=====================================================================
% Two-way insertion to sort integers increasingly
% 
% In tail form.
%
isort_2w(L) -> isort_2w([],[],L).

isort_2w(   [],    B,   [])            -> B;
isort_2w([I|A],    B,   [])            -> isort_2w(    A,[I|B],   []);
isort_2w(    A,[J|B],[K|C]) when J < K -> isort_2w([J|A],    B,[K|C]);
% alternative following body: isort_2w([K],B,C)
isort_2w(   [],    B,[K|C])            -> isort_2w(   [],[K|B],    C);
isort_2w([I|A],    B,[K|C]) when K < I -> isort_2w(    A,[I|B],[K|C]);
isort_2w(    A,    B,[K|C])            -> isort_2w([K|A],    B,    C).

%=====================================================================
% foldl(F,A,[I1,I2,...,In]) = F(In,F(...F(I2,F(I1,A))...))
% foldl(F,A,[]) = A
%
% Tail form.
%
foldl(_,A,   []) -> A;
foldl(F,A,[I|L]) -> foldl(F,F(I,A),L).
