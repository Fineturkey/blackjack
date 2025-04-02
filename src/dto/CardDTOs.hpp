/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @date Spring 2025
 */
#ifndef CARD_DTO_HPP_INCLUDED
#define CARD_DTO_HPP_INCLUDED

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @class CardDto CardDTOs.hpp "dto/CardDTOs.hpp"
 * @brief A class DTO to represent a card in the game.
 */
class CardDto : public oatpp::DTO {
  DTO_INIT(CardDto, DTO);
  DTO_FIELD(String, rank);
  DTO_FIELD(String, suit);
};

#include OATPP_CODEGEN_END(DTO)

#endif  // CARD_DTO_HPP_INCLUDED
