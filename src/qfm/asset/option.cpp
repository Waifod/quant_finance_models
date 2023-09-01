//
// Created by Durante, Matteo on 19/8/23.
//

#include "qfm/asset/option.hpp"

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_expiration.hpp"
#include "qfm/asset/asset_strike_price.hpp"
#include "qfm/asset/asset_type.hpp"
#include "qfm/asset/trait/expiration_trait.hpp"
#include "qfm/asset/trait/strike_price_trait.hpp"
#include "qfm/asset/trait/type_trait.hpp"
#include "qfm/asset/trait/underlying_trait.hpp"

namespace qfm {
namespace asset {

Option::Option(const std::string& ticker, const AssetType& type,
               const AssetTraitSet& traits) noexcept
    : Asset(ticker, type, traits) {}

std::string Option::GetUnderlying() const noexcept {
  return traits_.GetValue<trait::UnderlyingTrait>();
}

AssetStrikePrice Option::GetStrikePrice() const noexcept {
  return AssetStrikePrice(
      std::stod(traits_.GetValue<trait::StrikePriceTrait>()));
}

AssetExpiration Option::GetExpirationDate() const noexcept {
  return AssetExpiration(
      std::stoll(traits_.GetValue<trait::ExpirationTrait>()));
}

}  // namespace asset
}  // namespace qfm
