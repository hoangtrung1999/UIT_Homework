transition(X,Y):- operation(X,Y).
%fill
operation([X,Y,_],[X,Y,9]).
operation([_,Y,Z],[3,Y,Z]).
operation([X,_,Z],[X,7,Z]).
%empty
operation([X,Y,_],[X,Y,0]).
operation([X,_,Z],[X,0,Z]).
operation([_,Y,Z],[0,Y,Z]).

%pour 1 to 2
operation([X,Y,Z], [A,B,Z]) :- X =< 7 - Y, A is 0, B is Y + X.
operation([X,Y,Z], [A,B,Z]) :- X > 7 - Y, A is X - 7 + Y, B is 7.

%pour 2 to 1
operation([X,Y,Z], [A,B,Z]) :- Y =< 3 - X, B is 0, A is Y + X.
operation([X,Y,Z], [A,B,Z]) :- Y > 3 - X, B is Y - 3 + X, A is 3.

%pour 2 to 3
operation([X,Y,Z], [X,B,C]) :- Y =< 9 - Z, B is 0, C is Y + X.
operation([X,Y,Z], [X,B,C]) :- Y > 9 - Z, B is Y - 9 + Z, C is 9.

%pour 3 to 2
operation([X,Y,Z], [X,B,C]) :- Z =< 7 - Y, C is 0, B is Y + X.
operation([X,Y,Z], [X,B,C]) :- Z > 7 - Y, C is Y - 7 + Z, B is 7.

%pour 1 to 3
operation([X,Y,Z], [A,Y,C]) :- X =< 9 - Z, A is 0, C is Y + X.
operation([X,Y,Z], [A,Y,C]) :- X > 9 - Z, A is Z - 9 + X, C is 9.

%pour 3 to 1
operation([X,Y,Z], [A,Y,C]) :- Z =< 3 - X, C is 0, A is Y + X.
operation([X,Y,Z], [A,Y,C]) :- Z > 3 - X, C is Z - 3 + X, A is 3.

goal([_,Y,_]) :- Y = 5.
goal([_,_,Z]) :- Z = 5.

dfs(CurrentNode, CurrentPath, [CurrentNode, CurrentPath]):- goal(CurrentNode).
dfs(CurrentNode,CurrentPath,Path):-transition(CurrentNode,NextNode),
CurrentNode \= NextNode,
\+member(NextNode,CurrentPath),
dfs(NextNode,[CurrentNode|CurrentPath],Path).
