registerNpc(163, {
  walk_speed        = 320,
  run_speed         = 700,
  scale             = 310,
  r_weapon          = 0,
  l_weapon          = 0,
  level             = 84,
  hp                = 181,
  attack            = 470,
  hit               = 260,
  def               = 266,
  res               = 216,
  avoid             = 133,
  attack_spd        = 85,
  is_magic_damage   = 0,
  ai_type           = 64,
  give_exp          = 631,
  drop_type         = 181,
  drop_money        = 1,
  drop_item         = 80,
  union_number      = 80,
  need_summon_count = 0,
  sell_tab0         = 0,
  sell_tab1         = 0,
  sell_tab2         = 0,
  sell_tab3         = 0,
  can_target        = 0,
  attack_range      = 250,
  npc_type          = 10,
  hit_material_type = 2,
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