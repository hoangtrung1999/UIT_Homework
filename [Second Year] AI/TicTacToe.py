''' 
Danh sach nhom
Nguyen Chi Bao 17520208
Nguyen Hoang Trung 17521176
Le Thanh Phuoc Hieu 17520474
Le Hoang An 17520271
'''
import numpy as np
from IPython.display import clear_output

def isMoveLeft(board):
    if ' ' in board:
        return 1
    return 0
    
def gameOver(board):
    if board[1][1] != ' ' and (board[0][0] == board[1][1] == board[2][2] or board[0][2] == board[1][1] == board[2][0]):
        if board[1][1] == 'X':
            return -10
        elif board[1][1] == 'O':
            return 10
    for i in range(3):
        if board[0][i] == board[1][i] == board[2][i] and board[0][i] != ' ':
            if board[0][i] == 'X':
                return -10
            else:
                return 10
        if board[i][0] == board[i][1] == board[i][2] and board[i][0] != ' ':
            if board[i][0] == 'X':
                return -10
            else:
                return 10
    return 0
    
def evaluate(board, player):
    move = 0
    if (board[0][0] == ' ' or board[0][0] == player) and (board[1][1] == ' ' or board[1][1] == player) and (board[2][2] == ' ' or board[2][2] == player):
        move += 1
    if (board[0][2] == ' ' or board[0][2] == player) and (board[1][1] == ' ' or board[1][1] == player) and (board[2][0] == ' ' or board[2][0] == player):
        move += 1
    for i in range(3):
        if (board[0][i] == ' ' or board[0][i] == player) and (board[1][i] == ' ' or board[1][i] == player) and (board[2][i] == ' ' or board[2][i] == player):
            move += 1
        if (board[i][0] == ' ' or board[i][0] == player) and (board[i][1] == ' ' or board[i][1] == player) and (board[i][2] == ' ' or board[i][2] == player):
            move += 1
    return move    
                   
def minimax(board):
    if gameOver(board):
        return board
    if isMoveLeft(board) == False:
        return board
    bestVal = -100
    row = column = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                board[i][j] = 'X'
                if gameOver(board) < 0:
                    board[i][j] = 'O'
                    return board
                board[i][j] = 'O'
                if bestVal < evaluate(board, 'O') - evaluate(board, 'X'):
                    bestVal = evaluate(board, 'O') - evaluate(board, 'X')
                    row = i
                    column = j
                if gameOver(board) > 0:
                    return board
                board[i][j] = ' '
    board[row][column] = 'O'
    return board

board = np.array([[' ', ' ', ' '], [' ', ' ', ' '], [' ', ' ',' ']])
print(board)
while True:
    while True:
    	print("Nhap toa do diem muon danh: ")
    	column,row = input().split()
    	column = int(column)
    	row = int(row)
    	if (row >= 0 and row <= 2 and column >= 0 and column <= 2):
            if (board[row][column] == ' '):
                break
    clear_output()    
    board[row][column] = 'X'
    board = minimax(board)
    print(board)
    if (gameOver(board) != 0):  
        break
    if (isMoveLeft(board) == 0):
        break
if gameOver(board) == 10:
    print("Bot win")
elif gameOver(board) == -10:
    print("Player win")
else:
    print("Draw")