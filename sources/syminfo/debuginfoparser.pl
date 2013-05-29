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

my $out = "$file.objdump_debug_info.out";
`objdump --dwarf=info $file > $out`;
`chmod 777 $out`;

my $line;
open OUT, '<', $out or die $!;
my $info;
my $mode = "none";
my ($id, $name, $type, $start, $end, $inline, $iid) = ("", "", "", "", "", "not inlined", "");
while ($line = <OUT>) {
    if ($line =~ /<[0-9]+><([0-9a-e]+)>: Abbrev Number: [0-9]+ \((.*)\)/ ) {
        if ($mode eq "reading DIE") {
            #previous DIE read is completed - dumping
            $info->{$name}->{id} = $id;
            $info->{$name}->{type} = $type;
            $info->{$name}->{start} = $start;
            $info->{$name}->{end} = $end;
            $info->{$name}->{inline} = $inline;
            $info->{$name}->{iid} = $iid;

            ($id, $name, $type, $start, $end, $inline, $iid) = ("", "", "", "", "", "not_inlined", "");
        }
        $mode = "none";

        ($id, $type) = ($1, $2);
        if ($type eq "DW_TAG_subprogram" ||
            $type eq "DW_TAG_inlined_subroutine") {
            $mode = "reading DIE";
        }
    }
    elsif ($mode eq "reading DIE") {
        if ($line =~ /DW_AT_name.*: (.*)\s*$/) {
            $name = $1;
        }
        elsif ($line =~ /DW_AT_low_pc\s*: (.*)\s*$/) {
            $start = $1;
        }
        elsif ($line =~ /DW_AT_high_pc\s*: (.*)\s*$/) {
            $end = $1;
        }
        elsif ($line =~ /DW_AT_inline/) {
            $inline = "inlined";
        }
        elsif ($line =~ /DW_AT_abstract_origin: <0x([0-9a-e]+)>/) {
            $iid = $1;
        }
    }
}
`rm -rf $out`;

foreach my $name (keys %{ $info }) {
    next if ($info->{$name}->{inline} eq "inlined");
    my ($start, $end, $inline) = ($info->{$name}->{start},
                                  $info->{$name}->{end},
                                  $info->{$name}->{inline});

    if ($info->{$name}->{type} eq "DW_TAG_inlined_subroutine") {
        my $inline_name;
        foreach $inline_name (keys %{ $info }) {
            if ($info->{$inline_name}->{inline} eq "inlined" && $info->{$inline_name}->{id} == $info->{$name}->{iid}) {
                $name = $inline_name;
                last;
            }
        }
        $inline = "inlined";
    }

    print "$name $start $end $inline\n" if ($start ne "" && $end ne "");
}

