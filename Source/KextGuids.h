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

#ifndef _KEXT_GUIDS_H_
#define _KEXT_GUIDS_H_

#include <Uefi.h>  // ����������� ��������� ��� EFI_GUID/Connecting the header for EFI_GUID

// ���������� GUID ��� ������ �������
// Number of GUIDs to search for kexts
#define NUM_KEXT_GUIDS 10

// ����������� GUID ��� ������ ������� � NVRAM
// GUID definitions for searching kexts in NVRAM
EFI_GUID KextGuids[NUM_KEXT_GUIDS] = {
    { 0xDADE1000, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE1001, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE1002, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE1003, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE1004, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE1005, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE1006, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE1007, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE1008, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE1009, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100A, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100B, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100C, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100D, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100E, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100F, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100G, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100H, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100I, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100J, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100L, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100M, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100N, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100O, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100P, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100Q, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100R, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100S, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100T, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100U, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100V, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100W, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100X, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100Y, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
    { 0xDADE100Z, 0x1B31, 0x4FE4, { 0x85, 0x57, 0x26, 0xFC, 0xEF, 0xC7, 0x82, 0x75 } },
};

#endif  // _KEXT_GUIDS_H_