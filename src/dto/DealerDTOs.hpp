/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @author Sofiah Plarison <s.plarisan@uleth.ca>
 * @date Spring 2025
 */
#ifndef DEALER_DTO_HPP_INCLUDED
#define DEALER_DTO_HPP_INCLUDED

#include "../dto/CardDTOs.hpp"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @class DealerDto DealerDto.hpp "DealerDto.hpp"
 * @brief Data transfer object representing a dealer in blackjack.
 */
class DealerDto : public oatpp::DTO {
  DTO_INIT(DealerDto, DTO);
  DTO_FIELD(List<Object<CardDto>>, hand);
  DTO_FIELD(Int32, handValue);
};

#include OATPP_CODEGEN_END(DTO)

#endif  // DEALER_DTO_HPP_INCLUDED
