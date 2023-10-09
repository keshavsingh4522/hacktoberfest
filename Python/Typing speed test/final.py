import curses
from curses import wrapper
import time
import random


def start_screen(stdscr):
	stdscr.clear()
	stdscr.addstr(1, 40, "Welcome to the Speed Typing Test!")
	stdscr.addstr(2, 3,  "\nPress any key to begin!")
	stdscr.refresh()
	stdscr.getkey()

def display_text(stdscr, target, current, wpm=0):
	stdscr.addstr(1, 3, target)
	stdscr.addstr(3, 3, f"WPM: {wpm}")

	for i, char in enumerate(current):
		correct_char = target[i]
		color = curses.color_pair(1)
		if char != correct_char:
			color = curses.color_pair(2)

		stdscr.addstr(1, i+3, char, color)

def load_text():
	with open("text.txt", "r") as f:
		lines = f.readlines()
		return random.choice(lines).strip()

def wpm_test(stdscr):
	target_text = load_text()
	current_text = []
	wpm = 0
	start_time = time.time()
	stdscr.nodelay(True)

	while True:
		time_elapsed = max(time.time() - start_time, 1)
		wpm = round((len(current_text) / (time_elapsed / 60)) / 5)

		stdscr.clear()
		display_text(stdscr, target_text, current_text, wpm)
		stdscr.refresh()

		if "".join(current_text) == target_text:
			stdscr.nodelay(False)
			break

		try:
			key = stdscr.getkey()
		except:
			continue

		if ord(key) == 27:
			break

		if key in ("KEY_BACKSPACE", '\b', "\x7f"):
			if len(current_text) > 0:
				current_text.pop()
		elif len(current_text) < len(target_text):
			current_text.append(key)


def main(stdscr):
	curses.init_pair(1, curses.COLOR_GREEN, curses.COLOR_BLACK)
	curses.init_pair(2, curses.COLOR_RED, curses.COLOR_BLACK)
	curses.init_pair(3, curses.COLOR_WHITE, curses.COLOR_BLACK)

	start_screen(stdscr)
	while True:
		wpm_test(stdscr)
		stdscr.addstr(5, 3, "Congratulations!! You completed the text. ")
		stdscr.addstr(6, 3, "Press any key to retry or escape to end...")
		key = stdscr.getkey()
		
		if ord(key) == 27:
			break

wrapper(main)
