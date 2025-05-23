/*
 *  Copyright 2019-2024 Diligent Graphics LLC
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
/// Implementation of the MemoryFileStream class

#include "../../Primitives/interface/FileStream.h"
#include "../../Primitives/interface/DataBlob.h"
#include "ObjectBase.hpp"
#include "RefCntAutoPtr.hpp"

namespace Diligent
{

/// Memory file stream implementation
class MemoryFileStream final : public ObjectBase<IFileStream>
{
public:
    typedef ObjectBase<IFileStream> TBase;

    MemoryFileStream(IReferenceCounters* pRefCounters,
                     IDataBlob*          pData);

    virtual void DILIGENT_CALL_TYPE QueryInterface(const INTERFACE_ID& IID, IObject** ppInterface) override final;

    /// Reads data from the stream
    virtual void DILIGENT_CALL_TYPE ReadBlob(IDataBlob* pData) override final;

    /// Reads data from the stream
    virtual bool DILIGENT_CALL_TYPE Read(void* Data, size_t Size) override final;

    /// Writes data to the stream
    virtual bool DILIGENT_CALL_TYPE Write(const void* Data, size_t Size) override final;

    virtual size_t DILIGENT_CALL_TYPE GetSize() override final;

    virtual size_t DILIGENT_CALL_TYPE GetPos() override;

    virtual bool DILIGENT_CALL_TYPE SetPos(size_t Offset, int Origin) override;

    virtual bool DILIGENT_CALL_TYPE IsValid() override final;

    static RefCntAutoPtr<MemoryFileStream> Create(IDataBlob* pData);

private:
    RefCntAutoPtr<IDataBlob> m_DataBlob;
    size_t                   m_CurrentOffset = 0;
};

} // namespace Diligent
