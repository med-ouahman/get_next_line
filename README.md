# 42 get_next_line Project

## Mandatory Part:

- This project's main goal is to read a line from a file each time the get_next_line() function is called.
- It handles expected errors like an invalid file descriptor or when a file doesn't have read permissions.
- It reads a certain amount of bytes each time until if finds a newline character, then it allocates memory for the line.
- It saves any leftovers in a static variable to make sure no bytes are skipped.

  ## Bonus Part:

  - The bonus part of this project aims to do the same thing as the mandatory part but it read from multiple files at the same time.
  - It follows the same rules as the mandatory version.
