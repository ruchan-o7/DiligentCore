/*
 *  Copyright 2019-2020 Diligent Graphics LLC
 *  Copyright 2015-2019 Egor Yusov
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *      http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#pragma once

/// \file
/// Definition of the Diligent::IRenderDeviceVk interface

#include "../../GraphicsEngine/interface/RenderDevice.h"

DILIGENT_BEGIN_NAMESPACE(Diligent)

// {AB8CF3A6-D959-41C1-AE00-A58AE9820E6A}
static const INTERFACE_ID IID_RenderDeviceVk =
    {0xab8cf3a6, 0xd959, 0x41c1, {0xae, 0x0, 0xa5, 0x8a, 0xe9, 0x82, 0xe, 0x6a}};

#define DILIGENT_INTERFACE_NAME IRenderDeviceVk
#include "../../../Primitives/interface/DefineInterfaceHelperMacros.h"

// clang-format off

/// Exposes Vulkan-specific functionality of a render device.
DILIGENT_INTERFACE(IRenderDeviceVk, IRenderDevice)
{
    /// Returns logical Vulkan device handle
    VIRTUAL VkDevice METHOD(GetVkDevice)(THIS) PURE;

    /// Returns physical Vulkan device
    VIRTUAL VkPhysicalDevice METHOD(GetVkPhysicalDevice)(THIS) PURE;

    /// Returns Vulkan instance
    VIRTUAL VkInstance METHOD(GetVkInstance)(THIS) PURE;

    /// Returns the fence value that will be signaled by the GPU command queue next
    VIRTUAL Uint64 METHOD(GetNextFenceValue)(THIS_
                                             Uint32 QueueIndex) PURE;

    /// Returns the last completed fence value for the given command queue
    VIRTUAL Uint64 METHOD(GetCompletedFenceValue)(THIS_
                                                  Uint32 QueueIndex) PURE;

    /// Checks if the fence value has been signaled by the GPU. True means
    /// that all associated work has been finished
    VIRTUAL Bool METHOD(IsFenceSignaled)(THIS_
                                         Uint32 QueueIndex, 
                                         Uint64 FenceValue) PURE;

    /// Creates a texture object from native Vulkan image

    /// \param [in]  vkImage      - Vulkan image handle
    /// \param [in]  TexDesc      - Texture description. Vulkan provides no means to retrieve any
    ///                             image properties from the image handle, so complete texture
    ///                             description must be provided
    /// \param [in]  InitialState - Initial texture state. See Diligent::RESOURCE_STATE.
    /// \param [out] ppTexture    - Address of the memory location where the pointer to the
    ///                             texture interface will be stored.
    ///                             The function calls AddRef(), so that the new object will contain
    ///                             one reference.
    /// \note  Created texture object does not take ownership of the Vulkan image and will not
    ///        destroy it once released. The application must not destroy the image while it is
    ///        in use by the engine.
    VIRTUAL void METHOD(CreateTextureFromVulkanImage)(THIS_
                                                      VkImage               vkImage,
                                                      const TextureDesc REF TexDesc,
                                                      RESOURCE_STATE        InitialState,
                                                      ITexture**            ppTexture) PURE;

    /// Creates a buffer object from native Vulkan resource

    /// \param [in] vkBuffer      - Vulkan buffer handle
    /// \param [in] BuffDesc      - Buffer description. Vulkan provides no means to retrieve any
    ///                             buffer properties from the buffer handle, so complete buffer
    ///                             description must be provided
    /// \param [in]  InitialState - Initial buffer state. See Diligent::RESOURCE_STATE.
    /// \param [out] ppBuffer     - Address of the memory location where the pointer to the
    ///                             buffer interface will be stored.
    ///                             The function calls AddRef(), so that the new object will contain
    ///                             one reference.
    /// \note  Created buffer object does not take ownership of the Vulkan buffer and will not
    ///        destroy it once released. The application must not destroy Vulkan buffer while it is
    ///        in use by the engine.
    VIRTUAL void METHOD(CreateBufferFromVulkanResource)(THIS_
                                                        VkBuffer             vkBuffer,
                                                        const BufferDesc REF BuffDesc,
                                                        RESOURCE_STATE       InitialState,
                                                        IBuffer**            ppBuffer) PURE;
};

#include "../../../Primitives/interface/UndefInterfaceHelperMacros.h"

#if DILIGENT_C_INTERFACE

// clang-format on

struct IRenderDeviceVkVtbl
{
    struct IObjectMethods         Object;
    struct IRenderDeviceMethods   RenderDevice;
    struct IRenderDeviceVkMethods RenderDeviceVk;
};

typedef struct IRenderDeviceVk
{
    struct IRenderDeviceVkVtbl* pVtbl;
} IRenderDeviceVk;

// clang-format off

#    define IRenderDeviceVk_GetVkDevice(This)                         (This)->pVtbl->RenderDeviceVk.GetVkDevice                    ((IRenderDeviceVk*)(This))
#    define IRenderDeviceVk_GetVkPhysicalDevice(This)                 (This)->pVtbl->RenderDeviceVk.GetVkPhysicalDevice            ((IRenderDeviceVk*)(This))
#    define IRenderDeviceVk_GetVkInstance(This)                       (This)->pVtbl->RenderDeviceVk.GetVkInstance                  ((IRenderDeviceVk*)(This))
#    define IRenderDeviceVk_GetNextFenceValue(This, ...)              (This)->pVtbl->RenderDeviceVk.GetNextFenceValue              ((IRenderDeviceVk*)(This), __VA_ARGS__)
#    define IRenderDeviceVk_GetCompletedFenceValue(This, ...)         (This)->pVtbl->RenderDeviceVk.GetCompletedFenceValue         ((IRenderDeviceVk*)(This), __VA_ARGS__)
#    define IRenderDeviceVk_IsFenceSignaled(This, ...)                (This)->pVtbl->RenderDeviceVk.IsFenceSignaled                ((IRenderDeviceVk*)(This), __VA_ARGS__)
#    define IRenderDeviceVk_CreateTextureFromVulkanImage(This, ...)   (This)->pVtbl->RenderDeviceVk.CreateTextureFromVulkanImage   ((IRenderDeviceVk*)(This), __VA_ARGS__)
#    define IRenderDeviceVk_CreateBufferFromVulkanResource(This, ...) (This)->pVtbl->RenderDeviceVk.CreateBufferFromVulkanResource ((IRenderDeviceVk*)(This), __VA_ARGS__)

// clang-format on

#endif

DILIGENT_END_NAMESPACE // namespace Diligent
