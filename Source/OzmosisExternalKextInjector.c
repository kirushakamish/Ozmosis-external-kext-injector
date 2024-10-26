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

#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/NvramLib.h>

// Определение списка GUID для поиска кекстов
// Defining a list of GUIDs for kexts search
#define NUM_KEXT_GUIDS 10  // Количество GUID для поиска/Number of GUIDs to search for

// GUID массив для кекстов
// GUID array for kexts
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

// Функция инжекции кекста в ядро
// Function of kext injection into the kernel
EFI_STATUS InjectKext(VOID* KextData, UINTN KextSize) {
    EFI_STATUS Status;

    // Логика инжекции кекста в Kernel Collection
    // Logic of kext injection in Kernel Collection
    Status = RegisterKextWithKernel(KextData, KextSize);
    if (EFI_ERROR(Status)) {
        DEBUG((DEBUG_ERROR, "Failed to register kext with kernel: %r\n", Status));
        return Status;
    }

    return EFI_SUCCESS;
}

// Основная функция загрузки и инжекции кекстов из NVRAM
// Basic function of loading and injection of kexts from NVRAM
EFI_STATUS LoadKextsFromNVRAM() {
    EFI_STATUS Status;
    UINTN KextDataSize;
    VOID* KextData;

    for (UINTN i = 0; i < NUM_KEXT_GUIDS; i++) {
        KextDataSize = 0;
        KextData = NULL;

        // Получение данных из NVRAM по текущему GUID
        // Getting data from NVRAM by current GUID
        Status = GetVariable(L"Kext", &KextGuids[i], NULL, &KextDataSize, NULL);
        if (Status == EFI_NOT_FOUND) {
            // Если кекст с данным GUID не найден, переходим к следующему
            // If a kext with this GUID is not found, go to the next one
            DEBUG((DEBUG_INFO, "Kext with GUID %g not found in NVRAM\n", &KextGuids[i]));
            continue;
        }
        else if (EFI_ERROR(Status) && Status != EFI_BUFFER_TOO_SMALL) {
            DEBUG((DEBUG_ERROR, "Error reading kext size from NVRAM: %r\n", Status));
            continue;
        }

        // Выделение памяти для кекста
        // Allocate memory for the kext
        KextData = AllocatePool(KextDataSize);
        if (KextData == NULL) {
            return EFI_OUT_OF_RESOURCES;
        }

        // Считывание кекста из NVRAM
        // Read kext from NVRAM
        Status = GetVariable(L"Kext", &KextGuids[i], NULL, &KextDataSize, KextData);
        if (EFI_ERROR(Status)) {
            FreePool(KextData);
            DEBUG((DEBUG_ERROR, "Failed to read kext data from NVRAM: %r\n", Status));
            continue;
        }

        // Инжекция кекста в ядро
        // Injecting the kext into the kernel
        Status = InjectKext(KextData, KextDataSize);
        FreePool(KextData);

        if (EFI_ERROR(Status)) {
            DEBUG((DEBUG_ERROR, "Failed to inject kext with GUID %g: %r\n", &KextGuids[i], Status));
            continue;
        }

        DEBUG((DEBUG_INFO, "Successfully injected kext with GUID %g\n", &KextGuids[i]));
    }

    return EFI_SUCCESS;
}

// Точка входа драйвера
// Driver input point
EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE* SystemTable) {
    EFI_STATUS Status;

    DEBUG((DEBUG_INFO, "Kext Injector Driver Loaded\n"));

    // Загрузка кекстов из NVRAM и их инжекция
    // Loading kexts from NVRAM and their injection
    Status = LoadKextsFromNVRAM();
    if (EFI_ERROR(Status)) {
        DEBUG((DEBUG_ERROR, "Failed to load and inject kexts: %r\n", Status));
    }

    return Status;
}
