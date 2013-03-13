/**
 * Elf64 structure specification
 */
/**
 * authors: 
 *  Oleg Shimko 
 *  Robert Khasanov
 * 
 * Copyright 2013 Denfer team
 */

#pragma once

/** Unsgined program address */
typedef Elf64_Addr unsigned long long;

/** Unsigned file offset */
typedef Elf64_Off unsigned long long;

/** Unsigned medium integer */
typedef Elf64_Half unsigned short int;

/** Unsigned integer */
typedef Elf64_Word unsigned long;

/** Signed integer */
typedef Elf64_Sword signed long;

/** Unsigned long integer */
typedef Elf64_Xword unsigned long long;

/** Signed long integer */
typedef ELf64_Sxword signed long long;


/** 
 * File Header
 */
typedef struct
{
    unsigned char e_ident[16]; /** ELF identification */
    Elf64_Half e_type; /** Object file type */
    Elf64_Half e_machine; /** Machine type */
    Elf64_Word e_version; /** Object file version */
    Elf64_Addr e_entry; /** Entry point address */
    Elf64_Off e_phoff; /** Program header offset */
    Elf64_Off e_shoff; /** Section header offset */
    Elf64_Word e_flags; /** Processor-specific flags */
    Elf64_Half e_ehsize; /** ELF header size */
    Elf64_Half e_phentsize; /** Size of program header entry */
    Elf64_Half e_phnum; /** Number of program header entries */
    Elf64_Half e_shentsize; /** Size of section header entry */
    Elf64_Half e_shnum; /** Number of section header entries */
    Elf64_Half e_shstrndx; /** Section name string table index */
} Elf64_Ehdr;

/**
 * ELF Identification, e_ident
 */
typedef enum
{
    EI_MAG0 = 0, /** File identification */
    EI_MAG1 = 1
    EI_MAG2 = 2
    EI_MAG3 = 3
    EI_CLASS = 4 /** File class */
    EI_DATA = 5 /** Data encoding */
    EI_VERSION = 6 /** File version */
    EI_OSABI = 7 /** OS/ABI identification */
    EI_ABIVERSION = 8 /** ABI version */
    EI_PAD = 9 /** Start of padding bytes */
    EI_NIDENT = 16 /** Size of e_ident[] */
} e_ident_index;


