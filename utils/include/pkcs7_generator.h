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

#ifndef CODE_SIGN_PKCS7_GENERATOR_H
#define CODE_SIGN_PKCS7_GENERATOR_H

#include <string>

#include "byte_buffer.h"
#include "signer_info.h"
#include "sign_key.h"

namespace OHOS {
namespace Security {
namespace CodeSign {
class PKCS7Generator {
public:
    static int32_t GenerateSignature(const std::string& ownerID, SignKey &key, const char *hashAlg,
        const ByteBuffer &contentData, ByteBuffer &out);
private:
    static int32_t SignData(SignKey &key, SignerInfo &signerInfo);
};
}
}
}
#endif