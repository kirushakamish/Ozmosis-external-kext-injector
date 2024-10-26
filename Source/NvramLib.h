## @file
# Copyright(C) 2024, kirusha_kamish.All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met :
#
# 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and /or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
##

// NvramLib.h

#ifndef _NVRAM_LIB_H_
#define _NVRAM_LIB_H_

#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>

// Функция для получения переменной из NVRAM
// Function to get a variable from NVRAM
EFI_STATUS
GetNvramVariable(
	IN CHAR16* VariableName,
	IN EFI_GUID* VendorGuid,
	OUT UINT32* Attributes OPTIONAL,
	IN OUT UINTN* DataSize,
	OUT VOID* Data
);

// Функция для установки переменной в NVRAM
// Function to set a variable in NVRAM
EFI_STATUS
SetNvramVariable(
	IN CHAR16* VariableName,
	IN EFI_GUID* VendorGuid,
	IN UINT32       Attributes,
	IN UINTN        DataSize,
	IN VOID* Data
);

#endif // _NVRAM_LIB_H_
