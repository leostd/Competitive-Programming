# Competitive-Programming
My competitive programming archive: solutions, templates, and training material.

## Structure (current)
- `Codeforces/`, `AtCoder/`, `UVa/`, `SPOJ/`, `HackerRank/`, `LeetCode/`, etc.
  - Contest or problem folders with `sol.cpp` (or problem name) and optional `testcases/`.
- `Library/`
  - Reusable algorithms and data structures, organized by topic.
- `Templates/`
  - Base templates, generators, and utilities.
- `Problemsetting/`
  - Problem statements and test data (`.in`, `.ans`).
- `WorkInProgress/` and `Unordered/`
  - Mixed/temporary content that should be triaged into the right platform.

## Workflow (neovim + cpbooster + UltiSnippets)
- `cpbooster-config.json` is the repo default config (editor `nvim`, C++ template `Templates/main.cpp`).
- With `cloneInCurrentDir: true`, run `cpb clone` from inside the target platform folder
  to keep a flat per-contest layout (e.g., `Codeforces/<Contest>/A.cpp`, `B.cpp`, ...).
- Use UltiSnippets to paste the C++ template on new files as usual.
- Compile aliases used in this repo:
  - `dbg`: compile with debug flags (prints debug statements).
  - `comp`: release compile (no debug output).
  - `dbgbf`: debug compile to a separate brute-force executable.
  - `compbf`: release compile to a separate brute-force executable.

## Naming conventions (suggested)
- Solutions: `sol.cpp` (or `A.cpp`/`B.cpp` for contest letters).
- Testcases: `testcases/0.in`, `testcases/0.out`, etc.
- Keep one problem per folder when possible.

## Cleanup policy
- Build artifacts and OS/editor temp files are ignored via `.gitignore`.
- Keep input/output testcases under `testcases/`.

## Next organization pass
- Move `Unordered/` files into their correct platform folders.
- Split `WorkInProgress/` into `Inbox/` (new work) and `Archive/` (old/unused).
- For Codeforces, consolidate either `Problems/` or `Rounds/` to a single scheme.
