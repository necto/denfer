#! /usr/bin/perl -w

use strict;
use warnings;

use Getopt::Long;

my $file;
&GetOptions("f|file=s" => \$file);

unless (-f $file) {
    print STDERR "[ERROR] File $file doesn't exist\n";
    exit -1;
}

if (`objdump -t $file` =~ /no symbols/) {
    print STDERR "[ERROR] Symbol table has been stripped from $file binary\n";
    exit -1;
}

my $out = "$file.objdump_symbols.out";
`objdump -t $file  | grep -P "^[0-9a-f]+ [^\.\*]*F" | sort > $out`;
`chmod 777 $out`;

my $line;
open OUT, '<', $out or die $!;
while ($line = <OUT>) {
    if ($line =~ /^([0-9a-f]+) [a-zA-Z\s\.\*]*([0-9a-f]+)[\s]*(.*)/) {
        print "$1\t$2\t$3\n";
    }
}
`rm -rf $out`;
