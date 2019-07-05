from __future__ import print_function
from pyswip import Prolog
from tkinter import *
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
p.assertz("operation([X,Y,_], [X,Y,9])")
p.assertz("operation([X,_, Z], [X,7,Z])")
p.assertz("operation([_,Y,Z], [3,Y,Z])")

# empyty
p.assertz("operation([X,Y,_], [X,Y,0])")
p.assertz("operation([X,_,Z], [X,0,Z])")
p.assertz("operation([_,Y,Z], [0,Y,Z])")

# pour 1 to 2
p.assertz("operation([X,Y,Z], [0,T,Z]):- X < 7-Y, T is Y+X")
p.assertz("operation([X,Y,Z], [T,7,Z]):- X >= 7-Y, T is X-(7-Y)")
# pour 1 to 3
p.assertz("operation([X,Y,Z], [0,Y,T]):- X < 9-Z, T is Z+X")
p.assertz("operation([X,Y,Z], [T,Y,9]):- X >= 9-Z, T is X-(9-Z)")

# pour 2 to 1
p.assertz("operation([X,Y,Z], [T,0,Z]):- Y < 3-X, T is X+Y")
p.assertz("operation([X,Y,Z], [3,T,Z]):- Y >= 3-X, T is Y-(3-X)")
# pour 2 to 3
p.assertz("operation([X,Y,Z], [X,0,T]):- Y < 9-Z, T is Z+Y")
p.assertz("operation([X,Y,Z], [X,T,9]):- Y >= 9-Z, T is Y-(9-Z)")

# pour 3 to 1
p.assertz("operation([X,Y,Z], [T,Y,0]):- Z < 3-X, T is X+Z")
p.assertz("operation([X,Y,Z], [3,Y,T]):- Z >= 3-X, T is Z-(3-X)")
# pour 3 to 2
p.assertz("operation([X,Y,Z], [X,T,0]):- Z < 7-Y, T is Y+Z")
p.assertz("operation([X,Y,Z], [X,7,T]):- Z >= 7-Y, T is Z-(7-Y)")

# set goal
#p.assertz("goal([X,_,_]) :- X = G")
p.assertz("goal([_,Y,_]) :- Y = 5")
p.assertz("goal([_,_,Z]) :- Z = 5")

p.assertz("dfs(CurrentNode, CurrentPath, [CurrentNode|CurrentPath]):-goal(CurrentNode)")
p.assertz("dfs(CurrentNode, CurrentPath, Path):- \+ length([CurrentNode|CurrentPath], 5),\
	operation(CurrentNode, Next_Node), CurrentNode \= Next_Node,\
	\+ member(Next_Node, CurrentPath), dfs(Next_Node, [CurrentNode|CurrentPath], Path)")

# UI part
window = Tk()
 
window.title("Prolog Project")
window.geometry('350x200')
 

lblX = Label(window, text="Input Current X")
lblX.grid(column=0, row=0)
txtX = Entry(window,width=30)
txtX.grid(column=1, row=0)

lblY = Label(window, text="Input Current Y")
lblY.grid(column=0, row=1)
txtY = Entry(window,width=30)
txtY.grid(column=1, row=1)

lblZ = Label(window, text="Input Current Z")
lblZ.grid(column=0, row=2)
txtZ = Entry(window,width=30)
txtZ.grid(column=1, row=2)

#default values
queryTxt = "dfs([0, 0, 0], [], P)"
Vx = int()
Vy = int()
Vz = int()
def getQuery():

	Vx = txtX.get()
	Vy = txtY.get()
	Vz = txtZ.get()
	#G = int(txtG.get())

	queryTxt = "dfs([" + Vx + ", " + Vy + ", " + Vz + "],[],P)"
	#queryTxt = txt.get()
	print(queryTxt)
	sol = list(p.query(queryTxt))

	print("I found ", len(sol), "solution(s).")

	#In nguoc do phai di tu node goc di xuong
	for i in range (len(sol)):
		print_jug(3, 7, 9, sol[i]["P"][::-1])
		wait = input() 
btnQuery = Button(window, text="Solve It!", command=getQuery)
btnQuery.grid(column=1, row=5)

window.mainloop()