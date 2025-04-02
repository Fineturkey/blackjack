/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @author Sofiah Plarison <s.plarisan@uleth.ca>
 * @date Spring 2025
 */
#ifndef PLAYER_DTO_hpp
#define PLAYER_DTO_hpp

#include "../dto/CardDTOs.hpp"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @class PlayerDto PlayerDTOs.hpp "dto/PlayerDTOs.hpp"
 * @brief A class DTO to represent a player in the game.
 */
class PlayerDto : public oatpp::DTO {
  DTO_INIT(PlayerDto, DTO);
  DTO_FIELD(String, name);
  DTO_FIELD(List<Object<CardDto>>, hand);
  DTO_FIELD(Int32, handValue);
  DTO_FIELD(String, isBusted);
};

#include OATPP_CODEGEN_END(DTO)

#endif /* PLAYER_DTO_hpp */
