/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include "qfm/asset/trait/expiration_trait.hpp"

#include <string>

namespace qfm {
namespace asset {
namespace trait {

ExpirationTrait::ExpirationTrait(const AssetExpiration& expiration) noexcept
    : AssetTrait(ExpirationTrait::Key, static_cast<std::string>(expiration)) {}

const std::string ExpirationTrait::Key = "expiration_date";

}  // namespace trait
}  // namespace asset
}  // namespace qfm
