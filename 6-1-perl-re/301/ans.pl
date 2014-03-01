
@inp = <STDIN>;

foreach $line ( @inp ) {
    $line =~ s/^\s*//;
    $line =~ s/\s*$//;
    $line =~ s/ +/ /g;
}
$s = join("\n", @inp);
$s =~ s/^\n*//;
$s =~ s/\n*$//;
$s =~ s/\n{2,}/\n\n/g;
print $s;

