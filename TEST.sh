#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

BUILD_DIR="${SCRIPT_DIR}/build"
INPUT_FILE="${SCRIPT_DIR}/inputs/pieces.txt"

"${BUILD_DIR}/PetroGM_test_task" "${INPUT_FILE}"