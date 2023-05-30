letters: dict[str, dict[str, tuple[str, ...]]] = {}

letters["QWERTY"] = {
    "TOP_ROW": (
        "q",
        "w",
        "e",
        "r",
        "t",
        "y",
        "u",
        "i",
        "o",
        "p",
    ),
    "HOME_ROW": (
        "a",
        "s",
        "d",
        "f",
        "g",
        "h",
        "j",
        "k",
        "l",
    ),
    "BOTTOM_ROW": (
        "z",
        "x",
        "c",
        "v",
        "b",
        "n",
        "m",
    ),
}


def one_row(
    words: list[str], rows: dict[str, tuple[str, ...]] = letters["QWERTY"]
) -> list[str]:
    one_row_words = []
    for word in words:
        row_name = _which_row(word=word, rows=rows)
        if row_name == "ERROR_ROW_NOT_FOUND":
            return [word]
        if _in_row(word=word, row_letters=rows[row_name]):
            one_row_words.append(word)
    return one_row_words


def _which_row(word: str, rows: dict[str, tuple[str, ...]]) -> str:
    letter = word[0]
    for row_name, characters in rows.items():
        if letter.lower() in characters:
            return row_name
    return "ERROR_ROW_NOT_FOUND"


def _in_row(word: str, row_letters: tuple[str, ...]) -> bool:
    for letter in word:
        if letter.lower() not in row_letters:
            return False

    return True
