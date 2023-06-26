import pytest
from missing_letter import missing_letter


@pytest.mark.parametrize(
    "index, letters, m_letters",
    [
        (1, ["a", "b", "c", "d", "f"], ["e"]),
        (
            2,
            [
                "a",
                "b",
                "c",
                "d",
                "e",
                "h",
                "i",
                "j",
                "k",
                "l",
                "m",
                "n",
                "o",
                "p",
                "q",
                "r",
                "s",
                "t",
                "u",
                "w",
                "x",
                "y",
                "z",
            ],
            ["f", "g", "v"],
        ),
    ],
)
def test_missing_letter(index: int, letters: list[str], m_letters: list[str]):
    assert missing_letter(letters=letters) == m_letters, f"Test: {index}"
