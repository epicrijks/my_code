"""Demonstrates use of Scoreboard."""
from GameEntry import GameEntry
from Scoreboard import Scoreboard

pacman = Scoreboard()

newScore = GameEntry('Ace', 100)
pacman.add(newScore)
print(pacman)
print()

newScore = GameEntry('Bob', 50)
pacman.add(newScore)
print(pacman)
print()

newScore = GameEntry('Cat', 75)
pacman.add(newScore)
print(pacman)
print()

newScore = GameEntry('Dan', 150)
pacman.add(newScore)
print(pacman)