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

#ifndef OHOS_SECURITY_CODE_SIGN_UTILS_H
#define OHOS_SECURITY_CODE_SIGN_UTILS_H

#include <cstdint>
#include <string>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unordered_map>

#include "byte_buffer.h"
#include "errcode.h"

namespace OHOS {
namespace Security {
namespace CodeSign {
using EntryMap = std::unordered_map<std::string, std::string>;

class CodeSignUtils {
public:
    /**
     * @brief Enforce code signature for app
     * @param entryPath map from entryname in hap to real path on disk
     * @param signatureFile signature file path
     * @return err code, see err_code.h
     */
    static int32_t EnforceCodeSignForApp(const EntryMap &entryPath, const std::string &signatureFile);
    /**
     * @brief Enforce code signature for file with signature
     * @param path file path
     * @param signature buffer carring signature of the target file
     * @param len length of signature data
     * @return err code, see err_code.h
     */
    static int32_t EnforceCodeSignForFile(const std::string &path, const uint8_t *signature, const size_t len);
    /**
     * @brief Enforce code signature for file with signature
     * @param path file path
     * @param signature bytebuffer carring signature of the target file
     * @return err code, see err_code.h
     */
    static int32_t EnforceCodeSignForFile(const std::string &path, const ByteBuffer &signature);
private:
    static int32_t IsSupportFsVerity(const std::string &path);
    static int32_t IsFsVerityEnabled(int fd);
};
}
}
}
#endif