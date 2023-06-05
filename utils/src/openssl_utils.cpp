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

#include "openssl_utils.h"
#include "openssl/err.h"
#include "log.h"

namespace OHOS {
namespace Security {
namespace CodeSign {
constexpr int OPENSSL_ERR_MESSAGE_MAX_LEN = 1024;

void ErrLogWithOpenSSLMsg(const char *msg)
{
    LOG_ERROR(LABEL, "%{public}s", msg);
    GetOpensslErrorMessage();
}

void GetOpensslErrorMessage()
{
    unsigned long retOpenssl;
    char errOpenssl[OPENSSL_ERR_MESSAGE_MAX_LEN];
    while ((retOpenssl = ERR_get_error()) != 0) {
        // error string is written no more than OPENSSL_ERR_MESSAGE_MAX_LEN in errOpenssl
        ERR_error_string_n(retOpenssl, errOpenssl, OPENSSL_ERR_MESSAGE_MAX_LEN);
        LOG_ERROR(LABEL, "openssl err: %{public}lu, message: %{public}s", retOpenssl, errOpenssl);
    }
}

X509 *LoadCertFromBuffer(const uint8_t *buffer, const uint32_t size)
{
    BIO *mem = BIO_new_mem_buf(buffer, size);
    if (mem == nullptr) {
        LOG_ERROR(LABEL, "Fail to create bio for cert.");
        return nullptr;
    }
    X509 *cert = d2i_X509_bio(mem, nullptr);
    if (cert == nullptr) {
        ErrLogWithOpenSSLMsg("Certificate is invalid.");
    }
    BIO_free(mem);
    return cert;
}

STACK_OF(X509) *MakeStackOfCerts(const std::vector<ByteBuffer> &certChain)
{
    STACK_OF(X509)* certs = sk_X509_new_null();
    if (certs == nullptr) {
        return nullptr;
    }
    for (const ByteBuffer &cert: certChain) {
        X509 *tmp = LoadCertFromBuffer(cert.GetBuffer(), cert.GetSize());
        if ((tmp == nullptr) || (!sk_X509_push(certs, tmp))) {
            // including each cert in certs and stack of certs
            sk_X509_pop_free(certs, X509_free);
            certs = nullptr;
            break;
        }
    }
    return certs;
}
}
}
}
