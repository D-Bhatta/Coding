import pytest
from one_row import one_row


@pytest.mark.parametrize(
    "index, words, words_one_row",
    [
        (
            1,
            ["candy", "fart", "pop", "Zelda", "flag", "typewriter"],
            ["pop", "flag", "typewriter"],
        ),
        (
            2,
            [
                "survival",
                "leftovers",
                "differ",
                "solution",
                "flask",
            ],
            ["flask"],
        ),
        (
            3,
            [
                "principle",
                "double",
                "writer",
                "perpetuity",
                "flags",
                "compromise",
                "yeet"
            ],
            ["writer", "perpetuity", "flags", "yeet"],
        ),
    ],
)
def test_one_row(index: int, words: list[str], words_one_row: list[str]):
    assert one_row(words=words) == words_one_row, f"Error in test: {index}"
