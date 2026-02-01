"""
This is the Base class, which handles basic input parsing and answer verification.

See README.md for how to use it; you shouldn't need to edit it directly.

If something in here is giving you trouble, please file an issue:

https://github.com/xavdid/advent-of-code-python-template/issues
"""

from enum import Enum, auto
from functools import wraps
from pathlib import Path
from pprint import pprint
from typing import (
    Callable,
    Generic,
    TypeVar,
    TypeVarTuple,
    Union,
    Unpack,
    cast,
    final,
    overload,
)


class AoCException(Exception):
    """
    custom error class for issues related to creating/running solutions
    """

    pass


class InputTypes(Enum):
    # one solid block of text; the default
    TEXT = auto()
    # a single int
    INTEGER = auto()
    # str[], split by a specified separator (default newline)
    STRSPLIT = auto()
    # int[], split by a split by a specified separator (default newline)
    INTSPLIT = auto()


# almost always int, but occasionally str; None is fine to disable a part
ResultType = Union[int, str, None]


def print_answer(i: int, ans: ResultType):
    if ans is not None:
        print(f"\n== Part {i}")
        print(f"=== {ans}")


InputType = Union[str, int, list[int], list[str], list[list[int]]]
I = TypeVar("I", bound=InputType)


class BaseSolution(Generic[I]):
    separator = "\n"

    # Solution Subclasses define these
    input_type: InputTypes = InputTypes.TEXT
    _year: int
    _day: int

    def __init__(self, run_slow=False, is_debugging=False, use_test_data=False):
        self.slow = run_slow  # should run slow functions?
        self.is_debugging = is_debugging
        self.use_test_data = use_test_data

        self.input = cast(I, self.read_input())

    @property
    def year(self):
        if not hasattr(self, "_year"):
            raise NotImplementedError("explicitly define Solution._year")
        return self._year

    @property
    def day(self):
        if not hasattr(self, "_day"):
            raise NotImplementedError("explicitly define Solution._day")
        return self._day

    def solve(self) -> tuple[ResultType, ResultType]:
        """
        Returns a 2-tuple with the answers.
            Used instead of `part_1/2` if one set of calculations yields both answers.
        """
        return self.part_1(), self.part_2()

    def part_1(self):
        """
        Returns the answer for part 1 of the puzzle. Only needed if there's not a unified solve method.
        """

    def part_2(self):
        """
        Returns the answer for part 2 of the puzzle. Only needed if there's not a unified solve method.
        """

    @final
    def read_input(self) -> InputType:
        """
        handles locating, reading, and parsing input files
        """
        input_file = Path(
            # __file__ is the solution base
            Path(__file__).parent,
            # the 4-digit year
            str(self.year),
            # padded day folder
            f"day_{self.day:02}",
            # either the real input or the test input
            f"input{'.test' if self.use_test_data else ''}.txt",
        )
        if not input_file.exists():
            raise AoCException(
                f'Failed to find an input file at path "./{input_file.relative_to(Path.cwd())}". You can run `./start --year {self.year} {self.day}` to create it.'
            )

        data = input_file.read_text().strip("\n")

        if not data:
            raise AoCException(
                f'Found a file at path "./{input_file.relative_to(Path.cwd())}", but it was empty. Make sure to paste some input!'
            )

        if self.input_type is InputTypes.TEXT:
            return data

        if self.input_type is InputTypes.INTEGER:
            return int(data)

        if (
            self.input_type is InputTypes.STRSPLIT
            or self.input_type is InputTypes.INTSPLIT
        ):
            # default to newlines
            parts = data.split(self.separator)

            if self.input_type == InputTypes.INTSPLIT:
                return [int(i) for i in parts]

            return parts

        raise ValueError(f"Unrecognized input_type: {self.input_type}")

    @final
    def run_and_print_solutions(self):
        result = self.solve()
        print(f"= Solutions for {self.year} Day {self.day}")
        try:
            if result:
                p1, p2 = result
                print_answer(1, p1)
                print_answer(2, p2)
            print()
        except TypeError as exc:
            raise ValueError(
                "unable to unpack 2-tuple from `solve`, got", result
            ) from exc

    @final
    def debug(self, *objects, trailing_newline=False):
        """
        helpful debugging utility. Does nothing if `./advent` isn't passed the --debug flag

        Takes any number of objects and pretty-prints them. Can add a trailing newline to create separation between blocks
        """
        if not self.is_debugging:
            return

        for o in objects:
            if isinstance(o, str):
                print(o)
            else:
                pprint(o)

        if trailing_newline:
            print()


class TextSolution(BaseSolution[str]):
    """
    input is one solid block of text; the default
    """

    input_type = InputTypes.TEXT


class IntSolution(BaseSolution[int]):
    """
    input is a single int
    """

    input_type = InputTypes.INTEGER


class StrSplitSolution(BaseSolution[list[str]]):
    """
    input is a str[], split by a specified separator (default newline); specify self.separator to tweak
    """

    input_type = InputTypes.STRSPLIT


class IntSplitSolution(BaseSolution[list[int]]):
    """
    input is a int[], split by a specified separator (default newline); specify self.separator to tweak
    """

    input_type = InputTypes.INTSPLIT


# https://stackoverflow.com/a/65681955/1825390
SolutionClassType = TypeVar("SolutionClassType", bound=BaseSolution)
# what the functions that @answer wraps can return
OutputType = Union[ResultType, tuple[ResultType, ResultType]]


def slow(
    func: Callable[[SolutionClassType], OutputType],
) -> Callable[[SolutionClassType], OutputType]:
    """
    A decorator for solution methods that blocks their execution (and returns without error)
    if the the function is manually marked as "slow". Helpful if running many solutions at once,
    so one doesn't gum up the whole thing.
    """

    def wrapper(self: SolutionClassType):
        if self.slow or self.use_test_data:
            return func(self)

        print(
            f"\nRefusing to run slow function ({func.__name__}). "
            "Run `./advent` again with the `--slow` flag."
        )
        return None

    return wrapper


# these types ensure the return type of the function matches `@answer`
# see: https://github.com/microsoft/pyright/discussions/4317#discussioncomment-4386187
R = TypeVar("R")  # return type generic
Ts = TypeVarTuple("Ts")  # tuple items generic


@overload
def answer(
    expected: tuple[Unpack[Ts]],
) -> Callable[
    [Callable[[SolutionClassType], tuple[Unpack[Ts]]]],
    Callable[[SolutionClassType], tuple[Unpack[Ts]]],
]:
    ...


@overload
def answer(
    expected: R,
) -> Callable[[Callable[[SolutionClassType], R]], Callable[[SolutionClassType], R]]:
    ...


def answer(
    expected: R,
) -> Callable[[Callable[[SolutionClassType], R]], Callable[[SolutionClassType], R]]:
    """
    Decorator to assert the result of the function is a certain thing.
    This is specifically designed to be used on instance methods of BaseSolution.
    It only throws errors when _not_ using test data.

    Usage:
    ```py
    @answer(3)
    def f(i):
        return i

    f(1) # throws
    f(3) # returns 3 like normal
    ```
    """

    def deco(func: Callable[[SolutionClassType], R]):
        @wraps(func)
        # uses `self` because that's what's passed to the original solution function
        def wrapper(self: SolutionClassType):
            result = func(self)
            # only assert the answer for non-test data
            if not self.use_test_data and result is not None:
                if result != expected:
                    _, year, day, _ = self.__module__.split(".")
                    raise AoCException(
                        f"Failed @answer assertion for {year} / {day} / {func.__name__}:\n  returned: {result}\n  expected: {expected}"
                    )
            return result

        return wrapper

    return deco

from heapq import heappop, heappush
from typing import NamedTuple


from enum import IntEnum
from itertools import product
from operator import itemgetter
from typing import Iterator, Literal

GridPoint = tuple[int, int]
Grid = dict[GridPoint, str]

DIRECTIONS = sorted(product((-1, 0, 1), repeat=2), key=itemgetter(1))


def neighbors(
    center: GridPoint,
    num_directions=8,
    *,
    ignore_negatives: bool = False,
    max_size: int = 0,
    max_x_size: int = 0,
    max_y_size: int = 0,
) -> Iterator[tuple[int, int]]:
    """
    given a point (2-tuple) it yields each neighboring point.
    Iterates from top left to bottom right, skipping any points as described below:

    * `num_directions`: Can get cardinal directions (4), include diagonals (8), or include self (9)
    * `ignore_negatives`: skips points where either value is less than 0
    * `max_DIM_size`: if specified, skips points where the dimension value is greater than the max grid size in that dimension. If doing a 2D-List based (aka `(row,col)` grid) rather than a pure `(x,y)` grid, the max values should be `len(DIM) - 1`. Is mutually exclusive with `max_size`.

    For a 2D list-based grid, neighbors will come out in (row, col) format.
    """
    assert num_directions in {4, 8, 9}
    # one or the other
    if max_size:
        assert not (max_x_size or max_y_size)
    if max_x_size or max_y_size:
        assert not max_size

    for dx, dy in DIRECTIONS:
        if num_directions == 4 and dx and dy:
            # diagonal; skip
            continue

        if num_directions != 9 and not (dx or dy):
            # skip self
            continue

        rx = center[0] + dx
        ry = center[1] + dy

        if ignore_negatives and (rx < 0 or ry < 0):
            continue

        if max_size and (rx > max_size or ry > max_size):
            continue

        if max_x_size and (rx > max_x_size):
            continue

        if max_y_size and (ry > max_y_size):
            continue

        yield (rx, ry)


def parse_grid(raw_grid: list[str], ignore_chars: str = "") -> Grid:
    """
    returns 2-tuples of (row, col) with their value

    (0, 0) ------> (0, 9)
      |              |
      |              |
      |              |
      |              |
      |              V
    (9, 0) ------> (9, 9)
    """
    result = {}
    ignore = set(ignore_chars)

    for row, line in enumerate(raw_grid):
        for col, c in enumerate(line):
            if c in ignore:
                continue
            result[row, col] = c

    return result


def add_points(a: GridPoint, b: GridPoint) -> GridPoint:
    """
    add a pair of 2-tuples together. Useful for calculating a new position from a location and an offset
    """
    return a[0] + b[0], a[1] + b[1]


def taxicab_distance(a: GridPoint, b: GridPoint) -> int:
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


Rotation = Literal["CCW", "CW"]


class Direction(IntEnum):
    UP = 0
    RIGHT = 1
    DOWN = 2
    LEFT = 3

    @staticmethod
    def rotate(facing: "Direction", towards: Rotation) -> "Direction":
        offset = 1 if towards == "CW" else -1
        return Direction((facing.value + offset) % 4)

    @staticmethod
    def offset(facing: "Direction") -> GridPoint:
        return _ROW_COLL_OFFSETS[facing]


_ROW_COLL_OFFSETS: dict[Direction, GridPoint] = {
    Direction.UP: (-1, 0),
    Direction.RIGHT: (0, 1),
    Direction.DOWN: (1, 0),
    Direction.LEFT: (0, -1),
}

class Position(NamedTuple):
    loc: GridPoint
    facing: Direction

    @property
    def next_loc(self) -> GridPoint:
        return add_points(self.loc, Direction.offset(self.facing))

    def step(self) -> "Position":
        return Position(self.next_loc, self.facing)

    def rotate_and_step(self, towards: Rotation):
        return Position(self.loc, Direction.rotate(self.facing, towards)).step()


# cost, position, number of steps in the same direction (max 3)
State = tuple[int, Position, int]


class Solution(StrSplitSolution):
    _year = 2023
    _day = 17

    def _solve(self, min_steps: int, max_steps: int) -> int:
        target = len(self.input) - 1, len(self.input[-1]) - 1
        grid = {k: int(v) for k, v in parse_grid(self.input).items()}

        queue: list[State] = [
            (0, Position((0, 0), Direction.DOWN), 0),
            (0, Position((0, 0), Direction.RIGHT), 0),
        ]
        seen: set[tuple[Position, int]] = set()

        while queue:
            cost, pos, num_steps = heappop(queue)

            if pos.loc == target and num_steps >= min_steps:
                return cost

            if (pos, num_steps) in seen:
                continue
            seen.add((pos, num_steps))

            if (
                num_steps >= min_steps
                and (left := pos.rotate_and_step("CCW")).loc in grid
            ):
                heappush(queue, (cost + grid[left.loc], left, 1))

            if (
                num_steps >= min_steps
                and (right := pos.rotate_and_step("CW")).loc in grid
            ):
                heappush(queue, (cost + grid[right.loc], right, 1))

            if num_steps < max_steps and (forward := pos.step()).loc in grid:
                heappush(queue, (cost + grid[forward.loc], forward, num_steps + 1))

        return -1

    def part_1(self) -> int:
        return self._solve(0, 3)

    def part_2(self) -> int:
        return self._solve(4, 10)

sol = Solution()

print(sol.part_2())
