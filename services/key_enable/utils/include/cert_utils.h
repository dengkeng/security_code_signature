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

#ifndef CODE_SIGN_IOCTL_UTILS_H
#define CODE_SIGN_IOCTL_UTILS_H

#include <cstdint>

#define CERT_DEVICE_PATH "/dev/code_sign"
#define CERT_IOCTL_MAGIC_NUMBER 'k'

struct CertPathInfo {
    uint32_t signing_length;
    uint32_t issuer_length;
    uint64_t signing;
    uint64_t issuer;
    uint32_t path_len;
    uint8_t __reserved[36];
};

#define CERT_IOCTL_CMD _IOW(CERT_IOCTL_MAGIC_NUMBER, 1, CertPathInfo)
#ifdef __cplusplus
extern "C" {
#endif
    int AddCertPath(const CertPathInfo &info);
#ifdef __cplusplus
}
#endif

#endif