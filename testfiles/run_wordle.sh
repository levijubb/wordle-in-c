#!/bin/bash
# Usage: run_wordle.sh answer guess-file [args]
# Runs wordle with the given word as the answer with stdin redirected from
# the given guess file (one guess per line). 
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
export WORD2310="${answer}"
# Run the program and only output the first $lines lines. 
${wordle:=./wordle} "$@" < ${guesses} | \
    awk "NR<=200 {print \$0} \
	NR==201 {print \"Output truncated - exceeds 200 lines\"}"
# Get wordle's exit status (first command in the pipeline)
status=${PIPESTATUS[0]}
exit $status
