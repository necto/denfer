#! /usr/bin/perl -w

use strict;
use warnings;

use Getopt::Long;

my $file;
&GetOptions("f|file=s" => \$file);

my $out = "$file.objdump.out";
`objdump -t $file  | grep -P "^[0-9a-f]+ [^\.\*]*F" | sort > $out`;
`chmod 777 $out`;

my $line;
open OUT, '<', $out or die $!;
while ($line = <OUT>) {
    if ($line =~ /^([0-9a-f]+) [a-zA-Z\s\.\*]*([0-9a-f]+)[\s]*(.*)/) {
        print "$1\t$2\t$3\n";
    }
}
