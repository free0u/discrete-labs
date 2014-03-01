sub uniq {
    return keys %{{ map { $_ => 1 } @_ }};
}

@inp = <STDIN>;

foreach $line ( @inp ) {
    $line =~ s/^\s*//;
    $line =~ s/\s*$//;
}
$s = join(" ", @inp);

@ans = ();

while ($s =~ /<a ([^>]*)href="((https?|ftp):\/\/)?(\w+.*?)("|:|\/)([^>]*)>/g) {
    push(@ans, $4)
}

@ans = uniq(@ans);
@ans = sort @ans;
print join("\n", @ans);
