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

#ifndef OHOS_LOCAL_CODE_SIGN_SERVICE_H
#define OHOS_LOCAL_CODE_SIGN_SERVICE_H

#include "event_handler.h"
#include "event_runner.h"
#include "local_code_sign_stub.h"
#include "system_ability.h"

namespace OHOS {
namespace Security {
namespace CodeSign {
class LocalCodeSignService : public SystemAbility, public LocalCodeSignStub {
DECLARE_SYSTEM_ABILITY(LocalCodeSignService);

public:
    LocalCodeSignService(int32_t saId, bool runOnCreate);
    ~LocalCodeSignService() = default;
    void OnStart() override;
    void OnStop() override;
    int32_t InitLocalCertificate(ByteBuffer &cert) override;
    void DelayUnloadTask() override;
private:
    bool Init();
    std::shared_ptr<AppExecFwk::EventHandler> unloadHandler_;
};
}
}
}
#endif
