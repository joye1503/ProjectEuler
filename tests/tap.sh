# Run in subshell
(build/$1 || false) > ${output}.out 2> ${output}.err
status=$?

# status
if [ $status -eq 0 ]; then
    printf "ok $i0 $1\n"
else
    printf "not ok $i0 $1\n"
fi

# stdout
if [ -f tests/output/$1.out ]; then
    if diff -u tests/output/$1.out ${output}.out > ${output}.diff; then
        printf "ok $i1 $1 stdout\n"
    else
        printf "not ok $i1 $1 stdout\n"
        while read line; do
            printf "# ${line}\n"
        done < ${output}.diff
    fi
elif [ -s ${output}.out ]; then
    printf "not ok $i1 $1 stdout\n"
    while read line; do
        printf "# + ${line}\n"
    done < ${output}.out
else
    printf "ok $i1 $1 stdout\n"
fi

# stderr
if [ -s ${output}.err ]; then
    printf "not ok $i2 $1 stderr\n"
    while read line; do
        printf "# +${line}\n"
    done < ${output}.err
else
    printf "ok $i2 $1 stderr\n"
fi
