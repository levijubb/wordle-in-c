#!/bin/bash
# Usage: run_wordle_and_save_first_two_lines.sh answer guess-file [args]
# Runs wordle with the given word as the answer with stdin redirected from
# the given guess file (one guess per line). 
# Only the first two lines from standard output will be saved.
# Additional args are given as command line arguments to wordle.
if [ "$#" -lt 2 ] ; then
    echo "Insufficient arguments to $0" >&2
    exit 1
fi
if [ ! -r "$2" ] ; then
    echo "Can't read guesses file \"$2\"" >&2
    exit 2
fi
answer="$1"
guesses="$2"
shift 2
line=2
export WORD2310="${answer}"
# Run the program and only output the first 2 lines. 
${wordle:=./wordle} "$@" < ${guesses} | head -2 
# There is a possibility wordle gets a SIGPIPE. We just exit
# with exit status 0 here.
exit 0
