### Description
The denfer is an educational project MIPT students as a part of the course "Modern programming technologies". 
It is a dynamic profiler based on QT, that can attach to any running process, count it's events and display the
statistics in a pretty grafical interface.

### Specifications:

Our aim is the profiler, which:

*  General:
 * Crossplatform: Windows XP/7, Linux SLES10/11
 * Works with generic user rights, doesn't require superuser
 * Installation might require superuser rights
 * Can attach to any running process
 * Has a GUI
*  System:
 * Uses Qt
 * Can work on both linux & windows basic and extended perf interfaces
 * Can use foreign perf interfaces(i.e. vtune or oprofile kernel driver)
 * Compatible with gcc 4.6.2 and MS VS 2010
 * Has an installer and automatic updates
 * Has pretty source code
 * Has no warnings on source code
 * Is optimized and tested with klockwork and valgrind
 * Licensed under GPL
