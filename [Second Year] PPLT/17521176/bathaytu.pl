transition(X,Y):- operation(X,Y).

%A,B: So su, so quy o ben bo trai
%C,D: So su, so quy o ben bo phai
%0->1: di tu phai sang trai.
%1->0: di tu trai sang phai.
goal([0,0,3,3,0]).

operation([A,B,C,D,1],[X,Y,Z,T,0]):- A>0,B>0,X is A-1,Y is B-1,Z is C+1, T is D+1.
operation([A,B,C,D,0],[X,Y,Z,T,1]):-C>0,D>0,X is A+1, Y is B+1,Z is C-1, T is D-1.

operation([A,B,C,D,0],[X,B,Z,D,1]):-C>1, X is A+2, Z is C-2.
operation([A,B,C,D,1],[X,B,Z,D,0]):-A>1, X is A-2, Z is C+2.

operation([A,B,C,D,1],[A,Y,C,T,0]):-B>1, Y is B-2, T is D+2.
operation([A,B,C,D,0],[A,Y,C,T,1]):-D>1 ,Y is B+2, T is D-2.

operation([A,B,C,D,0],[X,B,Z,D,1]):-C>0, X is A+1, Z is C-1.
operation([A,B,C,D,1],[X,B,Z,D,0]):-A>0, X is A-1, Z is C+1.

operation([A,B,C,D,0],[A,Y,C,T,1]):-D>0, Y is B+1, T is D-1.
operation([A,B,C,D,1],[A,Y,C,T,0]):-B>0, Y is B-1, T is D+1.

invalid([A,B,C,D,_]):-B>A,D>C.
invalid([A,B,0,_,_]):-B>A.
invalid([0,_,A,B,_]):-B>A.
dfs(CurrentNode, CurrentPath, [CurrentNode, CurrentPath]):- goal(CurrentNode).
dfs(CurrentNode,CurrentPath,Path):-transition(CurrentNode,NextNode),
CurrentNode \= NextNode,
\+member(NextNode,CurrentPath),
\+invalid(CurrentNode),
dfs(NextNode,[CurrentNode|CurrentPath],Path).



