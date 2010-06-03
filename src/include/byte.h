/**
 * Copyright (C) 2010, Shao Miller <shao.miller@yrdsb.edu.on.ca>.
 *
 * This file is part of WinVBlock, derived from WinAoE.
 *
 * WinVBlock is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * WinVBlock is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with WinVBlock.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _byte_h
#  define _byte_h

/**
 * @file
 *
 * Byte order (endian) specifics
 *
 */

#  define byte__array_union( type, name ) \
  union                                 \
    {                                   \
      type val;                         \
      char bytes[sizeof ( type )];      \
    }                                   \
    name

/* Function body in header so user-land utility links without WinVBlock */
static void STDCALL
byte__order_swap (
  IN OUT char *bytes,
  int count
 )
{
  /*
   * Just for fun
   */
  while ( --count > 0 )
    {
      bytes[0] ^= bytes[count];
      bytes[count] ^= bytes[0];
      bytes[0] ^= bytes[count];
      bytes++;
      count--;
    }
}

/* Expects a byte_array_union only! */
#  define byte__rev_array_union( x ) \
  byte__order_swap ( x.bytes, sizeof(x.bytes) )

#endif				/* _byte_h */