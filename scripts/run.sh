#!/usr/bin/env bash
# Build and run one file: ./scripts/run.sh leetcode/arrays-hashing/0217-contains-duplicate.cpp
set -euo pipefail
cd "$(dirname "$0")/.."
[ $# -eq 1 ] || { echo "Usage: ./scripts/run.sh <path/to/file.cpp>"; exit 1; }
target=$(printf '%s' "${1%.cpp}" | sed 's|/|__|g')
[ -d build ] || cmake -B build > /dev/null
cmake -B build > /dev/null   # picks up newly added files
cmake --build build --target "$target"
"./build/$target"
