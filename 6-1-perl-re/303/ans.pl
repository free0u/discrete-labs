sub uniq {
    return keys %{{ map { $_ => 1 } @_ }};
}

#while (<>) {
#    $r = "^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?";
#    #print if /^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?/;
#    $r = "^a";
#    print if /$r/;
#}



@inp = <STDIN>;

foreach $line ( @inp ) {
    $line =~ s/^\s*//;
    $line =~ s/\s*$//;
}
$s = join(" ", @inp);

#$s =~ s/<.*?>//g;
#$s =~ s/^\n*//;
#$s =~ s/\n*$//;
#$s =~ s/\n{2,}/\n\n/g;

#@a = $s =~ /<a(.*?)href="(.*?)"(.*?)>/g;
#print @a[0];
#foreach (@a) {
#    print $_[1];
#}

@ans = ();

while ($s =~ /<a ([^>]*)href="((https?|ftp):\/\/)?(\w+.*?)("|:|\/)([^>]*)>/g) {
    #print "$4\n";
    push(@ans, $4)
}

@ans = uniq(@ans);
@ans = sort @ans;
#@ans = do { my %seen; grep { !$seen{$_}++ } @data };
print join("\n", @ans);

#
#@inp = <STDIN>;
#
#foreach $line ( @inp ) {
#    $line =~ s/^\s*//;
#    $line =~ s/\s*$//;
#    $line =~ s/ +/ /g;
#}
#$s = join("\n", @inp);
#
#$s =~ s/<.*?>//g;
#
#$s =~ s/^\n*//;
#$s =~ s/\n*$//;
#$s =~ s/\n{2,}/\n\n/g;
#print $s;
#
