while(<>) {
    print if /\([^()]*\w[^()]*\)/;
}