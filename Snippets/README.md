# UltiSnips snippets (version controlled)

Snippets live here so they stay in sync across machines and are version controlled with the rest of the repo.

- **`UltiSnippets/cpp.snippets`** – C++ (template, sieve, etc.)
- **`UltiSnippets/python.snippets`** – Python

## Using on a new Mac

Two options; pick one.

### Option A: Symlink (recommended)

Run once after cloning the repo (from anywhere inside the repo):

```bash
./scripts/setup-ultisnips.sh
```

This links `~/.config/nvim/UltiSnips` → `Snippets/UltiSnippets` in this repo. Nvim/LazyVim will load snippets from the repo; pull the repo to get updates.

### Option B: Env var in Neovim config

If you prefer not to use a symlink:

1. Set an env var on each Mac (e.g. in `~/.zshrc`):

   ```bash
   export CP_REPO="$HOME/ws/Competitive-Programming"   # or your clone path
   ```

2. In your LazyVim config (e.g. `~/.config/nvim/lua/config/options.lua` or a dedicated snippet config), add:

   ```lua
   vim.g.UltiSnipsSnippetsDir = os.getenv("CP_REPO") .. "/Snippets/UltiSnippets"
   vim.g.UltiSnipsSnippetDirectories = { "UltiSnips" }
   ```

   Or in Vimscript (e.g. in `plugin/ultisnips.lua` or `after/plugin/ultisnips.vim`):

   ```vim
   let g:UltiSnipsSnippetsDir = $CP_REPO . "/Snippets/UltiSnippets"
   let g:UltiSnipsSnippetDirectories = ['UltiSnips']
   ```

Then open nvim; UltiSnips will use the repo snippets. Ensure UltiSnips is installed in LazyVim (e.g. via `lazy.nvim`).

## Editing snippets

Edit `UltiSnippets/*.snippets` in this repo and commit/push as usual. On other machines, pull and (with Option A) the symlink already points at the updated files; with Option B, restart nvim or reload.
