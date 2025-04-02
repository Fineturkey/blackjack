/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @author Sofiah Plarison <s.plarisan@uleth.ca>
 * @date Spring 2025
 */
#ifndef GAME_DTO_hpp
#define GAME_DTO_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "../dto/CardDTOs.hpp"
#include "../dto/DealerDTOs.hpp"
#include "../dto/PlayerDTOs.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @class GameDto GameDTOs.hpp "dto/GameDTOs.hpp"
 * @brief A class DTO to represent a game of blackjack.
 */
class GameDto : public oatpp::DTO {
  DTO_INIT(GameDto, DTO);
  DTO_FIELD(Boolean, isGameOver);
  DTO_FIELD(Int32, currentPlayer);
  DTO_FIELD(Object<DealerDto>, dealer);
  DTO_FIELD(List<Object<PlayerDto>>, players);
};

#include OATPP_CODEGEN_END(DTO)

#endif /* GAME_DTO_hpp */
