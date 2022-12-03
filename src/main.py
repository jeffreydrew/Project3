import pygame, random, sys
from pygame.locals import *

SIZE = (500, 500)
WHITE = (0, 0, 0)
BLACK = (255, 255, 255)

width = 1


class Board:
    # initializes the board
    def __init__(self, size=SIZE):
        self.size = size

    def window(self):
        # creates the window
        pygame.init()
        pygame.display.set_caption("Password Colorizer")

        self.background = pygame.Surface(self.size)
        self.background.fill((0, 0, 0))
        self.screen = pygame.display.set_mode(self.size)


class ColorBar:  # the width will depend on the length of the XORed string, basically (SIZE[1]/len(XORed string))
    # initialize the color bars
    def __init__(self, height=SIZE[1], color=WHITE):
        self.height = height
        self.color = color
        self.width = width


class Password:
    # initializes the password
    def __init__(self):
        self.plaintext = ""  # plaintext is the password straight from rockyou
        self.ciphertext = (
            ""  # ciphertext is the password after it's been XORed with the key
        )
        self.key = ""  # the key :)

    def xor(self):
        # xor the plaintext with the key and store the result in ciphertext
        pass


class Universe:
    # initialize the universe
    def __init__(self):
        self.board = Board()
        self.password = Password()
        self.bars = []  # vector of color bars
        self.running = True

    def update(self):
        # update the universe
        # wont really need this, but we could probably show the bars while the password is being xored, that'd be pretty cool
        # don't do any visual stuff here, its all backend
        ###rules###

        pass

    def draw(self, screen):
        # draw the universe
        # fill the screen with white
        screen = self.board.screen
        background = self.board.background
        screen.blit(background, (0, 0))
        # do all the visual stuff here on the pygame board

    def run(self):
        # run the universe
        self.board.window()
        screen = self.board.screen
        background = self.board.background
        clock = pygame.time.Clock()
        while self.running:
            # this is the event loop
            for event in pygame.event.get():
                if event.type == QUIT:
                    pygame.quit()
                    sys.exit()
                # if key q down, quit
                if event.type == KEYDOWN:
                    if event.key == K_q:
                        pygame.quit()
                        sys.exit()
            self.update()
            self.draw(screen)
            pygame.display.update()
            clock.tick(60)


def takeInput():  # this can be in CLI or have a way to display this on the window, should prob be part of Universe class
    print("Enter characters to be in password: ")
    characters = input()
    # use search algorithm to find best fit password in rockyou.txt


# driver
def main():
    universe = Universe()
    universe.run()
    # will run takeinput(), search algorithm and store the appropriate password, run XOR with input string,
    # create color bars based on the XORed string, and display the password
    pass


if __name__ == "__main__":
    main()
