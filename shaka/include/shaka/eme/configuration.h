// Copyright 2017 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SHAKA_EMBEDDED_EME_CONFIGURATION_H_
#define SHAKA_EMBEDDED_EME_CONFIGURATION_H_

#include <stdint.h>

#include "../macros.h"

namespace shaka {
namespace eme {

/**
 * @defgroup eme EME Implementations
 * @ingroup exported
 * Interfaces for defining custom EME implementations.
 * @{
 */

enum class MediaKeysRequirement : uint8_t {
  Required,
  Optional,
  NotAllowed,
};

enum class MediaKeySessionType : uint8_t {
  Temporary,
  PersistentLicense,
};

enum class MediaKeyInitDataType : uint8_t {
  Cenc,
  KeyIds,
  WebM,
};

enum class MediaKeyMessageType : uint8_t {
  LicenseRequest,
  LicenseRenewal,
  LicenseRelease,
  IndividualizationRequest,
};

enum class MediaKeyStatus : uint8_t {
  Usable,
  Expired,
  Released,
  OutputRestricted,
  OutputDownscaled,
  StatusPending,
  InternalError,
};

enum class ExceptionType : uint8_t {
  TypeError,
  NotSupported,
  InvalidState,
  QuotaExceeded,
  RangeError,
};

enum class DecryptStatus : uint8_t {
  /** The decrypt was successful. */
  Success,
  /** The required key was not found in any session. */
  KeyNotFound,
  /** The encryption scheme or other setting isn't supported. */
  NotSupported,
  /** Some other internal error occurred. */
  OtherError,
};

enum class EncryptionScheme : uint8_t {
  AesCtr,
  AesCbc,
};

struct SHAKA_EXPORT EncryptionPattern final {
  /** The number of 16-byte blocks that are encrypted. */
  uint32_t encrypted_blocks;
  /** The number of 16-byte blocks that are clear. */
  uint32_t clear_blocks;
};

/** @} */

}  // namespace eme
}  // namespace shaka

#endif  // SHAKA_EMBEDDED_EME_CONFIGURATION_H_
