while(<>) {
    s/\(.*?\)/\(\)/g;
    print;
}