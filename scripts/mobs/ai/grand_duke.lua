registerNpc(295, {
  walk_speed        = 300,
  run_speed         = 310,
  scale             = 240,
  r_weapon          = 0,
  l_weapon          = 0,
  level             = 90,
  hp                = 204,
  attack            = 18,
  hit               = 65,
  def               = 50,
  res               = 50,
  avoid             = 60,
  attack_spd        = 105,
  is_magic_damage   = 0,
  ai_type           = 287,
  give_exp          = 1,
  drop_type         = 0,
  drop_money        = 1,
  drop_item         = 90,
  union_number      = 90,
  need_summon_count = 0,
  sell_tab0         = 0,
  sell_tab1         = 0,
  sell_tab2         = 0,
  sell_tab3         = 0,
  can_target        = 0,
  attack_range      = 250,
  npc_type          = 1,
  hit_material_type = 1,
  face_icon         = 0,
  summon_mob_type   = 0,
  quest_type        = 0,
  height            = 0
});

function OnInit(entity)
  return true
end

function OnCreate(entity)
  return true
end

function OnDelete(entity)
  return true
end

function OnDead(entity)
end

function OnDamaged(entity)
end