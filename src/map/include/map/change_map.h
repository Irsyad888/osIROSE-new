#pragma once

#include "dataconsts.h"
#include "cli_change_map_req.h"
#include "cli_teleport_req.h"

class EntitySystem;

namespace Map {
void change_map_request(EntitySystem&, RoseCommon::Entity, const RoseCommon::Packet::CliChangeMapReq&);
void teleport_request(EntitySystem&, RoseCommon::Entity, const RoseCommon::Packet::CliTeleportReq&);
}
