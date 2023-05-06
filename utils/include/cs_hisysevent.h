/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CODE_SIGN_HISYSEVENT_H
#define CODE_SIGN_HISYSEVENT_H

#include <hisysevent.h>
#include <string>

namespace OHOS {
namespace Security {
namespace CodeSign {
inline void ReportEnableError(std::string filePath, int32_t errCode)
{
    HiSysEventWrite(HiviewDFX::HiSysEvent::Domain::CODE_SIGN, "CS_ENABLE_ERR",
        HiviewDFX::HiSysEvent::EventType::SECURITY,
        "FILE_INFO", filePath, "ERR_TYPE", errCode);
}

inline void ReportLoadSAError(int32_t errCode)
{
    HiSysEventWrite(HiviewDFX::HiSysEvent::Domain::CODE_SIGN, "CS_LOAD_SA_ERR",
        HiviewDFX::HiSysEvent::EventType::FAULT, "ERR_TYPE", errCode);
}

inline void ReportInvalidCaller(const std::string &interfaceType, uint32_t tokenID)
{
    HiSysEventWrite(HiviewDFX::HiSysEvent::Domain::CODE_SIGN, "CS_SA_INVALID_CALLER",
        HiviewDFX::HiSysEvent::EventType::SECURITY,
        "INTERFACE", interfaceType, "TOKEN_ID", tokenID);
}
}
}
}
#endif