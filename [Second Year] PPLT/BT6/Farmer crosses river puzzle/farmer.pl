transition(X,Y):- operation(X,Y).
%F is for Farmer
%W is for Wolf
%G is for Goat
%C is for Cabbage

%invalid
invalid([0,1,1,1]).
invalid([0,0,1,1]).

invalid([1,1,0,0]).
invalid([1,0,0,0]).

invalid([0,1,1,0]).
invalid([1,0,0,1]).
%goal
goal([1,1,1,1]).
%Move both
operation([1,W,1,C],[0,W,0,C]).
operation([0,W,0,C],[1,W,1,C]).

operation([0,0,G,C],[1,1,G,C]).
operation([1,1,G,C],[0,0,G,C]).

operation([0,W,G,0],[1,W,G,1]).
operation([1,W,G,1],[0,W,G,0]).

operation([0,W,G,C],[1,W,G,C]).
operation([1,W,G,C],[0,W,G,C]).
dfs(CurrentNode, CurrentPath, [CurrentNode, CurrentPath]):- goal(CurrentNode).
dfs(CurrentNode,CurrentPath,Path):-transition(CurrentNode,NextNode),
CurrentNode \= NextNode,
\+member(NextNode,CurrentPath),
\+invalid(CurrentNode),
dfs(NextNode,[CurrentNode|CurrentPath],Path).




