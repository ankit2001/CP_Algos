class BlackBoxGame:
    """
    Making a Grid named Matrix as private variable
    and initializing it to 0
    Also other data members like score for total score, total_atoms for total atoms, atoms_dict to store previous atoms, 
    guesses_dict to store previous guesses, entry dict to store previous entry points of rays
    """
    __Matrix = [[0 for x in range(10)] for y in range(10)] 
    __score = 25
    __total_atoms = 0
    __atoms_dict = {}
    __guesses_dict = {}
    __entry_dict = {}
    def __init__(self, val):
        """
        Initiazlizing all the private members using init method
        """
        self.__total_atoms = len(val)
        for x in val:
            self.__atoms_dict[(x[0], x[1])] = 1
            self.__guesses_dict[(x[0], x[1])] = 1
            self.__Matrix[x[0]][x[1]] = 1

    def Print(self):
        """
        Printing Method to print all the Present Grid values
        """
        for x in self.__Matrix:
            print(x)
        print(self.__atoms_dict)

    def get_score(self):
        """
        Method to return final total final score
        """
        return self.__score
    
    def reflection(self, x, y):
        """
        Wrapper function to check reflection is taking place or not
        Method will return boolean variable
        """
        if x == 0:
            if self.__Matrix[x + 1][y - 1] == 1 or self.__Matrix[x + 1][y + 1] == 1:
                return True
        if x == 9:
            if self.__Matrix[x - 1][y - 1] == 1 or self.__Matrix[x - 1][y + 1] == 1:
                return True
        if y == 0:
            if self.__Matrix[x - 1][y + 1] == 1 or self.__Matrix[x + 1][y + 1] == 1:
                return True
        if y == 9:
            if self.__Matrix[x + 1][y - 1] == 1 or self.__Matrix[x - 1][y - 1] == 1:
                return True
        return False
    
    def exit_indexes(self, x, y):
        """
        Method to return exit indexes as in tuple like (x1, y1) form if no reflection is taking place
        """
        direction = ""
        if x == 0:
            direction = "down"
            x += 1
        if x == 9:
            direction = "up"
            x -= 1
        if y == 0:
            direction = "right"
            y += 1
        if y == 9:
            direction = "left"
            y -= 1
        while True:
            if self.__Matrix[x][y] == 1 or x == 0 or x == 9 or y == 0 or y == 9:
                return (x, y)
            if direction == "down":
                if self.__Matrix[x + 1][y] == 1:
                    pass
                elif self.__Matrix[x + 1][y - 1] == 1:
                    direction = "right"
                elif self.__Matrix[x + 1][y + 1]:
                    direction = "left"
            elif direction == "up":
                if self.__Matrix[x - 1][y] == 1:
                    pass
                elif self.__Matrix[x - 1][y - 1]:
                    direction = "right"
                elif self.__Matrix[x - 1][y + 1]:
                    direction = "left"
            elif direction == "left":
                if self.__Matrix[x][y - 1] == 1:
                    pass
                elif self.__Matrix[x - 1][y - 1] == 1:
                    direction = "down"
                elif self.__Matrix[x + 1][y - 1]:
                    direction = "up"
            elif direction == "right":
                if self.__Matrix[x][y + 1] == 1:
                    pass
                elif self.__Matrix[x - 1][y + 1] == 1:
                    direction = "down"
                elif self.__Matrix[x + 1][y + 1] == 1:
                    direction = "up"
            if direction == "down":
                x += 1
            elif direction == "up":
                x -= 1
            elif direction == "right":
                y += 1
            elif direction == "left":
                y -= 1

    def shoot_ray(self, x, y):
        """
        Method to find a ray will hit, reflect, miss or Detour
        """
        if (((x == 0 or x == 9) and (y >= 1 and y <= 8)) or ((y == 0 or y == 9) and (x >= 1 and x <= 8))):
            if self.reflection(x, y):
                if self.__entry_dict.get((x, y)) == None:
                    self.__score -= 1
                    self.__entry_dict[(x, y)] = 1
                """
                Return None if a ray reflects
                """
                return None
            (x1, y1) = self.exit_indexes(x, y)
            if x1 != 0 and x1 != 9 and y1!= 0 and y1 != 9:
                if self.__entry_dict.get((x, y)) == None:
                    self.__score -= 1
                    self.__entry_dict[(x, y)] = 1
                """
                Return False if a ray is hit
                """
                return None
            else:
                if self.__entry_dict.get((x, y)) == None:
                    self.__score -= 2
                    self.__entry_dict[(x, y)] = 1
                """
                Return exit points as tuples if a ray detour or misses
                """
                return (x1, y1)
        else:
            """
            Return False if invalid (x, y) for ray
            """
            return False

    def guess_atom(self, x, y):
        """
        Method to you guessed the correct atom or not
        """
        if self.__guesses_dict.get((x, y)) == None:
            self.__score -= 5
            self.__guesses_dict[(x, y)] = 1

        if self.__Matrix[x][y] == 1:
            del self.__atoms_dict[(x, y)]
            return True
        return False
    
    def atoms_left(self):
        """
        Method to find number of atoms left to be guessed
        """
        return len(self.__atoms_dict)

if __name__ == "__main__":
    #Creating BlackBoxGame Class and using init method to initialize
    game = BlackBoxGame([(3, 2), (1, 7), (4, 6), (8, 8)])
    #Printing the grid 
    game.Print()
    #Ray at (5, 9) will give (7, 0) as ouput or exit point according to Algorithm
    move_result = game.shoot_ray(5, 9)
    print(move_result)
    #Ray at (0, 2) will also give None object
    game.shoot_ray(0, 2)
    print(game.shoot_ray(0, 2))
    #(3, 2) is desired location of atom returns True
    guess_result = game.guess_atom(3, 2)
    print(guess_result)
    #Getting score after all operation i.e. 22
    score = game.get_score()
    print(score)
    #No of atoms left i.e 3
    atoms = game.atoms_left()
    print(atoms)