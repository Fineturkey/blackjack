/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @author Sofiah Plarison <s.plarisan@uleth.ca>
 * @date Spring 2025
 */
#ifndef PLAYERLIST_DTO_HPP
#define PLAYERLIST_DTO_HPP

#include "../dto/CardDTOs.hpp"
#include "../dto/DealerDTOs.hpp"
#include "../dto/PlayerDTOs.hpp"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @class PlayerListDto PlayerListDTOs.hpp "dto/PlayerListDTOs.hpp"
 * @brief A class DTO to represent a list of players in the game.
 */
class PlayerListDto : public oatpp::DTO {
  DTO_INIT(PlayerListDto, DTO);
  DTO_FIELD(List<Object<PlayerDto>>, players);
};

#include OATPP_CODEGEN_END(DTO)

#endif /* PLAYERLIST_DTO_HPP */
