"""
Write a function that takes an array of consecutive, increasing letters as input, and
returns any missing letters in the array between the first and last letter.

Example:

> missingLetters(['a','b','c','d','f'])
> ['e']

> missingLetters(['a','b','c','d','e','h','i','j','k','l','m','n','o','p','q','r','s',
                't','u','w','x','y','z'])
> ['f','g','v']
"""

all_letters: list[str] = [
"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
]


def missing_letter(letters: list[str]) -> list[str | None]:
    """Returns a list of missing letters."""
    m_letters: list[str | None] = []

    index = 0
    for letter in letters:
        if letter != all_letters[index]:
            found_letters, index = find_letters(index=index, letter=letter)
            m_letters.extend(found_letters)
        index += 1

    return m_letters


def find_letters(index: int, letter: str) -> tuple[list[str], int]:
    found_letters = []
    while True:
        if all_letters[index] == letter:
            break
        found_letters.append(all_letters[index])
        index += 1
    return (found_letters, index)
