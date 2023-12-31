/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include "qfm/pricing/pricing.hpp"

#include <memory>
#include <string>

#include "qfm/asset/asset.hpp"
#include "qfm/pricing/model/model.hpp"
#include "qfm/pricing/model/null_model.hpp"

namespace qfm {
namespace pricing {

void Pricing::SetModel(std::shared_ptr<model::Model> model,
                       const asset::AssetType &type) noexcept {
  models_.insert(std::make_pair(type, model));
}

double Pricing::GetAssetPrice(
    std::shared_ptr<asset::Asset> asset) const noexcept {
  auto iterator = models_.find(asset->GetType());
  if (iterator != models_.end()) {
    return iterator->second->GetAssetPrice(asset);
  }
  return model::NullModel().GetAssetPrice(asset);
}

}  // namespace pricing
}  // namespace qfm
