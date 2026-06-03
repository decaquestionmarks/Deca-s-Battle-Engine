#!/usr/bin/env bash
# Run a Windows executable via cmd.exe, converting paths as needed.
# Usage: run_win_cmd.sh <path-to-exe> [args...]

set -euo pipefail

if [ $# -lt 1 ]; then
  echo "usage: $0 <exe> [args...]" >&2
  exit 2
fi

exe="$1"
shift || true

if command -v cygpath >/dev/null 2>&1; then
  winpath=$(cygpath -w "$exe")
else
  # naive slash -> backslash conversion
  winpath=$(printf '%s' "$exe" | sed 's#/#\\#g')
fi

if [ ! -f "$winpath" ] && [ -f "${winpath}.exe" ]; then
  winpath="${winpath}.exe"
fi

# build args string with quotes
args=""
for a in "$@"; do
  args="$args \"$a\""
done

powershell.exe -NoProfile -ExecutionPolicy Bypass -Command "& \"$winpath\" $args"
