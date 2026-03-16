#!/usr/bin/env bash
# Symlink ~/.config/nvim/UltiSnips -> repo/Snippets/UltiSnippets so nvim/LazyVim
# loads version-controlled snippets. Run from anywhere inside the repo.

set -e

REPO_ROOT="$(git -C "$(dirname "${BASH_SOURCE[0]}")" rev-parse --show-toplevel)"
SNIPPETS_SRC="${REPO_ROOT}/Snippets/UltiSnippets"
NVIM_ULTI="${XDG_CONFIG_HOME:-$HOME/.config}/nvim/UltiSnips"

if [[ ! -d "$SNIPPETS_SRC" ]]; then
  echo "Error: Snippets dir not found: $SNIPPETS_SRC" >&2
  exit 1
fi

mkdir -p "$(dirname "$NVIM_ULTI")"

if [[ -L "$NVIM_ULTI" ]]; then
  CURRENT="$(readlink "$NVIM_ULTI")"
  if [[ "$CURRENT" == "$SNIPPETS_SRC" ]]; then
    echo "UltiSnips already linked to repo: $SNIPPETS_SRC"
    exit 0
  fi
  echo "Replacing existing UltiSnips symlink (was: $CURRENT)"
  rm "$NVIM_ULTI"
elif [[ -e "$NVIM_ULTI" ]]; then
  BACKUP="${NVIM_ULTI}.bak.$(date +%Y%m%d%H%M%S)"
  echo "Backing up existing UltiSnips to: $BACKUP"
  mv "$NVIM_ULTI" "$BACKUP"
fi

ln -s "$SNIPPETS_SRC" "$NVIM_ULTI"
echo "Linked: $NVIM_ULTI -> $SNIPPETS_SRC"
echo "Done. Restart nvim or open a file to use the snippets."
