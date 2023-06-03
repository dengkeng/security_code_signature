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

#include "permission_utils.h"

#include "accesstoken_kit.h"
#include "cs_hisysevent.h"
#include "ipc_skeleton.h"
#include "log.h"

namespace OHOS {
namespace Security {
namespace CodeSign {
const std::vector<std::string> CERTIFICATE_CALLERS = {"key_enable"};
const std::vector<std::string> SIGN_CALLERS = {"installs"};

bool PermissionUtils::IsValidCallerOfCert()
{
    AccessToken::AccessTokenID callerTokenId = IPCSkeleton::GetCallingTokenID();
    if (VerifyCallingProcess(CERTIFICATE_CALLERS, callerTokenId)) {
        return true;
    }
    ReportInvalidCaller("Cert", callerTokenId);
    return false;
}

bool PermissionUtils::IsValidCallerOfLocalCodeSign()
{
    AccessToken::AccessTokenID callerTokenId = IPCSkeleton::GetCallingTokenID();
    if (VerifyCallingProcess(SIGN_CALLERS, callerTokenId)) {
        return true;
    }
    ReportInvalidCaller("Sign", callerTokenId);
    return false;
}

bool PermissionUtils::VerifyCallingProcess(const std::vector<std::string> &validCallers,
    const AccessToken::AccessTokenID &callerTokenId)
{
    for (const auto &caller: validCallers) {
        AccessToken::AccessTokenID tokenId = AccessToken::AccessTokenKit::GetNativeTokenId(caller);
        if (tokenId == callerTokenId) {
            return true;
        }
    }
    LOG_ERROR(LABEL, "Invalid caller.");
    return false;
}
}
}
}