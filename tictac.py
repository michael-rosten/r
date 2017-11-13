# -----------------------------------------------------------------------------
# Name:       tictac
# Purpose:    Implement a game of Tic Tac Toe
#
# Author:   Michael Rosten
# -----------------------------------------------------------------------------
'''
Module that implements a tic tac toe game. Uses tkinter to make
a GUI. Processes click inputs, makes computer imputs, and
detects a win, loss, or tie.
'''
import tkinter
import random

class Game(object):
    '''
    Gui Game class that makes a tic tac toe board
    
    Argument:
    parent(tkinter.Tk) : the root window object

    Attributes:
    parent: (tkinter.Tk) the root window object
    canvas: (tkinter.Canvas) canvas representing the game board
    restart_button: (tkinter.Button) button representing the reset button
    result: (tkinter.Label) notifies the user of a win loss or tie
    '''
    square_size = 50
    base_color = 'white'
    row_one = ['P0','P0','P0']
    row_two = ['P0','P0','P0']
    row_three = ['P0','P0','P0']
    turn_count = 0

    def __init__(self, parent):
        parent.title('Tic Tac Toe')
        self.parent = parent
        restart_button = tkinter.Button(self.parent, text='RESTART',command=self.restart)
        restart_button.grid()
        self.canvas = tkinter.Canvas(self.parent, background='black',width = 145, height = 145)
        for row in range(3):
            for column in range(3):
                self.canvas.create_rectangle(self.square_size * column,
                                             self.square_size * row,
                                             self.square_size * (column + 1),
                                             self.square_size * (row + 1),
                                             fill=self.base_color)
        self.canvas.grid()
        self.canvas.bind("<Button-1>", self.play)
        self.result = tkinter.Label(self.parent, text='')
        self.result.grid()

    def restart(self):
        # This method is invoked when the user clicks on the RESTART button.
        for shape in self.canvas.find_all():
            self.canvas.itemconfigure(shape, fill='white')
            self.canvas.bind("<Button-1>", self.play)
        for item in range(0,3):
            self.row_one[item] = 'P0'
        for item in range(0,3):
            self.row_two[item] = 'P0'
        for item in range(0,3):
            self.row_three[item] = 'P0'
        self.result.configure(text='')
        self.turn_count = 0

    def play(self, event):
        # This method is invoked when the user clicks on a square.
        check = 0
        if event.x > 100:
            column = 2
        if event.x > 50 and event.x < 100:
            column = 1
        if event.x <= 50:
            column = 0
        if event.y > 100:
            row = 3
        if event.y > 50 and event.y < 100:
            row = 2
        if event.y <= 50:
            row = 1
                        
        if row == 1:
            if self.row_one[column] != 'P1' and self.row_one[column] != 'P2':
                shape = self.canvas.find_closest(event.x, event.y)
                self.canvas.itemconfigure(shape, fill='green')
                self.row_one[column] = 'P1'
                if self.row_one[0] == 'P1' and self.row_one[1] == 'P1'
                and self.row_one[2] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
                if self.row_one[column] == 'P1' and self.row_two[column] == 'P1'
                and self.row_three[column] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
                if self.row_one[0] == 'P1' and self.row_two[1] == 'P1'
                and self.row_three[2] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
                if self.row_one[2] == 'P1' and self.row_two[1] == 'P1'
                and self.row_three[0] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
            else:
                check = 1
                pass
        if row == 2:
            if self.row_two[column] != 'P1' and self.row_two[column] != 'P2':
                shape = self.canvas.find_closest(event.x, event.y)
                self.canvas.itemconfigure(shape, fill='green')
                self.row_two[column] = 'P1'
                if self.row_two[0] == 'P1' and self.row_two[1] == 'P1'
                and self.row_two[2] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
                if self.row_one[column] == 'P1' and self.row_two[column] == 'P1'
                and self.row_three[column] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
                if self.row_one[0] == 'P1' and self.row_two[1] == 'P1'
                and self.row_three[2] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
                if self.row_one[2] == 'P1' and self.row_two[1] == 'P1'
                and self.row_three[0] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
            else:
                check = 1
                pass
        if row == 3:
            if self.row_three[column] != 'P1' and self.row_three[column] != 'P2':
                shape = self.canvas.find_closest(event.x, event.y)
                self.canvas.itemconfigure(shape, fill='green')
                self.row_three[column] = 'P1'
                if self.row_three[0] == 'P1' and self.row_three[1] == 'P1'
                and self.row_three[2] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
                if self.row_one[column] == 'P1' and self.row_two[column] == 'P1'
                and self.row_three[column] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
                if self.row_three[0] == 'P1' and self.row_two[1] == 'P1'
                and self.row_one[2] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
                if self.row_three[2] == 'P1' and self.row_two[1] == 'P1'
                and self.row_one[0] == 'P1':
                    for shape in self.canvas.find_all():
                        self.canvas.unbind("<Button-1>")
                    self.result.configure(text='You win!')
                    self.turn_count -= 1
                    check = 1
            else:
                check = 1
                pass
        while check == 0:
            random_row = random.randint(0, 150)
            random_column = random.randint(0, 150)
            if random_column > 100:
                column = 2
            if random_column > 50 and random_column < 100:
                column = 1
            if random_column <= 50:
                column = 0
            if random_row > 100:
                row = 3
            if random_row > 50 and random_row < 100:
                row = 2
            if random_row <= 50:
                row = 1
                            
            if row == 1:
                if self.row_one[column] != 'P1' and self.row_one[column] != 'P2':
                    shape = self.canvas.find_closest(random_column, random_row)
                    self.canvas.itemconfigure(shape, fill='red')
                    self.row_one[column] = 'P2'
                    self.turn_count += 1
                    if self.row_one[0] == 'P2' and self.row_one[1] == 'P2'
                    and self.row_one[2] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    if self.row_one[column] == 'P2' and self.row_two[column] == 'P2'
                    and self.row_three[column] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    if self.row_one[0] == 'P2' and self.row_two[1] == 'P2'
                    and self.row_three[2] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    if self.row_one[2] == 'P2' and self.row_two[1] == 'P2'
                    and self.row_three[0] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    check = 1
                else:
                    pass
            if row == 2:
                if self.row_two[column] != 'P1' and self.row_two[column] != 'P2':
                    shape = self.canvas.find_closest(random_column, random_row)
                    self.canvas.itemconfigure(shape, fill='red')
                    self.row_two[column] = 'P2'
                    self.turn_count += 1
                    if self.row_two[0] == 'P2' and self.row_two[1] == 'P2'
                    and self.row_two[2] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    if self.row_one[column] == 'P2' and self.row_two[column] == 'P2'
                    and self.row_three[column] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    if self.row_one[0] == 'P2' and self.row_two[1] == 'P2'
                    and self.row_three[2] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    if self.row_one[2] == 'P2' and self.row_two[1] == 'P2'
                    and self.row_three[0] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    check = 1
                else:
                    pass
            if row == 3:
                if self.row_three[column] != 'P1' and self.row_three[column] != 'P2':
                    shape = self.canvas.find_closest(random_column, random_row)
                    self.canvas.itemconfigure(shape, fill='red')
                    self.row_three[column] = 'P2'
                    self.turn_count += 1
                    if self.row_three[0] == 'P2' and self.row_three[1] == 'P2'
                    and self.row_three[2] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    if self.row_one[column] == 'P2' and self.row_two[column] == 'P2'
                    and self.row_three[column] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    if self.row_three[0] == 'P2' and self.row_two[1] == 'P2'
                    and self.row_one[2] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    if self.row_three[2] == 'P2' and self.row_two[1] == 'P2'
                    and self.row_one[0] == 'P2':
                        for shape in self.canvas.find_all():
                            self.canvas.unbind("<Button-1>")
                        self.result.configure(text='You lose.')
                        self.turn_count -= 1
                    check = 1
                else:
                    pass
        if self.turn_count == 4:
            for shape in self.canvas.find_all():
                self.canvas.unbind("<Button-1>")
            self.result.configure(text='Its a Tie!')
    
def main():
    root = tkinter.Tk()
    new_game = Game(root)
    root.mainloop()

if __name__ == '__main__':
    main()
