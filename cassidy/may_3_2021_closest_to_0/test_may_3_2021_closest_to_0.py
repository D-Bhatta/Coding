from may_3_2021_closest_to_0 import round

def test_round():
    # From @cassidoo(https://twitter.com/cassidoo)
    assert round(1.7) == 1, "Failed at test case 1"
    assert round(-2.1) == -2, "Failed at test case 2"
    assert round(500.4) == 500, "Failed at test case 3"
    assert round(-369.5) == -369, "Failed at test case 4"
    assert round(150) == 150, "Failed at test case 5"
    assert round(-350) == -350, "Failed at test case 6"
    # New cases I created
    assert round(-0) == 0, "Failed at test case 7"
    assert round(-0.9) == 0, "Failed at test case 8"
    assert round(0.9) == 0, "Failed at test case 9"
    assert round(1.01) == 1, "Failed at test case 10"