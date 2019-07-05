from __future__ import print_function
from pyswip import Prolog
from tkinter import *
import numpy as np
#print jugs
def print_jug(x, y, z, route):
    m = max(max(x, y), z)
    print("--------------------------Begin----------------------------")
    for i in range(len(route)):
        print(route[i])
        for j in range(m):
            if j >= m - x:
                print('|', end = '')
                if j >= m - route[i][0]:
                    print('███', end = '')
                else:
                    print('   ', end = '')
                print('|\t', end = '')
            else:
                print('    \t', end = '')
            if j >= m - y:
                print('|', end = '')
                if j >= m - route[i][1]:
                    print('███', end = '')
                else:
                    print('   ', end = '')
                print('|\t', end = '')
            else:
                print('    \t', end = '')
            if j >= m - z:
                print('|', end = '')
                if j >= m - route[i][2]:
                    print('███', end = '')
                else:
                    print('   ', end = '')
                print('|', end = '')
            
            print()        
        print(' ¯¯¯ \t ¯¯¯ \t ¯¯¯')
    print("--------------------------Done----------------------------")
p = Prolog()

# fill
p.assertz("operation([Vx,_,_],[_,Y,Z], [Vx,Y,Z])")
p.assertz("operation([_,Vy,_],[X,_,Z], [X,Vy,Z])")
p.assertz("operation([_,_,Vz],[X,Y,_], [X,Y,Vz])")

#empty
p.assertz("operation(_,[_,Y,Z], [0,Y,Z])")
p.assertz("operation(_,[X,_,Z], [X,0,Z])")
p.assertz("operation(_,[X,Y,_], [X,Y,0])")

#pour 1 to 2
p.assertz("operation([_,Vy,_],[X,Y,Z], [A,B,Z]) :- X =< Vy - Y, A is 0, B is Y + X")
p.assertz("operation([_,Vy,_],[X,Y,Z], [A,B,Z]) :- X > Vy - Y, A is X - Vy + Y, B is Vy")

#pour 2 to 1
p.assertz("operation([Vx,_,_],[X,Y,Z], [A,B,Z]) :- Y =< Vx - X, B is 0, A is Y + X")
p.assertz("operation([Vx,_,_],[X,Y,Z], [A,B,Z]) :- Y > Vx - X, B is Y - Vx + X, A is Vx")

#pour 2 to 3
p.assertz("operation([_,_,Vz],[X,Y,Z], [X,B,C]) :- Y =< Vz - Z, B is 0, C is Y + X")
p.assertz("operation([_,_,Vz],[X,Y,Z], [X,B,C]) :- Y > Vz - Z, B is Y - Vz + Z, C is Vz")

#pour 3 to 2
p.assertz("operation([_,Vy,_],[X,Y,Z], [X,B,C]) :- Z =< Vy - Y, C is 0, B is Y + Z")
p.assertz("operation([_,Vy,_],[X,Y,Z], [X,B,C]) :- Z > Vy - Y, C is Y - Vy + Z, B is Vy")

#pour 1 to 3
p.assertz("operation([_,_,Vz],[X,Y,Z], [A,Y,C]) :- X =< Vz - Z, A is 0, C is Z + X")
p.assertz("operation([_,_,Vz],[X,Y,Z], [A,Y,C]) :- X > Vz - Z, A is Z - Vz + X, C is Vz")

#pour 3 to 1
p.assertz("operation([Vx,_,_],[X,Y,Z], [A,Y,C]) :- Z =< Vx - X, C is 0, A is Z + X")
p.assertz("operation([Vx,_,_],[X,Y,Z], [A,Y,C]) :- Z > Vx - X, C is Z - Vx + X, A is Vx")

p.assertz("goal([X,Y,Z],Goal) :- X == Goal; Y == Goal; Z == Goal")

p.assertz("dfs(_,CurrentNode, CurrentPath, [CurrentNode|CurrentPath],Goal):- goal(CurrentNode,Goal)")
p.assertz("dfs(Volume,CurrentNode,CurrentPath,Path,Goal):-\
    \+length(CurrentPath,4),\
    operation(Volume,CurrentNode,NextNode),\
    CurrentNode \= NextNode,\
    \+member(NextNode,CurrentPath),\
    dfs(Volume,NextNode,[CurrentNode|CurrentPath],Path,Goal)")


# UI part
window = Tk()
 
window.title("Prolog Project")
window.geometry('350x200')
 

lblX = Label(window, text="Input Max X")
lblX.grid(column=0, row=0)
txtX = Entry(window,width=30)
txtX.grid(column=1, row=0)

lblY = Label(window, text="Input Max Y")
lblY.grid(column=0, row=1)
txtY = Entry(window,width=30)
txtY.grid(column=1, row=1)

lblZ = Label(window, text="Input Max Z")
lblZ.grid(column=0, row=2)
txtZ = Entry(window,width=30)
txtZ.grid(column=1, row=2)

lblZ = Label(window, text="Input Goal")
lblZ.grid(column=0, row=3)
txtG = Entry(window,width=30)
txtG.grid(column=1, row=3)


#default values
queryTxt = " "
Vx = int()
Vy = int()
Vz = int()
G = int()
def getQuery():
	Vx = txtX.get()
	Vy = txtY.get()
	Vz = txtZ.get()
	G  = txtG.get()
	#dfs([Vx,Vy,Vz],[0,0,0],[],X,Goal)
	queryTxt = "dfs([" + Vx + "," + Vy + "," + Vz + "],[0,0,0],[],P," + G + ")"
	print(queryTxt)

	#In nguoc do phai di tu node goc di xuong
	sol = list(p.query(queryTxt))
    
	for i in range (len(sol)):
		print_jug(int(Vx), int(Vy), int(Vz), sol[i]["P"][::-1])
	
	
btnQuery = Button(window, text="Solve It!", command=getQuery)
btnQuery.grid(column=1, row=5)

window.mainloop()