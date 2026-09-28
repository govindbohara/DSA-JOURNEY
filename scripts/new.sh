#!/usr/bin/env bash
# Usage: ./scripts/new.sh <pattern-folder> <number> "Problem Title" [Easy|Medium|Hard]
set -euo pipefail
cd "$(dirname "$0")/.."

if [ $# -lt 3 ]; then
  echo 'Usage: ./scripts/new.sh <pattern-folder> <number> "Problem Title" [Easy|Medium|Hard]'
  echo "Pattern folders:"; ls leetcode
  exit 1
fi

pattern=$1; number=$2; title=$3; difficulty=${4:-Easy}
slug=$(printf '%s' "$title" | tr '[:upper:]' '[:lower:]' | sed -E 's/[^a-z0-9]+/-/g; s/^-+|-+$//g')
dir="leetcode/$pattern"
file="$dir/$(printf '%04d' "$number")-$slug.cpp"

[ -d "$dir" ] || { echo "No folder $dir. Choose one of:"; ls leetcode; exit 1; }
[ -e "$file" ] && { echo "$file already exists"; exit 1; }

sed -e "s|{{TITLE}}|$title|g" -e "s|{{NUM}}|$number|g" -e "s|{{SLUG}}|$slug|g" \
    -e "s|{{DIFF}}|$difficulty|g" -e "s|{{DATE}}|$(date +%F)|g" \
    templates/solution.cpp > "$file"
rm -f "$dir/.gitkeep"
echo "Created $file"
