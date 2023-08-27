#include <boost/math/distributions/normal.hpp>
#include <iostream>

#include "asset/asset_expiration.hpp"
#include "asset/asset_strike_price.hpp"
#include "asset/asset_trait_set.hpp"
#include "asset/asset_type.hpp"
#include "asset/option.hpp"
#include "asset/trait/expiration_trait.hpp"
#include "asset/trait/strike_price_trait.hpp"
#include "market_data_provider.hpp"
#include "pricing/model/black_scholes.hpp"
#include "pricing/pricing.hpp"

int main() {
  std::cout << "Hello World!" << std::endl;

  auto gaussian = boost::math::normal_distribution(0, 1);
  std::cout << "Outputting random value: " << cdf(gaussian, 2) << std::endl;

  std::string ticker{"fake_ticker"};
  AssetType type{AssetType::CALL_OPTION};
  AssetExpiration expiration{1704067200};
  AssetStrikePrice strike_price{10};
  AssetTraitSet traits{
      {ExpirationTrait(expiration), StrikePriceTrait(strike_price)}};
  auto asset = std::make_shared<Asset>(ticker, type, traits);

  std::shared_ptr<MarketDataProvider> market_data_provider =
      std::make_shared<MarketDataProvider>();

  auto model = std::make_shared<BlackScholes>(market_data_provider);

  Pricing pricing;
  pricing.SetModel(model, type);

  std::cout << "Price of asset " << std::string(ticker)
            << " is: " << pricing.GetAssetPrice(asset) << std::endl;
}
