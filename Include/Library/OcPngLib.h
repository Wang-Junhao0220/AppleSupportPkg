/** @file

OcPngLib - library with PNG decoder functions

Copyright (c) 2018, savvas

All rights reserved.

This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef OC_PNG_LIB_H
#define OC_PNG_LIB_H

/**
  Retrieves PNG image dimensions

  @param  Buffer            Buffer with desired png image
  @param  Size              Size of input image
  @param  Width             Image width at output
  @param  Height            Image height at output

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_OUT_OF_RESOURCES  There are not enough resources to init state.
  @return EFI_INVALID_PARAMETER Passed wrong parameter
**/
EFI_STATUS
GetPngDims (
  IN  UINT8   *Buffer,
  IN  UINTN   Size,
  OUT UINT32  *Width,
  OUT UINT32  *Height
  );

/**
  Decodes PNG image into raw pixel buffer

  @param  Buffer                 Buffer with desired png image
  @param  Size                   Size of input image
  @param  RawData                Output buffer with raw data
  @param  Width                  Image width at output
  @param  Height                 Image height at output
  @param  HasAlphaType           Returns 1 if alpha layer present, optional param
                                 Set NULL, if not used

  @return EFI_SUCCESS            The function completed successfully.
  @return EFI_OUT_OF_RESOURCES   There are not enough resources to init state.
  @return EFI_INVALID_PARAMETER  Passed wrong parameter
**/
EFI_STATUS
DecodePng (
  IN   UINT8   *Buffer,
  IN   UINTN   Size,
  OUT  UINT8   **RawData,
  OUT  UINT32  *Width,
  OUT  UINT32  *Height,
  OUT  UINT32  *HasAlphaType OPTIONAL
  );

/**
  Frees image buffer

  @param  Buffer                 Buffer with desired png image
**/
VOID
FreePng (
  VOID *Buffer
  );

#endif
