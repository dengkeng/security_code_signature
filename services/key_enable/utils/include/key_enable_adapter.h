/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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

#ifndef CODE_SIGN_KEY_ENABLE_ADAPTER_H
#define CODE_SIGN_KEY_ENABLE_ADAPTER_H

#ifndef LOG_RUST
#define LOG_RUST
#endif

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif
int32_t InitLocalCertificate(uint8_t *cert, uint32_t *certSize);
bool CheckUserUnlock();
#ifdef __cplusplus
}
#endif

#endif